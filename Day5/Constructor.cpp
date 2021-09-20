//파일명: Constructor

#include"My.h"



class Person{
//공개 비공개 -> 접근제어자!(private, public, protected)
	
// 멤버 
// 멤버 변수 
//	int b;
public:
	int a;

	Person(int a1){
		this->a = a1;
		cout << "생성자 동작!"<< endl;
	}
// 멤버 함수
	void show(){  cout << this->a << endl;	}
};

class Test{

public:
	int a;
	double b;
	string str;

	Test(){}
	//입력값을 받는 생성자
	Test(int a1,double b1,string str2){
		this->a = a1;
		this->b = b1;
		this->str = str2;

		cout << "a:"<< this->a << endl;
		cout << "b:"<< this->b << endl;
		//cout << "str:" << this-> str <<endl;
	}
};

class A{
	//A(){} 기본생성자
};


int main(){
	A a1; // 클래스로 인해서 실제 사물 개념 
	      // 객체

	Test t1(10,1.1,"문자");
	Test t2;
	
	//Person p1;	p1.a = 10;	Person p2 = {10};
	//Person p3{10}; 상위버전에서는 충분히 사용이 가능!

	// 생성자 
	// 클래스 객체 생성과 동시에 멤버 변수를 초기화(자동적)해주는
	// 멤버 함수
	// 입력값을 받는 생성자를 만들 경우에는 기본생성자가 생기지 않는다.
	// 클래스 기본적으로 기본생성자를 하나씩 가지고 있고 
	// 생략이 가능하다.

	// 생성자를 선언
	// 1. 생성자의 이름은 클래스이름과 동일해야된다.
	// 2. 생성자는 리턴 타입이 없다.

	// 생성자를 이용한 클래스 객체 생성
	Person p(10);

	// 1. Person 타입으로 객체 생성(메모리공간선언)
	// 2. 10라는 입력값을 a변수에 저장
	// 3. 주소값을 p에 저장한다.


	// 클래스로 객체를 생성
	// Person p1;
	// 1. Person 타입으로 메모리공간을 선언하고 
	// 2. 주소값을 p1에 저장

	return 0;
}