#ifndef __AbstractFactory_h__
#define __AbstractFactory_h__
/**
 * ���󹤳�ģʽ
 * ���󹤳�ģʽ�ṩ��һ�ַ�ʽ�����Խ�һ�����ͬһ����ĵ����Ĺ�����װ������
 * ������ʹ���У��ͻ��˳�����Ҫ�������󹤳��ľ���ʵ�֣�Ȼ��ʹ�ó��󹤳���Ϊ�ӿ���������һ����ľ������
 * �ͻ��˳�����Ҫ֪��������ģ�������Щ�ڲ��Ĺ��������л�ö���ľ������ͣ���Ϊ�ͻ��˳����ʹ����Щ�����ͨ�ýӿڡ�
 * ���󹤳�ģʽ��һ������ʵ��ϸ�������ǵ�һ��ʹ�÷��뿪����
 * ������������Կ���ʹ�ó��󹤳�ģʽ��
 *   һ��ϵͳҪ���������Ĳ�Ʒ�Ĵ�������Ϻͱ�ʾʱ��
 *   һ��ϵͳҪ�ɶ����Ʒϵ���е�һ��������ʱ��
 *   ��Ҫǿ��һϵ����صĲ�Ʒ���������Ա��������ʹ��ʱ��
 *   �ṩһ����Ʒ��⣬��ֻ����ʾ���ǵĽӿڶ�����ʵ��ʱ��
 * �ŵ㣺
 *   �����Ʒ�ӿͻ������б��������
 *   ���׸ı��Ʒ��ϵ��
 *   ��һ��ϵ�еĲ�Ʒ��ͳһ��һ�𴴽�
 * ȱ�㣺
 *   �ڲ�Ʒ������չ�µĲ�Ʒ�Ǻ����ѵģ�����Ҫ�޸ĳ��󹤳��Ľӿ�
 */
 
class Button {}; // Abstract Class
class MacButton: public Button {};
class WinButton: public Button {};

class Border {}; // Abstract Class
class MacBorder: public Border {};
class WinBorder: public Border {};

class AbstractFactory 
{
public:
    virtual Button* CreateButton() = 0;
    virtual Border* CreateBorder() = 0;
};

class MacFactory: public AbstractFactory 
{
public:
    MacButton* CreateButton() { return new MacButton; }
    MacBorder* CreateBorder() { return new MacBorder; }
};

class WinFactory: public AbstractFactory 
{
public:
    WinButton* CreateButton() { return new WinButton; }
    WinBorder* CreateBorder() { return new WinBorder; }
};

#endif
