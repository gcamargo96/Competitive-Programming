#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int n;
ii v[N];

bool cmp(ii a, ii b){
	return a.fi-a.se > b.fi-b.se;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &v[i].fi, &v[i].se);
	}

	sort(v, v+n, cmp);

	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += ll(i)*ll(v[i].fi) + ll(n-i-1)*ll(v[i].se);
	}

	printf("%lld\n", ans);

	return 0;
}