#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> ans;
            // a hashmap can be used to store the index of the elements and check if the complement exists in the hashmap
           unordered_map<int,int> mp;
            for(int i = 0; i < nums.size(); i++) {
                mp.insert({nums[i], i});
            }
            sort(nums.begin(),nums.end());
            int left=0;
            int right=nums.size()-1;
            while(left<=right){
                if(nums[left]+nums[right]==target){
                    ans.push_back(left);
                    ans.push_back(right);
                    break;
                }
                else{
                    if(nums[left]+nums[right]>target){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
            // we need to find the original indices of the elements in the sorted array
           ans[0]=mp[nums[ans[0]]];
           ans[1]=mp[nums[ans[1]]];
           return ans;
            
    }
    };
    int main() {
        Solution solution;
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> result = solution.twoSum(nums, target);
        for (int index : result) {
            cout << index << " ";
        }
        return 0;
    }