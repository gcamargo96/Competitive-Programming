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

#define BEG 0
#define POINT 1
#define END 2

struct point{
	ll x;
	int i, tipo;

	point() {}

	point(ll _x, ll _i, ll _tipo){
		x = _x;
		i = _i;
		tipo = _tipo;
	}

	void print(){
		printf("x = %lld, i = %d, tipo = %d\n", x, i, tipo);
	}

	bool operator<(const point& b) const {
		if(x == b.x)
			return tipo < b.tipo;
		return x < b.x;
	}
};

const int N = 200005;
int n, m;
pair<ll,ll> islands[N];
vector<point> v;
set<pair<ll,ll> > active;
ll Ends[N];
int ans[N];

int main(void){
	scanf("%d%d", &n, &m);

	ll l, r;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &l, &r);
		islands[i].fi = l;
		islands[i].se = r;

		// v.eb(l, i, BEG);
		// v.eb(r, i, END);
		// Ends[i] = r;
	}

	sort(islands, islands+n);

	ll l1, r1, l2, r2;
	for(int i = 1; i < n; i++){
		l1 = islands[i-1].fi;
		r1 = islands[i-1].se;
		l2 = islands[i].fi;
		r2 = islands[i].se;

		v.eb(l2-r1, i, BEG);
		v.eb(r2-l1, i, END);
		Ends[i] = r2-l1;
	}

	ll x;
	for(int i = 1; i <= m; i++){
		scanf("%lld", &x);
		v.eb(x, i, POINT);
	}

	sort(v.begin(), v.end());

	// for(int i = 0; i < v.size(); i++){
	// 	v[i].print();
	// }

	memset(ans, -1, sizeof ans);

	for(int i = 0; i < v.size(); i++){
		if(v[i].tipo == BEG){
			active.insert(mp(Ends[v[i].i], (ll) v[i].i));
		}
		else if(v[i].tipo == POINT){
			auto it = active.lower_bound(mp((ll)v[i].x, (ll)-1));

			if(it != active.end()){
				ans[it->se] = v[i].i;
				active.erase(it);
			}
		}
		else{ // tipo == END
			active.erase(mp(Ends[v[i].i], (ll)v[i].i));
		}
	}

	bool ok = 1;
	for(int i = 1; i < n; i++){
		// printf("%d ", ans[i]);
		if(ans[i] == -1){
			ok = 0;
			break;
		}
	}
	// printf("\n");

	if(ok){
		printf("Yes\n");
		for(int i = 1; i < n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}