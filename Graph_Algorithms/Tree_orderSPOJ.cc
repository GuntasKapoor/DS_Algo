#include <iostream>
using namespace std;

bool isBinaryTree(int preorder[], int postorder[], int inorder[],int preS,int preE, int postS, int postE,int inS, int inE){
	
	if(preS > preE && inS > inE && postS > postE){
		return true;
	}
	
	if((preE - preS)!=(postE - postS) || (preE - preS)!=(inE-inS) || (postE - postS)!=(inE - inS)){
		return false;
	}
	if(preorder[preS]!=postorder[postE]){
		return false;
	}
	
	int inlS = inS;
	int postlS = postS;
	int rootidx = -1;
	for(int i = inS; i <= inE; i++){
		if(inorder[i] == preorder[preS]){
			rootidx = i;
			break;
		}
	}
	
	if(rootidx == -1){
		return false;
	}
	int inlE = rootidx - 1;
	int postlE = postlS + (inlE - inlS);
	
	int inrS = rootidx + 1;
	int inrE = inE;
	int postrS = postlE + 1;
	int postrE = postE - 1;
	int prelS = preS + 1;
	int prelE = prelS + (inlE - inlS);
	int prerS = prelE + 1;
	int prerE = preE;
	bool left = isBinaryTree(preorder, postorder, inorder, prelS, prelE, postlS, postlE, inlS, inlE );
	bool right = isBinaryTree(preorder,postorder, inorder, prerS, prerE, postrS, postrE, inrS, inrE);
	return left&&right;
}



int main() {
	int N;
	int inorder[8001],preorder[8001],postorder[8001];
	cin>>N;
	for(int i = 0; i < N; i++){
		cin>>preorder[i];
	}
	for(int i = 0; i < N; i++){
		cin>>postorder[i];
	}
	for(int i = 0; i < N; i++){
		cin>>inorder[i];
	}
	
	bool check = isBinaryTree(preorder, postorder, inorder,0,N-1,0,N-1,0,N-1);
	if(check){
		cout<<"yes"<<endl;
	}
	else{
		cout<<"no"<<endl;
	}
	return 0;
}