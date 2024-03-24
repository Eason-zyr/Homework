//電影評價&比較推測
#include<iostream>
#include<cmath>
using namespace std;
const int Movies_Num = 6;    //電影數量
const int Reviewers = 4;     //影評數量

int compare(int reviews[][Movies_Num], int movies[3], int score[3]);                          //比較與誰最相似
double cal_distance(int reviews[][Movies_Num], int movies[3], int score[3], int reviewer);    //計算差異值

int main(void) {
	int closest;                                             //最接近者
	int movies[3], score[3];                                 //評價的3部電影和評分
	int reviews[Reviewers][Movies_Num] = { {3,1,5,2,1,5},    //影評與電影評分之表格
										   {4,2,1,4,2,4},
										   {3,1,2,4,4,1},
										   {5,1,4,2,4,2} };
	bool error;                                              //輸入是否錯誤
	cout << "Movie numbers 100~105 ,ratings 1~5." << endl;
	cout << "Giving three movies and ratings (example. 102 5) >> ";
	do {
		error = false;
		for (int i = 0; i < 3; i++) {                                                              //輸入3部電影及評分
			cin >> movies[i] >> score[i];
			if (!(movies[i] >= 100 && movies[i] <= 105) || !(score[i] >= 1 && score[i] <= 5)) {    //檢測輸入是否正確
				error = true;
				cout << "Input error ,please input again!" << endl;
			}
		}
		if (movies[0] == movies[1] || movies[0] == movies[2] || movies[1] == movies[2]) {          //檢測是否重複輸入
			error = true;
			cout << "Duplicate input ,please input again!" << endl;
		}
	} while (error);
	closest = compare(reviews, movies, score);                                                     //呼叫函式進行比對
	cout << "The closest match of your ratings is reviewer " << closest << endl;                   //顯示結果
	for (int i = 0; i < Movies_Num; i++) {                                                         //推測其餘電影使用者可能會給的評分
		if (i + 100 != movies[0] &&
			i + 100 != movies[1] &&
			i + 100 != movies[2]) {
			cout << "You may give rating " << reviews[closest][i] << " to movie " << i + 100 << endl;
		}
	}
	system("pause");
	return(0);
}

int compare(int reviews[][Movies_Num], int movies[3], int score[3]) {    //比對最接近誰的評價
	int closest = 0;                                                     //預設最接近0號
	double distance[Reviewers];                                          //和每位的差異值
	for (int i = 0; i < Reviewers; i++) {
		distance[i] = cal_distance(reviews, movies, score, i);           //呼叫函式進行計算
	}
	for (int i = 1; i < Reviewers; i++) {
		if (distance[i] < distance[closest]) {                           //一一比較
			closest = i;
		}
	}
	return(closest);                                                     //回傳最接近者
}

double cal_distance(int reviews[][Movies_Num], int movies[3], int score[3], int reviewer) {    //計算差異值
	double distance = 0;                                                                       //差異值
	for (int i = 0; i < 3; i++) {
		distance += pow((score[i] - reviews[reviewer][movies[i] - 100]), 2);                   //差異值公式步驟1
	}
	return(sqrt(distance));                                                                    //步驟2&回傳
}
