#include <iostream>
using namespace std;

void Print() {
	cout << "���� �Լ� Print()" << endl;
}

class Point {
public:
	void Print() {
		cout << "��� �Լ� Print()" << endl;
	}
};

int main() {
	Point pt;
	Point *p = &pt;

	Print();    //1)���� �Լ� ȣ��
	pt.Print(); //2)��ü�� ��� �Լ� ȣ��
	p->Print(); //3)�ּҷ� ��� �Լ� ȣ��

	return 0;

}