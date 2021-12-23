#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
	s.push(state(1, 1, 1));
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        /*****************
        # YOUR CODE HERE #
        *****************/

		int index = top.i;
		x[index] = top.j;
		L = top.old_L;
		if (index == n){
			s.pop();
			s.push(state(index+1,0,0));
			continue;
		}
		if (L == k-1){
			s.pop();
			s.push(state(index + 1, 0, 0));
		} else {
			s.pop();
			s.push(state(index + 1, 1, L + 1));
			s.push(state(index + 1, 0, 0));
		}
    }
    return 0;
}
