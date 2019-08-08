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

int n, m, q;

int main(void){
	scanf("%d", &q);

	while(q--){
		scanf("%d%d", &n, &m);

		vector<vector<int> > g(n+5);
		vector<vector<int> > l(n+5), r(n+5), u(n+5), d(n+5);

		for(int i = 0; i < n+5; i++){
			g[i] = vector<int>(m+5, 0);
			l[i] = vector<int>(m+5, 0);
			r[i] = vector<int>(m+5, 0);
			u[i] = vector<int>(m+5, 0);
			d[i] = vector<int>(m+5, 0);
		}

		char x;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf(" %c", &x);
				g[i][j] = x == '.' ? 0 : 1;
			}
		}


		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				l[i][j] = l[i][j-1] + g[i][j];
			}
			for(int j = m; j >= 1; j--){
				r[i][j] = r[i][j+1] + g[i][j];
			}
		}

		// for(int i = 1; i <= n; i++){
		// 	for(int j = 1; j <= m; j++){
		// 		printf("%d ", d[i][j]);
		// 	}
		// 	printf("\n");
		// }

		// u[1][1] = u[0][1];

		for(int j = 1; j <= m; j++){
			for(int i = 1; i <= n; i++){
				u[i][j] = u[i-1][j] + g[i][j];
			}
			for(int i = n; i >= 1; i--){
				d[i][j] = d[i+1][j] + g[i][j];
			}
		}
		
		int mx = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				mx = max(mx, l[i][j-1] + r[i][j+1] + u[i-1][j] + d[i+1][j] + g[i][j]);
			}
		}

		printf("%d\n", n+m-1-mx);
	}

	return 0;
}