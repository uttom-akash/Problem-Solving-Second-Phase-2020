#include <stdio.h>
#include <stdlib.h>

int main()
{

    char ch,amount;
    ch = getchar();
    bool dollarContext=false;
    do{
        if(ch == '$')dollarContext=true;

        if(dollarContext && ((ch >= '0' && ch <= '9') || ch == '$' || ch == '.')){
            amount = ch;
            printf("%c",amount);
        }

        if(ch == ' ' )
        {
            dollarContext=false;
            amount = ch;
            printf("%c\n", amount);
        }

    }while ((ch = getchar()) != '\n' );
    
    return 0;
}