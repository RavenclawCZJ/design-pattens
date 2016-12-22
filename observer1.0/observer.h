#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include<string>
#include<list>
#include<iostream>
using namespace std;

class Subject;

//obverser的抽象基类
class Obverser
{
public:
	~Obverser(){}
	virtual void Update(Subject* pSubject) = 0;//通知observer状态发生了变化
protected:
	int Observer(){}
};

class ConcreteObserverA : public Obverser//派生自observer
{
public:
	ConcreteObserverA(){}
	~ConcreteObserverA(){}
	virtual void Update(Subject* pSubject)//实现基类提供的借口
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
//subject抽象基类
class Subject
{
public:
	~Subject(){}

	virtual void Notify() //通知对象改变状态
	{
		cout << "Notify Observer's state" << endl;
		list<Observer*>::iterator it1, it2;
		for (it1 = m_list.begin(); it2 = m_list.end(); it1 != it2; it1++)
		{
			(*it1)->Update(this);
		}
	}

	virtual void Attach(Observer* pObserver)//新增对象
	{
		m_list.push_back(pObserver);
		cout << "Attach an Observer" << endl;
	}

	virtual void Detach(Observer* pObserver)//删除对象
	{
		list<Observer*>::iterator it;
		it = find(m_list.begin(), m_list.end(), pObserver);
		if (m_list.end()!=it)
		{
			m_list.erase(it);
		}
		cout << "Detach an Observer" << endl;
	}

	virtual string GetState()//得到状态
	{
		return this->m_state;
	}
	virtual void SetState(string state)//设置状态
	{
		this->m_state = state;
	}
protected:
	Subject(){}
private:
	string m_state;//模拟保存subject的状态的变量
	list<Obverser*> m_list;//保存observer指针的链表
};

class ConcreteSubjectA : public Subject//派生自subject
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