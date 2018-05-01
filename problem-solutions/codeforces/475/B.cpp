#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 1005;
int n, a, b, c, t;
int v[N];

int main(void){
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &t);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	int ans = 0;
	if(b >= c){
		ans = n*a;
	}
	else{
		int cnt = 0;
		for(int i = 1; i < t; i++){
			for(int j = 0; j < n; j++){
				if(v[j] == i){
					cnt++;
				}
			}
			ans += cnt*c;
		}
		for(int i = 0; i < n; i++){
			ans += a - (t-v[i])*b;
		}
	}

	printf("%d\n", ans);

	return 0;
}