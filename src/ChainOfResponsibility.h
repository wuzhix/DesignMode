#ifndef __ChainOfResponsibility_h__
#define __ChainOfResponsibility_h__
/**
 * 责任链模式
 * 它包含了一些命令对象和一系列的处理对象。
 * 每一个处理对象决定它能处理哪些命令对象，它也知道如何将它不能处理的命令对象传递给该链中的下一个处理对象。
 * 该模式还描述了往该处理链的末尾添加新的处理对象的方法。
 */

//抽象管理者
class Manager
{
protected:
    Manager *m_manager;
    string m_name;
public:
    Manager(Manager *manager, string name):m_manager(manager), m_name(name){}
    virtual void DealWithRequest(string name, int num){}
};

//经理
class CommonManager : public Manager
{
public:
    CommonManager(Manager *manager, string name):Manager(manager,name){}
    void DealWithRequest(string name, int num)
    {
        if(num < 500) //经理职权之内
        {
            cout<<"经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;
        }
        else
        {
            cout<<"经理"<<m_name<<"无法处理，交由总监处理"<<endl;
            m_manager->DealWithRequest(name, num);
        }
    }
};

//总监
class Majordomo : public Manager
{
public:
    Majordomo(Manager *manager, string name):Manager(manager,name){}
    void DealWithRequest(string name, int num)
    {
        if(num < 1000) //总监职权之内
        {
            cout<<"总监"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;
        }
        else
        {
            cout<<"总监"<<m_name<<"无法处理，交由总经理处理"<<endl;
            m_manager->DealWithRequest(name, num);
        }
    }
};

//总经理
class GeneralManager : public Manager
{
public:
    GeneralManager(Manager *manager, string name):Manager(manager,name){}
    void DealWithRequest(string name, int num)  //总经理可以处理所有请求
    {
        cout<<"总经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl<<endl;
    }
};
#endif
