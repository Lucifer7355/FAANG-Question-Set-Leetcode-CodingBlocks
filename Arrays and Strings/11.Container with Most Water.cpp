class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int n = height.size();
        int i = 0;
        int j = n - 1;
        while(i<j){
            int h = min(height[i],height[j]);
            area = max(area,h*(j-i));
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return area;
    }
};
