/**************************************************************************
* Name:      Van-der-Pol.cpp                                              *
* Zweck:     Simuliert die Dynamik eines Van-der-Pol-Oszillators          *
* Gleichung: (d^2/d t^2) x + epsilon * (1-x) * (d/dt) x + x = 0           *
* verwendete Bibiliothek: GSL                                             *
**************************************************************************/

#include <iostream>
#include <fstream>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv.h>
#include <gsl/gsl_odeiv2.h>
#include <math.h>
#include "tools.h"

using namespace std;

//---- globale Variablen
int    icount1, icount2;
double kappa, D, M, g, l_0;

//-------------------------------------------------------------------------

int f(double t, const double x[], double dxdt[], void *params)

{
double l = sqrt( sqr(x[0])+sqr(x[1]) );
double r = x[0];
double phi = x[1];
double drdt = x[2];
double dphidt = x[3];
dxdt[0] = x[2];
dxdt[1] = x[3];
dxdt[2] = -g * sin(phi)-D*(r-l_0)-kappa*drdt+r*sqr(dphidt);
dxdt[3] = -(g*cos(phi)+2*drdt*dphidt)/r;

icount1++;
return GSL_SUCCESS;
}

//-------------------------------------------------------------------------

int jac(double t, const double x[], double *dfdx, double dfdt[],
        void *params)

{
double mu = *(double *)params;

double l = sqrt( sqr(x[0])+sqr(x[1]) );
double r = x[0];
double phi = x[1];
double drdt = x[2];
double dphidt = x[3];
gsl_matrix_view dfdx_mat 
   = gsl_matrix_view_array (dfdx, 4, 4);
gsl_matrix * m = &dfdx_mat.matrix; 
gsl_matrix_set (m, 0, 0, 0.0);
gsl_matrix_set (m, 0, 1, 0.0);
gsl_matrix_set (m, 0, 2, 1.0);
gsl_matrix_set (m, 0, 3, 0.0);
gsl_matrix_set (m, 1, 0, 0.0);
gsl_matrix_set (m, 1, 1, 0.0);
gsl_matrix_set (m, 1, 2, 0.0);
gsl_matrix_set (m, 1, 3, 1.0);
gsl_matrix_set (m, 2, 0, -D+sqr(dphidt)); 
gsl_matrix_set (m, 2, 1, -g*cos(phi));
gsl_matrix_set (m, 2, 2, -kappa);
gsl_matrix_set (m, 2, 3, 2*r*dphidt);
gsl_matrix_set (m, 3, 0, (g*cos(phi)+2*drdt*dphidt)/sqr(r));
gsl_matrix_set (m, 3, 1, g*sin(phi)/r);
gsl_matrix_set (m, 3, 2, -2*dphidt/r);
gsl_matrix_set (m, 3, 3, -2*drdt/r);
dfdt[0] = 0.0;
dfdt[1] = 0.0;
dfdt[2] = 0.0;
dfdt[3] = 0.0;
icount2++;
return GSL_SUCCESS;
}

//-------------------------------------------------------------------------

int main( int argc, char *argv[] )

{

//-- Definition der Variablen
int    n, n1, n_max;
double t, tend, dt, t1, E, l;
double rtol, atol, h;
double x[4], x_ref[4];
double mu = 10;
ifstream in_stream, ref_stream;
ofstream out_stream;
out_stream.precision(16);

//-- Fehlermeldung, wenn Input- und Outputfilename nicht uebergeben wurden
if (argc<3)
  {
  cout << " Aufruf: faden_lib infile referencefile outfile\n";
  exit(1);
  }

//-- Einlesen der Parameter --
in_stream.open(argv[1]);
ref_stream.open(argv[2]);
out_stream.open(argv[3]);
out_stream << "! Ergebnis-Datei generiert von gedaempfter_oszillator.cpp\n";
inout(tend,"tend");      inout(n_max,"n_max");
inout(D,"D");            inout(M,"M");
inout(l_0,"l_0");        inout(kappa,"kappa");
inout(atol,"atol");      inout(rtol,"rtol");      
inout(x[0],"x[0]");      inout(x[1],"x[1]");
inout(x[2],"x[2]");      inout(x[3],"x[3]");

//-- Einlesen der Referenzwerte
for (n=0; n<4; n++) ref_stream >> x_ref[n];

//-- Berechnung einiger benoetigter Parameter --
dt = tend/float(n_max);
h = 1.e-6;
g = 9.81;

//-- Anfangsbedingungen
t = 0;

out_stream << t << " " << x[0] << " " << x[1] << " " 
	               << x[2] << " " << x[3] << "\n";

//-- Initialisierung der GSL-Routine
const gsl_odeiv2_step_type *T = gsl_odeiv2_step_msbdf;
gsl_odeiv2_step    *s = gsl_odeiv2_step_alloc(T, 4);
gsl_odeiv2_control *c = gsl_odeiv2_control_y_new(atol, rtol);
gsl_odeiv2_evolve  *e = gsl_odeiv2_evolve_alloc(4);
gsl_odeiv2_system  sys = {f, jac, 4, &mu};
gsl_odeiv2_driver  *d = gsl_odeiv2_driver_alloc_y_new(&sys, T, atol, rtol, 0.); 

for (n=1; n<=n_max; n++)
  {
  t1 = n*dt;
  while (t<t1)
    {
    int status = gsl_odeiv2_driver_apply(d, &t, t1, x);
    if (status != GSL_SUCCESS) break;
    }
  l = sqrt( sqr(x[0])+sqr(x[1]) );
  out_stream << t << " " << x[0] << " " << x[1] << " " << x[2] 
	                 << " " << x[3] << " " << l <<  "\n";
  }
for (n=0; n<4; n++) cout << x[n]-x_ref[n] << " "; cout << "\n";
cout << "Aufrufe von f, jac: " << icount1 << " " << icount2 << "\n";


gsl_odeiv2_evolve_free(e);
gsl_odeiv2_control_free(c);
gsl_odeiv2_step_free(s);

out_stream.close();
ref_stream.close();
in_stream.close();
}
