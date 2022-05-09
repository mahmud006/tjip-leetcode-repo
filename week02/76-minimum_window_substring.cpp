class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> freq(130, 0);
        for (auto ch : t)
        {
            freq[ch]++;
        }
        int L = 0, R = 0, cnt = t.size(), minLength = INT_MAX, startIdx = -1;
        while (R < s.size())
        {
            if (freq[s[R]] > 0)
            {
                cnt--;
            }
            freq[s[R]]--;
            R++;
            while (cnt == 0)
            {
                if (minLength > R - L)
                {
                    minLength = R - L;
                    startIdx = L;
                }
                if (freq[s[L]] == 0)
                {
                    cnt++;
                }
                freq[s[L]]++;
                L++;
            }
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLength);
    }
};