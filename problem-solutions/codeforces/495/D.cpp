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

const int N = 4000005;
int t, n, m;
int cnt[N], cnt2[N];
int x0 = -1, Y0 = -1, mx = -1;

void check(int n, int m){
	int x = n;
	int y = mx-n+1;

	if(y > m) return;

	while(x >= 1){
		// testar os cantos
		int d1 = x+y-2;
		int d2 = x + m-y - 1;
		int d3 = n-x + y - 1;
		int d4 = n-x + m-y;

		int cnt_mx = 0;
		if(d1 == mx) cnt_mx++;
		if(d2 == mx) cnt_mx++;
		if(d3 == mx) cnt_mx++;
		if(d4 == mx) cnt_mx++;

		if(d1 <= mx and d2 <= mx and d3 <= mx and d4 <= mx and cnt_mx == cnt[mx]){
			// printf("testando para n = %d, m = %d, x = %d, y = %d\n", n, m, x, y);
			memset(cnt2, 0, sizeof cnt2);

			for(int ii = 1; ii <= n; ii++){
				for(int jj = 1; jj <= m; jj++){
					int dist = abs(ii-x) + abs(jj-y);
					cnt2[dist]++;
				}
			}

			bool ok = 1;
			for(int j = 0; j < N; j++){
				if(cnt[j] != cnt2[j]){
					// printf("deu ruim em %d %d\n", it.fi, it.se);
					ok = 0;
					break;
				}
			}

			if(ok){
				x0 = x;
				Y0 = y;
				break;
			}
		}
		x--;
		y++;
	}
}

int main(void){
	scanf("%d", &t);

	int x;
	for(int i = 0; i < t; i++){
		scanf("%d", &x);
		cnt[x]++;
		mx = max(mx, x);
	}

	for(int i = 1; i <= t; i++){
		if(t%i == 0){
			n = i;
			m = t/i;

			check(n, m);

			if(x0 != -1) break;
		}
	}

	if(x0 != -1){
		printf("%d %d\n", n, m);
		printf("%d %d\n", x0, Y0);
	}
	else{
		printf("-1\n");
	}

	return 0;
}