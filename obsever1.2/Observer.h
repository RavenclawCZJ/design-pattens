#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Subject;

//observer�ĳ������
class Observer
{
public:
	Observer(){}
	~Observer(){}

	virtual void Update(Subject*) = 0;//֪ͨobserver״̬�����仯

};

class ConcreteObserver : public Observer//������observer
{
public:
	ConcreteObserver(){}
	~ConcreteObserver(){}

	virtual void Update(Subject*);//ʵ�ֻ����ṩ�Ľӿ�
private:
	string m_state;//״̬
};


class Subject
{
public:
	Subject(){}
	~Subject(){}

	virtual void Notify()//֪ͨ����ı�״̬
	{
		cout << "��ȥ֪ͨ�۲��߸��£�" <<endl<< endl;
		list<Observer*>::iterator iter = this->m_list.begin();
		for (; iter != m_list.end(); iter++)
		{
			(*iter)->Update(this);
		}
	}

	virtual void Attach(Observer*);//��������

	virtual void Detach(Observer*);//ɾ������

	virtual string GetState()//�õ�״̬
	{
		return this->m_state;
	}

	virtual void SetState(string state)//����״̬
	{
		this->m_state = state;
	}
	
private:
	string m_state;//ģ�Ᵽ��subject��״̬�ı���
	list<Observer*> m_list;//����observerָ�������
};

class ConcreteSubject : public Subject//������subject
{
public:
	ConcreteSubject(){}
	~ConcreteSubject(){}
private:
};



#endif