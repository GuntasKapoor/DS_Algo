#include<bits/stdc++.h>
using namespace std;
int max(int arr[], int n) {
	map<int,pair<int,int>> count;
    
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    count[0]=p;
    
    int count0 = 0;
    int count1 = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else{
            count1++;
        }
        count[i+1] = make_pair(count1,count0);
    }
    
    int i = 0;
    int j = n-1;
    int ans;
    while(i<j){
        count1 = count[j+1].first - count[i].first;
        count0 = count[j+1].second - count[i].second;
        if(count1>count0){
            if(arr[i]==1){
                i++;
            }
            else if(arr[j]==1){
                j--;
            }
            else{
                int x = i+1;
                int y = j-1;
                while(x<y){
                    if(arr[x]==1){
                        i = x;
                        break;
                    }
                    if(arr[y]==1){
                        j = y;
                        break;
                    }
                    x++;
                    y--;
                }
            }
        }
        else if(count0>count1){
            if(arr[i]==0){
                i++;
            }
            else if(arr[j]==0){
                j--;
            }
            else{
                int x = i+1;
                int y = j-1;
                while(x<y){
                    if(arr[x]==0){
                        i = x;
                        break;
                    }
                    if(arr[y]==0){
                        j = y;
                        break;
                    }
                    x++;
                    y--;
                }
            }            
        }
        else{
            ans = j - i + 1;
            break;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    int arr[1000000];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int ans = max(arr,n);
    cout<<ans;
}