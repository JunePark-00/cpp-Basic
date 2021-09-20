//파일명: Game

#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

// 캐릭터를 관리하는 창

// 캐릭터 내용  (기본공격,id,목숨(체력), 마력)

class Character{
	
public:
	int hp;
	int mp;
	string id;
	
	void attack(){} //기본공격은 반드시 자식이 오버라이딩 
};

//전사 힘을 쓰는 캐릭터

class Warrior : public Character{

public: 
	void attack(){
		cout << "칼로 공격"<<endl;
	}
};

class Wizard : public Character{

public:
	void attack(){
		cout <<"마법으로 공격"<<endl;
	}
};
//화살로 공격하는 캐릭터 
class Archer : public Character{

public:
	void attack(){
		cout << "활로 공격"<<endl;
	}
};

class User{
	// id, pw ,캐릭터를 저장할 수있는 창!최대 6개 까지만 
private:
	string pw;

public:
	string id;
	Character* list; //캐릭터를 담을 수있는 변수 => Character list[6];

	vector<User> v;
	//생성자를 이용해서 객체 생성!

};

  //데이터를 배열처럼 추가 할 수있는 것!



int main(){

	string idlist ="20001";
	string pwlist ="1111";

	User* u = new User; // user1 만들어지면 그 사람의 캐릭터 창에 
									// 워리어 객체를 추가한것!

	while(true){

		cout << " 1. 게임시작"<<endl;
		cout << " 2. 캐릭터 선택"<<endl;
		cout << " 3. 전체 출력 "<<endl;
		cout << " 4. 캐릭터 삭제"<<endl;
		cout << " 5. 종료"<< endl;

		int sel;
		cin >>sel;

		if(sel == 1){

		}else if(sel == 2){
			cout << " 캐릭터 추가"<<endl;
			cout << " 1. 전사"<<endl;
			cout << "2. 마법사  3. 궁수 "<<endl;
			cin >> sel;
			
			int count = 0;

			if(count == 0){
				u->list = new Character;
						
			}else{
				// 백터 복사 방식! 기존 데이터를 복사하는 개념!
				Character* temp = u->list;

				u->list = new Character[count +1];

				for(int i=0; i < count; i++){
					u->list[i] = temp[i];
				}
			}

			cout << "배열 사이즈 :"<< count <<endl;

			if(sel == 1){
				cout << "전사 생성"<<endl;
				string name; 
				cin >> name;

				Warrior* w1 = new Warrior;
				w1->id = name;							
				u ->list = w1; //user캐릭터 창으로 저장!
			}else if(sel == 2){

				cout << "마법사 생성"<<endl;
				string name; 
				cin >> name;

				Wizard* w1 = new Wizard;
				w1->id = name;							
				u ->list = w1; //user캐릭터 창으로 저장!


			}else if(sel == 3){
				cout << "궁수 생성"<<endl;
				string name; 
				cin >> name;

				Archer* w1 = new Archer;
				w1->id = name;							
				u ->list = w1; //user캐릭터 창으로 저장!
			}
			// 두번째 


			count = count +1; //배열의 메모리공간의 카운트를 증가!
		}
		else if(sel == 3){}
		else if(sel == 4){}
		else if(sel == 5){ break; }

	}

	return 0;
}