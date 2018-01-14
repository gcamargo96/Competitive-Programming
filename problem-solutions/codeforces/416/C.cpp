#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct range{
	int l, r, val;

	range() {}

	range(int _l, int _r, int _val){
		l = _l;
		r = _r;
		val = _val;
	}
};

const int N = 5002;
int n;
int v[N], first[N], last[N];
bool foi[N], tem[N];
vector<range> ranges;
int dp[N][N];

bool cmp(range a, range b){
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}

int go(int i, int last){
	if(i >= ranges.size()) return 0;
	if(ranges[i].l < last) return dp[i][last] = go(i+1, last);
	if(dp[i][last] != -1) return dp[i][last];

	int a = 0, b = 0;
	a = go(i+1, last);
	b = go(i+1, ranges[i].r+1) + ranges[i].val;

	//printf("a = %d / b = %d\n", a, b);

	return dp[i][last] = max(a, b);
}

int main(void){
	memset(first, INF, sizeof first);
	memset(last, -1, sizeof last);
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);


	For(i,0,n){
		scanf("%d", &v[i]);
		tem[v[i]] = 1;
		first[v[i]] = min(first[v[i]], i);
		last[v[i]] = max(last[v[i]], i);
	}

	For(i,0,N){
		if(tem[i]){
			int l = first[i], r = last[i];
			int li = l, ri = r;
			bool init = 1;

			while(init or li != l or ri != r){
				init = 0;
				li = l, ri = r;

				for(int j = l; j <= r; j++){
					l = min(first[v[j]], l);
					r = max(last[v[j]], r);
				}
				for(int j = r; j >= l; j--){	
					l = min(first[v[j]], l);
					r = max(last[v[j]], r);
				}
			}
			
			int val = 0;
			set<int> s;
			for(int i = l; i <= r; i++){
				if(!s.count(v[i])){
					s.insert(v[i]);
				}
			}

			for(int x : s){
				val ^= x;
			}

			//printf("range do %d: %d a %d, xor = %d\n", i, l, r, val);
			ranges.pb(range(l, r, val));
		}
	}

	sort(ranges.begin(), ranges.end(), cmp);

	/*For(i,0,ranges.size()){
		printf("%d %d %d\n", ranges[i].l, ranges[i].r, ranges[i].val);
	}*/

	int res = go(0,0);

	printf("%d\n", res);
	
	return 0;
}

