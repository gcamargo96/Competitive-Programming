#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 3005;
int b, w;
char g[N][5];

int main(void){
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);
	
	scanf("%d%d", &b, &w);

	int r = max(b,w)*2+1, c = 3;
	printf("%d %d\n", r, c);

	int x, y;
	char cx, cy;
	if(b <= w){
		x = b, cx = '@';
		y = w, cy = '.';
	}
	else{
		x = w, cx = '.';
		y = b, cy = '@';
	}

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			g[i][j] = cx;
		}
	}

	int cnt = 0;
	for(int i = 2; cnt < y; i += 2, cnt++){
		g[i][2] = cy;

		if(cnt < x-1){
			for(int j = 1; j <= c; j++){
				g[i][j] = cy;
			}
		}
	}

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			printf("%c", g[i][j]);
		}
		printf("\n");
	}


	return 0;
}