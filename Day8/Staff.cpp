//파일명: Staff

#include<iostream>
#include<string>

using namespace std;

// c언어에서 공통적으로 변수를 하나가지고 사용하는 static 
// 객체를 생성할 때마다 하나씩 증가 시켜서 사원번호를 지정할 것!
// 정적 멤버 변수 
//  클래스에 속하지만 객체 별로 변수가 생성 X
//  클래스의 모든 객체가 공유하는 멤버 
//  하나의 뎅이터만 유지 관리됩니다.
//  지금같은 사원의 번호 , 계좌번호 , 공유폴더 
// 정적멤버변수 접근하는 방법

// 클래스명.멤버변수

// 전역변수 : 프로그램의 전체적인 영역에서 누구나 상속관계없이 
//           접근가능 하다. 저장되는 메모리 영역 데이터영역!

// static : 선언된 클래스 안에서는 누구나 접근이 가능하고 
//         만약 static이 선언된 클래스를 상속받아간다면 당연히 접근 가능
//         하지만 상속관계가 없는 클래스는 접근 X

class Employee{

//private:
//	int number;

public: 
	string name; // 인스턴스변수 or 멤버 변수  각각 객체안에 생성
	static int number;   // static변수 객체안에 X 

	Employee(int n,string name){
		number++;
		this->name = name;
		cout << number << "번째 사원번호발급"<<endl;
	}
};
int Employee::number = 0; // 정적멤버 변수의 정의및 초기화!
// :: 어디 클래스 안에 멤버 
// 객체(자동차) , 인스턴스 ( 벤츠C이서희오너)
// 객체(사람)  인스턴스(이서희)
// 객체(스마트폰) 인스턴스 (갤럭시10노트사용하는 이서희)

// 
class PartTime{

	PartTime(){
		//number++;
		cout << "아르바이트"<<endl;
	}

};

int main(){
	// 객체 메가커피->직원-> 사람

	Employee s1(0,"홍길동"); //인스턴스

	Employee s2(0,"이몽룡"); // 인스턴스 

	// 클래스 멤버 , 함수 
	// 클래스 멤버 변수(인스턴스 변수) 인스턴스 안에 각각
	//       멤버 공유되는 static (클래스변수)

	//            함수 멤버함수(인스턴스 함수)
	//            공유되는 static 클래스 함수 

	// 객체 생성되기 이전에 이미 전역변수처럼 메모리에 할당
	// 생성자에서는 초기화를 해줄 수 없다.
	


	return 0;
}





// 메가커피 
// 정규직과 아르바이트

// 직원 employee 
//  string name, int number 사원번호 , type 타입을 저장 

// 정규직 
// 급여 월급여 + 보너스 
// 멤버 급여변수 , 보너스 변수 
//   함수로 급여를 계산하는 getPay() 정의하기 급여 + 보너스 
//      월 급여: ** 입니다. 출력!

// 아르바이트 
// 멤버 변수 시간 time 시급변수 
//   함수로 급여를 계산하는 getPay() 정의하기 time * 시급
//      월급: ** 입니다. 출력! 



