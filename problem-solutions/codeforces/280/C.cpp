#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
ll n, r, avg;
pair<ll,ll> v[N];

	bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return a.se < b.se;
}

int main(void){
	scanf("%lld%lld%lld", &n, &r, &avg);

	For(i,0,n){
		scanf("%lld%lld", &v[i].fi, &v[i].se);
	}

	sort(v, v+n, cmp);

	ll tot = n*avg;

	ll tem = 0;
	For(i,0,n){
		tem += v[i].fi;
	}

	if(tem >= tot){
		printf("0\n");
		return 0;
	}

	ll res = 0;
	For(i,0,n){
		if(v[i].fi < r){
			ll aux;
			if(tot - tem >= 0) aux = tot-tem;
			else aux = 1000000000000000000LL;
			tem += min(aux, r - v[i].fi);
			res += v[i].se * min(aux, r - v[i].fi);
		}
		//cout << tem << endl;
		if(tem >= tot) break;
	}

	printf("%lld\n", res);

	return 0;
}

