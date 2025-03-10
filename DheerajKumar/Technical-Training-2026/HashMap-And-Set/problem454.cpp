/*454. 4Sum II
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
 

Constraints:

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            unordered_map<int, int> mapper;
            int count = 0;
    
            for(int i = 0; i < nums1.size(); i++){
                for(int j = 0; j < nums2.size(); j++){
                    mapper[nums1[i] + nums2[j]]++;
                }
            }
            
            for(int i = 0; i < nums3.size(); i++){
                for(int j = 0; j < nums4.size(); j++){
                    int remaining = - (nums3[i] + nums4[j]);
                    if(mapper.find(remaining) != mapper.end()){
                        count += mapper[remaining]; 
                    }
                }
            }
            return count;
        }
    };


int main(){
    int testCases;
    cout<<"\n Enter number of test Cases ->> ";
    cin>>testCases;

    for(int i = 0; i < testCases; i++){
        vector<int> nums1, nums2, nums3, nums4;
        int size;
        cout<<"\n Enter the size of array -> ";
        cin>>size;

        for(int j = 0; j < size; j++){
            cout<<"Enter Array 1 - > \n \t";
            int input;
            cin>>input;
            nums1.push_back(input);
        }

        for(int j = 0; j < size; j++){
            cout<<"Enter Array 2 - > \n \t";
            int input;
            cin>>input;
            nums2.push_back(input);
        }

        for(int j = 0; j < size; j++){
            cout<<"Enter Array 3 - > \n \t";
            int input;
            cin>>input;
            nums3.push_back(input);
        }

        for(int j = 0; j < size; j++){
            cout<<"Enter Array 4 - > \n \t";
            int input;
            cin>>input;
            nums4.push_back(input);
        }

        Solution Test;

        cout<<"possible count ->> "<<Test.fourSumCount(nums1, nums2, nums3, nums4);

    }
}