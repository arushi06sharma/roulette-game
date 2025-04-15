// DECLARING ALL HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Defining ANSI codes as some strings for ease in use when using color-coding.
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"
#define BBLUE   "\033[94m"
// Defining particular global variables since they'll be accessed by multiple functions.
int balance = 1000; // User deposited balance, user is allowed to bet money within their balance limit.
int bet_money = 0; // The amount being put up for bet by the user, is initialized to 0 due to updating the value.
int bet_choice = 0; // Choice within the bet that the user wishes to make.
int bet_type = 0; // Choice of what bet the user wishes to make.
// Declaring global array of red numbers on the wheel. Numbers outside this array will be green.
const int red_numbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
// Function to identify whether a number is red or not; used for printing & picking red colored numbers.
int is_red(int num) {
    for (int i = 0; i < 18; i++) {
        if (num == red_numbers[i]) {
            return 1;
        }
    }
    return 0;
}
// Function to pick color associated to the particular number on the wheel.
const char* pickColor(int num) {
    if (num == 0) {
        return WHITE;  // 0 gets white since it's a house slot.
    } else if (is_red(num)) {
        return RED; // Numbers belonging to red_numbers array will be associated RED ANSI C codes for the displayed wheel.
    } else {
        return GREEN; // Numbers NOT belonging to red_numbers array will be associated GREEN ANSI C codes for the displayed wheel.
    }
}
// Function to handle and validate bets.
void place_bets(int *bet_type, int *bet_choice, int *bet_money, int balance) {
    // Printing the menu of the type of bets.
    printf("\033[1;33;4mBET ON THE ROULETTE WHEEL: Choose your bet!" RESET);
    printf("\n\t 1. %sCOLOUR%s %sPOWER%s! Bet on whether the resulting number will either be red or green. \n\t\tPayouts are 1:1! Wager, if won, will be multiplied by: 1.\n", RED, RESET, GREEN, RESET);
    printf("\n\t 2. %sODD%s or %sEVEN%s! Bet on whether the resulting number will either be even or odd. \n\t\tPayouts are 1:1! Wager, if won, will be multiplied by: 1.\n", MAGENTA, RESET, CYAN, RESET);
    printf("\n\t 3. %sA DIME A DOZEN%s! Bet on whether the resulting number will be in which set of dozen numbers: \n\t\tChoose from: (0-12), (13-24), (25-36)! \n\t\tPayouts are 1:3! Wager, if won, will be multiplied by: 3.\n", YELLOW, RESET);
    printf("\n\t 4. %sUPPING THE ODDS: FOUR BET%s! Bet on whether the resulting number will be 0, 1, 2, or 3. \n\t\tPayouts are 1:8! Wager, if won, will be multiplied by: 8.\n\n", BBLUE, RESET);
    // A do-while loop to take user input for bet type, & check for validity of input.
    do {
        printf("\033[4;mEnter the serial number of the bet you would like to choose:" RESET " ");
        scanf("%d", bet_type);
        if (*bet_type < 1 || *bet_type > 4) {
            printf(RED "[[ERROR!]] INVALID INPUT: Enter a number among 1, 2, 3 and 4. Try again!\n" RESET);
            while(getchar()!='\n'); // Clearing the buffer for scanf, handles alphabetic/non-numeric input errors.
        }
    } while (*bet_type < 1 || *bet_type > 4);
    // Switch case to handle the taking of bets (& validating the input along the process).
    switch (*bet_type) {
        // The case for handling red/green (color-based) bets
        case 1:
            printf("YOU HAVE CHOSEN: \033[31mCOLOUR\033[0m \033[32mPOWER\033[0m!\n");
            do {
                printf("Make your bet! Enter 1 for RED and 0 for GREEN! :: ");
                // Handling error cases for any input that is not 1 or 0.
                if (scanf("%d", bet_choice) != 1) {
                    printf(RED "[[ERROR!]] ENTER EITHER 1 OR 0.\n" RESET);
                    while(getchar()!='\n');
                } else if (*bet_choice < 0 || *bet_choice > 1) {
                    printf(RED "[[ERROR!]] ENTER EITHER 1 OR 0.\n" RESET);
                    while(getchar()!='\n');
                } else {
                    break;
                }
            } while (1);
            break;
        // The case for handling odd or even bets
        case 2:
            printf("YOU HAVE CHOSEN: \033[35mODD\033[0m OR \033[36mEVEN\033[0m!\n");
            do {
                printf("Make your bet! Enter 1 for ODD and 0 for EVEN! :: ");
                if (scanf("%d", bet_choice) != 1) {
                    printf(RED "[[ERROR!]] ENTER EITHER 1 OR 0.\n" RESET);
                    while(getchar()!='\n');
                } else if (*bet_choice < 0 || *bet_choice > 1) {
                    printf(RED "[[ERROR!]] ENTER EITHER 1 OR 0.\n" RESET);
                    while(getchar()!='\n');
                } else {
                    break;
                }
            } while (1);
            break;
        // The case for handling dozen bets
        case 3:
            printf("YOU HAVE CHOSEN: \033[33mA DIME A DOZEN\033[0m!\n");
            do {
                printf("Make your bet! Enter 1 for (0-12), 2 for (13-24) and 3 for (25-36) :: ");
                scanf("%d", bet_choice);
                if (*bet_choice != 1 && *bet_choice != 2 && *bet_choice != 3) {
                    printf(RED "[[ERROR!]] INVALID INPUT: Enter either 1, 2 or 3. Try again!\n" RESET);
                }
                while(getchar()!='\n');
            } while (*bet_choice != 1 && *bet_choice != 2 && *bet_choice != 3);
            break;
        // The case for handling a four bet
        case 4:
            printf("YOU HAVE CHOSEN: \033[94mUPPING THE ODDS: FOUR BET\033[0m!\n");
            printf("Your choice of betting has already been logged as the numbers: 0, 1, 2 and 3.\n");
            break;
        // An unreachable case in the case of an error.
        default:
            printf(RED "404: ERROR IN SELECTING BET.");
            break;
    }
    // An infinite while loop to take correct betting amount (Handles errors & validates the input)
    while (1) {
        printf("Enter your betting amount [CURRENT BALANCE: $%d]: $", balance);
        scanf("%d", bet_money);
        if (*bet_money > balance) {
            printf(RED "[[ERROR!]] INVALID BETTING AMOUNT: You have insufficient funds to be betting $%d. Try again...\n" RESET, *bet_money);
            while(getchar()!='\n');
        }
        else if (*bet_money < 1) {
            printf(RED "[[ERROR!]] MINIMUM BETTING AMOUNT IS $1. Try again...\n" RESET);
            while(getchar()!='\n'); // Used as a buffer to clear scanf.
        }
        else {
            break;
        }
    }
}
// Function to assign payout multiplier--used for cases when the bet has been won
int payout_multiplier(int bet_type) {
    switch (bet_type) {
    case 1:
    case 2:
        return 1;
        break;
    case 3:
        return 3;
        break;
    default:
        return 8;
        break;
    }
}
// Function to spin the wheel and display the wheel
int spinWheel() {
    // Array of numbers on the roulette wheel in a random order as is observed in real life European roulette to maintain integrity to real model
    int a[37] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
    srand(time(0)); // To set random generator's seed to 0--ensuring true randomness in the result of the wheel, avoiding/minimizing repetition of the result in consequent spins
    int i = 0, j = 0, seconds = rand()%(37) + 20; // So the wheel spins for any time between 20-57 secs (Ensuring a time interval where any number on the wheel has a probability of appearing (reducing biases)
    while(j <= seconds) {
        // The wheel is formatted using spaces, and in the place of each number is a left padded number to maintain the formatting during spinning
        // The spinning is essentially just the array shifting one element forward with every frame, giving a sense of animation by employing system("cls")
        printf("							Spinning...\n");
        printf("						 	    VV\n");
        printf("							    %s%02d%s\n", pickColor(a[(i+0)%37]), a[(i+0)%37], RESET);
        printf("					         %s%02d%s	              %s%02d%s\n", pickColor(a[(i+1)%37]), a[(i+1)%37], RESET, pickColor(a[(i+36)%37]), a[(i+36)%37], RESET);
        printf("					    %s%02d%s                              %s%02d%s\n", pickColor(a[(i+2)%37]), a[(i+2)%37], RESET, pickColor(a[(i+35)%37]), a[(i+35)%37], RESET);
        printf("			   		  %s%02d%s                   	              %s%02d%s\n", pickColor(a[(i+3)%37]), a[(i+3)%37], RESET, pickColor(a[(i+34)%37]), a[(i+34)%37], RESET);
        printf("                                        %s%02d%s                      	        %s%02d%s\n", pickColor(a[(i+4)%37]), a[(i+4)%37], RESET, pickColor(a[(i+33)%37]), a[(i+33)%37], RESET);
        printf("                                       %s%02d%s               		         %s%02d%s\n", pickColor(a[(i+5)%37]), a[(i+5)%37], RESET, pickColor(a[(i+32)%37]), a[(i+32)%37], RESET);
        printf("                                      %s%02d%s                                          %s%02d%s\n", pickColor(a[(i+6)%37]), a[(i+6)%37], RESET, pickColor(a[(i+31)%37]), a[(i+31)%37], RESET);
        printf("                                     %s%02d%s          	                           %s%02d%s\n", pickColor(a[(i+7)%37]), a[(i+7)%37], RESET, pickColor(a[(i+30)%37]), a[(i+30)%37], RESET);
        printf("                                     %s%02d%s            	                           %s%02d%s\n", pickColor(a[(i+8)%37]), a[(i+8)%37], RESET, pickColor(a[(i+29)%37]), a[(i+29)%37], RESET);
        printf("                                     %s%02d%s                     	                   %s%02d%s\n", pickColor(a[(i+9)%37]), a[(i+9)%37], RESET, pickColor(a[(i+28)%37]), a[(i+28)%37], RESET);
        printf("                                     %s%02d%s                                 	  %s%02d%s\n", pickColor(a[(i+10)%37]), a[(i+10)%37], RESET, pickColor(a[(i+27)%37]), a[(i+27)%37], RESET);
        printf("                                      %s%02d%s         	        	         %s%02d%s\n", pickColor(a[(i+11)%37]), a[(i+11)%37], RESET, pickColor(a[(i+26)%37]), a[(i+26)%37], RESET);
        printf("                                       %s%02d%s         	                 	%s%02d%s\n", pickColor(a[(i+12)%37]), a[(i+12)%37], RESET, pickColor(a[(i+25)%37]), a[(i+25)%37], RESET);
        printf("                                        %s%02d%s	                               %s%02d%s\n", pickColor(a[(i+13)%37]), a[(i+13)%37], RESET, pickColor(a[(i+24)%37]), a[(i+24)%37], RESET);
        printf("                                         %s%02d%s              	             %s%02d%s\n", pickColor(a[(i+14)%37]), a[(i+14)%37], RESET, pickColor(a[(i+23)%37]), a[(i+23)%37], RESET);
        printf("                                           %s%02d%s           	     	   %s%02d%s\n", pickColor(a[(i+15)%37]), a[(i+15)%37], RESET, pickColor(a[(i+22)%37]), a[(i+22)%37], RESET);
        printf("                                              %s%02d%s         	        %s%02d%s\n", pickColor(a[(i+16)%37]), a[(i+16)%37], RESET, pickColor(a[(i+21)%37]), a[(i+21)%37], RESET);
        printf("                                                  %s%02d%s      	    %s%02d%s\n", pickColor(a[(i+17)%37]), a[(i+17)%37], RESET, pickColor(a[(i+20)%37]), a[(i+20)%37], RESET);
        printf("                                                       %s%02d%s     %s%02d%s\n", pickColor(a[(i+18)%37]), a[(i+18)%37], RESET, pickColor(a[(i+19)%37]), a[(i+19)%37], RESET);
        usleep(20000 + 5000*j); // Dynamic delay to give the effect of the wheel slowing down realistically, i.e. losing momentum.
        if (j<seconds) {
            system("cls"); // Clearing screen and displaying next frame of wheel to give a sense of animation
        }
        // incrementing i, j  to keep the wheel spinning and time progressing
        i++;
        j++;
    }
    // Once the wheel is done spinning, output of result is displayed and returned to store in the result variable.
    printf("\n\n\t\t\t\t\t \033[4mRESULT\033[0m: The number you spun is: %s%d%s!\a\n\n", pickColor(a[(i+36)%37]), a[(i+36)%37], RESET); // Using ANSI codes to format text & adding a little jingle for effect
    return a[(i+36)%37];
}
// Function to update the balance accordingly to the result (victory/loss)
void win(int num) {
    if (num == 1) {
        printf("\n\t\t\t\t\033[4mCONGRATS! YOU WIN! [You bet: $%d and won +$%d: Added $%d to your balance!]\n" RESET, bet_money, bet_money*payout_multiplier(bet_type), bet_money + payout_multiplier(bet_type)*bet_money);
        // Updating the balance when the bet is won: bet amount is multiplied with payout multiplier, added to initial bet amount and added to the total balance
        balance = balance + bet_money + payout_multiplier(bet_type)*bet_money;
        printf("\n\t\t\t\t\t\033[1;33;4mYour current balance is: $%d\n" RESET, balance);
    }
    else {
        printf("\n\t\t\t\t\t\033[4mOH NO, YOU LOSE! [-$%d from your balance!]\n" RESET, bet_money);
        // Updating the balance when the bet is lost, only deducting the initial amount put up for bet by the user from the balance
        balance = balance - bet_money;
        printf("\n\t\t\t\t\t\033[1;33;4mYour current balance is: $%d\n" RESET, balance);
    }
}
// Function to determine result
int determineWin() {
    int result = spinWheel();
    // Accounting for each type of bet:
    switch (bet_type) {
        // Win/Lose case for red vs. green result
        case 1:
            printf("\t\t\t\t\tYOUR CHOICE: ");
            if (bet_choice) {
                printf(RED "RED" RESET "!\t");
            }
            else {
                printf(GREEN "GREEN" RESET "!\t");
            }
            printf("THE RESULT IS: ");
            if (is_red(result)) {
                printf(RED "RED" RESET "!\n");
            }
            else {
                printf(GREEN "GREEN" RESET "!\n");
            }
            (bet_choice == is_red(result)) ? win(1) : win(0);
            break;
        // Win/Lose case for odd vs. even result
        case 2:
            printf("\t\t\t\t\tYOUR CHOICE: ");
            if (bet_choice) {
                printf(MAGENTA "ODD" RESET "!\t");
            }
            else {
                printf(CYAN "EVEN" RESET "!\t");
            }
            printf("THE RESULT IS: ");
            if (result%2==1) {
                printf(MAGENTA "ODD" RESET "!\n");
            }
            else {
                printf(CYAN "EVEN" RESET "!\n");
            }
            (bet_choice%2 == result%2) ? win(1) : win(0);
            break;
        // Win/Lose case for the dozen bet
        case 3:
            printf("\t\t\t\t\tYOUR CHOICE: ");
            switch (bet_choice) {
                case 1:
                    printf("(0-12)!\t");
                    break;
                case 2:
                    printf("(13-24)!\t");
                    break;
                case 3:
                    printf("(25-36)!\t");
            }
            printf("THE RESULT IS: ");
            if (result < 13) {
                result = 1;
                printf("(0-12)!");
            }
            else if (result > 12 && result < 25) {
                result = 2;
                printf("(13-24)!");
            }
            else {
                result = 3;
                printf("(25-36)!");
            }
            (result == bet_choice) ? win(1) : win(0);
            break;
        // Win/Lose case for the four bet
        case 4:
            printf("\t\t\t\t\tYOUR CHOICE: 0, 1, 2 or 3!");
            printf("\t THE RESULT IS: %d!", result);
            if (result == 0 || result == 1 || result == 2 || result == 3) {
                win(1);
            }
            else {
                win(0);
            }
            break;
        default:
            printf("BET NOT FOUND.");
    }
}
// Function to start up the roulette game [Makes it easier to compile under gameMenu();--making apt use of functions]
void roulette() {
    int again;
    place_bets(&bet_type, &bet_choice, &bet_money, balance); // Given values are pointers and end up being initialised within the function rather than needing to be pre-declared
    determineWin();
    // A do...while loop to ask the user for another round of the roulette & handle errors (+ check validity of the input)
    do {
        printf("\n\nPlay again? (Enter 1 to play again, and 0 to go back to the main menu.): ");
        if (scanf("%d", &again) != 1) {
            printf(RED "\n[[ERROR!]] ENTER EITHER 1 OR 0." RESET);
            while(getchar()!='\n'); // To clear the buffer for scanf
        } else if (again < 0 || again > 1) {
            printf(RED "\n[[ERROR!]] ENTER EITHER 1 OR 0." RESET);
            while(getchar()!='\n'); // To clear the buffer of scanf
        } else {
            break; // If program reaches to this bit of code, the input has been validated and hence the infinite loop is broken out of.
        }
    } while (1);

    if (again) {
        system("cls"); // Clears the terminal to start a fresh new round of roulette
        roulette();
    }
    else{
        printf(MAGENTA "\033[4mTaking you back to the main menu..." RESET);
        // gameMenu();
    }
}
// Condensing into a single function for using it in main
int main() {
    roulette();
    return 0;
}
