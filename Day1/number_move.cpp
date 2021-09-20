#include <iostream>
#include <unistd.h>

using namespace std;

// 숫자이동 게임

int main(){
	
	int map[8] = {0};
	
	int player = 4;			// 캐릭터의 위치
	map[player] = 8;		// 캐릭터 배치

	bool run= true;
	while(run){
		for(int i = 0; i < 8; i++){
			cout << map[i] << " ";
		}
		cout << endl;

		int dir = 0;
		cout << "좌(1) 우(2) 입력 : ";
		cin >> dir;

		if(dir == 1){
			if(player - 1 >= 0){
				map[player] = 0;
				player -= 1;
				map[player] = 8;
			}
		}
		else if(dir == 2){
			if(player + 1 < 8){
				map[player] = 0;
				player += 1;
				map[player] = 8;
			}
		}
			
		sleep(300);				// 0.3초(밀리세컨드 단위) 멈추기
		system("cls");			// 화면 지우기
	}
	
	return 0;
}



