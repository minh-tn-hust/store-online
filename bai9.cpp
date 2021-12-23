#include <bits/stdc++.h>
using namespace std;


int mark[201] = {0};
int N, K1, K2;

void TRY(int index, int lastWorkingDays){
	if (index > N ) {
		if (mark[N] == 0){
			for (int i = 1; i <= N; i++)
				cout << mark[i];
			cout << endl;
		} else if (K1 <= lastWorkingDays && lastWorkingDays <= K2){
			for (int i = 1; i <= N; i++)
				cout << mark[i];
			cout << endl;
		}
		return;
	}

	
	if (index != 1 && lastWorkingDays < K1){
		mark[index] = 1;
		TRY(index + 1, lastWorkingDays + 1);
	} else if (lastWorkingDays < K2){
		for (int i = 0; i <= 1; i++){
			mark[index] = i;
			if (i == 0)
				TRY(index + 1, 0);
			if (i == 1)
				TRY(index + 1, lastWorkingDays + 1);
		}
	} else if (lastWorkingDays == K2){
		mark[index] = 0;
		TRY(index+1, 0);
	}
	else {
		mark[index] = 0;
		TRY(index+1, 0);
	}

}

int main() {
	cin >> N >> K1 >> K2;
	int index = 1;
	int lastWorkingDays = 0;
	TRY(index, lastWorkingDays);
	
}
