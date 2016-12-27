#include "Composite.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "----------------------------" << endl;
	cout << "----------1452711-----------" << endl;
	cout << "----------------------------" << endl;
	
	/*
	һ�¶Դ����ֽڵ㣬ֱ�ӵ���Operation()
	�����ˡ�ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ���
	*/

	//�����϶���
	Composite* pRoot1 = new Composite();

	//��϶������Ҷ�ӽڵ�
	pRoot1->Add(new Leaf());
	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();
	

	//Ҷ�ӽڵ�ֻʵ����Operation����������Add��Remove��GetChild���̳��Ի���
	pLeaf1->Add(pLeaf2);
	pLeaf1->Remove(pLeaf2);
	pLeaf1->Operation();

	//��϶���ʵ���˻���Component�����нӿڣ����Կ��������ֲ���(Add��Remove��GetChild��Operation)��
	Composite* pCom = new Composite();
	pCom->Add(pLeaf1);
	pCom->Add(pLeaf2);
	pCom->Operation();

	//��϶��������϶���
	pRoot1->Add(pCom);
	pRoot1->Operation();

	



	//һ�����ʵ��
	cout << "---------------------------" << endl;
	cout << "----------Sample-----------" << endl;
	Composite* pRoot = new Composite("���޿�");
	pRoot->Add(new Leaf("���ģʽ"));
	pRoot->Add(new Leaf("�������"));
	pRoot->Operation();
	pRoot = new Composite("ѡ�޿�");
	pRoot->Add(new Leaf("��������"));
	pRoot->Add(new Leaf("�������"));
	pRoot->Operation();


	system("pause");
	return 0;
}