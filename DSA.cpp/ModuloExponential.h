#define mod 10000000

class MatrixExponential
{
public:
    int getPowered(int base, int power)
    {
        int result = 1;

        while (power)
        {
            if (power & 1)
            {
                result *= base;
                power--;
            }
            else
            {
                base *= base;
                power >>= 1;
            }
        }

        return result;
    }
};
