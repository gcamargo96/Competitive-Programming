#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 100002;
int n, f;
ii v[N];

bool cmp(ii a, ii b){
	return max(0, min(2*a.fi, a.se)) > max(0, min(2*b.fi, b.se));
}

int main(void){
	scanf("%d%d", &n, &f);

	For(i,0,n){
		scanf("%d%d", &v[i].fi, &v[i].se);
	}

	sort(v, v+n, cmp);

	ll res = 0;
	For(i,0,f){
		res += (ll) max(0, min(2*v[i].fi, v[i].se));
	}
	for(int i = f; i < n; i++){
		res += (ll) min(v[i].fi, v[i].se);	
	}

	printf("%lld\n", res);

	return 0;
}

