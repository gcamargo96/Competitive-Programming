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

int a, b;
int c;
bool vis[10];

int main(void){
	scanf("%d%d%d", &a, &b, &c);

	for(int i = 0; i < b; i++){
		a *= 10;
		int q = a/b;
		
		if(q == c){
			printf("%d\n", i+1);
			return 0;
		}

		a %= b;
	}

	printf("-1\n");

	return 0;
}