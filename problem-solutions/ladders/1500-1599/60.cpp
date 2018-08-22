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

int n;

int main(void){
	scanf("%d", &n);

	if(n%2 == 0){
		printf("white\n");
		printf("1 2\n");
	}
	else{
		printf("black\n");
	}
	
	return 0;
}

