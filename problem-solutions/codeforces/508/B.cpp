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

ll n;
ll sum = 0;

int main(void){
	scanf("%lld", &n);

	if(n == 1){
		printf("No\n");
		return 0;
	}

	for(int i = 1; i <= n; i++){
		sum += i;
	}

	for(ll i = 2; i*i <= sum; i++){
		if(sum%i == 0){

			// printf("i = %lld\n", i);

			ll s1 = 0;
			vector<int> v1, v2;
			for(int j = n; j >= 1; j--){
				if(s1 < i and j <= i-s1){
					v1.pb(j);
					s1 += j;
				}
				else{
					v2.pb(j);
				}
			}

			printf("Yes\n");

			printf("%d ", int(v1.size()));
			for(int j = 0; j < v1.size(); j++){
				printf("%d ", v1[j]);
			}
			printf("\n");

			printf("%d ", int(v2.size()));
			for(int j = 0; j < v2.size(); j++){
				printf("%d ", v2[j]);
			}
			printf("\n");

			return 0;
		}
	}

	printf("No\n");

	return 0;
}