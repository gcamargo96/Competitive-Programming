#include <bits/stdc++.h>
using namespace std;
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

const int N = 602;
int cnt[N];
int n;

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}

	int ans = 0;
	for(int i = 600; i > 0; i--){
		if(cnt[i] > 0)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}