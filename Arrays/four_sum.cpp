#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                for(int j=i+1;j<nums.size();j++){
                    if(j>i+1 && nums[j]==nums[j-1]) continue;
                    int k=j+1;
                    int l=nums.size()-1;
                  while(k<l){
                    if (nums[i]+nums[j]+nums[k]+nums[l]<target){
                        k++;
                    }
                    else if(nums[i]+nums[j]+nums[k]+nums[l]>target){
                        l--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(nums[k]==nums[k-1]&& k<l) k++;
                        while(nums[l]==nums[l+1]&& k<l) l--;
                    
                    }
                  }
                }
            }
            return ans;
        }
    };
    int main() {
        Solution solution;
        vector<int> nums ={1, -2, 3, 5, 7, 9 };
        int target = 7;
        vector<vector<int>> result = solution.fourSum(nums, target);
    
        // Print the result
        for (const auto& quadruplet : result) {
            for (const auto& num : quadruplet) {
                cout << num << " ";
            }
            cout << endl;
        }
    
        return 0;
    }