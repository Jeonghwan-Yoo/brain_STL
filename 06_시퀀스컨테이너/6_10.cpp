#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v(5);

	cout << "size : " << v.size() << " capacity : " << v.capacity() << endl;

	//기본 생성자로 만든 vector컨테이너와 v컨테이너를 swap한다.
	vector<int>().swap(v);
	cout << "size : " << v.size() << " capacity : " << v.capacity() << endl;

	return 0;
}