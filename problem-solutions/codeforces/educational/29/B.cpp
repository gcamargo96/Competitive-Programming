#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

int h1, a1, c1;
int h2, a2;

int main(void){
	scanf("%d%d%d", &h1, &a1, &c1);
	scanf("%d%d", &h2, &a2);

	int strikes = ceil((double)h2/(double)a1);
	int H = strikes*a2+1;
	int extra = H-h1;
	int hturns = ceil((double)extra/(double)(c1-a2));

	printf("%d\n", strikes + hturns);

	for(int i = 0; i < hturns; i++){
		printf("HEAL\n");
	}

	for(int i = 0; i < strikes; i++){
		printf("STRIKE\n");
	}

	return 0;
}