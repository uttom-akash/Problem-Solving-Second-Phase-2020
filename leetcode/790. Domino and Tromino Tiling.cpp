#define modulo 1000000007

class MatrixExponential
{
private:
    void multiply(int a[3][3], int b[3][3], int matrixDegree)
    {
        int mul[3][3];
        for (int i = 0; i < matrixDegree; i++)
        {
            for (int j = 0; j < matrixDegree; j++)
            {
                mul[i][j] = 0;
                for (int k = 0; k < matrixDegree; k++)
                {
                    long currentValue = (1LL * a[i][k] * b[k][j]) % modulo;
                    mul[i][j] = (currentValue + 1LL * mul[i][j]) % modulo;
                }
            }
        }

        this->copy(a, mul, matrixDegree);
    }

    void copy(int a[3][3], int b[3][3], int matrixDegree)
    {
        for (int i = 0; i < matrixDegree; i++)
        {
            for (int j = 0; j < matrixDegree; j++)
            {
                a[i][j] = b[i][j];
            }
        }
    }

public:
    void getPowered(int matrix[3][3], int matrixDegree, int power)
    {
        int resultMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // identity matrix

        while (power)
        {
            if (power & 1)
            {
                this->multiply(resultMatrix, matrix, matrixDegree);
                power--;
            }
            else
            {
                this->multiply(matrix, matrix, matrixDegree);
                power >>= 1;
            }
        }

        this->copy(matrix, resultMatrix, matrixDegree);
    }
};

class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int matrix[][3] = {{1, 1, 2}, {1, 0, 0}, {0, 1, 1}}; // [f(n-1),f(n-2),p(n-1)] for n=3

        MatrixExponential me;
        me.getPowered(matrix, 3, n - 2);

        return (matrix[0][0] * 2LL + matrix[0][1] * 1LL + matrix[0][2] * 1LL) % modulo;
    }
};