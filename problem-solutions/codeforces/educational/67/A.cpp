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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int T, n, s, t;

int main(void){
	scanf("%d", &T);

	while(T--){
		scanf("%d%d%d", &n, &s, &t);

		if(n == s and n == t and s == t){
			printf("1\n");
			continue;
		}

		int ans = n - min(s,t) + 1;
		printf("%d\n", ans);
	}

	return 0;
}