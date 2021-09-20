#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Info {
public:
	string name;
	int time;
};

class Rank {
public:
	Info user[3];
	void load() {}
	void save() {}
	void print_rank() {
		for (int i = 0; i < 3; i++) {
			cout << user[i].name << " " << user[i].time << endl;
		}
	}
	void check_rank(int result) {}
};

class Gugu {
public:
	Rank rank;

	void menu() {
		srand(time(NULL));

		bool run = true;
		while (run) {
			cout << "구구단 게임" << endl;
			cout << "1)게임" << endl;
			cout << "2)랭킹" << endl;
			cout << "3)종료" << endl;

			int sel = 0;
			cin >> sel;

			if (sel == 1) { play(); }
			else if (sel == 2) { rank.print_rank(); }
			else if (sel == 3) { run = !run; }
		}
	}

	void play() {
		time_t start = time(NULL);
		int count = 0;

		bool run = true;
		while (run) {
			cout << "시행횟수 : " << count << endl;
			int x = rand() % 8 + 2;
			int y = rand() % 9 + 1;

			int answer = x * y;
			cout << x << " X " << y << " = ";
			int my_answer = 0;
			cin >> my_answer;

			if (answer == my_answer) {
				cout << "정답" << endl;
				count += 1;
			}
			if (count == 5) {
				run = !run;
			}
		}

		time_t end = time(NULL);
		int result = end - start;
		cout << "기록 : " << result << endl;

		rank.check_rank(result);
	}
};

int main() {

	Gugu game;
	game.menu();

	return 0;
}