#ifndef __Visitor_h__
#define __Visitor_h__
/**
 * 访问者模式 
 * 我们去银行柜台办业务，一般情况下会开几个个人业务柜台的，你去其中任何一个柜台办理都是可以的。
 * 我们的访问者模式可以很好付诸在这个场景中：对于银行柜台来说，他们是不用变化的，就是说今天和明天提供个人业务的柜台是不需要有变化的。
 * 而我们作为访问者，今天来银行可能是取消费流水，明天来银行可能是去办理手机银行业务，这些是我们访问者的操作，一直是在变化的。
 * 访问者模式就是表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。 
 */
#include<list>

using namespace std;
 
class Element;  
  
class Visitor  
{  
public:  
    virtual void Visit( Element *element ){}
};  
  
// "Element"  
class Element  
{  
public:  
    // Methods  
    virtual void Accept( Visitor *visitor ){}
};  
  
  
// "ConcreteElement"  
class Employee : public Element  
{  
public:  
    string name;  
    double income;  
    int vacationDays;  
public :  
    Employee( string name, double income, int vacationDays )  
    {  
        this->name = name;  
        this->income = income;  
        this->vacationDays = vacationDays;  
    }  
  
    void Accept( Visitor *visitor )  
    {  
        visitor->Visit( this );  
    }  
};  
  
class IncomeVisitor : public Visitor  
{  
public:   
    void Visit( Element *element )  
    {  
        Employee *employee = ((Employee*)element);  
        employee->income *= 1.10;  
        cout<<employee->name<<" 's new income: " <<employee->income<<endl;  
    }  
};  
  
class VacationVisitor : public Visitor  
{  
public :  
    void Visit( Element *element )  
    {  
        Employee *employee = ((Employee*)element);  
        // Provide 3 extra vacation days  
        employee->vacationDays += 3;       
        cout<<employee->name<<" 's new vacation days: " <<employee->vacationDays<<endl;  
    }  
};  
  
// "ObjectStructure"  
class Employees  
{     
private :  
    list< Employee*> employees;  
public :  
    void Attach( Employee *employee )  
    {         
        employees.push_back(employee);        
    }  
    void Detach( Employee *employee )  
    {  
        employees.remove(employee);       
    }  
    void Accept( Visitor *visitor )  
    {         
        for (std::list<Employee*>::iterator it=employees.begin(); it != employees.end(); ++it)  
        { 
            (*it)->Accept(visitor);  
        }
    }  
};
#endif
