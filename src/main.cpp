#include<iostream>
#include "AbstractFactory.h"
#include "Builder.h"
#include "FactoryMethod.h"
#include "Prototype.h"
#include "Singleton.h"
#include "Adapter.h"
#include "Bridge.h"

int main()
{
    //抽象工厂模式 
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
    
    //生成器模式 
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
    
    //工厂方法模式 
    RadioFactory* pMac = new MacRadioFactory();
    pMac->CreateRadio();
    RadioFactory* pWin = new WinRadioFactory();
    pWin->CreateRadio();
    delete pMac;
    pMac = NULL;
    delete pWin;
    pWin = NULL;
    
    //原型模式 
    Prototype* pTypeA = new ConcretePrototype();
    Prototype* pTypeB = pTypeA->clone();
    delete pTypeA;
    pTypeA = NULL;
    delete pTypeB;
    pTypeB = NULL;
    
    //单例模式 
    Singleton* pInstance = Singleton::Instance();
    Singleton* pInstance1 = Singleton::Instance();
    cout<<"pInstance : "<<pInstance<<endl;
    cout<<"pInstance1 : "<<pInstance1<<endl;
    
    //适配器模式 
    Adapter* pAdapter = new Adapter();
    pAdapter->Request();
    Adapter1* pAdapter1 = new Adapter1();
    pAdapter1->Request();
    delete pAdapter;
    pAdapter = NULL;
    delete pAdapter1;
    pAdapter1 = NULL;
    
    //桥接模式
    DrawingAPI* pDraw1 = new DrawingCircle();
    DrawingAPI* pDraw2 = new DrawingTriangle();
    Shape* pShape1 = new CircleShape(pDraw1);
    Shape* pShape2 = new TriangleShape(pDraw2);
    pShape1->drawShape();
    pShape2->drawShape();
    delete pDraw1;
    pDraw1 = NULL;
    delete pDraw2;
    pDraw2 = NULL;
    delete pShape1;
    pShape1 = NULL;
    delete pShape2;
    pShape2 = NULL;
    system("pause");
    return 0;
}
