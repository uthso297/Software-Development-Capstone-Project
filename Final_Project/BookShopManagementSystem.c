#include <stdio.h>
#include <string.h>

// User Details
typedef struct
{
    char userName[30];
    char userPassword[20];
    char role[10]; // "admin" or "user"
} User;

// Book details
typedef struct
{
    int id;
    char title[50];
    char author[50];
    float price;
    float sellPrice;
    int quantity;
    float totalPrice;
} Book;

// Sales info
typedef struct
{
    int bookId;
    char bookTitle[50];
    int quantitySold;
    float totalPrice;
} Sale;

// Buy Report structure
typedef struct
{
    int bookId;
    char bookTitle[50];
    int quantityBought;
    float totalPrice;
} BuyReport;

User users[3];
int userCount = 0;
Book books[20];
Sale sales[20];
BuyReport buyReports[20];
int bookCount = 0;
int salesCount = 0;
int buyReportCount = 0;

// Function to save user with file handling
void saveUser()
{
    FILE *fptr;
    fptr = fopen("user.txt", "w");
    if (fptr)
    {
        for (int i = 0; i < userCount; i++)
        {
            fprintf(fptr, "Name: %s Password: %s Role: %s\n", users[i].userName, users[i].userPassword, users[i].role);
        }
        fclose(fptr);
    }
}
// Registration
void registerUser()
{
    printf("Registering user...\n");
    if (userCount < 3)
    {
        User newUser;
        getchar(); // To prevent new line problem
        printf("Enter Username: ");
        fgets(newUser.userName, sizeof(newUser.userName), stdin);
        newUser.userName[strcspn(newUser.userName, "\n")] = '\0';

        // Check if the username already exists
        for (int i = 0; i < userCount; i++)
        {
            if (strcmp(users[i].userName, newUser.userName) == 0)
            {
                printf("Username already exists. Please choose a different username.\n");
                return;
            }
        }

        printf("Enter Password: ");
        fgets(newUser.userPassword, sizeof(newUser.userPassword), stdin);
        newUser.userPassword[strcspn(newUser.userPassword, "\n")] = '\0';

        printf("Enter Role (admin/user): ");
        fgets(newUser.role, sizeof(newUser.role), stdin);
        newUser.role[strcspn(newUser.role, "\n")] = '\0';

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
            if (strcmp(users[i].role, "admin") == 0)
            {
                printf("Logged in as Admin.\n");
                return 2; // Admin access
            }
            else
            {
                printf("Logged in as User.\n");
                return 1; // User access
            }
        }
    }

    printf("Invalid username and password!\n");
    return 0;
}

// View Books function
void viewInventory()
{
    printf("\nBook Inventory:\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("ID: %d, Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
               books[i].id, books[i].title, books[i].author,
               books[i].price, books[i].quantity);
    }
}

// Save buy report function
void saveBuy()
{
    FILE *fptr = fopen("buyreport.txt", "w");
    if (fptr)
    {
        for (int i = 0; i < buyReportCount; i++)
        {
            fprintf(fptr, "Book ID: %d Title: %s Quantity: %d Total Price: %.2f\n",
                    buyReports[i].bookId, buyReports[i].bookTitle,
                    buyReports[i].quantityBought, buyReports[i].totalPrice);
        }
        fclose(fptr);
    }
}

// Save book function
void saveBooks()
{
    FILE *fptr = fopen("book.txt", "w");
    if (fptr)
    {
        for (int i = 0; i < bookCount; i++)
        {
            fprintf(fptr, "Book Id: %d Title: %s Author: %s Price: %.2f Quantity: %d Total price: %0.2f\n", books[i].id, books[i].title,
                    books[i].author, books[i].price, books[i].quantity, books[i].totalPrice);
        }
        fclose(fptr);
    }
}

// Add Book function
void addBook()
{
    if (bookCount < 20)
    {
        Book newBook;
        printf("Enter Book ID: ");
        scanf("%d", &newBook.id);

        printf("Enter Book Title: ");
        getchar();
        fgets(newBook.title, sizeof(newBook.title), stdin);
        newBook.title[strcspn(newBook.title, "\n")] = '\0';

        printf("Enter Author Name: ");
        fgets(newBook.author, sizeof(newBook.author), stdin);
        newBook.author[strcspn(newBook.author, "\n")] = '\0';

        printf("Enter Book Price: ");
        scanf("%f", &newBook.price);

        printf("Enter Book Sell Price: ");
        scanf("%f", &newBook.sellPrice);

        printf("Enter Quantity: ");
        scanf("%d", &newBook.quantity);

        newBook.totalPrice = newBook.price * newBook.quantity;

        books[bookCount++] = newBook;

        // Track buy report
        BuyReport newBuyReport;
        newBuyReport.bookId = newBook.id;
        strcpy(newBuyReport.bookTitle, newBook.title);
        newBuyReport.quantityBought = newBook.quantity;
        newBuyReport.totalPrice = newBook.totalPrice;

        buyReports[buyReportCount++] = newBuyReport;

        printf("Book added successfully!\n");
        saveBooks();
        saveBuy();
    }
    else
    {
        printf("Inventory is full!\n");
    }
}

// Function to generate Buy Report
void generateBuyReport()
{
    printf("\nBuy Report:\n");
    for (int i = 0; i < buyReportCount; i++)
    {
        printf("Book ID: %d, Title: %s, Quantity Bought: %d, Total Price: %.2f\n",
               buyReports[i].bookId, buyReports[i].bookTitle,
               buyReports[i].quantityBought, buyReports[i].totalPrice);
    }
}

