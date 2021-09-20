//파일명: reference

#include"My.h"

//함수 데이터를 변경하는 함수!
void swap(int& a,int& b){
	
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "a:" << a <<"b:"<<b <<endl;
}


int main(){

	// 참조자 
	// 주소를 저장하는 변수  (포인터 변수)
	// &
	// 변수에 "별명"을 붙인다.
	// 그 별명을 통해서 변수의 메모리공간에 직접 접근이 가능하다
	// 참조자는 변수에 대해서만 선언이 가능하다
	// 선언과 동시에 누군가를 참조해야 된다.
	// 참조자는 참조의 대상을 바꾸는 것이 불가능하다.
	// 참조자는 NULL로 초기화하는 것이 불가능하다.
		
	int number = 10;  //일반변수: 데이터를 저장하는 변수
	int* p = &number; // C언어 포인터변수

	// C++ 참조자
	int& ref = number;

	cout << number <<endl;
	cout << ref <<endl;

	// swap 호출

	int a=100, b=200;
	
	swap(a,b);

	cout << "main a:" << a << "b :" << b <<endl;




	//cout << "확인"<<endl;
	return 0;
}