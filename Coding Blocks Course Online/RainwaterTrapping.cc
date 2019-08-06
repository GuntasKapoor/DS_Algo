class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int left[height.size()+1];
        int right[height.size()+1];
        left[0]=height[0];
        for(int i=1;i<height.size();i++){
            left[i]=max(height[i],left[i-1]);
        }   
        int N = height.size();
        right[N-1]=height[N-1];
        for(int i=N-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<N;i++){
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
    }

    int method2(vector<int &height>){
        if(height.size()==0 || height.size()==1 || height.size()==2){
            return 0;
        }
        stack<int> st;
        int N = height.size();
        st.push(0);
        int ans = 0;
        for(int i=1;i<N;i++){

            while(!st.empty() && A[st.top()]<=A[i]){
                int tp = st.top();
                st.pop();
                if(!st.empty()){
                    ans+=(min(A[i], A[st.top()]) - A[tp])*(i-st.top()-1);
                }
            }
            st.push(i);
        }
    }
};