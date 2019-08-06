#include<bits/stdc++.h>
using namespace std;
char* findMinSubstringContainingString(char *large, char *small){
    
    unordered_map<char, int> smallcounts;
    unordered_map<char,int> largecounts;
    
    int len2 = 0;
    for(int i = 0; small[i]!='\0';i++){
        smallcounts[small[i]]++;
        len2++;
    }

    
    int startidx = -1;
    int minlength = INT_MAX;
    int start = 0;
    int count = 0;
    for(int i = 0; large[i]!='\0' ; i++){
        largecounts[large[i]]++;
        
        if(smallcounts[large[i]]!=0 && largecounts[large[i]]<=smallcounts[large[i]]){
            count++;
        }
        
        if(count == len2){
            
            while(largecounts[large[start]]>smallcounts[large[start]] || smallcounts[large[start]]==0){
                if(largecounts[large[start]]>smallcounts[large[start]]){
                    largecounts[large[start]]--;
                }
                start++;
            }
            
            int lenwindow = i - start + 1;
            if(minlength>lenwindow){
                minlength = lenwindow;
                startidx = start;
            }
            
        }
    }
    
    if(startidx == -1){
        return NULL;
    }
    else{
        int i;
        char S[10000];
        for(i = startidx ; i <= startidx + minlength;i++){
            S[i-startidx]=large[i];
        }
        S[i] = '\0';
        char * ptr=NULL;
        ptr = &S[0];
        return ptr;
    }

}

int main(){
    
}
