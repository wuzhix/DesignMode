#ifndef __TemplateMethod_h__
#define __TemplateMethod_h__
/**
 * ģ�巽��ģʽ 
 * �߶���һ�������е��㷨�Ǽܣ�����һЩ�����ӳٵ������С� 
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
