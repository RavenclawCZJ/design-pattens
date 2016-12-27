#include "Composite.h"
#include <iostream>
#include<vector>

using namespace std;

void Composite::Add(Component* com)//����һ�������
{
	this->m_ComVec.push_back(com);
}

void Composite::Remove(Component* com)//ɾ��һ�������
{
	vector<Component*>::iterator it = this->m_ComVec.begin();
	for (; it != this->m_ComVec.end(); it++) {
		if (*it == com) {
			this->m_ComVec.erase(it);
			break;
		}
	}
}

void Composite::Operation()//��ÿ����϶�������������в���
{
	cout << "+" << m_strName << endl;
	cout << "Do something to composite!" << endl;
	vector<Component*>::iterator iter = this->m_ComVec.begin();
	for (; iter != this->m_ComVec.end(); iter++)
	{
		cout << "|-";
		(*iter)->Operation();
	}
}

