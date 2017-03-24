#ifndef __Bridge_h__
#define __Bridge_h__
/**
 * �Ž�ģʽ 
 * �Ž�ģʽ�����������������Ϊ�������������뿪����ʹ���ǿ��Ը��Զ����ı仯��
 * ����������һ������ĸ��
 * �硰Բ�Ρ����������Ρ����ڳ���ġ���״��֮�£�������Բ�����������ǡ�����ʵ����Ϊ�ġ���ͼ����֮�£�Ȼ���ɡ���״�����á���ͼ����
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
