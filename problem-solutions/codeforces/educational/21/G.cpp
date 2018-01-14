#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

string str, s, t;
int kmp[N];
int nxt[N][26];

int main(void){
	cin >> str >> t;

	s = t;
   	s += "#";
   	s += str;
	
	int n = s.length();
	int m = t.length();
	int len = 0;

	kmp[0] = -1;
	int i=0,j=-1;
	while(i<n){
		while(j>=0 && s[i]!=s[j])j=kmp[j];
			++i;
			++j;
			kmp[i]=j;
	}
	for(int i = 0; i < n; i++){
		kmp[i] = kmp[i+1];
	}
	kmp[n] = 0;

	/*for(int i = 0; i <= n; i++){
		printf("%d ", kmp[i]);
	}
	printf("\n");
	*/

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 26; j++) {
			if (t[i] - 'a' == j) {
				nxt[i][j] = i + 1;
			} else if (i > 0) {
				nxt[i][j] = nxt[kmp[i - 1]][j];
			}
		}
	}

	vector<vector<int> > dp(n-m+5);
	for(int i = 0; i < n-m+5; i++){
		dp[i].resize(m+5);
		for(int j = 0; j < m+5; j++) dp[i][j] = 0;
	}
		
		
	for(int i = n-1; i > m; i--){
		for(int j = 0; j < m; j++){
			if(s[i] == '?'){
				for(int c = 0; c < 26; c++){
					int newj = nxt[j][c];
					if(newj == m){
						newj = kmp[m-1];
						dp[i-m-1][j] = max(dp[i-m-1][j], 1 + dp[i-m-1+1][newj]);
					}
					else{
						dp[i-m-1][j] = max(dp[i-m-1][j], dp[i-m-1+1][newj]);
					}
				}	
			}
			else{
				int newj = nxt[j][s[i]-'a'];
				if(newj == m){
					newj = kmp[m-1];
					dp[i-m-1][j] = max(dp[i-m-1][j], 1 + dp[i-m-1+1][newj]);
				}
				else{
					dp[i-m-1][j] = max(dp[i-m-1][j], dp[i-m-1+1][newj]);
				}
			}
		}
	}

	cout << dp[0][0] << endl;
	
	return 0;
}
