class Solution {
public:
  int maxArea(vector<int>& height) {
    int last = height.size() - 1;
    int front = 0;
    int area = 0;

    while (front < last) {
      int a1 = (last - front) * min(height[last], height[front]); // Calculate area directly
      area = max(area, a1); // Update maximum area

      if (height[last] < height[front]) {
        last--;
      } else {
        front++;
      }
    }

    return area;
  }
};
