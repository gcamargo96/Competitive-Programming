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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n;
ll a[N], b[N];

int main(void){
	scanf("%d", &n);

	ll sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);	
		sum += a[i];
	}

	for(int i = 0; i < n; i++){
		scanf("%lld", &b[i]);	
	}

	sort(b, b+n);

	if(b[n-2] + b[n-1] < sum){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}

	return 0;
}