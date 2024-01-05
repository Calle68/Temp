#include <iostream>
#include <string>

using namespace std;

int main()
{
    int intZahl;
    // unsind int unsigndZahl;
    double doubleZahl;

    char buchstabe;
    string einString;


    std::cout << "Int Zahl?" << std::endl;
    std::cin >> intZahl;
    std::cout << sizeof(intZahl) << std::endl;
    
    std::cout << "Double Zahl?" << std::endl;
    std::cin >> doubleZahl;
    std::cout << sizeof(doubleZahl) << std::endl;

    std::cout << "Char?" << std::endl;
    std::cin >> buchstabe;
    std::cout << sizeof(buchstabe) << std::endl;

    std::cout << "String?" << std::endl;
    std::cin >> einString;
    std::cout << sizeof(einString) << std::endl;
}