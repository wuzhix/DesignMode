#include<iostream>
#include "AbstractFactory.h"
#include "Builder.h"

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
    delete button;
    delete border;
    
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
    delete b1;
    delete b2;
    
    system("pause");
    return 0;
}
