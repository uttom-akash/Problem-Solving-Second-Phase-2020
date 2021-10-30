struct p
{
    int index;
    int soc;

    bool operator<(const p &a)
    {
        return soc < a.soc;
    }
};