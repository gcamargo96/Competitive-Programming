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

#define BEG 0
#define END 1

struct event{
	int l, p, id, t;

	event() {}

	event(int _l, int _p, int _id, int _t){
		l = _l;
		p = _p;
		id = _id;
		t = _t;
	}

	bool operator<(const event& b) const{
		if(p == b.p){
			if(t == b.t){
				return l > b.l;
			}
			return t < b.t;
		}
		return p < b.p;
	}
};

const int N = 300005;
vector<event> v;
ii in[N];
int n;

int main(void){
	scanf("%d", &n);

	int l, r;
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &l, &r);
		in[i] = ii(l, r);

		v.pb(event(l, l, i, BEG));
		v.pb(event(l, r, i, END));
	}

	sort(v.begin(), v.end());

	// for(int i = 0; i < v.size(); i++){
	// 	printf("%d %d %d\n", v[i].p, v[i].t, v[i].l);
	// }

	set<ii> s; // (pos, id)
	for(int i = 0; i < v.size(); i++){
		if(v[i].t == BEG){
			s.insert(ii(v[i].p, v[i].id));
		}
		else{ // type == END
			s.erase(ii(in[v[i].id].fi, v[i].id));

			if(s.size() > 0 and s.begin()->fi <= in[v[i].id].fi){
				printf("%d %d\n", v[i].id, s.begin()->se);
				return 0;
			}
		}
	}

	printf("-1 -1\n");

	return 0;
}