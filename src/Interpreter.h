#ifndef __Interpreter_h__
#define __Interpreter_h__
/**
 * ������ģʽ
 * ����ģʽʵ����һ�����ʽ�ӿڣ��ýӿڽ���һ���ض��������ġ�����ģʽ������ SQL ���������Ŵ�������ȡ�
 * ��ͼ������һ�����ԣ����������ķ���ʾ��������һ�������������������ʹ�øñ�ʶ�����������еľ��ӡ�
 * ��Ҫ���������һЩ�̶��ķ�����һ�����;��ӵĽ�������
 * ��ʱʹ�ã����һ���ض����͵����ⷢ����Ƶ���㹻�ߣ���ô���ܾ�ֵ�ý�������ĸ���ʵ������Ϊһ���������еľ��ӡ������Ϳ��Թ���һ�����������ý�����ͨ��������Щ��������������⡣
 * ��ν���������﷨���������ս������ս����
 * �ؼ����룺���������࣬����������֮���һЩȫ����Ϣ��һ���� HashMap��
 * Ӧ��ʵ������������������ʽ���㡣
 * �ŵ㣺 1������չ�ԱȽϺã��� 2���������µĽ��ͱ��ʽ�ķ�ʽ�� 3������ʵ�ּ��ķ���
 * ȱ�㣺 1�������ó����Ƚ��١� 2�����ڸ��ӵ��ķ��Ƚ���ά���� 3��������ģʽ�����������͡� 4��������ģʽ���õݹ���÷�����
 * ʹ�ó����� 1�����Խ�һ����Ҫ����ִ�е������еľ��ӱ�ʾΪһ�������﷨���� 2��һЩ�ظ����ֵ����������һ�ּ򵥵����������б� 3��һ�����﷨��Ҫ���͵ĳ�����
 */

class Context
{

};

class AbstractExpression
{
public:
    AbstractExpression(){}
    void virtual interpret(Context* pContext) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    TerminalExpression(){}
    void interpret(Context *context)
    {
        cout<<"Terminal Expression --> context"<<endl;
    }
};

class NonterminalExpression : public AbstractExpression
{
public:
    NonterminalExpression(){}
    void interpret(Context *context)
    {
        cout<<"Non-Terminal Expression --> context"<<endl;
    }
};
#endif
