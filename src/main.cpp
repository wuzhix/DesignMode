#include<iostream>
#include "AbstractFactory.h"

int main()
{
    AbstractFactory* fac;
    enum OS {MAC, WIN};
    int style = MAC;
    switch (style) 
    {
    case MAC:
        fac = new MacFactory;
        break;
    case WIN:
        fac = new WinFactory;
        break;
    }
    Button* button = fac->CreateButton();
    Border* border = fac->CreateBorder();

    return 0;
}
