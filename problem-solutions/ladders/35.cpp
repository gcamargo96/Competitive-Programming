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
int n, m;
int t, l, r;
int v[N], s[N];
ll v2[N], s2[N];

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		s[i] = v[i];
	}

	sort(s+1, s+n+1);

	for(int i = 1; i <= n; i++){
		v2[i] = v2[i-1] + v[i];
		s2[i] = s2[i-1] + s[i];
	}

	scanf("%d", &m);

	For(i,0,m){
		scanf("%d%d%d", &t, &l, &r);
		
		if(t == 1){
			printf("%I64d\n", v2[r]-v2[l-1]);
		}
		else{
			printf("%I64d\n", s2[r]-s2[l-1]);
		}
	}

	return 0;
}

