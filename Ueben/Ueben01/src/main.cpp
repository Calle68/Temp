#include <iostream>

using namespace std;

int main()
{
//int intZahl;
char buchstabe;
/*
std::cout << "Eine int Zahl!" << std::endl;
std::cin >> intZahl;
std::cout << "Die int Zahl ist: " << intZahl << std::endl;
std::cout << "Die Größe der int Zahl ist: " << sizeof(intZahl) << " Byte" << std::endl;
*/

std::cout << "Einen Buchstaben eingeben!" << std::endl;
std::cin >> buchstabe;
std::cout << "Der Buchstabe ist: " << buchstabe << std::endl;
//std::cout << "Die Größe des Buchstabe ist: " << sizeof(buchstabe) << " Byte"<< std::endl;
/*
for(int i = 1; i <= 25; i++)
{
buchstabe = buchstabe + 1;
std::cout << "Der neue Buchstabe ist: " << buchstabe << std::endl;
}
*/

int i=0;
while (i<4)
{
    buchstabe = buchstabe + 1;
    std::cout << "Der neue Buchstabe ist: " << buchstabe << std::endl;
    i++;
}
}
