#include <cstdio>
#include <iostream>
#include <string>

#define B 33

using namespace std;

typedef long long ll;
int a, b, c, d, n;
ll mod[2] = {1000000007, 1000000009};
ll h[2][10000000];
ll pot[2][10000000];

void precalc(string &s){
    for(int k = 0; k < 2; k++){
        h[k][0] = s[0] - 'A' + 1;
        pot[k][0] = 1;

        for(int i = 1; i < s.size(); i++){
            h[k][i] = (h[k][i-1]*B)%mod[k] + (s[i] - 'A' + 1)%mod[k];
            pot[k][i] = (pot[k][i-1]*B)%mod[k];
        }
    }
}

ll calcHash(int i, int j, int k){
    if(i == 0) return h[k][j];
    return (h[k][j] - (h[k][i-1]*pot[k][j-i+1])%mod[k] + mod[k])%mod[k];
}

int main(void){
	string s;
	cin >> s >> n;

	precalc(s);

	ll h1, h2, h3, h4;

	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d); // verify if two substrings are equals
        // 0 <= a <= b <= s.size()-1 / 0 <= c <= d <= s.size()-1
        h1 = calcHash(a, b, 0);
        h2 = calcHash(a, b, 1);
        h3 = calcHash(c, d, 0);
        h4 = calcHash(c, d, 1);

        if(h1 == h3 && h2 == h4){
            printf("EQUALS\n");
        }else{
            printf("NOT EQUALS\n");
        }
	}

	return 0;
}
