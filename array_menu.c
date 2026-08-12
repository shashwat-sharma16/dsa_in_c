#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX];
    int n = 0;
    int choice, i, pos, value, key;
    int found;

    while (1)
    {
        printf("\n\n----- MENU -----\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // CREATE
                printf("Enter the number of elements: ");
                scanf("%d", &n);

                if (n > MAX || n < 0)
                {
                    printf("Invalid size!\n");
                    n = 0;
                    break;
                }

                printf("Enter %d elements:\n", n);

                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }

                printf("Array created successfully.\n");
                break;


            case 2:
                // DISPLAY
                if (n == 0)
                {
                    printf("Array is empty.\n");
                }
                else
                {
                    printf("Array elements are:\n");

                    for (i = 0; i < n; i++)
                    {
                        printf("%d ", arr[i]);
                    }

                    printf("\n");
                }
                break;


            case 3:
                // INSERT
                if (n == MAX)
                {
                    printf("Array is full. Cannot insert.\n");
                    break;
                }

                printf("Enter the position where you want to insert: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1)
                {
                    printf("Invalid position!\n");
                    break;
                }

                printf("Enter the value to insert: ");
                scanf("%d", &value);

                // Shift elements to the right
                for (i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;


            case 4:
                // DELETE
                if (n == 0)
                {
                    printf("Array is empty. Cannot delete.\n");
                    break;
                }

                printf("Enter the position of the element to delete: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n)
                {
                    printf("Invalid position!\n");
                    break;
                }

                // Shift elements to the left
                for (i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;


            case 5:
                // LINEAR SEARCH
                if (n == 0)
                {
                    printf("Array is empty.\n");
                    break;
                }

                printf("Enter the element to search: ");
                scanf("%d", &key);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (arr[i] == key)
                    {
                        printf("Element found at position %d.\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Element not found.\n");
                }

                break;


            case 6:
                // EXIT
                printf("Program terminated.\n");
                return 0;


            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
