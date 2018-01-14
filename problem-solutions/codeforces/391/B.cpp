#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
vi grupo[N];
int cnt[N], vis[N];
int n;

void sieve(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			grupo[i].pb(i);
			vis[i] = 1;
			for(int j = i+i; j < N; j += i){
				grupo[j].pb(i);
				vis[j] = 1;
			}
		}
	}
}

int main(void){
	sieve();
	scanf("%d", &n);

	int x;
	For(i,0,n){
		scanf("%d", &x);
		For(j,0,grupo[x].size()){
			cnt[grupo[x][j]]++;
		}
	}

	int res = 1;
	for(int i = 2; i < N; i++){
		//printf("cnt[%d] = %d\n", i, cnt[i]);
		res = max(res, cnt[i]);
	}

	printf("%d\n", res);

	return 0;
}

