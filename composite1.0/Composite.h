#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include <vector>
#include<iostream>

using namespace std;

/*
Component������࣬Ϊ����еĶ��������ӿ�,�������๲�нӿڵ�ȱʡ��Ϊ(�������Add,Remove,GetChild����),
����һ���ӿں������Է���Component�������.
*/
class Component
{
public:
	//���麯����ֻ�ṩ�ӿڣ�û��Ĭ�ϵ�ʵ��
	virtual void Operation() = 0
	{
		cout << "Do something to component!" << endl;
	}

	// �麯��,�ṩ�ӿ�,��Ĭ�ϵ�ʵ�־���ʲô������
	virtual void Add(Component* com)
	{
		cout << "Add a component" << endl;
	}
	virtual void Remove(Component* com){}
	virtual Component* GetChild(int index)
	{
		return NULL;
	}
	virtual ~Component(){}
protected:
	Component(){}
};

//Leaf��Ҷ�ӽ��,Ҳ���ǲ�����������Ľ���࣬���Բ���ʵ��Add��Remove��GetChild�ȷ���
class Leaf :public Component
{
public:
	//ֻʵ��Operation�ӿ�
	virtual void Operation()
	{
		cout << "Do something to leaf!" << endl;
	}
	Leaf(){}
	~Leaf(){}
};

//Composite���������������
class Composite :public Component
{
public:
	Composite(){}
	~Composite(){}
	//ʵ�����нӿ�
	void Operation()
	{
		cout << "Do something to composite!" << endl;
		vector<Component*>::iterator iter = this->m_ComVec.begin();
		for (; iter != this->m_ComVec.end(); iter++)
		     {
		         (*iter)->Operation();
		     }
	}
	void Add(Component* com)
	{
		this->m_ComVec.push_back(com);
	}
	void Remove(Component* com)
	{
		this->m_ComVec.erase(&com);
	}
	Component* GetChild(int index)
	{
		if (index < 0 || index > this->m_ComVec.size())
		{
			return NULL;
		}
		return this->m_ComVec[index];
	}
private:
	//�������vector�����������
	vector<Component*> m_ComVec;
};
#endif