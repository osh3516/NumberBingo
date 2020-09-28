#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;

int main() {
	/*
	�������
	1~25������ ���ڰ� �ְ� �� ���ڸ� ���� ��� 5X5�� ����Ѵ�
	�÷��̾�� 1~25�� ���ڸ� �Է��Ͽ����Ѵ�.
	0�� �Է� ������ �����Ѵ�

	���ڸ� �Է� �޾����� ���� ����� �Է� ���� ���ڸ� ã�Ƽ� *�� ������ش�
	���ڸ� *�� ���� �Ŀ� ���� �ټ��� üũ�Ѵ�. 5X5�̱� ������ ����5�� ����5��
	�밢�� 2���� ���� �� �ִ� �������� �������� üũ�ؼ� ȭ�鿡 �����ش�.
	5�� �̻��� ��� ������ �����Ѵ�
	*/

	//�ʿ����� : 25ĭ�� ������ ���ڰ� ���� �� �迭ok, ���� �ϼ��� �� üũ�ϴ� ���� Line ok, �Է¹��� ���ڸ� *�� ��ȯ
	//�������� : 1~25������ ���ڸ� �Է�ok, 0�� �Է��ϸ� ����ok
	
	int Bingo[25], Input_Bingo[25] = {0};
	int Temp, Index1, Index2;
	int Line = 0;
	int Input;

	srand((unsigned int)time(0));

	//�迭 Bingo�� 1~25�� ���ڸ� ����
	for (int i = 0; i < 25; i++) {
		Bingo[i] = i + 1;
	}

	//���ڸ� �����ϰ� 100�� ����
	for (int i = 0; i < 100; i++) {
		Index1 = rand() % 25;
		Index2 = rand() % 25;

		Temp = Bingo[Index1];
		Bingo[Index1] = Bingo[Index2];
		Bingo[Index2] = Temp;
	}

	//����ؼ� ���ư� ����
	while (1) {
		system("cls");

	/*
		//�迭 Bingo�� 5X5 ������� ���
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << Bingo[i * 5 + j] << "\t";
			}
			cout << "" << endl;
		}
		cout << "" << endl;
	*/
		cout <<"\t"<<"    �ں�����ӡ�" << endl;

		//����� ������ ���ڸ� ���(�� 0���� ��� �����صΰ� 0�̸� *�� ���, ���ڰ� ����Ǹ� ���� ���)
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (Input_Bingo[i * 5 + j] == 0)
					cout << "*" << '\t';
				else
					cout << Input_Bingo[i * 5 + j] << '\t';
			}
			cout << "" << endl;
		}

		//���� 5���� �Ѿ�� ������ ����
		if (Line >= 5) {
			cout << "�����մϴ�! 5���� ���� �ϼ��ϼ̽��ϴ�!" << endl;
			break;
		}

		//���� ������� ���
		cout << endl << "���� ���� �� : " << Line << " (5�� ����� �¸�)" << endl;

		//�� ���������� Line�� üũ����
		Line = 0;

		//���ڸ� �Է� ����(1~25�� ���ڸ�)
		cout << "1~25�� ���ڸ� �Է����ּ���(0�� �Է��ϸ� ���� ����) : ";
		cin >> Input;

		//��������
		if (0 > Input || Input > 25) {
			cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���"<<endl;
			continue;
		}
		else if (Input == 0) {
			cout << "������ �����ϼ̽��ϴ�" << endl;
			break;
		}

		//�Է¹��� ����(Input_Bingo[i]��Bingo[25]�� ��ġ�� ���ؼ� ���� ��ġ�� �ִ°� Input_Bingo[i]�� ����)
		for (int i = 0; i < 25; i++) {
			if (Bingo[i] == Input) {
				Input_Bingo[i] = Input;
			}
		}

		//���� üũ
		//������ üũ
		for (int i = 0; i < 5; i++) {
			if (Input_Bingo[i * 5] > 0 && Input_Bingo[i * 5 + 1] > 0 && Input_Bingo[i * 5 + 2] > 0 &&
				Input_Bingo[i * 5 + 3] > 0 && Input_Bingo[i * 5 + 4] > 0) {
				Line++;
			}
		}
		//������ üũ
		for (int i = 0; i < 5; i++) {
			if (Input_Bingo[i] > 0 && Input_Bingo[5 * 1 + i] > 0 && Input_Bingo[5 * 2 + i] > 0 &&
				Input_Bingo[5 * 3 + i] > 0 && Input_Bingo[5 * 4 + i] > 0) {
				Line++;
			}
		}
		//�밢�� üũ
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
