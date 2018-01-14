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

const int N = 1000002;
int t, n, k;
string s;
int cnt[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		memset(cnt, 0, sizeof cnt);
		cin >> n >> k >> s;
		s += '#';
		
		if(n == 1 or n == 2){
			cout << 1 << endl;
			continue;
		}

		int i = 0;
		while(i < n){
			int j;
			for(j = i; s[j] == s[j+1]; j++){}

			cnt[j-i+1]++;
			if(i == j) j++;
			i = j;
		}

		int c = 0;
		for(int i = 1000000; i > 2 and c < k; i--){
			int j;
			for(j = 0; j < cnt[i]; j++){
				if(i%2 == 1){
					cnt[i/2] += 2;
				}
				else{
					cnt[i/2-1]++;
					cnt[i/2]++;
				}
				cnt[1]++;
				c++;
			}
			cnt[i] -= j;
		}

		for(int i = 1000000; i >= 1; i--){
			if(cnt[i]){
				cout << i << endl;
				break;
			}
		}
	}


	return 0;
}

