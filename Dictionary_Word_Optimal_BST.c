#include <stdio.h>

#define MAX 20

int main()
{
    int n, i, j, k;
    int cost[MAX][MAX];
    int freq[MAX];

    printf("DICTIONARY WORD SEARCH USING OPTIMAL BINARY SEARCH TREE\n");
    printf("-------------------------------------------------------\n");

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("\nEnter search frequencies of each word:\n");

    for (i = 0; i < n; i++)
    {
        printf("Word %d frequency: ", i + 1);
        scanf("%d", &freq[i]);
    }

    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (i = 0; i < n - 1; i++)
    {
        cost[i][i + 1] = freq[i] + freq[i + 1]
                         + (freq[i] < freq[i + 1] ? freq[i] : freq[i + 1]);
    }

    for (int length = 3; length <= n; length++)
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

                int currentCost = leftCost + rightCost + totalFrequency;

                if (currentCost < cost[i][j])
                    cost[i][j] = currentCost;
            }
        }
    }

    printf("\nMinimum Search Cost = %d\n", cost[0][n - 1]);

    printf("\nThe Optimal Binary Search Tree minimizes the expected search cost.\n");

    return 0;
}