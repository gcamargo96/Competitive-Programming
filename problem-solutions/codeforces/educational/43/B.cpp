#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

ll n, m, k;

int main(void){
	scanf("%lld%lld%lld", &n, &m, &k);

	if(k < n){
		printf("%lld 1\n", k+1);
		return 0;
	}

	ll row = n - (k-n)/(m-1);
	
	ll col;
	if(row%2 == 0){
		col = (k-n)%(m-1) + 2;
	}
	else{
		col = (m-1) - (k-n)%(m-1) + 1;
	}

	printf("%lld %lld\n", row, col);

	return 0;
}