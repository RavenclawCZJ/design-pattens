#ifndef _COMMANDMANAGER_H 
#define _COMMANDMANAGER_H

#include <iostream>  
#include <stack>  
#include <string>  
#include "Command.h"

//命令处理类
class CommandManager : public Command//继承自Command，进行各个函数的具体实现
{
public:
	CommandManager(Command*);
	~CommandManager();

	void ExecuteCommand(Command*);
	void Execute(){}
	void Undo();
	void Redo();

private:
	std::stack< Command* > mUndo;//用一个栈来存储需要undo动作
	std::stack< Command* > mRedo;//用一个栈来存储需要redo动作
};

#endif