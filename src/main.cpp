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
    //���󹤳�ģʽ
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

    //������ģʽ
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

    //��������ģʽ
    RadioFactory* pMac = new MacRadioFactory();
    pMac->CreateRadio();
    RadioFactory* pWin = new WinRadioFactory();
    pWin->CreateRadio();
    SAFE_DELETE(pMac);
    SAFE_DELETE(pWin);

    //ԭ��ģʽ
    Prototype* pTypeA = new ConcretePrototype();
    Prototype* pTypeB = pTypeA->clone();
    SAFE_DELETE(pTypeA);
    SAFE_DELETE(pTypeB);

    //����ģʽ
    Singleton* pInstance = Singleton::Instance();
    Singleton* pInstance1 = Singleton::Instance();
    cout<<"pInstance : "<<pInstance<<endl;
    cout<<"pInstance1 : "<<pInstance1<<endl;

    //������ģʽ
    Adapter* pAdapter = new Adapter();
    pAdapter->Request();
    Adapter1* pAdapter1 = new Adapter1();
    pAdapter1->Request();
    SAFE_DELETE(pAdapter);
    SAFE_DELETE(pAdapter1);

    //�Ž�ģʽ
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

    //���ģʽ
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

    //װ��ģʽ
    Widget* aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator(new TextField(80, 24))));
    aWidget->draw();
    SAFE_DELETE(aWidget);

    //���ģʽ
    CPU* pCpu = new CPU();
    Memory* pMemory = new Memory();
    HardDrive* pHardDrive = new HardDrive();
    Computer* pComputer = new Computer(pCpu, pMemory, pHardDrive);
    SAFE_DELETE(pCpu);
    SAFE_DELETE(pMemory);
    SAFE_DELETE(pHardDrive);
    SAFE_DELETE(pComputer);

    //��Ԫģʽ
    //�ⲿ״̬extrinsicState
    string extrinsicState = "ext";
    string extrinsicState1 = "ext1";
    //��������
    FlyweightFactory* fc = new FlyweightFactory();
    //�򹤳�����һ��Flyweight�����Ҹö�����ڲ�״ֵ̬Ϊ��hello��
    Flyweight* fly = fc->GetFlyweight("hello");
    Flyweight* fly1 = fc->GetFlyweight("hello");
    //Ӧ���ⲿ״̬
    fly->Operation(extrinsicState);
    fly1->Operation(extrinsicState1);
    fc->GetFlyweightCount();

    //����ģʽ
    CSubject *pSubject = new CProxy();
	pSubject->Request();
	SAFE_DELETE(pSubject);

	//������ģʽ
    Manager *general = new GeneralManager(NULL, "A"); //�����ϼ����ܾ���û���ϼ�
    Manager *majordomo = new Majordomo(general, "B"); //�����ϼ�
    Manager *common = new CommonManager(majordomo, "C"); //�����ϼ�
    common->DealWithRequest("D",300);   //Ա��DҪ���н
    common->DealWithRequest("E", 600);
    common->DealWithRequest("F", 1000);
    SAFE_DELETE(common);
    SAFE_DELETE(majordomo);
    SAFE_DELETE(general);

    //����ģʽ
    //���ɿ���ʦ��������Ա����������
    Barbecuer *p_cook = new Barbecuer();
    Command *p_mutton = new BakeMuttonCommand(p_cook);
    Command *p_chickenwing = new BakeChickenWingCommand(p_cook);
    Waiter *p_waiter = new Waiter();
    //�������������͵��������
    p_waiter->SetOrder(p_mutton);
    p_waiter->SetOrder(p_chickenwing);
    //����Ա֪ͨ����ʦ�����嶩��
    p_waiter->Notify();
    SAFE_DELETE(p_cook);
    SAFE_DELETE(p_mutton);
    SAFE_DELETE(p_chickenwing);
    SAFE_DELETE(p_waiter);

    //������ģʽ
    cout<<"Interpreter test!"<<endl;
    Context *context = new Context();
    AbstractExpression *t = new TerminalExpression();
    AbstractExpression *n = new NonterminalExpression();
    t->interpret(context);
    n->interpret(context);
    SAFE_DELETE(context);
    SAFE_DELETE(t);
    SAFE_DELETE(n);

    //������ģʽ
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

    //�н���ģʽ
    Mediator* mediator = new HouseMediator();
    Person *person1 = new Renter();
    Person *person2 = new Landlord();
    mediator->SetRenter(person1);
    mediator->SetLandlord(person2);
    person1->SetMediator(mediator);
    person2->SetMediator(mediator);
    person1->SendMessage(string("���������ڱ�վ�������׷��ӣ�һ��һ��\n"));
    person2->SendMessage(string("�ҳ���һ�����ӣ�һ��һ�������ڱ�վ����\n"));
    SAFE_DELETE(person1);
    SAFE_DELETE(person2)
    SAFE_DELETE(mediator);

    //����¼ģʽ
    Caretake caretake;
	GameRole role;
	role.Show();   //��ʼֵ
	caretake.Save(role.Save()); //����״̬
	role.Attack();
	role.Show();  //������
	role.Load(caretake.Load(0)); //����״̬
	role.Show();  //�ָ���״̬0

	//�۲���ģʽ
	Secretary* pSecretary = new Secretary();
    // �۲���
    StockObserver* s1 = new StockObserver("Lazy", pSecretary);
    StockObserver* s2 = new StockObserver("SnowFire", pSecretary);
    // ����֪ͨ����
    pSecretary->Add(s1);
    pSecretary->Add(s2);
    // ֪ͨ
    pSecretary->Notify();
    // ��̬ɾ��
    pSecretary->Remove(0);
    pSecretary->Notify();
    SAFE_DELETE(pSecretary);
    SAFE_DELETE(s1);
    SAFE_DELETE(s2);
    
    //״̬ģʽ
    State* pStateA = new ConcreteStateA();
    State* pStateB = new ConcreteStateB();
    Role* pRole = new Role(pStateA);
    pRole->Request();
    pRole->ChangeState(pStateB);
    pRole->Request();
    SAFE_DELETE(pStateA);
    SAFE_DELETE(pStateB);
    SAFE_DELETE(pRole);
    
    //����ģʽ
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
