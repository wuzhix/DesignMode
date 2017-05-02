#ifndef __State_h__
#define __State_h__
/**
 * ״̬ģʽ 
 * ����һ�����������ڲ�״̬�ı�ʱ�ı�������Ϊ��
 * ���������ƺ��޸��������ࡣ
 * ״̬ģʽ���ص�����״̬ת�����ܶ�ʱ�򣬶���һ�������״̬�����Ƕ���������������һ��״̬�����ԣ�
 * ���״̬���Լ�¼�Ŷ���ľ���״̬������״̬�Ĳ�ͬʹ�÷�֧�ṹ��ִ�в�ͬ�Ĺ��ܣ���������Ĵ�����������
 * ��������˵�ģ����д��ڴ����Ľṹ���Ƶķ�֧��䣬�������ά������⡣
 * ״̬ģʽ�����˷�֧��䣬���񹤳�ģʽ�����˼򵥹���ģʽ�ķ�֧���һ����
 * ��״̬�����ɢ������״̬������ȥ��ÿ�����༯�д���һ��״̬��������ʹ��״̬�Ĵ����ת��������ȷ��
 */
 
class Role;

class State
{
public:
     virtual void Handle(Role *pRole) = 0;
};

class ConcreteStateA : public State
{
public:
     virtual void Handle(Role *pRole)
     {
          cout<<"I am concretestateA."<<endl;
     }
};

class ConcreteStateB : public State
{
public:
     virtual void Handle(Role *pRole)
     {
          cout<<"I am concretestateB."<<endl;
     }
};

class Role
{
public:
     Role(State *pState) : m_pState(pState){}

     void Request()
     {
          if (m_pState)
          {
               m_pState->Handle(this);
          }
     }

     void ChangeState(State *pState)
     {
          m_pState = pState;
     }

private:
     State *m_pState;
};
#endif
