void menu()
{
    printf("\n---------------------------\n");
    printf("1>Make new Equation\n");
    printf("1>Add to Equation\n");
    printf("1>Display Current Equation\n");
    printf("4>Display All Equations\n");
    printf("5>Add all Equations\n");

    printf("8>Select Equations\n");
    printf("9>Print Menu\n");
    printf("0>Exit\n");
    printf("\n---------------------------\n");
}

poly *makeNode()
{
    poly *temp = (poly *)malloc(sizeof(poly));

    int constant, variable;
    printf("Enter Constant and Variable : ");
    scanf("%d %d", &constant, &variable);
    temp->constant = constant;
    temp->variable = variable;
    temp->next = NULL;

    return temp;
}

void insert(poly **head, poly *node)
{
    poly *temp = *head;

    if (temp->variable < node->variable)
    {
        node->next = temp;
        *head = node;
        return;
    }
    else if (temp->variable == node->variable)
    {
        temp->constant += node->constant;
        return;
    }
    else if (temp->next == NULL)
    {

        node->next = temp->next;
        temp->next = node;
        return;
    }
    else
    {
        insert(&temp->next, node);
    }
    temp = temp->next;
}

void display(poly *head)
{
    if (head == NULL)
        printf("Empty");
    else
    {
        while (head != NULL)
        {
            printf("%dx%d", head->constant, head->variable);
            head = head->next;
            if (head != NULL)
                printf(" + ");
        }
    }
}

void displayAll(poly *heads[], int i)
{
    poly *temp = NULL;
    for (int j = 0; j <= i; j++)
    {
        temp = heads[j];
        printf("Equation No. %d is : ", j);
        display(temp);
        printf("\n");
    }
}

int selectEq(poly *heads[], int i)
{
    printf("Select Equation : \n");

    displayAll(heads, i);

    int sPoly;
    printf("Equation No : ");
    scanf("%d", &sPoly);

    if (sPoly < 0 || sPoly > i)
    {
        printf("\nPlease Enter a Valid Equation Number\n");
        sPoly = selectEq(heads, i);
    }

    printf("Eq %d selected ", sPoly);

    return sPoly;
}

void addAll(poly *heads[], int i)
{
    poly *base = heads[0], *temp = NULL;

    for (int j = 1; j <= i; j++)
    {
        temp = heads[j];

        do
        {
            printf("%dx%d\n", temp->constant, temp->variable);
            insert(&base, temp);

            temp = temp->next;
        } while (temp != NULL);
    }

    printf("All Equations added\n");
}
