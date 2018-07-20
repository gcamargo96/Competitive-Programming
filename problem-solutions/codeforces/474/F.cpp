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

const int N = 100005;
int a, b;

struct SegTree{
	vi seg;
	int n;

	SegTree() {}

	SegTree(int n){
		seg.resize(4*n+1, 0);
		this->n = n;
	}

	int size(){
		return n;
	}

	int query(int r, int i, int j){
		if(b < i or a > j) return 0;
		if(a <= i and j <= b) return seg[r];
		int mid = (i+j)/2;	
		int L = query(2*r, i, mid);
		int R = query(2*r+1, mid+1, j);
		return max(L, R);
	}

	void update(int r, int x, int i, int j){
		if(b < i or a > j) return;
		if(a <= i and b >= j){
			seg[r] = x;
			return;
		}
		int mid = (i+j)/2;
		update(r*2, x, i, mid);
		update(r*2+1, x, mid+1, j);
		seg[r] = max(seg[2*r], seg[2*r+1]);
	}
};

int n, m;
vector<tuple<int,int,int> >in;
vector<int> pesos[N];
SegTree seg[N];

int main(void){
	scanf("%d%d", &n, &m);

	int u, v, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &w);
		in.eb(u,v,w);
		pesos[v].pb(w);
	}

	for(int i = 1; i <= n; i++){
		sort(pesos[i].begin(), pesos[i].end());
		pesos[i].resize(unique(pesos[i].begin(), pesos[i].end()) - pesos[i].begin());
		seg[i] = SegTree(pesos[i].size());
	}

	int ans = 0;
	for(int i = 0; i < m; i++){
		tie(u,v,w) = in[i];
		
		int p = lower_bound(pesos[u].begin(), pesos[u].end(), w) - pesos[u].begin();
		p--;

		int x;
		if(p >= 0){
			a = 0, b = p;
			x = seg[u].query(1, 0, seg[u].size()-1);
		}
		else{
			x = 0;
		}

		a = b = lower_bound(pesos[v].begin(), pesos[v].end(), w) - pesos[v].begin();
		seg[v].update(1, x+1, 0, seg[v].size()-1);

		ans = max(ans, x+1);
	}

	printf("%d\n", ans);

	return 0;
}