#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002;
int n, m, a, b;
ll segsum[4*N];
int v[N], segmax[4*N];
int divs[1000002];

void sieve(){
	for(int i = 1; i <= 1000000; i++){
		for(int j = i; j <= 1000000; j += i){
			divs[j]++;
		}
	}
}

void update_sum(int r, int i, int j){
	if(i > b or j < a){
		return;
	}
	if(i == j){
		segsum[r] = v[i];
		return;
	}

	int mid = (i+j)/2;
	update_sum(2*r, i, mid);
	update_sum(2*r+1, mid+1, j);
	segsum[r] = segsum[2*r] + segsum[2*r+1];
}

void update_max(int r, int i, int j){
	if(i > b or j < a){
		return;
	}
	if(i == j){
		segmax[r] = v[i];
		return;
	}

	int mid = (i+j)/2;
	update_max(2*r, i, mid);
	update_max(2*r+1, mid+1, j);
	segmax[r] = max(segmax[2*r], segmax[2*r+1]);
}

ll query_sum(int r, int i, int j){
	if(i > b or j < a){
		return 0;
	}
	if(a <= i and j <= b){
		return segsum[r];
	}

	int mid = (i+j)/2;
	ll L = query_sum(2*r, i, mid);
	ll R = query_sum(2*r+1, mid+1, j);
	return L+R;
}

int query_max(int r, int i, int j){
	if(i > b or j < a){
		return 0;
	}
	if(a <= i and j <= b){
		return segmax[r];
	}

	int mid = (i+j)/2;
	ll L = query_max(2*r, i, mid);
	ll R = query_max(2*r+1, mid+1, j);
	return max(L, R);
}


int main(void){
	scanf("%d%d", &n, &m);
	sieve();

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	a = 1, b = n;
	update_sum(1, 1, n);
	update_max(1, 1, n);

	int t, l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &t, &l, &r);

		if(t == 1){
			a = l, b = r;
			if(query_max(1, 1, n) > 2){
				for(int i = l; i <= r; i++)
					v[i] = divs[v[i]];
				update_sum(1, 1, n);
				update_max(1, 1, n);
			}
		}
		else{
			a = l, b = r;
			printf("%lld\n", query_sum(1, 1, n));
		}
	}

	return 0;
}