#include<iostream>
#include "CommandManager.h"
#include"Command.h"
#include"CommandOperation.h"

using namespace std;
//模拟输入字符串,然后对输入的字符串进行undo redo操作  
//这里记录的是完整记录,即:即便在undo 或 redo 过程中又发生数据改变也会记录,如果不想这样在undo 或者 redo 输入新字符串时 将redo清空即可  
//即认为在历史记录中修改值被认为是最新的值，不需要再redo  

void printOrder(){
	cout << "============================" << endl
		<< "== Please input No.1-4   ===\n"
		<< "== 1. Input your command ===\n"
		<< "== 2. Undo Command       ===\n"
		<< "== 3. Redo Command       ===\n"
		<< "== 4. Shut Down          ===\n"
		<< "============================" << endl;
}


int main()
{

	cout << "=====1452711 chenzijian=====" << endl;
	cout << "=======Undo/Redo Test=======" << endl;

	printOrder();
	//默认没有输入字符串可以是空，这里为了演示赋值一个特殊的字符串  
	CommandManager *p = new CommandManager(new CommandOperation(" PREPARATION\n"));

	int commandOrder = 0;
	while (1){
		cout << "Please Input your Order: 	";
		try{
			cin.clear();
			cin.sync();
			cin >> commandOrder;
			if (commandOrder != 1 && commandOrder != 2 && commandOrder != 3 && commandOrder != 4)
				throw exception();
		}
		//抓取异常
		catch (...){
			//cout << "Error input, try to input again\n";
			commandOrder = 5;
		}
		switch (commandOrder)
		{
		case 1:
		{getchar();
		cout << "Please input your command: 	";
		string commandName;
		while (getline(cin, commandName) && commandName == ""){
			cout << "Error input, try to input again\n";
		}
		p->ExecuteCommand(new CommandOperation(commandName));
		cout << endl;
		}
		break;
		case 2:
		{
			p->Undo();
			break;
		}
		case 3:{
			p->Redo();
			cout << endl;
			break;
		}
		case 4:{

			cout << endl;
			delete p;
			system("pause");
			return 0;
		}
		default:{
			cout << "Your Order is illegel,Please re-enter.\n"<< endl;
			break;
		}

		}
	}





	////输入 step1-5
	//p->ExecuteCommand(new CommandOperation("STEP ONE\n"));
	//p->ExecuteCommand(new CommandOperation("STEP TWO\n"));
	//p->ExecuteCommand(new CommandOperation("STEP THREE\n"));
	//p->ExecuteCommand(new CommandOperation("STEP FOUR\n"));
	//p->ExecuteCommand(new CommandOperation("STEP FIVE\n"));

	////undo 撤销到S4
	//p->Undo();
	////undo 撤销到S3
	//p->Undo();
	////undo 撤销到S2
	//p->Undo();

	////undo 撤销到S1
	//p->Undo();

	////undo 撤销到PRE 
	//p->Undo();

	////执行失败，因为已经undo 到最原始情况，不能再 Redo() 
	//p->Undo();
	//cout << endl;

	////redo 重做到PRE 
	//p->Redo();
	////redo 重做到S1  
	//p->Redo();
	////redo 重做到S2
	//p->Redo();
	////redo 重做到S3
	//p->Redo();

	//cout << endl;
	//cout << "  ADD NEW RECORD\n" << endl;
	////redo后中间输入新字符串 “S6”"S7" 覆盖当前字符串  
	//p->ExecuteCommand(new CommandOperation("STEP SIX\n"));

	//p->ExecuteCommand(new CommandOperation("STEP SEVEN\n"));

	////undo 撤销到S6
	//p->Undo();

	////undo 撤销到S3
	//p->Undo();

	////redo 重做S6
	//p->Redo();

	////redo 重做S7
	//p->Redo();

	////redo 重做S5
	//p->Redo();

	//// Redo执行失败，已经到最新情况  
	//p->Redo();

	//
	//system("pause");
	//return 0;

}

