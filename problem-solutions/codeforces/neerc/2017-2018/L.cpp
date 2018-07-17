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

ll n;


int main(void){
	freopen("little.in", "r", stdin);
	freopen("little.out", "w", stdout);

	scanf("%lld", &n);

	ll aux = n;
	while(aux%2 == 0){
		aux /= 2;
	}

	if(aux == 1){
		printf("-1\n");
		return 0;
	}

	set<vector<ll> > ans;
	
	ll r = sqrt(n);
	if(r*r == n){
		vector<ll> v;
		v.pb(r); v.pb(r);
		ans.insert(v);
	}
	if(r*(r+1) == n){
		vector<ll> v;
		v.pb(r); v.pb(r+1);
		ans.insert(v);
	}

	for(ll i = 2; i <= 1000000; i++){
		vector<ll> v;
		ll aux = n;
		while(aux%i == 0){
			aux /= i;
			v.pb(i);
		}
		while(aux%(i+1) == 0){
			aux /= (i+1);
			v.pb(i+1);
		}
		if(aux == 1){
			ans.insert(v);
		}
	}

	vector<ll> v;
	v.pb(n);
	ans.insert(v);

	printf("%d\n", int(ans.size()));

	for(auto v : ans){
		printf("%d ", int(v.size()));
		for(int j = 0; j < v.size(); j++){
			printf("%lld ", v[j]);
		}
		printf("\n");
	}

	return 0;
}