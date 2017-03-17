#ifndef __Builder_h__
#define __Builder_h__
#include <string>
#include <iostream>

using namespace std;
/**
 * 生成器模式 
 * 它可以将复杂对象的建造过程抽象出来（抽象类别），使这个抽象过程的不同实现方法可以构造出不同表现。 
 * 在以下情况使用生成器模式：
 *   当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时
 *   当构造过程必须允许被构造的对象有不同的表示时
 * 参与者：
 *   Builder
 *     为创建一个Product对象的各个部件指定抽象接口
 *   ConcreteBuilder
 *     实现Builder的接口以构造和装配该产品的各个部件
 *     定义并明确它所创建的表示
 *     提供一个检索产品的接口
 *   Director
 *     构造一个使用Builder接口的对象
 *   Product
 *     表示被构造的复杂对象。ConcreateBuilder创建该产品的内部表示并定义它的装配过程
 *     包含定义组成部件的类，包括将这些部件装配成最终产品的接口
 */
class Product
{
private:
    string result;
public:
    Product() {result = "";}
    void add(string part) {result += part;}
    void output() {cout<<result<<endl;}
};
 
class Builder
{
public:
    Builder() {};
    virtual ~Builder() {};
    
    virtual void builderPartA() = 0;
    virtual void builderPartB() = 0;
    virtual Product* getResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product *product;
public:
    ConcreteBuilder1()
    {
        product = new Product();
    }
    virtual ~ConcreteBuilder1()
    {
        delete product;
    }
    
    virtual void builderPartA()
    {
        product->add("部件A");
    }
    virtual void builderPartB()
    {
        product->add("部件B");
    }
    virtual Product* getResult()
    {
        return product;
    }  
};

class ConcreteBuilder2 : public Builder
{
private:
    Product *product;
public:
    ConcreteBuilder2()
    {
        product = new Product();
    }
    virtual ~ConcreteBuilder2()
    {
        delete product;
    }
    
    virtual void builderPartA()
    {
        product->add("部件X");
    }
    virtual void builderPartB()
    {
        product->add("部件Y");
    }
    virtual Product* getResult()
    {
        return product;
    }    
};

class Director
{
public:
    void construct(Builder* pBuilder)
    {
        pBuilder->builderPartA();
        pBuilder->builderPartB();
    }
};

#endif
