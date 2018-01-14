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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, m, r, k;

int main(void){
	scanf("%d%d%d%d", &n, &m, &r, &k);

	vector<ii> g[n+5];
	for(int i = 0; i < n+5; i++){
		g[i].resize(m+5, ii(min(r, m-r+1), min(r, n-r+1)));
	}

	for(int i = 0; i < n; i++){
		int cnt = 1;
		for(int j = 0; j < r; j++){
			g[i][j].fi = min(g[i][j].fi, cnt++);
		}

		cnt = 1;
		for(int j = m-1; j >= m-r; j--){
			g[i][j].fi = min(g[i][j].fi, cnt++);
		}
	}

	for(int j = 0; j < m; j++){
		int cnt = 1;
		for(int i = 0; i < r; i++){
			g[i][j].se = min(g[i][j].se, cnt++);
		}

		cnt = 1;
		for(int i = n-1; i >= n-r; i--){
			g[i][j].se = min(g[i][j].se, cnt++);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("(%d,%d) ", g[i][j].fi, g[i][j].se);
		}
		printf("\n");
	}

	vector<double> cnt;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cnt.pb(double(g[i][j].fi) * double(g[i][j].se));
			// printf("%lf ", cnt[cnt.size()-1]);
		}
	}
	// printf("\n");

	sort(cnt.begin(), cnt.end());

	int len = cnt.size();
	double sum = 0;
	for(int i = 1; i <= k; i++){
		sum += cnt[len-i];
	}

	double prob = double(n-r+1) * double(m-r+1);
	double E = sum/prob;

	printf("%.10lf\n", E);

	return 0;
}