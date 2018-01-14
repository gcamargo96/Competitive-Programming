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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int t;
ll n;
ll sum[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lld", &n);

		ll cur = (n%2 == 0 ? 40000 : 39999);

		for(int i = 0; i < n-1; i++){
			printf("%lld ", cur);
		}

		ll sum = (n-1)*cur;
		ll falta = (1LL<<32) - sum;
		printf("%lld\n", falta/2);

		ll test = (n-1)*cur + falta;
		test %= (1LL<<32);
		printf("test = %lld\n", test);
	}

	return 0;
}