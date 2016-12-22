#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;



void ConcreteObserverA::Update(Subject* pSubject)//实现基类提供的借口
{
	this->m_state = pSubject->GetState();
	cout << "这个观察者的状态 " << m_state << endl<< endl;
}


//void ConcreteObserverB::Update(Subject* pSubject)
//{
	//this->m_state = pSubject->GetState();
	//cout << "The ConcreteObserverB is " << m_state << endl << endl;
//}



void Subject::Attach(Observer* pObserver)
{
	this->m_lst.push_back(pObserver);
	cout << "添加一个观察者！！" << endl<< endl;
}

void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(m_lst.begin(), m_lst.end(), pObserver);
	if (iter != m_lst.end())
	{
		m_lst.erase(iter);
	}
	cout << "删除一个观察者！！" << endl << endl;
}



