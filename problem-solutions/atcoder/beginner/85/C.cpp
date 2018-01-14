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

int n;
ll y;

int main(void){
	scanf("%d%lld", &n, &y);

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			ll falta = y - (10000LL*i + 5000LL*j);
			if(falta >= 0 and falta%1000 == 0 and i + j + falta/1000 == n){
				printf("%d %d %lld\n", i, j, falta/1000);
				return 0;
			}
		}
	}

	printf("-1 -1 -1\n");

	return 0;
}