#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000
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

const int N = 200002;
int n, k;
int a[N], b[N];
ll pd[N];

ll go(int i, int bef, int aft){
	if(i == n){
		if(bef < k) return INF;
		else return 0;
	}
	ll& dp = 
}

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%d", &a[i]);
	}
	
	For(i,0,n){
		scanf("%d", &b[i]);
	}

	ll res = go(0, 0, 0);

	return 0;
}

