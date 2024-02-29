#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct IPO { // Struct to store IPO information
    char companyName[30];
    char stockSymbol[10];
    float offeringPrice; // Offering price could be decimal 
    int numberOfShares;
    char underwriters[30];
};

void addIPO(struct IPO ipo[], int *numIPO) { // A Function to add a new IPO
    printf("Enter IPO details:\n");
    printf("Company Name: ");
    scanf("%s", ipo[*numIPO].companyName);
    printf("Stock Symbol: ");
    scanf("%s", ipo[*numIPO].stockSymbol);

    for (int i = 0; i < *numIPO; i++) { // Check for duplicate IPO entry (if user enter multiple IPOs)
        if (strcmp(ipo[i].stockSymbol, ipo[*numIPO].stockSymbol) == 0) { // Compare two strings to check if they are equal
            printf("Error: Duplicate IPO entry.\n");
            return;
        }
    }

    printf("Offering Price: ");
    scanf("%f", &ipo[*numIPO].offeringPrice);
    printf("Number of Shares: ");
    scanf("%d", &ipo[*numIPO].numberOfShares);
    printf("Underwriters: ");
    scanf("%s", ipo[*numIPO].underwriters);

    (*numIPO)++; // Increment the value stored in the memory location pointed to by numIPO by 1 
    printf("IPO added successfully!\n");
}

void searchIPO(struct IPO ipo[], int numIPO) { // Function to search for an IPO
    char search[30];
    printf("Enter search term (Company Name or Stock Symbol): ");
    scanf("%s", search);

    int found = 0; // Initializes a variable found to 0. This variable is used to track whether a matching IPO is found during the search
    for (int i = 0; i < numIPO; i++) { // A loop that iterates through the existing IPOs stored in the ipo array
        if (strcmp(ipo[i].companyName, search) == 0 || strcmp(ipo[i].stockSymbol, search) == 0) { // Check if the current IPO's company name or stock symbol matches the user-provided search term 
            printf("\nIPO Found:\n");
            printf("Company Name: %s\n", ipo[i].companyName);
            printf("Stock Symbol: %s\n", ipo[i].stockSymbol);
            printf("Offering Price: %.2f\n", ipo[i].offeringPrice);
            printf("Number of Shares: %d\n", ipo[i].numberOfShares);
            printf("Underwriters: %s\n", ipo[i].underwriters);
            found = 1;
            break;
        }
    }

    if (!found) { // Print IPO not found if the IPO doesn't exists
    printf("IPO not found.\n");
    }
}

int main() {
    struct IPO ipo[100]; // Maximum of 100 IPOs
    int numIPO = 0;
    int choice;

    do { // Display the menu of options to user
        printf("\n=== IPO Management System ===\n");
        printf("1. Add a New IPO\n");
        printf("2. Search for an IPO\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) { 
        case 1:
            addIPO(ipo, &numIPO);
        break;
        case 2:
        	searchIPO(ipo, numIPO);
        break;
        case 3:
            printf("Exiting the IPO Management System. Goodbye!\n");
        break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3); // The loop continues to give options as soon as user enters 3 to exit

    return 0; // Exit program
}

