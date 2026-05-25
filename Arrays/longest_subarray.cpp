#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int longestSubarray(vector<int> &nums, int k){
            map<int,int> mp;
            int sum=0;int maxlen=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum==k){
                    maxlen=max(maxlen,i+1);
                }
                else{
                    if(mp.find(sum-k)!=mp.end()){
                        maxlen=max(maxlen,i-mp[sum-k]);
                    }
                    mp.insert({sum,i});
                }
            }
            
            return maxlen;
        }
    };
    
    
    int main() {
        Solution solution;
        vector<int> nums = {-3, 2, 1};
        int k = 6;
        int result = solution.longestSubarray(nums, k);
        cout << result << endl; // Output the result
        return 0;
    }