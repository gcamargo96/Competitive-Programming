#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000005;
int t, mx = -1;
int f[N], f2[N];

bool check(int n, int m, int x, int y){
	// printf("%d %d %d %d\n", n, m, x, y);
	if(x < 1 or x > n or y < 1 or y > m) return 0;

	memset(f2, 0, sizeof f2);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int dist = abs(x-i) + abs(y-j);
			f2[dist]++;
		}
	}

	for(int i = 0; i <= mx; i++){
		if(f[i] != f2[i]) return 0;
	}

	return 1;
}

int main(void){
	scanf("%d", &t);

	int val;
	for(int i = 0; i < t; i++){
		scanf("%d", &val);
		f[val]++;
		mx = max(mx, val);
	}

	if(t == 1){
		if(mx == 0){
			printf("1 1\n");
			printf("1 1\n");
		}
		else{
			printf("-1\n");
		}
		return 0;
	}

	for(int n = 1; n*n <= t; n++){
		if(t%n == 0){
			int m = t/n;

			int x = -1;
			for(int i = 1; i <= mx; i++){
				if(f[i] != 4*i){
					x = i;
					break;
				}
			}

			if(x == -1){
				continue;
			}

			int y = n+m-mx-x;

			if(check(n, m, x, y)){
				printf("%d %d\n", n, m);
				printf("%d %d\n", x, y);
				return 0;
			}
			if(check(n, m, y, x)){
				printf("%d %d\n", n, m);
				printf("%d %d\n", y, x);
				return 0;
			}
			// if(check(m, n, x, y)){
			// 	printf("%d %d\n", m, n);
			// 	printf("%d %d\n", x, y);
			// 	return 0;
			// }
			// if(check(m, n, y, x)){
			// 	printf("%d %d\n", m, n);
			// 	printf("%d %d\n", y, x);
			// 	return 0;
			// }
		}
	}

	printf("-1\n");

	return 0;
}