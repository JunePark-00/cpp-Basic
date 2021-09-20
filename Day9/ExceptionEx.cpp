//파일명: ExceptionEx

#include<iostream>
#include<string>
using namespace std;


int main(){

	char myarray[10]; 
	
	try{
		char * mystring;

		mystring = new char[10];

		if(mystring == NULL){
			throw "메모리할당 실패!";
		}

		for(int n =0; n<10; n++){
			
			if(n > 9){
				throw "범위를 넘었습니다.";
			}
			myarray[n] = 'A';
		}
	}catch(string str){// 에러메시지 문자일 경우
		cout << "예외:"<< str <<endl;
	}catch(int i){
		// 정수일때는 밑에 catch 정수에 대한 예외처리
	}

	// 동적할당 할 경우 메모리공간이 없으면 NULL 
	// 파일 입출력할때 try ~ catch







	return 0;
}


/*

예외 구문 처리

try{

	// 예외발생하는 구문
	// throw 예외;

}catch(type 예외){
	//예외처리에 실행되어질 코드 	
}


void swap(int& a,int& b){

	int tmp;

	// swap함수를 이용해서 데이터 변경을 해야되는데
	// 동일한 데이터를 변경 할 수는 없다.
	if(a == b) throw a;

	tmp = a;
	a = b;
	b = tmp;
	
}

int main(){

	int num1;
	int num2;

	try{
		cin >> num1;
		cin >> num2;

		// 함수 호출시 예외가 발생 
		swap(num1,num2);

		cout << "정상 호출"<<endl;
		cout << "num1 :"<< num1 <<"num2:"<<num2<<endl;
	}catch(int expn){// throw를 통해 변수를 인자값으로 받는다.
		cout << "실패"<<endl;
		cout << "num1,num2:"<< expn <<"으로 동일하다"<<endl;
	}

	// 객체 지향 프로그램에는 예외적인 상황을 처리하는 클래스
	// exception 클래스
	

	// 예외처리
	// - 프로그램이 비정상적으로 종료되지 않도록 처리하는 것!
	
	// 예외 - 프로그램 코드로 수습 가능한 것!
	// 에러 - 프로그램 코드로는 수습이 불가능! 

	// 컴파일에러
	//  -> 프로그램 시작전에 번역하는 단계 
	// 런타임에러 
	//  -> 프로그램이 실행중에 나타는 에러!

	// 프로그램을 정상적으로 실행하기 위해서 if문 
	// try -> try 내부에서 예외가 있는지 없는지 탐색하는 부분
	// catch -> try 내부에서 예외가 발생하면 catch내부에서 처리하는 부분
	// throw -> 발생한 예외의 인자값을 보낸다.

	// 두 정수를 입력받아서 나눈 결과를 확인하는 프로그램 
	/*int a, b;

	//cin>> a; 
	//cin>> b;

	//cout << a/b << endl;
	//cout <<"정상종료"<<endl;

	//예외적인 상황이 발생할 수있는 부분
	try{
		cin>> a; 
		cin>> b;

		if(b <= 0){
			throw b; // 예외발생시 throw를 통해서 변수 b를 catch 매개변수로보냄

		}
		
		cout << a/b << endl;
		
	}catch(int expn){
		cout << "[에러]"<<endl; // 에러메시지!
		cout << " 0으로 나눌 수 없다!"<< endl;
	}
	
	
	cout << "정상종료!"<<endl;

	


	return 0;
}
*/