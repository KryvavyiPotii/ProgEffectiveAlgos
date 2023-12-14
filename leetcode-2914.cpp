class Solution {
public:
    int minChanges(string s) {
        int res = 0, count = 1;
        vector<char> v;
        char prev;

        for (int i = 0; i < s.length(); i++)
            v.push_back(s[i]);
        prev = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] != prev)
            {
                if (count % 2 == 1)
                {
                    v[i] = prev;
                    res++;
                    count++;
                }
                else
                {
                    count = 1;
                }
            }
            else
            {
                count++;
            }
            prev = v[i];  
            cout << count << ' ';
        }

        return res;
    }
};
