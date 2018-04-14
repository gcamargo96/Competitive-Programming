#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

int n;

int main(void){
	scanf("%d", &n);

	if(n < 6){
		printf("-1\n");
	}
	else{
		printf("1 2\n");
		printf("1 3\n");
		printf("1 4\n");
		for(int i = 5; i <= n; i++){
			printf("4 %d\n", i);
		}
	}

	for(int i = 1; i <= n-1; i++){
		printf("%d %d\n", i, i+1);
	}

	return 0;
}