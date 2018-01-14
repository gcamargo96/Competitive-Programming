#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back
#define eb emplace_back
#define BEG 0
#define END 1
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int t;
string a, b;
int ca[26], cb[26];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		memset(ca, 0, sizeof ca);
		memset(cb, 0, sizeof cb);
		cin >> a >> b;

		if(a.size() == 1){
			cout << "B" << endl;
			continue;
		}

		for(int i = 0; i < a.size(); i++){
			ca[a[i]-'a']++;
			cb[b[i]-'a']++;
		}

		char ans = 'B';
		for(int i = 0; i < 26; i++){
			if(ca[i] > 1 and cb[i] == 0){
				ans = 'A';	
				break;
				/*ca[i]--;
				bool A_nao_tem = 0;			
				for(int j = 0; j < 26; j++){
					if(cb[j] > 0 and ca[j] == 0){
						A_nao_tem = 1;	
					}
				}

				if(A_nao_tem){
					ans = 'B';
					break;
				}
				else{
					ans = 'A';
					break;
				}
				ca[i]++;
				*/
			}
		}

		if(ans == 'B'){
			for(int i = 0; i < 26; i++){
				if(ca[i] == 1){
					ca[i]--;

					bool A_tem = 1;
					for(int j = 0; j < 26; j++){
						if(cb[j] > 0 and ca[j] == 0){
							A_tem = 0;
						}
					}

					if(A_tem == 1){
						ans = 'A';
						break;
					}

					ca[i]++;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}