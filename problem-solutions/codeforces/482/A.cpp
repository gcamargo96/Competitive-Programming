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

ll n;

int main(void){
	scanf("%lld", &n);
	n++;

	if(n == 1){
		printf("0\n");
	}
	else if(n%2LL == 0){
		printf("%lld\n", n/2LL);
	}
	else{
		printf("%lld\n", n);
	}

	return 0;
}