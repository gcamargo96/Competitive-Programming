#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int A, D, M;
int g, p, b;

void no(){
	printf("NO\n");
	exit(0);
}

int main(void){
	scanf("%d%d%d", &A, &D, &M);
	scanf("%d%d%d", &g, &p, &b);

	g -= A;
	if(g < 0) no();

	int d = min(D, g);
	D -= d;
	g -= d;

	d = min(D, p);
	D -= d;
	p -= d;

	if(D > 0) no();

	if(g+p+b >= M){
		printf("YES\n");
	}
	else{
		no();
	}

	return 0;
}