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

const int N = 100005;
int n;
ii v[N];

bool cmp(ii a, ii b){
	if(a.fi == b.fi)
		return a.se > b.se;
	return a.fi < b.fi;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &v[i].fi, &v[i].se);
	}

	sort(v, v+n, cmp);

	int r = v[0].se, ans = 0;
	for(int i = 1; i < n; i++){
		if(v[i].se < r)
			ans++;
		r = max(r, v[i].se);
	}

	printf("%d\n", ans);

	return 0;
}