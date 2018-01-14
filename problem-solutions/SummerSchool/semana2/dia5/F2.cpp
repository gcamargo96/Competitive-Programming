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

const int N = 1000002;
int n;
ii seg[4*N];
int a, b;
int v[100002];

void update(int r, int x, int i, int j){
	if(i > b or j < a) return;
	if(a <= i and j <= b){
		seg[r].fi = x;
		return;
	}
	
	int mid = (i+j)/2;
	update(2*r, x, i, mid);
	update(2*r+1, x, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

ii query(int r, int i, int j){
	if(i > b or j < a) return ii(0,0);
	if(a <= i and j <= b) return seg[r];

	int mid = (i+j)/2;
	ii L = query(2*r, i, mid);
	ii R = query(2*r+1, mid+1, j);
	return max(L, R);
}

void init(int r, int i, int j){
	if(i == j){
		seg[r].se = i;
		return;
	}

	int mid = (i+j)/2;
	init(2*r, i, mid);
	init(2*r+1, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

int main(void){
	init(1, 1, N);
	scanf("%d", &n);

	int x;
	For(i,0,n){
		scanf("%d", &x);
		a = 1, b = x-2;
		ii l = query(1, 1, N);
		a = b = x;
		ii m = query(1, 1, N);
		a = x+2, b = N;
		ii r = query(1, 1, N);
		a = b = x;
		update(1, max(l.fi,max(m.fi, r.fi))+1, 1, N);
		v[i] = x;
	}

	/*for(int i = 1; i <= 4; i++){
		a = b = i;
		printf("%d ", query(1, 1, N));
	}
	printf("\n");
	*/

	set<int> keep;
	a = 1, b = N;
	ii mx  = query(1, 1, N);
	int res = mx.fi;
	while(mx.fi > 0){
		keep.insert(mx.se);
		a = b = mx.se-1;
		update(1, 0, 1, N);
		a = b = mx.se;
		update(1, 0, 1, N);
		a = b = mx.se+1;
		update(1, 0, 1, N);
		a = 1, b = N;
		mx = query(1, 1, N);
	}

	vi vres;
	For(i,0,n){
		if(keep.count(v[i])) vres.pb(v[i]);
	}

	printf("%d\n", n-res);
	For(i,0,vres.size()){
		printf("%d ", vres[i]);
	}
	printf("\n");

	return 0;
}

