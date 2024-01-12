#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max 10
char stackQ[max][256];
int stackAns[max];
int top = -1;

void pushAns(int a)
{
    top = top + 1;
    stackAns[top] = a;
}

int main()
{
    int points = 0, i, ans, sec, min;
    char name[256]; // Fixed the declaration of name to be an array of characters
    time_t t1, t2;
    double diff;

    char stackQ[max][256] = {
        "10.HERE IS AN INFIX EXPRESSION:4+3*(6*3-12).SUPPOSE THAT WE ARE USING THE USUAL STACK ALGORITHM TO CONVERT "
        "THE EXPRESSION FROM INFIX TO POSTFIX NOTATION.THE MAXIMUM NUMBER "
        "OF SYMBOLS THAT WILL APPEAR ON THE STACK AT ONE TIME DURING THE "
        "CONVERSION OF THIS EXPRESSION?\n1)1\t2)2\t3)3\t4)4",
        "9.WHAT IS THE VALUE OF THE POSTFIX EXPRESSION 6 3 2 4 + - *\n1)1\t2)40\t3)74\t4)-18",
        "8.CONSIDER THE USUAL ALGORITHM FOR DETERMINING WHETHER A "
        "SEQUENCE OF PARENTHESES IS BALANCED.SUPPOSE THAT YOU RUN THE "
        "ALGORITHM ON A SEQUENCE THAT CONTAINS 2 LEFT PARENTHESES AND 3 RIGHT "
        "PARENTHESES(IN SOME ORDER).THE MAXIMUM NUMBER OF PARENTHESES "
        "THAT APPEAR ON THE STACK AT ANY ONE TIME DURING THE COMPUTATION? "
        "\n1)1\t2)2\t3)3\t4)4 OR MORE",
        "7.CONSIDER THE USUAL ALGORITHM FOR DETERMINING WHETHER A "
        "SEQUENCE OF PARENTHESES IS BALANCED.THE MAXIMUM NUMBER OF "
        "PARENTHESES THAT APPEAR ON THE STACK AT ANY ONE TIME WHEN THE "
        "ALGORITHM ANALYZES:(()(())(()))?\n1)1\t2)2\t3)3\t4)4 OR MORE",
        "6.WHICH OF THE FOLLOWING IS NOT THE APPLICATION OF STACK\n1)A "
        "PARENTHESES BALANCING PROGRAM\t2)TRACKING OF LOCAL VARIABLES AT "
        "THE RUN TIME\t3)COMPILER SYNTAX ANALYZER\t4)DATA TRANSFER BETWEEN "
        "TWO SYNCHRONOUS PROCESS",
        "5.ENTRIES IN STACK ARE ORDERED.WHAT IS THE MEANING OF THE "
        "STATEMENT?\n1)A COLLECTION OF STACKS IS SORTABLE\t2)STACK ENTRIES "
        "MAY BE COMPARED WITH THE '<' OPERATION\t3)THE ENTRIES ARE STORED IN A "
        "LINKED LIST\t4)THERE IS A SEQUENTIAL ENTRY THAT IS ONE BY ONE",
        "4.PUSHING AN ELEMENT INTO STACK ALREADY HAVING FIVE ELEMENTS AND "
        "STACK SIZE OF 5, THEN STACK "
        "BECOMES\n1)OVERFLOW\t2)CRASH\t3)UNDERFLOW\t4)USER FLOW",
        "3.IN A STACK, IF A USER TRIES TO REMOVE AN ELEMENT FROM AN EMPTY "
        "STACK IT IS CALLED\n1)UNDERFLOW\t2)EMPTY "
        "COLLECTION\t3)OVERFLOW\t4)GARBAGE COLLECTION",
        "2.PROCESS OF REMOVING AN ELEMENT FROM A STACK IS "
        "CALLED\n1)CREATE\t2)PUSH\t3)EVALUATION\t4)POP",
        "1.PROCESS OF INSERTING AN ELEMENT IN STACK IS "
        "CALLED\n1)CREATE\t2)PUSH\t3)EVALUATION\t4)POP"};

    clrscr();
    printf("A quieria using STACK as the data structure to pop the first and most valued question at last.\n");
    pushAns(4); // push 10 ans.
    pushAns(4);
    pushAns(2);
    pushAns(3);
    pushAns(4);
    pushAns(4);
    pushAns(1);
    pushAns(1);
    pushAns(4);
    pushAns(2);
    printf("\nWelcome to Quizeria.\n");
    printf("Enter your name.\n");
    scanf("%s", name);
    printf("Welcome %s\n", name);

    for (i = 9; i >= 0; i--)
    {
        for (sec = 15; sec >= 0; sec--)
        {
            clrscr();
            printf("\n\nThis question is for %d points\n", (10 - i) * 10);
            printf("00:00: %d\n %s", sec, stackQ[i]);
            delay(1000);
        }
        time(&t1);
        printf("Enter your ans.\n");
        scanf("%d", &ans);
        time(&t2);
        if (ans == stackAns[i])
        {
            diff = difftime(t2, t1);
            printf("\n Extra time taken is %2lf seconds \n", diff);
            if (diff >= 5)
            {
                points = points + (((10 - i) * 10) - ((10 - i) * 5));
                printf("Half points are reduced for late answer");
                printf("Congrats!!!\t You earn %d points\n", (((10 - i) * 10) - ((10 - i) * 5)));
                delay(6000);
            }
            else
            {
                points = points + (10 - i) * 10;
                printf("Congrats!!!\t You earned %d points\n", (10 - i) * 10);
                delay(6000);
            }
        }
        else if (ans == 0)
        {
            printf("You chose to quit\n");
            break;
        }
        else
        {
            points = points - 50;
            printf("Sorry, the correct answer is %d. \n", stackAns[i]);
            break;
        }
    }

    if (points == 550)
        printf("You are the winner of the Quizeria with %d points!!!\n", points);
    else if (points >= 275)
        printf("\n You have successfully completed the Quizeria with %d", points);
    else
        printf("\n You are disqualified\n You scored %d points!!!\n", points);

    getch();
    return 0;
}
