#ifndef __Visitor_h__
#define __Visitor_h__
/**
 * ������ģʽ 
 * ����ȥ���й�̨��ҵ��һ������»Ὺ��������ҵ���̨�ģ���ȥ�����κ�һ����̨�����ǿ��Եġ�
 * ���ǵķ�����ģʽ���Ժܺø�������������У��������й�̨��˵�������ǲ��ñ仯�ģ�����˵����������ṩ����ҵ��Ĺ�̨�ǲ���Ҫ�б仯�ġ�
 * ��������Ϊ�����ߣ����������п�����ȡ������ˮ�����������п�����ȥ�����ֻ�����ҵ����Щ�����Ƿ����ߵĲ�����һֱ���ڱ仯�ġ�
 * ������ģʽ���Ǳ�ʾһ��������ĳ����ṹ�еĸ�Ԫ�صĲ�������ʹ������ڲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²����� 
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
