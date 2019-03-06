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

const int N = 200005;
int cnt[N];
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int sum = v[i]+v[j];
			cnt[sum]++;
		}
	}

	int ans = 0;
	for(int i = 0; i < N; i++){
		ans = max(ans, cnt[i]);
	}

	printf("%d\n", ans);

	return 0;
}