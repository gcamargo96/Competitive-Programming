#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int t, n;

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d", &n);

		int x;
		for(int i = 0; i < n+1; i++){
			scanf("%d", &x);
		}

		if(n%2 == 0){
			printf("Case #%d: 0\n", caso);
		}
		else{
			printf("Case #%d: 1\n", caso);
			printf("0.0\n");
		}
	}

	return 0;
}