string flipCoins(int N, string s){
        bool flag=1;
        // Your code goes here
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
            for(int i=0;i<N-1;i++){
                if(s.substr(i,2)!="10"||s.substr(i,2)!="01"){
                    s=s.replace(i,2,"11");
                    //cout<<s<<endl;
                }
            }
            for(int i=0;i<N;i++){
                if(s.at(i)=='0'){
                    flag=0;
                }
            }
            if(flag==1)
                return "Yes";
            else
                return "No";
        }
}