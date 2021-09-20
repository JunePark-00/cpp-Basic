//파일명: new

#include<iostream>  // cout ,cin 사용하기 위한 헤더파일
#include<string>    // 문자들에 대한 헤더파일


using namespace std;

struct Person{

	int age;
	string name;

};

/*
Person 구조체 배열선언 
 3명의 데이터를 저장  첫번째 이서희 20
				    두번째 이지희 25
					세번째 이정희 19

*/


int main(void){

	//Person* pt = new Person;

	//pt->age = 30;
	//pt->name = "이서희";

	
	Person* list = new Person[3];

	for(int i=0; i< 3; i++){

		cout << " 이름과 나이를 입력:";
		cin >> list[i].name >> list[i].age;
	}

	for(int i=0; i< 3; i++){

		cout <<"[" << i+1 <<"] 이름: " << list[i].name << endl;
		cout <<"[" << i+1 <<"] 나이: " << list[i].age << endl;
	}

// User user_list[3]; // 2001 2002 2003 
// struct_Shopping 파일에 가서 동적할당으로 생성해서 데이터를 채워보세요!
	
	
	//	list[1].name = "이지희";
//	list[1].age = 25;
	
	// 메모리의 동적할당
	// 컴파일 타임 -> 변수들의 메모리 사이즈 확인 
	//			     데이터영역 스택영역  (메모리할당과 크기 미리정하는 과정)

	// 런타임 -> 프로그램이 동작하는 도중에 (실행중인 프로그램)
	//  ex) 메모장  
	//        힙영역 -> 프로그래머가 직접 결정 삭제 추가 자유롭다.

	// new 
	// 동적할당으로 메모리 할당 받으면 주소값을 반환
	// 메모리공간 있으면 주소반환
	// 메로리공간 없으면 null

	// c++동적할당 선언방법
	// 타입* 포인터변수 = new 타입;
	/*
	int* p=new int;  
	double* p2 = new double;

	*p = 10;
	cout << "p포인터변수가 가리키는 데이터:"<<*p <<endl; 

	*p2 = 1.1;
	cout << "p포인터변수가 가리키는 데이터:"<<*p2 <<endl; 


	// 예외적 메시지 try catch
	if (p == NULL){
		cout << "메모리공간 없습니다.!"<<endl;
		//return; 요것때문에 에러가 발생합니다. 돌려주는 리턴값이
		//        일단 생략하도록 하겠습니다. 비정상적 종료를 의미하는건 
		//		  -1로 작성하셔도 됩니다!
	}

	// delete 포인터변수명;

	delete p;
	delete p2;
	

	// 동적할당 배열 

	int* ptr = new int[3];

	// 포인터 연산 
	// 배열 접근하는 방식 사용
	ptr[0] = 10;
	ptr[1] = 20;
	ptr[2] = 30;

	for(int i=0; i<3; i++){
		cout << ptr[i] <<"  ";
	}

	// 동적할당 해제
	delete[] ptr;

	*/





	return 0;
}