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
int t, n;
int v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		For(i,0,n){
			scanf("%d", &v[i]);
		}

		sort(v, v+n);

		if(v[1] != v[0]+1 and v[2] == v[1]+1){
			printf("%d\n", v[0]);
			continue;
		}
		For(i,1,n-1){
			if(v[i+1] != v[i]+1){
				printf("%d\n", v[i+1]);
				break;
			}
		}
	}

	return 0;
}

