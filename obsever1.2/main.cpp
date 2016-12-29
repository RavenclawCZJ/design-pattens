#include "Observer.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "----------1452711陈子鉴-------------------" << endl<< endl;
	
	Observer* p1 = new ConcreteObserver();
	Observer* p2 = new ConcreteObserver();

	Subject* pSubject = new ConcreteSubject();
	
	pSubject->Attach(p1);//添加观察者1
	pSubject->Attach(p2);//添加观察者2

	cout << "-------------------------------------" << endl;
	cout << "测试通知之前的状态：" << endl << endl;

	pSubject->SetState("没更新！");

	pSubject->Notify();

	cout << "-------------------------------------" << endl;

	cout << "测试通知之后的状态：" << endl << endl;

	pSubject->SetState("更新啦！");

	pSubject->Detach(p2);//删除观察者2

	pSubject->Notify();//通知自动更新

	system("pause");
	return 0;
}