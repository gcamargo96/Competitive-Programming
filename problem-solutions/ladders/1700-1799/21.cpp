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
int a[12];

int main(void){
	scanf("%d", &n);

	int mincost = INF, pos = -1;
	for(int i = 1; i <= 9; i++){
		scanf("%d", &a[i]);

		if(a[i] < mincost){
			mincost = a[i];
			pos = i;
		}
	}

	if(mincost > n){
		printf("-1\n");
		return 0;
	}

	vi ans;
	while(n >= mincost){
		ans.pb(pos);
		n -= mincost;
	}

	for(int i = 0; i < ans.size(); i++){
		for(int j = 9; j > ans[i]; j--){
			if(n >= a[j]-a[ans[i]]){
				n -= a[j]-a[ans[i]];
				ans[i] = j;
				break;
			}
		}
	}

	for(int i = 0; i < ans.size(); i++){
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}