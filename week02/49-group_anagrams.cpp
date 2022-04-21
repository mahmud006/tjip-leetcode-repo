// TC - O(n) n=strs.size()
// MC - O(n)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (auto s : strs)
        {
            string st = s;
            sort(st.begin(), st.end());
            mp[st].push_back(s);
        }
        for (auto i : mp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

// TC - O(n) n=strs.size()
// MC - O(n)
class Solution
{
public:
    string strSort(string s)
    {
        int counter[26] = {0};
        for (auto ch : s)
        {
            counter[ch - 'a']++;
        }
        string t;
        for (int i = 0; i < 26; i++)
        {
            t += string(counter[i], i + 'a');
        }
        return t;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (auto s : strs)
        {
            mp[strSort(s)].push_back(s);
        }
        for (auto i : mp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

// TC - O(nlogn) n=strs.size()
// MC - O(n)
class Solution
{
public:
    int MOD = 1000000007;
    int base = 29;

    long long generateHash(string str)
    {
        long long h = 0;
        sort(str.begin(), str.end());
        for (auto s : str)
        {
            h = (h * base) + s;
            h %= MOD;
        }
        return h;
    }
    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        return a.second < b.second;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        vector<pair<string, int>> v;
        for (auto s : strs)
        {
            v.push_back(make_pair(s, generateHash(s)));
        }
        sort(v.begin(), v.end(), cmp);

        int check, j = 0;
        vector<string> v1;
        for (auto &it : v)
        {
            if (j > 0 && it.second != check)
            {
                res.push_back(v1);
                v1 = {};
            }
            v1.push_back(it.first);
            check = it.second;
            j++;
        }

        res.push_back(v1);
        return res;
    }
};