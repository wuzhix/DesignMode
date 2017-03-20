#ifndef __FactoryMethod_h__
#define __FactoryMethod_h__
/**
 * ��������ģʽģʽ
 * ��������ģʽ��ʵ���ǡ�����һ����������Ľӿڣ�����ʵ������ӿڵ���������ʵ�����ĸ��ࡣ
 * �������������ʵ�����Ƴٵ������н��С�
 * ������������Կ���ʹ�ù�������ģʽ��
 *   ����������Ҫ�����ظ��Ĵ��롣
 *   һ��ϵͳҪ�ɶ����Ʒϵ���е�һ��������ʱ��
 *   ����������Ҫ����ĳЩ��Ϣ������Щ��Ϣ��Ӧ�ð����ڸ������С�
 *   ����������������ڱ��뼯�й����Ա�֤�����������о���һ�µ���Ϊ��
 */
 
class Radio {}; 
class MacRadio: public Radio {};
class WinRadio: public Radio {};

class RadioFactory 
{
public:
    virtual Radio* CreateRadio() = 0;
};

class MacRadioFactory: public RadioFactory 
{
public:
    Radio* CreateRadio() { return new MacRadio; }
};

class WinRadioFactory: public RadioFactory 
{
public:
    Radio* CreateRadio() { return new WinRadio; }
};

#endif
