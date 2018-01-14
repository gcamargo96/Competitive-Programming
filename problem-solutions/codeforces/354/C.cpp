#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;

	int i, j, cnt = 0, maiorb = 0;
	for(j = 0; j < n; j++){
		if(s[j] == 'b') cnt++;
		//cout << cnt << k <<  endl;
		//else cnt--;
		while(cnt > k and i < j){
			//cout << "i " << i << " j " << j << endl;
			if(s[i] == 'b') cnt--;
			i++;
		}
		maiorb = max(maiorb, j-i+1);
	}

	int maiora = 0;
	cnt = 0, i = 0, j = 0;
	for(j = 0; j < n; j++){
		if(s[j] == 'a') cnt++;
		//else cnt--;
		while(cnt > k and i < j){
			if(s[i] == 'a') cnt--;
			i++;
		}
		maiora = max(maiora, j-i+1);
	}

	cout << max(maiora, maiorb) << endl;

	return 0;
}
