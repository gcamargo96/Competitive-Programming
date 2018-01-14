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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002, M = 300002;
int n, m, k;
set<int> hole;

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	int x;
	For(i,0,m){
		scanf("%d", &x);
		hole.insert(x);
	}

	if(hole.count(1)){
		printf("1\n");
		return 0;
	}

	int u, v, bone = 1;
	bool caiu = 0;
	For(i,0,k){
		scanf("%d%d", &u, &v);
		if(u == bone){
			if(hole.count(v)){
				printf("%d\n", v);
				return 0;
			}
			else{
				bone = v;
			}
		}
		else if(v == bone){
			if(hole.count(u)){
				printf("%d\n", u);
				return 0;
			}
			else{
				bone = u;
			}
		}
	}

	printf("%d\n", bone);

	return 0;
}

