#include <bits/stdc++.h>
using namespace std;
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

int n, m;
ll x, d;

int main(void){
	scanf("%d%d", &n, &m);

	ll sum = 0;
	for(int i = 0; i < m; i++){
		scanf("%lld%lld", &x, &d);
		sum += n*x;

		if(d >= 0){
			sum += ((ll(n-1)*d)*n)/2LL;
		}
		else{
			if((n&1) == 0){
				sum += ((d + ll(n/2-1)*d)*ll(n/2-1))/2LL + ((d + ll(n/2)*d)*ll(n/2))/2LL;
			}
			else{
				sum += (d + ll(n/2)*d)*ll(n/2);
			}
		}
	}

	printf("%lf\n", double(sum)/double(n));

	return 0;
}