#include <bits/stdc++.h>
using namespace std;


int mark[201] = {0};
int N, H;

void TRY(int index, int remainingLetter){
	if (index > N){
		if (remainingLetter == 0){
			for (int i = 1; i <= N; i++){
				cout << mark[i];
			}
			cout << endl;
		}
		return;
	}

	if (remainingLetter == 0){
		mark[index] = 0;
		TRY(index + 1, remainingLetter);
	} else {
		for (int i = 0; i <= 1; i++){
			mark[index] = i;
			TRY(index + 1, remainingLetter - i);
		}
	}

}

int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> N >> H;
		int index = 1;
		int remaingingLetter = H;
		TRY(index, H);
	}
	
}

