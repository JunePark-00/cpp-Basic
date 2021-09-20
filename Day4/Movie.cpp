//파일명: Movie

// #include <> c++ 이미 만들어놓은 헤더파일을 내가 사용할때
// #include "" 프로그래머가 직접 만든 헤더파일을 사용할때 
#include"Myheader.h"

/*
 struct : 변수만 가지고 있다. 

 class : 사용자가 직접 만든 자료형 
     - 변수 + 함수를 가지고 있다.
	 - 기본적으로 멤버들이 은닉성 private으로 모든 변수가 잠겨있다.
	 - class키워드
	 - 클래스명 (첫 글자가 무조건 대문자)
	 - {} ; 원하는 자료형을 묶어서 만든다.
	 - 1) 은닉성 2) 상속 3) 추상화 4) 다형성 

*/

struct St{
	string name;
	int score;

};
class Student{ 

public: //공개
	string name;
	int score;

private: // 비공개
	int money;

	// 접근제어자 
	// private 내부접근 외부X
	// public 내부,외부 모두 접근 가능!

	// 기본설정 값이 private 클래스 내부에서는 접근이 가능하지만
	// {} 중괄호 밖에서는 접근이 안된다. 
	
};
int main(void){
	// 구조체 변수 선언 
	St st;
	st.name = "김철수";
	st.score = 100;

	// 클래스 변수 선언
	Student st2;

	st2.name ="홍길동";
	st2.score = 35;



	

	return 0;
}