// TC - O(n) n=s.size()
// MC - O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]--;
            mp[t[i]]++;
        }
        for (auto s : mp)
        {
            if (s.second)
            {
                return false;
            }
        }
        return true;
    }
};