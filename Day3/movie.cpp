
// 파일명: movie
// 영화예매 (자리예매하는 프로그램)
#include<iostream>  // cout ,cin 사용하기 위한 헤더파일
#include<string>    // 문자들에 대한 헤더파일
#include<unistd.h> 
#include<time.h>

using namespace std;

 /*메가 영화관에 오신걸 환영합니다.
 1. 회원가입
 2. 로그인
 3. 로그아웃
 4. 예매하기
 5. 예매취소
 0. 종료

 1. 회원가입 clinet 생성해서 데이터 저장
 2. 로그인 
 3. 로그아웃 */

 
struct  Client{
	string id;
    string pw;
};

struct Movie{
	
	int cnt; 
	Client * client;
	
};
 
void menu(){
		cout << "1.로그인" << endl;
		cout << "2.로그아웃" << endl;
		cout << "3.예매하기" <<endl;
		cout << "4.예매취소" << endl;
		cout << "5.종료" << endl; 
}

int main(void){

	Client user_list[10];

	for(int i=0; i < 10; i++){
		cout << i+1 <<"번째 id pw:" <<endl;
		cin >> user_list[i].id >> user_list[i].pw;
		system("pause"); 
	    system("cls");
	}

	int seat[10] = {0};

    int temp = 0;
	int log = -1;

	while(true){

		if(log == -1){
			cout << "로그인을 해주세요." << endl;
		}else{
			cout << "[" << user_list[log].id << "]님,환영합니다."<<endl;
		} 

		menu();
		int sel;
		cin >> sel;

		if(sel == 1){
		
			if(log == -1){
				cout << "[로그인] ID를 입력하세요: ";
				string id;    
				cin >> id; 

				cout << "[로그인] PW를 입력하세요: ";
				string pw;
				cin >> pw;
				

				bool check = false;
				for( int i=0; i < 10; i++){
					if(user_list[i].id == id && user_list[i].pw == pw){
						log = i;
						check = true;
						break;
					}
				}
				if(check == false){ 
					cout << "[로그인 실패] ID or PW를 확인해주세요."<<endl;
				}
			}
			system("pause"); 
	        system("cls");
		}
		else if(sel == 2){
			cout << "["<< user_list[log].id << "]님 로그아웃!"<<endl;
			log = -1;			
			system("pause"); 
	        system("cls");
		} 
		else if(sel == 3){
			cout << " 좌석을 예매하세요." << endl;
			for(int i = 0; i < 10; i++){
				if(seat[i] == 0){
					cout << "[O]";
				}
				else{
					cout << "[X]";
				}
			}
			cout << endl;
			cout << "좌석의 index를 입력하세요.";
			cin >> temp;

			if(seat[temp] == 0){
				cout << "정상적으로 예매되었습니다." << endl;
				seat[temp] = 1;
			}
			else{
				cout << "이미 예약된 자리입니다. 다시 예매하세요." << endl;
			}

			system("pause"); 
	        system("cls");

		}
		else if(sel == 4){
			cout << "취소하실 좌석의 index를 입력하세요." << endl;
			for(int i = 0; i < 10; i++){
				if(seat[i] == 0){
					cout << "[O]";
				}
				else{
					cout << "[X]";
				}
			}
			cout << endl;
			cout << "index: ";
			cin >> temp;

			if(seat[temp] == 0){
				cout << "잘못 선택하셨습니다." << endl;
			}
			else{
				cout << "정상적으로 예매가 취소되었습니다." << endl;
				seat[temp] = 0;
			}

			system("pause"); 
	        system("cls");

		}
		else if(sel == 5){
			break;
		}
		else{
			cout << "잘못 누르셨습니다." << endl;
			system("pause"); 
	        system("cls");
		}
	}

	return 0;
}