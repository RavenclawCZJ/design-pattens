#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include<string>
#include<list>
#include<iostream>
using namespace std;

class Subject;

//obverser�ĳ������
class Obverser
{
public:
	~Obverser(){}
	virtual void Update(Subject* pSubject) = 0;//֪ͨobserver״̬�����˱仯
protected:
	int Observer(){}
};

class ConcreteObserverA : public Obverser//������observer
{
public:
	ConcreteObserverA(){}
	~ConcreteObserverA(){}
	virtual void Update(Subject* pSubject)//ʵ�ֻ����ṩ�Ľ��
	{
		this->m_state = pSubject->GetState();
		cout << "The ConcreteObserverA is" << m_state << endl;
	}
private:
	string m_state;
};

class ConcreteObserverB : public Obverser
{
public:
	ConcreteObserverB(){}
	~ConcreteObserverB(){}
	virtual void Update(Subject* pSubject)
	{
		this->m_state = pSubject->GetState();
		cout << "The ConcreteObserverB is" << m_state << endl;
	}
private:
	string m_state;
};

class Observer;
//subject�������
class Subject
{
public:
	~Subject(){}

	virtual void Notify() //֪ͨ����ı�״̬
	{
		cout << "Notify Observer's state" << endl;
		list<Observer*>::iterator it1, it2;
		for (it1 = m_list.begin(); it2 = m_list.end(); it1 != it2; it1++)
		{
			(*it1)->Update(this);
		}
	}

	virtual void Attach(Observer* pObserver)//��������
	{
		m_list.push_back(pObserver);
		cout << "Attach an Observer" << endl;
	}

	virtual void Detach(Observer* pObserver)//ɾ������
	{
		list<Observer*>::iterator it;
		it = find(m_list.begin(), m_list.end(), pObserver);
		if (m_list.end()!=it)
		{
			m_list.erase(it);
		}
		cout << "Detach an Observer" << endl;
	}

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
	list<Obverser*> m_list;//����observerָ�������
};

class ConcreteSubjectA : public Subject//������subject
{
public:
	ConcreteSubjectA(){}
	~ConcreteSubjectA(){}
private:
};

class ConcreteSubjectB : public Subject
{
public:
	ConcreteSubjectB(){}
	~ConcreteSubjectB(){}
private:
};

#endif