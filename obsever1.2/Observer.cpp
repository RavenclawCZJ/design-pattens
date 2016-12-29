#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;



void ConcreteObserver::Update(Subject* pSubject)//实现基类提供的借口
{
	this->m_state = pSubject->GetState();
	cout << "这个观察者的状态是 " << m_state << endl<< endl;
}



void Subject::Attach(Observer* pObserver)
{
	this->m_list.push_back(pObserver);
	cout << "添加一个观察者" << endl<< endl;
}

void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(m_list.begin(), m_list.end(), pObserver);
	if (iter != m_list.end())
	{
		m_list.erase(iter);
	}
	cout << "删除一个观察者" << endl << endl;
}



