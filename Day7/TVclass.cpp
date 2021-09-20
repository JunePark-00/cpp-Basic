//파일명: TvClass

#include<iostream>
#include<string>

using namespace std;

// 상속구조 

class Tv{
public:
	int size;
	string name;

	//생성자 기본생성자 , 입력값을 받는 생성자 
	Tv(){ cout << "Tv 객체 생성 빈 데이터"<<endl;}

	Tv(int size,string str){
		this->size = size;
		this->name = str;
	}

	void print(){
		cout << "Tv 정보"<<endl;
		cout << "이름:"<< this->name <<endl;
		cout << "사이즈:" << this->size <<endl;
		cout << "====================="<<endl;
	}
};

class WideTv : public Tv{
public:
	bool wideOn;

	WideTv(int size,string str,bool wideOn){
		this->size = size;
		this->name = str;
		this->wideOn = wideOn;
		cout << "wideTv생성"<<endl;
	}
	void setWide(){
		this->wideOn = !wideOn; //not연산자 
							    // !거짓 -> 참
	}
};

class SmartTv :public Tv{

public:
	string ip; 

	SmartTv(string ip,int size,string str){
		this->ip = ip;
		this->size = size;
		this->name = str;
		cout << "스마트Tv객체 생성!"<<endl;
	}
};

class Pokemon{
public:
	string name;

	Pokemon(){ }
	Pokemon(string name){
		this->name = name;
	}
};
class Pikachu : public Pokemon{
public:
	string type;

	// 기본생성자는 명시하지 않았기 때문에 
	// 자식클래스인 피카츄는 기본생성을 할 수 없다.
	Pikachu(string name,string type){
		this->name = name;
		this->type = type;
	}
};

class Squirtle : public Pokemon{
public:
	string type;

	Squirtle(string name,string type){
		this->name = name;
		this->type = type;
	}
};
int main(){

	Pikachu p("피카츄","번개속성");

	// 객체 생성 
	// 스마트 Tv 삼성 50 

	SmartTv st("192.0.0.2",50,"삼성스마트Tv");

	// SmartTv 객체를 생성하면 상속받은 부모클래스의 객체를 
	// 먼저 생성하고 그걸 상속받아서 자식클래스의 객체 안으로
	// 집어넣어 사용할 수 있도록 한다.

	WideTv wt(60,"LG와이드Tv",false);

	// 실습 
	// 기본적으로 포켓몬 
	// 부모클래스는 Pokemon
	//    멤버 : string name;
	//    객체 생성할때 이름을 받는 생성자를 선언하세요
	//    기본생성자 같이 선언 하세요.

	// pikachu 클래스가 pokemon 클래스를 상속 
	// 피카츄 멤버 : string type저장 : 번개속성

	// Squirtle 클래스가 pokemon 클래스를 상속
	// 꼬부기 멤버 : string type 저장: 물속성 

	// 모든 출력!





	return 0;
}