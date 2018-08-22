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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300005, M = 1000005;
map<ll,ll> m;
vector<pair<ll, ll> > v;
int has[M], to[M];
int n;
ll l = 1;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

void precalc(int x){
	for(int i = x+x; i < M; i += x){
		if(has[i])
			to[x] = i;
	}
}

bool cmp(pair<ll,ll> a, pair<ll, ll> b){
	if(to[a.se] != 0 and to[b.se] != 0){
		return a.fi < b.fi;
	}
	if(to[a.se] > 0 or to[b.se] > 0)
		return to[a.se] > to[b.se];
	return a.fi < b.fi;
}

int main(void){
	freopen("equal.in", "r", stdin);
	freopen("equal.out", "w", stdout);

	scanf("%d", &n);

	ll x;
	for(int i = 0; i < n; i++){
		scanf("%lld", &x);
		m[x]++;
		has[x] = 1;
		l = lcm(l, x);
	}

	for(auto it : m){
		v.pb(mp(it.se, it.fi));
	}

	sort(v.begin(), v.end());

	int cnt = 0;	
	vector<ll> ans1, ans2;
	map<ll,ll> m1, m2;
	m1 = m2 = m;

	ans1.pb(m.size());
	for(int i = 0; i < v.size(); i++){
		if(v[i].se == l) continue;

		for(int j = 0; j < v[i].fi; j++){
			m1[v[i].se]--;
			if(m1[v[i].se] == 0){
				m1.erase(v[i].se);
			}
			m1[l]++;
			ans1.pb(m1.size());
			cnt++;
		}
	}
	while(cnt < n){
		ans1.pb(m1.size());
		cnt++;
	}

	if(m.count(l)){
		for(int i = 0; i < n+1; i++){
			printf("%d ", ans1[i]);
		}
		printf("\n");
	}
	else{
		for(auto it : m){
			precalc(it.fi);
		}

		sort(v.begin(), v.end(), cmp);
		
		cnt = 0;
		ans2.pb(m2.size());
		for(int i = 0; i < v.size(); i++){
			for(int j = 0; j < v[i].fi; j++){
				m2[v[i].se]--;
				if(m2[v[i].se] == 0){
					m2.erase(v[i].se);
				}

				if(to[v[i].se] != 0){
					m2[to[v[i].se]]++;
				}
				else{
					m2[l]++;
				}
				ans2.pb(m2.size());
				cnt++;
			}
		}
		while(cnt < n){
			ans2.pb(m2.size());
			cnt++;
		}

		for(int i = 0; i < n+1; i++){
			printf("%lld ", min(ans1[i], ans2[i]));
		}
		printf("\n");
	}

	return 0;
}