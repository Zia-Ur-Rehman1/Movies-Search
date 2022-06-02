#include <iostream>
#include "classes.h"
using namespace std;
int main()
{
    int condition;
    float value;
    File_handling objf;
    objf.read();
    do
    {
        std::cout << "Press 1 to Check Movie Having Max rating and Min Rating:" << '\n';
        std::cout << "Press 2 to Check Movies Having Same Rating:" << '\n';
        std::cin >> condition;
        switch (condition)
        {
        case 1:
            objf.display();
            break;
        case 2:
            std::cout << "Give the Rating You want to check At:" << '\n';
            std::cin >> value;
            objf.check(value);
            break;
        default:
            std::cout << "You have given Wrong Input:" << '\n';
        }
        std::cout << "Press 0 to stop program else press 1:" << '\n';
        std::cin >> condition;
    }
    while(condition!=0);
    return(0);
}
