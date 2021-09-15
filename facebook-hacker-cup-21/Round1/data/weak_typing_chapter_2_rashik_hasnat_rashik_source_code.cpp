#include <iostream>
#include<stdio.h>
#include <cstring>
#include <vector>
#define write freopen("output.txt","w",stdout)
#define read freopen("input.txt","r",stdin)
#define INF INT_MAX
#define MOD 1000000007
using namespace std;
vector<string> subString(string str, int n)
{
    vector<string> result;
    for (int len = 1; len <= n; len++)
    {

        for (int i = 0; i <= n - len; i++)
        {

            int j = i + len - 1;
            string test;
            for (int k = i; k <= j; k++)
            {
                test.push_back(str[k]);
//                    cout << str[k];
            }
            if(test.size()!=1)
                result.push_back(test);
        }
    }
    return result;
}

int main()
{
    //cout << "Hello world!" << endl;
//    string abc;
//    cin>>abc;
//    freopen("input.txt","w",stdout);
//    vector<string> results=subString(abc, abc.size());
//    cout<<results.size()<<endl;
//    for(int i=0;i<results.size(); i++)
//    {
//        cout<<results[i].size()<<endl<<results[i]<<endl;
//    }
    write;
    read;
    long long totalNodes,totalRelations, totalInput, shortestPath[60][60],relation[60][60],x ,y, z, temp;
    string inp;
    cin>>totalInput;
    int tot=0;
    for(int tt=0;tt<totalInput; tt++)
    {
        cin>>temp;
        cin>>inp;
        char last=' ';
        long long swtch=0,lastIncreaes=0;
        long long lastIndex=0;
        for(int i=0;i<temp;i++)
        {
           if(inp[i]=='F')
            {
                swtch+=lastIncreaes;
                swtch%=MOD;
                continue;
            }
            if(last!=' ' && last!=inp[i])
            {
                lastIncreaes+=lastIndex%MOD+1;
            }
            last=inp[i];
            lastIndex=i;
            swtch+=lastIncreaes;
            swtch%=MOD;
        }
        //if(swtch)
        cout<<"Case #"<<tt+1<<": "<<swtch<<endl;
        tot+=swtch;
    }
   // cout<<tot;
    return 0;
}

//int swtch=0;
//        for(int i=0;i<temp;i++)
//        {
//            if(inp[i]=='F')
//            {
//                continue;
//            }
//            if(last!=' ' && last!=inp[i])
//            {
//                swtch++;
//            }
//            last=inp[i];
//        }
//        if(swtch)
//            cout<<inp<<": "<<swtch<<endl;
//        tot+=swtch;

