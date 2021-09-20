//파일명: Game

#include<iostream>
#include<string>
#include<ctime>


using namespace std;

//구구단 게임을 시작할때 
// 5번게임하는 와중 시간을 기준으로 랭킹을 저장

class Info{

public:
	string name;
	int time;
};

class Rank{
public:
	string file_name;
	Info user[3];

	Rank(){
		file_name = "ranking.txt";
	}
	void set_dummy() {
		for (int i = 0; i < 3; i++) {
			user[i].name = "";
			user[i].time = 1000;
		}
	}

	void load(string file_name){// 불러오기
	FILE* f = fopen(file_name.c_str(), "rt");
		if (f == NULL) {
			set_dummy();
			save(file_name);
		}
		else {
			for (int i = 0; i < 3; i++) {
				char temp[100];
				fscanf(f, "%s %d\n", temp, &user[i].time);
				user[i].name = temp;
			}
			fclose(f);
		}
	} 
	void save(string file_name){
		FILE* f = fopen(file_name.c_str(), "wt");
		if (f == NULL) return;
		for (int i = 0; i < 3; i++) {
			fprintf(f, "%s %d\n", user[i].name.c_str(), user[i].time);
		}
		fclose(f);
	} // 저장

	// 순위 체크하는 함수 
	// play하는 함수 안에서 초시간을 입력 받아서 
	// 초시간이 가장 작은 데이터가 1순위 
	// 오름차순으로 데이터를 정리 
	// 정리의 기준은 초시간!
	void check_rank(int time){
		// if (time > user[2].time) return;		
		// 현재게임한 user의 데이터를 먼저 저장
		// 현재 user 3명밖에 없다. 저장할 수있는 공간 3개밖에 없다
		
		// 최소값구하는 문제
		for(int i = 0; i < 3; i++){
			for(int j = 0; i < 2-i; i++){
				if(user[j].time > user[j+1].time){
					int temp = user[j].time;
					user[j].time = user[j+1].time;
					user[j+1].time = temp;

					string temp_name = user[j].name;
					user[j].name = user[j+1].name;
					user[j+1].name = temp_name;
				}
			}
		}
		// 3등의 시간보다 크면 굳이 비교할 필요가 없다
		// 왜? 순위에 못들었으니 그냥 함수 종료!
		//순위에 대한 데이터를 저장하는 함수!
		save(file_name);
	}

	void print_rank(){ //단순 출력!
		for(int i=0; i<3; i++){
			cout << user[i].name <<" " << user[i].time <<endl;
		}
	}

	
};

class Gugu{

public:
	Rank rank;
	string name;

	void play(){
		// 게임이 시작되면 시간 카운트 
		// time_t 1970년 1월 1일 0시0분0초로부터 초단위 카운트
		
		time_t start = time(NULL);
		int count = 0;  //5번 게임을 실행
        cout << "이름을 입력하세요: ";
		cin >> rank.user[2].name;

		while(true){
			// 랜덤값 저장해서 출력해서 입력받기 
			// 2 * 3 = 
			int x = rand() % 8 + 2;
			int y = rand() % 9 + 1;

			cout << x << "*"<<y <<"=";

			int answer = x * y;
			int my_answer;
			cin >> my_answer;
			
			if(answer == my_answer){
				cout << "정답!!"<<endl;
				count++;
			}
			else{
				cout << "땡!!" << endl;
			}

			if(count == 5){
				cout << "5번 완료!"<< endl;
				break;
			}
		}

		time_t end = time(NULL);
		int result = end - start;

		cout << "기록:"<< result <<endl;

		rank.user[2].time = result;
		rank.check_rank(result);
		/*
		clock_t  double형태의 ms 단위로 값을 리턴

		clock_t start,end;
		start = clock();

		프로그램을 조금 지연시키는 Sleep(500)

		end = clock();
		*/
	}
	void menu(){
		rank.load(rank.file_name);

		srand(time(NULL)); //숫자를 랜덤적으로 초기화

		while(true){
			cout << "구구단 게임"<<endl;
			cout << "1)게임"<<endl;
			cout << "2)랭킹"<<endl;
			cout << "3)종료"<<endl;

			int sel = 0;
			cin >> sel;

			if(sel == 1){
				play();
			}else if(sel == 2){
				rank.print_rank();
			}
			else if(sel == 3){
				break; //게임끝!
			}
		}
	}
};

int main(){

	Gugu game;
	game.menu();

	// 프로그램들 마다 자료를 저장하는 자료구조!
	// STL (standard template Library)

	// 데이터를 저장할 때 프로그램에서 이미 만들어놓은 규칙!
	// 타입지정

	return 0;
}
