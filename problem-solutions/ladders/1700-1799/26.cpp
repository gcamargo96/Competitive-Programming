#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int> 
#define fi first
#define se second

const int N = 5002;
int seg[4*N];
ii v[N];
int n, m, a, b;

void update(int r, int x, int i, int j){
	if(i > b or j < a) return;
	if(a <= i and j <= b){
		seg[r] = x;
	}
	else{
		int mid = (i+j)/2;
		update(2*r, x, i, mid);
		update(2*r+1, x, mid+1, j);
		seg[r] = max(seg[2*r], seg[2*r+1]);
	}
}

int query(int r, int i, int j){
	if(i > b or j < a) return 0;
	if(a <= i and j <= b){
		return seg[r];
	}
	else{
		int mid = (i+j)/2;
		int L = query(2*r, i, mid);
		int R = query(2*r+1, mid+1, j);
		return max(L, R);
	}
}

bool cmp(ii a, ii b){
	if(a.fi == b.fi){
		return a.se < b.se;
	}
	return a.fi < b.fi;
}

int main(void){
	scanf("%d%d", &n, &m);

	double aux;
	for(int i = 1; i <= n; i++){
		scanf("%d%lf", &v[i].fi, &aux);
		v[i].se = i;
	}

	sort(v+1, v+n+1, cmp);

	for(int i = 1; i <= n; i++){
		a = 1, b = v[i].se-1;
		int q = query(1, 1, n);

		a = b = v[i].se;
		update(1, q+1, 1, n);
	}

	// for(int i = 1; i <= n; i++){
	// 	a = b = i;
	// 	printf("%d ", query(1, 1, n));
	// }
	// printf("\n");

	a = 1, b = n;
	int ans = query(1, 1, n);
	printf("%d\n", n-ans);

	return 0;
}