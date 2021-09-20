//파일명 Account

// 클래스명 첫글자 대문자
// Account
// Bank_Account

// 함수명 첫글자 무조건 소문자 , 두단어 이상으로 이루지면 두번째단어인
// 첫글자가 대문자 
// show()
// printShow()

#include<iostream>
#include<string>
using namespace std;

// 은행 계좌 클래스 상속 
// 체크 카드 
class Account{
private:
	int balance; //private생략이 가능하다.

public:
	int accountNumber;
	string accountName;

	// 기본생성자X
	Account(){}
	Account(int bal,int number,string name){
		this->balance = bal;
		this->accountNumber = number;
		this->accountName = name;
		cout <<" 계좌등록 완료!"<<endl;
	}
	// 은행계좌를 생성하면 출금,입금,계좌조회,잔액확인
	void deposit(int money){
		// 내 잔액에 저장
		this->balance += money;
		cout << "입금되었습니다. 잔액:"<<this->balance<<endl;
	}

	// 출금 
	int withdraw(int money){
		if(this->balance < money){
			cout << "잔액 부족!"<<endl;
			return 0;
		}else{
			this->balance -= money;
			cout << "정상출금 잔액:"<< this->balance <<endl;
			return money;
		}
	}
	// 잔액확인 
	int check(){
		return this->balance;
	}
};
class CheckCard :public Account{
	//  체크카드 번호 공개/ 비공개
	//  암호화 3자리 공개 / 비공개
	//  유효기간 공개 / 비공개
	//  체크카드 비밀번호 비공개 
private:
	int cardpw;  //숫자 4자리 

public:
	string cardNumber;    //카드번호 
	string cardValid;     //유효기간
	int cvc;			  // 암호화 

	// 상속의 구조에서 생성자를 생성하는 방법
	// 부모클래스는 자식클래스가 생성될때 먼저 생성 

	// checkccard() 호출하면 
	// account() 부모클래스가 만들어 질 때 생성자가 입력값을 받으면 
	// 자식이 : account(입력,입력,입력)
	// 매개변수를 넘겨주지 않으면 객체를 생성할 수 없다.

	// c++ 가장 중요한 것 특징 
	// 하나의 클래스에 여러개의 클래스를 동시에 상속할 수있다!
	// 다중상속!

	CheckCard(int b,int n,string name,int cardpw,string cardnumber,
		   string cardValid,int cvc): Account(b,n,name){

			   //this->balance = b;
			   //this->accountNumber = n;
			   //this->accountName = name;
			   this->cardpw = cardpw;
			   this->cardNumber = cardnumber;
			   this->cardValid = cardValid;
			   this->cvc = cvc;
	}


	void pay(int money){

		int res = this->withdraw(money);
		
		if(res == 0){
			cout << "카드 한도초과"<<endl;
		}
		// 1. 얼마결제 입력!
		// 2. account 안에 있는 출금기능을 사용!
		// 3. 그 결과를 리턴해서 0이면 카드한도초과! 출력
		//    통장에 잔액이 있을 경우 정상결제 출력!
	}
};
int main(){

	// 서희 
	// 은행에 계좌만 등록한 사람!
	Account a(100000,1111,"서희계좌");

	// 지희
	// 은행계좌도 등록하고 체크카드 발급한 사람!
	CheckCard b(200000,2222,"지희계좌",1234,"1111-1111-1111-1111"
		,"07/24",323);

	b.pay(150000);


	return 0;
}