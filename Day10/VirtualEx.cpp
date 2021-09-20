//파일명: VirutalEx

#include<iostream>
#include<string>
#include<cstdlib> // 동적할당 new 키워드를 사용하기 위해서
				  // c언어에서 stdlib.h 해더와 같은것!

using namespace std;

class Car{ // 추상클래스 : 누군가에게 강제성을 부여하기 위해서 (다형성 도움줄 목적으로 사용)

public: 
	void Drive(){ cout << "앞으로 이동"<<endl; }
	void Stop(){ cout <<"멈춘다."<<endl; }
	virtual void openDoor()=0; // 순수 가상함수 
};
// 가상함수 
// 일반 가상 함수 {} 
// 순수 가상 함수 {} X


// 일반자동차 , 슈퍼카 

// 가상함수를 가진 클래스는 불완전 클래스 객체를 생성할 수 가 없다.
// 가상함수를 하나라도 가진 클래스는 추상클래스 부른다.
// 자바 추상클래스 , 가상함수 추상메서드 !


class SuperCar : public Car{

public: 
	void openDoor(){
		cout << "위로열린다."<<endl;
	}
};

class A{  //캐릭터창!

public:
	virtual void show(){ cout << " A클래스"<<endl;}
};

class B : public A{ //워리어!
public:
	void show(){ cout << "B클래스"<<endl; }
};

int main(void){

	B* b1 = new B;
	b1->show();   //오버라이딩 자식!

	//다형성 부모클래스명으로 참조변수를 선언!
	// 
	A* a1 = new B;
	a1->show();






	//Car* c1 = new Car;  // 객체 생성X

	//SuperCar* c2 = new SuperCar;
	//c2->openDoor();


	// 가상 함수 
	// -> 상속하는클래스에 꼭 들어가되는 규칙! 강제적으로 상속하기 위해서
	//    사용하는 것! 
	// -> 다형성 사용하면 꼭 알아야되는 중요한 함수
	// -> 부모클래스가 참조변수로 선언되고 실제 객체가 자식클래스이면 
	//    부모클래스의 함수밖에 접근을 못하기 때문에 자식이 오버라이딩한 내용에 접근하고
	//    싶을 경우에는 가상함수를 사용할 수 밖에 없다!

	// 자동차를 만들때 필수조건 
	// 문이 열려야된다. 문이 닫혀야 한다. 앞으로 간다 뒤로 간다. 멈춰야된다.



	return 0;
}