#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(25);
	lt2.push_back(35);
	lt2.push_back(60);

	list<int>::iterator iter;
	cout << "iter1 : ";
	for(iter = lt1.begin();iter!=lt1.end();++iter){
		cout << *iter << ' ';
	}
	cout << endl;

	cout << "iter2 : ";
	for (iter = lt2.begin();iter != lt2.end();++iter) {
		cout << *iter << ' ';
	}
	cout << endl << "==========" << endl;

	lt1.merge(lt2); //l2를 lt1으로 합병 정렬. 정렬 기준은 less

	cout << "iter1 : ";
	for (iter = lt1.begin();iter != lt1.end();++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	cout << "iter2 : ";
	for (iter = lt2.begin();iter != lt2.end();++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	return 0;
}