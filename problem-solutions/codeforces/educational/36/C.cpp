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

const int N = 20;
string a, b;
map<char,int> cnt;

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
			cnt[a[i]]++;
		}

		bool flag = 0;
		for(int i = 0; i < b.size(); i++){
			char c = 0;
			for(auto it = cnt.begin(); it != cnt.end(); ++it){
				if(!flag){
					if(it->fi <= b[i]){
						c = max(c, it->fi);
					}
				}
				else{
					c = max(c, it->fi);
				}
			}

			cnt[c]--;
			if(cnt[c] == 0){
				cnt.erase(c);
			}

			if(c < b[i]){
				flag = 1;
			}

			cout << c;
		}
		cout << endl;

		// for(int j = 0; j < a.size(); j++){
		// 	cout << vis[j];
		// }
		// cout << endl;

	}


	return 0;
}