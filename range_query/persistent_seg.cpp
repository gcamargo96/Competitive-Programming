#include <bits/stdc++.h>
using namespace std;

const int N = 10000002;
int n, a, b, curr, cntroot;
int v[N];
int seg[N], root[N];
int esq[N], dir[N];

void build(int r, int i, int j){
	if(i == j){
		if(r > curr) curr = r;
		seg[r] = v[i];
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

int main(void){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	build(1, 1, n);
	root[0] = 1;
	cntroot = 1;

	a = b = 2;
	root[cntroot] = update(root[cntroot-1], 5, 1, n);
	cntroot++;
	a = b = 3;
	root[cntroot] = update(root[cntroot-1], 6, 1, n);
	cntroot++;

	for(int k = 0; k < cntroot; k++){
		for(int i = 1; i <= n; i++){
			a = b = i;
			int res = query(root[k], 1, n);
			printf("%d ", res);
		}
		printf("\n");
	}

	return 0;
}
