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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

int n;

int main(void){
	scanf("%d", &n);

	ll sum = 1000000000000000000LL;
	for(ll i = 1;; i++){
		if(i*i >= n){
			sum = i+i;
			break;
		}
	}

	for(ll i = 1;; i++){
		if(i*(i+1) >= n){
			sum = min(sum, i+i+1);
			break;
		}
	}

	printf("%d\n", sum);

	return 0;
}