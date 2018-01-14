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

string a, b, ans, s;
int cnt[12];

bool solve(int i, bool flag){
	if(i == a.size()){
		ans = s;
		return 1;
	}

	bool ok = 0;
	if(flag == 0){
		for(int j = b[i]-'0'; j >= 0; j--){
			if(j == b[i]-'0'){
				if(cnt[j] > 0){
					s += j+'0';
					cnt[j]--;
					ok |= solve(i+1, 0);
					cnt[j]++;
					s.pop_back();
				}
			}
			else if(cnt[j] > 0){
				s += j+'0';
				cnt[j]--;
				ok |= solve(i+1, 1);
				cnt[j]++;
				s.pop_back();
			}
			if(ok) break;
		}
	}
	else{ // flag == 1
		for(int j = 9; j >= 0; j--){
			if(cnt[j] > 0){
				s += j+'0';
				cnt[j]--;
				ok |= solve(i+1, 1);
				cnt[j]++;
				s.pop_back();
			}
			if(ok) break;
		}
	}

	return ok;
}

int main(void){
	fastcin;
	cin >> a >> b;

	if(a.size() < b.size()){
		sort(a.begin(), a.end());
		for(int i = int(a.size())-1; i >= 0; i--){
			cout << a[i];
		}
		cout << endl;
	}
	else{
		for(int i = 0; i < a.size(); i++){
			cnt[a[i]-'0']++;
		}

		solve(0, 0);

		cout << ans << endl;
	}

	return 0;
}