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
#define fast_cin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define int long long

int a, b, c;

main(void){
	scanf("%lld%lld%lld", &a, &b, &c);

	bool ans = 0;
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < 10000; j++){
			if(a*i + b*j == c){
				ans = 1;
				break;
			}
			else if(a*i + b*j > c){
				break;
			}
		}
		if(ans) break;
	}

	if(ans) printf("Yes\n");
	else printf("No\n");

	return 0;
}