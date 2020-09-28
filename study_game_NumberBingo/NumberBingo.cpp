#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

int main() {
	/*
	빙고게임
	1~25까지의 숫자가 있고 이 숫자를 골고루 섞어서 5X5로 출력한다
	플레이어는 1~25의 숫자를 입력하여야한다.
	0을 입력 받으면 종료한다

	숫자를 입력 받았으면 숫자 목록중 입력 받은 숫자를 찾아서 *로 만들어준다
	숫자를 *로 만든 후에 빙고 줄수를 체크한다. 5X5이기 때문에 가로5줄 세로5줄
	대각선 2줄이 나올 수 있다 빙고줄이 몇줄인지 체크해서 화면에 보여준다.
	5줄 이상일 경우 게임을 종료한다
	*/

	//필요조건 : 25칸의 랜덤한 숫자가 저장 된 배열ok, 줄이 완성된 걸 체크하는 변수 Line ok, 입력받은 숫자를 *로 변환
	//예외조건 : 1~25사이의 숫자만 입력ok, 0을 입력하면 종료ok
	
	int Bingo[25], Input_Bingo[25] = {0};
	int Temp, Index1, Index2;
	int Line = 0;
	int Input;

	srand((unsigned int)time(0));

	//배열 Bingo에 1~25의 숫자를 저장
	for (int i = 0; i < 25; i++) {
		Bingo[i] = i + 1;
	}

	//숫자를 랜덤하게 100번 섞음
	for (int i = 0; i < 100; i++) {
		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = Bingo[Index1];
		Bingo[Index1] = Bingo[Index2];
		Bingo[Index2] = Temp;
	}

	//계속해서 돌아갈 게임
	while (1) {
		system("cls");

	/*
		//배열 Bingo를 5X5 모양으로 출력
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << Bingo[i * 5 + j] << "\t";
			}
			cout << "" << endl;
		}
		cout << "" << endl;
	*/
		cout <<"\t"<<"    ★빙고게임★" << endl;

		//저장된 유저의 숫자를 출력(단 0으로 모두 저장해두고 0이면 *을 출력, 숫자가 저장되면 숫자 출력)
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Input_Bingo[i * 5 + j] == 0)
					cout << "*" << '\t';
				else
					cout << Input_Bingo[i * 5 + j] << '\t';
			}
			cout << "" << endl;
		}

		//빙고가 5개가 넘어가면 게임을 종료
		if (Line >= 5) {
			cout << "축하합니다! 5줄의 빙고를 완성하셨습니다!" << endl;
			break;
		}

		//맞춘 빙고수를 출력
		cout << endl << "맞춘 빙고 수 : " << Line << " (5줄 맞출시 승리)" << endl;

		//한 루프에서만 Line을 체크해줌
		Line = 0;

		//숫자를 입력 받음(1~25의 숫자만)
		cout << "1~25의 숫자를 입력해주세요(0을 입력하면 게임 종료) : ";
		cin >> Input;

		//예외조건
		if (0 > Input || Input > 25) {
			cout << "잘못된 범위입니다. 다시 입력해주세요"<<endl;
			continue;
		}
		else if (Input == 0) {
			cout << "게임을 종료하셨습니다" << endl;
			break;
		}

		//입력받은 숫자(Input_Bingo[i]와Bingo[25]의 위치를 비교해서 같은 위치에 있는걸 Input_Bingo[i]에 저장)
		for (int i = 0; i < 25; i++) {
			if (Bingo[i] == Input) {
				Input_Bingo[i] = Input;
			}
		}

		//빙고 체크
		//가로줄 체크
		for (int i = 0; i < 5; i++) {
			if (Input_Bingo[i * 5] > 0 && Input_Bingo[i * 5 + 1] > 0 && Input_Bingo[i * 5 + 2] > 0 &&
				Input_Bingo[i * 5 + 3] > 0 && Input_Bingo[i * 5 + 4] > 0) {
				Line++;
			}
		}
		//세로줄 체크
		for (int i = 0; i < 5; i++) {
			if (Input_Bingo[i] > 0 && Input_Bingo[5 * 1 + i] > 0 && Input_Bingo[5 * 2 + i] > 0 &&
				Input_Bingo[5 * 3 + i] > 0 && Input_Bingo[5 * 4 + i] > 0) {
				Line++;
			}
		}
		//대각선 체크
		if (Input_Bingo[0] > 0 && Input_Bingo[6] > 0 && Input_Bingo[12] > 0 &&
			Input_Bingo[18] > 0 && Input_Bingo[24] > 0) {
			Line++;
		}
		if (Input_Bingo[4] > 0 && Input_Bingo[8] > 0 && Input_Bingo[12] > 0 &&
			Input_Bingo[16] > 0 && Input_Bingo[20] > 0) {
			Line++;
		}
	}
	while (1);
}
