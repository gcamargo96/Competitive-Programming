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

int n;

int main(void){
	scanf("%d", &n);

	ll a = 0;
	int sgn = 0;
	int par = 0;
	for(int i = 0; i < n+1; i++){
		scanf("%lld", &a);
		if(a < 0){
			sgn = -1;
			if(i%2 == 0) par = 0;
			else par = 1;
		}
		else if(a > 0){
			sgn = 1;
			if(i%2 == 0) par = 0;
			else par = 1;
		}
	}

	if(sgn == 0){
		printf("0 0\n");
	}
	else if(sgn == 1){
		printf("1 ");
		if(par == 0) printf("1\n");
		else printf("-1\n");
	}
	else{
		printf("-1 ");
		if(par == 0) printf("-1\n");
		else printf("1\n");
	}

	return 0;
}