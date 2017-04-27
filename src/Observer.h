#ifndef __Observer_h__
#define __Observer_h__
/**
 * �۲���ģʽ
 * �ڴ���ģʽ�У�һ��Ŀ���������������������Ĺ۲��߶��󣬲������������״̬�ı�ʱ��������֪ͨ��
 * ��;
 *   ������������������������Ĳ���ʱ����װ��Щ�����ڵ����Ķ����ڽ����������Ա������ȥ������ظ�ʹ����Щ���󣬶������������֮�佻�������⡣
 *   ������һ������ı����Ӱ����������ȴ�ֲ�֪�����ٶ�����뱻ͬʱ���ʱ��
 *   ������Ӧ��������֪ͨ���������ֲ�Ӧ��֪�����������ʵ��ϸ��ʱ��
 */

class Secretary;
// ����Ʊ��ͬ���ࣨ�۲���󣬹۲��ߣ�
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

// �����ࣨ�������֪ͨ�ߣ�
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
