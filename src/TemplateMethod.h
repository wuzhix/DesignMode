#ifndef __TemplateMethod_h__
#define __TemplateMethod_h__
/**
 * 模板方法模式 
 * 策定义一个操作中的算法骨架，而将一些步骤延迟到子类中。 
 */
 
class AbstractClass
{
public:
     void TemplateMethod()
     {
          PrimitiveOperation1();
          cout<<"TemplateMethod"<<endl;
          PrimitiveOperation2();
     }

protected:
     virtual void PrimitiveOperation1()
     {
          cout<<"Default Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"Default Operation2"<<endl;
     }
};

class ConcreteClassA : public AbstractClass
{
protected:
     virtual void PrimitiveOperation1()
     {
          cout<<"ConcreteA Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"ConcreteA Operation2"<<endl;
     }
};

class ConcreteClassB : public AbstractClass
{
protected:
     virtual void PrimitiveOperation1()
     {
          cout<<"ConcreteB Operation1"<<endl;
     }

     virtual void PrimitiveOperation2()
     {
          cout<<"ConcreteB Operation2"<<endl;
     }
};
#endif
