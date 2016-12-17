#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int seg[4*N], lazy[4*N];
int a, b;

void prop(int r, int i, int j){
	int t = lazy[r];
	seg[r] += (j-i+1) * lazy[r];
	lazy[r] = 0;
	if(i != j){
		lazy[2*r] += t;
		lazy[2*r+1] += t;
	}
}

int query(int r, int i, int j){
	prop(r, i, j);
	if(b < i or a > j) return 0;
	if(a <= i and j <= b) return seg[r];
	int mid = (i+j)/2;	
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return L+R;
}

void update(int r, int x, int i, int j){
	prop(r, i, j);
	if(b < i or a > j) return;
	if(a <= i and b >= j){
		seg[r] += x;
		if(i != j){
			lazy[2*r] += x;
			lazy[2*r+1] += x;
		}
		return;
	}
	int mid = (i+j)/2;
	update(r*2, x, i, mid);
	update(r*2+1, x, mid+1, j);
	seg[r] = min(seg[2*r], seg[2*r+1]);
}
