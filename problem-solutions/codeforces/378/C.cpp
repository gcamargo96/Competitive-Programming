#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 502;
int n, m;
ll a[N], b[N];

bool go(int l, int r, int mxid){
	
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lld", &a[i]);
	}

	scanf("%d", &m);

	For(i,0,m){
		scanf("%lld", &b[i]);
	}

	bool ok = 1;

	int l, i = 0, j;
	for(j = 0; j < m; j++){
		ll sum = 0;
		int maxid = i, maxval = 0;
		l = i;
		while(i < n){
			sum += a[i];

			if(a[i] > maxval){
				maxval = a[i];
				maxid = i;
			}
			if(sum == b[j]) break;
			if(sum > b[j]){
				ok = 0;
				break;
			}
			i++;
		}
		if(ok == 0) break;
		ok = go(l, i, maxid);
		if(ok == 0) break;
	}

	return 0;
}

