#include "workerManager.h"

wokerManager::wokerManager(){
}

void wokerManager::showMenu()
{
	cout << "************************************" << endl;
	cout << "******  ��ӭʹ��ְ������ϵͳ!  *****" << endl;
	cout << "*********  0.�˳��������  *********" << endl;
	cout << "*********  1.����ְ����Ϣ  *********" << endl;
	cout << "*********  2.��ʾְ����Ϣ  *********" << endl;
	cout << "*********  3.ɾ����ְְ��  *********" << endl;
	cout << "*********  4.�޸�ְ����Ϣ  *********" << endl;
	cout << "*********  5.����ְ����Ϣ  *********" << endl;
	cout << "*********  6.���ձ������  *********" << endl;
	cout << "*********  7.��������ĵ�  *********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void wokerManager::exitSystem()
{
	cout << "�˳�ϵͳ�ɹ���" << endl;
	cout << "��ӭ�´�ʹ��." << endl;
	system("pause");
	system("cls");
	exit(0);
}

wokerManager::~wokerManager()
{
}
