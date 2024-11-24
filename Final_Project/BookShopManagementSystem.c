#include <stdio.h>
#include <string.h>

// User Details
typedef struct
{

    char userName[30];
    char userPassword[20];

} User;

User users[3];
int userCount = 0;

// Function to save user with file handling
void saveUser()
{
    FILE *fptr;
    fptr = fopen("user.txt", "w");
    if (fptr)
    {
        for (int i = 0; i < userCount; i++)
        {
            fprintf(fptr, "%s %s\n", users[i].userName, users[i].userPassword);
        }
        fclose(fptr);
    }
}

// Function to register user with file handling
void registerUser()
{
    printf("Registering user...\n");
    if (userCount < 3)
    {
        User newUser;
        getchar();
        printf("Enter Username: ");
        fgets(newUser.userName, sizeof(newUser.userName), stdin);
        newUser.userName[strcspn(newUser.userName, "\n")] = '\0';

        printf("Enter Password: ");
        fgets(newUser.userPassword, sizeof(newUser.userPassword), stdin);
        newUser.userPassword[strcspn(newUser.userPassword, "\n")] = '\0';

        printf("User registration successfully completed\n");
        users[userCount++] = newUser;
        saveUser();
    }
    else
    {
        printf("User limit reached\n");
    }
}

// Function to login user
int loginUser()
{
    printf("Logging in user...\n");

    char userName[30];
    char userPass[20];

    getchar();
    printf("Enter Username: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = '\0';

    printf("Enter Password: ");
    fgets(userPass, sizeof(userPass), stdin);
    userPass[strcspn(userPass, "\n")] = '\0';

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].userName, userName) == 0 && strcmp(users[i].userPassword, userPass) == 0)
        {
            printf("Login successfully!\n");
            return 1;
        }
    }

    printf("Invalid username and password!\n");
    return 0;
}

// Here is our main function
int main()
{

    int choice;

    do
    {

        printf("Enter your choice: \n");
        printf("1/Register\n");
        printf("2/Login\n");
        printf("3/Exit\n");
        scanf("%d", &choice);
        switch (choice)

        {

        case 1:
            // printf("This is registration\n");
            registerUser();
            break;

        case 2:
            // printf("This is login\n");
            if (loginUser())
            {
                printf("Congrats!You are in login page");
                do
                {
                    printf("\nBook Shop Management System\n");
                    printf("1. View Inventory\n");
                    printf("2. Add Book\n");
                    printf("3. Search Book\n");
                    printf("4. Sell Book\n");
                    printf("5. Delete Book\n");
                    printf("6. Generate Sales Report\n");
                    printf("7. Logout\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        // viewInventory();
                        printf("Displaying book...");
                        break;
                    case 2:
                        // addBook();
                        printf("Adding book....");
                        break;
                    case 3:

                        printf("Searching book....");
                        break;
                    case 4:
                        // sellBook();
                        printf("Selling book....");
                        break;
                    case 5:
                        // deleteBook();
                        printf("Deleting book....");
                        break;
                    case 6:
                        // generateSalesReport();
                        printf("Generating sales report....");
                        break;
                    case 7:
                        printf("Logging out...\n");
                        break;
                    default:
                        printf("Invalid choice! Please try again.");
                    }
                } while (choice != 7);
            }
            break;

        case 3:
            printf("Existing....\n");
            break;

        default:
            printf("Invalid Choice! Please try again\n");
        }

    } while (choice != 3);

    return 0;
}