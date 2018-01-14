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

int n;
int cnt[102];

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}

	int ans = 0;
	vector<int> v;
	for(int i = 1; i <= 100; i++){
		if(cnt[i] == n/2){
			ans++;
			v.pb(i);
		}
	}

	if(ans == 2){
		printf("YES\n");
		printf("%d %d\n", v[0], v[1]);
	}
	else{
		printf("NO\n");
	}

	return 0;
}