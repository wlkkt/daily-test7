////�����������������λ��
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
//        if (nums1.size() > nums2.size()) { // ��֤����1һ�����
//            swap(nums1, nums2);
//        }
//        int m = nums1.size();
//        int n = nums2.size();
//
//        // ��������ָ���������е�Ԫ�ظ������ָ��ߵ�һ������
//        int totalLeft = (m + n + 1) / 2;
//
//        int left = 0; // ��һ���������߽�
//        int right = m; // ��һ��������ұ߽�
//
//        // ѭ�����ң����õ���i��ʾ��һ�������ڷָ����Ҳ���ֵ���±꣬j��ʾ�ڶ��������ڷָ����Ҳ���ֵ���±�
//        while (left < right) {
//            int i = (left + right + 1) / 2; // ��һ������ķָ���
//            int j = totalLeft - i; // �ڶ�������ķָ���
//
//            if (nums1[i - 1] > nums2[j]) { // ��һ������ָ���������ֵ���ڵڶ�������ָ����Ҳ����ֵ
//                right = i - 1; // ��һ�ֵ���������Ϊ[left, i - 1]
//            }
//            else {
//                left = i; // ��һ�ֵ���������Ϊ[i, right]
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
//        // ������λ��
//        if ((m + n) % 2 == 1) { // �������ܳ���Ϊ����
//            return max(nums1LeftMax, nums2LeftMax);
//        }
//        else { // �������ܳ���Ϊż��
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


////������Ӵ�
//class Solution {
//public:
//    //���������м�Ѱ��
//    string longestPalindrome(string s) {
//        int sz = s.size();
//        if (sz < 2) return s;
//        int lengthMax = 1;//��ǰ������ִ�����ʼ����
//        int begin = 0;//��ǰ������ִ�����ʼ�±�
//
//        for (int i = 0; i < sz - 1; i++)//���Ĳ����ܵ�����ĩβ����Ϊ��������Ļ�
//        {
//            for (int j = i + 1; j < sz; j++)
//            {//�ж�[i,j]��Χ�ڵ��Ӵ��ǲ��ǻ����Ӵ�������ǣ��һ����ִ��ĳ��ȴ���֮ǰ��¼�ķ�Χ�ڵ��Ӵ��ǲ��ǻ����Ӵ�������ǣ��һ����ִ��ĳ��ȴ���֮ǰ��¼��lengthhMax���͸���lengthMax�ͻ����Ӵ����±�i���͸���lengthMax�ͻ����Ӵ����±�i
//                if (j - i + 1 > lengthMax && judgeLPS(s, i, j))//LPS��������Ӵ�Longest palindromic substring����д
//                {
//                    lengthMax = j - i + 1;
//                    begin = i;
//                }
//            }
//        }
//
//        return s.substr(begin, lengthMax);
//    }
//
//private:
//    bool judgeLPS(const string& s, int left, int right)//��ֹ�ַ����������µĳ����ڴ���������,�����ô��ν����ж�
//    {
//        while (left < right)
//        {
//            if (s[left] != s[right])
//            {
//                return false;
//            }
//            else
//            {
//                left++;
//                right--;
//            }
//        }
//        return true;//��[i,j]��Χ�ڶ���ͬ�˾ͷ�����
//    }
//};

//Z���ͱ任


//
//#include <stdio.h>
//#include <unistd.h>
//#include <signal.h>
//
//// volatile int g_flag = 0;
//int g_flag = 0;
//
//void changeflag(int signo)
//{
//    (void)signo;
//    printf("��g_flag,��%d->%d\n", g_flag, 1);
//    g_flag = 1;
//}
//
//int main()
//{
//    signal(2, changeflag);
//
//    while (!g_flag); // ����д���������, ������Ĭ�ϻ�����ǵĴ�������Զ��Ż���
//    // {
//    //     printf("hello world\n");
//    //     sleep(1);
//    // }
//
//    printf("process quit normal\n");
//    return 0;
//}