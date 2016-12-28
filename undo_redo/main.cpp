#include<iostream>
#include "CommandManager.h"
#include"Command.h"
#include"CommandOperation.h"

using namespace std;
//ģ�������ַ���,Ȼ���������ַ�������undo redo����  
//�����¼����������¼,��:������undo �� redo �������ַ������ݸı�Ҳ���¼,�������������undo ���� redo �������ַ���ʱ ��redo��ռ���  
//����Ϊ����ʷ��¼���޸�ֵ����Ϊ�����µ�ֵ������Ҫ��redo  

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
	//Ĭ��û�������ַ��������ǿգ�����Ϊ����ʾ��ֵһ��������ַ���  
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
		//ץȡ�쳣
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





	////���� step1-5
	//p->ExecuteCommand(new CommandOperation("STEP ONE\n"));
	//p->ExecuteCommand(new CommandOperation("STEP TWO\n"));
	//p->ExecuteCommand(new CommandOperation("STEP THREE\n"));
	//p->ExecuteCommand(new CommandOperation("STEP FOUR\n"));
	//p->ExecuteCommand(new CommandOperation("STEP FIVE\n"));

	////undo ������S4
	//p->Undo();
	////undo ������S3
	//p->Undo();
	////undo ������S2
	//p->Undo();

	////undo ������S1
	//p->Undo();

	////undo ������PRE 
	//p->Undo();

	////ִ��ʧ�ܣ���Ϊ�Ѿ�undo ����ԭʼ����������� Redo() 
	//p->Undo();
	//cout << endl;

	////redo ������PRE 
	//p->Redo();
	////redo ������S1  
	//p->Redo();
	////redo ������S2
	//p->Redo();
	////redo ������S3
	//p->Redo();

	//cout << endl;
	//cout << "  ADD NEW RECORD\n" << endl;
	////redo���м��������ַ��� ��S6��"S7" ���ǵ�ǰ�ַ���  
	//p->ExecuteCommand(new CommandOperation("STEP SIX\n"));

	//p->ExecuteCommand(new CommandOperation("STEP SEVEN\n"));

	////undo ������S6
	//p->Undo();

	////undo ������S3
	//p->Undo();

	////redo ����S6
	//p->Redo();

	////redo ����S7
	//p->Redo();

	////redo ����S5
	//p->Redo();

	//// Redoִ��ʧ�ܣ��Ѿ����������  
	//p->Redo();

	//
	//system("pause");
	//return 0;

}

