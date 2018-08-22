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

const int N = 102;
int n, m;
int tot[N], used[N];

int main(void){
	scanf("%d%d", &n, &m);

	int x;
	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		tot[x]++;
	}
	
	if(n > m){
		printf("0\n");
		return 0;
	}

	for(int i = 0; i < n; i++){
		int id = -1, best = -1;
		for(int j = 1; j <= 100; j++){
			if(tot[j]-used[j] > 0 and tot[j]/(used[j]+1) > best){
				id = j;
				best = tot[j]/(used[j]+1);
			}
		}
		used[id]++;
	}

	int ans = 1000000;
	for(int i = 1; i <= 100; i++){
		if(used[i] > 0){
			ans = min(ans, tot[i]/used[i]);
		}
	}

	printf("%d\n", ans);

	return 0;
}