#include<iostream>
#include "AbstractFactory.h"
#include "Builder.h"
#include "FactoryMethod.h"
#include "Prototype.h"

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
    delete fac;
    fac = NULL;
    delete button;
    button = NULL;
    delete border;
    border = NULL;
    
    Director* director = new Director();
    Builder* b1 = new ConcreteBuilder1();
    Builder* b2 = new ConcreteBuilder2();
    director->construct(b1);
    director->construct(b2);
    Product* p1 = b1->getResult();
    Product* p2 = b2->getResult();
    p1->output();
    p2->output();
    delete director;
    director = NULL;
    delete b1;
    b1 = NULL;
    delete b2;
    b2 = NULL;
    
    RadioFactory* pMac = new MacRadioFactory();
    pMac->CreateRadio();
    RadioFactory* pWin = new WinRadioFactory();
    pWin->CreateRadio();
    delete pMac;
    pMac = NULL;
    delete pWin;
    pWin = NULL;
    
    Prototype* pTypeA = new ConcretePrototype();
    Prototype* pTypeB = pTypeA->clone();
    delete pTypeA;
    pTypeA = NULL;
    delete pTypeB;
    pTypeB = NULL;
            
    system("pause");
    return 0;
}
