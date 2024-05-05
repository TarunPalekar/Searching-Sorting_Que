#include<bits/stdc++.h>
using namespace std;
bool isPossibleSoultion(vector<int> cooksRanks, int np, int mid){
    int currp=0;
    for(int i=0;i<cooksRanks.size();i++){
        int timetaken=0;
        int R=cooksRanks[i], j=1;
        while(true){
            if(timetaken+j*R<=mid){
                ++currp;
                timetaken+=j*R;
                j++;
            }
            else{
                break;
            }
        }
        if(currp>=np){
            return true;
        }
    }
    return false;
}
int PrataSpoj(vector<int> cooksRanks, int np){
    int start=0;
    int highestRank=*max_element(cooksRanks.begin(), cooksRanks.end());
    int end= highestRank*(np*(np+1)/2);
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossibleSoultion(cooksRanks, np, mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;

}
int main(){
    int t;cin>>t;
    while(t--){
        int np, nc;
     vector<int> cooksRanks;
        cin>>np;
        cin>>nc;
        while(nc--){
            int r;
            cin>>r;
            cooksRanks.push_back(r);

        }
        cout<< PrataSpoj(cooksRanks, np);
    }
    return 0;
}