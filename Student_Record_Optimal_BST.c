#include <stdio.h>

#define MAX 20

int main()
{
    int n, i, j, k;
    int cost[MAX][MAX];
    int freq[MAX];

    printf("STUDENT RECORD SEARCH USING OPTIMAL BINARY SEARCH TREE\n");
    printf("------------------------------------------------------\n");

    printf("Enter number of student records: ");
    scanf("%d", &n);

    printf("\nEnter search frequencies of each student record:\n");

    for (i = 0; i < n; i++)
    {
        printf("Student %d frequency: ", i + 1);
        scanf("%d", &freq[i]);
    }

    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int length = 2; length <= n; length++)
    {
        for (i = 0; i <= n - length; i++)
        {
            j = i + length - 1;
            cost[i][j] = 99999;

            int totalFrequency = 0;

            for (k = i; k <= j; k++)
                totalFrequency += freq[k];

            for (k = i; k <= j; k++)
            {
                int leftCost = (k > i) ? cost[i][k - 1] : 0;
                int rightCost = (k < j) ? cost[k + 1][j] : 0;

                int currentCost =
                    leftCost + rightCost + totalFrequency;

                if (currentCost < cost[i][j])
                    cost[i][j] = currentCost;
            }
        }
    }

    printf("\nMinimum Student Record Search Cost = %d\n",
           cost[0][n - 1]);

    printf("\nOptimal BST provides efficient student record searching.\n");

    return 0;
}