//Name: Hasan Kaan
//Surname: Doygun
//ID: 2640464

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice(); //function that rolls a dice (0-6) and returns the number as an integer.
int scoring(int dice1, int dice2, int dice3); //function that takes dice values as integer inputs and calculates the score should be earned and return the score as an integer.
int play_user(int round); //function that plays for user , takes the round as an integer input and returns the user score of that round as an integer.
int play_computer(int round); //function that plays for computer , takes the round as an integer input and returns the computer score of that round as an integer.
int decide(int dice1, int dice2, int dice3); //function that takes dice values as integer inputs and decides whether roll a dice or not (for computer because user decides himself/herself) returns the dice number as an integer which wanted to be rolled.
void scoresheet(int round, int pctotalscore, int usertotalscore); //function that takes round, pctotalscore and usertotalscore as integer inputs and prints the total scores after each round and returns nothing(void)


int main() {
    int userscore;
    int pcscore;
    int pctotalscore = 0;
    int usertotalscore = 0;
    int mynum, yournum;
    int round = 1;
    int roundToPlay;
    printf("Welcome to Crag game.\n");
    printf("Let's get started!\n");
    printf("\nHow many rounds would you like to play? ");
    scanf("%d",&roundToPlay);

    //gets a random seed to have random results, it is for randomizing
    srand(time(NULL));

    do{
        mynum = roll_a_dice();
        yournum = roll_a_dice();
    }while(mynum == yournum);
    printf("\nI have rolled the dice and got %d!\n", mynum);
    printf("I have rolled the dice for you and you got %d!\n\n", yournum);

    while(round <= roundToPlay) //loops until current played round number bigger than the number that user wanted to play
    {
        //checks the first two dices numbers and decide who will start
        if(mynum > yournum){
            //plays a round for both user and computer , updates their total scores,
            pcscore = play_computer(round);
            pctotalscore += pcscore;
            printf("My score: %d  Total score: %d\n\n", pcscore, pctotalscore);
            userscore = play_user(round);
            usertotalscore += userscore;
            printf("Your score: %d Total score: %d\n\n", userscore, usertotalscore);
            scoresheet(round, pctotalscore, usertotalscore);
            round++;
        }
        else if(yournum > mynum){
            //plays a round for both user and computer , updates their total scores,
            userscore = play_user(round);
            usertotalscore += userscore;
            printf("Your score: %d Total score: %d\n\n", userscore, usertotalscore);
            pcscore = play_computer(round);
            pctotalscore += pcscore;
            printf("My score: %d  Total score: %d\n\n", pcscore, pctotalscore);
            scoresheet(round, pctotalscore, usertotalscore);
            round++;
        }
    }
    // Decides what to print(who won?) at the end of the program
    if(usertotalscore > pctotalscore){
        printf("YOU ARE THE WINNER!");
    }
    else if(usertotalscore == pctotalscore){
        printf("DRAW!");
    }
    else{
        printf("I AM THE WINNER!\n\n");
    }
    system("pause");
    return 0;
}
int roll_a_dice(){
    return (rand() % 6) + 1; //rand() % x takes random input between 0 and x-1 , I used (rand() % 5) + 1 because the function shouldn't return 0 , when we want a number between 0 and 5 and add 1 , we got a number between 1 and 6.
}

