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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t;
int v[4];

int main(void){
	scanf("%d", &t);

	while(t--){
		for(int i = 0; i < 4; i++){
			scanf("%d", &v[i]);
		}

		sort(v, v+4);

		if(v[0] == v[1] and v[2] == v[3]){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}