
#include"workerManager.h"
#include"Worker.h"
#include"employee.h"



int main() {
	//测试代码
	/*Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();

	system("pause");*/



	//实例化manager对象
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



