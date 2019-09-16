#include <iostream>
using namespace std;

class Point {
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {

	}
	void Print() const {
		cout << x << ", " << y << endl;
	}
	const Point& operator++() { //���� ++ ������
		++x;
		++y;
		return *this;
	}
	const Point operator++(int) { //���� ++ ������
		Point pt(x, y);
		++x; //���α����̹Ƿ� ��� ������ ���� ++������ ����ص� ����
		++y; //���α����̹Ƿ� ��� ������ ���� ++������ ����ص� ����
		return pt;
	}
	/*
	//�ߺ� �ڵ带 ���ϴ� ������� ���� �ڵ带 ����� ���� �ִ�.
	const Point operator++(int) {
		Point tmp = *this;
		++*this;
		return tmp;
	}
	*/

};

int main() {
	Point p1(2, 3), p2(2, 3);
	Point result;

	result = ++p1; //p1.operator++();�� �����ϴ�.
	p1.Print();
	result.Print();

	result = p2++; //p2.operator++(0);�� �����ϴ�.
	p2.Print();
	result.Print();

	return 0;
}