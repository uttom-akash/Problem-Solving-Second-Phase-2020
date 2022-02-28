#include <bits/stdc++.h>

#define mx 10000
#define mod 1000007
#define ll long long

using namespace std;

// fill_n(&a[0][0], ntc * ntc, -100);

void optimize()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void setupFileIO(string fin = "input.txt", string fout = "output.txt")
{
    freopen(fin.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

class Robot
{
private:
    int width, height;
    int posx, posy;
    int dx, dy;

    void setDir(int x, int y)
    {
        if (x >= width)
            dx = 0, dy = 1;

        else if (x < 0)
            dx = 0, dy = -1;

        else if (y >= height)
            dx = -1, dy = 0;
        else if (y < 0)
            dx = 1, dy = 0;
    }

public:
    Robot(int width, int height)
    {
        this->dx = 1;
        this->dy = 0;
        this->width = width;
        this->height = height;
        this->posx = 0;
        this->posy = 0;
    }

    void move(int num)
    {
        num%=(width*height-4);
        while (num--)
        {
            setDir(posx+dx,posy+dy);
            posx=posx+dx;
            posy=posy+dy;
        }
    }

    vector<int> getPos()
    {
        return vector<int>({posx,posy});
    }

    string getDir()
    {
        if(dx==1)
            return "East";
        if(dx==-1)
            return "West";
        if(dy==1)
            return "North";
        if(dy==-1)
            return "South";
    }
};

void solve()
{

    int n;
    cin >> n;
    int a[n + 5];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, bool> mapper;

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            mapper[4 * i * j + 3 * i + 3 * j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mapper[a[i]] == false)
            ans++;
    }

    cout << ans << "\n";
}

int main()
{
    optimize();

    solve();

    return 0;
}