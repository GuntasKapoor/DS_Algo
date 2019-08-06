bool ispossible(long long int mid,vector<int> A,int B){
    int cnt = 1;
    long long int cum = 0;
    for(long long int i=0;i<A.size();){
        cum+=(long long int)A[i];
        if(cum>mid){
            cnt++;
            cum = 0;
        }
        else{
            i++;
        }
    }
    if(cnt<=B){
        return true;
    }
    return false;
}
int Solution::books(vector<int> &A, int B) {
    if(A.size()<B){
        return -1;
    }
    long long int start = INT_MIN;
    long long int end = 0;
    for(long long int i=0;i<A.size();i++){
        start = max(start, (long long int)A[i]);
        end += (long long int)A[i];
    }
    int ans;
    while(start<=end){
        long long int mid = (start + end)/2;
        if(ispossible(mid,A,B)){
            ans = min((long long int)ans,mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
