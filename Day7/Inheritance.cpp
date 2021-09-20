//파일명: Inheritance

#include"Myhead.h"

/*
헤더파일이 만들기 힘들면
#include<iostream>
#include<string>

using namespace std; 요것만 파일에 추가해주세요!
*/

class Point{ //기본 클래스 

public:
	int x,y;  // x좌표 , y좌표값을 저장

	//x좌표y좌표 수정하는 함수
	void set(int x,int y){
		this->x = x;
		this->y = y;
	}
	void print(){ //좌표출력하는 함수
		cout << "("<< x <<"," <<y <<")" << endl;
	}
};
// 상속하는 방법
// class 자식클래스 : public 부모클래스{}

class Shape : public Point{
	
};

// 상속을 받아와도 새로만드는 자식클래스에 변수나
// 함수를 추가해서 만들 수있다.
// 객체 지향 프로그램은 모두 공통적인 부모 Object클래스 

class Color : public Point{ //자식클래스 
public:
	string color1;

	void colorprint(){
		cout << "입력한 컬러:"<< color1<<endl;
	}
};


int main(void){

	Shape s1;
	s1.x = 10;
	s1.y = 20;

	s1.print();
	s1.set(100,200);
	
	// 상속 : 물려 받는다.
	//      : 다른 클래스를 상속해서 마치 자기 클래스 인것처럼 
	//		: 사용하는 것!

	// 상속은 사용자에게 높은 수준의 코드 재활용성을 제공
	// 클래스간에 계층적 관계를 구성하므로 다형성 




	return 0;
}