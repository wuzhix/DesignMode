#ifndef __Strategy_h__
#define __Strategy_h__
/**
 * ����ģʽ 
 * ����ģʽ��Ϊһ��������ģʽ��ָ������ĳ����Ϊ�������ڲ�ͬ�ĳ����У�����Ϊ�в�ͬ��ʵ���㷨��
 * ����ÿ���˶�Ҫ������������˰�������ǡ�����������������˰���͡����й�����������˰�����в�ͬ����˰������
 * ������һ���㷨��ҵ����򣩣�
 * ��װ��ÿ���㷨��
 * ������㷨�ɻ������棨interchangeable���� 
 */
 
class StrategyInterface
{
public:
    virtual void execute() = 0;
};

class ConcreteStrategyA: public StrategyInterface
{
public:
    virtual void execute()
    {
        cout << "Called ConcreteStrategyA execute method" << endl;
    }
};

class ConcreteStrategyB: public StrategyInterface
{
public:
    virtual void execute()
    {
        cout << "Called ConcreteStrategyB execute method" << endl;
    }
};

class ConcreteStrategyC: public StrategyInterface
{
public:
    virtual void execute()
    {
        cout << "Called ConcreteStrategyC execute method" << endl;
    }
};

class Strategy
{
private:
    StrategyInterface *_strategy;

public:
    Strategy(StrategyInterface *strategy):_strategy(strategy)
    {
    }

    void set_strategy(StrategyInterface *strategy)
    {
        _strategy = strategy;
    }

    void execute()
    {
        _strategy->execute();
    }
};
#endif
