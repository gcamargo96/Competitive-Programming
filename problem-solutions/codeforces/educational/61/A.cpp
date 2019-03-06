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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll c1, c2, c3, c4;

void no(){
	printf("0\n");
	exit(0);
}

int main(void){
	scanf("%lld%lld%lld%lld", &c1, &c2, &c3, &c4);

	ll sum = 2LL*c1;

	if(c3 > 0 and sum == 0){
		no();
	}

	sum -= 2LL*c4;

	if(sum == 0){
		printf("1\n");
	}
	else{
		no();
	}

	return 0;
}