#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

//클래스 
template<class T,class E>

class Box{ // 어떤 타입이든지 결정 컴파일시!

public:
	T data;  // Apple data; 
	E data2; 
};

class Apple{

public:
	int i;

	Apple() { cout << "사과객체생성"<<endl; }
};

class Orange{

public:
	int j;

	Orange() {  cout << "오렌지 객체 생성"<<endl; }
};

int main(){
	//기본자료형 
	Box<int> b1;
	b1.data = 10;

	cout << b1.data<<endl;

	Box<double> b2;
	b2.data = 10.10;
	cout << b2.data<<endl;

	Box<Apple> a1;
	a1.data.i = 100;

	cout << a1.data.i <<endl;

	Box<Orange> o1;
	o1.data.j = 200;
	cout << o1.data.j <<endl;

	return 0;
}