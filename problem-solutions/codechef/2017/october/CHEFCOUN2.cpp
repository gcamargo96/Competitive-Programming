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

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lld", &n);

		ll cur = (1LL<<32)/n;
		ll last = (1LL<<32) - (n-1)*cur; //cur + (1LL<<32)%(2LL*n);

		if((1LL<<32)%n == 0){
			cur = (1LL<<32)/n - 1;
			last = (1LL<<32) - (n-1)*cur; //cur + 2LL*n-1;
		}

		while(last/2 < cur){
			cur--;
			last += (n-1);
		}

		ll mid = cur;
		if(last%2 == 1){
			mid--;
			last++;
		}

		for(int i = 0; i < n-2; i++){
			printf("%lld ", cur);
		}

		printf("%lld %lld\n", mid, last/2);

		ll test = (n-1)*cur + last;
		// printf("test = %lld\n", test%(1LL<<32));
		// printf("last = %lld\n", last);
	}

	return 0;
}