#ifndef __AbstractFactory_h__
#define __AbstractFactory_h__
/**
 * 抽象工厂模式
 * 抽象工厂模式提供了一种方式，可以将一组具有同一主题的单独的工厂封装起来。
 * 在正常使用中，客户端程序需要创建抽象工厂的具体实现，然后使用抽象工厂作为接口来创建这一主题的具体对象。
 * 客户端程序不需要知道（或关心）它从这些内部的工厂方法中获得对象的具体类型，因为客户端程序仅使用这些对象的通用接口。
 * 抽象工厂模式将一组对象的实现细节与他们的一般使用分离开来。
 * 在以下情况可以考虑使用抽象工厂模式：
 *   一个系统要独立于它的产品的创建、组合和表示时。
 *   一个系统要由多个产品系列中的一个来配置时。
 *   需要强调一系列相关的产品对象的设计以便进行联合使用时。
 *   提供一个产品类库，而只想显示它们的接口而不是实现时。
 * 优点：
 *   具体产品从客户代码中被分离出来
 *   容易改变产品的系列
 *   将一个系列的产品族统一到一起创建
 * 缺点：
 *   在产品族中扩展新的产品是很困难的，它需要修改抽象工厂的接口
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
