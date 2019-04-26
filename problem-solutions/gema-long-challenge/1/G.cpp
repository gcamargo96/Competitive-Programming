#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 300005;
string s[3];
int p[N];

void prefix_function(string& s){
	int n = s.size();
	for(int i = 2; i <= n; i++){
		p[i] = p[i-1];
		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}
}

int main(void){
	fastcin;
	while(cin >> s[0] >> s[1] >> s[2]){
		int min_size = INF;
		sort(s, s+3);

		do{
			string t = s[1] + "#" + s[0];
			prefix_function(t);

			bool contains = 0;
			for(int i = 1; i <= s[0].size(); i++){
				if(p[s[1].size()+1+i] == s[1].size()){
					contains = 1;
					break;
				}
			}

			string ans = s[0];
			if(!contains){
				int id = p[t.size()];
				for(int i = id; i < s[1].size(); i++){
					ans += s[1][i];
				}
			}

			t = s[2] + "#" + ans;
			prefix_function(t);

			contains = 0;
			for(int i = 1; i <= ans.size(); i++){
				if(p[s[2].size()+1+i] == s[2].size()){
					contains = 1;
					break;
				}
			}

			if(!contains){
				int id = p[t.size()];
				for(int i = id; i < s[2].size(); i++){
					ans += s[2][i];
				}
			}

			min_size = min(min_size, (int) ans.size());
		}while(next_permutation(s, s+3));
		
		cout << min_size << endl;
	}

	return 0;
}