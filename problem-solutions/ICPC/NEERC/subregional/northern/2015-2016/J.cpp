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

const int N = 50005;
int n;
ll t;
ll p[N], d[N];

bool check(int step){
	map<ll, int> m;
	map<int, ll> mr;

	ll cur;
	m[0] = 1, mr[1] = 0;
	for(int i = 2; i <= n; i++){
		ll last = 0;
		if(!m.empty()){
			auto it = m.begin();
			last = it->fi;

			if(mr.size() == step){
				auto itr = mr.begin();
				m[itr->se]--;

				if(m[itr->se] == 0){
					m.erase(itr->se);
				}
				mr.erase(itr);
			}
		}

		cur = last + d[i];
		m[cur]++;
		mr[i] = cur;
	}

	// printf("step = %d, cur = %lld\n", step, cur);

	return cur <= t;
}

int main(void){
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);

	scanf("%d%lld", &n, &t);

	vector<pair<ll, int> > v;
	for(int i = 1; i <= n-1; i++){
		scanf("%lld", &p[i]);

		while(!v.empty() and v.back().fi >= p[i]){
			v.pop_back();
		}
		v.eb(p[i], i);
	}

	for(int i = 2; i <= n-1; i++){
		scanf("%lld", &d[i]);
	}

	int l = 0, r = v.size()-1;
	ll ans = v.back().fi;
	while(l <= r){
		int mid = (l+r)/2;

		if(check(v[mid].se)){
			ans = v[mid].fi;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}