#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &mat,int r,int c,string &path,vector<string>& ans,int n){
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == -1 || mat[r][c] == 0)
        return;
        
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }
    mat[r][c] = -1;
    
    //down
    path.push_back('D');
    helper(mat,r+1,c,path,ans,n);
    path.pop_back();
    
    //left
    path.push_back('L');
    helper(mat,r,c-1,path,ans,n);
    path.pop_back();
    
    //up
    path.push_back('U');
    helper(mat,r-1,c,path,ans,n);
    path.pop_back();
    
    //right
    path.push_back('R');
    helper(mat,r,c+1,path,ans,n);
    path.pop_back();
    
    mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    int n = mat.size();
    string path = "";
    helper(mat,0,0,path,ans,n);
    return ans;
}

int main(){
   vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

   vector<string> res = findPath(mat);
   for(auto ele : res){
    cout<<ele<<"\n";
   }

    return 0;
}