#include<iostream>
#include<string>
using namespace std;

int main(void){

	// 반복문
	// 1부터 50까지 출력 
	/*
	for(int i =0; i <=50; i++){
		cout << i << endl;
	}
	
	// 1부터 100까지 짝수만 출력
	
	for(int i=1; i < 101; i++){
				
		if(i%2 == 0){ 
			cout << "짝수:" << i << endl;
		}
	}
	
	// 1~50사이의 숫자 중 
	// 하나를 입력 받아서 
	// 3이나 6이나 9가 1개 있으면 "짝" 출력
	// 3이나 6이나 9가 2개 있으면 "짝짝" 출력 
	// or 
	
	// while문 사용하는 방법도 똑같다.
	// continue , break 방법도 똑같다.
	
	// 배열 
	// 사용하는 방법 똑같다.
	// 배열 선언하는 방법
	// 자료형 배열이름[길이];

	// 국어 수학 영어 점수 3개를 배열에 저장하고 그 합을 sum 변수에 저장
	int sum = 0; // 합을 저장하는 변수
	int avg = 0;
	int k = 0;
				  // 메모리는 1byte 당으로 주소값이 있습니다.
				  // 4byte 주소가 총 4개 그 대표되는 주소가 가장 낮은 주소값을 가진 대표주소!
	int grade[3]; // 길이가 3인 배열 선언
				  // 정수를 저장하는 변수 3개로 묶였다.

	grade[0] = 85;
	grade[1] = 90;
	grade[2] = 80;

	// cin으로 배열을 저장 
	
	cout << "국어:";				cin >> grade[0];
	cout << "영어:";				cin >> grade[1];
	cout << "수학:";				cin >> grade[2];

	for(int i=0; i < 3; i++){
		sum = sum + grade[i];  // += 더하고 왼쪽변수에 저장
		cout << grade[i]<<endl;
	}

	cout << "최종 합:" << sum << endl;
	
	// cin 여러개를 한번에 입력받을 때 
	int num,num2;

	cin>> num >> num2;

	cout << num << ":" << num2 << endl;

	*/

	// 배열 선언
	int arr[5] = {10,20,30,40,50};
	int temp[5] = {0,0,0,0,0};

	// arr배열에 값 중에서 4의 배수만 temp 배열에 차례대로 저장후 출력

	int count = 0;			// count변수는 4의 배수 개수 카운트해서 temp배열의 index로 
							// 사용할 예정
	for(int i = 0; i <5; i++){

		if(arr[i]%4 == 0){			//4의 배수가 맞다면 
			temp[count] = arr[i];	// temp배열의 0번째 인덱스에 arr[0]을 저장해라!
			count = count +1;		// count 를 하나씩 올려준다!
		}		
	}
	// 출력 
	for(int i = 0; i < 5; i++){
		cout << temp[i] << " ";
	}

	return 0;
}