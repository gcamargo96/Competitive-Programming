// LIS2    http://codeforces.com/gym/101055/problem/D SOLUTION
//
// POINT UPDATE, RANGE QUERY
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define vi vector<int>

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = exp(1);

#define L(x) 2*x
#define R(x) 2*x + 1

struct no {
	int *seg;
	vector <ii> v;
	int n;
	int ay, by, a, b;

	no () {}

	no (int n) : n(n) {
		seg = new int [4*n + 1];
		for (int i = 0; i < 4*n + 1; i++)
			seg[i] = 0;
		v.resize(n);
	}

	int query (int ly, int ry, int l, int r, int val) {
		ay = ly;	by = ry;
		a = l;	b = r;
		return query (1, 0, n-1, val);
	}

	int query (int r, int i, int j, int val) {
		if (v[j] < ii(ay, a) or v[i] > ii(by, b)) return 0;

		if (v[i] >= ii(ay, a) and v[j] <= ii(by, b)) {
			seg[r] = max (seg[r], val);
			return seg[r];
		} else {
			int mid = (i + j)/2;
			int L = query (L(r), i, mid, val);
			int R = query (R(r), mid + 1, j, val);
			seg[r] = max (seg[L(r)], seg[R(r)]);
			return max(L, R);
		}
	}
};

const int N = 1e5 + 10;
int n;
vector<ii> v, p;
no seg[4*N + 1];
int xh, yh, xw, yw;

void build (int r, int i, int j) {
	seg[r] = no (j - i + 1);

	if (i == j) {
		seg[r].v[0] = ii(v[i].se, v[i].fi);
	} else {
		int mid = (i + j)/2;
		build (L(r), i, mid);
		build (R(r), mid + 1, j);

		merge (seg[L(r)].v.begin(), seg[L(r)].v.end(), 
		seg[R(r)].v.begin(), seg[R(r)].v.end(), seg[r].v.begin());
	}
}

int a, b, ay, by;

int query (int r, int i, int j, int val) {
	if (v[j].fi < a or v[i].fi > b) return 0;

	if (v[i].fi >= a and v[j].fi <= b) {
		return seg[r].query(ay, by, a, b, val);
	} else {
		int mid = (i + j)/2;
		int L = query (L(r), i, mid, val);
		int R = query (R(r), mid + 1, j, val);
		seg[r].query(ay, by, a, b, val);
		return max(L, R);
	}
}

// bool cmp(ii a, ii b){
// 	if(xh <= xw){ // x normal
// 		if(yh <= yw){ // y normal
// 			return a < b;
// 		}
// 		else{ // y ao contrario
// 			if(a.fi == b.fi)
// 				return a.se > b.se;
// 			return a.fi < b.fi;
// 		}
// 	}
// 	else{ // x ao contrario
// 		if(yh <= yw){ // y normal
// 			if(a.fi == b.fi)
// 				return a.se < b.se;
// 			return a.fi > b.fi;
// 		}
// 		else{ // y ao contrario
// 			if(a.fi == b.fi)
// 				return a.se > b.se;
// 			return a.fi > b.fi;
// 		}
// 	}
// }

int main (void) {
	scanf ("%d", &n);
	scanf("%d%d%d%d", &xh, &yh, &xw, &yw);

	int x, y;
	vi vx, vy;
	for (int i = 0; i < n; i++) {
		scanf ("%d %d", &x, &y);
		
		if(x >= min(xh,xw) and y >= min(yh,yw) and x <= max(xh,xw) and y <= max(yh,yw)){
			if(xh > xw){ // inverte x
				x = xw + xh-x;
			}
			if(yh > yw){ // inverte y
				y = yw + yh-y;
			}

			p.eb(x,y);
			v.eb(x,y);

			vx.pb(x);
			vy.pb(y);
		}
	}

	n = v.size();

	if(n == 0){
		printf("0\n");
		return 0;
	}

	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());

	vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
	vy.resize(unique(vy.begin(), vy.end()) - vy.begin());	

	for(int i = 0; i < n; i++){
		v[i].fi = lower_bound(vx.begin(), vx.end(), v[i].fi) - vx.begin();
		v[i].se = lower_bound(vy.begin(), vy.end(), v[i].se) - vy.begin();
		p[i] = v[i];
	}


	sort (v.begin(), v.end());
	sort(p.begin(), p.end());
	build (1, 0, n - 1);

	int res = 0;
	/*V DEVE ESTAR ORDENADO PARA AS QUERIES FUNCIONAREM*/
	for (int i = 0; i < n; i++) {
		a = 0;	b = p[i].fi;
		ay = 0;	by = p[i].se;

		int x = query (1, 0, n - 1, 0);	
		// printf("%d %d %d\n", p[i].fi, p[i].se, x);

		res = max (res, x + 1);

		a = b = p[i].fi;
		ay = by = p[i].se;
		query (1, 0, n - 1, x + 1);
	}

	printf ("%d\n", res);

	return 0;
}