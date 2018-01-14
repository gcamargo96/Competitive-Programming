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
int n, m, a, b;
int seg[4*N];
int v[N], fr[N], esq[N], dir[N];

void build(int r, int i, int j){
	if(i == j){
		seg[r] = fr[i];
		return;
	}
	int mid = (i+j)/2;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

int query(int r, int i, int j){
	if(j < a or i > b){
		return 0;
	}
	if(a <= i and j <=b){
		return seg[r];
	}
	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	
	return max(L,R);
}

void init(){
	memset(seg, 0, sizeof seg);
	For(i,0,N){
		v[i] = 0;
		esq[i] = 0;
		dir[i] = 0;
		fr[i] = 0;
	}
}

int main(void){
	while(scanf("%d", &n) and n != 0){
		init();
		scanf("%d", &m);

		For(i,1,n+1){
			scanf("%d", &v[i]);
		}

		int x = v[1], i = 1, j = 1;
		for(i = 2; i <= n; i++){
			if(v[i] != x){
				int freq = i-j;
				int l = j, r = i-1;
				while(j < i){
					fr[j] = freq;
					esq[j] = l;
					dir[j] = r;
					j++;
				}
				x = v[i];
			}
		}
		int freq = i-j;
		int l = j, r = i-1;
		while(j <= n){
			fr[j] = freq;
			esq[j] = l;
			dir[j] = r;
			j++;
		}
		
		build(1,1,n);

		For(i,0,m){
			scanf("%d%d", &a, &b);
			int A = min(dir[a],b) - a + 1;
			int B = b - max(esq[b], a) + 1;
			
			a = dir[a]+1;
			b = esq[b]-1;
			int C = query(1,1,n);
			
			int res = max(max(A,B), C);
			printf("%d\n", res);
		}
	}

	return 0;
}
