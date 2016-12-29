#include "Observer.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "----------1452711���Ӽ�-------------------" << endl<< endl;
	
	Observer* p1 = new ConcreteObserver();
	Observer* p2 = new ConcreteObserver();

	Subject* pSubject = new ConcreteSubject();
	
	pSubject->Attach(p1);//��ӹ۲���1
	pSubject->Attach(p2);//��ӹ۲���2

	cout << "-------------------------------------" << endl;
	cout << "����֪֮ͨǰ��״̬��" << endl << endl;

	pSubject->SetState("û���£�");

	pSubject->Notify();

	cout << "-------------------------------------" << endl;

	cout << "����֪֮ͨ���״̬��" << endl << endl;

	pSubject->SetState("��������");

	pSubject->Detach(p2);//ɾ���۲���2

	pSubject->Notify();//֪ͨ�Զ�����

	system("pause");
	return 0;
}