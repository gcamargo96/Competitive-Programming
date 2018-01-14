#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, c;
//int v
int x, ant;

int main(void){
	scanf("%d%d", &n, &c);

	scanf("%d", &ant);
	int cnt = 1;

	For(i,1,n){
		scanf("%d", &x);
		if(x-ant > c){
			cnt = 0;
		}
		cnt++;
		ant = x;
	}

	printf("%d\n", cnt);

	return 0;
}

