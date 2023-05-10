#include <iostream>
using namespace std;

class Person
{
public:

	int age;

	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}

	void ShowPerson() {     //但是如果成员函数中用到了this指针，就不可以了
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;
	}

public:
	int mAge;
};

void testnullpointer()
{
	Person* p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //错误，但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	testnullpointer();
	system("pause");

	return 0;
}