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
	~Observer(){}

	virtual void Update(Subject*) = 0;//֪ͨobserver״̬�����仯
protected:
	Observer(){}
private:
};

class ConcreteObserverA : public Observer//������observer
{
public:
	ConcreteObserverA(){}

	~ConcreteObserverA(){}

	virtual void Update(Subject*);//ʵ�ֻ����ṩ�Ľӿ�
protected:
private:
	string m_state;//״̬
};

//class ConcreteObserverB : public Observer//ͬConcreteObserverA
//{
//public:
	//ConcreteObserverB(){}
	//~ConcreteObserverB(){}
	//virtual void Update(Subject*);
//protected:
//private:
	//string m_state;
//};

class Subject
{
public:
	~Subject(){}

	virtual void Notify()//֪ͨ����ı�״̬
	{
		cout << "��ȥ֪ͨ�۲��߸��£�" <<endl<< endl;
		list<Observer*>::iterator iter = this->m_lst.begin();
		for (; iter != m_lst.end(); iter++)
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
protected:
	Subject(){}
private:
	string m_state;//ģ�Ᵽ��subject��״̬�ı���
	list<Observer*> m_lst;//����observerָ�������
};

class ConcreteSubjectA : public Subject//������subject
{
public:
	ConcreteSubjectA(){}
	~ConcreteSubjectA(){}
protected:
private:
};

//class ConcreteSubjectB : public Subject
//{
//public:
	//ConcreteSubjectB(){}
	//~ConcreteSubjectB(){}
//protected:
//private:
//};

#endif