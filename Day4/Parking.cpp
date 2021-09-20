//파일명: Parking

// 주차관리하는 프로그램 
// 차번호 , 입차시간, 출차시간,결제요금

#include"Myheader.h"

class Parking_Management{

public:
	string car_number;
	int st_time;
	int end_time;
	int pay;
};

// 은행에서 계좌를 등록합니다.
// 계좌명,계좌번호,id,pw , 잔액

class Bank_Account{
// {  } 중괄호안에 있는 변수,함수들을 클래스의 멤버!
// 클래스 내부에 정의한 함수들은 호출될때 (자기 주소)가 자동으로 저장된다.

public://공개 
	string acc_name;
	string acc_number;

	void setMoney(int money){
		this->balance = money;
	}
	// setMoney함수는 외부에 있는 데이터를 비공개 부분으로 집어 넣겠다!
	int getMoney(){
		return this->balance;
	}
	// getMoney함수는 비공개 부분에 있는 잔액을 클래스 외부로 꺼내기!
    int balance;
private: //비공개
	string id;
	string pw;
	

};

void main(){
	// 차 한테 들어왔습니다.
	Parking_Management car1;

	car1.car_number = "11거1234";
	car1.st_time = 9;
	car1.pay = 2000; // 기본요금 
	car1.end_time = 0;

	//계좌 등록 ! 
	// 이서희, 1111 ,10000, id : love,  pw :love

	//클래스로 선언한 변수를 할당 (메모리공간 할당)

	Bank_Account acc1;
	acc1.acc_name = "이서희";
	acc1.acc_number = 1111;

	acc1.balance = 10000;


}