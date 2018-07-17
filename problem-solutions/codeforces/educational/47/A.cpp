#include <bits/stdc++.h>
using namespace std;
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

const int N = 1005;
int c[N], a[N];
int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}

	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
	}

	int j = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(j < m and a[j] >= c[i]){
			// printf("%d %d\n", i, j);
			ans++;
			j++;
		}
	}

	printf("%d\n", ans);


	return 0;
}