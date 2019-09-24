int histarea(vector<int>v){
    //max area in histogram
    int size = v.size(),max=0,xc;
    stack<pair<int,int> > s;
    pair<int,int> temp;
    for(int i=0;i<size;i++){
        if(s.size()==0||s.top().first<=v[i]){
            s.push({v[i],i});
        }else{
            while(s.size()!=0&&s.top().first>v[i]){
                temp = s.top();
                s.pop();
                if(s.size()==0) xc = -1;
                else xc = s.top().second;
                if(temp.first*(i-xc-1)>max){
                    max = temp.first*(i-xc-1);
                }
            }
            s.push({v[i],i});
        }
    }
    int i=size;
    while(s.size()!=0){
        temp = s.top();
        s.pop();
        if(s.size()==0) xc = -1;
        else xc = s.top().second;
        if(temp.first*(i-xc-1)>max){
            max = temp.first*(i-xc-1);
        }
    }
    return max;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    if(A.size() == 0||A[0].size() == 0) return 0;
    int xc = A.size(),yc = A[0].size(),dp1,dp2;pair<int,int> r1,r2;
    vector<vector<int> > dp(xc,vector<int> (yc));
    for(int j=0;j<yc;j++){
        dp[0][j]=A[0][j];
    }
    for(int i=1;i<xc;i++){
        for(int j=0;j<yc;j++){
            if(A[i][j]==0){
                dp[i][j]=0;
            }else{
                dp[i][j]=dp[i-1][j]+1;
            }
        }
    }
    int max = 0,cur;
    for(int i=0;i<xc;i++){
        cur = histarea(dp[i]);
        if(max<cur){
            max = cur;
        } 
    }
    return max;
}

