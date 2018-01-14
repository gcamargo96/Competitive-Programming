#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002, M = 1000002;
int n;
int seg[4*M];
int a, b;
int dp[N], v[N];

void update(int r, int x, int i, int j){
	if(i > b or j < a) return;
	if(a <= i and j <= b){
		seg[r] = x;
		return;
	}
	
	int mid = (i+j)/2;
	update(2*r, x, i, mid);
	update(2*r+1, x, mid+1, j);
	seg[r] = max(seg[2*r], seg[2*r+1]);
}

int query(int r, int i, int j){
	if(i > b or j < a) return 0;
	if(a <= i and j <= b) return seg[r];

	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return max(L, R);
}

int main(void){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);

	int x;
	For(i,0,n){
		scanf("%d", &x);
		v[i] = x;
		a = 0, b = x-2;
		int l = query(1, 0, M);
		a = b = x;
		int m = query(1, 0, M);
		a = x+2, b = M;
		int r = query(1, 0, M);
		a = b = x;
		dp[i] = max(l, max(m, r))+1;
		update(1, max(l,max(m, r))+1, 0, M);
	}

	a = 0, b = M;
	int mx = query(1, 0, M);

	printf("%d\n", n-mx);

	int last = INF;
	vi vr;
	for(int i = n-1; i >= 0; i--){
		if(dp[i] == mx and v[i] != last-1 and v[i] != last+1){
			vr.pb(v[i]);
			last = v[i];
			mx--;
		}
	}

	reverse(vr.begin(), vr.end());

	For(i,0,vr.size()){
		printf("%d ", vr[i]);
	}
	printf("\n");
	
	return 0;
}

