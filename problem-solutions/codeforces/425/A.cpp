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

ll n, k;

int main(void){
	// scanf("%lld%lld", &n, &k);
	cin >> n >> k;

	ll res = n/k;
	if(res%2 == 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}