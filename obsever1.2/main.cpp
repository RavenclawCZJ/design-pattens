#include "Observer.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "----------1452711���Ӽ�-------------------" << endl<< endl;
	Observer* p1 = new ConcreteObserverA();
	//Observer* p2 = new ConcreteObserverB();
	Observer* p3 = new ConcreteObserverA();

	Subject* pSubject = new ConcreteSubjectA();
	pSubject->Attach(p1);
	//pSubject->Attach(p2);
	pSubject->Attach(p3);

	cout << "֪֮ͨǰ��" << endl << endl;

	pSubject->SetState("û���£�");

	pSubject->Notify();

	cout << "-------------------------------------" << endl;

	cout << "֪֮ͨ��" << endl << endl;

	pSubject->SetState("��������");

	pSubject->Detach(p3);

	pSubject->Notify();

	system("pause");
	return 0;
}