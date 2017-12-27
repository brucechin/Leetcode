/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!


*/

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int left = 0,size = height.size();
        if(size == 0) return result;
        int right = size -1;
        int maxleft=height[left],maxright = height[right];
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= maxleft) maxleft = height[left];
                else result += maxleft - height[left];
                left++;
            }else{
                if(height[right] >= maxright) maxright = height[right];
                else result+= maxright - height[right];
                right--;
            }
        }
        return result;
    }
};