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

const int N = 200005;
int n, k;
char s[N];
int sum[27][N];

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf(" %c", &s[i]);
	}

	for(char c = 'a'; c <= 'z'; c++){
		for(int i = 1; i <= n; i++){
			sum[c-'a'][i] = sum[c-'a'][i-1] + (s[i] == c);
		}
	}

	int ans = 0;
	for(char c = 'a'; c <= 'z'; c++){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			int j = i+k-1;

			if(j > n) break;

			if(sum[c-'a'][j] - sum[c-'a'][i-1] >= k){
				cnt++;
				i += k-1;
			}
		}
		ans = max(ans, cnt);
	}

	printf("%d\n", ans);

	return 0;
}