#include<iostream>
#include<string>

using namespace std;

int main(){
	// 학번과 이름을 각각 파일로 저장하는 것!

	int hakbuns[3] = {0};
	string names[3] = {""};

	// 프로그램이 멈추면 메모리가 휘발성 데이터가 모두 날라간다.
	// 저장

	// 1. 데이터베이스 
	// 2. 파일  
	//    1. 텍스트 파일 
	//    2. 이진파일  ( 비디오, 사진 , 음성 ,csv파일.. )
	//       기본적으로 C++ 자료형은 텍스파일로 저장X

	// 파일에 대한 객체를 생성 
	// C언어에서는 파일포인터 FILE*

	// 텍스트파일을 생성 fopen_s(파일포인터명,파일명,모드) 
	//                 fclose(파일포인터명)
	//				 close 제대로 하지 않으면 읽을 때 에러! 

	// 기본 저장: 현재 컴파일된 프로젝트 폴더 안에 파일이 생성!
	// 만약 저장하는 공간을 변경하고 싶을 때 는 두가지 방법

	// 1. 절대경로 
	// 디스크부터 현재있는 경로를 모두 표시

	// D:\C++방특\파일명

	// 2. 상대경로 
	//   . 표시  기본적인 경로가 현재 컴파일되는 폴더!
	//  ../ 상위폴더를 선택!


	// c++ 파일입출력을 사용할때는 ifstream 
	
	//파일 읽기
	FILE* file = NULL;
	fopen(&file,"0505.txt","rt");

	char temp[100];

	for(int i=0;  i<3; i++){
		fscanf(file,"%d %s\n",&hakbuns[i],temp);
		names[i] = temp;
	}
	fclose(file);

	for(int i = 0; i<3; i++){
		cout << hakbuns[i] <<": "<<names[i] << endl;
	}




	// 파일 쓰기 
	/*FILE* file = NULL;
	fopen_s(&file,"0505.txt","wt");


	// c_str() char* 형식으로 변경하겠다.
	for(int i=0; i<3; i++){
		fprintf(file,"%d %s\n",hakbuns[i],names[i].c_str());
	}
	fclose(file);
	*/



	return 0;
}