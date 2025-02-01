#include<bits/stdc++.h>
using namespace std;

void printSubstr(string& str,int i,int n,string temp){
    if(i >= n){
        cout<<temp<<endl;
        return;
    }

    printSubstr(str,i+1,n,temp+=str[i]);
    
}

int main(){
    string str = "abc";
    printSubstr(str,0,3,"");
    return 0;
}