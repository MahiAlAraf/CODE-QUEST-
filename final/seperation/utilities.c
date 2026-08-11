#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"utilities.h"

//linking global variables..........extern means the variable exists in another file
extern char Name[50];
extern int Coin;
extern int HP;
extern int Max_HP;
extern int XP;
extern int Iron_shield;   
extern int Pause;
extern int Vibranium_sheld;
extern int dubble_XP;
//now the function Definitions..........
void clear_screen()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");//for Linux and Macos
    #endif
}
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void enter_to_continue() {
    printf("\nPress Enter to continue...");
    getchar();
}
void current_status() {
    printf("\n\n<------------------your current status---------------->\n");
    printf("       %d HP  ;   %d   XP    ;    %d   Coins\n", HP, XP, Coin);
    HP_Bar();
    level_status();
}
void level_status()
{
    if (XP > 85) {
        printf("    Level  :   Expert\n");
    } else if (XP > 75) {
        printf("    Level  :   Advanced\n");
    } else if (XP > 50) {
        printf("    Level   :    Intermediate\n");
    } else if (XP > 25) {
        printf("    Level    :   Noob\n");
    } else {
        printf("    Level     :  Beginner\n");
    }
}
void HP_Bar() {
    int filled = (HP * 10) / Max_HP;
    int i;

    printf("HP[");
    for (i = 0; i < 10; i++) {
        if (i < filled) {
            printf("#");
        } else {
            printf(".");
        }
    }
    printf("]%d/%d\n", HP, Max_HP);
}
//__________________VALIDATED ANSWER INPUT_____________
int answer_input_loop() {
    int answer;
    while (1) {
        scanf("%d", &answer);
        flush_input();
        if (answer == 1 || answer == 2 || answer == 3 || answer == 4) {
            return answer;
        } else {
            printf("Invalid Input....\nEnter again: ");
        }
    }
}
//_____________________________________Yes NO loop______________________________________
char Yes_No_loop()
{
    char answer;
    while(1)
    {
        scanf(" %c",&answer);
        flush_input();
        if(answer=='y'||answer=='Y'||answer=='n'||answer=='N')
        {
            return answer;
        }
        else
        {
            printf("Invalid Input...\nEnter correctly :");
        }
    }
}
//____________________________________QUESTION / BATTLE SYSTEM________________________________
int correct_answer(char question[], char option[4][60], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]) {
    int i, answer, is_wrong;
    Market_open();

    printf("\n%s\n", question);
    for (i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, option[i]);
    }
    printf("Enter Answer: ");
    answer = answer_input_loop();

    if (answer == correctAns) {
        if(dubble_XP==1)
        {
            reward_XP=reward_XP*2;
            dubble_XP=0;
            printf("Your Double XP Potion doubles your XP reward!\n");
        }
        printf("Correct!...\n+%d XP  +%d Coin\n", reward_XP, Reward_Coin);
        XP = XP + reward_XP;
        Coin = Coin + Reward_Coin;
        is_wrong = 0;
    } else {
        int actual_penalty = HP_Minus_if_wrong;
        printf("Wrong! The correct answer is: %s\n", option[correctAns - 1]);
        if (Vibranium_sheld == 1) {
            actual_penalty = 0;
            Vibranium_sheld = 0;
            printf("Your Vibranium Shield absorbs all the damage!\n");
        }
        else if (Iron_shield == 1) {
            actual_penalty = actual_penalty / 2;
            Iron_shield = 0;
            printf("Your Iron Shield absorbs half the damage!\n");
        }
        printf("-%d HP\n", actual_penalty);
        HP = HP - actual_penalty;
        if (HP < 0) {
            HP = 0;
        }
        HP_Bar();
        is_wrong = 1;
    }
    Market_save();

    printf("Want to see why?...\n");
    char yes;
    printf("\n Choose : y/n  :");
    yes = Yes_No_loop();
    if (yes == 'y' || yes=='Y') 
    {
        for (i = 0; i < 4; i++) {
            printf("%s\n", explanation[i]);
        }
        enter_to_continue();
        clear_screen();
    }
    else
    {
        clear_screen();
    }
    return is_wrong;
}
char lesson_navigation(int section, int total_sections)
{
    char input;
    printf("\n");

    if(section > 1)  
    {
        printf("[1] Previous Section\n");
    }

    printf("Press ENTER to continue...\n");

    input = getchar(); 

    if(input == '\n')  
    {
        if(section < total_sections)  
        {
            return 'N'; 
        }
        else
        {
            return 'E'; 
        }
    }
    if(input == '1' && section > 1) 
    {
        flush_input(); 
        return 'P'; 
    }

    flush_input(); 
    printf("Invalid input.\n");
    return 'I'; 
}

