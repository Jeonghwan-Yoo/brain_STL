#include <iostream>
#include <algorithm> //for_each() 알고리즘(서버)을 사용하기 위한 헤더
using namespace std;

/////클라이언트/////
struct Functor1 {
	void operator()(int n) { //공백을 이용해 원소 출력
		cout << n << " ";
	}
};
struct Functor2 {
	void operator()(int n) { //각 원소를 제곱해 출력
		cout << n * n << " ";
	}
};
struct Functor3 {
	void operator()(int n) { //문자열과 endl을 이용해 원소 출력
		cout << "정수 : " << n << endl;
	}
};

int main() {
	int arr[5] = { 10,20,30,40,50 };

	//임시 함수 객체(Functor1())를 만들어 함수로 전달
	for_each(arr, arr + 5, Functor1());

	cout << endl << endl;
	//임시 함수 객체(Functor2())를 만들어 함수로 전달
	for_each(arr, arr + 5, Functor2());
	
	cout << endl << endl;
	//임시 함수 객체(Functor3())를 만들어 함수로 전달
	for_each(arr, arr + 5, Functor3());
	
	return 0;
}