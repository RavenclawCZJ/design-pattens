
#include <iostream>  
#include <stack>  
#include <string>  
#include"Command.h"
#include"CommandManager.h"

using namespace std;

//命令处理类
CommandManager::CommandManager(Command *pCmd)
{
	//最初的命令数据存入undolist
	mUndo.push(pCmd);
	pCmd->Execute();
}
CommandManager::~CommandManager()
{
	while (false == mUndo.empty())
	{
		delete mUndo.top();
		mUndo.pop();
	}
	while (false == mRedo.empty())
	{
		delete mRedo.top();
		mRedo.pop();
	}
}

void CommandManager::ExecuteCommand(Command *pCmd)//执行方法，实现相应操作
{
	pCmd->Execute();
	mUndo.push(pCmd);
}

void CommandManager::Undo()//undo具体实现
{
	if (mUndo.size() < 2)
	{
		//没有数据，无法undo  
		cout << "  no records!" << endl;
		cout << "  undo failed." << endl;;
		return;
	}

	cout << "  undo:" << endl;

	//当前命令  
	auto pCmd = mUndo.top();

	//保存当前命令  
	mRedo.push(pCmd);

	//弹出  
	mUndo.pop();

	//还原到上个命令  
	pCmd = mUndo.top();

	pCmd->Execute();
}

void CommandManager::Redo()//redo具体实现
{
	if (mRedo.empty())
	{
		//没有数据，无法redo  
		cout << "  no records!" << endl;
		cout << "  redo failed." << endl;;
		return;
	}

	cout << "  redo:" << endl;

	auto pCmd = mRedo.top();

	pCmd->Execute();

	mRedo.pop();

	mUndo.push(pCmd);
}



