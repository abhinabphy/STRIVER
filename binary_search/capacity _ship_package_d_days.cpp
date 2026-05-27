#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
         int daysrequired(vector<int>& weights,int cap){
            long long sum=0;int days=1;
            int i=0;
           while(i<=weights.size()-1){
                sum+=weights[i];
                if (sum>cap){
                    sum=weights[i];
                    
                    days++;
                }
               
                    i++;
            
            }
            return days;
         }
        int shipWithinDays(vector<int>& weights, int days) {
           //int max=*max_element(weights.start(),weights.end());
           long long sum=0;int maxi=INT_MIN;
           for(int i=0;i<weights.size();i++){
              sum+=weights[i];
              maxi=max(maxi,weights[i]);
    
           }
           int low=maxi;
           int high=sum;
           while(low<=high){
              int mid=low+(high-low)/2;
            if (daysrequired(weights,mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
           }
           return low;
    
        }
    };

int main() {
    Solution s;
    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    int days=5;
    int result=s.shipWithinDays(weights,days);
    cout<<"Minimum capacity required to ship the packages within "<<days<<" days is: "<<result<<endl;
     return 0;  }
     