#ifndef __Facade_h__
#define __Facade_h__
/**
 * ���ģʽ
 * Ϊ��ϵͳ�е�һ��ӿ��ṩһ��ͳһ�ĸ߲�ӿڣ�ʹ����ϵͳ������ʹ��
 */

class CPU
{
public:
	void freeze(){}
	void jump(long position){}
	void execute(){}
};

class Memory
{
public:
	void load(long position, char* data) {}
};

class HardDrive
{
public:
	char* read(long lba, int size) {}
};

/* Facade */
class Computer
{
private:
    CPU* cpu;
    Memory* memory;
    HardDrive* hardDrive;
public:
    Computer(CPU* cpu, Memory* memory, HardDrive* hardDrive)
    {
        this->cpu = cpu;
        this->memory = memory;
        this->hardDrive = hardDrive;
    }
	void startComputer()
	{
		cpu->freeze();
		memory->load(10, hardDrive->read(11, 4));
		cpu->jump(10);
		cpu->execute();
	}
};
#endif
