#ifndef __Composite_h__
#define __Composite_h__
#include<vector>

using namespace std;
/**
 * 组合模式 
 * 将对象组合成树形结构以表示“部分-整体”的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
 * 解决的问题：
 * 我们PC用到的文件系统，其实就是我们数据结构里的树形结构。
 * 我们处理树中的每个节点时，其实不用考虑他是叶子节点还是根节点，因为他们的成员函数都是一样的，这个就是组合模式的精髓。
 * 他模糊了简单元素和复杂元素的概念，客户程序可以向处理简单元素一样来处理复杂元素,从而使得客户程序与复杂元素的内部结构解耦。
 * 注明：树形结构里的叶子节点也有左右孩子，只不过他的孩子都是空。
 * 何时使用组合模式：
 * 当你发现需求中是体现部分与整体层次的结构时，以及你希望用户可以忽略组合对象与单个对象的不同，统一地使用组合结构中的所有对象时，就应该考虑用组合模式了。
 * 基本对象可以被组合成更复杂的组合对象，而这个组合对象又可以被组合，这样不断地递归下去，客户代码中，任何用到基本对象的地方都可以使用组合对象了。
 * 用户不用关心到底是处理一个叶节点还是处理一个组合组件，也就用不着为定义组合二写一些选择判断语句了。
 * 组合模式让客户可以一致地使用组合结构和单个对象。
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
