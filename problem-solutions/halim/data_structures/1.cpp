#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int cnt[30000], v[3002];
int n;

int main(void){
	ios_base::sync_with_stdio(false);
	while(cin >> n){
		memset(cnt, 0, sizeof cnt);
		For(i,0,n){
			cin >> v[i];
		}

		For(i,0,n-1){
			cnt[abs(v[i]-v[i+1])]++;
		}

		bool res = 1;
		For(i,1,n){
			if(cnt[i] == 0){
				res = 0;
				break;
			}
		}

		if(res) cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}

	return 0;
}