int scoring(int dice1, int dice2, int dice3){
    int sum = dice1 + dice2 + dice3;
    //if else chain to decide what number to return , this chain based on the chart has been given for scoring.
    if((sum == 13) && ((dice1 == dice2) || (dice1 == dice3) || (dice2 == dice3))){
        return 50;
    }
    else if(sum == 13){
        return 26;
    }
    else if(dice1 == dice2 && dice2 == dice3){
        return 25;
    }
    else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
        return 20;
    }
    else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
        return 20;
    }
    else if(dice1 == 1 && dice2 == 3 && dice3 == 5){
        return 20;
    }
    else if(dice1 == 2 && dice2 == 4 && dice3 == 6){
        return 20;
    }
    else{
        return sum;
    }
}
int decide(int dice1, int dice2, int dice3) {
    // checks whether the dice numbers are close to do a high strait ( just need one dice to change for hight straight ) if dice numbers are close to do a high straight , returns the dice number that should be rolled.
    if ((dice1 == 4 && dice2 == 5 && dice3 != 6) || (dice1 != 4 && dice2 == 5 && dice3 == 6) ||
        (dice1 == 4 && dice2 != 5 && dice3 == 6)) {
        if ((dice1 == 4) && (dice2 == 5) && (dice3 != 6)) {
            return 3;
        } else if ((dice1 != 4) && (dice2 == 5) && (dice3 == 6)) {
            return 1;
        } else if ((dice1 == 4) && (dice2 != 5) && (dice3 == 6)) {
            return 2;
        }
    }
    else {
        return 0;
    }
}
int play_user(int round){
    printf("Round %d -- Your Turn:\n-----------------------------------------\n", round);
    int dice1 = roll_a_dice(), dice2 = roll_a_dice(), dice3 = roll_a_dice();
    int userscore;
    char dec;
    printf("You got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);

    do{ //checks the character input , if not Y/N , asks again
        printf("Shall I roll for you (Y/N)? ");
        scanf(" %c", &dec);
        if((dec != 'Y' && dec != 'y') && (dec != 'N' && dec != 'n')){
            printf("Sorry, I don't understand!\n");
        }
    }while((dec != 'Y' && dec != 'y') && (dec != 'N' && dec != 'n'));

    if(dec == 'Y' || dec == 'y'){
        int keep1, keep2;
        do{ //asks for dices to keep
            printf("Which ones do you want to keep? ");
            scanf("%d %d", &keep1, &keep2);
            if((keep1 != 1 && keep1 != 2 && keep1 != 3) || (keep2 != 1 && keep2 != 2 && keep2 != 3)) // checks the numbers if there is a number not between 1-3
            {
                printf("Sorry, wrong input!\n\n");
            }
        }while((keep1 != 1 && keep1 != 2 && keep1 != 3) || (keep2 != 1 && keep2 != 2 && keep2 != 3) || (keep1 == keep2)); //checks whether the numbers are between 1-3 and not equal each other.

        // checks the dice numbers that wanted to keep and rolls the other number (ex: keep1 = 1, keep2 = 2, rolls the third dice ) then prints the new numbers
        if((keep1 == 1 && keep2 == 2) ||(keep1 == 2 && keep2 == 1)){
            dice3 = roll_a_dice();
            printf("\nYou got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);
        }
        else if((keep1 == 1 && keep2 == 3) ||(keep1 == 3 && keep2 == 1)){
            dice2 = roll_a_dice();
            printf("\nYou got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);
        }
        else if((keep1 == 2 && keep2 == 3) ||(keep1 == 3 && keep2 == 1)){
            dice1 = roll_a_dice();
            printf("\nYou got -> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);
        }
    }
    else if(dec == 'N' || dec == 'n'){
        printf("\n");
    }
    userscore = scoring(dice1 ,dice2, dice3);

    if(userscore == 50) // it wasn't told in the description but I saw in the sample run when user makes crag , program prints Crag!!, I didn't put this code in play_computer function because I didn't saw it in the simple run.
    {
        printf("Crag!!\n\n");
    }
    return userscore;
}

int play_computer(int round){
    printf("Round %d -- My Turn:\n-----------------------------------------\n", round);
    int dice1 = roll_a_dice(), dice2 = roll_a_dice(), dice3 = roll_a_dice();
    int pcscore;
    printf("I rolled them and I got \n-> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n", dice1, dice2, dice3);

    int dec = decide(dice1, dice2, dice3); // uses decide function to decide for computer whether roll a dice or not.
    //if-else chain checks the value of decide function which is saved in dec , then rolls the dice it should roll (decided by value of dec) and prints the new dice numbers.
    if (dec == 1) {
        printf("Rolled dice 1!\n");
        dice1 = roll_a_dice();
        printf("-> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);

    } else if (dec == 2) {
        printf("Rolled dice 2!\n");
        dice2 = roll_a_dice();
        printf("-> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);

    } else if (dec == 3) {
        printf("Rolled dice 3!\n");
        dice3 = roll_a_dice();
        printf("-> [Dice 1]: %d [Dice 2]: %d [Dice 3]: %d\n\n", dice1, dice2, dice3);

    }
    pcscore = scoring(dice1, dice2, dice3);
    return pcscore;
}
void scoresheet(int round, int pctotalscore, int usertotalscore){
    //prints the total scores after rounds.
    printf("Our scoresheet after round %d:\n=============================\nMy score:       Your score:\n    %d               %d\n\n",round,pctotalscore, usertotalscore);
}