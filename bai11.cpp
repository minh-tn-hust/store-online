#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

#define INIT_INDEX  1
#define INIT_PRICE  0

const int INF = 1e9;


int mark[2*MAX] = {0};
int price[MAX][MAX];
int place[MAX];
int vis[MAX];
int ans = INF;

int getListPlace(int arr[]){
	int place;
	char c;
	int pos = 1;
	do {
		scanf("%d%c", &place, &c);
		arr[pos++] = place;
	} while(c != '\n');
	return pos - 1;
}

void TRY(int index, int length, int currentPrice){
	int currentPlace = (index == 1)? place[1] : mark[index-1];

	if (index > length){
		ans = min(ans, currentPrice);
		return;
	}

	if (index == 1){
		mark[index] = place[index];
		TRY(index+1, length, currentPrice);
	} else if (index == length){
		if (price[currentPlace][place[length]] == 0)
			return;
		mark[length] = place[length];
		TRY(index+1, length, currentPrice + price[currentPlace][mark[index]]);
	} else {
		for (int i = 2; i < length; i++){
			int nextPlace = place[i];
			if (vis[nextPlace] == 0 && price[currentPlace][nextPlace] != 0){
				vis[nextPlace] = 1;
				mark[index] = nextPlace;
				TRY(index +1, length, currentPrice + price[currentPlace][nextPlace]);
				vis[nextPlace] = 0;
			}
		}
	}

}

int main() {
	int n,r;
	cin >> n >> r;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> price[i][j];
		}
	}

	for (int i = 1; i <= r; i++){
		int length = getListPlace(place);
		memset(vis,0,sizeof(vis));
		memset(mark,0,sizeof(mark));
		ans = INF;
		TRY(INIT_INDEX, length, INIT_PRICE);
		if (ans == INF){
			cout << 0 << endl;
		} else cout << ans << endl;
	}
}


