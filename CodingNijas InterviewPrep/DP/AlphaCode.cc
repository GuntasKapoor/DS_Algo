#include <bits/stdc++.h>
using namespace std;


int comb(string str,int i){
    if(i == str.length()){
        return 1;
    }
    
    int ans = 0;
    ans += comb(str,i + 1);
    if(str[i+1]!='\0'){
    string h = "";
    h += str[i];
    h += str[i+1];
    if(stoi(h)<=26){
        ans += comb(str, i + 2);
    }
}
    return ans;
}


int main()
{
    
    return 0;
}
