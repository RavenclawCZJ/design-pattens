#ifndef _COMMAND_H 
#define _COMMAND_H

#include <iostream>  
#include <stack>  
#include <string>  

//�������
//����������ĳ���ӿ�

class Command
{
public:
	Command(){}
	virtual ~Command(){}

	virtual void Execute() = 0;
};


#endif