#ifndef _COMMANDOPERATION_H 
#define _COMMANDOPERATION_H

#include <iostream>  
#include <stack>  
#include <string>  
#include "Command.h"

using namespace std;


class CommandOperation : public Command	//�̳���Command 
{
public:

	CommandOperation(string a);
	~CommandOperation();

	void Execute();


private:

	string mOperation;
};

#endif