//だ计だガ参璸
#include<iostream>
using namespace std;

int main(void) {
	int students;                     //厩ネ计秖
	int student[100];                 //程100厩ネ
	int grades[6];                    //Θ罿参璸
	
	for (int i = 0; i < 6; i++) {     //﹍て皚0
		grades[i] = 0;
	}
	
	cout << "How many students? ";    //Τぶ厩ネ
	cin >> students;
	cout << "Input the grade of each student >> ";    
	for (int i = 0; i < students; i++) {             
		cin >> student[i];                           //块–厩ネΘ罿
		grades[student[i]]++;                        //参璸计秖
	}
	cout << endl;

	for (int i = 0; i < 6; i++) {                    //块参璸挡狦
		cout << grades[i] << " grade(s) of " << i << endl;
	}

	system("pause");
	return(0);
}