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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002;
int n;
int imp, par;

int main(void){
	scanf("%d", &n);

	int x;
	For(i,0,n){
		scanf("%d", &x);
		if(x%2) imp++;
		else par++;
	}

	if(imp) printf("First\n");
	else printf("Second\n");

	return 0;
}