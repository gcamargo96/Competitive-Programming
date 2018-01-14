#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second

const int N = 10000002;
int n, q, a, b, k, curr, cntroot;
ii v[N];
int seg[N], root[N];
int esq[N], dir[N];
map<int,int> mp;

void build(int r, int i, int j){
	if(i == j){
		if(r > curr) curr = r;
		seg[r] = 0;
	}
	else{
		int mid = (i+j)/2;
		build(2*r, i, mid);
		build(2*r+1, mid+1, j);
		esq[r] = 2*r;
		dir[r] = 2*r+1;
		seg[r] = seg[2*r]+seg[2*r+1];
	}
}

int update(int r, int x, int i, int j){
	if(i > b or j < a) return r;
	if(a <= i and j <= b){
		seg[++curr] = x;
		return curr;
	}
	int mid = (i+j)/2;
	int L = update(esq[r], x, i, mid);
	int R = update(dir[r], x, mid+1, j);
	curr++;
	seg[curr] = seg[L]+seg[R];
	esq[curr] = L;
	dir[curr] = R;
	return curr;
}

int query(int r, int i, int j){
	if(i > b or j < a) return 0;
	if(a <= i and j <= b){
		return seg[r];
	}
	int mid = (i+j)/2;
	int L = query(esq[r], i, mid);
	int R = query(dir[r], mid+1, j);
	return L+R;
}

bool cmp(ii a, ii b){
	return b.fi < a.fi;
}

int main(void){
	scanf("%d", &n);
	build(1, 1, n);
	root[0] = 1;
	cntroot = 1;

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i].fi);
		v[i].se = i;
	}

	sort(v+1, v+n+1, cmp);

	for(int i = 1; i <= n; i++){
		a = b = v[i].se;
		root[cntroot] = update(root[cntroot-1], 1, 1, n);
		mp[v[i].fi] = cntroot;
		cntroot++;
	}

	/*for(int i = 1; i < cntroot; i++){
		for(int j = 1; j <= n; j++){
			a = b = j;
			int res = query(root[i], 1, n);
			printf("%d ", res);
		}
		printf("\n");
	}*/

	scanf("%d", &q);
	int last = 0;
	for(int i = 1; i <= q; i++){
		scanf("%d%d%d", &a, &b, &k);
		a = a^last;
		b = b^last;
		k = k^last;
		if(a < 1) a = 1;
		if(b > n) b = n;
		auto it = mp.upper_bound(k);
		if(it == mp.end()){
			printf("0\n");
			last = 0;
		}
		else{
			int id = it->se;
			//printf("seg de %d: root[%d] de %d a %d\n", it->fi, it->se, a, b);
			int res = query(root[id], 1, n);
			printf("%d\n", res);
			last = res;
		}
	}

	return 0;
}
