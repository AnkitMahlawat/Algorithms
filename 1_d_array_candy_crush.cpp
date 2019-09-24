#include <bits/stdc++.h>
using namespace std;
bool check(pair<int,int> t){
    return t.first<=t.second;
}
void candyc(list<int>&arr){
    vector<pair<int,int>> s;vector<std::list<int>::iterator> v;
    for(auto it=arr.begin();it!=arr.end();it++){
        cout<<*it<<" ";
        int size = s.size();
        if(size==0||*it==s.back().first){
            if(size==0){
                s.push_back({*it,1});
                v.push_back(it);
            }else{
                s[size-1].second++;
            }
        }else{
            if(check(s[size-1])){
                arr.erase(v.back(),it);
                s.pop_back();
                v.pop_back();
                it--;
            }else{
                s.push_back({*it,1});
                v.push_back(it);
            }
        }
    }
    cout<<endl;
    while(true){
        if(s.size()!=0&&check(s[arr.size()-1])){
            arr.erase(v.back(),arr.end());
            s.pop_back();
            v.pop_back();
        }else{
            break;
        }
    }
}
int main(){
    int n,temp;
    cin>>n;
    std::list<int> arr;
    for (int i = 0; i < n; i++) {
        cin>>temp;
        arr.push_back(temp);
    }
    candyc(arr);
    for(auto elem:arr){
        cout<<elem<<" ";
    }
    return 0;
}

