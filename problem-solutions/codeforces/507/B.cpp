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

int n, k;

int main(void){
	scanf("%d%d", &n, &k);

	if(k == 0){
		printf("%d\n", n);
		for(int i = 1; i <= n; i++){
			printf("%d ", i);
		}
		printf("\n");
		return 0;
	}

	int q = n/(2*k+1);
	int r = n%(2*k+1);

	if(r == 0){
		int ans = q;
		printf("%d\n", ans);
		for(int i = k+1; i <= n; i += 2*k+1){
			printf("%d ", i);
		}
		printf("\n");
	}
	else if(q > 0){
		int ans = q+1;
		printf("%d\n", ans);
		for(int i = 1; i <= n; i += 2*k+1){
			printf("%d ", i);
		}
		printf("\n");
	}
	else{
		printf("1\n");
		printf("%d\n", n/2);
	}

	return 0;
}