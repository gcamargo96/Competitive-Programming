#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int t, n, p;
int v[N];
int cnt[N];
int dp[N][N];

int solve(int pos, int resto){
	if(pos == p){
		if(resto == 0){
			//printf("resto = 0\n");
			return -1;
		}
		return 0;
	}
	if(dp[pos][resto] != -1) return dp[pos][resto];
	int ret = 0, add = 0;
	if(cnt[pos] > 0){
		for(int i = 0; i <= cnt[pos]; i++){
			int resto2 = resto + i*pos;
			add += (resto2%p == 0 ? 1 : 0);
			ret = max(ret, solve(pos+1, resto2%p) + add);
		}
	}
	else{
		ret = solve(pos+1, resto);
	}
	//ret += (resto == 0 ? 1 : 0);

	return dp[pos][resto] = ret;
}

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		memset(cnt, 0, sizeof cnt);
		scanf("%d%d", &n, &p);
		
		int x, dif = 0;
		For(i,0,n){
			scanf("%d", &x);
			//if(cnt[x%p] == 0) dif++;
			cnt[x%p]++;
		}

		int res = 0, put = 0;
		//if(dif > 2){
			For(i,1,p){
				if(i != p-i and cnt[i] and cnt[p-i]){
					//printf("%d + %d\n", i, p-i);
					int add = min(cnt[i], cnt[p-i]);
					put += add*2;
					res += add;
					cnt[i] -= add;
					cnt[p-i] -= add;
					//res++;
					break;
				}
			}
		//}

		put += cnt[0];
		res += cnt[0];	
		cnt[0] = 0;

		For(i,1,p){
			if(i != p-i and cnt[i] and cnt[p-i]){
				//printf("%d + %d\n", i, p-i);
				int add = min(cnt[i], cnt[p-i]);
				put += 2*add;
				res += add;
				cnt[i] -= add;
				cnt[p-i] -= add;
			}
		}

	
		memset(dp, -1, sizeof dp);	
		res += solve(0,0) + 1;
	
		printf("Case #%d: %d\n", caso, res);
	}

	return 0;
}

