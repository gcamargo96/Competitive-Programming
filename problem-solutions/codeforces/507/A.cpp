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

const int N = 25;
int n;
int v[N];
int cost[3];

int main(void){
	scanf("%d%d%d", &n, &cost[0], &cost[1]);
	cost[2] = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int ans = 0;
	bool ok = 1;
	for(int i = 0; i < n/2; i++){
		int j = n-i-1;
		
		if((v[i] == 0 and v[j] == 1) or (v[i] == 1 and v[j] == 0)){
			ok = 0;
			break;
		}

		if(v[i] == 2 and v[j] == 2){
			ans += 2*min(cost[0], cost[1]);
		}
		else if(v[i] == 2 or v[j] == 2){
			ans += cost[v[i]] + cost[v[j]];
		}
	}

	if(n%2 == 1){
		if(v[n/2] == 2){
			ans += min(cost[0], cost[1]);
		}
	}

	if(ok){
		printf("%d\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}