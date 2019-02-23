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

const int N = 100005;
int n;
int v[N];

bool check(ll x){
	for(int i = 0; i < n; i++){
		x += v[i];
		if(x < 0) return 0;
	}
	return 1;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int lo = 0, hi = 1000000005;
	int ans = hi;
	while(lo <= hi){
		int mid = (lo+hi)/2;

		if(check(mid)){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}

	printf("%d\n", ans);

	return 0;
}