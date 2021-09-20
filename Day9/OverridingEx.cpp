//파일명: Overriding

#include<iostream>
#include<string>

using namespace std;


/*
class Pokemon{ //포켓몬의 공통적인 기능! 
public:
	void attack(){
		cout <<"기본공격"<<endl;
	}
};

class Pikachu : public Pokemon{
public:
	// 피카츄 전기 공격 
	void attack(){
		cout << "전기공격!"<< endl;
	}
};

// 스타크래프 테란 군대!
// 사람,탱크,비행기 게임을 구성하는 캐릭터 

class Unit{

public:
	int hp; //목숨 

	void attack(){}

};

// 하늘에서 움직이는 캐릭터들의 그룹
class Sky :public Unit{

};

// 땅에서 움직이는 캐릭터들의 그룹
class Land : public Unit{
	
};

//군인

class Marine : public Land{
public:
	void attack(){
		cout << "사격한다"<<endl;
	}
};

// 비행기
class Airplane :public Sky{

public:
	void attack(){ //오버라이딩
		cout << "미사일 발사!"<<endl;
	}
	void attack(string str){ //오버로딩 
		cout << "새로운 공격:" <<str << endl;
	}
};
*/

class Shape{

public:
	void Draw(){}
};

class Rect : public Shape{
public:
	void Draw(){
		cout << "사각형"<<endl;
	}
};

class Circle : public Shape{
public:
	void Draw(){
		cout << "원"<<endl;
	}
};


int main(){

	cout <<"이서희"<<endl;


	Shape s1; // 그리는 함수를 가진 객체!

	Rect r1; // 사각형을 그리는 함수를 가진 객체!

	Shape s2[] = new Shape[2];

	// 조변수가 부모 클래스로 선언이 되고 실제 생성되는 
	// 객체는 자식클래스로 생성이 가능하다.
	// 단! 부모로 참조를 하게 되면 부모가 물려준 데이터 밖에 접근을 
	// 못 한다.

	s2[0] = new Circle();
	s2[1] = new Rect();



	//Airplane a1;
	//a1.attack();

	//Marine m1;
	//m1.attack();
	
	
	
	//Pikachu c1;
	//c1.attack();

	
	// 오버라이딩 
	// 부모한테 물려받은 함수의 내용을 자식클래스에 
	// 맞게 재정의 

	// 오버라이딩의 단점 
	// - 강제성 부여 약하다.
	// - 가상함수 , 추상클래스! 강제적으로 오버라이딩을 할 수 밖에 없게
	//   만드는 것!

	// 1. 상위클래스(부모클래스) 함수가 있어야된다.
	// 2. 함수의 이름 동일해야된다.
	// 3. 매개변수의 개수,타입이 똑같아야된다.
	// 4. 함수의 리턴값도 같아야된다. 
	// 5. { } 함수 실행했을때 내용만 다르게 바꾸는 것!


	// 다형성 
	//  - 여러 가지 형태를 가질 수있는 능력 
	//  - 하나의 참조변수 여러가지의 객체(자식클래스를 ) 참조할 수있는 것!

	

	return 0;
}
