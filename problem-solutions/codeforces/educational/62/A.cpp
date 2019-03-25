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

const int N = 10005;
int a[N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	int ans = 0, nxt = 0;
	for(int i = 1; i <= n; i++){
		nxt = max(nxt, a[i]);
		if(nxt <= i){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}