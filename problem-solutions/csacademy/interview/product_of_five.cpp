#include <bits/stdc++.h>
using namespace std;

bool compareModule(int a, int b){
    return abs(a) < abs(b);
}

bool canBePositive(vector<int>& v){
    int positiveCounter = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0) positiveCounter++;
    }
    return positiveCounter == 1 or positiveCounter == 3 or positiveCounter >= 5;
}

int productOfFive(vector<int>& v) {
    sort(v.begin(), v.end(), compareModule);
    
    int product = 1;
    for(int i = v.size()-5; i < v.size(); i++){
        product *= v[i];
    }
    
    if(product < 0){
        if(canBePositive(v)){    
            int smallestPositive = 100, smallestNegative = 100;
            for(int i = v.size()-1; i >= v.size()-5; i--){
                if(v[i] > 0) smallestPositive = v[i];
                if(v[i] < 0) smallestNegative = v[i];
            }
            
            int largestPositive = 100, largestNegative = 100;
            for(int i = 0; i < v.size()-5; i++){
                if(v[i] > 0) largestPositive = v[i];
                if(v[i] < 0) largestNegative = v[i];
            }
            
            int productWithPositive = -1000000000, productWithNegative = -1000000000;
            if(smallestPositive != 100 and largestNegative != 100){
                productWithNegative = product/smallestPositive * largestNegative;
            }
            if(smallestNegative != 100 and largestPositive != 100){
                productWithPositive = product/smallestNegative * largestPositive;
            }
            
            product = max(productWithPositive, productWithNegative);
        }
        else{
            product = 1;
            for(int i = 0; i < 5; i++){
                product *= v[i];
            }
        }
    }
    
    return product;
}
int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    cout << productOfFive(v) << "\n";
    return 0;
}
