// 메모 한줄주석
/* 요기서부터 메모시작합니다.
   요기까지 메모합니다.
*/

#include<iostream>   // #include<stdio.h>
#include<string>	 // 문자들을 저장하는 string 헤더파일을 포함하다.

using namespace std; 

int main(void){

	// printf() ==  C++ 에서는 cout << 출력하고싶은 문장;
	// \n  == c++ endl;
	cout << "hello world" << endl;
	cout << 10 << endl;
	cout << 1.1 <<endl;

	// C 자료형 
	// int			4byte
	// char			1byte
	// double		8byte
	// bool			1byte   --> 참과 거짓을 저장하는 자료형 

	// C언어에서 참과 거짓은 1 , 0 
	// c++ true , false

	bool b = true;
	bool c = false;
	
	//cout << b << endl;
	//cout << b  << c << endl;

	// c언어에서 문자들을 저장할 때 
	// char name[100] = "이서희";

	// c++ string
	//     #include<string>
	string str = "김철수";
	cout << str << endl;

	return 0;
}