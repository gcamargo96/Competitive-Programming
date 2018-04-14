#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 500002;
int v[N];
vi g[N];
int n, m;

bool check(int l, int r, int x){
	int qnt = upper_bound(g[x].begin(), g[x].end(), r) - lower_bound(g[x].begin(), g[x].end(), l);
	return qnt > (r-l+1)/2;	
}

int main(void){
	srand(time(NULL));
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		g[v[i]].pb(i);
	}

	int l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l, &r);

		int tries = 50, ans = 0;
		while(tries--){
			int p = rand()%(r-l+1) + l;
			if(check(l, r, v[p])){
				ans = v[p];
				break;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}