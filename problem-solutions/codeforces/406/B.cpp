#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	int k, x;
	bool res = 0;
	For(i,0,m){
		scanf("%d", &k);
		set<int> s;
		bool ok = 0;
		For(j,0,k){
			scanf("%d", &x);
			if(s.count(-x)) ok = 1;
			s.insert(x);
		}
		if(!ok) res = 1;
	}

	if(res) printf("YES\n");
	else printf("NO\n");

	return 0;
}

