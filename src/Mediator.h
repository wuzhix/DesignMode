#ifndef __Mediator_h__
#define __Mediator_h__
/**
 * 中介者模式
 * 用一个中介对象来封装一系列的对象交互。
 * 中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。
 * 中介者模式的例子很多，大到联合国安理会，小到房屋中介，都扮演了中间者的角色，协调各方利益。
 * 中介者模式很容易在系统中应用，也很容易在系统中误用。
 * 当系统出现了多对多交互复杂的对象群时，不要急于使用中介者模式，而要先反思你的系统在设计上是不是合理。
 * 优点：Mediator的出现减少了各个Colleague的耦合，使得可以独立地改变和复用各个Colleague类和Mediator；
 *       由于把对象如何协作进行了抽象，将中介作为一个独立的概念并将其封装在一个对象中，这样关注的对象就从对象各自本身的行为转移到它们之间的交互上来，也就是站在一个更宏观的角度去看待系统。
 * 缺点：由于ConcreteMediator控制了集中化。于是就把交互的复杂性变为了中介者的复杂性，使得中介者比任何一个ConcreteColleague都复杂。
 */

/*声明抽象中介类*/
class Mediator;

/*定义抽象人类*/
class Person
{
public:
    virtual void SetMediator(Mediator *mediator){}
    virtual void SendMessage(string message){}
    virtual void GetMessage(string message){}
protected:
    Mediator *p_mediator; //中介
};

/*定义抽象中介类*/
class Mediator
{
public:
    virtual void Send(string &message, Person *person){}
    virtual void SetRenter(Person *renter){}
    virtual void SetLandlord(Person *landlord){}

};

/*定义租客类*/
class Renter:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string message){p_mediator->Send(message,this);}
    void GetMessage(string message){cout<<"租房者收到房东发来的消息："<<message;}
};

/*定义房东类*/
class Landlord:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string message){p_mediator->Send(message,this);}
    void GetMessage(string message){cout<<"房东收到租客发来的消息："<<message;}
};

/*定义具体中介类*/
class HouseMediator:public Mediator
{
public:
    HouseMediator():p_renter(NULL),p_landlord(NULL){}
    void SetRenter(Person *renter){p_renter = renter;}
    void SetLandlord(Person *landlord){p_landlord = landlord;}
    void Send(string &message, Person *person)
    {
        //接收消息的对象为该对象的对应对象
        if(person == p_renter)
        {
            p_landlord->GetMessage(message);
        }
        else
        {
            p_renter->GetMessage(message);
        }
    }
private:
    Person *p_renter;
    Person *p_landlord;
};
#endif
