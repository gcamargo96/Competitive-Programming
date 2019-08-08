#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200005;
int n;
vi v;
vi pos[N];

int main(void){
	scanf("%d", &n);

	int op, x, l, r;
	for(int i = 0; i < n; i++){
		scanf("%d", &op);

		if(op == 0){
			if(v.size() > 0){
				pos[v.back()].pop_back();
				v.pop_back();
			}
			else{
				printf("invalid\n");
			}
		}
		if(op == 1){
			scanf("%d", &x);
			pos[x].pb(v.size());
			v.pb(x);
		}
		if(op == 2){
			scanf("%d%d%d", &x, &l, &r);
			l--, r--;
			int ans = upper_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l);
			printf("%d\n", ans);
		}
	}

	return 0;
}