//randomized challenge-response 系統
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

void random(int num[]);                             //隨機生成數字
void input(int pin,const int num[]);                //使用者輸入
int compare(int pin, const int num[], int nput);    //確認密碼是否正確

int main(void) {
	int pin = 12345;                                //正確密碼
	int num[10];                                    //隨機數字陣列
	srand(time(NULL));                              //使每次隨機結果不同
	random(num);                                    //進行隨機
	cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;     //輸出結果至螢幕
	cout << "NUM: ";
	for (int i = 0; i < 10; i++) {
		if (i < 9) {
			cout << num[i] << " ";
		}
		else {
			cout << num[i] << endl;
		}
	}
	input(pin, num);                     //使用者輸入

	system("pause");
	return(0);
}

void random(int num[]) {                 //隨機10個1~3的數字對應0~9
	for (int i = 0; i < 10; i++) {
		num[i] = (rand() % 3) + 1;
	}
}

void input(int pin,const int num[]) {    //輸入對應至NUM的五位數字當密碼
	int input;
	cout << "Use the above NUM to enter your password (five digits) >> ";
	cin >> input;
	if (compare(pin, num, input)) {      //進行比對&顯示結果
		cout << "Correct input." << endl;
	}
	else {
		cout << "Wrong input." << endl;
	}
}

int compare(int pin, const int num[], int input) {    //比對輸入是否為正確密碼
	int count = 0;                                    //正確位數計數器
	for (int i = 4; i >= 0; i--) {                    //位數進行一一比對
		for (int j = 0; j < 10; j++) {
			if ((input / int(pow(10, i)))%10 == num[j] && j == int((pin / pow(10, i)))%10) {
				count++;
				break;
			}
		}
	}
	if (count == 5) {                                 //每位皆正確則回傳true,否則false
		return(1);
	}
	else {
		return(0);
	}
}