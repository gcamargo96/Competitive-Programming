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

const int N = 52;
int n, m;
int g[N][N];
ll pot[N];
ll c0r[N], c1r[N], c0c[N], c1c[N];

void precalc(){
	pot[0] = 1;
	for(int i = 1; i < N; i++){
		pot[i] = 2LL*pot[i-1];
	}
}

int main(void){
	precalc();
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &g[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == 0){
				c0r[i]++;
			}
			else{
				c1r[i]++;
			}
		}
	}

	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(g[i][j] == 0){
				c0c[j]++;
			}
			else{
				c1c[j]++;
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += pot[c0r[i]] - 1;
		ans += pot[c1r[i]] - 1;
	}

	for(int j = 0; j < m; j++){
		ans += pot[c0c[j]] - c0c[j] - 1;
		ans += pot[c1c[j]] - c1c[j] - 1;		
	}

	printf("%lld\n", ans);

	return 0;
}