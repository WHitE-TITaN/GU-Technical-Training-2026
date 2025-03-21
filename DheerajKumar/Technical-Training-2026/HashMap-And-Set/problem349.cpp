/*349. Intersection of Two Arrays
Solved

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> firstArray;
            vector<int> output;
            
            for(auto numbers : nums1){
                firstArray.insert(numbers);
            }
    
            for(auto numbers : nums2){
                if(firstArray.find(numbers) != firstArray.end()){
                    output.push_back(numbers);
                    firstArray.erase(numbers);
                }
            }
    
            return output;
        }
    };

int main(){
    int numberOfTestCase;
    cout<<"Enter number of Test case -> ";
    cin>>numberOfTestCase;

    for(int i = 0; i < numberOfTestCase; i++){
        vector<int> nums1, nums2;
        int size1, size2;

        cout<<"\n Enter size of first array -> ";
        cin>>size1;

        cout<<"\nsize of second Array";
        cin>>size2;

        cout<<"Enter array 1 -> ";
        for(int i = 0; i < size1; i++){
            int input;
            cin>>input;

            nums1.push_back(input);
        }

        cout<<"Enetr array 2 ->";
        for(int i = 0; i < size2; i++){
            int input;
            cin>>input;

            nums2.push_back(input);
        }

        Solution test;

        vector<int> output = test.intersection(nums1, nums2);
    }
}