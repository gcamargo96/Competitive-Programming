#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 105;
int t, m;
ii r[N];
int g[N];


int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d", &m);

		for(int i = 1; i <= m; i++){
			scanf("%d%d", &r[i].fi, &r[i].se);
		}

		for(int i = 1; i <= m; i++){
			scanf("%d", &g[i]);
		}

		int ans = solve(1, 0);
	}

	return 0;
}