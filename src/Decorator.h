#ifndef __Decorator_h__
#define __Decorator_h__
/**
 * װ��ģʽ
 * ͨ��ʹ������ģʽ������������ʱ����һ����Ĺ��ܡ�
 * ԭ���ǣ�����һ�����������ԭ�����࣬�����ķ�ʽһ����ͨ���ڽ�ԭ���Ķ�����Ϊ������Ĺ��캯���Ĳ�����
 * װ����ʵ���µĹ��ܣ����ǣ��ڲ���Ҫ�õ��¹��ܵĵط���������ֱ�ӵ���ԭ�������еķ���������������ԭ����������ͬ�Ľӿڡ�
 * ����ģʽ����̳е�����һ��ѡ����̳��ڱ���ʱ��������Ϊ����װ��ģʽ��������ʱ������Ϊ��
 * ���м����໥�����Ĺ�����Ҫ����ʱ���������ͱ�ú���Ҫ��
 * ����Щ�������ı�������У��಻��������ʱ��������ͨ������Ƶ�ʱ��Ҳ����Ԥ�⵽���ļ��ֹ�����ϡ�
 * �����ζ��ҪΪÿһ����ϴ���һ�����ࡣ�෴������ģʽ����������ʱ��Ķ���ʵ����,�����Ϳ���������ʱ������Ҫ������ϡ�
 * һ������ģʽ��ʾ����JAVA���Java I/O Streams��ʵ�֡�
 */

/* Component (interface) */
class Widget
{
public:
    virtual void draw() = 0;
    virtual ~Widget() {}
};

/* ConcreteComponent */
class TextField : public Widget
{
private:
    int width, height;
public:
    TextField(int w, int h)
    {
        width  = w;
        height = h;
    }
    void draw()
    {
        cout<<"TextField: "<<width<< ", "<<height<<endl;
    }
};

/* Decorator (interface) */
class Decorator : public Widget
{
private:
    Widget* wid;       // reference to Widget
public:
    Decorator(Widget* w)
    {
        wid = w;
    }
    void draw()
    {
        wid->draw();
    }
    ~Decorator()
    {
        if (wid != NULL)
        {
            delete wid;
            wid = NULL;
        }
    }
};

/* ConcreteDecoratorA */
class BorderDecorator : public Decorator
{
public:
    BorderDecorator(Widget* w):Decorator(w){}
    void draw()
    {
        Decorator::draw();
        cout<<"   BorderDecorator"<<endl;
    }
};

/* ConcreteDecoratorB */
class ScrollDecorator : public Decorator
{
public:
    ScrollDecorator(Widget* w):Decorator(w){}
    void draw()
    {
        Decorator::draw();
        cout<<"   ScrollDecorator"<<endl;
    }
};

#endif
