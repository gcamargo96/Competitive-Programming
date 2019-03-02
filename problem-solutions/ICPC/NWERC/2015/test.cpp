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

#define INF 1000000000000000000LL

ull mult(ull a, ull b){
	printf("%lld\n", a*b);
	printf("%lld\n", (a*b)/b);
	if((a*b)/a != b or (a*b)/b != a or a*b > INF){
		printf("too many\n");
		exit(0);
	}
	return a*b;
}

int main(void){
	mult(405442909778673664LL, 92);
	printf("not too many\n");

	return 0;
}