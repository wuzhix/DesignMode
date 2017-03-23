#ifndef __Adapter_h__
#define __Adapter_h__
/**
 * ������ģʽ 
 * ��һ����Ľӿ�ת�ӳ��û����ڴ��ġ�
 * һ������ʹ����ӿڲ����ݶ�������һ�������๤����һ�������ǽ����Լ��Ľӿڰ�����һ���Ѵ��ڵ����С�
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

//�������� 
class Adapter : public Adaptee, public Target
{
public:
    virtual void Request()
    {
        this->SpecificRequest();
    }
};

//����������
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
