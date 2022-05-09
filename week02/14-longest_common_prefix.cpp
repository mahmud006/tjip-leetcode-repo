// TC - O(n)
// MC - O(1)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string mn = strs[0], mx = strs[0], str;
        for (auto s : strs)
        {
            mn = min(mn, s);
            mx = max(mx, s);
        }
        for (int i = 0; i < mn.size(); i++)
        {
            if (mn[i] != mx[i])
            {
                break;
            }
            str += mn[i];
        }
        return str;
    }
};
//
//
//
// TC - O(n*n)
// MC - O(1)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string str, str1;
        for (int i = 0; i < strs.size(); i++)
        {
            str1 = "";
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] != strs[i][j])
                {
                    break;
                }
                str1 += str[j];
            }
            (i == 0 ? str = strs[i] : str = str1);
        }
        return (strs.size() == 1 ? str : str1);
    }
};