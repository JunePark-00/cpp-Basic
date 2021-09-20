//파일명: employee 클래스안에 int get(){} 함수 오버라이딩해서
//  정규직과 아르바이트 함수 실행시 급여 출력!



class Employee{

//private:
//	int number;

public: 
	string name; // 인스턴스변수 or 멤버 변수  각각 객체안에 생성
	static int number;   // static변수 객체안에 X 

	Employee(int n,string name){
		number++;
		this->name = name;
		cout << number << "번째 사원번호발급"<<endl;
	}
	int get(){} 
};

class Part_Time: public Employee{

	int time;
	int money;

public:
	Part_Time(int n,string name):Employee(n,name){}

	int get(){
		cout << "월급:"<< time * money <<endl;
	}
};




