#ifndef __State_h__
#define __State_h__
/**
 * 状态模式 
 * 允许一个对象在其内部状态改变时改变它的行为。
 * 对象看起来似乎修改了它的类。
 * 状态模式的重点在于状态转换，很多时候，对于一个对象的状态，我们都是让这个对象包含一个状态的属性，
 * 这个状态属性记录着对象的具体状态，根据状态的不同使用分支结构来执行不同的功能，就像上面的代码那样处理；
 * 就像上面说的，类中存在大量的结构类似的分支语句，变得难以维护和理解。
 * 状态模式消除了分支语句，就像工厂模式消除了简单工厂模式的分支语句一样，
 * 将状态处理分散到各个状态子类中去，每个子类集中处理一种状态，这样就使得状态的处理和转换清晰明确。
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
