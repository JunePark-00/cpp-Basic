//파일명: TemplateEx

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

// 계산기 
// 오버로딩 단점 : 타입이 변하거나 개수 달라질 때마다 함수를 새로 만들어야된다.
//                함수가 기하급수적으로 늘면 관리자 입장 관리 안된다.
// 단점 템플릿 : 컴파일시에 타입을 정해서 함수를 지정한다.
//		자바 -> 제네릭!

// 

// 더하기 
// 정수 정수 
// 실수 실수
// 정수 실수 
/*
void add(int i,int s){}
void add(double i, double s){}
void add(int i, double s){}
void add(int i, int s, int j){}


선언 방법 
전역변수 공간에 template<typename T>

템플릿 사용하는 변수가 2개 이상일 경우에는 함수 이름 뒤에 <> 안에 
// 명확하게 사용하지 않습니다. 
 컴파일이 그때 스스로 자료형을 판단합니다. 

*/

// 함수 템플릿 
template<class T>// 하나의 타입 지정

T sum(T a,T b){
	cout << a+b<< endl;
	return a+b;
}

template<typename T1,typename T2> //두개의 타입으로 각각 지정
        //int a, double b
void sum1(T1 a,T2 b){
	cout << a + b << endl;
}
//템플릿을 선언하실때 매개변수이름을 대문자 
// 리턴값, 매개변수 값 함수 안에서 실행되는 명령어 변수로도 사용이 가능합니다.

template<typename T1>
void swap(T1& a, T1& b){
	T1 temp;
	temp = a;
	a = b;
	b = temp;
}

int main(){

	int a = 10;
	int b = 20;

	double d1 = 2.2;
	double d2 = 3.3;

	string s1 = "SHow";
	string s2 = "show Show";

	cout << "int 합: " << sum<int>(a,b) <<endl;
	//함수가 실행할때 타입은 정수 타입으로 변해서 실행하게 되고
	cout << "double합:"<< sum<double>(d1,d2) <<endl;
	cout << "String합:"<< sum<string>(s1,s2) <<endl;
	// sum함수가 실행할때 타입은 string 타입으로 더하기를 한다.
	

	sum1<int,double>(a,d1);


	/*
	double sum(double i,double s){
			return i +s;
	}
	*/

	// 템플릿 
	// - 함수나 클래스를 개별적으로 다시 작성하지 않아도 여러 자료형ㅇ으로 
	//    사용할 수 있도록 하게 만들어 놓은 틀!
	// - 함수 템플릿, 클래스 템플릿 




	return 0;
}