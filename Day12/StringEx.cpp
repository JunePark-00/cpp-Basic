//파일명: StringEx

#include<iostream>
#include<string>   //포함하기!문자에 대한 자료형쓰거나 비교할때!
#include<stdio.h>

using namespace std;

int main(){
	//char name[50] = "이서희"; // \0 동적할당 sizeof(name)+ 1  (char)malloc[strlen(name)+1]
	//char* name2 = "이서희";

	string name = "";  //\0없어요 객체이기때문에  
	// 길이를 확인하는 함수 
	// 자동으로 길이는 0 

	name  = "이서희";
	
	int size = name.length();  // size()
	cout << "문자열의 사이즈:"<< size << endl;

	name.size(); //string클래스 안에 이미 함수가 정의되어있기때문에 내가 호출해서 사용!

	// 비교 
	string name2 = "이서희";

	if(name == name2){
		cout << "같다;"<<endl;
	}else{
		cout << "다르다."<<endl;
	}

	string name3 = "이지희";

	if(name == name3){  //같으면 true, 다르면 false
		cout << "같다;"<<endl;
	}else{
		cout << "다르다."<<endl;
	}

	// 사전적으로 데이터를 비교해서 오름차순,내림차순
	// 비교할대상변수.compare(비교대상)
	// return 값을 돌려주는데
	// name < name3 -1
	// name > name3 1
	// name == name3 0

	cout << name.compare(name3) <<endl;

	// copy
	//  name.copy(char[],1,3);

	// 문자열 + (연결) , += 연결해서 대입!
	string str1 = "뽀로로";
	string str2 = "루피";

	cout << str1 + str2 <<endl;

	// 문자열을 찾는 함수 find("문자열")
	// 찾는 문자열의 첫번째 인자 반환

	// swap(str1,str2)
	// str1, str2를 바꾸는 것! 

	// 문자열 자르는 기능!
	// substr() "문자열 자체를 반환
	// substr(index) index부터 끝까지 반환
	// substr(index,len) index부터 len의 길이만큼 문자열을 반환

	string name4 = "hello joo";
	cout << name4.substr() <<endl;
	cout << name4.substr(3) <<endl;
	cout << name4.substr(1,5) <<endl;

	// empty() 
	// string 문자열 변수가 비어있는지 확인하는 함수 
	// 결과 bool 참, 거짓

	if(name4.empty()){
		cout << "비어있다"<<endl;
	}else{
		cout << "문자열있음"<<endl;
	}

	// split() 구분
	

	return 0;
}