#ifndef __Command_h__
#define __Command_h__
/**
 * 命令模式
 * 命令模式（英语：Command pattern）是一种设计模式，它尝试以对象来代表实际行动。
 * 命令对象可以把行动(action) 及其参数封装起来，于是这些行动可以被：
 *   重复多次
 *   取消（如果该对象有实现的话）
 *   取消后又再重做
 * 这些都是现代大型应用程序所必须的功能，即“撤消”及“重复”。除此之外，可以用命令模式来实现的功能例子还有：
 *   交易行为
 *   进度列
 *   向导
 *   用户界面按钮及功能表项目
 *   线程 pool
 *   宏收录
 */

class Barbecuer
{
public:
    void BakeMutton(){cout<<"Bake mutton"<<endl;}
    void BakeChickenWing(){cout<<"Bake ChickenWing"<<endl;}
};

/*抽象命令类：是执行具体操作的接口*/
class Command
{
public:
    Command(){}
    Command(Barbecuer *receiver):p_receiver(receiver){}
    virtual void ExecuteCommand() = 0; //执行命令
protected:
    Barbecuer *p_receiver;
};

/*具体命令类:烤羊肉串命令*/
class BakeMuttonCommand:public Command
{
public:
    BakeMuttonCommand(Barbecuer *receiver){p_receiver = receiver;}
    void ExecuteCommand(){p_receiver->BakeMutton();}
};

/*具体命令类:烤鸡翅串命令*/
class BakeChickenWingCommand:public Command
{
public:
    BakeChickenWingCommand(Barbecuer *receiver){p_receiver = receiver;}
    void ExecuteCommand(){p_receiver->BakeChickenWing();}
};

/*服务员类*/
class Waiter
{
public:
    void SetOrder(Command *command)
    {
        p_commandList.push_back(command);
        cout << "增加烤肉命令" << endl;
    }
    void Notify()
    {
        vector<Command*>::iterator i;
        for(i = p_commandList.begin(); i != p_commandList.end(); ++ i)
        {
            (*i)->ExecuteCommand();
        }
    }
private:
    vector<Command *>p_commandList; //这里相当于一个命令对象队列
};
#endif
