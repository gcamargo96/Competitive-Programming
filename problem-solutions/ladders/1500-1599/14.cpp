#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int t, x;

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &x);
		int ang = 180-x;
		if(360%ang == 0) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

