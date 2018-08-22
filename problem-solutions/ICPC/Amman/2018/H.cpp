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

const int N = 2005;
int t, n;
int h[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 1; i <= 2*n; i++){
			scanf("%d", &h[i]);
		}

		int ans = -1;
		for(int i = 1; i <= n; i++){
			ans = max(ans, h[i] + h[2*n-i+1]);
		}

		printf("%d\n", ans);
	}

	return 0;
}