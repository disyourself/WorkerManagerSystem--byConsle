#pragma once

#include<iostream>
#include<string>


using namespace std;

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDepatName() = 0;


	int _ID;	//ְ�����
	string _Name;	//ְ������
	int _DeparmentId;  //���ű��
};

