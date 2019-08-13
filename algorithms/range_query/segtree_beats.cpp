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
ll mn[4*N], mx[4*N], clf[4*N], lazy[4*N];
int a, b;
int n, m;

void build(int r, int i, int j){
	if(i == j){
		mn[r] = mx[r] = i;
		return;
	}

	int mid = (i+j)/2;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);

	mn[r] = min(mn[2*r], mn[2*r+1]);
	mx[r] = max(mx[2*r], mx[2*r+1]);
}

void prop(int r, int i, int j){
	if(lazy[r]){
		clf[r] += ll(j-i+1) * lazy[r];

		if(i != j){
			lazy[2*r] = lazy[r];
			mn[2*r] = mx[2*r] = mn[r];
			
			lazy[2*r+1] = lazy[r];
			mn[2*r+1] = mx[2*r+1] = mn[r];
		}

		lazy[r] = 0;
	}
}

void update(int r, int x, int i, int j){
	prop(r, i, j);
	if(i > b or j < a) return;
	if(i >= a and j <= b and mn[r] == mx[r]){
		lazy[r] = abs(mx[r]-x);
		mn[r] = mx[r] = x;
		prop(r, i, j);
		return;
	}

	int mid = (i+j)/2;
	update(2*r, x, i, mid);
	update(2*r+1, x, mid+1, j);

	clf[r] = clf[2*r] + clf[2*r+1];
	mn[r] = min(mn[2*r], mn[2*r+1]);
	mx[r] = max(mx[2*r], mx[2*r+1]);
}

ll query(int r, int i, int j){
	prop(r, i, j);
	if(i > b or j < a) return 0;
	if(i >= a and j <= b){
		return clf[r];
	}
	
	// printf("[%d,%d] = %lld\n", i, j, clf[r]);

	int mid = (i+j)/2;
	ll L = query(2*r, i, mid);
	ll R = query(2*r+1, mid+1, j);
	return L+R;
}

void print(){
	for(int i = 1; i <= n; i++){
		a = b = i;
		printf("%d ", query(1, 1, n));
	}
	printf("\n");
}

int main(void){
	scanf("%d%d", &n, &m);

	build(1, 1, n);

	int tipo, l, r, x;
	while(m--){
		scanf("%d", &tipo);

		if(tipo == 1){
			scanf("%d%d%d", &l, &r, &x);
			a = l, b = r;
			update(1, x, 1, n);
		}
		else{
			scanf("%d%d", &l, &r);
			a = l, b = r;
			ll ans = query(1, 1, n);
			printf("%lld\n", ans);
		}
	}

	return 0;
}