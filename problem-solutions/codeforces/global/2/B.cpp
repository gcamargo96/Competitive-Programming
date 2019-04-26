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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1005;
int n, h;
int a[N];
vi v[N];

int main(void){
	scanf("%d%d", &n, &h);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			v[i].pb(a[j]);
		}
		sort(v[i].begin(), v[i].end());
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		ll H = 0;
		for(int j = i; j >= 0; j -= 2){
			H += v[i][j];
		}
		if(H <= h){
			ans = i+1;
		}
	}

	printf("%d\n", ans);

	return 0;
}