int menu_input(int min, int max)
{
    int choice;

    while(1)
    {
        if(scanf("%d", &choice) == 1)  
        {
            flush_input();  

            if(choice >= min && choice <= max){  
                return choice;  // valid choice entered, exit the input loop
            }
        }
        else
        {
            flush_input();  
        }

        printf("Invalid input.\n");
        printf("Enter your choice again: ");
    }
}
void traning_answer(char question[], char option[4][60], int correctAns,char explanation[4][150])
{
    int i;
    int answer;

    printf("\n%s\n", question);

    for(i = 0; i < 4; i++)
    {
        printf("%d. %s\n", i + 1, option[i]);
    }

    printf("Enter Answer: ");
    answer = answer_input_loop();  

    if(answer == correctAns)  
    {
        printf("\nCorrect Answer!\n");
        printf("%s\n", explanation[correctAns - 1]);
        return;
    }
    else
    {
        printf("\nWrong Answer!\n");

        printf("Your Answer: [%d] %s\n", answer, option[answer - 1]);
        printf("Why it is wrong: %s\n", explanation[answer - 1]);

        printf("\nCorrect Answer: [%d] %s\n",
               correctAns,
               option[correctAns - 1]);

        printf("Explanation: %s\n",
               explanation[correctAns - 1]);

        enter_to_continue();

        return;
    }
}
//All file functions...............
void profile_reset()
{
    FILE *reset;
    reset=fopen("profile.txt","w");
    fclose(reset);
}
void profile_save()
{
   printf("Enter your name: ");
    scanf("%s",Name);
    flush_input();
    printf("\nWelcome %s, your journey begins!\n", Name);
    FILE *save;
    save=fopen("profile.txt","w");
    fprintf(save, "%49s",Name);
    fclose(save);
}
int profile_open()
{
    FILE *save;
    save=fopen("profile.txt","r");
    if (save == NULL) {
        return 0;
    }
    fscanf(save,"%s\n",Name);
    fclose(save);
    return 1;
}
void file_reset()
{
    FILE *reset;
    reset=fopen("save.txt","w");
    fprintf(reset, "%d %d %d %d %d",1,100,0,0,0);
    fclose(reset);
}
int file_open()
{
    FILE *save;
    save=fopen("save.txt","r");
    if (save == NULL) {
        return 0;
    }
    fscanf(save,"%d %d %d %d %d",&Pause,&HP,&Coin,&XP,&Iron_shield);
    fclose(save);
    return 1;
}
void file_save()
{
    FILE *save;
    save=fopen("save.txt","w");
    fprintf(save,"%d %d %d %d %d",Pause,HP,Coin,XP,Iron_shield);
    fclose(save);
}
void Market_reset()
{
    FILE *reset;
    reset=fopen("market.txt","w");
    fprintf(reset, "%d %d",0,0);
    fclose(reset);
}
void Market_open()
{
    FILE *open;
    open=fopen("market.txt","r");
    if(open == NULL)
    {
        Market_reset();
        open=fopen("market.txt","r");
    }
    fscanf(open,"%d %d",&Vibranium_sheld,&dubble_XP);
    fclose(open);
}
void Market_save()
{
    FILE *save;
    save=fopen("market.txt","w");
    fprintf(save, "%d %d",Vibranium_sheld,dubble_XP);
    fclose(save);
}
