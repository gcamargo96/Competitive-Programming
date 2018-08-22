#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 150002;

int n, k, x;
ll sum[N];

int main(void){
	scanf("%d%d", &n, &k);
	
	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		sum[i] = sum[i-1] + x;
	}

	ll minsum = 1000000000000000LL;
	int res = 1;

	for(int i = 1; i+k-1 <= n; i++){
		int j = i+k-1;
		if(minsum > sum[j]-sum[i-1]){
			minsum = sum[j]-sum[i-1];
			res = i;
		}
	}

	printf("%d\n", res);

	return 0;
}

