#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define H 0
#define G 1

const int N = 1002;

struct cow{
	ll x, y;
};

int n, m;
cow h[N], g[N];
ll pd[N][N][2];

ll solve(int i, int j, int tipo){
	if(i == n and tipo == H) return 1000000000000000;
	if(j == m and tipo == G) return 1000000000000000;
	if(i == n-1 and j == m and tipo == H) return 0;
	//if(i == n-1 and j < m and tipo == H) return 1000000000000000;
	//if(j > m) return 1000000000000000;
	ll& dp = pd[i][j][tipo];
	if(dp != -1) return dp;

	ll ret1, ret2;
	
	ll dist;
	if(tipo == H){
		dist = (h[i].x-h[i+1].x)*(h[i].x-h[i+1].x) + (h[i].y-h[i+1].y)*(h[i].y-h[i+1].y);
		ret1 = dist + solve(i+1, j, H);
		dist = (h[i].x-g[j].x)*(h[i].x-g[j].x) + (h[i].y-g[j].y)*(h[i].y-g[j].y);
		ret2 = dist + solve(i+1, j, G);
	}
	else{
		dist = (g[j].x-g[j+1].x)*(g[j].x-g[j+1].x) + (g[j].y-g[j+1].y)*(g[j].y-g[j+1].y);
		ret1 = dist + solve(i, j+1, G);
		dist = (h[i].x-g[j].x)*(h[i].x-g[j].x) + (h[i].y-g[j].y)*(h[i].y-g[j].y);
		ret2 = dist + solve(i, j+1, H);
	}

	return dp = min(ret1, ret2);
}

int main(void){
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);

	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%lld%lld", &h[i].x, &h[i].y);
	}
	For(i,0,m){
		scanf("%lld%lld", &g[i].x, &g[i].y);
	}

	memset(pd, -1, sizeof pd);
	ll res = solve(0,0,H);

	printf("%lld\n", res);

	return 0;
}
