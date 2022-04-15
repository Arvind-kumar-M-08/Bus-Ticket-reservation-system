/*Hello! This is a project made by us from scratch creating a Bus Reservation system
Created by Abhinav,Arvind,Hari,Surzith
Hope you enjoy the experience*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int p, date, pass, i, seat[21], a[14], j, k, pay, c[2], z = 0, q[14], t;
long long int mob;
char name[21][30], bname[30];
char bookedname[14][30], line[500];
char uname[30];
char cdate[10];
int cn, sn, rat;
float ratings, y;
FILE *fp;

void signup();
void ticketno();
void cancl_data();
void empty_seat();
void Homepage();
void login();
int adminlogin();
void booking();
int status();
int freecheck();
void ticket();
void update();
void user_rating();
void rate();
void cancl();
void refund();
void delay();
void booking_data();
void display_bookings();
void display_cancl();

void delay(int secs)
{
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime)
        ;
}

void signup() //Used to create a new account
{
    system("cls");
    FILE *cred;
    printf("\n\n\t\t\t\t\tSIGNUP PAGE");
    char username[30], password[30];
    printf("\n\n\n\n\t\t\tEnter Username: ");
    scanf("%s", username);
    char *ext = ".txt";
    strcat(username, ext);
    cred = fopen(username, "w+");
    printf("\n\n\t\t\tEnter Password: ");
    scanf("%s", password);
    fprintf(cred, "%s\n", password);
    printf("\n\n\n\t\t\t\tSigned Up Successfully\n");
    fclose(cred);
    delay(3);
    login();
}

int adminlogin() //Login for admin
{
    system("cls");
    char usernamei[30], passwordi[30], setusername[30], setpassword[30];
    FILE *adminu, *adminp;
    adminp = fopen("adminpass.bin", "rb");
    adminu = fopen("adminuser.bin", "rb");
    printf("\n\n\n\t\t\t\tADMIN Login Page");
    delay(1);
    printf("\n\n\n\n\n\t\tEnter Username: ");
    scanf("%s", usernamei);
    printf("\n\t\tEnter Password: ");
    scanf("%s", passwordi);
    while (fread(setusername, sizeof(char), 30, adminu) && fread(setpassword, sizeof(char), 30, adminp))
        ;
    {
        if (strcmp(usernamei, setusername) == 0 && strcmp(passwordi, setpassword) == 0)
        {
            printf("\n\n\t\t\t\tSuccessfully Logged in Admin Mode.\n");
            delay(3);
        }
        else
        {
            printf("\n\n\t\t\tIncorrect Login Details\n\n\t\t\tPlease Re-enter the correct credentials\n");
            delay(2);
            adminlogin();
        }
    }
    fclose(adminu);
    fclose(adminp);
    z = 12;
    return z;
}

void login() //Used for login into the application
{

    system("cls");
    char usernameip[30], passwordip[30], spassword[30];
    printf("\n\t\t\t\tWelcome to login page");
    printf("\n\n\n\n\n\n\tEnter username: ");
    scanf("%s", usernameip);
    FILE *fs;
    char *ext = ".txt";
    strcat(usernameip, ext);
    fs = fopen(usernameip, "r");
    fgets(spassword, 30, fs);
    printf("\n\n\tEnter your password: ");
    scanf("%s", passwordip);
    strcat(passwordip, "\n");

    if (strcmp(passwordip, spassword) == 0)
    {
        printf("\n\n\n\n\t\t\t\t\tSuccessful Login\n");
        delay(3);
        system("cls");
    }
    else
    {
        printf("\n\n\t\t\tIncorrect Login Details\n\n\t\t\tPlease Re-enter the correct credentials\n");
        delay(3);
        login();
    }
    fclose(fs);
}
void Homepage() //Presents the homescreen of the app
{
    printf("\n\n\n\t\t\t\t ~~~~~~~~~~  Welcome  to BLUE Bus  ~~~~~~~~~~  \n\n\n\n\n");
    delay(2);
    printf("\t1.SIGN UP (if you are new) \n\n \t2.LOGIN \n\n \t3.ADMINLOGIN\n\n \n\n  \tEnter your choice: ");
    int us1;
    scanf("%d", &us1);
    switch (us1)
    {
    case 1:
    {
        signup();
        break;
    }
    case 2:
    {
        login();
        break;
    }
    case 3:
    {
        adminlogin();
        break;
    }
    default:
    {
        printf("Invalid input entered");
        delay(3);
        system("cls");
        signup();
    }
    }
}

void booking() //Function for Seat reservation
{
    int x;
    ticketno();
    system("cls");
    status();
    i = 0;
    printf("\n\n\n\tEnter Booking Name :");
    scanf("%s", uname);
    strcpy(bname, uname);
    strcat(uname, "\n");
    printf("\n\tEnter mobile number :");
    scanf("%lld", &mob);
    printf("\n\tEnter number of passengers : ");
    scanf("%d", &pass);
    for (k = 0; k < pass; k++)
    {
        seat[k] = 0;
    }
    system("cls");
    do
    {
        do
        {
            printf("\n\n\n\n\t\tEnter seat number: ");
            scanf("%d", &seat[i]);
            x = freecheck();
            if (x == 0)
            {
                k = seat[i] - 1;
                strcpy(bookedname[k], uname);
                if (seat[i] % 2 == 1)
                {
                    printf("\n\t\tEnter passenger name: ");
                    scanf("%s", name[i]);
                    a[k] = 1;
                    i = i + 1;
                    break;
                }
                if (seat[i] % 2 == 0)
                {
                    printf("\n\t\tEnter two passenger's name: ");
                    scanf("%s %s", name[i], name[i + 1]);
                    a[k] = 1;
                    i = i + 2;
                    break;
                }
            }
        } while (x == 1);
    } while (i < pass);
    delay(3);

    pay = 200 * pass;
    system("cls");
    ticket();
    update();
}

int status() //Returns the seat status of the bus
{

    system("cls");
    printf("\n\n\n\n\n\t\t\t\t 1.MONDAY \n\t\t\t\t 2.TUESDAY \n\t\t\t\t 3.WEDNESDAY  \n\t\t\t\t 4.THURSDAY \n \t\t\t\t 5.FRIDAY  \n\t\t\t\t 6.SATURDAY \n");
    printf("\n\t\tEnter the date of travel: ");
    scanf("%d", &date);
    system("cls");
    switch (date)
    {
    case 1:
        strcpy(cdate, "Monday");
        fp = fopen("monday.txt", " r");
        break;
    case 2:
        strcpy(cdate, "Tuesday");
        fp = fopen("tuesday.txt", " r");
        break;
    case 3:
        strcpy(cdate, "Wednesday");
        fp = fopen("wednesday.txt", "r ");
        break;
    case 4:
        strcpy(cdate, "Thursday");
        fp = fopen("thursday.txt", " r");
        break;
    case 5:
        strcpy(cdate, "Friday");
        fp = fopen("friday.txt", " r");
        break;
    case 6:
        strcpy(cdate, "Saturday");
        fp = fopen("saturday.txt", "r");
        break;
    }
    for (i = 0; i < 14; i++)
    {
        fscanf(fp, "%d", &j);
        a[i] = j;
    }
    fclose(fp);
    j = 0;
    k = 0;
    printf("\t\t\t\t~~~~~~~~~SEAT STATUS~~~~~~~~~");
    printf("\n\n");
    for (i = 0; i < 14; i = i + 2)
    {
        j = i + 1;
        k = i + 2;
        printf("\t\t\t\t%d.", j);
        if (a[i] == 0)
        {
            printf("empty\t");
        }
        if (a[i] == 1)
        {
            printf("booked\t");
        }
        printf("\t%d.", k);
        if (a[j] == 0)
        {
            printf("empty ");
        }
        if (a[j] == 1)
        {
            printf("booked ");
        }
        printf("\n");
    }
    FILE *fn;
    switch (date)
    {
    case 1:
        fn = fopen("monday1.txt", " r");
        break;
    case 2:
        fn = fopen("tuesday1.txt", " r");
        break;
    case 3:
        fn = fopen("wednesday1.txt", "r ");
        break;
    case 4:
        fn = fopen("thursday1.txt", " r");
        break;
    case 5:
        fn = fopen("friday1.txt", " r");
        break;
    case 6:
        fn = fopen("saturday1.txt", "r");
        break;
    }
    char line[30];
    int j = 0;
    while (fgets(line, 30, fn) != NULL)
    {
        strcpy(bookedname[j], line);
        j++;
    }
    fclose(fn);
    delay(2);
}

int freecheck() //Checks whether selected seat is free
{
    k = seat[i] - 1;
    if (a[k] == 1)
    {
        printf("\nSeat already booked, Try others.");
        return 1;
    }
    if (a[k] == 0)
    {
        return 0;
    }
}
void ticket() //Prints the ticket details
{
    system("cls");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~TICKET DETAILS~~~~~~~~~~~~~~~~~\n");
    printf("\n\n\t\t\tTICKET NO: %d", t);
    printf("\n\n\t\t\tNAME OF PASSENGERS : ");
    for (i = 0; i < pass; i++)
    {
        printf("%d.%s \t", i + 1, name[i]);
    }
    printf("\n\n\t\t\tDATE OF JOURNEY : %s ", cdate);
    printf("\n\n\t\t\tFROM : CHENNAI\t ");
    printf("TO : BANGALORE \n");
    printf("\n\t\t\tMOBILE : %lld \n", mob);
    printf("\n\t\t\tSeat no.  :");
    for (i = 0; i < pass; i++)
    {
        if (seat[i] != 0)
            printf("%d ", seat[i]);
    }
    printf("\n\n");
    printf("\n\n\t\t\tTOTAL AMOUNT TO BE PAID : %d \n", pay);
    booking_data();
    delay(5);
}

void empty_seat() //clears the booked seat after journey date
{
    system("cls");
    printf("\n\n\n\t\t\t\t\tSEAT EMPTIER");
    printf("\n\n\n\t\t\t\t1.MONDAY\n\n\t\t\t\t2.TUESDAY\n\n\t\t\t\t3.WEDNESDAY\n\n\t\t\t\t4.THURSDAY\n\n\t\t\t\t5.FRIDAY\n\n\t\t\t\t6.SATURDAY\n\n\t\t\t\t7.SUNDAY\n ");
    printf("Enter current date :  ");
    int date, i;
    scanf("%d", &date);
    FILE *fp;
    if (date != 1)
    {
        switch (date)
        {
        case 2:
            fp = fopen("monday.txt", "w");
            printf("\n\n\n\t\t\t\tMonday is emptied");
            break;
        case 3:
            fp = fopen("tuesday.txt", " w");
            printf("\n\n\n\t\t\t\tTuesday is emptied");
            break;
        case 4:
            fp = fopen("wednesday.txt", "w ");
            printf("\n\n\n\t\t\t\tWednesday is emptied");
            break;
        case 5:
            fp = fopen("thursday.txt", "w");
            printf("\n\n\n\t\t\t\tThursday is emptied");
            break;
        case 6:
            fp = fopen("friday.txt", " w");
            printf("\n\n\n\t\t\t\tFriday is emptied");
            break;
        case 7:
            fp = fopen("saturday.txt", "w");
            printf("\n\n\n\t\t\t\tSaturday is emptied");
            break;
        }
        int j = 0;
        for (i = 0; i < 14; i++)
        {
            fprintf(fp, "%d\n", j);
        }

        fclose(fp);
        FILE *fn;
        switch (date)
        {
        case 2:
            fn = fopen("monday1.txt", "w");
            break;
        case 3:
            fn = fopen("tuesday1.txt", "w");
            break;
        case 4:
            fn = fopen("wednesday1.txt", "w");
            break;
        case 5:
            fn = fopen("thursday1.txt", "w");
            break;
        case 6:
            fn = fopen("friday1.txt", "w");
            break;
        case 7:
            fn = fopen("saturday1.txt", "w");
            break;
        }
        for (i = 0; i < 14; i++)
        {
            fprintf(fn, "Empty\n");
        }

        fclose(fn);
    }
    else
    {
        printf("\n\n\t\t\tNo buses to empty");
    }
    delay(3);
}

void update() //Updates the changes in the txt files
{
    switch (date)
    {
    case 1:
        fp = fopen("monday.txt", "w");
        break;
    case 2:
        fp = fopen("tuesday.txt", " w");
        break;
    case 3:
        fp = fopen("wednesday.txt", "w ");
        break;
    case 4:
        fp = fopen("thursday.txt", "w");
        break;
    case 5:
        fp = fopen("friday.txt", " w");
        break;
    case 6:
        fp = fopen("saturday.txt", "w");
        break;
    }
    for (i = 0; i < 14; i++)
    {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    FILE *fn;
    switch (date)
    {
    case 1:
        fn = fopen("monday1.txt", "w");
        break;
    case 2:
        fn = fopen("tuesday1.txt", "w");
        break;
    case 3:
        fn = fopen("wednesday1.txt", "w");
        break;
    case 4:
        fn = fopen("thursday1.txt", "w");
        break;
    case 5:
        fn = fopen("friday1.txt", "w");
        break;
    case 6:
        fn = fopen("saturday1.txt", "w");
        break;
    }
    for (j = 0; j < 14; j++)
    {
        fprintf(fn, "%s", bookedname[j]);
    }
    fclose(fn);
}

void user_rating() //Obtains ratings from the user
{
    printf("\n\n\n\t\t\tEnter rating(1-5) :  ");
    scanf("%d", &rat);
    c[0] = 0;
    c[1] = 0;
    FILE *fp;
    fp = fopen("rating.txt", "r");
    for (i = 0; i < 2; i++)
    {
        fscanf(fp, "%d", &c[i]);
    }
    fclose(fp);
    c[0] = c[0] + rat;
    ++c[1];
    printf("\n\n\n\n\t\t\tThanks for rating us");
    fp = fopen("rating.txt", "w");
    for (i = 0; i < 2; i++)
    {
        fprintf(fp, "%d\n", c[i]);
    }
    fclose(fp);
}

void rate() //Reads rating from file
{
    FILE *fp;
    fp = fopen("rating.txt", "r");
    for (i = 0; i < 2; i++)
    {
        fscanf(fp, "%d", &c[i]);
    }
    fclose(fp);
    ratings = (float)c[0] / (float)c[1];
    printf("\n\n\n\n\t\t\tRatings: %f", ratings);
    delay(2);
}

void cancl() //Function to cancel booked seat
{
    status();
    printf("\n\n\t\tEnter username : ");
    scanf("%s", uname);
    strcpy(bname, uname);
    printf("\n\n\t\tEnter Mobile Number : ");
    scanf("%lld", &mob);
    printf("\n\n\t\tEnter no of seats to cancel : ");
    scanf("%d", &cn);
    pay = 0;
    strcat(uname, "\n");
    for (i = 0; i < cn; i++)
    {
        printf("\n\n\t\tEnter seat no. : ");
        scanf("%d", &sn);
        if (strcmp(bookedname[sn - 1], uname) == 0)
        {
            q[i] = sn;
            a[sn - 1] = 0;
            strcpy(bookedname[sn - 1], "Empty\n");
            if (sn % 2 == 0)
            {
                pay = pay + 200;
            }
            else
            {
                pay = pay + 100;
            }
        }
        else
        {
            printf("\n\n\t\tWrong details");
            q[i] = 0;
        }
    }
    if (pay != 0)
    {
        update();
        cancl_data();
        refund();
    }
    delay(3);
    system("cls");
}

void refund() //Refunds the amount 50 percent of booking fee
{
    printf("\n\n\t\tYour seats are cancelled succesfully");
    delay(3);
    system("cls");
    printf("\n\n\n\n\n\t\t\tDisclaimer:ONLY 50 PERCENT OF AMOUNT WILL BE REFUNDED");
    printf("\n\n\n\t\t\t\tCancelled seats: ");
    for (i = 0; i < cn; i++)
    {
        if (q[i] != 0)
            printf("%d ", q[i]);
    }
    printf("\n\n\t\t\t\tYour %d rupees will be refunded", pay);
}
void booking_data() //stores the ticket details in database
{
    FILE *fs;
    fs = fopen("Bookeddata.txt", "a");
    fprintf(fs, "T.No : %d Name : %s Date of journey : %s No.of passengers : %d Mobile : %lld Amount : %d ", t, bname, cdate, pass, mob, pay);
    fprintf(fs, "Seats :");
    for (i = 0; i < pass; i++)
    {
        if (seat[i] != 0)
            fprintf(fs, "%d ", seat[i]);
    }
    fprintf(fs, "\n");
    fclose(fs);
}
void cancl_data() //stores the ticket details in database
{
    FILE *fs;
    fs = fopen("cancldata.txt", "a");
    fprintf(fs, "Name : %s Moblie : %lld Date of journey : %s No.of seats : %d  Amount : %d ", bname, mob, cdate, cn, pay);
    fprintf(fs, "Seats :");
    for (i = 0; i < cn; i++)
    {
        if (q[i] != 0)
            fprintf(fs, "%d ", q[i]);
    }
    fprintf(fs, "\n");
    fclose(fs);
}

void ticketno()
{
    int t1 = 0;
    t = 0;
    FILE *fs;
    fs = fopen("ticketno.txt", "r");
    fscanf(fs, "%d", &t1);
    t = t1 + 1;
    fclose(fs);
    fs = fopen("ticketno.txt", "w");
    fprintf(fs, "%d", t);
    fclose(fs);
}

void display_bookings()
{
    system("cls");
    printf("\n\n\t\t\tDISPLAYING BOOKED DATA\n\n");
    FILE *fp;
    fp = fopen("Bookeddata.txt", "r");
    while (fgets(line, 499, fp) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(fp);
    delay(7);
}

void display_cancl()
{
    system("cls");
    printf("\n\n\t\t\tDISPLAYING CANCELED DATA\n\n");
    FILE *fp;
    fp = fopen("cancldata.txt", "r");
    while (fgets(line, 499, fp) != NULL)
    {
        printf("%s\n", line);
    }
    fclose(fp);
    delay(7);
}

int main()
{
    Homepage();
    if (z == 12)
    {
        do
        {
            system("cls");
            printf("\n\n\t\t\t\t\tADMIN PAGE");
            printf("\n\n\n\n\t1.SEAT EMPTIER \n\n\t2.VIEW BOOKINGS\n\n\t3.VIEW CANCELLATION \n\n\t4.EXIT");
            printf("\n\n\t\tEnter Your Choice : ");
            scanf("%d", &p);
            switch (p)
            {
            case 1:
                empty_seat();
                break;

            case 2:
                display_bookings();
                break;

            case 3:
                display_cancl();
                break;

            case 4:
                system("cls");
                printf("\n\n\n\t\t\tYOU HAVE LOGGED OUT");
                delay(3);
                break;

            default:
                printf("\n\n\t\t\tEnter a Valid Number");
                break;
            }
        } while (p != 4);
    }

    else
    {
        do
        {
            system("cls");
            printf("\n\n\n\n\t1.BOOK TICKET \n\n\t2.STATUS \n\n\t3.CANCEL \n\n\t4.FEEDBACK \n\n\t5.EXIT\n\n");
            printf("\tEnter your Choice : ");
            scanf("%d", &p);
            system("cls");
            switch (p)
            {
            case 1:
                booking();
                break;
            case 2:
                status();
                break;
            case 3:
                cancl();
                break;
            case 4:
                user_rating();
                rate();
                break;
            case 5:
                printf("\n\n\n\t\t\t~~~~~~~~~~~~~~~Thanks for using our system~~~~~~~~~~~~  ");
                printf("\n\n\n\t\t\t\tDESIGNED BY\n\n\t\t\t\t\t*  Abhinav\n\t\t\t\t\t*  Arvind\n\t\t\t\t\t*  Hari\n\t\t\t\t\t*  Surzith");
                rate();
                break;
            default:
                printf("\nEnter a valid number");
                break;
            }
        } while (p != 5);
        return 0;
    }
}
