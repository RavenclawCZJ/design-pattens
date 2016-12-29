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
	Observer(){}
	~Observer(){}

	virtual void Update(Subject*) = 0;//通知observer状态发生变化

};

class ConcreteObserver : public Observer//派生自observer
{
public:
	ConcreteObserver(){}
	~ConcreteObserver(){}

	virtual void Update(Subject*);//实现基类提供的接口
private:
	string m_state;//状态
};


class Subject
{
public:
	Subject(){}
	~Subject(){}

	virtual void Notify()//通知对象改变状态
	{
		cout << "快去通知观察者更新！" <<endl<< endl;
		list<Observer*>::iterator iter = this->m_list.begin();
		for (; iter != m_list.end(); iter++)
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
	
private:
	string m_state;//模拟保存subject的状态的变量
	list<Observer*> m_list;//保存observer指针的链表
};

class ConcreteSubject : public Subject//派生自subject
{
public:
	ConcreteSubject(){}
	~ConcreteSubject(){}
private:
};



#endif