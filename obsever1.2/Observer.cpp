#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;



void ConcreteObserverA::Update(Subject* pSubject)//ʵ�ֻ����ṩ�Ľ��
{
	this->m_state = pSubject->GetState();
	cout << "����۲��ߵ�״̬ " << m_state << endl<< endl;
}


//void ConcreteObserverB::Update(Subject* pSubject)
//{
	//this->m_state = pSubject->GetState();
	//cout << "The ConcreteObserverB is " << m_state << endl << endl;
//}



void Subject::Attach(Observer* pObserver)
{
	this->m_lst.push_back(pObserver);
	cout << "���һ���۲��ߣ���" << endl<< endl;
}

void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(m_lst.begin(), m_lst.end(), pObserver);
	if (iter != m_lst.end())
	{
		m_lst.erase(iter);
	}
	cout << "ɾ��һ���۲��ߣ���" << endl << endl;
}



