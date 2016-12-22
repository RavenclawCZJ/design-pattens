#include "Observer.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "----------1452711陈子鉴-------------------" << endl<< endl;
	Observer* p1 = new ConcreteObserverA();
	//Observer* p2 = new ConcreteObserverB();
	Observer* p3 = new ConcreteObserverA();

	Subject* pSubject = new ConcreteSubjectA();
	pSubject->Attach(p1);
	//pSubject->Attach(p2);
	pSubject->Attach(p3);

	cout << "通知之前！" << endl << endl;

	pSubject->SetState("没更新！");

	pSubject->Notify();

	cout << "-------------------------------------" << endl;

	cout << "通知之后！" << endl << endl;

	pSubject->SetState("更新啦！");

	pSubject->Detach(p3);

	pSubject->Notify();

	system("pause");
	return 0;
}