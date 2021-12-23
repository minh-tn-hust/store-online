#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int previousState[10000] = {0};
int storeState[10000] = {0};

int binom2(int n, int k){
	if (k == 0){
		previousState[k] = 1;
		storeState[k] = 1;
		return 1;
	} else if (k == n){
		// tien hanh cap nhat lai mang previousState
		for (int j = 0; j < n; j++){
			previousState[j] = storeState[j];
		}
		previousState[n] = 1;
		storeState[n] = 1;
		return 1;

	} else {
		storeState[k] = previousState[k-1] + previousState[k];
		return storeState[k];
	}
		
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
