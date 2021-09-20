//파일명: Moive

// 온라인으로 코딩을 할 수있는 사이트 
// https://www.tutorialspoint.com/codingground.htm

#include<iostream>
#include<string>  // cstring c++에서만 사용하는 string 

using namespace std;

//영화좌석 예매하는 프로그램 
class Megabox{
public:
	int seat[10];
	string id[10];

	void init(){
		//좌석 초기화를 진행 할 것!
		// 인덱스번호 좌석을 선택하면 그 안에 데이터가 0이면 빈좌석
		// 예매진행

		// 인덱스번호 선택 했는데 1로 데이터가 있으면 예매가 된 상태! 
		for(int i=0; i < 10; i++){
			seat[i] = 0;
			id[i] ="";
		}
	}
	// 로그인 확인하는 함수 
	int login(string* p,int count,int log){
		cout << "[로그인]id를 입력하세요>";
		string my_id; // 현재 입력하는 문자를 저장하는 변수 
		cin >> my_id;

		bool check = false;  // 혹시 로그인아이디가 없을 경우 처리하는 구문

		for(int i=0; i<count; i++){
			if(my_id == p[i]){
				check = true;
				log = i;
			}
		}
		if(check == false){
			cout << "id를 확인해주세요"<<endl;
		}
		
		return log;
	}

	// 좌석을 출력하는 함수!
	void print_seat(){
		for(int i=0; i < 10; i++){
			if(seat[i] == 0){
				cout << "[ ]";
			}else{
				cout << "[" << id[i]<<"]";
			}
		}
	}

	void ticketing(string id){
		// 예매하기 위해서는 좌석을 먼저 출력 
		print_seat();

		cout << " 예매할 좌석을 인덱스번호로 선택:(0~9):";
		int choice;  
		cin >> choice;

		if(seat[choice] == 0){
			this->seat[choice] = 1;
			this->id[choice] = id;
		
		}else{
			cout << "이미 예약된 좌석입니다"<<endl;
		}
	}
	void check_ticket(string id){
		// 내가 예매한 자리를 확인
		for(int i=0; i<10; i++){
			if(this->id[i] == id){
				cout << i << "번째 좌석 예매"<<endl;
			}
		}
	}	
};


int main(void){

	string id[3] = {"aaa","bbb","ccc"};
	int log = -1;

	Megabox mbox; // 클래스 객체를 생성하는 것!
	mbox.init();

	while(true){

		if(log == -1){
			cout << "로그인을 하세요."<< endl;
		}else{
			cout << "["<<id[log] <<"] 로그인"<<endl;
		}

		cout << "1.로그인"<<endl;
		cout << "2.로그아웃" <<endl;
		cout << "3.예매" <<endl;
		cout << "4.예매확인" <<endl;
		cout << "5.종료" <<endl;

		int sel;
		cin >> sel;

		if(sel == 1){
			log = mbox.login(id,3,log);
		}
		else if(sel ==2){  log = -1;  cout <<"로그아웃"<< endl;   }
		else if(sel ==3){

			// 로그인이 안된 상태는 예약할 수X
			if(log == -1){
				continue;
			}
			mbox.ticketing(id[log]);
		}
		else if(sel ==4){
			if(log == -1){
					continue;
			}
			mbox.check_ticket(id[log]);
		}
		else if(sel ==5){
			cout << "프로그램 종료"<< endl;
			break;
		}
	}

	return 0;
}