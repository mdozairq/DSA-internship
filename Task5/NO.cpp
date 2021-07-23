#include<bits/stdc++.h>
using namespace std;
    string flipCoins(int N, string s){
        bool flag;
            if(N==1){
            if(s.at(0)=='0')
            {
                return "Yes";
            }
            else{
                return "No";
            }
        }
        else{
            for(int i=0;i<s.size()-1;i++){
                if(s.substr(i,2)=="10"||s.substr(i,2)=="01"){
                    flag=0;
                }
                else 
                {
                    s=s.replace(i,2,"11");
                    //cout<<s<<endl;
                }
            }

            for(int i=0;i<s.size();i++){
                //cout<<s.at(i)<<endl;
                if(s.at(i)=='0')
                {
                    flag=0;
                    break;
                }
                else
                flag=1;
            }
            if(flag==1)
                return "Yes";
            else
                return "No";
        }
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<flipCoins(n,s);
}
