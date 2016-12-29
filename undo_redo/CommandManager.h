#ifndef _COMMANDMANAGER_H 
#define _COMMANDMANAGER_H

#include <iostream>  
#include <stack>  
#include <string>  
#include "Command.h"

//�������
class CommandManager : public Command//�̳���Command�����и��������ľ���ʵ��
{
public:
	CommandManager(Command*);
	~CommandManager();

	void ExecuteCommand(Command*);
	void Execute(){}
	void Undo();
	void Redo();

private:
	std::stack< Command* > mUndo;//��һ��ջ���洢��Ҫundo����
	std::stack< Command* > mRedo;//��һ��ջ���洢��Ҫredo����
};

#endif