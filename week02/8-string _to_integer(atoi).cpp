// TC - O(n)
// MC - O(1)
class Solution
{
public:
    int myAtoi(string s)
    {
        long long num = 0;
        int index = 0;
        while (s[index] == ' ')
        {
            index++;
        }
        int sign = 1;
        if (s[index] == '-' || s[index] == '+')
        {
            sign = (s[index++] == '-') ? -1 : 1;
        }
        while (s[index] - '0' >= 0 && s[index] - '0' <= 9)
        {
            num = (num * 10) + (s[index++] - '0');
            if (num * sign >= INT_MAX)
                return INT_MAX;
            if (num * sign <= INT_MIN)
                return INT_MIN;
        }
        return num * sign;
    }
};

// TC - O(n)
// MC - O(1)
class Solution
{
public:
    int myAtoi(string s)
    {
        int num = 0;
        int pos = 0, neg = 0, flg = 0, high = INT_MAX;
        long long check;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                check = (long long)num * 10 + (s[i] - '0');
                if (check > high)
                {
                    num = high;
                    break;
                }
                num = (num * 10) + (s[i] - '0');
                flg++;
            }
            else if (flg > 0)
            {
                break;
            }
            else
            {
                if (s[i] == '-')
                {
                    neg++;
                }
                else if (s[i] == '+')
                {
                    pos++;
                }
                else if (s[i] == ' ' && (pos == 0 && neg == 0))
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        if (pos + neg > 1)
        {
            return 0;
        }
        else if (neg == 1 && num > 0)
        {
            num = num * (-1);
            return check > high ? num - 1 : num;
        }
        return num;
    }
};