#ifndef __FactoryMethod_h__
#define __FactoryMethod_h__
/**
 * 工厂方法模式模式
 * 工厂方法模式的实质是“定义一个创建对象的接口，但让实现这个接口的类来决定实例化哪个类。
 * 工厂方法让类的实例化推迟到子类中进行。
 * 在以下情况可以考虑使用工厂方法模式：
 *   创建对象需要大量重复的代码。
 *   一个系统要由多个产品系列中的一个来配置时。
 *   创建对象需要访问某些信息，而这些信息不应该包含在复合类中。
 *   创建对象的生命周期必须集中管理，以保证在整个程序中具有一致的行为。
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
