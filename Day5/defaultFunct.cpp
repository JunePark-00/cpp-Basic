//파일명: defaultFunt

#include"My.h"

//	 addDouble(1.1);

// 함수의 원형
// 함수가 main 뒤쪽에 위치해 있기때문에 위에서 코드를 컴파일하는
// 입장에서 함수가 어디있는지 매개변수의 개수 몇개인지 알 수 가 없다
// 중요한 반환값 , 함수명,매개변수 개수 
void addDouble(double=0.0,double=0.0);


int main(void){
	// c언어경우	add(10); 	add(); 매개변수를 넘겨주지 않으면 에러!
	
	// c++ 경우

	addDouble(1.1,2.2);
	addDouble(1.1);
	addDouble();

	add(); //만약 함수를 호출할때 매개변수값을 써주지 않으면
		   // add함수안에서 설정된 기본값으로 연산 혹은 출력한다.

	add(100);



	// 디폴트인수 
	// 기본값이 미리 정의 되어있는 인수 
	// 함수의 매개변수에 초기화가능!
	// 설정할때는 항상 뒤쪽부터 설정


	return 0;
}

void addDouble(double a=0.0,double b=0.0){
	double total = a+b;
	cout << "실수 더한값:"<< total << endl;
}

void add(int i=0){
	i = i+i;
	cout << "더한값:"<< i << endl;
}

void show(int a=0,double b= 0.0,char ch='a'){
	cout << a << b << ch << endl;
}