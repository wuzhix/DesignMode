#ifndef __Command_h__
#define __Command_h__
/**
 * ����ģʽ
 * ����ģʽ��Ӣ�Command pattern����һ�����ģʽ���������Զ���������ʵ���ж���
 * ���������԰��ж�(action) ���������װ������������Щ�ж����Ա���
 *   �ظ����
 *   ȡ��������ö�����ʵ�ֵĻ���
 *   ȡ������������
 * ��Щ�����ִ�����Ӧ�ó���������Ĺ��ܣ����������������ظ���������֮�⣬����������ģʽ��ʵ�ֵĹ������ӻ��У�
 *   ������Ϊ
 *   ������
 *   ��
 *   �û����水ť�����ܱ���Ŀ
 *   �߳� pool
 *   ����¼
 */

class Barbecuer
{
public:
    void BakeMutton(){cout<<"Bake mutton"<<endl;}
    void BakeChickenWing(){cout<<"Bake ChickenWing"<<endl;}
};

/*���������ࣺ��ִ�о�������Ľӿ�*/
class Command
{
public:
    Command(){}
    Command(Barbecuer *receiver):p_receiver(receiver){}
    virtual void ExecuteCommand() = 0; //ִ������
protected:
    Barbecuer *p_receiver;
};

/*����������:�����⴮����*/
class BakeMuttonCommand:public Command
{
public:
    BakeMuttonCommand(Barbecuer *receiver){p_receiver = receiver;}
    void ExecuteCommand(){p_receiver->BakeMutton();}
};

/*����������:�����ᴮ����*/
class BakeChickenWingCommand:public Command
{
public:
    BakeChickenWingCommand(Barbecuer *receiver){p_receiver = receiver;}
    void ExecuteCommand(){p_receiver->BakeChickenWing();}
};

/*����Ա��*/
class Waiter
{
public:
    void SetOrder(Command *command)
    {
        p_commandList.push_back(command);
        cout << "���ӿ�������" << endl;
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
    vector<Command *>p_commandList; //�����൱��һ������������
};
#endif
