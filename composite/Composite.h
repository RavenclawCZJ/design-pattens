#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include <vector>
#include<iostream>
#include<string>

using namespace std;

/*
Component抽象基类，为组合中的对象声明接口
声明了类共有接口的缺省行为(如这里的Add,Remove,GetChild函数),
*/
class Component
{
public:
	//纯虚函数，只提供接口，没有默认的实现
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

//Leaf是叶子结点,不含有子组件的结点类
//所以不用实现Add、Remove、GetChild等方法
class Leaf :public Component
{
public:
	//只实现Operation接口
	virtual void Operation()
	{
		cout << m_strName << endl;
		cout << "Do something to leaf!" << endl;
	}
	Leaf(){}
	Leaf(string strName) :Component(strName){}
	virtual ~Leaf(){}
};

//Composite：含有子组件的类
//具体实现接口
class Composite :public Component
{
public:
	Composite(){}
	Composite(string strName) : Component(strName){}
	~Composite(){}
	
	//实现所有接口
	void Operation();
	void Add(Component* com);//添加
	void Remove(Component* com);//删除
	
	Component* GetChild(int index)//获取子节点
	{
		if (index < 0 || index > this->m_ComVec.size())
		{
			return NULL;
		}
		return this->m_ComVec[index];
	}
private:
	//这里采用vector来保存子组件
	vector<Component*> m_ComVec;
};
#endif