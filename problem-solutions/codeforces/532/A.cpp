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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 105;
int n, k;
int v[N];

int main(void){
	scanf("%d%d", &n, &k);

	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i] == 1) a++;
		else b++;
	}

	int ans = 0;
	for(int i = 0; i < k; i++){
		int aa = a, bb = b;
		for(int j = i; j < n; j += k){
			if(v[j] == 1) aa--;
			else bb--;
		}
		// printf("%d %d\n", aa, bb);
		ans = max(ans, abs(aa-bb));
	}

	printf("%d\n", ans);

	return 0;
}