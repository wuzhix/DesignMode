#ifndef __Adapter_h__
#define __Adapter_h__
/**
 * 适配器模式 
 * 将一个类的接口转接成用户所期待的。
 * 一个适配使得因接口不兼容而不能在一起工作的类工作在一起，做法是将类自己的接口包裹在一个已存在的类中。
 */
class Target
{
public:
    virtual void Request(){}
};

class Adaptee
{
public:
    void SpecificRequest(){}
};

//类适配器 
class Adapter : public Adaptee, public Target
{
public:
    virtual void Request()
    {
        this->SpecificRequest();
    }
};

//对象适配器
class Adapter1 : public Target
{
private:
    Adaptee* pAdaptee;
public:
    Adapter1()
    {
        pAdaptee = new Adaptee();
    }
    virtual ~Adapter1()
    {
        delete pAdaptee;
        pAdaptee = NULL;
    }
    virtual void Request()
    {
        pAdaptee->SpecificRequest();
    }
};

#endif
