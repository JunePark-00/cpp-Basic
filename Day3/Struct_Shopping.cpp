//파일명: Struct_Shopping
// 

#include<iostream> // cout ,cin 입출력
#include<string>   // 문자들을 저장하는 헤더파일
#include<unistd.h>
#include<time.h>

using namespace std;

struct Item{
	string name; //포도, 칸쵸,사과
};
struct Cart{
	int item;
	string id; 
};
struct User{
	string id; 
	string pw;

	Cart cart[100];		// 동적할당
};

void menu(){
		cout << "1.로그인" << endl;
		cout << "2.로그아웃" << endl;
		cout << "3.쇼핑" <<endl;
		cout << "4.내카트확인" << endl;
		cout << "5.내카트삭제" << endl; 
}


int main(void){

	User user_list[3]; // 2001 2002 2003 
	Item item_list[3]; // 포도 사과 칸쵸

	item_list[0].name = "칸쵸";
	item_list[1].name = "포도";
	item_list[2].name = "사과";

	for(int i=0; i < 3; i++){
		cout << i+1 <<"번째 id pw:" <<endl;
		cin >> user_list[i].id >> user_list[i].pw;
	}

	int count = 0; // 장바구니 개수를 카운트
	int log = -1;  // 인덱스

	while(true){

		if(log == -1){
			cout << "로그인을 해주세요." << endl;
		}else{
			cout << "[" << user_list[log].id << "]님,환영합니다."<<endl;
		}  //구조체 배열을 선언 log 인덱스 그 안에 있는 id값을 가지고와야된다.!

		menu();
		int sel;
		cin >> sel;

		if(sel == 1){
		
			if(log == -1){
				cout << "[로그인]아이디를 입력하세요>>";
				string id;    
				cin >> id; // 2004

				cout << "[로그인]pw를 입력하세요>>";
				string pw;
				cin >> pw;
				

				bool check = false;
				// 입력받은 id user_list 있는지 확인
				for( int i=0; i <3; i++){
					if(user_list[i].id == id && user_list[i].pw == pw){
						log = i;
						check = true;
						break;
					}
				}
				if(check == false){ // 예외적인상황 메시지!
					cout << "id or pw를 확인해주세요."<<endl;
				}
			}		
		}
		else if(sel ==2){
			// 로그 아웃 
			cout << "["<< user_list[log].id << "]님 로그아웃!"<<endl;
			log = -1;			
		} 
		else if(sel ==3){ //쇼핑하기!
			
			cout << "[1] 칸쵸" <<endl;
			cout << "[2] 포도" <<endl;
			cout << "[3] 사과" <<endl;

			int sel;
			cin >> sel;

			// 2001번 고객님의 카트안에 첫번째 물건!
			// count 0이기때문에 
			user_list[log].cart[count].id = item_list[sel-1].name;
			user_list[log].cart[count].item = sel-1;

			count +=1; 		
		}
		else if(sel ==4){ 
			// 카트 확인
			cout << "장바구니 개수:"<< count << endl;

			for(int i=0; i< count; i++){
				cout << "[" << user_list[log].cart[i].item<<"]"
					 << user_list[log].cart[i].id << endl;
			}
			cout << endl;
		}
		else if(sel ==5){ 
			cout << "삭제할 품목의 번호를 입력하세요>";
			int num;
			cin >> num;

			int del_idx=0;

			// 삭제할 인덱스 번호를 찾아서 del_idx 저장!
			for(int i=0; i < count; i++){
				if(user_list[log].cart[i].item == num-1){
					del_idx = i;					
				}
			}

			// 삭제하는 데이터 없애고 뒤에 있는 데이터를 
			// 대입하는 과정

			for(int i=del_idx; i<count; i++){
				user_list[log].cart[i].id = user_list[log].cart[i+1].id;
				user_list[log].cart[i].item = user_list[log].cart[i+1].item;
			}
			count -=1;
		}
	}

	return 0;
}