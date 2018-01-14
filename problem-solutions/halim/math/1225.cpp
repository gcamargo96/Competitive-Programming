#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t, n;
int cnt[10];

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			int aux = i;
			while(aux > 0){
				cnt[aux%10]++;
				aux /= 10;
			}
		}

		for(int i = 0; i < 9; i++){
			printf("%d ", cnt[i]);
		}
		printf("\n");
	}

	return 0;
}