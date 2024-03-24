//24時制轉12時制工具
#include<iostream>
using namespace std;

void Input_time(void);                               //輸入時間
void conversion(char AM, int hours, int minutes);    //時間轉換(A.M.)
void conversion(int hours, int minutes, char PM);    //時間轉換(P.M.)
void output_time(int hours, int minutes, char time);    //輸出時間

int main(void) {
	char again;          //用於確認是否再來一遍
	do {
		Input_time();    //呼叫函式輸入
		cout << "Do you want to input again? Input Y or y(Yes), or N or n(No) >> ";    //確認是否再次執行
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');            //Yes則再來一次
	cout << "The procedure is terminated." << endl;    //輸出結束訊息
	system("pause");
	return(0);
}

void Input_time(void) {
	int hours, minutes;                              //幾點,幾分
	char time;                                       //AM還是PM
	cout << "Iuput time (hours and minutes) >> ";    //輸入時間
	cin >> hours >> minutes;
	if (hours <= 12) {                               //判定AM或PM,呼叫轉換
		time = 'A';
		conversion(time, hours, minutes);
	}
	else {
		time = 'P';
		conversion(hours, minutes, time);
	}
}

void conversion(char AM, int hours, int minutes) {    //AM可直接輸出
	output_time(hours, minutes, AM);
}

void conversion(int hours, int minutes, char PM) {    //PM減12小時
	hours -= 12;
	output_time(hours, minutes, PM);
}

void output_time(int hours, int minutes, char time) {    //判斷AM或PM來輸出訊息
	if (time == 'A') {
		cout << "It is " << hours << ":" << minutes << " A.M. now." << endl;
	}
	if (time == 'P') {
		cout << "It is " << hours << ":" << minutes << " P.M. now." << endl;
	}
}