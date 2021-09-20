//파일명: Cookie_Run

#include"Myheader.h"

// 쿠키 이름,쿠키등급,레벨
// 목숨 , 속성 

class Character{
public:
	string Cookie_name;
	string grade;
	string property1;
	int level;
	int hp;

	// 초기화하는 함수를 작성 
	void init(string name,string g,int l,int h ,string p){
		this->Cookie_name = name;
		this->grade = g;
		this->level = l;
		this-> hp = h;
		this->property1 = p;
	}
};

int main(void){

	// 백터 데이터를 저장하는 방법중에 하나!
	// 배열을 이용해서 데이터를 추가하거나 삭제하는 것!

	// 배열의 길이를 확인할 수있는 변수
	int count = 0;

	// 캐릭터를 추가해서 접근할 수있는 동적할당 변수를 선언
	Character* p = NULL;	


	while(true){
		cout << "1. 게임시작" << endl;
		cout << "2. 캐릭터 선택(추가)" <<endl;
		cout << "3. 캐릭터 창 확인(출력)"<< endl;
		cout << "4. 캐릭터 삭제"<<endl;

		int sel;
		cout << ">>"; cin >> sel;

		if(sel == 1){
			cout << "게임시작"<<endl;
		}else if(sel == 2){

			if(count == 0){
				p = new Character[count +1];
			}else{
				Character* temp = p;    // 기존배열을 복사하기위해서
										// 잠시 임시저장하는 공간

				p = new Character[count +1]; // 추가되는 배열의 생성

				for(int i=0; i<count; i++){ // 이전 데이터를 복사하는명령문
					p[i] = temp[i];
				}
				delete[] temp;
			}

			// 추가될 캐릭터의 정보를 저장
			cout <<"추가될 쿠키이름:"; cin>> p[count].Cookie_name;
			cout <<"추가될 쿠키등급:"; cin>> p[count].grade;
			cout <<"추가될 쿠키레벨:"; cin>> p[count].level;
			cout <<"추가될 쿠키목숨:"; cin>> p[count].hp;
			cout <<"추가될 쿠키속성:"; cin>> p[count].property1;

			count = count +1; // 카운트는 배열의 길이
		}else if(sel == 3){

			cout << " 캐릭터 창 확인"<<endl;
			for(int i=0; i < count; i++){
				cout <<"추가될 쿠키이름:" << p[i].Cookie_name <<endl;
				cout <<"추가될 쿠키등급:" << p[i].grade<<endl;
				cout <<"추가될 쿠키레벨:" << p[i].level<<endl;
				cout <<"추가될 쿠키목숨:" << p[i].hp << endl;
				cout <<"추가될 쿠키속성:" << p[i].property1 << endl;
			}
			cout << "========================="<<endl;

		}else if(sel == 4){
			// 삭제할때는 변수들 
			// index , 캐릭터 이름 삭제 (예시)

			int del_idx=-1; // 동적할당 한 new 배열의 index 0부터 시작!

			string delname;
			cout << "삭제할 캐릭터이름:"; cin >> delname;

			// 삭제할 인덱스를 찾는 반복문
			for(int i=0; i<count; i++){
				if(p[i].Cookie_name == delname){
					del_idx = i;
				}
			}

			if(del_idx == -1){
				cout << "찾는 캐릭터가 없습니다."<<endl;
				cout << "다시 입력하세요!"<<endl;
			
			}else{
				// 삭제하는 명령
				Character* temp = p;

				p = new Character[count-1];

				int j = 0; // 새로만든 배열의 count

				for(int i=0; i<count; i++){

					if(i != del_idx){
						p[j] = temp[i];
						j = j +1;
					}
				}
			}
		}

	}







	/*
	Character cookie1;	
	cookie1.init("치어리더맛쿠키","S",6,160,"치어리더응원단6단");
	
	Character cookie2;
	cookie2.init("특전사맛쿠키","S",6,160,"별사탕 사격6단");

	Character cookie3;
	cookie3.init("용감한 쿠키","C",1,90,"용감한");

	
	cookie1.Cookie_name = "치어리더맛쿠키";
	cookie1.grade ="S";
	cookie1.level = 6;
	cookie1.hp = 160;
	cookie1.property1 =" 치어리더응원단6단";
	*/



	return 0;
}