#ifndef _COMMAND_H 
#define _COMMAND_H

#include <iostream>  
#include <stack>  
#include <string>  

//命令基类
//具体命令类的抽象接口

class Command
{
public:
	Command(){}
	virtual ~Command(){}

	virtual void Execute() = 0;
};


#endif