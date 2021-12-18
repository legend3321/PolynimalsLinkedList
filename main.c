#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Polynomials
{
    int constant;
    int variable;
    struct Polynomials *next;
} poly;

void menu();
poly *makeNode();
void insert(poly **, poly *);
void display(poly *);
void displayAll(poly *[], int);
int selectEq(poly *[], int);
void addAll(poly *[], int);

int main()
{
    poly *heads[MAX], *temp;
    int i = -1, sPoly = i, choice = 1;

    menu();

    while (choice)
    {
        printf("\n\nCommand : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            i++;
            heads[i] = makeNode();
            sPoly = i;
            printf("Equation Selected With Start %dx%d\n", heads[sPoly]->constant, heads[sPoly]->variable);
            break;

        case 2:
            temp = makeNode();
            insert(&heads[sPoly], temp);
            break;

        case 3:
            printf("\nEquation No. %d is : ", i);
            display(heads[sPoly]);
            break;

        case 4:
            displayAll(heads, i);
            break;

        case 5:
            addAll(heads, i);
            i = 0;
            sPoly = i;
            break;

        case 8:
            sPoly = selectEq(heads, i);
            break;

        case 9:
            menu();
            break;
        }
    }
}

#include "functions.h"