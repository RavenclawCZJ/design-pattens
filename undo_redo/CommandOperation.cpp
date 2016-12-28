#include <iostream>  
#include <stack>  
#include <string>  
#include"Command.h"
#include"CommandOperation.h"

using namespace std;

CommandOperation::CommandOperation(string operation)
{
	mOperation = operation;
}

CommandOperation::~CommandOperation()
{}

void CommandOperation::Execute()
{
	cout << " Current Operation:" << mOperation.c_str() << endl;
}

