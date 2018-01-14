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

const int N = 300002;
int n, q;
int h[N];
set<int> s;

int main(void){
	scanf("%d", &n);

	int x, y;
	for(int i = 0; i < n; i++){
		scanf("%d", &h[i]);	
		s.insert(i);
	}

	scanf("%d", &q);

	int alive = n;
	for(int i = 0; i < q; i++){
		scanf("%d%d", &x, &y);

		vi to_delete;
		for(int j : s){
			if((j&x) == j and h[j] > 0){
				h[j] -= y;
				if(h[j] <= 0)
					to_delete.pb(j);
			}
		}

		for(int a : to_delete){
			alive--;
			s.erase(a);
		}

		printf("%d\n", alive);
	}
	return 0;
}