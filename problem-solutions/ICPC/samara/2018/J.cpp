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
int n;
int cnt[N];

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		cnt[x]++;
	}

	int ans = 0;
	for(int i = 1; i < N; i++){
		int aux = cnt[i]/4;
		ans += aux;
		cnt[i] -= 4*aux;
	}

	int sum = 0;
	for(int i = 1; i < N; i++){
		if(cnt[i] >= 2) sum++;
	}
	ans += sum/2;

	printf("%d\n", ans);

	return 0;
}