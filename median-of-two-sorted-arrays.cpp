// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Yang Liuqing
// yllqq@outlook.com


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int>::const_iterator p1 = nums1.begin();
            vector<int>::const_iterator p2 = nums2.begin();
            int sum = nums1.size() + nums2.size();
            int target = (sum + 1) / 2;
            int curr = 0;
            int num = 0;

            if (sum == 1)
            {
                if (nums1.size() == 1) return *p1;
                else return *p2;
            }

            while (curr < target)
            {
                if ((p2 == nums2.end()) || ((p1 != nums1.end()) && (*p1 <= *p2)))
                {
                    num = *p1;
                    ++p1;
                }
                else
                {
                    num = *p2;
                    ++p2;
                }
                curr++;
            }

            if (sum % 2)
            {   // Odd
                return num;
            }
            else
            {   // Even
                int num2;
                if ((p2 == nums2.end()) || ((p1 != nums1.end()) && (*p1 <= *p2)))
                {
                    num2 = *p1;
                }
                else
                {
                    num2 = *p2;
                }
                return ((double)num + num2) / 2;
            }
    }
};
