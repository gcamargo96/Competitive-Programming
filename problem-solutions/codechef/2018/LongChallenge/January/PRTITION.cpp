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

const int N = 1000002;
int t;
ll x, n;
int ans[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lld%lld", &x, &n);

		ll sum = ((1+n)*n)/2 - x;
		
		if(sum%2 == 1){
			printf("impossible\n");
			continue;
		}

		ll acum = 0, target = sum/2;
		for(int i = n; i >= 1; i--){
			if(i == x){
				ans[i] = 2;
			}
			else if(acum + i <= target and target - (acum+i) != x){
				ans[i] = 1;
				acum += i;
			}
			else{
				ans[i] = 0;
			}
		}

		if(acum == target){
			for(int i = 1; i <= n; i++){
				printf("%d", ans[i]);
			}
			printf("\n");
		}
		else{
			printf("impossible\n");
		}
	}



	return 0;
}