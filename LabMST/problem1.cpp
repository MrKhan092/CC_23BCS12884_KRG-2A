#include<iostream>
using namespace std;

bool solve(vector<int>&nums , int maxop,int mid){
    int op=0;
    for(int i=0;i<nums.size();i++){
        op+=(nums[i]-1)/mid;
    }
    return op<=maxop;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int maxop;
    cin>>maxop;
    int low=0;
    int high=*max_element(nums.begin(),nums.end());
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(solve(nums,maxop,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;

}
