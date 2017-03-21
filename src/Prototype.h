#ifndef __Prototype_h__
#define __Prototype_h__
/**
 * 原型模式 
 * 原型模式是创建型模式的一种,其特点在于通过“复制”一个已经存在的实例来返回新的实例,而不是新建实例。
 * 被复制的实例就是我们所称的“原型”，这个原型是可定制的。
 * 原型模式多用于创建复杂的或者耗时的实例，因为这种情况下，复制一个已经存在的实例使程序运行更高效；
 * 或者创建值相等，只是命名不一样的同类数据。
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

    //复制自身
    virtual Prototype* clone()
    {
        //调用拷贝构造函数
        return new ConcretePrototype(*this);
    }
};

#endif
