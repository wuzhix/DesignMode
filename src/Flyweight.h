#ifndef __Flyweight_h__
#define __Flyweight_h__
/**
 * ��Ԫģʽ
 * ���ù�������Ч��֧�ִ���ϸ���ȵĶ���
 * Flyweight����Ԫ��Ļ��࣬����һ���ӿڣ�ͨ������ӿ�Flyweight���Խ��ܲ��������ⲿ״̬��
 * ConcreteFlyweight��ʵ��Flyweight�ӿڣ� ��Ϊ�ڲ�״̬�� ����еĻ��� ���Ӵ洢�ռ䡣ConcreteFlyweight��������ǿɹ���ġ������洢��״̬�������ڲ��ģ�intrinsic�������������������ConcreteFlyweight����ĳ�����
 * UnsharedConcreteFlyweight���������е�Flyweight���඼��Ҫ������Flyweight�ӿ�ʹ�����Ϊ���ܣ���������ǿ�ƹ�����Flyweight����ṹ��ĳЩ��Σ�UnsharedConcreteFlyweight����ͨ����ConcreteFlyweight������Ϊ�ӽڵ㡣
 * FlyweightFactory��
 * 1�� ����������Flyweight����
 * 2��ȷ������ع���Flyweight�����û�����һ��Flyweightʱ��FlyweightFactory�����ṩһ���Ѵ�����ʵ�����ߴ���һ������������ڵĻ���
 * Client
 * 1��ά��һ����Flyweight�����á�
 * 2�������洢һ���������Flyweight���ⲿ״̬��
 * ��Ԫģʽ���Ա�������ǳ�������Ŀ�����
 * �ڳ�������У���ʱ��Ҫ���ɴ���ϸ���ȵ���ʵ������ʾ���ݡ�
 * ����ܷ�����Щʵ�����ݳ��˼������������������ͬ�ġ�
 * ��ʱ���ܹ�����ȵؼ���ʵ���������������
 * ����ܰ���Щ�����Ƶ���ʵ�������棬�ڷ�������ʱ�����Ǵ��ݽ������Ϳ���ͨ���������ȵؼ��ٵ���ʵ������Ŀ��
 */

//���࣬��������ӿ�Operation
class Flyweight
{
public:
    //�����ⲿ״̬extrinsicState
    virtual void Operation(const string& extrinsicState) = 0;
    string GetIntrinsicState(){return _intrinsicState;}
    virtual ~Flyweight(){}
protected:
    Flyweight(string intrinsicState){_intrinsicState = intrinsicState;}
private:
    //�ڲ�״̬��Ҳ���Է���ConcreteFlyweight��
    string _intrinsicState;
};

class ConcreteFlyweight : public Flyweight
{
public:
    //ʵ�ֽӿں���
    virtual void Operation(const string& extrinsicState)
    {
        cout<<GetIntrinsicState()<<endl;
        cout<<extrinsicState<<endl;
    }
    ConcreteFlyweight(string intrinsicState):Flyweight(intrinsicState){}
    ~ConcreteFlyweight(){}
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    virtual void Operation(const string& extrinsicState){cout<<"extrinsicState"<<endl;}
    UnsharedConcreteFlyweight(string intrinsicState):Flyweight(intrinsicState){}
    ~UnsharedConcreteFlyweight(){}
};

class FlyweightFactory
{
public:
    FlyweightFactory(){}
    ~FlyweightFactory(){}
    //���һ�������Flyweight����
    Flyweight* GetFlyweight(string key)
    {
        vector<Flyweight*>::iterator iter = m_vecFly.begin();
        for(;iter!= m_vecFly.end();iter++)
        {
            if((*iter)->GetIntrinsicState() == key)
            {
                return *iter;
            }
        }
        Flyweight* fly = new ConcreteFlyweight(key);
        m_vecFly.push_back(fly);
        return fly;
    }
    //��ȡ�����д洢�Ķ�������
    void GetFlyweightCount(){cout<<m_vecFly.size()<<endl;}
protected:
private:
    //�����ڲ�״̬���������
    vector<Flyweight*> m_vecFly;
};
#endif
