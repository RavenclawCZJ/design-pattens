#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include <vector>
#include<iostream>
#include<string>

using namespace std;

/*
Component������࣬Ϊ����еĶ��������ӿ�
�������๲�нӿڵ�ȱʡ��Ϊ(�������Add,Remove,GetChild����),
*/
class Component
{
public:
	//���麯����ֻ�ṩ�ӿڣ�û��Ĭ�ϵ�ʵ��
	virtual void Operation() = 0;

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
	Component(string strName) : m_strName(strName){}
	string m_strName;
};

//Leaf��Ҷ�ӽ��,������������Ľ����
//���Բ���ʵ��Add��Remove��GetChild�ȷ���
class Leaf :public Component
{
public:
	//ֻʵ��Operation�ӿ�
	virtual void Operation()
	{
		cout << m_strName << endl;
		cout << "Do something to leaf!" << endl;
	}
	Leaf(){}
	Leaf(string strName) :Component(strName){}
	virtual ~Leaf(){}
};

//Composite���������������
//����ʵ�ֽӿ�
class Composite :public Component
{
public:
	Composite(){}
	Composite(string strName) : Component(strName){}
	~Composite(){}
	
	//ʵ�����нӿ�
	void Operation();
	void Add(Component* com);//���
	void Remove(Component* com);//ɾ��
	
	Component* GetChild(int index)//��ȡ�ӽڵ�
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