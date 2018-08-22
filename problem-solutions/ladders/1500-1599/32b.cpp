#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define ll long long
#define endl "\n"

const int N = 100005;
ll seg[4*N], lazy[4*N], v[N];
int a, b;
int n, m;
ll x, w, h;

void prop(int r, int i, int j){
	seg[r] = max(seg[r], lazy[r]);
	if(i != j){
		lazy[2*r] = max(lazy[2*r], lazy[r]);
		lazy[2*r+1] = max(lazy[2*r+1], lazy[r]);
	}
	lazy[r] = 0;
}

ll query(int r, int i, int j){
	if(b < i or a > j) return 0;
	prop(r, i, j);
	if(a <= i and j <= b) return seg[r];
	
	int mid = (i+j)/2;
	ll L = query(2*r, i, mid);
	ll R = query(2*r+1, mid+1, j);
	return max(L,R);
}

void update(int r, ll x, int i, int j){
	if(b < i or a > j) return;
	prop(r, i, j);
	if(a <= i and j <= b){
		seg[r] = x;
		if(i != j){
			lazy[2*r] = x;
			lazy[2*r+1] = x;
		}
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

void build(int r, int i, int j){
	if(i == j){
		seg[r] = v[i];
		return;
	}
	int mid = (i+j)/2;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}

	build(1,1,n);

	scanf("%d%d", &a, &b);
	update(1, 2, 1, n);

	for(int i = 1; i <= n; i++){
		a = b = i;
		cout << query(1,1,n) << " ";
	}
	cout << endl;

/*	For(i,0,n){
		cin >> x;
		a = b = i+1;
		update(1, x, 1, N);
	}

	cin >> m;

	For(i,0,m){
		cin >> w >> h;
		a = 1, b = w;
		ll res = query(1, 1, N);
		cout << res << endl;
		update(1, res+h, 1, N);
	}
*/

	return 0;
}
