#include <stdio.h>
#include <string.h>

typedef struct
{

    char userName[30];
    char userPassword[20];

} User;

User users[3];
int userCount = 0;

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

void loginUser()
{
    printf("Logging in user...\n");
}

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
            loginUser();
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