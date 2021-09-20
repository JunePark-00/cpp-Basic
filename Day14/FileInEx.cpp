//파일명: FileInEx
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

	// 읽기
	// 1. 입력스트림 객체를 생성
	// 텍스트 파일로 저장한 내용은 문자 형태의 자료형으로 저장된다!
	/*string str;
	ifstream ifs;

	ifs.open("test.txt");

	// eof()
	//  파일 내용의 끝에 도달하면 true
	//  
	while(!ifs.eof()){

		ifs >> str;
		cout << str <<endl;
	}
	*/
	// is_open()
	// 파일 스트림이 연결이 되어있다. 파일이 열려있을 경우 
	//  true 반환 

	// 파일입출력 문제(실습)
	// 1. numberlist.txt 생성
	// 2. 1부터 10까지 저장

	ofstream fout;

	fout.open("numberlist.txt");

	for(int i=1; i<11; i++){
		fout << i <<endl;
	}

	fout.close();


	ifstream ifs;
	ifs.open("numberlist.txt");
	int num;

	for(int i=0; i<10; i++){
		ifs >> num ;
		cout << num <<endl;
	}

	ifs.close();
	
	// 불러와서 출력까지 하기!

	// string클래스의 문자를 한줄단위로 불러오는 함수
	// getline(파일객체,변수명);


	return 0;
}