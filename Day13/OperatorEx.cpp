//파일명: OperatorEx

#include<iostream>
#include<string>
using namespace std;

class A{

	int i;
	int y;

public:
	//생성자 오버로딩 
	A(){cout << "기본생성자"<<endl;}
	
	A(int i){ this->i = i; }
	
	A(int i , int y){
		this->i = i;
		this->y = y;
	}
};

class Point{
	int x,y;

public:
	Point(int x,int y){
		this->x = x;
		this->y = y;
	}
	void print(){
		cout <<"X: "<< this->x << "Y:"<<this->y <<endl;
	}

	//객체 끼리 더하는 연산자를 사용할 수있다.
	Point operator +(Point& p){
		int x1 = this->x + p.x;
		int y1 = this->y + p.y;

		return Point(x1,y1);
	}

	Point operator -(Point& p){
		int x1 = this->x - p.x;
		int y1 = this->y - p.y;

		return Point(x1,y1);
	}

	bool operator ==(Point& p){
		bool res = this->x == p.x  && this->y == p.y;
		// cout << res;
		return res;
	}

	// 연산한 값이 double형태로 변환하고 싶을때 
	// 객체끼리 연산한 데이터가 int 형태로 값을 반환하고 싶을때 

	operator double() const{
		return double(x) / double(y);
	}

	//자바 toString
	ostream& operator <<(ostream& os,const Point& p){
		os << p.x << "," <<p.y;
		return os;
	}
};
int main(){
	// 연산자 오버로딩
	// 클래스 안에 있는 멤버들끼리 더하거나 비교할때 사용하는 연산자 오버로딩

	// 기존에 제공하는 연산자를 재정의하여 사용자 정의 클래스로 사용
	
	// string 클래스 안에 + 연산자 오버로딩 되어있다
	// == 연산자 오버로딩!


	Point p(10,10);
	double db = p;

	int a=10;
	int b = 10;
	double s = (double)a/b;

	Point p1(2,2);
	Point p2(1,1);

	Point p3 = p1 + p2;
			// p1.operator +(p2)
	p3.print();

	cout << p3;

	Point p4 = p1 - p2;
	p4.print();
		
	p1 == p2;

	return 0;
}