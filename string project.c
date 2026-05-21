#include<stdio.h>
#include<string.h>

void inputString();
void MainMenu(char *);
void convertUpperCase(char *);
void convertLowerCase(char *);
void reverseString(char *);
void reverseOnPosition(char *);
void firstLetterWordUpperCase(char *);
void lastLetterWordUpperCase(char *);
void countOccurance(char *);

int main()
{
    inputString();
    return 0;
}

void inputString()
{
    char input[100];

    printf("***** Welcome to String Operation Project *****\n\n");
    printf("Enter String -- ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input,"\n")] = '\0';   // remove newline

    printf("\nYou Enter -- %s\n\n",input);
    MainMenu(input);
}

void MainMenu(char *input)
{
    int c;

    printf("\n***** String Operation Project *****\n");
    printf("1. Convert UpperCase\n");
    printf("2. Convert LowerCase\n");
    printf("3. Reverse String\n");
    printf("4. Reverse Each Word\n");
    printf("5. First Letter Uppercase\n");
    printf("6. Last Letter Uppercase\n");
    printf("7. Count Occurrence\n");
    printf("Enter Choice: ");
    scanf("%d",&c);
    getchar();

    switch(c)
    {
        case 1: convertUpperCase(input); break;
        case 2: convertLowerCase(input); break;
        case 3: reverseString(input); break;
        case 4: reverseOnPosition(input); break;
        case 5: firstLetterWordUpperCase(input); break;
        case 6: lastLetterWordUpperCase(input); break;
        case 7: countOccurance(input); break;
    }

    printf("\n\nPress s for same string, n for new string: ");
    char ch = getchar();
    getchar();

    if(ch=='s') MainMenu(input);
    else if(ch=='n') inputString();
}

void convertUpperCase(char *input)
{
    for(int i=0; input[i]; i++)
        if(input[i]>='a' && input[i]<='z')
            input[i]-=32;

    printf("\nResult: %s\n",input);
}

void convertLowerCase(char *input)
{
    for(int i=0; input[i]; i++)
        if(input[i]>='A' && input[i]<='Z')
            input[i]+=32;

    printf("\nResult: %s\n",input);
}

void reverseString(char *input)
{
    int len=strlen(input);
    printf("\nReverse: ");
    for(int i=len-1;i>=0;i--)
        printf("%c",input[i]);
}

void firstLetterWordUpperCase(char *input)
{
    for(int i=0; input[i]; i++)
    {
        if(i==0 || input[i-1]==' ')
            if(input[i]>='a' && input[i]<='z')
                input[i]-=32;
    }
    printf("\nResult: %s\n",input);
}

void lastLetterWordUpperCase(char *input)
{
    int len=strlen(input);

    for(int i=0;i<len;i++)
    {
        if(i==len-1 || input[i+1]==' ')
            if(input[i]>='a' && input[i]<='z')
                input[i]-=32;
    }
    printf("\nResult: %s\n",input);
}

void countOccurance(char *input)
{
    int count[256]={0};

    for(int i=0; input[i]; i++)
        count[(int)input[i]]++;

    for(int i=0;i<256;i++)
        if(count[i]>0 && i!=' ')
            printf("%c = %d\n",i,count[i]);
}

void reverseOnPosition(char *input)
{
    int start=0;

    for(int i=0; ; i++)
    {
        if(input[i]==' ' || input[i]=='\0')
        {
            int end=i-1;
            while(start<end)
            {
                char t=input[start];
                input[start]=input[end];
                input[end]=t;
                start++;
                end--;
            }
            start=i+1;
        }
        if(input[i]=='\0') break;
    }
    printf("\nResult: %s\n",input);
}

