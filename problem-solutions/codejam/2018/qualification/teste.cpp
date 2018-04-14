#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

int g[3][3];

bool complete(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(g[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

int main(void){
	srand(time(NULL));

	int cnt = 0;
	while(!complete()){
		int i = rand()%3;
		int j = rand()%3;
		g[i][j] = 1;
		cnt++;
	}

	printf("iterations = %d\n", cnt);

	return 0;
}