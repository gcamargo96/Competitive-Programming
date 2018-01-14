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

int r, n;

int main(void){
	int c = 1;
	while(scanf("%d%d", &r, &n) and !(r == 0 and n == 0)){
		if(r <= n){
			printf("Case %d: 0\n", c);
		}
		else if(r/n <= 26){
			int ans = (r%n == 0 ? r/n-1 : r/n);
			printf("Case %d: %d\n", c, ans);
		}
		else{
			printf("Case %d: impossible\n", c);
		}
		c++;
	}

	return 0;
}