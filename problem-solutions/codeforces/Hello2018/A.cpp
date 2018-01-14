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

int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	if(n >= 27){
		printf("%d\n", m);
		return 0;
	}

	int pot = 1;
	for(int i = 0; i < n; i++){
		pot *= 2;
	}

	printf("%d\n", m%pot);

	return 0;
}