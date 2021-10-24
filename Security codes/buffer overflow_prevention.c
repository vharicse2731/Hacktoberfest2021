#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[9];
    int pass = 0;

    printf("\n Enter the password : \n");
    fgets(buff,9,stdin);
    printf("%s\n",buff);

    if(strcmp(buff, "dynamite"))
    {
        printf ("\n Wrong Password \n");
    }
    else
    {
        printf ("\n Correct Password \n");
        pass = 1;
    }

    if(pass)
    {
       /* Giving root rights to user if password is correct and pass is set*/
        printf ("\n Root privileges given to the user \n");
    }

    return 0;
}
