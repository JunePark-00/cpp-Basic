//파일명: Overloading

#include"My.h"

// 함수 오버로딩 (new) 새로운 함수만든다. 
// 같은 이름의 함수를 중복해서 정의할 수있다.
// 매개변수의 개수로 구별! 타입으로 구별!

// 함수의 기본값설정시 호출에 문제가 생길 수있으니 조심해서
// 설정을 해야된다. 

// 함수 오버라이딩 -> 클래스 상속에서 중요하게 사용되는 구문

// c++언어로 계산기를 만들어야된다.
// 객체 지향 프로그램 (언어) 
void add(int a){
	a = a+a;
	cout << "하나 더하기:" << a << endl;
}
void add(int a,int b){
	int total = a+b;
	cout <<"두개 정수더하기:"<< total << endl;
}
void add(double a=1.1, double b=2.2){
	double total = a+b;
	cout <<"두개 실수더하기:"<< total << endl;
}

void add(int a=10, double b=10){
	double total = a+b;
	cout <<"한개는 정수 한개는 실수더하기:"<< total << endl;
}

int main(void){

	add(10);
	add(10,20);
	add(1.1,2.2);
	add(10,20.215);



	return 0;
}