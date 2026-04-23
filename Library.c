#include <stdio.h>
#include <string.h>
#include <time.h>

// Global variables
char memberName[100] = "";
char profession[100] = "";
char contactNumber[12] = "";
char bookTaken[100] = "";
char issueDate[12] = "";
char returnDate[12] = "";

// Function to save member/book info to CSV
void saveToCSV() {

    FILE *fp;
    int fileExists = 0;

    fp = fopen("members.csv", "r");
    if (fp != NULL) {
        fileExists = 1;
        fclose(fp);
    }

    fp = fopen("members.csv", "a");

    if (fp == NULL) {
        printf("Error creating CSV file!\n");
        return;
    }

    if (!fileExists) {
        fprintf(fp, "MemberName,Profession,ContactNumber,BookTaken,IssueDate,ReturnDate\n");
    }

    fprintf(fp, "%s,%s,%s,%s,%s,%s\n",
            memberName,
            profession,
            contactNumber,
            bookTaken,
            issueDate,
            returnDate);

    fclose(fp);
    printf("Member info saved to CSV!\n");
}

void Subscription(int choice1, int member) {

    char name[100], profs[100];
    char numb[12];

    printf("Are you \n");
    printf("1. Existing Member \n");
    printf("2. New Member \n\n");
    printf("Enter your choice1: ");
    scanf("%d", &choice1);
    
    if (choice1 == 1) {

        printf("1. Renew Your Membership \n");
        printf("2. Not Now \n");
        printf("Select one of the above: ");
        scanf("%d", &member);
        
        if (member == 1) {
            printf("You can renew your membership by visiting our official web page.\n");
        } else {
            printf("OK THANKS!!\n");
        }

    } else {

        printf("Your Name: ");
        scanf("%s", name); 

        printf("Your Profession: ");
        scanf("%s", profs); 

        printf("Your Contact Number: ");
        scanf("%s", numb); 
        
        printf("Congratulations!!\n");
        printf("You are a new member now!\n");

        strcpy(memberName, name);
        strcpy(profession, profs);
        strcpy(contactNumber, numb);

        strcpy(bookTaken, "");
        strcpy(issueDate, "");
        strcpy(returnDate, "");

        saveToCSV();
    }
}

void displayBooks(int choice2) {

    if (choice2 == 1) {
        printf("1. Practical Electronics for Inventors [ID: 101], 5\n");
        printf("2. The Art of Electronics [ID: 102], 3\n");
        printf("3. Fundamentals of Digital Circuits [ID: 103], 2\n");
        printf("4. Engineering Circuit Analysis by Hayt [ID: 104], 4\n");
    } 
    else if (choice2 == 2) {
        printf("1. A New Earth [ID: 105], 6\n");
        printf("2. Karma [ID: 106], 7\n");
        printf("3. Life's Amazing Secrets [ID: 107], 8\n");
        printf("4. Seven Spiritual Laws [ID: 111], 10\n");
        printf("5. Don't Believe Everything You Think [ID: 114], 5\n");
    } 
    else if (choice2 == 3) {
        printf("1. The Alchemist [ID: 115], 3\n");
        printf("2. Pride and Prejudice [ID: 117], 4\n");
        printf("3. Wuthering Heights [ID: 118], 6\n");
        printf("4. Great Expectations [ID: 120], 2\n");
        printf("5. Treasure Island [ID: 122], 5\n");
    } 
    else if (choice2 == 4) {
        printf("1. Shigley's Mechanical Engineering Design [ID: 123], 3\n");
        printf("2. Machinery's Handbook [ID: 124], 7\n");
        printf("3. Thermodynamics [ID: 125], 5\n");
        printf("4. Engineering Mechanics [ID: 126], 4\n");
    } 
    else if (choice2 == 5) {
        printf("1. Let Us C [ID: 127], 9\n");
        printf("2. Principles Of Programming Language [ID: 128], 6\n");
        printf("3. Language and Computers [ID: 129], 3\n");
        printf("4. Introduction to Algorithms [ID: 109], 2\n");
        printf("5. The C Programming Language [ID: 110], 8\n");
    } 
    else {
        printf("Invalid choice.\n");
    }
}

struct Book {
    int bookID;
    char title[100];
    int booksAvailable;
};

