class Solution
{
public:
    int countPrimes(int n)
    {
        bitset<2500001> primes;

        for (int i = 3; i * i < n; i += 2)
        {
            if (!primes[i >> 1])
            {
                for (int j = i * i; j < n; j += 2 * i)
                {
                    primes.set(j >> 1);
                }
            }
        }

        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if (i == 2 || (i & 1 && !primes[i >> 1]))
            {
                ans++;
            }
        }

        return ans;
    }
};