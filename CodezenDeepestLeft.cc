// Following is the Binary Tree node structure
// *************
#include<bits/stdc++.h>
template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
// **************

// Following is the Binary Tree node structure
/**************
 class BinaryTreeNode {
 public :
 T data;
 BinaryTreeNode<T> *left;
 BinaryTreeNode<T> *right;
 
 BinaryTreeNode(T data) {
 this -> data = data;
 left = NULL;
 right = NULL;
 }
 };
 ***************/
#include<unordered_map>
using namespace std;
bool helper2(BinaryTreeNode<int> * root, BinaryTreeNode<int> * curr, int X, unordered_map<int,bool> mp){
    
    if(root == NULL){
        return false;
    }
    
  if(root != curr){
    int data = root->data;
   if(X - data > 0){
    if(mp[X - data]){
        return true;
    }
    else{
        mp[data] = true;
    }
   }
  }
    return helper2(root->left, curr, X,mp) || helper2(root->right, curr, X,mp);
}


bool helper1(BinaryTreeNode<int> * root, BinaryTreeNode<int> * current, int X){
    if(current == NULL){
        return false;
    }
    if(X - current->data > 0){
    unordered_map<int, bool> mp;
    bool ans = helper2(root, current, X - current->data,mp);
    if(ans){
        return true;
    }
    }
    bool left = helper1(root, current->left, X);
    bool right = helper1(root, current->right, X);
    return left || right;
}


void checkTriplet(BinaryTreeNode<int>* root, int X){
    
    if(root == NULL){
        return;
    }
    bool ans = helper1(root, root, X);
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
