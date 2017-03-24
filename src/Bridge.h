#ifndef __Bridge_h__
#define __Bridge_h__
/**
 * 桥接模式 
 * 桥接模式把事物对象和其具体行为、具体特征分离开来，使它们可以各自独立的变化。
 * 事物对象仅是一个抽象的概念。
 * 如“圆形”、“三角形”归于抽象的“形状”之下，而“画圆”、“画三角”归于实现行为的“画图”类之下，然后由“形状”调用“画图”。
 */

class DrawingAPI
{
public:
    virtual void draw() = 0;
};

class DrawingCircle : public DrawingAPI
{
public:
    virtual void draw(){cout<<"DrawingCircle"<<endl;}
};

class DrawingTriangle : public DrawingAPI
{
public:
    virtual void draw(){cout<<"DrawingTriangle"<<endl;}
};

class Shape
{
public:
    virtual void drawShape() = 0;
};

class CircleShape : public Shape
{
private:
    DrawingAPI* m_pDraw;
public:
    CircleShape(DrawingAPI* pDraw) : m_pDraw(pDraw) {}
    virtual void drawShape()
    {
        m_pDraw->draw();
    }
};

class TriangleShape : public Shape
{
private:
    DrawingAPI* m_pDraw;
public:
    TriangleShape(DrawingAPI* pDraw) : m_pDraw(pDraw) {}
    virtual void drawShape()
    {
        m_pDraw->draw();
    }
};

#endif
