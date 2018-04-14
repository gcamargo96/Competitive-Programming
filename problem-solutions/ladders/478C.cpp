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

ll v[3];

int main(void){
	scanf("%lld%lld%lld", &v[0], &v[1], &v[2]);
	sort(v, v+3);

	if(2LL*(v[0]+v[1]) <= v[2]){
		printf("%lld\n", v[0]+v[1]);
	}
	else{
		printf("%lld\n", (v[0]+v[1]+v[2])/3);
	}

	return 0;
}