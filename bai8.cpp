#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
	// i la vi tri thi i trong stack
	// j la can gia tri cua qua can thu i
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    s.push(state(1, 0));
    s.push(state(1, 1));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M << endl;;
                //exit(0);
            }
            s.pop();
            continue;
        }
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/
		int index = top.i;
		x[index] = top.j;
		sum = 0;
		for (int i = 1; i <= index; i++)
			sum += x[i] * m[i];
		if (sum > M){
			s.pop();
			s.push(state(index+1, -1));	
		} else if (sum == M){
			s.pop();
			s.push(state(index+1, 0));
		} else {
			s.pop();
			s.push(state(index+1, -1));
			s.push(state(index+1, 0));
			s.push(state(index+1, 1));
		}
        
    }
    cout << -1;

    return 0;
}
