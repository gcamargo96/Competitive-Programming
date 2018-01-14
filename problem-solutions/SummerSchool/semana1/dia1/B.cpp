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

#define L 0
#define R 1

int n, x;
set<int> l, r;

int main(void){
	scanf("%d%d", &n, &x);
	
	int pos, tipo, meio = -1;
	bool foi = 0;
	For(i,0,n){
		scanf("%d%d", &pos, &tipo);
		if(!tipo) r.insert(pos);
		else l.insert(pos);
	}

	int dir = L, res = 0;
	pos = x;
	while(!l.empty() or !r.empty()){
		if(dir == L){
			auto it = r.upper_bound(pos);
			if(it != r.begin()){
				it--;
				pos = *it;
				r.erase(it);
			}
			else{
				pos = 0;
				res++;
			}
			dir = R;
		}
		else{ // dir == R
			auto it = l.upper_bound(pos);
			if(it != l.end()){
				//it--;
				pos = *it;
				l.erase(it);
			}
			else{
				break;
			}
			dir = L;
		}
	}

	//printf("%d %d\n", l.size(), r.size());
	if(l.empty() and r.empty()){
		if(dir == L) res++;
		printf("%d\n", res);
	}
	else{
		printf("-1\n");
	}

	return 0;
}

