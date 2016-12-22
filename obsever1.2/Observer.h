#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
#include <list>
#include <iostream>
using namespace std;

class Subject;

//observer的抽象基类
class Observer
{
public:
	~Observer(){}

	virtual void Update(Subject*) = 0;//通知observer状态发生变化
protected:
	Observer(){}
private:
};

class ConcreteObserverA : public Observer//派生自observer
{
public:
	ConcreteObserverA(){}

	~ConcreteObserverA(){}

	virtual void Update(Subject*);//实现基类提供的接口
protected:
private:
	string m_state;//状态
};

//class ConcreteObserverB : public Observer//同ConcreteObserverA
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

	virtual void Notify()//通知对象改变状态
	{
		cout << "快去通知观察者更新！" <<endl<< endl;
		list<Observer*>::iterator iter = this->m_lst.begin();
		for (; iter != m_lst.end(); iter++)
		{
			(*iter)->Update(this);
		}
	}

	virtual void Attach(Observer*);//新增对象

	virtual void Detach(Observer*);//删除对象

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
	list<Observer*> m_lst;//保存observer指针的链表
};

class ConcreteSubjectA : public Subject//派生自subject
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