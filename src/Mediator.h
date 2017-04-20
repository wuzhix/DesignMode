#ifndef __Mediator_h__
#define __Mediator_h__
/**
 * �н���ģʽ
 * ��һ���н��������װһϵ�еĶ��󽻻���
 * �н���ʹ��������Ҫ��ʽ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ظı�����֮��Ľ�����
 * �н���ģʽ�����Ӻܶ࣬�����Ϲ�����ᣬС�������н飬���������м��ߵĽ�ɫ��Э���������档
 * �н���ģʽ��������ϵͳ��Ӧ�ã�Ҳ��������ϵͳ�����á�
 * ��ϵͳ�����˶�Զཻ�����ӵĶ���Ⱥʱ����Ҫ����ʹ���н���ģʽ����Ҫ�ȷ�˼���ϵͳ��������ǲ��Ǻ���
 * �ŵ㣺Mediator�ĳ��ּ����˸���Colleague����ϣ�ʹ�ÿ��Զ����ظı�͸��ø���Colleague���Mediator��
 *       ���ڰѶ������Э�������˳��󣬽��н���Ϊһ�������ĸ�������װ��һ�������У�������ע�Ķ���ʹӶ�����Ա������Ϊת�Ƶ�����֮��Ľ���������Ҳ����վ��һ������۵ĽǶ�ȥ����ϵͳ��
 * ȱ�㣺����ConcreteMediator�����˼��л������ǾͰѽ����ĸ����Ա�Ϊ���н��ߵĸ����ԣ�ʹ���н��߱��κ�һ��ConcreteColleague�����ӡ�
 */

/*���������н���*/
class Mediator;

/*�����������*/
class Person
{
public:
    virtual void SetMediator(Mediator *mediator){}
    virtual void SendMessage(string message){}
    virtual void GetMessage(string message){}
protected:
    Mediator *p_mediator; //�н�
};

/*��������н���*/
class Mediator
{
public:
    virtual void Send(string &message, Person *person){}
    virtual void SetRenter(Person *renter){}
    virtual void SetLandlord(Person *landlord){}

};

/*���������*/
class Renter:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string message){p_mediator->Send(message,this);}
    void GetMessage(string message){cout<<"�ⷿ���յ�������������Ϣ��"<<message;}
};

/*���巿����*/
class Landlord:public Person
{
public:
    void SetMediator(Mediator *mediator){p_mediator = mediator;}
    void SendMessage(string message){p_mediator->Send(message,this);}
    void GetMessage(string message){cout<<"�����յ���ͷ�������Ϣ��"<<message;}
};

/*��������н���*/
class HouseMediator:public Mediator
{
public:
    HouseMediator():p_renter(NULL),p_landlord(NULL){}
    void SetRenter(Person *renter){p_renter = renter;}
    void SetLandlord(Person *landlord){p_landlord = landlord;}
    void Send(string &message, Person *person)
    {
        //������Ϣ�Ķ���Ϊ�ö���Ķ�Ӧ����
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
