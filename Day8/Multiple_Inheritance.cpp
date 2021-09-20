//파일명 : Multiple_Inheritance

#include<iostream>
#include<string>

using namespace std;

// 카드 
// 신용카드, 체크카드 
// 교통카드,영화할인,놀이동산 할인 , 주유

class Card{

private:
	int pw;

public:
	string card_number;

	Card(int pw,string number){
		this->pw = pw;
		this->card_number = number;
	}
	void pay(){}
};

//카드는 부모클래스 신용카드 자식클래스 
class Credit_Card : public Card{
public:
	Credit_Card(int pw,string number):Card(pw,number){
		// 부모클래스의 생성자가 기본생성자인데 입력값을 받는 생성자로 객체를 만들기때문에
		// 에러!
	}
};

class Check_Card : public Card{
public:
	Check_Card(int pw,string number):Card(pw,number){ }
};

class Transportation{
public:
	Transportation(){  	cout << "교통기능"<<endl;}
};

class Movie{
public:
	Movie(){  cout << "영화기능"<<endl; }
};

class Gas{
public:
	Gas(){ cout << "주유기능"<<endl; }
};

class Shopping{
public:
	Shopping() {   cout << "쇼핑기능"<<endl; }
};

// 삼성카드에서 신용카드를 발급 
// 기능 영화 , 쇼핑, 교통카드 기능! 발급!

class Samsung_Card : public Credit_Card,public Movie,public Shopping,public Transportation{

public:
	Samsung_Card(int pw,string number):Credit_Card(pw,number)
	{  cout << "삼성카드발급완료!"<<endl; } 
};

// 다중상속을 하더라도 부모클래스가 입력값을 받아서 객체를 생성하면 
// 자식클래스가 받아서 부모한테 넘겨줘야된다.

// 롯데카드 체크카드
// 주유기능, 교통카드 기능
// 롯데카드 pw 2583 카드 번호 "2222-2222"
// 롯데카드 발급완료! 

class Lotte_Card : public Check_Card,public Gas,public Transportation{

public:
	Lotte_Card(int pw,string number):Check_Card(pw,number){
		cout << "롯데카드 발급완료!"<<endl;
	}
};

class KaKao_Bank : public Check_Card,public Credit_Card{

};

int main(){

	// 다중상속 
	// 각각의 부모클래스의 생성자가 충돌! 
	// 여러개의 부모클래스는 동일한 생성자를 가질 수있다.




	
	// 삼성카드 발급  c++ 엑세스할 수없습니다. 접근제어자! (비공개)
	// 클래스와 구조체의 차이? 상속 
	Samsung_Card s1(1234,"1111-1111");

	Lotte_Card l1(2583,"2222-2222");

	// 다형성 
	// 객체 안에 상속받은 부모클래스들의 명으로 객체를 참조할 수있다.
	
	//상속이 일어나도 부모클래스에 private멤버는 상속 X 접근자체도 X
	//Credit_Card c1;
	//c1.pw = 1234;



	// 다중상속 : 하나의 클래스에 여러개의 클래스를 동시에 상속 받는 기능!
	// class 파생클래스(자식클래스) : public 부모클래스,public 부모클래스2,
	// , 쉼표를 사용해서 여러개의 클래스를 상속받는다!






	return 0;
}