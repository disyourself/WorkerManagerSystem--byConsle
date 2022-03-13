#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include<vector>

#include"Worker.h"

#define FILENAME "DataBase/empList.txt"


using namespace std;


class wokerManager
{
public:

	wokerManager();

	bool _FileIsEmpty;	//�ж��ļ��Ƿ�Ϊ��
	int _EmpNum;		//��¼ְ������
	Worker** _EmpArray;	//ְ������ָ��
	
	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//���ְ��
	void addEmp();

	//�����ļ�
	void save();

	//ͳ���ļ�������
	int getEmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void show_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);
	int IsExist(string name);

	//ɾ��ְ��
	void dele_Emp();

	//�޸�ְ����Ϣ
	void modify_Emp();

	//����Ա��
	void find_Emp();

	//��ְ���������
	void sort_Emp();

	//��������ĵ�
	void dele_AllData();


	~wokerManager();
};

