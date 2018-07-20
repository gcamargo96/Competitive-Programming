#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct star{
	int x, y, s;

	star() {}

	star(int _x, int _y, int _s){
		x = _x;
		y = _y;
		s = _s;
	}


};

const int N = 100005;
int n, q, c;
star s[N];
int ans[105][105][15]; // x, y, t

int main(void){
	scanf("%d%d%d", &n, &q, &c);

	int x, y, s;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &x, &y, &s);
		// s[i] = star(x,y,s);

		for(int t = 0; t <= c; t++){
			ans[x][y][t] += (s+t)%(c+1);
		}
	}

	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			for(int t = 0; t <= c; t++){
				ans[i][j][t] += ans[i-1][j][t] + ans[i][j-1][t] - ans[i-1][j-1][t];
			}
		}
	}

	// for(int t = 0; t <= c; t++){
	// 	for(int i = 1; i <= 3; i++){
	// 		for(int j = 1; j <= 3; j++){
	// 			printf("%d ", ans[i][j][t]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }

	int t, x1, y1, x2, y2;
	for(int i = 0; i < q; i++){
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		t %= (c+1);

		int sum = ans[x2][y2][t] - ans[x2][y1-1][t] - ans[x1-1][y2][t] + ans[x1-1][y1-1][t];
		printf("%d\n", sum);
	}

	return 0;
}