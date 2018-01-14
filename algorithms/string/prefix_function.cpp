#include <bits/stdc++.h>
using namespace std;

// prefix function will be 1-based
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
