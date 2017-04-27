#ifndef __Observer_h__
#define __Observer_h__
/**
 * 观察者模式
 * 在此种模式中，一个目标对象管理所有相依于它的观察者对象，并且在它本身的状态改变时主动发出通知。
 * 用途
 *   当抽象个体有两个互相依赖的层面时。封装这些层面在单独的对象内将可允许程序员单独地去变更与重复使用这些对象，而不会产生两者之间交互的问题。
 *   当其中一个对象的变更会影响其他对象，却又不知道多少对象必须被同时变更时。
 *   当对象应该有能力通知其他对象，又不应该知道其他对象的实做细节时。
 */

class Secretary;
// 看股票的同事类（观察对象，观察者）
class StockObserver
{
public:
    StockObserver(string strName, Secretary* strSub)
    {
        name = strName;
        sub = strSub;
    }
    void Update()
    {
        cout << name << " begin to work" << endl;
    }
private:
    string name;
    Secretary* sub;
};

// 秘书类（主题对象，通知者）
class Secretary
{

public:
    void Add(StockObserver *ob) { observers.push_back(ob); }
    void Remove(int addIndex)
    {
        if(addIndex >=0 && addIndex < observers.size())
        {
            observers.erase(observers.begin() + addIndex);
        }
    }
    void Notify()
    {
        vector<StockObserver*>::iterator it;
        for (it=observers.begin(); it!=observers.end(); ++it)
        {
            (*it)->Update();
        }
    }

private:
    vector<StockObserver*> observers;
};
#endif
