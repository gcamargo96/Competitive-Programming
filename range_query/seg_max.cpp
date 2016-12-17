#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define ll long long
#define endl "\n"

const int N = 100005;
ll seg[4*N], lazy[4*N], v[N];
int a, b;
int n, m;
ll x, w, h;

#define NUNCA_ACONTECE	-0x3f3f3f3f

void prop(int r, int i, int j){
	if (lazy[r] != NUNCA_ACONTECE) seg[r] = lazy[r];	/*AQUI*/
	if(i != j){
		lazy[2*r] = max(lazy[2*r], lazy[r]);
		lazy[2*r+1] = max(lazy[2*r+1], lazy[r]);
	}
	lazy[r] = NUNCA_ACONTECE;							/*AQUI*/
}

ll query(int r, int i, int j){
	prop(r, i, j);		/* COLOCA O PROP ANTES DE TUDO*/
	if(b < i || a > j) return 0;
	if(a <= i && j <= b) return seg[r];
	
	int mid = (i+j)/2;
	ll L = query(2*r, i, mid);
	ll R = query(2*r+1, mid+1, j);
	return max(L,R);
}

void update(int r, ll x, int i, int j){
	prop(r, i, j);		/*COLOCA O PROP ANTES DE TUDO*/
	if(b < i || a > j) return;
	if(a <= i && j <= b){
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
	lazy[r] = NUNCA_ACONTECE;	/*	AQUI */
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
	ios::sync_with_stdio(false);
	
	n = 5;

	for (int i = 1; i <= 5; i++)
		v[i] = 10;
	build(1,1,n);

	a = 3;	b = 5;
	update (1, 2, 1, n);


	for(int i = 1; i <= n; i++){
		a = b = i;
		cout << query(1,1,n) << " ";
	}
	cout << endl;

	//cin >> a >> b;
	//cout << query(1, 1, n) << endl;

	return 0;
}
