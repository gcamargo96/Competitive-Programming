#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 200005;
// priority_queue<int, vector<int>, greater<int> > pqi;
priority_queue<ii, vector<ii>, greater<ii> > pqi;
priority_queue<ii> pqe;
int n;

int main(void){
	scanf("%d", &n);

	int w;
	for(int i = 1; i <= n; i++){
		scanf("%d", &w);
		pqi.push(ii(w, i));
	}

	char c;
	for(int i = 0; i < 2*n; i++){
		scanf(" %c", &c);

		if(c == '0'){ // introvert
			ii cur = pqi.top();
			pqe.push(cur);
			pqi.pop();
			printf("%d ", cur.se);
		}
		else{
			ii cur = pqe.top();
			printf("%d ", cur.se);
			pqe.pop();
		}
	}
	printf("\n");

	return 0;
}