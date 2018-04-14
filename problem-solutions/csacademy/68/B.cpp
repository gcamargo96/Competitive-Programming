#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, m, k;
vector<ii> p;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			p.emplace_back(i,j);
		}
	}

	int ans = 0;
	for(int i = 0; i < p.size(); i++){
		for(int j = i+1; j < p.size(); j++){
			int g = gcd(abs(p[i].fi-p[j].fi), abs(p[i].se-p[j].se));
			if(g+1 == k){
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}