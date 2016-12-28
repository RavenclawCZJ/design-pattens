
#include <iostream>  
#include <stack>  
#include <string>  
#include"Command.h"
#include"CommandManager.h"

using namespace std;

//�������
CommandManager::CommandManager(Command *pCmd)
{
	//������������ݴ���undolist
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

void CommandManager::ExecuteCommand(Command *pCmd)//ִ�з�����ʵ����Ӧ����
{
	pCmd->Execute();
	mUndo.push(pCmd);
}

void CommandManager::Undo()//undo����ʵ��
{
	if (mUndo.size() < 2)
	{
		//û�����ݣ��޷�undo  
		cout << "  no records!" << endl;
		cout << "  undo failed." << endl;;
		return;
	}

	cout << "  undo:" << endl;

	//��ǰ����  
	auto pCmd = mUndo.top();

	//���浱ǰ����  
	mRedo.push(pCmd);

	//����  
	mUndo.pop();

	//��ԭ���ϸ�����  
	pCmd = mUndo.top();

	pCmd->Execute();
}

void CommandManager::Redo()//redo����ʵ��
{
	if (mRedo.empty())
	{
		//û�����ݣ��޷�redo  
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



