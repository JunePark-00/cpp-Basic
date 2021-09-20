//파일명: Vector
/*
#include<string>
#include<iostream>
#include<vector>
using namespace std;
*/

#include"My.h"
#include<vector>

class Student{

public:
	string name;
	int score;

};
int main(){

	vector<Student> vec;

	while(true){

		cout <<"1. 추가"<<endl;
		cout <<"2. 삭제"<<endl;
		cout <<"3. 정렬"<<endl;
		cout <<"4. 출력"<<endl;

		int sel;
		cin >> sel;

		if(sel == 1){
			cout << "이름:";
			Student st;
			cin >> st.name;

			cout << "점수:";
			cin >> st.score;

			vec.push_back(st);
		}else if(sel == 2){

			for(int i=0; i < vec.size(); i++){
				cout << "["<< i <<"]" << vec[i].name << vec[i].score;
			}

			// 삭제를 할 때 erase()
			cout << "삭제할  번호를 입력하세요:"<<endl;
			int num;  cin >> num;
			// begin() : 시작 인덱스를 가지고 온다.
			vec.erase(vec.begin()+num);
		
		}else if(sel == 3){
			// 점수가 가장 큰 값부터 정렬 내림차순
			// 가장 작은 값부터 큰 값 오름차순

			// 배열 
			 int arr[] = {80,50,60,100,90};

			  for(int i =0; i<5; i++){
				 int max = arr[i];
				  for(int j=0; j<5; j++){
					 if(max < arr[j]){
						int temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					 }
				 }
			 }


			// 100 90 80 60 50 데이터가 출력 될 수있도록 명령문 

			 for(int i =0; i<vec.size(); i++){
				 for(int j=0; j<vec.size(); j++){
					 if(vec[i].score > vec[j].score){
						 Student temp = vec[i];
						 vec[i] = vec[j];
						 vec[j] = temp;
					 }
				 }
			 }
			 
		}else if(sel == 4){
			for(int i=0; i < vec.size(); i++){
				cout << i <<":" << vec[i].name << vec[i].score << endl;
			}
		}
	}

	return  0;
}



/*
#include"My.h"
#include<vector>

// Vector 자료구조 형태
// 배열을 추가하고 삭제하고 데이터를 저장하는 방식

// vector 키워드
// <자료형> => 사용할 자료형을 표시한다.
// include<vector>

int main(){
	// <자료형> 템플릿 
	vector<int> vec;

	// 추가하기 
	// 맨 뒤에 추가 
	// push_back(value)
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	// 길이 구하기 
	// size()

	for(int i=0; i<vec.size(); i++){
		cout << vec[i] <<endl;
	}
	cout << "===================="<<endl;

	// 삽입하기 
	// insert(index,value)
	// 해당 index에 값을 삽입
	// . 나머지는 뒤로 밀려난다.

	vec.insert(vec.begin(),9);
	
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] <<endl;
	}
	cout << "===================="<<endl;

	// 삭제하기 (소멸자) 정의가 되어있으면 출력
	// 맨 뒤에 있는 값 삭제
	vec.pop_back();

	for(int i=0; i<vec.size(); i++){
		cout << vec[i] <<endl;
	}
	cout << "===================="<<endl;



	return 0;
}
*/