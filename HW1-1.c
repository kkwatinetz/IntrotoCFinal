//unit1.hw
//Katie Kwatinetz

#include <stdio.h>

int main()
{
    int studentId;
    int class1;
    int class2;
    int credit1;
    int credit2;
    double GPA;
    double totalCost;

    printf("Enter the Student\'s Id: ");
    scanf("%d", &studentId);

    printf("\nEnter crn/credit hours for the first class: ");
    scanf("%d / %d", &class1, &credit1);

    printf("\nEnter crn/credit hours for the second class: ");
    scanf("%d / %d", &class2, &credit2);


    printf("\nEnter the gpa of Student %d:", studentId);
    scanf("%lf", &GPA);

    double class1Cost = credit1 * 120.25;
    double class2Cost = credit2 * 120.25;


    if (GPA > 2.5)
    {
        printf("(25%% discount is applicable)");
        totalCost = .75 * (class1Cost + class2Cost) + 35.0;
    }
    else
    {
        printf("(25%% discount is not applicable)");
        totalCost = class1Cost + class2Cost + 35;
    }


    printf("\n\nThank you! \nHERE IS THE FEE INVOICE...");
    printf("\n\nSIMPLE COLLEGE \nORLANDO FL 10101");
    printf("\n*************************");
    printf("\n\nFee Invoice Prepared for:\n\[Student: %d\]",studentId);
    printf("\n\n1 Credit Hour = $120.25");
    printf("\n\nCRN	    CREDIT HOURS        ");
    printf("\n%d        %d                  %.2f",class1,credit1, class1Cost);
    printf("\n%d        %d                  %.2f",class2,credit2, class2Cost);
    printf("\n\nHealth & id fees $35.00");
    printf("\n\n----------------------------------------");
    printf("\n             Total Payments    %.2f\n\n", totalCost);

    return 0;
}
