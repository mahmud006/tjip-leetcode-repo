// TC - O(nlogn) n=nums.size()
// MC - O(n)
class Solution
{
public:
    static bool cmp(int &a, int &b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        string s;
        for (auto i : nums)
        {
            s += to_string(i);
        }
        if (s[0] == '0')
            return "0";
        return s;
    }
};