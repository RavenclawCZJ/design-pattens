#include "Composite.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "----------------------------" << endl;
	cout << "----------1452711-----------" << endl;
	cout << "----------------------------" << endl;
	
	/*
	一致对待三种节点，直接调用Operation()
	体现了“使得用户对单个对象和组合对象的使用具有一致性。”
	*/

	//添加组合对象
	Composite* pRoot1 = new Composite();

	//组合对象添加叶子节点
	pRoot1->Add(new Leaf());
	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();
	

	//叶子节点只实现了Operation方法，其他Add、Remove、GetChild都继承自基类
	pLeaf1->Add(pLeaf2);
	pLeaf1->Remove(pLeaf2);
	pLeaf1->Operation();

	//组合对象实现了基类Component的所有接口，所以可以做各种操作(Add、Remove、GetChild、Operation)。
	Composite* pCom = new Composite();
	pCom->Add(pLeaf1);
	pCom->Add(pLeaf2);
	pCom->Operation();

	//组合对象添加组合对象
	pRoot1->Add(pCom);
	pRoot1->Operation();

	



	//一个组合实例
	cout << "---------------------------" << endl;
	cout << "----------Sample-----------" << endl;
	Composite* pRoot = new Composite("必修课");
	pRoot->Add(new Leaf("设计模式"));
	pRoot->Add(new Leaf("软件工程"));
	pRoot->Operation();
	pRoot = new Composite("选修课");
	pRoot->Add(new Leaf("艺术鉴赏"));
	pRoot->Add(new Leaf("界面设计"));
	pRoot->Operation();


	system("pause");
	return 0;
}