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

int s, v1, v2, t1, t2;

int main(void){
	scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);

	int p1 = 2*t1 + s*v1;
	int p2 = 2*t2 + s*v2;

	if(p1 == p2){
		printf("Friendship\n");
	}
	else if(p1 < p2){
		printf("First\n");
	}
	else{
		printf("Second\n");
	}

	return 0;
}