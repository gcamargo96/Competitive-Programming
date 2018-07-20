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