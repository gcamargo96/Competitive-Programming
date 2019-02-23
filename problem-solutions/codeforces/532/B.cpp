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

const int N = 100005;
int n, m;
int v[N], cnt[N];

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d", &v[i]);
	}

	int diff = 0;
	for(int i = 0; i < m; i++){
		if(cnt[v[i]] == 0){
			diff++;
		}
		cnt[v[i]]++;

		if(diff == n){
			for(int j = 1; j <= n; j++){
				cnt[j]--;
				if(cnt[j] == 0) diff--;
			}

			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");

	return 0;
}