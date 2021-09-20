//파일명: shopping

#include<iostream>  // cout ,cin 사용하기 위한 헤더파일
#include<string>    // 문자들에 대한 헤더파일

using namespace std;

//구조체변경
// 구조체 안에는 멤버 
typedef struct shoppoing{
	string member;
}SP;

// user구조체를 관리하는 배열을 선언해서 
// 구조체 생성하고 배열에 저장!

// user
// 로그인 id
//        pw 
typedef struct user{
	string id;
	string pw;
}USER;

// cart 구조체
// item 번호
// string id 상품명 저장
typedef struct cart{
	string names;
	string id;
	int item;
}CART;

int main(){

	USER user_list[3] = {" "};
	user_list[0].id = "2001";
	user_list[1].id = "2002";
	user_list[2].id = "2003";

	user_list[0].pw = "0000";
	user_list[1].pw = "0000";
	user_list[2].pw = "0000";

	CART names_list[3] = {"apple","graph","kancho"};

	CART cart[100];

	return 0;
}

/*int main(){

	// 로그인정보를 userlist 3개 정도 저장
	int user_list[3] = {2001,2002,2003};

	// 로그인 로그아웃을 확인하는 변수
	// -1 로그아웃 된 상태 1 로그인상태
	// 로그인 하고 로그인 아이디로 인사말 표시할경우 log값 변경
	int log = -1;

	// 물건 사면 담는카드 
	int cart[100][2] ={0}; // 2차원배열전체를 0으로 초기화!

	string item_list[3] = {"사과","포도","칸쵸"};
	// 물품의 개수를 카운트하는 변수
	int count = 0;

	while(true){

		if(log == -1){
			cout << "로그인을 해주세요." << endl;
		}else{
			cout << "["<< user_list[log] << "]님,환영합니다."<<endl;
		}

		cout << "1.로그인" << endl;
		cout << "2.로그아웃" << endl;
		cout << "3.쇼핑" <<endl;
		cout << "4.내카트확인" << endl;
		cout << "5.내카트삭제" << endl; 

		int sel;
		cin >> sel;

		if(sel == 1){
		
			if(log == -1){
				cout << "[로그인]아이디를 입력하세요>>";
				int id;
				cin >> id; // 2004

				bool check = false;
				// 입력받은 id user_list 있는지 확인
				for( int i=0; i <3; i++){
					if(user_list[i] == id){
						log = i;
						check = true;
						break;
					}
				}
				if(check == false){ // 예외적인상황 메시지!
					cout << "아이디를 확인해주세요."<<endl;
				}
			}		
		}
		else if(sel ==2){
			// 로그 아웃 
			cout << "["<< user_list[log] << "]님 로그아웃!"<<endl;
			log = -1;			
		} 
		else if(sel ==3){ //쇼핑하기!
			
			cout << "[1] 사과" <<endl;
			cout << "[2] 포도" <<endl;
			cout << "[3] 칸쵸" <<endl;

			int sel;
			cin >> sel;

			// 카트에 물건을 저장
			// 물건의 번호 
			cart[count][0] = count;  
			cart[count][1] = sel -1; //실제물건이 저장된 string배열의
									 // index저장!

			count +=1; 		
		}
		else if(sel ==4){ 
			// 카트 확인
			for(int i=0; i< count; i++){
				cout << item_list[cart[i][1]] <<endl;
			}
			cout << endl;
		}
		else if(sel ==5){ }
	}
	return 0;
}
*/