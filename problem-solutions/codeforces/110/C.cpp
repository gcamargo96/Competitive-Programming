#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int solve(int i, int j){
	int dif = 0;

	if(j > 0) dif += j;

	while(j < s2.size()){
		if(i >= s1.size()){
			dif++;
		}
		else if(s1[i] != s2[j]){
			dif++;
		}
		i++;
		j++;
	}

	return dif;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s1 >> s2;

	int res = 99999;
	for(int i = s2.size()-1; i >= 0; i--){
		res = min(res, solve(0, i));
	}

	for(int i = 0; i < s1.size(); i++){
		res = min(res, solve(i, 0));
	}

	cout << res << endl;

	return 0;
}
