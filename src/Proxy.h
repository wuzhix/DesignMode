#ifndef __Proxy_h__
#define __Proxy_h__
/**
 * 代理模式
 * 所谓的代理者是指一个类别可以作为其它东西的接口。
 * 代理者可以作任何东西的接口：网络连接、存储器中的大对象、文件或其它昂贵或无法复制的资源。
 * 当一个复杂对象的多份副本须存在时，代理模式可以结合享元模式以减少存储器用量。
 * 典型作法是创建一个复杂对象及多个代理者，每个代理者会引用到原本的复杂对象。
 * 而作用在代理者的运算会转送到原本对象。一旦所有的代理者都不存在时，复杂对象会被移除。
 */

class CSubject
{
public:
    CSubject(){};
    virtual ~CSubject(){}

    virtual void Request() = 0;
};

class CRealSubject : public CSubject
{
public:
    CRealSubject(){}
    ~CRealSubject(){}

    void Request()
    {
        cout<<"CRealSubject Request"<<endl;
    }
};

class CProxy : public CSubject
{
public:
    CProxy() : m_pRealSubject(NULL){}
    ~CProxy()
    {
        if(m_pRealSubject != NULL)
        {
            delete m_pRealSubject;
            m_pRealSubject = NULL;
        }
    }

    void Request()
    {
        if (NULL == m_pRealSubject)
        {
            m_pRealSubject = new CRealSubject();
        }
        cout<<"CProxy Request"<<endl;
        m_pRealSubject->Request();
    }

private:
    CRealSubject *m_pRealSubject;
};
#endif
