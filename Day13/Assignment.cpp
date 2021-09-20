#include <iostream>		
#include <string>
#include <vector>
using namespace std;

class User{
public:
	User(){}
	int num;
	string name;
	vector<int> scores;
};

class UserManager{
public:
	UserManager(){}
	vector<User*> userlist;	
};

void saveData(){
	int scoredata[6][2] = {
		{1001, 2},
		{1003, 21},
		{1002, 54},
		{1003, 39},
		{1001, 87},
		{1003, 9}
	};
}

// 클래스로 변경하고 생성자 
// 데이터 잘 저장해서 가지고 오기!

int main() {

	vector<User> vec;

	User userdata[3] = {{"김철수",1001} , {"이만수",1002} , {"김철민",1003}};

	//int nums[] = { 1001, 1002, 1003 };
	//string names[] = { "김철수" , "이만수" , "김철민" };
	int datasize = 3;

	UserManager* a = new UserManager;

	for(int i = 0; i < datasize; i++){
		a->userlist.push_back(new User);
		a->userlist.name = userdata[i].name;
		a->userlist.num = userdata[i].num;
	}


	saveData();

	// 위 데이터를 저장하는 함수를 만드시오.
	UserManager* um;
	// 메모리 해재~
	for(int i = 0; i < a->userlist.size(); i++){
		delete a->userlist[i];
	}
	delete[] a;

	return 0;
}