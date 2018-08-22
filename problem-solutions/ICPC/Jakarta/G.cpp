#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(ll (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef complex<double> base;

struct patient{
	ll t0, s, r;

	patient() {}

	patient(ll _t0, ll _s, ll _r){
		t0 = _t0;
		s = _s;
		r = _r;
	}

	ll severity(ll t){
		return s + r*(t-t0);
	}

	// bool operator<(const patient& b) const{
	// 	return (s + r*(100-t0)) > (b.s + b.r*(100-t0));
	// }
};

struct Cmp {
   bool operator()(const patient &a, const patient &b) const {
      return (a.s - a.r*a.t0 + a.r * 100) < (b.s - b.r*b.t0 + b.r * 100);
   }
};

const ll N = 105;
ll t, n;
priority_queue<patient, vector<patient>, Cmp> pq[N];


void init(){
	for(ll i = 0; i < N; i++){
		while(!pq[i].empty()){
			pq[i].pop();
		}
	}
}

main(void){
	fastcin;
	cin >> t;

	for(ll caso = 1; caso <= t; caso++){
		init();
		cin >> n;

		cout << "Case #" << caso << ":" << endl;

		char op;
		for(ll i = 0; i < n; i++){
			cin >> op;

			if(op == 'P'){
				ll t0, s, r;
				cin >> t0 >> s >> r;
				pq[r].push(patient(t0, s, r));
			}
			else{
				ll tempo; cin >> tempo;
				
				pair<ll,int> ans = mp(-1LL,-1);
				for(int j = 0; j <= 100; j++){
					if(!pq[j].empty()){
						patient p = pq[j].top();
						ans = max(ans, mp(p.severity(tempo), j));
					}
				}

				cout << ans.fi << " " << ans.se << endl;
				pq[ans.se].pop();
			}
		}
	}

	// return 0;
}