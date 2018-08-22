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

int t, n;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		int m = n-1;

		int ans = 0;
		for(int i = 0; i < 31; i++){
			int b1 = (n>>i)&1;
			int b2 = (m>>i)&1;

			if(b1 != b2)
				ans++;
		}

		printf("%d\n", ans);
	}

	return 0;
}