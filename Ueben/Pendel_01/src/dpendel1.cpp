/*************************************************************************
* Name:      dpendel1.cpp                                                *
* Zweck:     Simuliert die Dynamik eines Doppelpendels                   *
* Gleichung: siehe Text                                                  *
* verwendete Bibiliothek: GSL                                            *
*************************************************************************/

#include <iostream>
#include <fstream>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv.h>
#include <math.h>
#include "tools.h"

//---- Definition der globalen Variablen
double alpha, beta;

//------------------------------------------------------------------------

int f(double t, const double x[], double dxdt[], void *params)

{
dxdt[0] = x[1];
dxdt[1] = ( - alpha*beta*x[3]*x[3] * sin(x[0]-x[2]) - 
           (1+alpha)*sin(x[0]) - alpha*x[1]*x[1]*sin(x[0]
           -x[2])*cos(x[0]-x[2]) + alpha*sin(x[2])*cos(x[2]-x[0]) )
          / ( 1 + alpha*pow(sin(x[0]-x[2]),2) );
dxdt[2] = x[3];
dxdt[3] = ( -dxdt[1] * cos(x[0]-x[2]) 
            +x[1]*x[1] * sin(x[0]-x[2]) - sin(x[2]) ) / beta;

return GSL_SUCCESS;
}

//------------------------------------------------------------------------


int jac(double t, const double x[], double *dfdx, double dxdt[],
        void *params)

{
return GSL_SUCCESS;
}


//------------------------------------------------------------------------

int main( int argc, char *argv[] )

{

//-- Definition der Variablen
int    n, nout;
double t, tend, dt, t1, E, x[4];
double phi1_0, phi2_0, v_phi1_0, v_phi2_0, rtol, atol, h;
double mu = 10;
std::ifstream in_stream;
std::ofstream out_stream;

//-- Fehlermeldung, wenn Input- und Outputfilename nicht uebergeben wurden
if (argc<3)
  {
  std::cout << " Aufruf: dpendel1 infile outfile\n";
  return 0;
  }

//-- Einlesen der Parameter --
in_stream.open(argv[1]);
out_stream.open(argv[2]);
out_stream << "! Ergebnis-Datei generiert von dpendel1.cpp\n";
inout(tend,"tend");          inout(phi1_0,"phi1_0");
inout(phi2_0,"phi2_0");      inout(v_phi1_0,"v_phi1_0");
inout(v_phi2_0,"v_phi2_0");  inout(alpha,"alpha");
inout(beta,"beta");          inout(nout,"nout");
in_stream.close();
rtol = 1.e-8;
atol = 1.e-8;

//-- Initialisierung der Bibliotheksroutine
const gsl_odeiv_step_type *T = gsl_odeiv_step_rkf45;
gsl_odeiv_step    *s = gsl_odeiv_step_alloc(T, 4);
gsl_odeiv_control *c = gsl_odeiv_control_y_new(atol, rtol);
gsl_odeiv_evolve  *e = gsl_odeiv_evolve_alloc(4);
gsl_odeiv_system  sys = {f, jac, 4, &mu};

//-- Berechnung einiger benoetigter Parameter --
dt = tend / nout;
h = 1.e-6;

x[0] = phi1_0;     x[1] = v_phi1_0;
x[2] = phi2_0;     x[3] = v_phi2_0;

E = 0.5 * x[1]*x[1] + 0.5 * alpha * (x[1]*x[1]+ pow(beta*x[3],2)
    + 2 * beta * x[1] * x[3] * cos(x[0]-x[2]))
    - cos(x[0]) - alpha *  (cos(x[0])+beta*cos(x[2]));
out_stream << 0 << " " << x[0] << " " << x[1] << " " 
                       << x[2] << " " << x[3] << " " << E << "\n";

t = 0;
for (n=1; n<=nout; n++)                
  {
  t1 = n * dt;
  while (t<t1)
    {
    int status = gsl_odeiv_evolve_apply(e, c, s, &sys, &t, t1, &h, x);
    if (status != GSL_SUCCESS) break;
    }
  E = 0.5 * x[1]*x[1] + 0.5 * alpha * (x[1]*x[1]+ pow(beta*x[3],2)
      + 2 * beta * x[1] * x[3] * cos(x[0]-x[2]))
      - cos(x[0]) - alpha *  (cos(x[0])+beta*cos(x[2]));

  out_stream << t << " " << x[0] << " " << x[1] << " " 
                         << x[2] << " " << x[3] << " " << E << "\n";
  }

gsl_odeiv_evolve_free(e);
gsl_odeiv_control_free(c);
gsl_odeiv_step_free(s);

out_stream.close();
}
/*************************************************************************
* This program is licensed under the terms of the                        *
*                    GNU General Public License.                         *
* For details see https://www.gnu.org/licenses/gpl-3.0.html, the file    *
* gpl.txt in this directoy, or Appendix E in the book                    *
* "Numerische Physik" by Harald Wiedemann                                *
*************************************************************************/
