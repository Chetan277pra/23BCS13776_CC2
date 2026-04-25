#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int base = 31;
#define ll long long
int hashfun(string &s){
    int n = s.length();
    ll hash = 0;
    ll power = 1;

    for(int i = 0; i < n; i++){
        int val = s[i] - 'a' + 1;
        hash = (hash + val * power) % mod;
        power = (power * base) % mod;
    }
    return hash;
}

int main(){
    string s;
    cin >> s;
    cout << hashfun(s);
    return 0;
}
