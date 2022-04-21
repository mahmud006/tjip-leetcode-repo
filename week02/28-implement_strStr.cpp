class Solution
{
public:
    vector<long long> prefixHashHaystack, po;
    int base = 29;
    int MOD = 1000000007;

    void preprocess(string &haystack)
    {
        prefixHashHaystack[0] = haystack[0];
        for (int i = 1; i < haystack.size(); i++)
        {
            prefixHashHaystack[i] = (prefixHashHaystack[i - 1] * base) % MOD;
            prefixHashHaystack[i] += haystack[i];
            po[i] = (po[i - 1] * base) % MOD;
        }
    }

    long long getRangeHash(int L, int R)
    {
        long long x1 = prefixHashHaystack[R];
        long long x2 = L == 0 ? 0 : (prefixHashHaystack[L - 1] * po[R - L + 1]) % MOD;
        return (x1 - x2 + MOD) % MOD;
    }

    long long generateHash(string &str)
    {
        long long h = 0;
        for (auto s : str)
        {
            h = (h * base) + s;
            h %= MOD;
        }
        return h;
    }
    int strStr(string haystack, string needle)
    {
        int sz1 = haystack.size();
        int sz2 = needle.size();
        prefixHashHaystack.resize(sz1 + 1, 0);
        po.resize(sz1 + 1, 1);
        preprocess(haystack);

        long long nH = generateHash(needle);

        for (int i = 0; i < sz1 - sz2 + 1; i++)
        {
            if (getRangeHash(i, i + sz2 - 1) == nH)
            {
                return i;
            }
        }
        return -1;
    }
};

/////////// O(N^2) solution ///////////
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int sz1 = haystack.size();
        int sz2 = needle.size();
        for (int i = 0; i < sz1 - sz2 + 1; i++)
        {
            if (haystack.substr(i, sz2) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};