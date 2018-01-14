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

const int N = 300002;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	ll res = 0;
	For(i,0,n){
		res += abs(v[i]-(i+1));
	}

	printf("%I64d\n", res);

	return 0;
}

