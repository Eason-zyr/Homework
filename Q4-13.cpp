//mph函式&測試
#include<iostream>
using namespace std;

double convertToMPH(int minutes, int seconds);    //用速率轉換
double convertToMPH(double kph);                  //用公里小時轉換

int main(void) {
	int minutes, seconds;    //幾分,幾秒
	double kph, mph;         //公里小時,英里小時
	char again;              //確認是否再次測試
	
	cout << "Testing 1" << endl;
	do {
		cout << "Input your pace (minutes and seconds per mile, Ex. 5 30) >> ";    //輸入幾分幾秒一英里
		cin >> minutes >> seconds;
		mph = convertToMPH(minutes, seconds);                                      //第一版函式測試
		cout << "Your mph (miles per hour) is " << mph << endl;                    //測試結果
		cout << "Test again? (y or n) >> ";                                        //是否再次測試
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');
	
	cout << "Testing 2" << endl;
	do {
		cout << "Input your kph (kilometers per hours) >> ";    //輸入公里小時
		cin >> kph;
		mph = convertToMPH(kph);                                //第二版函式測試
		cout << "Your mph is " << mph << endl;                  //測試結果
		cout << "Test again? (y or n) >> ";                     //是否再次測試
		cin >> again;
		cout << endl;
	} while (again == 'Y' || again == 'y');
	
	cout << "Testing terminated." << endl;                      //測試結束
	system("pause");
	return(0);
}

double convertToMPH(int minutes, int seconds) {
	double mph;
	mph = 3600 / (double(minutes) * 60 + double(seconds));      //mph計算式
	return(mph);
}

double convertToMPH(double kph) {
	double mph;
	mph = kph / 1.61;                                           //mph計算式
	return(mph);
}