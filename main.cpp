
#include"workerManager.h"
#include"Worker.h"
#include"employee.h"



int main() {
	//���Դ���
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();

	system("pause");*/



	//ʵ����manager����
	wokerManager wm;

	int choice;

	while (1) {

		wm.showMenu();

		cin>>choice;

		switch(choice){
		case 0:
			wm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}



