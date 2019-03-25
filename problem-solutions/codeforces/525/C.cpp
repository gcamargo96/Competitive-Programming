#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 2005;
int n;
int a[N];

int main(){
    scanf("%d",&n);

    for (int i=0;i<n;i++){
 	   scanf("%d",&a[i]);
    }

    printf("%d\n",n+1);
    
    int sum=0;
    for (int i=n-1;i>=0;i--){
        int add=(i-(a[i]+sum)%n+n)%n;
        printf("1 %d %d\n",i+1,add);
        sum+=add;
    }
    
    printf("2 %d %d",n,n);
}