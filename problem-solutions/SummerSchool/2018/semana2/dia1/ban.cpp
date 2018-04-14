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
int b[N], c[N], dp[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}

	scanf("%d", &m);

	for(int i = 0; i < n; i++){
		for(int j = m - b[i]; j >= 0; j--){
			if(dp[j]){
				int k = 1;
				while(k <= c[i] and j+k*b[i] < m and dp[j+k*b[i]] == 0){
					dp[j+k*b[i]] = 1;
					k++;
				}
			}
		}
	}

	return 0;
}