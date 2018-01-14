#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 300002;
int n, Q;
queue<ii> q;
int READ[N], READQ[N], total[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> Q;

	int t, x;
	int res = 0;
	int ord = 1;
	For(i,0,Q){
		cin >> t >> x;
		if(t == 1){
			q.push(mp(x,ord++));
			total[x]++;
			res++;
		}
		if(t == 2){
			res -= (total[x]-READ[x]);
			READ[x]  = total[x];
		}
		if(t == 3){
			int j = 0;
			while(!q.empty()){
				ii F = q.front();
				if(F.se > x) break;
				q.pop();
				
				if(READQ[F.fi] == READ[F.fi]){
					READ[F.fi]++;
					READQ[F.fi]++;
					res--;
				//	cout << F.fi << " ";
				}
				else{
					READQ[F.fi]++;
				}
				j++;
			}
				//cout << endl;
		}
		cout << res << endl;
	}

	return 0;
}
