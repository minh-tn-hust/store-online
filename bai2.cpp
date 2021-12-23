#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Luu t?a d? các bu?c di chuy?n c?a quân mã
int mark[100][100]; //# Ðánh d?u v? trí các ô mà quân mã dã di chuy?n qua

//# M?ng hx, hy mô t? 8 v? trí quân mã có th? di chuy?n k? t? v? trí hi?n t?i
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int flag = 0;
//# In ra dãy các di chuy?n tìm du?c
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thu?t toán quay lui
void TRY(int k){
	if (flag == 1)
		return;
	if (k > n*n){
		int sum = 0;
		for (int a = 1 ; a <= n; a++){
    		for (int b = 1; b <= n; b++){
    			sum += mark[a][b];
			}
		}
		if (sum == n*n){
			flag = 1;
			for (int i = 1; i <= n*n; i++)
				cout << "(" <<X[i] << " " << Y[i] << ")"<< endl;
		}
		return;
	}
	
    for(int i = 0; i < 8; i++){
    	int xx = X[k-1] + hx[i];
	        int yy = Y[k-1] + hy[i];		
	        if (xx >= 1 && yy >= 1 && xx <= n && yy <= n){
	        	X[k] = xx;
	        	Y[k] = yy;
	        	if (mark[yy][xx] == 0){
					mark[yy][xx] = 1;
					TRY(k+1);
					mark[yy][xx] = 0;
				}
			}
		}
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
