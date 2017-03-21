#ifndef __Prototype_h__
#define __Prototype_h__
/**
 * ԭ��ģʽ 
 * ԭ��ģʽ�Ǵ�����ģʽ��һ��,���ص�����ͨ�������ơ�һ���Ѿ����ڵ�ʵ���������µ�ʵ��,�������½�ʵ����
 * �����Ƶ�ʵ�������������Ƶġ�ԭ�͡������ԭ���ǿɶ��Ƶġ�
 * ԭ��ģʽ�����ڴ������ӵĻ��ߺ�ʱ��ʵ������Ϊ��������£�����һ���Ѿ����ڵ�ʵ��ʹ�������и���Ч��
 * ���ߴ���ֵ��ȣ�ֻ��������һ����ͬ�����ݡ�
 */
 
class Prototype
{
public:
    Prototype(){}
    virtual ~Prototype(){}
    
    virtual Prototype* clone() = 0;
};

class ConcretePrototype : public Prototype
{
private :
    int m_counter;
public:
    ConcretePrototype():m_counter(0){}
    virtual ~ConcretePrototype(){}

    ConcretePrototype(const ConcretePrototype& rhs)
    {
        m_counter = rhs.m_counter;
    }

    //��������
    virtual Prototype* clone()
    {
        //���ÿ������캯��
        return new ConcretePrototype(*this);
    }
};

#endif
