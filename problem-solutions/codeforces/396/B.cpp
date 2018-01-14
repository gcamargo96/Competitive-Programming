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
int n;
ll v[N];

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lld", &v[i]);
	}

	sort(v, v+n);

	bool ok = 0;	
	For(i,2,n){
		if(v[i-2] + v[i-1] > v[i]){
			ok = 1;
			break;
		}
	}

	if(ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}

