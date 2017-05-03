#include<iostream>
#include<string>
#include "AbstractFactory.h"
#include "Builder.h"
#include "FactoryMethod.h"
#include "Prototype.h"
#include "Singleton.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Flyweight.h"
#include "Proxy.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "Interpreter.h"
#include "Iterator.h"
#include "Mediator.h"
#include "Memento.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"

#define SAFE_DELETE(p) if (p) {delete p;p = NULL;}

using namespace std;

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
    SAFE_DELETE(fac);
    SAFE_DELETE(button);
    SAFE_DELETE(border);

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
    SAFE_DELETE(director);
    SAFE_DELETE(b1);
    SAFE_DELETE(b2);

    //工厂方法模式
    RadioFactory* pMac = new MacRadioFactory();
    pMac->CreateRadio();
    RadioFactory* pWin = new WinRadioFactory();
    pWin->CreateRadio();
    SAFE_DELETE(pMac);
    SAFE_DELETE(pWin);

    //原型模式
    Prototype* pTypeA = new ConcretePrototype();
    Prototype* pTypeB = pTypeA->clone();
    SAFE_DELETE(pTypeA);
    SAFE_DELETE(pTypeB);

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
    SAFE_DELETE(pAdapter);
    SAFE_DELETE(pAdapter1);

    //桥接模式
    DrawingAPI* pDraw1 = new DrawingCircle();
    DrawingAPI* pDraw2 = new DrawingTriangle();
    Shape* pShape1 = new CircleShape(pDraw1);
    Shape* pShape2 = new TriangleShape(pDraw2);
    pShape1->drawShape();
    pShape2->drawShape();
    SAFE_DELETE(pDraw1);
    SAFE_DELETE(pDraw2);
    SAFE_DELETE(pShape1);
    SAFE_DELETE(pShape2);

    //组合模式
    Component* pLeaf1 = new Leaf();
    Component* pLeaf2 = new Leaf();
    Component* pComposite = new Composite();
    pComposite->Operation();
    pComposite->Add(pLeaf1);
    pComposite->Operation();
    pComposite->Add(pLeaf2);
    pComposite->Operation();
    pComposite->Remove(pLeaf1);
    pComposite->Operation();
    Component* pLeaf = pComposite->GetChild(0);
    pLeaf->Operation();
    SAFE_DELETE(pLeaf1);
    SAFE_DELETE(pLeaf2);
    SAFE_DELETE(pComposite);

    //装饰模式
    Widget* aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator(new TextField(80, 24))));
    aWidget->draw();
    SAFE_DELETE(aWidget);

    //外观模式
    CPU* pCpu = new CPU();
    Memory* pMemory = new Memory();
    HardDrive* pHardDrive = new HardDrive();
    Computer* pComputer = new Computer(pCpu, pMemory, pHardDrive);
    SAFE_DELETE(pCpu);
    SAFE_DELETE(pMemory);
    SAFE_DELETE(pHardDrive);
    SAFE_DELETE(pComputer);

    //享元模式
    //外部状态extrinsicState
    string extrinsicState = "ext";
    string extrinsicState1 = "ext1";
    //工厂对象
    FlyweightFactory* fc = new FlyweightFactory();
    //向工厂申请一个Flyweight对象，且该对象的内部状态值为“hello”
    Flyweight* fly = fc->GetFlyweight("hello");
    Flyweight* fly1 = fc->GetFlyweight("hello");
    //应用外部状态
    fly->Operation(extrinsicState);
    fly1->Operation(extrinsicState1);
    fc->GetFlyweightCount();

    //代理模式
    CSubject *pSubject = new CProxy();
	pSubject->Request();
	SAFE_DELETE(pSubject);

	//责任链模式
    Manager *general = new GeneralManager(NULL, "A"); //设置上级，总经理没有上级
    Manager *majordomo = new Majordomo(general, "B"); //设置上级
    Manager *common = new CommonManager(majordomo, "C"); //设置上级
    common->DealWithRequest("D",300);   //员工D要求加薪
    common->DealWithRequest("E", 600);
    common->DealWithRequest("F", 1000);
    SAFE_DELETE(common);
    SAFE_DELETE(majordomo);
    SAFE_DELETE(general);

    //命令模式
    //生成烤肉师傅、服务员、订单对象
    Barbecuer *p_cook = new Barbecuer();
    Command *p_mutton = new BakeMuttonCommand(p_cook);
    Command *p_chickenwing = new BakeChickenWingCommand(p_cook);
    Waiter *p_waiter = new Waiter();
    //将订单对象推送到命令队列
    p_waiter->SetOrder(p_mutton);
    p_waiter->SetOrder(p_chickenwing);
    //服务员通知烤肉师傅具体订单
    p_waiter->Notify();
    SAFE_DELETE(p_cook);
    SAFE_DELETE(p_mutton);
    SAFE_DELETE(p_chickenwing);
    SAFE_DELETE(p_waiter);

    //解释器模式
    cout<<"Interpreter test!"<<endl;
    Context *context = new Context();
    AbstractExpression *t = new TerminalExpression();
    AbstractExpression *n = new NonterminalExpression();
    t->interpret(context);
    n->interpret(context);
    SAFE_DELETE(context);
    SAFE_DELETE(t);
    SAFE_DELETE(n);

    //迭代器模式
    ConcreteAggregate* pName = NULL;
    pName = new ConcreteAggregate();
    if(NULL != pName)
    {
        pName->Push("hello");
        pName->Push("word");
        pName->Push("cxue");
    }
    Iterator* iter = NULL;
    iter = pName->CreateIterator();
    if(NULL != iter)
    {
        string strItem = iter->First();
        while(!iter->IsEnd())
        {
            cout << iter->GetCur() << " is ok" << endl;
            iter->Next();
        }
    }
    SAFE_DELETE(pName);

    //中介者模式
    Mediator* mediator = new HouseMediator();
    Person *person1 = new Renter();
    Person *person2 = new Landlord();
    mediator->SetRenter(person1);
    mediator->SetLandlord(person2);
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);
    person1->SendMessage(string("我想在深圳北站附近租套房子，一室一厅\n"));
    person2->SendMessage(string("我出租一条房子，一室一厅，深圳北站附近\n"));
    SAFE_DELETE(person1);
    SAFE_DELETE(person2)
    SAFE_DELETE(mediator);

    //备忘录模式
    Caretake caretake;
	GameRole role;
	role.Show();   //初始值
	caretake.Save(role.Save()); //保存状态
	role.Attack();
	role.Show();  //进攻后
	role.Load(caretake.Load(0)); //载入状态
	role.Show();  //恢复到状态0

	//观察者模式
	Secretary* pSecretary = new Secretary();
    // 观察者
    StockObserver* s1 = new StockObserver("Lazy", pSecretary);
    StockObserver* s2 = new StockObserver("SnowFire", pSecretary);
    // 加入通知队列
    pSecretary->Add(s1);
    pSecretary->Add(s2);
    // 通知
    pSecretary->Notify();
    // 动态删除
    pSecretary->Remove(0);
    pSecretary->Notify();
    SAFE_DELETE(pSecretary);
    SAFE_DELETE(s1);
    SAFE_DELETE(s2);
    
    //状态模式
    State* pStateA = new ConcreteStateA();
    State* pStateB = new ConcreteStateB();
    Role* pRole = new Role(pStateA);
    pRole->Request();
    pRole->ChangeState(pStateB);
    pRole->Request();
    SAFE_DELETE(pStateA);
    SAFE_DELETE(pStateB);
    SAFE_DELETE(pRole);
    
    //策略模式
    ConcreteStrategyA concreteStrategyA;
    ConcreteStrategyB concreteStrategyB;
    ConcreteStrategyC concreteStrategyC;
    Strategy contextA(&concreteStrategyA);
    Strategy contextB(&concreteStrategyB);
    Strategy contextC(&concreteStrategyC);
    contextA.execute();
    contextB.execute();
    contextC.execute();
    contextA.set_strategy(&concreteStrategyB);
    contextA.execute();
    contextA.set_strategy(&concreteStrategyC);
    contextA.execute();
 

    system("pause");
    return 0;
}
