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

const int N = 200002;
int n, k;
vi v;

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		v.pb(x);
	}

	sort(v.begin(), v.end());

	int ans = n;
	for(int i = 0; i < n; i++){
		auto it = upper_bound(v.begin(), v.end(), v[i]);

		if(it != v.end() and *it <= v[i]+k){
			ans--;
		}
	}

	printf("%d\n", ans);

	return 0;
}