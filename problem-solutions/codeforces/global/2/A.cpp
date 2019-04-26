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

const int N = 300005;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int ans = 0;
	for(int j = n-1; j > 0; j--){
		if(v[0] != v[j]){
			ans = j;
			break;
		}
	}

	for(int i = 0; i < n; i++){
		if(v[i] != v[n-1]){
			ans = max(ans, n-1-i);
		}
	}

	printf("%d\n", ans);

	return 0;
}