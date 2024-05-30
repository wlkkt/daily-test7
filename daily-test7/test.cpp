////求两个有序数组的中位数
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        if (nums1.size() > nums2.size()) { // 保证数组1一定最短
//            swap(nums1, nums2);
//        }
//        int m = nums1.size();
//        int n = nums2.size();
//
//        // 两个数组分割线左侧所有的元素个数（分割线第一条件）
//        int totalLeft = (m + n + 1) / 2;
//
//        int left = 0; // 第一个数组的左边界
//        int right = m; // 第一个数组的右边界
//
//        // 循环查找，最后得到的i表示第一个数组在分割线右侧数值的下标，j表示第二个数组在分割线右侧数值的下标
//        while (left < right) {
//            int i = (left + right + 1) / 2; // 第一个数组的分割线
//            int j = totalLeft - i; // 第二个数组的分割线
//
//            if (nums1[i - 1] > nums2[j]) { // 第一个数组分割线左侧的数值大于第二个数组分割线右侧的数值
//                right = i - 1; // 下一轮的搜索区间为[left, i - 1]
//            }
//            else {
//                left = i; // 下一轮的搜索区间为[i, right]
//            }
//        }
//
//        int i = left;
//        int j = totalLeft - i;
//        int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
//        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
//        int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
//        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];
//
//        // 计算中位数
//        if ((m + n) % 2 == 1) { // 两数组总长度为奇数
//            return max(nums1LeftMax, nums2LeftMax);
//        }
//        else { // 两数组总长度为偶数
//            return (double)(max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
//        }
//    }
//};
//
//int main() {
//    Solution sol;
//
//    vector<int> nums1 = { 1, 3 };
//    vector<int> nums2 = { 2 };
//    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 2.0
//
//    nums1 = { 1, 2 };
//    nums2 = { 3, 4 };
//    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 2.5
//
//    nums1 = { 2, 4, 6, 15 };
//    nums2 = { 1, 7, 8, 10, 17 };
//    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // 7.0
//
//    return 0;
//}
