#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 100002;
int seg[4*N], v[N];
int a, b, n, k;

void build(int r, int i, int j){
	if(i == j){
		seg[r] = v[i];
		return;
	}
	int mid = (i+j)/2;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);
	seg[r] = seg[2*r]*seg[2*r+1];
}

void update(int r, int x, int i, int j){
	if(i > b or j < a) return;
	if(a <= i and j <= b){
		seg[r] = x;
		return;
	}
	int mid = (i+j)/2;
	update(2*r, x, i, mid);
	update(2*r+1, x, mid+1, j);
	seg[r] = seg[2*r]*seg[2*r+1];
}

int query(int r, int i, int j){
	if(i > b or j < a) return 1;
	if(a <= i and j <= b) return seg[r];
	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return L*R;
}

int main(void){
	ios_base::sync_with_stdio(false);
	
	while(cin >> n >> k){
		memset(seg, 0, sizeof seg);
		
		int x, y;
		For(i,1,n+1){
			cin >> x;
			if(x > 0) v[i] = 1;
			else if(x < 0) v[i] = -1;
			else v[i] = 0;
		}

		build(1,1,n);

		char c;
		For(i,0,k){
			cin >> c >> x >> y;
			if(c == 'C'){
				a = b = x;
				if(y > 0) y = 1;
				if(y < 0) y = -1;

				update(1, y, 1, n);
			}
			else{
				a = x, b = y;
				int res = query(1,1,n);
				if(res == 1) printf("+");
				else if(res == -1) printf("-");
				else printf("0");
			}
		}
		printf("\n");
	}

	return 0;
}
