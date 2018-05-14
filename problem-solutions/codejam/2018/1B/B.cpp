#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

struct item{
	int d, a, b;

	bool operator<(const item& x) const{
		return d < x.d;
	}
};

const int N = 100005;
int t, s;
item v[N];

int check(int x){
	int cnt = 0;
	for(int i = 0; i <= s-x; i++){
		set<int> sm, sn;
		for(int j = 0; j < x; j++){
			sm.insert(v[i+j].d + v[i+j].a);
			sn.insert(v[i+j].d - v[i+j].b);
		}

		bool ok = 0;
		for(int m : sm){
			for(int n : sn){
				bool ok2 = 1;
				for(int j = 0; j < x; j++){
					if(v[i+j].d + v[i+j].a != m and v[i+j].d - v[i+j].b != n){
						ok2 = 0;
					}
				}
				if(ok2){
					ok = 1;
				}
			}
		}

		if(ok){
			cnt++;
		}
	}
	return cnt;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d", &s);
		
		for(int i = 0; i < s; i++){
			scanf("%d%d%d", &v[i].d, &v[i].a, &v[i].b);
		}

		sort(v, v+s);

		int l = 1, r = s, y, z = 0;
		while(l <= r){
			int mid = (l+r)/2;

			int cnt = check(mid);
			if(cnt > 0){
				y = mid;
				z = cnt;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}

		printf("Case #%d: %d %d\n", caso, y, z);
	}

	return 0;
}