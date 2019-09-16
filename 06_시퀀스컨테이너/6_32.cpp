#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> lt;

	lt.push_back(10); //뒤쪽에 추가
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	list<int>::iterator iter;
	for (iter = lt.begin();iter != lt.end();++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	lt.push_front(100); //앞쪽에 추가
	lt.push_front(200);
	
	for (iter = lt.begin();iter != lt.end();++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	return 0;
}