#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[100005];
char r[100005];

int main(void){
	scanf("%d%d", &n, &k);
	scanf("%s", s);

	int falta = k, i = 0, flag;

	while(falta > 0 and i < n){
		int dif;
		if(s[i]-'a' > 'z'-s[i]){
			flag = 1;
			dif = s[i]-'a';
		}
		else{
			flag = 2;
			dif = 'z'-s[i];
		}
		
		if(dif < falta){
			if(flag == 1){
				r[i] = 'a';
			}
			else r[i] = 'z';
		}
		else{
			if(flag == 1){
				r[i] = s[i]-falta;
			}
			else r[i] = s[i]+falta;
		}
		falta -= dif;
		i++;
	}
	while(i < n){
		r[i] = s[i];
		i++;
	}

	r[n] = '\0';

	if(falta <= 0) printf("%s\n", r);	
	else printf("-1\n");

	return 0;
}
