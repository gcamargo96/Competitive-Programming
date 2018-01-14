#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

int t, n;
int v[11];

int main(void){
	scanf("%d", &t);

	for(int c = 1; c <= t; c++){
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		sort(v, v+n);

		int ans = v[n/2];
		printf("Case %d: %d\n", c, ans);
	}

	return 0;
}