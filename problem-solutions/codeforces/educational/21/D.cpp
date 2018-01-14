#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
int n;
ll v[N], sum[N];

int main(void){
	scanf("%d", &n);

	ll total = 0;
	For(i,1,n+1){
		scanf("%lld", &v[i]);
		total += v[i];
	}

	if(total%2 == 1){
		printf("NO\n");
		return 0;
	}

	int last = -1;
	bool stop = 0;
	For(i,1,n+1){
		if(!stop and sum[i-1] + v[i] <= total/2){
			last = i;
			sum[i] = sum[i-1] + v[i];
		}
		if(sum[i-1] + v[i] >= total/2){
			stop = 1;
		}
	}

	if(sum[last] == total/2){
		printf("YES\n");
		return 0;
	}

	for(int i = last+1; i <= n; i++){
		if(sum[last] + v[i] == total/2 or sum[last] - v[last] + v[i] == total/2){
			printf("YES\n");
			return 0;
		}
	}

	/*for(int i = 1; i <= n; i++){
		printf("%lld ", sum[i]);
	}
	printf("\n");
	*/

	printf("NO\n");

	return 0;
}

