#ifndef __Flyweight_h__
#define __Flyweight_h__
/**
 * 享元模式
 * 运用共享技术有效地支持大量细粒度的对象。
 * Flyweight：享元类的基类，定义一个接口，通过这个接口Flyweight可以接受并作用于外部状态。
 * ConcreteFlyweight：实现Flyweight接口， 并为内部状态（ 如果有的话） 增加存储空间。ConcreteFlyweight对象必须是可共享的。它所存储的状态必须是内部的（intrinsic）；即，它必须独立于ConcreteFlyweight对象的场景。
 * UnsharedConcreteFlyweight：并非所有的Flyweight子类都需要被共享。Flyweight接口使共享成为可能，但它并不强制共享。在Flyweight对象结构的某些层次，UnsharedConcreteFlyweight对象通常将ConcreteFlyweight对象作为子节点。
 * FlyweightFactory：
 * 1） 创建并管理Flyweight对象。
 * 2）确保合理地共享Flyweight。当用户请求一个Flyweight时，FlyweightFactory对象提供一个已创建的实例或者创建一个（如果不存在的话）
 * Client
 * 1）维持一个对Flyweight的引用。
 * 2）计算或存储一个（多个）Flyweight的外部状态。
 * 享元模式可以避免大量非常相似类的开销。
 * 在程序设计中，有时需要生成大量细粒度的类实例来表示数据。
 * 如果能发现这些实例数据除了几个参数外基本都是相同的。
 * 有时就能够大幅度地减少实例化的类的数量。
 * 如果能把那些参数移到类实例的外面，在方法调用时将它们传递进来，就可以通过共享大幅度地减少单个实例的数目。
 */

//基类，定义操作接口Operation
class Flyweight
{
public:
    //操作外部状态extrinsicState
    virtual void Operation(const string& extrinsicState) = 0;
    string GetIntrinsicState(){return _intrinsicState;}
    virtual ~Flyweight(){}
protected:
    Flyweight(string intrinsicState){_intrinsicState = intrinsicState;}
private:
    //内部状态，也可以放在ConcreteFlyweight中
    string _intrinsicState;
};

class ConcreteFlyweight : public Flyweight
{
public:
    //实现接口函数
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
    //获得一个请求的Flyweight对象
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
    //获取容器中存储的对象数量
    void GetFlyweightCount(){cout<<m_vecFly.size()<<endl;}
protected:
private:
    //保存内部状态对象的容器
    vector<Flyweight*> m_vecFly;
};
#endif
