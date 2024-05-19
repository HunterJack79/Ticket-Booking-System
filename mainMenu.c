#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#pragma warning(disable:4996)
#define RED(string) "\x1b[31m" string "\x1b[0m"
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define GREY(string) "\x1b[38;5;245m" string "\x1b[0m"
#define BROWN(string) "\x1b[38;5;130m" string "\x1b[0m"

typedef struct {
	char paxName[20];
	char paxIC[13];
}PaxDetail;

typedef struct {
	char paymentMethod[20];
	double amount;
	double totalAmount;
}Payment;

typedef struct {
	char departureStation[30];
	char arrivalStation[30];
	int departureMonth;
	int departureDay;
	int departureHour;
	int departureMinute;
	int arrivalHour;
	int arrivalMinute;
}StationDetail;

typedef struct {
	char coach;
	int seatNumber;
}SeatDetail;

typedef struct {
	int trainID;
	SeatDetail seatDetail[6];
}TrainDetail;

typedef struct {
	int bYear;
	int bMonth;
	int bDay;
}BookingDate;

typedef struct {
	char ticketID[13];
	char memberID[13];
	int pax;
	PaxDetail pDetail[6];
	Payment payment;
	StationDetail sDetail;
	TrainDetail tDetail;
	BookingDate bDate;
	char ticketStatus[20];
}Ticket;

void asciiArt();
int displayMenu();
void welcome();

void main() {
	int option;

	do {

		asciiArt();

		welcome();

		option = displayMenu();

		switch (option) {
		case 1:
			loginStaff();
			break;
		case 2:
			displayMembersMenu();
			break;
		case 3:
			exit(-1);
			break;
		default:
			printf("Invalid Option\n");
			system("pause");
			system("cls");
		}
	} while (option != 3);

	getch();
}


//Get Main Menu Option
int displayMenu() {
	int option;

	printf("\n=========== Main Menu ==========\n");
	printf("1.Staff / Admin Login\n");
	printf("2.Member Login\n");
	printf("3.Exit");
	line();
	printf("\nSelect your mode: ");
	rewind(stdin);
	scanf("%d", &option);

	return option;
}

void asciiArt() {
	printf(GREY("\t\t\t\t                                      (@@@)     (@@@@@)              \n"));
	printf(GREY("\t\t\t\t                          (@@@@@@@)   (@@@@@)       (@@@@@@@@@@@)     \n"));
	printf(GREY("\t\t\t\t                     (@@@)     (@@@@@@@)   (@@@@@@)             (@@@) \n"));
	printf(GREY("\t\t\t\t                (@@@@@@)    (@@@@@@)                (@)               \n"));
	printf(GREY("\t\t\t\t                                (@@)     (@@@@@@@)        (@@@@@@@)   \n"));
	printf(GREY("\t\t\t\t            (@@@)  (@@@@)           (@@)                               \n"));
	printf(GREY("\t\t\t\t         (@@)              (@@@)\n"));
	printf("\t\t\t\t        .-.  \n");
	printf("\t\t\t\t        ] [    .-.      _    .-----.        \n");
	printf("\t\t\t\t      .\#   \#\#\#\#   \#\#\#\#\#\# \#\#\#\# | .--`          \n");
	printf("\t\t\t\t     (:--:--:--:--:--:--:--:-| [___    .------------------------. \n");
	printf("\t\t\t\t      | ");
	printf(RED("KTM"));
	printf(" :  :  :  :  :  : [_9_] |'='|.----------------------.|   \n");
	printf("\t\t\t\t     /|.___________________________|___|'--.___.--.___.--.___.-'|   \n");
	printf("\t\t\t\t    / ||_.--.______.--.______.--._ |---\'--\-.-/==\-.-/==\-.-/-'/--   \n");
	printf("\t\t\t\t   /__;^=(==)======(==)======(==)=^#^^^ ^^^^(-)^^^^(-)^^^^(-)^^^ aac   \n");
	printf(BROWN("\t\t\t\t ###^####^###^###^###^###^###^###^###^###^###^###^###^###^###^###^###     \n\n\n"));
}

void welcome() {
	char day[7][10] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	SYSTEMTIME t; // Declare SYSTEMTIME struct

	GetLocalTime(&t); // Fill out the struct so that it can be used

	printf("=================================================================================================================================\n\n");
	printf("================================================  ");
	printf(RED("Welcome To KTM Booking System"));
	printf("  ================================================\n\n");
	printf("=================================================================================================================================\n\n");
	printf("Day : %s\t\t\t\t\t Date : %02d/%02d/%04d\t\t\t\t\tTime : %02d:%02d ", day[t.wDayOfWeek], t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
	if (t.wHour < 12) {
		printf("AM\n\n");
	}
	else {
		printf("PM\n\n");
	}
}