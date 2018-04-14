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

const int N = 200002;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int k = n-1;
	bool ok = 1;
	vector<ii> ans;
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < v[i]; j++){
			if(k <= i){
				ok = 0;
				break;
			}
			ans.pb(ii(i+1, k+1));
			k--;
		}

		if(!ok){
			break;
		}
	}

	if(ok){
		printf("YES\n");

		for(int i = 0; i < ans.size(); i++){
			printf("%d %d\n", ans[i].fi, ans[i].se);
		}
	}
	else{
		printf("NO\n");
	}

	return 0;
}