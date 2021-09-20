#include<iostream>
#include<string>
#include<cstdlib>
#include<vector> //추가!
#include<Windows.h> 
#include<time.h>


using namespace std;

class Subject{
public:
	string name;  //과목명
	int score;    //과목 점수
	int sbnumber;

	void subjectPrint(){
		// 과목과 점수를 출력하는 명령문 작성 
		cout << "과목명: "<< this->name << " ";
		cout << "점수:"<< this->score <<endl;
	}
	Subject(string sbname, int sbnumber){
		this->name = sbname;
		this->sbnumber = sbnumber;
	}
};

class SubjectManager{
public:
	string sbname;
	int sbnumber;

	vector<Subject> subjectList;

	void addSubject(){
		cout << " 과목명 , 번호"<< endl; 
		string sbname; int sbnumber;
		cin >> sbname >> sbnumber;
		
		this->subjectList.push_back(Subject(sbname,sbnumber));
	}


};

class Student{

private:
	string name;

public: 
	int number; 
	//수강하는 과목을 관리하는 매니저설정!
	SubjectManager sj;
	
	// 생성자
	Student(string name, int number){
		this->name = name;
		this->number = number;
		//this->sj = new SubjectManager;
	}
	void studentPrint(){
		cout << "학생의번호"<< this->number << " ";
		cout << "학생의이름:"<< this->name <<endl;
	}

	string getName(){
		return this->name;
	}
};

class StudentManager{

public:
	vector<Student> studentList;

	// login을 하는 함수를 작성 


	
	// 학생을 추가하는 함수 
	void addStudent(){

		cout << " 이름 , 번호"<< endl; 
		string name; int sel;
		cin >> name >> sel;
		
		this->studentList.push_back(Student(name,sel));
	}

	// 학생들을 전체 출력하는 함수 
	void StudentAllPrint(){
		for(int i=0; i<studentList.size(); i++){
				studentList[i].studentPrint();
		} 
	}
};



int main(){
	// 학생의 수강과목을 추가할때는 그 학생의 로그인 되어있어야만 추가할 수있다.!
	// 로그인이 되어있지 않으면 수강과목 추가 X
	StudentManager sm;
	SubjectManager sbm;
	int index = -1;  //-1일 경우 로그인 실패! 

	string id; 

	while(true){
		cout << "학생관리프로그램"<<endl;
		cout << "1. 로그인"<< endl;
		cout << "2. 로그아웃"<<endl;
		cout << "3. 학생 추가"<<endl;
		cout << "4. 학생 삭제"<<endl;
		cout << "5. 전체출력" <<endl;
		cout << "6. 수강추가" <<endl;
		cout << "7. 수강삭제" <<endl;

		int sel;
		cin >> sel;
		
		
		
		switch(sel){
		
		case 1: 			
			cout << "로그인 id :";  
			cin >> id;			
			
			// 로그인 
			for(int i = 0; i<sm.studentList.size(); i++){
				
				if(sm.studentList[i].getName()== id){
					cout << "로그인 성공" <<endl;
					index = i; //로그인한 학생의 인덱스를 저장
				}
			}
			if(index == -1){
				cout << "로그인을 하지 못했습니다."<<endl;
			}
			
			break;
		case 2:  
			
			if(index == -1){
				cout << "로그아웃 상태입니다"<<endl;
			}else{
				cout << "로그아웃 되었습니다."<<endl;
				index = -1;
			}
			break;
		case 3:  sm.addStudent();	break;
		case 4:  break;
		case 5:  sm.StudentAllPrint();	break;
		case 6:
			if(index != -1){
				// 로그인된 상태
				sbm.addSubject();
				/*sm.studentList[index].sj.subjectList.push_back(Subject("자바",1));
				sm.studentList[index].sj.subjectList.push_back(Subject("파이썬",2));
				sm.studentList[index].sj.subjectList.push_back(Subject("C++",3));*/
				
				// 1. 수강과목을 추가  자바 파이썬 c++
				// 출력형태는 1.자바 
				//			 2.파이썬
				//           3.c++
				// 생성자 이용! 
				// 2. 전체 출력하는 함수 
				// 3. subjectManager 클래스 안에 수강을 추가하는 함수를 정의
				//  addSubjdect() 


			}else{
				cout << "로그인을 해야 수강추가 가능합니다."<<endl;
			}
			break;

		case 7:
			break;

		default: cout << "1~7입력하세요!"<<endl;
		}
	}
	
	//화면을 잠시 멈추기 system("pause")
	// 화면을 지우기 system("cls")
	// 프로그램을 지연시키는 Sleep(3000) --> 2초


	///Student s1; // 입력값을 받는 생성자를 만들어놓으면 기본생성자 X
	//.number = 1;
	//s1.name = "이서희";
	//sm.studentList.push_back(Student("이서희",1));
	//sm.studentList.push_back(Student("돈도니",2));
	//sm.studentList.push_back(Student("뽀로로",3));

	/*
	for(int i=0; i < 3; i++){
		cout << " 이름 , 번호"<< endl; 
		string name; int sel;
		cin >> name >> sel;
		
		sm.studentList.push_back(Student(name,sel));
	}
	*/


	// 백터라는 studentList에 저장
	// 1 이서희
	// 2 돈도니
	// 3 뽀로로
	// 저장을 하고 studentPrint() 함수를 이용해서 출력!

	// 로그인 ( 이름)  
	// 로그인 성공시 수강과목을 추가!(자바,파이썬 , 씨언어 등등)
	
	// 백터 생성
	/*vector<int> v; //정수 여러개를 저장하는 배열생성 
	
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

	*/

	return 0;
}