// Save sales function
void saveSales()
{
    FILE *fptr = fopen("sales.txt", "w");
    if (fptr)
    {
        for (int i = 0; i < salesCount; i++)
        {
            fprintf(fptr, "BookID: %d Title: %s Quantity: %d Total Price: %.2f\n", sales[i].bookId, sales[i].bookTitle,
                    sales[i].quantitySold, sales[i].totalPrice);
        }
        fclose(fptr);
    }
}

// Track Sale function
void trackSale(int id, char *title, int quantity, float totalPrice)
{
    Sale newSale = {id, "", quantity, totalPrice};
    strcpy(newSale.bookTitle, title);
    sales[salesCount++] = newSale;
    saveSales();
}

// Sell Book
void sellBook()
{
    int id, quantity;
    printf("Enter Book ID to sell: ");
    scanf("%d", &id);
    printf("Enter Quantity to sell: ");
    scanf("%d", &quantity);
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].quantity >= quantity)
            {
                books[i].quantity -= quantity;
                float totalPrice = books[i].price * quantity;
                books[i].totalPrice -= totalPrice;
                float totalSellPrice = books[i].sellPrice * quantity;
                printf("Sold %d copies of '%s' for a total of %.2f\n", quantity, books[i].title, totalSellPrice);
                trackSale(id, books[i].title, quantity, totalSellPrice);
                saveBooks();
            }
            else
            {
                printf("Not enough stock available!\n");
            }
            return;
        }
    }
    printf("Book ID not found!\n");
}

// Sales report function
void generateSalesReport()
{
    printf("\nSales Report:\n");

    for (int i = 0; i < salesCount; i++)
    {
        float sellPrice = 0.0;
        float costPrice = 0.0;

        for (int j = 0; j < bookCount; j++)
        {
            if (books[j].id == sales[i].bookId)
            {
                sellPrice = books[j].sellPrice; 
                costPrice = books[j].price;  
                break; 
            }
        }

        float profit = (sellPrice * sales[i].quantitySold) - (costPrice * sales[i].quantitySold);

        printf("Book Id: %d, Title: %s, Quantity: %d, Total Price: %.2f, Profit: %.2f\n",
               sales[i].bookId, sales[i].bookTitle, sales[i].quantitySold,
               sales[i].totalPrice, profit);
    }
}


// Function to delete a book from inventory
void deleteBook()
{
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    int found = 0;

    // Search for the book with the given ID
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            found = 1;

            // Shift to fill the gap
            for (int j = i; j < bookCount - 1; j++)
            {
                books[j] = books[j + 1];
            }

            // Decrease book count
            bookCount--;

            printf("Book with ID %d deleted successfully!\n", id);

            // Update book list
            saveBooks();
            saveBuy();

            return;
        }
    }

    if (!found)
    {
        printf("Book with ID %d not found!\n", id);
    }
}

// Function to search book by title (strstr is for advance search but if we needed exact title then strcmp could be used)
void searchBook()
{
    char searchTitle[50];
    int found = 0;

    printf("Enter Book Title to search: ");
    getchar();
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++)
    {
        if (strstr(books[i].title, searchTitle) != NULL)
        {
            printf("\nBook Found: \n");
            printf("ID: %d, Title: %s, Author: %s, Price: %.2f, Quantity: %d\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].price, books[i].quantity);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No book found with the title '%s'\n", searchTitle);
    }
}

// Here is our main function
// Here is our main function
int main()
{
    int choice;
    int userType = 0; // 0 = no login, 1 = user, 2 = admin

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
            registerUser();
            break;

        case 2:
            userType = loginUser();
            if (userType)
            {
                do
                {
                    printf("\nBook Shop Management System\n");
                    printf("1. View Inventory\n");
                    if (userType == 2) // Admin has full access
                    {
                        printf("2. Add Book\n");
                        printf("3. Delete Book\n");
                        printf("4. Generate Buy Report\n");
                        printf("5. Generate Sales Report\n");
                    }
                    printf("6. Search Book\n");
                    printf("7. Sell Book\n");
                    printf("8. Logout\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice)
                    {
                    case 1:
                        viewInventory();
                        break;
                    case 2:
                        if (userType == 2) // Admin can add books
                            addBook();
                        else
                            printf("Access denied! Admin privileges required.\n");
                        break;
                    case 3:
                        if (userType == 2) // Admin can delete books
                            deleteBook();
                        else
                            printf("Access denied! Admin privileges required.\n");
                        break;
                    case 4:
                        if (userType == 2) // Admin can generate buy report
                            generateBuyReport();
                        else
                            printf("Access denied! Admin privileges required.\n");
                        break;
                    case 5:
                        if (userType == 2) // Admin can generate sales report
                            generateSalesReport();
                        else
                            printf("Access denied! Admin privileges required.\n");
                        break;
                    case 6:
                        searchBook();
                        break;
                    case 7:
                        sellBook();
                        break;
                    case 8:
                        printf("Logging out...\n");
                        userType = 0;
                        break;
                    default:
                        printf("Invalid choice, try again!\n");
                        break;
                    }
                } while (userType != 0);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice, try again!\n");
            break;
        }
    } while (choice != 3);

    return 0;
}
