//파일명: FileInOutEx

#include<iostream>
#include<string>
#include<fstream> // C++에서 파일을 저장하고 읽는 헤더파일

using namespace std;

int main(){

	// 스트림 (Stream)
	//  데이터를 전송하는 통로
	//  한쪽 방향으로 통로가 정해진다.

	// 한쪽 프로그램(c++)이 연결 반대쪽 파일,키보드 

	// 입력 : 키보드로 입력 cin
	//  ex) 장치 ( 키보드 , 핀포인트,소리,빛)

	// 출력 : 모니터 출력 , 프린트 
	// 프로그램에서는 입력(키보드) 과 출력(모니터)

	// cin >> , cout << 

	// 파일을 읽고 생성하는 open()
	// 입력,출력인지 클래스 객체를 이용해서 모드를 먼저 결정

	//입력클래스 객체를 생성(읽기)

	ifstream ifs; // 입력스트림 ifs 객체 생성

	// 출력클래스 객체를 생성(쓰기)
	ofstream fout; // 출력스트림 fout 객체 생성 

	// 읽기모드에서 파일을 open("파일명.txt")
	// ifs.open("test.txt");

	// 저장 (쓰기모드)
	fout.open("test.txt");
	// 파일이 없으면 test.txt라는 파일을 생성하라!
	// 파일이 있으면 test.txt라는 파일을 생성하지는 않는다.
	// 단~ 그안에 있는 내용을 모조리 지워린다.
		
	// 내용을 저장하는 방법

	fout << "1234" <<endl;
	fout << "이서희"<<endl; 
	fout << "이지희"<<endl;

	fout.close(); //파일을닫는 연습! 항상!

	/* :: 범위 연산자 어떤 특정 클래스안에 범위에 있다! 

	ofstream fout("파일명",ios_base::out) 생성자 

	*/


	return 0;
}