#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

const int N = 202, M = 20002;
int n, m;
int w[N], dp[N];

void knapsack(){
	for(int j = 0; j <= m; j++){
		dp[j] = (j == 0);
	}
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= m; j++){
			dp[j] |= dp[j-w[i]];
		}
	}
}