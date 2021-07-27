/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        for (int r = 0; r < numRows; ++r) {
            string rowStr = "";
            int pos = r;
            bool down = true;
            int gap_down = 2 * (numRows - 1 - r);
            int gap_up = 2 * r;
            while (pos < s.size()) {
                rowStr.push_back(s[pos]);
                if (gap_down != 0 && gap_up != 0) {
                    if (down) {
                        pos += gap_down;
                    } else {
                        pos += gap_up;
                    }
                    down = !down;
                } else if (gap_up != 0) {
                    pos += gap_up;
                } else if (gap_down != 0) {
                    pos += gap_down;
                } else {
                    pos += 1;
                }
            }
            res = res + rowStr;
        }
        return res;
    }
};
// @lc code=end

