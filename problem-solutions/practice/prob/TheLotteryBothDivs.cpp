#include <bits/stdc++.h>
using namespace std;

bool isSuffix(string a, string b){
	if(a.size() < b.size()) return 0;
	for(int i = 0; i < b.size(); i++){
		if(a[a.size()-1-i] != b[b.size()-1-i]){
			return 0;
		}
	}
	return 1;
}

double find(vector<string> goodSuffixes){
 	sort(goodSuffixes.begin(), goodSuffixes.end());
 	goodSuffixes.resize(unique(goodSuffixes.begin(), goodSuffixes.end()) - goodSuffixes.begin());

 	 for(int i = 0; i < goodSuffixes.size(); i++){
 		cout << goodSuffixes[i] << " ";
 	}
 	cout << endl;


 	bool flag[goodSuffixes.size()];
 	memset(flag, 0, sizeof flag);

 	for(int i = 0; i < goodSuffixes.size(); i++){
 		for(int j = 0; j < goodSuffixes.size(); j++){
 			if(i != j and isSuffix(goodSuffixes[i], goodSuffixes[j])){
 				flag[i] = 1;
 			}
 		}
 	}

 	for(int i = 0; i < goodSuffixes.size(); i++){
 		cout << flag[i] << " ";
 	}
 	cout << endl;

 	double ans = 0;
 	double num = 0;

 	double pot[] = {1, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.0000000001, 0.00000000001};

 	for(int i = 0; i < goodSuffixes.size(); i++){
 		if(flag[i]) continue;

 		string suffix = goodSuffixes[i];
 		
 		// ans += pow(10,9-cnt)/1e9;
 		num += pot[suffix.size()];
 	}

 	return num;
}

int main(void){
	int n; cin >> n;

	vector<string> v;
	while(n--){
		string s; cin >> s;
		v.push_back(s);
	}

	cout << fixed << setprecision(10) << find(v) << endl;

	return 0;
}