struct Book library[] = {
    {101,"Practical Electronics for Inventors",5},
    {102,"The Art of Electronics",3},
    {103,"Fundamentals of Digital Circuits",2},
    {104,"Engineering Circuit Analysis",4},
    {105,"A New Earth",6},
    {106,"Karma",7},
    {107,"Life's Amazing Secrets",8},
    {111,"Seven Spiritual Laws",10},
    {114,"Don't Believe Everything You Think",5},
    {115,"The Alchemist",3},
    {117,"Pride and Prejudice",4},
    {118,"Wuthering Heights",6},
    {120,"Great Expectations",2},
    {122,"Treasure Island",5},
    {123,"Shigley's Mechanical Engineering Design",3},
    {124,"Machinery's Handbook",7},
    {125,"Thermodynamics",5},
    {126,"Engineering Mechanics",4},
    {127,"Let Us C",9},
    {128,"Principles of Programming Languages",6},
    {129,"Language and Computers",3},
    {109,"Introduction to Algorithms",2},
    {110,"The C Programming Language",8}
};

int totalBooks = sizeof(library)/sizeof(library[0]);

void issuebook() {

    int enteredBookID,booksRequested,i;
    int found = 0;

    printf("Enter Book ID: ");
    scanf("%d",&enteredBookID);

    for(int i=0;i<totalBooks;i++) {

        if(library[i].bookID == enteredBookID) {

            found = 1;
        printf("Enter number of copies u want issue: ");
        scanf("%d",&booksRequested);
                 if (booksRequested <= library[i].booksAvailable) {
                printf("Book issued successfully!\n");
                library[i].booksAvailable -= booksRequested;
                printf("Book: '%s'\n", library[i].title);
                printf("Number of copies issued: %d\n", booksRequested);
                printf("Remaining copies: %d\n", library[i].booksAvailable);
            } else {
                printf("Not enough books available!\n");
            }
            
            break;
        }
    }

    if(!found){
        printf("Book ID not found.\n");
}
}
int calculateFine(int days_late) {
    int fine_per_day = 10;
    return days_late * fine_per_day;
}

void returnbook() {

    printf("You have chosen the 'Return a Book' option.\n");

    int days_late;

    printf("Enter the number of days the book is late (0 if on time): ");
    scanf("%d", &days_late);

    if (days_late <= 0) {
        printf("Book returned on time! No fine incurred.\n");
    } else {
        printf("Book returned late by %d day(s).\n", days_late);
        printf("Fine: %d\n", days_late*10);
         int fine = calculateFine(days_late);  // Function call
        printf("The fine for being %d day(s) late is: $%d\n", days_late, fine);
    }
}

int main() {

    int choice;

    printf("------Library Menu------ \n");
    printf("1.Membership \n");
    printf("2.View books \n");
    printf("3.Issue a Book \n");
    printf("4.Return a Book \n");
    printf("5.View Members \n");
    printf("6.Exit \n");

    printf("Enter your Choice: ");
    scanf("%d",&choice);

    switch(choice) {

        case 1: {
            int c1=0,m=0;
            Subscription(c1,m);
            break;
        }

        case 2: {
            int choice2;
            printf("------Choose the subject------\n");
            printf("1. Electrical\n");
            printf("2. Spiritual\n");
            printf("3. Novels\n");
            printf("4. Mechanical\n");
            printf("5. Computer Study and Languages\n");
            printf("Enter your choice: ");
            scanf("%d",&choice2);
            displayBooks(choice2);
            break;
        }

        case 3: {

            issuebook();

            time_t now=time(NULL);
            time_t future=now+(20*24*60*60);

            struct tm current=*localtime(&now);
            struct tm after20=*localtime(&future);

            printf(issueDate,"%02d-%02d-%04d",
                    current.tm_mday,
                    current.tm_mon+1,
                    current.tm_year+1900);

            printf(returnDate,"%02d-%02d-%04d",
                    after20.tm_mday,
                    after20.tm_mon+1,
                    after20.tm_year+1900);

            printf("Issue date: %s\n",issueDate);
            printf("Return date: %s\n",returnDate);

            saveToCSV();
            break;
        }

        case 4:
            returnbook();
            break;

        case 5: {
            FILE *fp=fopen("members.csv","r");
            if(fp==NULL){
                printf("No records found.\n");
            } else {
                char line[200];
                while(fgets(line,sizeof(line),fp)){
                    printf("%s",line);
                }
                fclose(fp);
            }
            break;
        }

        case 6:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}