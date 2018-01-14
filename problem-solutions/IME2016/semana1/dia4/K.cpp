#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 0x3f3f3f3f

const int N = 30002;
vector<int> seg[4*N];
int n, q;
int a, b, k;

void update(int r, int x, int i, int j){
	if(i > b or j < a) return;
	if(a <= i and j <= b){
		seg[r].pb(x);
	}
	else{
		int mid = (i+j)/2;
		update(2*r, x, i, mid);
		update(2*r+1, x, mid+1, j);
	}
}

void build(int r, int i, int j){
	if(i == j){
		return;
	}
	else{
		int mid = (i+j)/2;
		build(2*r, i, mid);
		build(2*r+1, mid+1, j);
		seg[r].insert(seg[r].end(), seg[2*r].begin(), seg[2*r].end());
		seg[r].insert(seg[r].end(), seg[2*r+1].begin(), seg[2*r+1].end());
		sort(seg[r].begin(), seg[r].end());
	}
}

int query(int r, int i, int j){
	int ret;
	if(j < a or i > b) return 0;
	if(a <= i and j <= b){
		int ret = upper_bound(seg[r].begin(), seg[r].end(), k) - seg[r].begin();
		return seg[r].size()-ret;
	}
	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return L+R;
}

void print_tree(int r, int i, int j){
	if(i == j){
		printf("r = %d %d\n", r, seg[r][0]);
		return;
	}
	int mid = (i+j)/2;
	print_tree(r*2, i, mid);
	printf("r = %d ", r);
	for(int i = 0; i < seg[r].size(); i++){
		printf("%d ", seg[r][i]);
	}
	printf("\n");
	print_tree(r*2+1, mid+1, j);
}

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		a = b = i+1;
		update(1, x, 1, n);
	}

	build(1, 1, n);
	
	scanf("%d", &q);

	int l, r, last = 0;
	for(int i = 0; i < q; i++){
		scanf("%d%d%d", &a, &b, &k);
		a = a^last;
		b = b^last;
		k = k^last;
		if(a < 1) a = 1;
		if(b > n) b = n;
		if(a > b){
			printf("0\n");
			last = 0;
		}
		else{
			int res = query(1, 1, n);
			printf("%d\n", res);
			last = res;
		}
	}

	return 0;
}
