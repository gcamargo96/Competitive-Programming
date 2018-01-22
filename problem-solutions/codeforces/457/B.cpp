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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll n;
int k;
int cnt[100];

int main(void){
	scanf("%lld%d", &n, &k);

	if(n == 1LL){
		if(k == 1){
			printf("Yes\n");
			printf("0\n");
		}
		else if(k == 2){
			printf("Yes\n");
			printf("-1 -1\n");			
		}
		else{
			printf("No\n");
		}
		return 0;
	}

	int d = 0;
	for(ll i = 0; i <= 62; i++){
		if(((n>>i)&1) == 1){
			cnt[i]++;
			d++;
		}
	}

	// for(ll i = 10; i >= 0; i--){
	// 	printf("%d ", cnt[i]);
	// }
	// printf("\n");

	for(ll i = 62; i > 0 and d < k; i--){
		while(d < k and cnt[i] > 0){
			cnt[i]--;
			cnt[i-1] += 2;
			d++;
		}
	}

	if(d == k){
		printf("Yes\n");
		for(int i = 62; i >= 0; i--){
			for(int j = 0; j < cnt[i]; j++){
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}