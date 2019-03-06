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

const int N = 100005;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	int mx = -1, len = 0, ans = 1;
	v[0] = -1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);

		if(v[i] > mx){
			mx = v[i];
		}
	}

	for(int i = 1; i <= n; i++){
		int len = 0;
		while(i <= n and v[i] == mx){
			len++;
			i++;
		}
		ans = max(ans, len);
	}

	printf("%d\n", ans);

	return 0;
}