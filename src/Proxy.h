#ifndef __Proxy_h__
#define __Proxy_h__
/**
 * ����ģʽ
 * ��ν�Ĵ�������ָһ����������Ϊ���������Ľӿڡ�
 * �����߿������κζ����Ľӿڣ��������ӡ��洢���еĴ�����ļ�������������޷����Ƶ���Դ��
 * ��һ�����Ӷ���Ķ�ݸ��������ʱ������ģʽ���Խ����Ԫģʽ�Լ��ٴ洢��������
 * ���������Ǵ���һ�����Ӷ��󼰶�������ߣ�ÿ�������߻����õ�ԭ���ĸ��Ӷ���
 * �������ڴ����ߵ������ת�͵�ԭ������һ�����еĴ����߶�������ʱ�����Ӷ���ᱻ�Ƴ���
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
