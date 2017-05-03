#ifndef __Strategy_h__
#define __Strategy_h__
/**
 * 策略模式 
 * 策略模式作为一种软件设计模式，指对象有某个行为，但是在不同的场景中，该行为有不同的实现算法。
 * 比如每个人都要“交个人所得税”，但是“在美国交个人所得税”和“在中国交个人所得税”就有不同的算税方法。
 * 定义了一族算法（业务规则）；
 * 封装了每个算法；
 * 这族的算法可互换代替（interchangeable）。 
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
