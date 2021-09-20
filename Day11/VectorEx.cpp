#include<iostream>
#include<string>
#include<cstdlib>
#include<vector> //추가!

using namespace std;

class Student{

private:
	string name;

public: 
	int number; 

	// 생성자 

	void studentPrint(){
		cout << "학생의이름:"<< this->name <<endl;
		cout << "학생의번호"<< this->number << endl;
	}
};

class StudentManager{

public:
	vector<Student> studentList;

};

class Subject{
public:
	string name;  //과목명
	int score;    //과목 점수

	void subjectPrint(){
		// 과목과 점수를 출력하는 명령문 작성 
	}
};

class SubjectManager{
public:
	vector<Subject> subjectList;

};

void menu(){
	cout << "학생관리프로그램" << endl;
	cout << "1. 로그인" << endl;
	cout << "2. 로그아웃" << endl;
	cout << "3. 학생추가" << endl;
	cout << "4. 전체보기" << endl;
	cout << "5. 학생삭제" << endl;
	cout << "6. 과목추가" << endl;
	cout << "7. 수강삭제" << endl;

}


int main(){

	StudentManager sm;
	int index = -1;
    int sel;
	string id;
	
	// 백터라는 studentList에 저장
	// 1 이서희
	// 2 돈도니
	// 3 뽀로로
	// 저장을 하고 studentPrint() 함수를 이용해서 출력!

	// 로그인 ( 이름)  
	// 로그인 성공시 수강과목을 추가!(자바,파이썬 , 씨언어 등등)
	while(true){

		menu();
		cin >> sel;

		switch(sel){
		case 1:
			if(index == -1)
			break;
		case 2:
			if(index == -1){
				cout << "로그아웃된 상태입니다." << endl;
			}
			else{
				cout << "정상적으로 로그아웃되었습니다." << endl;
				index = -1;
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}
		
		
	}
	
	// 백터 생성
	vector<int> v; //정수 여러개를 저장하는 배열생성 
	
	// 자동배열에 데이터를 추가하는 것 push_back(value) 맨 뒤부터 추가 
	v.push_back(10); // 0
	v.push_back(20); // 1
	v.push_back(30); // 2

	// index 접근 할때 at(index) : 범위를 점검하므로 안전성이 좋다.
	//                v[index]  : 범위를 점검 X  속도!

	cout <<"at함수:" << v.at(0) <<endl;

	cout << "배열처럼[]: "<< v[0] <<endl;
	cout << "배열처럼[]: "<< v[1] <<endl;
	cout << "배열처럼[]: "<< v[2] <<endl;

	// 첫번째 원소(index) 참조
	// front() 
	cout << v.front() <<endl;

	// 마지막 원소 참조
	cout << v.back() <<endl;

	// 원소들을 제거! 
	// clear() 
	v.clear();	

	// vector  
	// 자동으로 메모리가 할당되는 배열
	// 삭제, 추가 알아서 맨 끝으로 추가할건지 맨 앞으로 추가! 
	// 함수들이 이미 만들어져있다.
	// 호출만 해서 사용하면 된다.

	// stack 자료구조
	// 단점 : 배열기반  삽입 삭제가 빈번하게 일어나면 비효율적 



	return 0;
}