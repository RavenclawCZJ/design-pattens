#include "Composite.h"
#include <iostream>
#include<vector>

using namespace std;

void Composite::Add(Component* com)//增加一个子组件
{
	this->m_ComVec.push_back(com);
}

void Composite::Remove(Component* com)//删除一个子组件
{
	vector<Component*>::iterator it = this->m_ComVec.begin();
	for (; it != this->m_ComVec.end(); it++) {
		if (*it == com) {
			this->m_ComVec.erase(it);
			break;
		}
	}
}

void Composite::Operation()//对每个组合对象及其子组件进行操作
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

