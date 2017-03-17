#ifndef __Builder_h__
#define __Builder_h__
#include <string>
#include <iostream>

using namespace std;
/**
 * ������ģʽ 
 * �����Խ����Ӷ���Ľ�����̳��������������𣩣�ʹ���������̵Ĳ�ͬʵ�ַ������Թ������ͬ���֡� 
 * ���������ʹ��������ģʽ��
 *   ���������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽʱ
 *   ��������̱�����������Ķ����в�ͬ�ı�ʾʱ
 * �����ߣ�
 *   Builder
 *     Ϊ����һ��Product����ĸ�������ָ������ӿ�
 *   ConcreteBuilder
 *     ʵ��Builder�Ľӿ��Թ����װ��ò�Ʒ�ĸ�������
 *     ���岢��ȷ���������ı�ʾ
 *     �ṩһ��������Ʒ�Ľӿ�
 *   Director
 *     ����һ��ʹ��Builder�ӿڵĶ���
 *   Product
 *     ��ʾ������ĸ��Ӷ���ConcreateBuilder�����ò�Ʒ���ڲ���ʾ����������װ�����
 *     ����������ɲ������࣬��������Щ����װ������ղ�Ʒ�Ľӿ�
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
        product->add("����A");
    }
    virtual void builderPartB()
    {
        product->add("����B");
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
        product->add("����X");
    }
    virtual void builderPartB()
    {
        product->add("����Y");
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
