#include <bits/stdc++.h>

using namespace std;
namespace kmp {
	char str[N], b[N];
	void prep() {
		n=strlen(str);
		b[0]=-1;
		int i=0,j=-1;
		while(i<n){
			while(j>=0 && str[i]!=str[j])j=b[j];
				++i;
				++j;
				b[i]=j;
			}
		}
};
