#include "Observer.h"
#include <iostream>
#include <algorithm>

using namespace std;



void ConcreteObserver::Update(Subject* pSubject)//ʵ�ֻ����ṩ�Ľ��
{
	this->m_state = pSubject->GetState();
	cout << "����۲��ߵ�״̬�� " << m_state << endl<< endl;
}



void Subject::Attach(Observer* pObserver)
{
	this->m_list.push_back(pObserver);
	cout << "���һ���۲���" << endl<< endl;
}

void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(m_list.begin(), m_list.end(), pObserver);
	if (iter != m_list.end())
	{
		m_list.erase(iter);
	}
	cout << "ɾ��һ���۲���" << endl << endl;
}



