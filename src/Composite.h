#ifndef __Composite_h__
#define __Composite_h__
#include<vector>

using namespace std;
/**
 * ���ģʽ 
 * ��������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ�����ģʽʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�
 * ��������⣺
 * ����PC�õ����ļ�ϵͳ����ʵ�����������ݽṹ������νṹ��
 * ���Ǵ������е�ÿ���ڵ�ʱ����ʵ���ÿ�������Ҷ�ӽڵ㻹�Ǹ��ڵ㣬��Ϊ���ǵĳ�Ա��������һ���ģ�����������ģʽ�ľ��衣
 * ��ģ���˼�Ԫ�غ͸���Ԫ�صĸ���ͻ�������������Ԫ��һ����������Ԫ��,�Ӷ�ʹ�ÿͻ������븴��Ԫ�ص��ڲ��ṹ���
 * ע�������νṹ���Ҷ�ӽڵ�Ҳ�����Һ��ӣ�ֻ�������ĺ��Ӷ��ǿա�
 * ��ʱʹ�����ģʽ��
 * ���㷢�������������ֲ����������εĽṹʱ���Լ���ϣ���û����Ժ�����϶����뵥������Ĳ�ͬ��ͳһ��ʹ����Ͻṹ�е����ж���ʱ����Ӧ�ÿ��������ģʽ�ˡ�
 * ����������Ա���ϳɸ����ӵ���϶��󣬶������϶����ֿ��Ա���ϣ��������ϵصݹ���ȥ���ͻ������У��κ��õ���������ĵط�������ʹ����϶����ˡ�
 * �û����ù��ĵ����Ǵ���һ��Ҷ�ڵ㻹�Ǵ���һ����������Ҳ���ò���Ϊ������϶�дһЩѡ���ж�����ˡ�
 * ���ģʽ�ÿͻ�����һ�µ�ʹ����Ͻṹ�͵�������
 */
 
class Component
{
public:
    virtual void Operation() = 0;
    virtual void Add(Component*){}
    virtual void Remove(Component*){}
    virtual Component* GetChild(int index){return NULL;}
};

class Leaf : public Component
{
public:
    virtual void Operation(){cout<<"Leaf:"<<this<<endl;}
};

class Composite : public Component
{
private:
    vector<Component*> m_pComponents;
public:
    virtual void Operation()
    {
        cout<<"Operation Component"<<endl;
        vector<Component*>::iterator iter = m_pComponents.begin();
        for(; iter != m_pComponents.end(); ++iter)
        {
            (*iter)->Operation();
        }
    }
    virtual void Add(Component* pCom)
    {
        cout<<"Add Leaf:"<<pCom<<endl;
        m_pComponents.push_back(pCom);
    }
    virtual void Remove(Component* pCom)
    {
        vector<Component*>::iterator iter = m_pComponents.begin();
        for(; iter != m_pComponents.end(); ++iter)
        {
            if ((*iter) == pCom)
            {
                cout<<"Remove Leaf:"<<pCom<<endl;
                m_pComponents.erase(iter);
                break;
            }
        }
    }
    virtual Component* GetChild(int index)
    {
        if (index < 0 || index > m_pComponents.size())
        {
            return NULL;
        }
        else
        {
            return m_pComponents[index];
        }
    }
};
#endif
