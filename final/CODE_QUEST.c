#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//_________________________global_variables______________________
char Name[50];
int Coin = 0;
int HP = 100;
int Max_HP = 100;
int XP = 0;
int Iron_shield = 0;   
int Pause;
int Vibranium_sheld=0;
int dubble_XP=0;
//_______________________function prototypes_____________________
void clear_screen();
void enter_to_continue();
char continue_or_back();
void current_status();
void level_status();
void flush_input();
void HP_Bar();
int answer_input_loop();
char Yes_No_loop();
int correct_answer(char question[], char option[4][60], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]);
void show_menu();
int profile_open();
void profile_save();
void profile_reset();
void MarketPlace();
void MarketPlace_items();
void file_reset();
int file_open();
void file_save();
void Market_open();
void Market_save();
void Market_reset();
void introduction();
char new_game();
void fallen_statement();
int variable_village();
int loop_forest();
void After_forest_EQuest();
int array_cave();
void After_cave_shop();
int Function_falls();
int Pointer_peak();
void Precaution_EQuest();
void precaution();
int final_stage();
int NUL_POINTER();
void Congratulations();

char lesson_navigation(int section, int total_sections);          //need
int menu_input(int min, int max);                                 //need
void traning_answer(char question[], char option[4][60], int correctAns, char explanation[4][150]);       //need

void training();
void VariableDatatypeTraining();
void V_D_lesson();
void V_D_quiz();

void ConditionTraining();
void Condition_lesson();
void Condition_quiz();

void LoopTraining();
void Loop_lesson();
void Loop_quiz();

void ArrayTraining();
void Array_lesson();
void Array_quiz();

void FunctionTraining();
void Function_lesson();
void Function_quiz();

void PointerTraining();
void Pointer_lesson();
void Pointer_quiz();

void StringTraining();
void String_lesson();
void String_quiz();


int main() {
    show_menu();
    return 0;
}

//__________________MAIN MENU_____________
void show_menu() {
    int choice;
    file_open();
    printf(
"   ______   ____  \n"
"  / ____/  / __ \\ \n"
" | |      | |  | |\n"
" | |      | |  | |\n"
" | |____  | |__| |\n"
"  \\_____|  \\___\\_\\\n"
);
    printf("================================================\n");
    printf("  CODE QUEST: Escape from the Compiler Kingdom\n");
    printf("================================================\n");
    printf("1. New Game\n2. Continue\n3. MarketPlace\n4. Profile\n5. Traning\n6. Exit\n");
    printf("Enter choice: ");

   while(1)
   {
    scanf("%d",&choice);
    flush_input();
    if(choice>=1 && choice<=6)
    {
        break;
    }
    else
    printf("Invalid Input....\nEnter again: ");
   }

    if (choice == 1) {
        file_reset();
        profile_reset();
        Market_reset();
        clear_screen();
        introduction();
        enter_to_continue();
        clear_screen();
        if(new_game()=='B') 
        {
            clear_screen();
            show_menu();
        }
    } else if (choice == 2) {
        clear_screen();
        if (file_open() == 0) {
            printf("\nNo saved game found. Starting a new game...\n");
            file_reset();
            introduction();
            enter_to_continue();
        } else {
            profile_open();
        }
        clear_screen();
        if(new_game()=='B') 
        {
            clear_screen();
            show_menu();
        }
    } else if (choice == 3) {
        if(Pause==1 || XP <=25)
        {
            printf("Marketplace is locked. You need to reach at least level \"Noob\" to access it.\n");
            enter_to_continue();
            clear_screen();
            show_menu();
        }
        else
        {
            MarketPlace();
            enter_to_continue();
            clear_screen();
            show_menu();
        }
    } else if (choice == 4) {
        if(profile_open()==0)
        {
            printf("\nNo profile found.\n\n\n");
        }else{
            printf("\nProfile loaded successfully.\n");
            profile_open();
            file_open();
            printf("\nProfile Name: %s\n", Name);
            printf("Current HP    :     %d\n", HP);
            printf("Current XP    :     %d\n", XP);
            level_status();
            printf("Current Coins :     %d\n\n\n", Coin);
        }
        enter_to_continue();
        clear_screen();
        show_menu();
    }
    else if(choice ==5)
    {
        training();
        clear_screen();
        show_menu();
    }
    else{
        printf("\n   Goodbye, Apprentice.\n");
        printf("==========game end===========\n");
    }
}
void clear_screen()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");//for Linux and Macos
    #endif
}
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
void MarketPlace()
{
    Market_open();
    printf("\n====================MARKETPLACE====================\n");
    printf("Welcome to the Marketplace, %s!\n", Name);
    printf("Here you can buy special items to aid your journey.\n");
    printf("Your current coins: %d\n", Coin);
    while(1)
  {
        MarketPlace_items();
        file_open();
        int choice;
        choice = answer_input_loop();

        if (choice == 1) {
            if (Coin >= 200) {
                Vibranium_sheld = 1;
                Coin =Coin - 200;
                printf("You have purchased the Vibranium Shield!\n");
                break;
            } 
            else 
            {
                printf("Insufficient coins for Vibranium Shield.\n");
                continue;
            }
        } else if (choice == 2) {
            if (Coin >= 150) {
                dubble_XP = 1;
                Coin =Coin - 150;
                printf("You have purchased the Double XP Potion!\n");
                break;
            } else {
                printf("Insufficient coins for Double XP Potion.\n");
                continue;
            }
        } else if (choice == 3) {
            if(HP==Max_HP)
            {
                printf("You are already at maximum HP. No need to buy HP drops.\n");
                continue;
            }
            else
            {
                printf("How many HP drops would you like to buy? (1-25): ");
                int drops;
                while(1)
               {
                    scanf("%d", &drops);
                    flush_input();
                    if(drops >= 1 && drops <= 25)
                    {
                        break;
                    }
                     else
                    {
                      printf("Invalid input. Please enter a number between 1 and 25: ");
                    }
                }
                if (Coin >= (drops * 4)) {
                    HP =HP + drops;
                    if (HP > Max_HP) {
                        HP = Max_HP;
                    }
                    Coin = Coin - (drops * 4);
                    printf("You have purchased %d HP drops! Your current HP: %d\n", drops, HP);
                    break;
                } else {
                    printf("Insufficient coins for %d HP drops.\n", drops);
                    continue;
                }
            }
        }
        else
        {
            printf("==========================");
            printf("  Exiting Marketplace.\n");
            break;
        }

    }
    Market_save();
    file_save();
}
void MarketPlace_items()
{
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("1. Vibranium Shield            (Prevents all HP loss for 1 battle)        -       200 coins\n");
    printf("2. Double XP Potion            (Doubles XP rewards for next battle)       -       150 coins\n");
    printf("3. HP Drop                           (One drop recovers 1 HP)             -       4 coins per drop\n");
    printf("                                         Maximum 25 HP\n\n");
    printf("4. Exit Marketplace\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("Enter your choice: ");
}
    

void introduction() 
{
    printf("\n--------------------------------------------------------------\n");
    printf("              The Compiler Kingdom is broken.\n");
    printf("       A virus called the NULL POINTER shattered its code.\n");
    printf("             You are the last Code Apprentice.\n");
    printf("      Fix 4 lands. Face the Null Pointer. Save the kingdom.\n");
    printf("----------------------------------------------------------------\n\n");

    profile_save();
    profile_open();
}

//___________________________________________________________NEW GAME____________________________________________________
char new_game() {

    while (1) {
      file_open();
      if(Pause==1)
        {
            HP = variable_village();
            if (HP <= 0) 
            {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            Pause=2;
            file_save();
            if(continue_or_back()=='R') return 'B';
            clear_screen();
        }
       if (Pause==2)
        {
            HP = loop_forest();
            if (HP <= 0)
            {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            Pause=3;
            file_save();
            current_status();
            if(continue_or_back()=='R') return'B';
            clear_screen();
        }
        if(Pause==3)
        {
            printf(" =========================================================================\n");
            printf("       Wizard of Iteration: \"You have restored the second fragment.      \n");
            printf("             But something's wrong deeper in the kingdom.              \n");
            printf("      The caves beyond the forest are collapsing. Tunnels vanishing,      \n");
            printf("        paths caving in without warning. That's not natural.          \n");
            printf("          Something is reading memory it was never meant to touch.\"        \n");
            printf("        Wizard of Iteration: \"Go to Array Cave, apprentice %s.       \n", Name);
            printf(  "Whatever broke the loops here..it's reaching further than we thought.\"\n");
            printf("=========================================================================\n");
            enter_to_continue();
            After_forest_EQuest();
            file_save();
            current_status();
            if(continue_or_back()=='R') return'B';
            clear_screen();
            Pause=4;
        }
        if(Pause==4)
        {
            HP = array_cave();
            if (HP <= 0) {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            Pause=5;
            file_save();
            if(continue_or_back()=='R') return'B';
            clear_screen();
        }
        if(Pause==5)
        {
            printf("-----------------------------------------------------------------------------------------\n");
            printf("%s : OHH, at last back in one piece. I guess there should be Function Falls ahead.\n", Name);
            current_status();
            printf("Need to do something about it\n");
            printf("Want to search for any store? (y/n): ");
            char store_choice = Yes_No_loop();
            if (store_choice == 'y' || store_choice == 'Y')
            {
                After_cave_shop();
                file_save();
            } 
            else 
            {
                printf("OK, to the next phase then...\n");
            }
            Pause=6;
            file_save();
            if(continue_or_back()=='R') return'B';
            clear_screen();
        }
        if(Pause==6)
        {
            HP = Function_falls();
            if (HP <= 0) {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            Pause=7;
            file_save();
            current_status();
            if(continue_or_back()=='R') return'B';
            clear_screen();
        }
        if(Pause==7)
        {
            HP = Pointer_peak();
            if (HP <= 0) {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            Pause=8;
            file_save();
            current_status();
            enter_to_continue();
            clear_screen();
        }
        if(Pause==8)
        {
            //__________________________________LINK from Peakpointer to nul pointer ______________________________
            printf("+----------------------------------------------------------+\n");
            printf("|                                                            |\n");
            printf("|   You survived Pointer Peak.                              |\n");
            printf("|                                                            |\n");
            printf("|   \"But something worse waits ahead. A broken pointer      |\n");
            printf("|    that grew into a virus -- the NULL POINTER. It          |\n");
            printf("|    doesn't break things. It erases them. Rooms, names,     |\n");
            printf("|    whole lands -- gone, like they never had an address.\"   |\n");
            printf("|                                                            |\n");
            printf("|   \"Keep it lit,\" the guard says, looking at your torch.   |\n");
            printf("|    \"You'll need it where you're going.\"                   |\n");
            printf("|                                                            |\n");
            printf("|   The road ahead fades into fog...                        |\n");
            printf("|                                                            |\n");
            printf("+----------------------------------------------------------+\n");
            enter_to_continue();
            clear_screen();
            current_status();
            printf("\n\n%s : I think I should take some precaution steps before facing the NULL POINTER\n", Name);
            printf("%s : Let's head back to the store and see what I can grab.\n\n", Name);
            printf("\n\n----------On the way to the store, %s found a man seeking his help!", Name);
            printf("\nWant to see? Or ignore him?\ny/n: ");

            char decision = Yes_No_loop();
            if (decision == 'y' || decision == 'Y')
            {
                clear_screen();
                Precaution_EQuest();
                file_save();
            }
            else
            {
                clear_screen();
                printf("Are you sure you want to avoid this? This might be a great chance to win some coins...\n");
                printf("y/n: ");
                char decision2 = Yes_No_loop();
                if (decision2 == 'y' || decision2 == 'Y')
                {
                    printf("%s : Sorry sir, but I am in a hurry, I have not much time.\n\n", Name);
                }
                else
                {
                    clear_screen();
                    Precaution_EQuest();
                    file_save();
                }
            }
            enter_to_continue();
            clear_screen();
            precaution();
            Pause=9;
            file_save();
            if(continue_or_back()=='R') return 'B';
            clear_screen();
        }

        if(Pause==9)
        {
            HP = final_stage();
            if (HP <= 0) {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            Pause=10;
            file_save();
            if(continue_or_back()=='R') return 'B';
            clear_screen();
        }
        if (Pause==10)
        {
            HP=NUL_POINTER();
            if(HP<=0)
            {
                fallen_statement();
                enter_to_continue();
                clear_screen();
                file_reset();
                continue;
            }
            remove("save.txt");
            profile_reset();
            Market_reset();
        }
        
        break;
    }
    return 'C'; // hudai kono kam nai..
}
//______________________________________fallen statment______________________
void fallen_statement()
{
    printf("\nYou have fallen, %s...\n", Name);
    printf("The kingdom's corruption was too strong this time.\n");
    printf("Restarting your journey from the beginning.\n");
    
}
//___________________________________________HP BAR_________________________________
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
//__________________________________curent status___________________________________
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

//_________________________________________REGION 1: VARIABLES VILLAGE_________________________________________
int variable_village() {
    printf("\n========================================\n");
    printf("REGION 1: Variables Village\n");
    printf("========================================\n");
    printf("Village houses keep changing values. Nobody trusts anything anymore.\n");
    printf("Elder Byte: \"Fix our variables, apprentice. Show them what's real.\"\n\n");
    printf("Be careful, wrong answers cost HP. Your current HP:\n");
    HP_Bar();
    enter_to_continue();
    clear_screen();

    //________________question NO. 1_________________
    char Q1[] = "Which data type stores a single character like 'A'?";
    char Q1_option[4][60] = {"int", "char", "float", "double"};
    char Q1_explanation[4][150] = {
        "int - stores whole numbers (no decimals), not meant for letters.",
        "char - designed specifically to hold a single character. Correct answer.",
        "float - stores decimal numbers like 3.14, not characters.",
        "double - stores larger, more precise decimal numbers, also not characters."
    };
    correct_answer(Q1, Q1_option, 2, 10, 3, 2, Q1_explanation);
    if (HP <= 0) return HP;


    //________________question NO. 2_________________
    char Q2[] = "What is the correct way to declare an integer variable named age?";
    char Q2_option[4][60] = {"int age;", "integer age;", "age int;", "var age;"};
    char Q2_explanation[4][150] = {
        "int age; - correct C syntax: type first, then variable name. Correct answer.",
        "integer age; - integer isn't a real C keyword (some other languages use it, C doesn't).",
        "age int; - wrong order; the type must always come before the name in C.",
        "var age; - var isn't a C keyword either (that's from JavaScript)."
    };
    correct_answer(Q2, Q2_option, 1, 8, 3, 2, Q2_explanation);
    if (HP <= 0) return HP;

    //________________question NO. 3_________________
    char Q3[] = "What will this print?\n  int x = 5;\n  x = x + 3;\n  printf(\"%d\", x);";
    char Q3_option[4][60] = {"5", "3", "8", "53"};
    char Q3_explanation[4][150] = {
        "5 - that was the value before the addition happened, not after.",
        "3 - that's just the number being added, not the final result.",
        "8 - correct: 5 + 3 = 8, and x is updated to that new value. Correct answer.",
        "53 - that would only happen if you joined text/strings together, not added numbers."
    };
    correct_answer(Q3, Q3_option, 3, 12, 4, 3, Q3_explanation);
    if (HP <= 0) return HP;

    //________________question NO. 4 - Corrupted Villager (mini-boss)_________________
    printf("\nA Corrupted Villager blocks the village exit!\n");
    char Q4[] = "Which data type is used to store decimal numbers like 3.14?";
    char Q4_option[4][60] = {"int", "char", "float", "void"};
    char Q4_explanation[4][150] = {
        "int - only holds whole numbers, would chop off the .14.",
        "char - holds a single character, not numeric values.",
        "float - built specifically for decimal/floating-point numbers. Correct answer.",
        "void - means no value at all, used for functions that return nothing, not a storage type."
    };
    correct_answer(Q4, Q4_option, 3, 20, 5, 4, Q4_explanation);
    if (HP <= 0) return HP;

    printf("\nThe Corrupted Villager fades away. The village calms down.\n");
    printf("A fragment of the Great Algorithm is restored!\n");
    printf("Elder Byte: \"Well done. The forest ahead awaits your help.\"\n");
    current_status();
    printf("\n");

    return HP;
}

//_________________________________________REGION 2: LOOP FOREST_________________________________________
int loop_forest() {
    printf("                         ==================\n");
    printf("                         ||  Loop Forest ||\n");
    printf("                         ==================\n");
    printf("===========================================================================\n");
    printf("     Trees shaped like `for` and `while`, paths that repeat forever.\n");
    printf("   Travelers wander here, stuck - trapped by loops with no exit condition.\n");
    printf("  A Wizard of Iteration: \"Something forgot how to stop looping. Free them.\"\n");
    printf("============================================================================\n");

    //Q1 - syntax check
    char Q1[] = "Which of these correctly writes a for loop that runs 5 times (from 0 to 4)?";
    char Q1_option[4][60] = {
        "for (i = 0; i < 5; i++)",
        "for (i = 0, i < 5, i++)",
        "while (i = 0; i < 5; i++)",
        "for i = 0; i < 5; i++"
    };
    char Q1_explanation[4][150] = {
        "Option 1: correct - semicolons separate the three parts of a for loop.",
        "Option 2: wrong - commas instead of semicolons; won't compile.",
        "Option 3: wrong - mixes while with for syntax.",
        "Option 4: wrong - missing the parentheses ( ) around the loop header."
    };
    correct_answer(Q1, Q1_option, 1, 10, 5, 3, Q1_explanation);
    if (HP <= 0) return HP;

    //Q2 - trace the output
    char Q2[] = "What does this print?\nfor (int i = 1; i <= 5; i++) {\n    printf(\"%d \", i);\n}";
    char Q2_option[4][60] = {
        "1 2 3 4 5",
        "0 1 2 3 4",
        "1 2 3 4 5 6",
        "5 4 3 2 1"
    };
    char Q2_explanation[4][150] = {
        "Option 1: correct - starts at 1, stops once i exceeds 5, so it prints 1 through 5.",
        "Option 2: wrong - that would be the output if the loop started at i = 0.",
        "Option 3: wrong - that would need the condition i <= 6.",
        "Option 4: wrong - that's a countdown, this loop counts up."
    };
    correct_answer(Q2, Q2_option, 1, 10, 5, 3, Q2_explanation);
    if (HP <= 0) return HP;

    //Q3 - spot the infinite loop
    char Q3[] = "Three of these loops end normally. One never stops. Which is trapped?\n"
                "Snippet 1: for (int i = 0; i < 10; i++) { printf(\"%d\", i); }\n"
                "Snippet 2: int i = 0; while (i < 10) { printf(\"%d\", i); i++; }\n"
                "Snippet 3: int i = 0; while (i < 10) { printf(\"%d\", i); }\n"
                "Snippet 4: for (int i = 10; i > 0; i--) { printf(\"%d\", i); }";
    char Q3_option[4][60] = {"Snippet 1", "Snippet 2", "Snippet 3", "Snippet 4"};
    char Q3_explanation[4][150] = {
        "Snippet 1: ends normally - i increments every pass, eventually hits 10.",
        "Snippet 2: ends normally - i++ inside the loop body correctly moves it toward the exit condition.",
        "Snippet 3: infinite - i is never incremented anywhere inside the loop, so i < 10 stays true forever.",
        "Snippet 4: ends normally - counts down from 10 to 1, correctly decrementing each pass."
    };
    correct_answer(Q3, Q3_option, 3, 10, 6, 4, Q3_explanation);
    if (HP <= 0) return HP;

    //Q4 - mini-boss: Infinite Loop Beast (off-by-one bug)
    char Q4[] = "int total = 0;\nfor (int i = 0; i <= 5; i++) {\n    total = total + i;\n}\n\n"
                "This is meant to sum the numbers 0 through 4 (0+1+2+3+4 = 10), but it gives the wrong result. What's the bug?";
    char Q4_option[4][60] = {
        "total should start at 1, not 0",
        "The condition should be i < 5, not i <= 5",
        "i should start at 1, not 0",
        "total = total + i should be total = i"
    };
    char Q4_explanation[4][150] = {
        "Option 1: wrong - starting total at 0 is correct; that's the right 'empty sum' starting point.",
        "Option 2: correct - i <= 5 lets the loop run one extra time (includes 5), the classic off-by-one bug.",
        "Option 3: wrong - starting i at 0 is intentional, since the goal is to include 0 in the sum.",
        "Option 4: wrong - that would overwrite total every time instead of accumulating it."
    };
    correct_answer(Q4, Q4_option, 2, 10, 9, 5, Q4_explanation);
    if (HP <= 0) return HP;

    printf("\nCongratulations %s, you have found a way out of the Loop Forest!\n", Name);

    return HP;
}

//_____________________________________________Loop forest Quest_______________________________________________
void After_forest_EQuest() {
    printf("\n\nOhh wait... another traveler is waving for help.\n");
    printf("Want to help her out? (y/n): ");
    char choice = Yes_No_loop();

    if (choice == 'y'|| choice=='Y') {
        clear_screen();
        printf("\n=============================SIDE QUEST===================================\n");
        printf("             Note: Side quests may give rewards but never cost HP.\n\n");
        printf("A traveler waves at you from a loop: \"Help me - I don't know if I'll ever get out!\"\n");

        char side_Q1[] = "int count = 5;\nwhile (count > 0)\n{\n    printf(\"Counting down: %d\\n\", count);\n    count--;\n}";
        char side_q1_options[4][60] = {
            "Yes, it will escape",
            "No, count > 0 stays true forever",
            "Yes, but only if count starts even",
            "No, while loops never stop"
        };
        char side_Q1_explanation[4][150] = {
            "Option 1: correct - count-- moves count toward 0 every pass, so the loop ends once count is no longer greater than 0.",
            "Option 2: wrong - that would only be true if count were never modified inside the loop.",
            "Option 3: wrong - the starting value being even or odd doesn't matter here; it counts down to 0 either way.",
            "Option 4: wrong - while loops absolutely can and do stop, as long as the condition eventually becomes false."
        };
        int wrong = correct_answer(side_Q1, side_q1_options, 1, 0, 8, 3, side_Q1_explanation);
        if (wrong == 0) {
            printf("\nThe Traveler: \"Thank you sir, it was a great help for me.\n");
            printf("I have nothing much to give you but I can surely give you some coins.\"\n");
            printf("----------------------------------------------------------------------\n");
            printf("    Congratulations %s! You have won a bonus of 6 coins and 2 XP.\n", Name);
            Coin = Coin + 6;
            XP = XP + 2;
        } else {
            printf("Traveler: \"Anyway, thank you sir for your kindness....\"\n");
        }
    } else {
        printf("\n---------------------------------------------------------------------\n");
        printf("%s: \"I think I have been through a lot for one day.\"\n", Name);
    }
}

//_________________________________________REGION 3: ARRAY CAVE_________________________________________
int array_cave() {
    printf("\n =================================================================================\n");
    printf(" ||                   The apprentice enters Array Cave                            ||\n");
    printf(" ||                    The walls aren't stone anymore                             ||\n");
    printf(" ||they're rows of glowing boxes, stacked side by side, each one holding a number.||\n");
    printf(" ||       This is how the old builders stored things in order: an array.          ||\n");
    printf(" ===================================================================================\n\n");
    printf("The Wizard: \"Careful, apprentice. Step wrong here, and you don't just fail - you corrupt what's next to you.\"\n");
    enter_to_continue();

    //_____________________________________question 1____________________________________
    printf("\nint arr[5] = {10, 20, 30, 40, 50};\n");
    printf("printf(\"%%d\", arr[5]);\n");
    char Q1[] = "What happens?";
    char Q1_option[4][60] = {
        "Prints 50",
        "Prints 0",
        "Undefined behavior - reading out of bounds",
        "Compiler error, won't build"
    };
    char Q1_explanation[4][150] = {
        "Wrong - arr[5] is past the valid range, there's no guaranteed value there.",
        "Wrong - memory isn't automatically zeroed just because it's out of bounds.",
        "Correct! Valid indices are 0 to 4. arr[5] reaches past the array into memory it doesn't own.",
        "Wrong - this compiles fine; the danger is at runtime, not compile time."
    };
    correct_answer(Q1, Q1_option, 3, 10, 6, 4, Q1_explanation);
    if (HP <= 0) return HP;

    //__________________________________Question 2___________________________________________________
    printf("\nint arr[4] = {1, 2, 3, 4};\n");
    printf("int sum = 0;\n");
    printf("for (int i = 1; i <= 4; i++) {\n");
    printf("    sum += arr[i];\n");
    printf("}\n");
    printf("printf(\"%%d\", sum);\n");
    char Q2[] = "What's wrong here?";
    char Q2_option[4][60] = {
        "Nothing, prints 10",
        "Off-by-one - loop should run i = 0 to i < 4",
        "sum was never initialized",
        "Arrays can't be used in loops"
    };
    char Q2_explanation[4][150] = {
        "Wrong - this does NOT print 10; it skips arr[0] and reads out of bounds.",
        "Correct! Starting at i=1 skips arr[0], and i<=4 reads one step past the array on the last pass.",
        "Wrong - sum = 0; is a proper initialization.",
        "Wrong - arrays are meant to be used inside loops; that's the whole point of indexing."
    };
    correct_answer(Q2, Q2_option, 2, 12, 8, 5, Q2_explanation);
    if (HP <= 0) return HP;

    //__________________________________________question 3________________________________________________________
    printf("\nint arr[3] = {5, 10, 15};\n");
    printf("int *p = arr;\n");
    printf("printf(\"%%d\", *(p + 2));\n");
    char Q3[] = "What prints?";
    char Q3_option[4][60] = {
        "5",
        "10",
        "15",
        "Garbage - invalid syntax"
    };
    char Q3_explanation[4][150] = {
        "Wrong - that's arr[0], not what *(p+2) points to.",
        "Wrong - that's arr[1], one step short.",
        "Correct! p points to arr[0]; *(p+2) is arr[2] = 15. Arrays and pointer arithmetic are the same thing under the hood.",
        "Wrong - this is completely valid C syntax."
    };
    correct_answer(Q3, Q3_option, 3, 15, 10, 5, Q3_explanation);
    if (HP <= 0) return HP;

    printf("\nWell done %s! Cave stabilizes. Fragment restored.\n", Name);
    return HP;
}
//___________________________________________________Shop After array cave ________________________________________
void After_cave_shop()
{
    clear_screen();
    printf("\n=================================================================================================\n");
    printf("                          There is a small wooden shop ahead \n");
    printf("                                Traveler %s goes inside\n", Name);
    printf("                         ----------------------------------------\n");
    printf("    Shopkeeper: Hello traveler, can I help you with something? I don't sell much,\n");
    printf("just a few things I found around the kingdom. Some are useful. Some are... expensive. Take a look.\n");
    printf("=================================================================================================\n");
    int Choose;
    printf("  Items                            Effects                                Price\n\n");
    printf("1.Elixir                       restore +50HP                             -30coins\n");
    printf("2.Iron Sheild              cancel panalty HP by 50%%                      -175coins\n");
    printf("3.Skip                     continue journey, no cost                       --\n");
    printf("Enter Choose: ");
    while(1)
    {
        Choose = answer_input_loop();
        if (Choose == 1) {
            if (Coin >= 30) {
                printf("Elixir obtained\nHP restored by 50\n");
                HP = HP + 50;
                if (HP >= Max_HP) {
                    HP = Max_HP;
                }
                Coin = Coin - 30;
                current_status();
                break;
            } else {
                printf(".... Insufficient Coins \nYou have %d coins.\nPick something else...\n", Coin);
            }
        } else if (Choose == 2) {
            if (Coin >= 175) {
                printf("Iron Shield obtained\nHP penalty canceled by 50%% for the next wrong answer.\n");
                Coin = Coin - 175;
                Iron_shield = 1;
                current_status();
                break;
            } else {
                printf(".... Insufficient Coins \nYou have %d coins.\nPick something else...\n", Coin);
            }
        }
        else if(Choose==3)
        {
            printf("OK, no purchase made.\n");
            break;
        }
        else {
            printf("That item isn't on the shelf. Pick 1 or 2 or 3: ");
        }
    }
    printf("%s : Let's head back to the journey\n", Name);
}

//_________________________________________REGION 4: FUNCTION FALLS_________________________________________
int Function_falls() {
    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("|         Water used to pour into the Great Waterwheel and come out exactly as it should            |\n");
    printf("|                     that's what the old engineers called functions.                               |\n");
    printf("|  Now the wheel is jammed. Something's torn its scrolls apart and scattered them across the falls. |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    enter_to_continue();
    clear_screen();
    printf("\nElder:\n");
    printf(" ______________________________________________________________________________________ \n");
    printf("|                           Careful this time, traveler.                               |\n");
    printf("|                   One wrong scroll and the whole wheel jams                          |\n");
    printf("|This region will cost you more if you fail - but it'll reward you more if you succeed |\n");
    printf("|______________________________________________________________________________________|\n");
    enter_to_continue();

    //________________________________________________________________Question NO 1_______________________________________________________________
    printf("\nvoid changeIt(int x) {\n");
    printf("    x = 100;\n");
    printf("}\n\n");
    printf("int main() {\n");
    printf("    int num = 5;\n");
    printf("    changeIt(num);\n");
    printf("    printf(\"%%d\", num);\n");
    printf("    return 0;\n");
    printf("}\n");
    char Q1[] = "What gets printed?";
    char Q1_option[4][60] = {
        "100",
        "5",
        "Garbage value",
        "Compilation error"
    };
    char Q1_explanation[4][150] = {
        "Wrong - that would only happen if C passed by reference, which it doesn't by default.",
        "Correct! C passes arguments by value. changeIt only modifies a copy of num, not the original.",
        "Wrong - num is a properly initialized local variable, not garbage.",
        "Wrong - this compiles and runs fine."
    };
    correct_answer(Q1, Q1_option, 2, 15, 11, 4, Q1_explanation);
    if (HP <= 0) return HP;

    //_____________________________________________Question 2___________________________________
    printf("\nint mystery(int n) {\n");
    printf("    if (n == 0)\n");
    printf("        return 0;\n");
    printf("    return n + mystery(n - 1);\n");
    printf("}\n");
    char Q2[] = "What does mystery(4) return?";
    char Q2_option[4][60] = {
        "4",
        "24",
        "10",
        "Infinite loop"
    };
    char Q2_explanation[4][150] = {
        "Wrong - that's just the starting value n, not the accumulated sum.",
        "Wrong - that's not how this sum works out.",
        "Correct! It's a sum: 4+3+2+1+0 = 10. Recursion with a proper base case (n==0) always terminates.",
        "Wrong - n == 0 is a valid base case, so this recursion does terminate."
    };
    correct_answer(Q2, Q2_option, 3, 18, 12, 5, Q2_explanation);
    if (HP <= 0) return HP;

    //________________________________________Question 3_______________________________________________
    printf("\nint count = 10;\n\n");
    printf("void reset() {\n");
    printf("    int count = 0;\n");
    printf("    printf(\"%%d\", count);\n");
    printf("}\n\n");
    printf("int main() {\n");
    printf("    reset();\n");
    printf("    printf(\"%%d\", count);\n");
    printf("    return 0;\n");
    printf("}\n");
    char Q3[] = "What will be the outcome of the program?";
    char Q3_option[4][60] = {
        "00",
        "1010",
        "100",
        "010"
    };
    char Q3_explanation[4][150] = {
        "Wrong - reset()'s local count and the global count are different variables.",
        "Wrong - that would happen only if both prints referred to the same variable.",
        "Wrong - close, but check the order of digits printed.",
        "Correct! Local count inside reset() shadows the global one. Prints 0, then the global 10 -> \"010\"."
    };
    correct_answer(Q3, Q3_option, 4, 20, 14, 6, Q3_explanation);
    if (HP <= 0) return HP;

    //________________________________________Question 4______________________________________________
    char Q4[] = "Which of these will cause a compiler warning/error if placed before main() calls it, with no prototype declared above main?";
    char Q4_option[4][60] = {
        "int add(int a, int b); declared above main",
        "The function defined after main() with no prototype above it",
        "A function defined before main()",
        "None of the above cause issues"
    };
    char Q4_explanation[4][150] = {
        "Wrong - a prototype above main is exactly what prevents the warning.",
        "Correct! With no prototype above main, the compiler doesn't know the function exists yet - implicit declaration warning/error in modern C.",
        "Wrong - a function fully defined before main() acts as its own prototype; no issue.",
        "Wrong - option 2 does cause an issue."
    };
    correct_answer(Q4, Q4_option, 2, 22, 16, 7, Q4_explanation);
    if (HP <= 0) return HP;

    printf("\nWell done %s! The Waterwheel turns once more.\n", Name);
    return HP;
}
int Pointer_peak()
{
    printf("The road ends at a tall, grey mountain. Cold wind blows.\nSigns everywhere say \"Do not trust what you see.\"\n");
    printf("An old guard stops you\n\n");
    printf("====================================================================\n");
    printf("                        This is Pointer Peak\n");
    printf("Here, nothing is what it looks like. A box may hold another box\n");
    printf("                    A name may point to a name.\n");
    printf("         One wrong step, and you fall into empty memory\n");
    printf("====================================================================\n");
    printf("He hands you a torch. \"Light your way. Trust the address, not the shadow.\"\n\n");
    enter_to_continue();

    printf("Note: Pointer Peak does not forgive mistakes. -15HP for each wrong answer\n");

    //________________________________Question 1__________________________________
    printf("int x = 7;\n");
    printf("int *p = &x;\n");
    printf("*p = *p + 3;\n");
    char Q1[] = "What is x after this code?";
    char Q1_option[4][60] = {
        "7",
        "10",
        "Address of x",
        "Error"
    };
    char Q1_explanation[4][150] = {
        "Wrong - *p reads x (7), adds 3, then writes it back into x.",
        "Correct - *p = *p + 3 means \"take what p points to, add 3, store it back.\" Since p points to x, x becomes 10.",
        "Wrong - *p is a value, not an address.",
        "Wrong - this is valid, common pointer code."
    };
    correct_answer(Q1, Q1_option, 2, 10, 9, 4, Q1_explanation);
    if (HP <= 0) return HP;

    //__________________________________________Question 2____________________________________
    printf("int a = 4, b = 9;\n");
    printf("int *p;\n");
    printf("if (a > b)\n");
    printf("    p = &a;\n");
    printf("else\n");
    printf("    p = &b;\n");
    printf("*p = *p * 2;\n");
    char Q2[] = "What is b after this code?";
    char Q2_option[4][60] = {
        "9",
        "18",
        "4",
        "8"
    };
    char Q2_explanation[4][150] = {
        "Wrong - b gets doubled by the last line, it does not stay the same.",
        "Correct - a > b is false (4 is not greater than 9), so the else runs: p = &b. Then *p = *p * 2 doubles b: 9 -> 18.",
        "Wrong - 4 is the value of a, not b, and a is untouched here.",
        "Wrong - 8 would be 4 doubled, but the pointer never points to a in this run."
    };
    correct_answer(Q2, Q2_option, 2, 15, 11, 5, Q2_explanation);
    if (HP <= 0) return HP;

    //____________________________________________Question 3________________________________________
    printf("int arr[4] = {1, 2, 3, 4};\n");
    printf("int *p = arr;\n");
    printf("int sum = 0;\n");
    printf("for (int i = 0; i < 4; i++)\n");
    printf("{\n");
    printf("    sum += *p;\n");
    printf("    p++;\n");
    printf("}\n");
    char Q3[] = "What is sum after this loop?";
    char Q3_option[4][60] = {
        "4",
        "0",
        "15",
        "10"
    };
    char Q3_explanation[4][150] = {
        "Wrong - 4 is only the last element, not the total.",
        "Wrong - sum starts at 0 but changes inside the loop; it does not stay 0.",
        "Wrong - 15 is not the sum of these four numbers.",
        "Correct - p starts at arr[0] and moves forward each loop (p++). It adds 1+2+3+4 = 10."
    };
    correct_answer(Q3, Q3_option, 4, 15, 12, 6, Q3_explanation);
    if (HP <= 0) return HP;

    //__________________________________Question 4___________________________________________
    printf("int arr[5] = {2, 4, 6, 8, 10};\n");
    printf("int *p = arr;\n");
    printf("int count = 0;\n");
    printf("for (int i = 0; i < 5; i++)\n");
    printf("{\n");
    printf("    if (*p %% 4 == 0)\n");
    printf("    {\n");
    printf("        count++;\n");
    printf("    }\n");
    printf("    p++;\n");
    printf("}\n");
    char Q4[] = "What is \"count\" after this code?";
    char Q4_option[4][60] = {
        "5",
        "3",
        "2",
        "0"
    };
    char Q4_explanation[4][150] = {
        "Wrong - not every number in the array divides evenly by 4.",
        "Wrong - 6 and 10 do not divide evenly by 4, so they don't count.",
        "Correct - the loop walks through the array using the pointer. Only 4 and 8 divide evenly by 4 (remainder 0), so count becomes 2.",
        "Wrong - some numbers do divide by 4 (4 and 8), so count is not 0."
    };
    correct_answer(Q4, Q4_option, 3, 15, 14, 7, Q4_explanation);
    if (HP <= 0) return HP;

    return HP;
}
//_______________________________________precoursion EQuest______________________________
void Precaution_EQuest()
{
    printf("-----------------------------------------------------------------\n");
    printf("    Traveler : Hello sir, I am locked outside of my house.\n");
    printf("and the password for my door is the output of this particular code\n");
    printf("    but I am unable to find the output. Can you help me?\n");
    printf("-------------------------------------------------------------------\n");
    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("int arr[] = {10, 20, 30, 40, 50};\n");
    printf("int *ptr = arr;\n");
    printf(" int sum = 0;\n");
    printf(" for (int i = 0; i < 5; i++) {\n");
    printf(" sum += *(ptr + i);\n");
    printf("  ptr++;}\n");
    printf("  printf(\"%%d\", sum);\n");
    printf(" return 0;\n");
    printf("}\n");

    char QE[] = "Find the output?";
    char QE_option[4][60] =
    {
        "150",
        "Undefined behavior",
        "100",
        "Compilation error",
    };
    char QE_explanation[4][150] =
    {
        "Wrong - 150 would be the sum only if ptr never moved on its own.",
        "Correct! ptr advances with ptr++ AND i is added on top of it each pass, so *(ptr+i) drifts past the array and reads out-of-bounds memory.",
        "Wrong - 100 isn't the sum of these five numbers even under normal conditions.",
        "Wrong - this compiles fine; the problem only shows up at runtime."
    };
    correct_answer(QE, QE_option, 2, 0, 18, 1, QE_explanation);
    printf("\n%s : Sir, your code is corrupted. It reads out of bounds - \"ptr++\" is causing the problem.\n", Name);
    printf("Remove it and the code should output 150.\n");
    printf("---------------------------------------------------------\n");
    printf("Traveler : Thank you, here's a little something for your trouble.\n");
    printf("---------------------------------------------------------\n");
    current_status();
    file_save();
}
//___________________________________precoursion___________________________________________
void precaution()
{
    printf("=========================================================================\n");
    printf("store...\n");
    printf("  Shopkeeper : Welcome back sir, is there anything I can help you with...\n");
    printf("   %s        : I am here to buy the Iron Shield\n", Name);
    printf("  Shopkeeper : This way sir....\n");
    printf("==========================================================================\n");
    printf("  Items                            Effects                                Price\n\n");
    printf("1.Iron Shield             Halve HP penalty on your next wrong answer     -80coins\n");
    printf("2.Skip                    Continue journey, no cost                       --\n");
    int choice;
    printf("Enter choice: ");
    while(1)
    {
        choice = answer_input_loop();
        if (choice == 1) {
            if (Coin >= 80) {
                printf("You have bought the Iron Shield.\n");
                printf("Your next wrong answer's HP penalty will be halved.\n");
                Coin = Coin - 80;
                Iron_shield = 1;
                break;
            } else {
                printf("Insufficient coins.\nYou have %d coins. Choose again: ", Coin);
            }
        } else if (choice == 2) {
            printf("OK, no purchase made.\n");
            break;
        } else {
            printf("That item isn't on the shelf. Pick 1 or 2: ");
        }
    }  
}
//__________________________________________________final stage_________________________________________
int final_stage()
{
    //__________________________________guard 1________________________________


    printf("                     ======================\n");
    printf("                     ||  Silent Corridor  ||\n");
    printf("                     ======================\n");
    printf("===========================================================================\n");
    printf("      Past the stone gate, the fog thickens into a narrow marble hall.\n");
    printf("        Two figures block the way - guardians carved from broken code.\n");
    printf(" The first speaks without moving its lips, voice jagged like corrupted text.\n");
    printf("     Sentinel: \"Words are not enough. Show me you understand growth.\"\n");
    printf("===========================================================================\n");
    
    
    //____________________________________question 1_______________________________________
    enter_to_continue();
    printf("char city[10] = \"Code\";\n");
    printf("strcat(city, \"Quest\");\n");
    printf("printf(\"%%s\", city);\n");
    char Q1[]="What does this code print?";
    char Q1_option[4][60]=
    {
        "CodeQuest",
        "Code Quest",
        "A crash from buffer overflow",
        "Quest",
    };
    char Q1_explanation[4][150]=
    {
        "Correct - strcat appends \"Quest\" right after \"Code\", and city[10] has exactly enough room: 4+5 = 9 characters + \\0 = 10.",
        "Wrong - strcat doesn't add a space, it joins the strings directly, back to back.",
        "Wrong - tempting, but count the space: city[10] holds 9 characters + \\0, and \"CodeQuest\" is exactly 9, it fits perfectly.",
        "Wrong - strcat doesn't overwrite, it appends onto the end of the existing string."
    };
    correct_answer(Q1,Q1_option,1,20,8,3,Q1_explanation);
    if(HP<=0)
    {
        return HP;
    }
   //____________________________guard 2____________________________
    printf("                     ======================\n");
    printf("                     || Warden of Whispers||\n");
    printf("                     ======================\n");
    printf("===========================================================================\n");
    printf("        Deeper in the corridor, the air turns cold and sharp-edged.\n");
    printf("          A second guard flickers into view, glitching between forms.\n");
    printf("       Warden: \"Appending is easy. Now show me when a string breaks.\"\n");
    printf("===========================================================================\n");

    //________________question2________________________
    printf("\n\n#include<stdio.h>\n");
    printf("#include<string.h>\n\n");
    printf("int Count(char s1[]){\n");
    printf("    int count=0,i;\n");
    printf("    for (i = 0; s1[i] != '\\0'; i++){\n");
    printf("        if (s1[i] == ' ')\n");
    printf("            count++;\n");
    printf("    }\n");
    printf("    return count;\n");
    printf("}\n\n");
    printf("int main(){\n");
    printf("    char s1[100];\n");
    printf("    int s_count;\n");
    printf("    printf(\"Enter the string S1 \\n\");\n");
    printf("    scanf(\"%%[^\\n]\", s1);\n");
    printf("    s_count = Count(s1);\n");
    printf("    printf(\"\\nAnswer is: %%d\", s_count);\n");
    printf("    return 0;\n");
    printf("}\n");
    char Q2[]="What will be the output?";
    char Q2_option[4][60]=
    {
        "Total number of words",
        "Total number of characters",
        "Total number of empty spaces",
        "Garbage value",
    };
    char Q2_explanation[4][150]=
    {
        "Wrong - the function never groups letters into words, it only reacts to space characters.",
        "Wrong - count only increases on spaces, not on every character in the string.",
        "Correct - count only increments when s1[i] hits a space character, so it totals the number of spaces.",
        "Wrong - s1 is properly read and count starts at 0, so there's no garbage here."
    };
    correct_answer(Q2,Q2_option,3,20,5,3,Q2_explanation);
    if(HP<=0)
    {
        return HP;
    }
    printf("\n\n\n                 The Warden's glitching form freezes, then shatters like broken glass.\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\"You saw the overflow before it saw you. Go - face what you came for.\"\n");
    printf("--------------------------------------------------------------------------\n");
    return HP;
}
int NUL_POINTER()
{
    printf("                     ======================\n");
    printf("                     ||   NULL POINTER    ||\n");
    printf("                     ======================\n");
    printf("===========================================================================\n");
    printf("        The corridor opens into a hollow, flickering chamber.\n");
    printf("     At its center floats a shape that is barely a shape - pointing\n");
    printf("                          at nothing at all.\n");
    printf("   NULL POINTER: \"I AM THE ABSENCE. I AM WHAT YOU FORGOT TO CHECK.\n");
    printf("        Solve what I have twisted, or become part of the void.\"\n");
    printf("===========================================================================\n\n");
    enter_to_continue();

    printf("#include <stdio.h>\n");
    printf("#include <string.h>\n\n");
    printf("int mystery(char *arr[], int n) {\n");
    printf("    char buffer[50] = \"\";\n");
    printf("    int count = 0;\n\n");
    printf("    for (int i = 0; i < n; i++) {\n");
    printf("        if (strlen(arr[i]) > 3) {\n");
    printf("            strcat(buffer, arr[i]);\n");
    printf("            count += strlen(arr[i]);\n");
    printf("        }\n");
    printf("    }\n\n");
    printf("    char temp[50];\n");
    printf("    strcpy(temp, buffer);\n\n");
    printf("    int matches = 0;\n");
    printf("    for (int i = 0; i < n; i++) {\n");
    printf("        if (strcmp(arr[i], \"NULL\") == 0) {\n");
    printf("            matches++;\n");
    printf("        }\n");
    printf("    }\n\n");
    printf("    return count + matches * 10 - strlen(temp);\n");
    printf("}\n\n");
    printf("int main() {\n");
    printf("    char *words[] = {\"Code\", \"Quest\", \"NULL\", \"Bug\", \"Pointer\", \"NULL\"};\n");
    printf("    int result = mystery(words, 6);\n");
    printf("    printf(\"%%d\\n\", result);\n");
    printf("    return 0;\n");
    printf("}\n\n");

    printf("===========================================================================\n");
    printf("                  What integer does this program print?\n");
    printf("                             you have 3 chance\n");
    printf("===========================================================================\n");

    int chance = 1, answer;
    int solved = 0;

    while (chance <= 3)
    {
        printf("Answer :");
        if(scanf("%d", &answer) != 1) 
        {
            printf("Invalid input. Please enter an integer.\n");
            flush_input(); 
            continue; 
        }
        flush_input();
        if (answer == 20)
        {
            clear_screen();
            Congratulations();
            file_reset();
            solved = 1;
            break;
        }
        else
        {
            printf("Wrong answer.\n%d chances left\n", 3 - chance);
            if (Iron_shield == 1)
            {
                HP = HP - 10;
                Iron_shield = 0;
                printf("Your Iron Shield absorbs half the damage!\n");
            }
            else
            {
                HP = HP - 20;
            }
            if (HP < 0)
            {
                HP = 0;
            }
            current_status();
            if (HP <= 0)
            {
                break;
            }
            chance++;
        }
    }

    if (!solved && HP > 0)
    {
        // ran out of guesses without ever finding the right answer
        HP = 0;
    }

    return HP;
}
void Congratulations()
{
    printf("\n");
    printf("===========================================================================\n");
    printf("===========================================================================\n");
    printf("\n");
    printf("                *          .            *        .    *\n");
    printf("        .    *        C O N G R A T U L A T I O N S !        .    *\n");
    printf("                     *          .            *        .\n");
    printf("\n");
    printf("===========================================================================\n");
    printf("===========================================================================\n\n");

    printf("      The NULL POINTER shrieks - a sound like a thousand null checks\n");
    printf("         finally passing. Its form tears apart into scattered bytes,\n");
    printf("              and the bytes rearrange themselves into clean code.\n\n");

    printf("                       \"...compiler... clean... rebuild...\"\n\n");

    printf("      The chamber fills with light. Where the monster stood, a single\n");
    printf("                        line hangs steady in the air:\n\n");

    printf("               ---------------------------------------------\n");
    printf("                 Build succeeded. 0 errors, 0 warnings.\n");
    printf("               ---------------------------------------------\n\n");

    printf("===========================================================================\n");
    printf("                          YOUR JOURNEY, RECALLED\n");
    printf("===========================================================================\n\n");

    printf("      [x] Variable Village .... the kingdom's names were restored\n");
    printf("      [x] Loop Forest ........ the endless paths finally broke\n");
    printf("      [x] Array Cave ......... the scattered chambers were indexed\n");
    printf("      [x] Pointer Peak ....... you learned to trust the address, not the shadow\n");
    printf("      [x] Silent Corridor .... two guards tested your grip on strings\n");
    printf("      [x] NULL POINTER ....... the Absence itself, undone\n\n");

    printf("===========================================================================\n\n");

    printf("      The kingdom is whole again. You lower your torch - you don't\n");
    printf("                          need it anymore.\n\n");

    printf("               The code is no longer broken. Neither are you.\n\n");

    printf("          You are no longer the last Code Apprentice.\n");
    printf("                    You are the COMPILER KING.\n\n");

    printf("===========================================================================\n");
    printf("                *          .            *        .    *\n");
    printf("                          THANK YOU FOR PLAYING\n");
    printf("                 C O D E   Q U E S T:  ESCAPE FROM THE\n");
    printf("                          COMPILER KINGDOM\n");
    printf("                *          .            *        .    *\n");
    printf("===========================================================================\n\n");
}
//_______________________________________ALL traning functions________________________________________________
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
void training()
{
    int choice;

    while (1)
    {
        clear_screen();  
        printf("\n============================================================\n");
        printf("                 C PROGRAMMING TRAINING\n");
        printf("============================================================\n\n");

        printf("1. Variables & Datatypes\n");
        printf("2. Conditionals\n");
        printf("3. Loops\n");
        printf("4. Arrays\n");
        printf("5. Functions\n");
        printf("6. Pointers\n");
        printf("7. Strings\n");
        printf("0. Return to Main Menu\n\n");

        printf("Enter your choice: ");
        choice = menu_input(0, 7);  

        switch (choice)
        {
            case 1:
                VariableDatatypeTraining(); 
                break;

            case 2:
                ConditionTraining(); 
                break;

            case 3:
                LoopTraining();  
                break;

            case 4:
                ArrayTraining();  
                break;

            case 5:
                FunctionTraining();  
                break;

            case 6:
                PointerTraining(); 
                break;

            case 7:
                StringTraining(); 
                break;

            case 0:
                return;
        }
    }
}

int V_D_QuizUnlocked = 0;

void VariableDatatypeTraining()
{
    int choice;

    while (1)
    {
        clear_screen();  

        printf("\n============================================================\n");
        printf("             VARIABLE & DATATYPE CHAMBER\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (V_D_QuizUnlocked==1) 
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); 

        if (choice == 0)  
            return;

        if (choice == 1)  
        {
            V_D_lesson();  
            V_D_QuizUnlocked = 1; 
        }
        else if (choice == 2) 
        {
            if (V_D_QuizUnlocked==1)  
                V_D_quiz(); 
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue();  
            }
        }
    }
}

void V_D_lesson()
{
    int section = 1;
    int total_sections = 4;
    char navigation;

    while(section >= 1 && section <= total_sections)
    {
        clear_screen(); 

        if (section == 1)  
        {
            printf("============================================================\n");
            printf("              VARIABLE & DATATYPE CHAMBER\n");
            printf("============================================================\n\n");

            printf("A variable is a named location used to store a value.\n\n");

            printf("Example:\n");
            printf("    int age = 20;\n\n");

            printf("int  -> datatype\n");
            printf("age  -> variable name\n");
            printf("20   -> value\n");
        }

        else if (section == 2)  
        {
            printf("------------------------------------------------------------\n");
            printf("                     DATA TYPES\n");
            printf("------------------------------------------------------------\n\n");

            printf("A datatype tells C what type of data a variable stores.\n\n");

            printf("int    -> Whole numbers\n");
            printf("float  -> Decimal numbers\n");
            printf("double -> Precise decimal numbers\n");
            printf("char   -> Single character\n\n");

            printf("Example:\n");
            printf("    int age = 20;\n");
            printf("    float height = 6.1;\n");
            printf("    char grade = 'A';\n");
        }

        else if (section == 3)  
        {
            printf("------------------------------------------------------------\n");
            printf("                VARIABLE RULES & PRINTING\n");
            printf("------------------------------------------------------------\n\n");

            printf("Variable naming rules:\n");
            printf("- Cannot start with a digit\n");
            printf("- No spaces\n");
            printf("- Cannot use C keywords\n");
            printf("- Underscore is allowed\n\n");

            printf("Format specifiers:\n");
            printf("%%d  -> int\n");
            printf("%%f  -> float\n");
            printf("%%lf -> double\n");
            printf("%%c  -> char\n");
            printf("%%s  -> string\n");
        }

        else if (section == 4)  
        {
            printf("------------------------------------------------------------\n");
            printf("                     WARRIOR TIP\n");
            printf("------------------------------------------------------------\n\n");

            printf("Variable -> stores a value\n");
            printf("Datatype -> determines the type of value\n");
            printf("Naming   -> follows C rules\n");
            printf("Specifier -> tells printf what to display\n\n");

            printf("Master variables and datatypes, Warrior!\n");
        }

        printf("\n------------------------------------------------------------\n");
        navigation = lesson_navigation(section, total_sections);  

        if (navigation == 'N')  
            section++;

        else if (navigation == 'P')  
            section--;

        else if (navigation == 'E')  
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }

    }
}

void V_D_quiz()
{
    clear_screen();  

    printf("============================================================\n");
    printf("          VARIABLE & DATATYPE KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "What will be the output?\n\n"
        "int age = 20;\n"
        "age = 25;\n"
        "printf(\"%d\", age);";

    char Q1_option[4][60] =
    {
        "20",
        "25",
        "0",
        "Garbage value"
    };

    char Q1_explanation[4][150] =
    {
        "age is changed to 25 before printf.",
        "age is changed from 20 to 25.",
        "age has a valid assigned value.",
        "age was initialized before printing."
    };

    traning_answer(Q1, Q1_option, 2, Q1_explanation); 


    char Q2[] =
        "Which datatype is normally used to store a single character?";

    char Q2_option[4][60] =
    {
        "int",
        "float",
        "char",
        "double"
    };

    char Q2_explanation[4][150] =
    {
        "int stores whole numbers.",
        "float stores decimal numbers.",
        "char stores a single character.",
        "double stores decimal values."
    };

    traning_answer(Q2, Q2_option, 3, Q2_explanation);  
    enter_to_continue();  
}

int Condition_quizUnlocked = 0;

void ConditionTraining()
{
    int choice;

    while (1)
    {
        clear_screen();  

        printf("\n============================================================\n");
        printf("                    CONDITION CITADEL\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Condition_quizUnlocked==1)  
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2);  

        if (choice == 0)  
            return;

        if (choice == 1)  
        {
            Condition_lesson();  
            Condition_quizUnlocked = 1;
        }

        else if (choice == 2) 
        {
            if (Condition_quizUnlocked==1)  
                Condition_quiz();  
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); 
            }
        }
    }
}

void Condition_lesson() {
    int section = 1;
    int total_sections = 8;
    char navigation;
    while(section >= 1 && section <= total_sections) {
        clear_screen();  

       
        if(section == 1) {  
            printf("============================================================\n");
            printf("                 CONDITION CITADEL\n");
            printf("============================================================\n\n");
            printf("Welcome, Warrior! You have entered the Condition Citadel.\n");
            printf("Here, your decisions will determine the path of your program.\n\n");
        } 
        else if(section == 2) {  
            printf("------------------------------------------------------------\n");
            printf("                    WHAT IS A CONDITION?\n");
            printf("------------------------------------------------------------\n");
            printf("A condition is an expression that can be either TRUE or FALSE.\n");
            printf("C uses conditions to make decisions in a program.\n\n");
            printf("Example:\n");
            printf("    if (age >= 18)\n");
            printf("        printf(\"You are an adult\");\n\n");
            printf("If age is 18 or greater, the condition is TRUE.\n");
            printf("Otherwise, the condition is FALSE.\n\n");
        }
        else if(section == 3) { 
            printf("------------------------------------------------------------\n");
            printf("                    BOOLEAN VALUES\n");
            printf("------------------------------------------------------------\n");
            printf("In C, TRUE is represented by any non-zero value.\n");
            printf("FALSE is represented by the value 0.\n\n");
            printf("Example:\n");
            printf("    int x = 5;\n");
            printf("    if (x > 0) // TRUE because 5 is greater than 0\n");
            printf("        printf(\"Positive number\");\n\n");
            printf("    int y = 0;\n");
            printf("    if (y) // FALSE because y is 0\n");
            printf("        printf(\"This won't print\");\n\n");
        }
        else if(section == 4) { 
            printf("------------------------------------------------------------\n");
            printf("                    IF STATEMENT\n");
            printf("------------------------------------------------------------\n");
            printf("The if statement allows the program to execute a block of code\n");
            printf("only if a specified condition is TRUE.\n\n");
            printf("Syntax:\n");
            printf("    if (condition)\n");
            printf("    {\n");
            printf("        // code to execute if condition is TRUE\n");
            printf("    }\n\n");
            printf("Example:\n");
            printf("    int age = 20;\n");
            printf("    if (age >= 18)\n");
            printf("        printf(\"You are an adult\");\n\n");
        }
        else if(section == 5) {  
            printf("------------------------------------------------------------\n");
            printf("                    IF-ELSE STATEMENT\n");
            printf("------------------------------------------------------------\n");
            printf("The if-else statement allows the program to choose between\n");
            printf("two blocks of code based on a condition.\n\n");
            printf("Syntax:\n");
            printf("    if (condition)\n");
            printf("    {\n");
            printf("        // code if condition is TRUE\n");
            printf("    }\n");
            printf("    else\n");
            printf("    {\n");
            printf("        // code if condition is FALSE\n");
            printf("    }\n\n");
            printf("Example:\n");
            printf("    int age = 16;\n");
            printf("    if (age >= 18)\n");
            printf("        printf(\"You are an adult\");\n");
            printf("    else\n");
            printf("        printf(\"You are a minor\");\n\n");
        }
        else if(section == 6) { 
            printf("------------------------------------------------------------\n");
            printf("                COMPARISON OPERATORS\n");
            printf("------------------------------------------------------------\n");
            printf("==   Equal to\n");
            printf("!=   Not equal to\n");
            printf(">    Greater than\n");
            printf("<    Less than\n");
            printf(">=   Greater than or equal to\n");
            printf("<=   Less than or equal to\n\n");
            printf("IMPORTANT:\n");
            printf("Use == to compare two values.\n");
            printf("Use =  to assign a value.\n\n");
            printf("Example:\n");
            printf("    if (x == 10)    // comparison\n");
            printf("    x = 10;         // assignment\n\n");
        }

       
        else if(section == 7) { 
            printf("------------------------------------------------------------\n");
            printf("                  LOGICAL OPERATORS\n");
            printf("------------------------------------------------------------\n");
            printf("&&   AND  -> Both conditions must be TRUE\n");
            printf("||   OR   -> At least one condition must be TRUE\n");
            printf("!    NOT  -> Reverses TRUE/FALSE\n\n");
            printf("Example:\n");
            printf("    if (age >= 18 && age <= 60)\n");
            printf("        printf(\"Eligible\");\n\n");
        }
        else if(section == 8) {  
            printf("------------------------------------------------------------\n");
            printf("                    WARRIOR TIP\n");
            printf("------------------------------------------------------------\n");
            printf("Conditions are the decision-making system of C.\n");
            printf("Master them, and your programs can choose what to do!\n\n");
        }

        // ========================= NAVIGATION =========================
        printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections);  
        if(navigation == 'N')  
        {
            section++;
        }
        else if(navigation == 'P')  
        {
            section--;
        }
        else if(navigation == 'E')  
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }
    }
}

void Condition_quiz()
{
    clear_screen();  

    printf("============================================================\n");
    printf("               CONDITION KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "What will be the output?\n\n"
        "int x = 10;\n\n"
        "if(x > 5)\n"
        "{\n"
        "    printf(\"YES\");\n"
        "}\n"
        "else\n"
        "{\n"
        "    printf(\"NO\");\n"
        "}";

    char Q1_option[4][60] =
    {
        "YES",
        "NO",
        "YES NO",
        "Nothing"
    };

    char Q1_explanation[4][150] =
    {
        "10 is greater than 5.",
        "the condition is TRUE.",
        "only one branch executes.",
        "YES is printed."
    };
    traning_answer(Q1, Q1_option, 1, Q1_explanation);  

    char Q2[] =
        "Which operator checks whether two values are equal?";

    char Q2_option[4][60] =
    {
        "=",
        "==",
        "!=",
        ">="
    };

    char Q2_explanation[4][150] =
    {
        "= is assignment.",
        "== compares two values.",
        "!= means not equal.",
        ">= means greater than or equal."
    };
    traning_answer(Q2, Q2_option, 2, Q2_explanation);  
    enter_to_continue();  
}

int Loop_quizUnlocked = 0;
void LoopTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); 

        printf("\n============================================================\n");
        printf("                    LOOP LABYRINTH\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Loop_quizUnlocked==1) 
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2);  

        if (choice == 0) 
            return;

        if (choice == 1)  
        {
            Loop_lesson();  
            Loop_quizUnlocked = 1;
        }

        else if (choice == 2)  
        {
            if (Loop_quizUnlocked==1)  
                Loop_quiz();  
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue();  
            }
        }
    }
}

void Loop_lesson()
{
    int section = 1;
    int total_sections = 7;
    char navigation;

    while(section >= 1 && section <= total_sections)
    {
        clear_screen();  
        if(section == 1) 
        {
            printf("============================================================\n");
            printf("                    LOOP FOREST\n");
            printf("============================================================\n\n");
            printf("Welcome, Warrior! You have entered the Loop Labyrinth.\n");
            printf("Here, repetition will become one of your greatest weapons.\n\n");
            printf("Loops allow a program to repeat a block of code\n");
            printf("multiple times without writing the same code again.\n\n");
            printf("C has three main types of loops:\n");
            printf("1. for loop\n");
            printf("2. while loop\n");
            printf("3. do-while loop\n\n");
        }
        else if(section == 2)  
        {
            printf("------------------------------------------------------------\n");
            printf("                       FOR LOOP\n");
            printf("------------------------------------------------------------\n");
            printf("The for loop is commonly used when you know how many\n");
            printf("times you want to repeat a block of code.\n\n");
            printf("Syntax:\n");
            printf("    for(initialization; condition; update)\n");
            printf("    {\n");
            printf("        // code to repeat\n");
            printf("    }\n\n");
            printf("Example:\n");
            printf("    for(int i = 1; i <= 5; i++)\n");
            printf("    {\n");
            printf("        printf(\"%%d \", i);\n");
            printf("    }\n\n");
            printf("Output:\n");
            printf("    1 2 3 4 5\n\n");
            printf("The loop runs while the condition is TRUE.\n");
        }

        else if(section == 3)  
        {
            printf("------------------------------------------------------------\n");
            printf("                      WHILE LOOP\n");
            printf("------------------------------------------------------------\n");
            printf("The while loop repeats a block of code as long as\n");
            printf("its condition remains TRUE.\n\n");
            printf("Syntax:\n");
            printf("    while(condition)\n");
            printf("    {\n");
            printf("        // code to repeat\n");
            printf("    }\n\n");
            printf("Example:\n");
            printf("    int i = 1;\n\n");
            printf("    while(i <= 5)\n");
            printf("    {\n");
            printf("        printf(\"%%d \", i);\n");
            printf("        i++;\n");
            printf("    }\n\n");
            printf("Output:\n");
            printf("    1 2 3 4 5\n\n");
            printf("IMPORTANT: Make sure the condition eventually becomes\n");
            printf("FALSE, otherwise you may create an infinite loop.\n");
        }
        else if(section == 4)  
        {
            printf("------------------------------------------------------------\n");
            printf("                    DO-WHILE LOOP\n");
            printf("------------------------------------------------------------\n");
            printf("The do-while loop is different because the code inside\n");
            printf("the loop executes at least once.\n\n");
            printf("Syntax:\n");
            printf("    do\n");
            printf("    {\n");
            printf("        // code to repeat\n");
            printf("    } while(condition);\n\n");
            printf("Example:\n");
            printf("    int i = 1;\n\n");
            printf("    do\n");
            printf("    {\n");
            printf("        printf(\"%%d \", i);\n");
            printf("        i++;\n");
            printf("    } while(i <= 5);\n\n");
            printf("Output:\n");
            printf("    1 2 3 4 5\n\n");
            printf("Remember:\n");
            printf("while     -> condition checked BEFORE execution\n");
            printf("do-while  -> condition checked AFTER execution\n");
        }
        else if(section == 5) 
        {
            printf("------------------------------------------------------------\n");
            printf("                  LOOP COMPARISON\n");
            printf("------------------------------------------------------------\n");
            printf("FOR LOOP:\n");
            printf("- Best when the number of repetitions is known.\n\n");
            printf("WHILE LOOP:\n");
            printf("- Best when repetition depends on a condition.\n\n");
            printf("DO-WHILE LOOP:\n");
            printf("- Runs at least once before checking the condition.\n\n");
            printf("Example situations:\n");
            printf("for      -> Print numbers from 1 to 10\n");
            printf("while    -> Keep asking until the correct answer\n");
            printf("do-while -> Show a menu at least once\n");
        }
        else if(section == 6)  
        {
            printf("------------------------------------------------------------\n");
            printf("                     NESTED LOOPS\n");
            printf("------------------------------------------------------------\n");
            printf("A loop inside another loop is called a nested loop.\n\n");
            printf("Example:\n");
            printf("    for(i = 1; i <= 3; i++)\n");
            printf("    {\n");
            printf("        for(j = 1; j <= 3; j++)\n");
            printf("        {\n");
            printf("            printf(\"* \");\n");
            printf("        }\n");
            printf("    }\n\n");
            printf("Nested loops are useful for working with patterns,\n");
            printf("tables, and multidimensional data.\n");
        }
        else if(section == 7) 
        {
            printf("------------------------------------------------------------\n");
            printf("                     WARRIOR TIP\n");
            printf("------------------------------------------------------------\n");
            printf("Loops are the power of repetition in C.\n\n");
            printf("Remember the three warriors:\n\n");
            printf("FOR       -> Known number of repetitions\n");
            printf("WHILE     -> Condition-controlled repetition\n");
            printf("DO-WHILE  -> Executes at least once\n\n");
            printf("Master loops, and you can make your programs\n");
            printf("perform thousands of actions with just a few lines!\n");
        }

         // ========================= NAVIGATION =========================

        printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections);  
        if(navigation == 'N')  
        {
            section++;
        }
        else if(navigation == 'P')  
        {
            section--;
        }
        else if(navigation == 'E')  
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }
    }
}

void Loop_quiz()
{
    clear_screen();  

    printf("============================================================\n");
    printf("                    LOOP KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "What will be the output?\n\n"
        "int i;\n"
        "for(i = 1; i <= 3; i++)\n"
        "{\n"
        "    printf(\"%d \", i);\n"
        "}";

    char Q1_option[4][60] =
    {
        "1 2 3",
        "0 1 2",
        "1 2 3 4",
        "3 2 1"
    };

    char Q1_explanation[4][150] =
    {
        "i prints 1, 2, and 3.",
        "i starts at 1.",
        "i becomes 4 and the condition becomes false.",
        "i is increasing."
    };

    traning_answer(Q1, Q1_option, 1, Q1_explanation);  


    char Q2[] =
        "Which loop executes its body at least once?";

    char Q2_option[4][60] =
    {
        "for loop",
        "while loop",
        "do-while loop",
        "nested loop"
    };

    char Q2_explanation[4][150] =
    {
        "for checks its condition first.",
        "while checks its condition first.",
        "do-while executes before checking.",
        "nested only describes loops inside loops."
    };

    traning_answer(Q2, Q2_option, 3, Q2_explanation);  
    enter_to_continue();  
}

int Array_quizUnlocked = 0;
void ArrayTraining()
{
    int choice;

    while (1)
    {
        clear_screen();  

        printf("\n============================================================\n");
        printf("                      ARRAY ARENA\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Array_quizUnlocked==1)  
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); 

        if (choice == 0)  
            return;

        if (choice == 1)  
        {
            Array_lesson();  
            Array_quizUnlocked = 1;
        }

        else if (choice == 2)  
        {
            if (Array_quizUnlocked==1)  
                Array_quiz();  
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue();  
            }
        }
    }
}

void Array_lesson()
{
    int section = 1;
    int total_sections = 4;
    char navigation;

    while(section >= 1 && section <= total_sections)
    {
        clear_screen(); 
        if(section == 1)  // SECTION 1: Array Cave
        {
            printf("============================================================\n");
            printf("                     ARRAY CAVE\n");
            printf("============================================================\n\n");
            printf("Welcome, Warrior! You have entered the Array Arena.\n");
            printf("Here, you will learn how to store multiple values\n");
            printf("using a single variable name.\n\n");
            printf("An array is a collection of elements of the same\n");
            printf("data type stored under one variable name.\n\n");
            printf("Example:\n");
            printf("    int marks[5];\n\n");
            printf("This creates an integer array that can store\n");
            printf("5 values.\n\n");
            printf("Arrays are useful for storing related data such as\n");
            printf("marks, ages, scores, or numbers.\n");
        }
        else if(section == 2)  
        {
            printf("------------------------------------------------------------\n");
            printf("                ARRAY DECLARATION & INDEX\n");
            printf("------------------------------------------------------------\n\n");
            printf("The basic syntax is:\n\n");
            printf("    data_type array_name[size];\n\n");
            printf("Example:\n");
            printf("    int numbers[5];\n\n");
            printf("An array of 5 elements has indexes:\n\n");
            printf("    Index:   0    1    2    3    4\n");
            printf("    Value:  [10] [20] [30] [40] [50]\n\n");
            printf("IMPORTANT:\n");
            printf("Array indexing starts from 0 in C.\n\n");
            printf("So numbers[0] is the first element,\n");
            printf("and numbers[4] is the fifth element.\n");
        }
        else if(section == 3)  
        {
            printf("------------------------------------------------------------\n");
            printf("              INITIALIZATION & USING ARRAYS\n");
            printf("------------------------------------------------------------\n\n");
            printf("You can initialize an array when declaring it:\n\n");
            printf("    int numbers[5] = {10, 20, 30, 40, 50};\n\n");
            printf("You can access or change an element using its index:\n\n");
            printf("    printf(\"%%d\", numbers[2]);\n");
            printf("    numbers[2] = 100;\n\n");
            printf("Loops are commonly used with arrays.\n\n");
            printf("Example:\n");
            printf("    for(int i = 0; i < 5; i++)\n");
            printf("    {\n");
            printf("        printf(\"%%d \", numbers[i]);\n");
            printf("    }\n\n");
            printf("Output:\n");
            printf("    10 20 30 40 50\n");
        }
        else if(section == 4)  
        {
            printf("------------------------------------------------------------\n");
            printf("                     WARRIOR TIP\n");
            printf("------------------------------------------------------------\n\n");
            printf("Remember these important array rules:\n\n");
            printf("1. An array stores multiple values.\n");
            printf("2. All elements have the same data type.\n");
            printf("3. Array indexing starts from 0.\n");
            printf("4. Loops make arrays easier to use.\n\n");
            printf("Example:\n");
            printf("    int scores[3] = {80, 90, 75};\n\n");
            printf("scores[0] -> 80\n");
            printf("scores[1] -> 90\n");
            printf("scores[2] -> 75\n\n");
            printf("Master arrays, Warrior!\n");
        }

        // ========================= NAVIGATION =========================
    printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections);  
        if(navigation == 'N')  
        {
            section++;
        }
        else if(navigation == 'P')  
        {
            section--;
        }
        else if(navigation == 'E')  
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }
    }
}

void Array_quiz()
{
    clear_screen();  

    printf("============================================================\n");
    printf("                    ARRAY KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "From which index does an array start in C?";

    char Q1_option[4][60] =
    {
        "0",
        "1",
        "-1",
        "It depends on the array"
    };

    char Q1_explanation[4][150] =
    {
        "C arrays use zero-based indexing.",
        "index 1 is the second element.",
        "arrays do not begin at -1.",
        "normal C arrays start at 0."
    };

    traning_answer(Q1, Q1_option, 1, Q1_explanation);  


    char Q2[] =
        "What is wrong with this code?\n\n"
        "int arr[3] = {10, 20, 30};\n"
        "printf(\"%d\", arr[3]);";

    char Q2_option[4][60] =
    {
        "arr[3] contains 30",
        "The array should contain 4 elements",
        "arr[3] is outside the valid index range",
        "printf cannot print arrays"
    };

    char Q2_explanation[4][150] =
    {
        "30 is stored at arr[2].",
        "the array correctly has 3 elements.",
        "valid indexes are 0, 1, and 2.",
        "printf can print an array element."
    };

    traning_answer(Q2, Q2_option, 3, Q2_explanation);  

    enter_to_continue();  
}

int Function_quizUnlocked = 0;
void FunctionTraining()
{
    int choice;

    while (1)
    {
        clear_screen();  
        printf("\n============================================================\n");
        printf("                   FUNCTION FORTRESS\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Function_quizUnlocked==1) 
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); 

        if (choice == 0)  
            return;

        if (choice == 1)  
        {
            Function_lesson();  
            Function_quizUnlocked = 1;
        }

        else if (choice == 2)  
        {
            if (Function_quizUnlocked==1)  
                Function_quiz(); 
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); 
            }
        }
    }
}

void Function_lesson()
{
    int section = 1;
    int total_sections = 5;
    char navigation;

    while(section >= 1 && section <= total_sections)
    {
        clear_screen(); 
        if(section == 1) 
        {
            printf("========================================\n");
            printf("          FUNCTION FORTRESS\n");
            printf("========================================\n\n");
            printf("Welcome to the Function Fortress, Warrior!\n\n");
            printf("Functions are reusable blocks of code\n");
            printf("designed to perform a specific task.\n\n");
            printf("Think of a function as a special ability.\n");
            printf("You define the ability once, then call it\n");
            printf("whenever you need it.\n\n");
        }

        else if(section == 2)  
        {
            printf("------------------------------------------------------------\n");
            printf("                    FUNCTION SYNTAX\n");
            printf("------------------------------------------------------------\n\n");
            printf("The basic syntax of a function is:\n\n");
            printf("    return_type function_name()\n");
            printf("    {\n");
            printf("        // statements\n");
            printf("    }\n\n");
            printf("Example:\n\n");
            printf("    void attack()\n");
            printf("    {\n");
            printf("        printf(\"Warrior attacks!\\n\");\n");
            printf("    }\n\n");
            printf("Here:\n");
            printf("    void       -> return type\n");
            printf("    attack     -> function name\n");
            printf("    ()         -> parameter list\n");
            printf("    { }        -> function body\n\n");
            printf("IMPORTANT:\n");
            printf("The function name should describe what the function does.\n");
        }

        else if(section == 3)  
        {
            printf("------------------------------------------------------------\n");
            printf("              FUNCTION CALLS & PARAMETERS\n");
            printf("------------------------------------------------------------\n\n");
            printf("A function is executed by calling its name.\n\n");
            printf("Example:\n\n");
            printf("    void attack()\n");
            printf("    {\n");
            printf("        printf(\"Attack!\\n\");\n");
            printf("    }\n\n");
            printf("To call the function:\n\n");
            printf("    attack();\n\n");
            printf("A function can also receive information through\n");
            printf("parameters.\n\n");
            printf("Example:\n\n");
            printf("    void attack(int damage)\n");
            printf("    {\n");
            printf("        printf(\"Damage: %%d\\n\", damage);\n");
            printf("    }\n\n");
            printf("Calling:\n\n");
            printf("    attack(50);\n\n");
            printf("Here, 50 is passed to the damage parameter.\n\n");
            printf("A function can have multiple parameters:\n\n");
            printf("    void battle(int attack, int defense)\n");
            printf("    {\n");
            printf("        // statements\n");
            printf("    }\n\n");
            printf("IMPORTANT:\n");
            printf("Parameters allow functions to work with different data.\n");
        }

        else if(section == 4)  
        {
            printf("------------------------------------------------------------\n");
            printf("                 RETURN VALUES & VOID\n");
            printf("------------------------------------------------------------\n\n");
            printf("A function can return a value to the place\n");
            printf("where it was called.\n\n");
            printf("Example:\n\n");
            printf("    int add(int a, int b)\n");
            printf("    {\n");
            printf("        return a + b;\n");
            printf("    }\n\n");
            printf("Calling the function:\n\n");
            printf("    int result = add(10, 20);\n\n");
            printf("The function calculates:\n");
            printf("    10 + 20 = 30\n\n");
            printf("Therefore:\n");
            printf("    result = 30\n\n");
            printf("A void function does not return a value.\n\n");
            printf("Example:\n\n");
            printf("    void greet()\n");
            printf("    {\n");
            printf("        printf(\"Hello!\\n\");\n");
            printf("    }\n\n");
            printf("Remember:\n");
            printf("    void -> does not return a value\n");
            printf("    int  -> returns an integer value\n\n");
            printf("IMPORTANT:\n");
            printf("If a function has a return type such as int,\n");
            printf("it should return a value of that type.\n");
        }

        else if(section == 5) 
        {
            printf("\n------------------------------------------------------------\n");
            printf("                      WARRIOR TIP\n");
            printf("------------------------------------------------------------\n\n");
            printf("One function, one task!\n\n");
            printf("Keep each function focused on doing one specific job.\n");
            printf("This makes your code easier to understand,\n");
            printf("debug, and reuse.\n");
            printf("Master functions, Warrior!\n");
        }

        // ========================= NAVIGATION =========================
    printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections);  
        if(navigation == 'N')  
        {
            section++;
        }
        else if(navigation == 'P')  
        {
            section--;
        }
        else if(navigation == 'E')  
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }
    }
}

void Function_quiz()
{
    clear_screen(); 
    printf("============================================================\n");
    printf("                 FUNCTION KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "What will be the output?\n\n"
        "int add(int a, int b)\n"
        "{\n"
        "    return a + b;\n"
        "}\n\n"
        "printf(\"%d\", add(5, 3));";

    char Q1_option[4][60] =
    {
        "5",
        "3",
        "8",
        "53"
    };

    char Q1_explanation[4][150] =
    {
        "5 is the first argument.",
        "3 is the second argument.",
        "5 + 3 equals 8.",
        "the values are added numerically."
    };

    traning_answer(Q1, Q1_option, 3, Q1_explanation); 


    char Q2[] =
        "What is the main purpose of a function?";

    char Q2_option[4][60] =
    {
        "To store multiple values",
        "To repeat code automatically",
        "To perform a specific reusable task",
        "To create an array"
    };

    char Q2_explanation[4][150] =
    {
        "arrays store multiple values.",
        "loops are used for repetition.",
        "functions perform reusable tasks.",
        "arrays are declared separately."
    };

    traning_answer(Q2, Q2_option, 3, Q2_explanation);  
    enter_to_continue();  
}



int Pointer_quizUnlocked = 0;
void PointerTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); 
        printf("\n============================================================\n");
        printf("                     POINTER PEAK\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Pointer_quizUnlocked==1) 
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2);  

        if (choice == 0) 
            return;

        if (choice == 1)  
        {
            Pointer_lesson();  
            Pointer_quizUnlocked = 1;
        }

        else if (choice == 2)  
        {
            if (Pointer_quizUnlocked==1) 
                Pointer_quiz(); 
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue();  
            }
        }
    }
}

void Pointer_lesson()
{
    int section = 1;
    int total_sections = 5;
    char navigation;

    while(section >= 1 && section <= total_sections)
    {
        clear_screen();  
        if(section == 1)  
        {
            printf("============================================================\n");
            printf("                     POINTER PEAK\n");
            printf("============================================================\n\n");
            printf("Welcome, Warrior! You have entered Pointer Peak.\n");
            printf("Here, you will learn how to use pointers to\n");
            printf("manipulate memory addresses directly.\n\n");
            printf("A pointer is a variable that stores the memory address\n");
            printf("of another variable.\n\n");
            printf("Example:\n");
            printf("    int x = 10;\n");
            printf("    int *ptr = &x;\n\n");
            printf("Here, ptr is a pointer that holds the address of x.\n");
        }

        else if(section == 2)  
        {
            printf("------------------------------------------------------------\n");
            printf("                  POINTER DECLARATION\n");
            printf("------------------------------------------------------------\n\n");
            printf("To declare a pointer, use the * symbol:\n\n");
            printf("    data_type *pointer_name;\n\n");
            printf("Example:\n");
            printf("    int *ptr;\n");
            printf("    char *cptr;\n\n");
            printf("The type of the pointer should match the type of the variable\n");
            printf("it points to.\n");
        }

        else if(section == 3)  
        {
            printf("------------------------------------------------------------\n");
            printf("                  POINTER OPERATIONS\n");
            printf("------------------------------------------------------------\n\n");
            printf("You can assign the address of a variable to a pointer using &:\n\n");
            printf("    int x = 10;\n");
            printf("    int *ptr = &x;\n\n");
            printf("You can access the value at the address using * (dereferencing):\n\n");
            printf("    int value = *ptr; // value is now 10\n\n");
            printf("You can also change the value of x through the pointer:\n\n");
            printf("    *ptr = 20; // x is now 20\n");
        }

        else if(section == 4)  
        {
            printf("------------------------------------------------------------\n");
            printf("                  POINTER ARITHMETIC\n");
            printf("------------------------------------------------------------\n\n");
            printf("Pointers can be incremented or decremented to point to\n");
            printf("the next or previous memory location of the same type.\n\n");
            printf("Example:\n");
            printf("    int arr[3] = {10, 20, 30};\n");
            printf("    int *ptr = arr;\n\n");
            printf("    ptr++; // now points to arr[1]\n");
            printf("    ptr--; // now points back to arr[0]\n\n");
            printf("Pointer arithmetic is useful when working with arrays.\n");
        }

        else if(section == 5)  
        {
            printf("------------------------------------------------------------\n");
            printf("                     WARRIOR TIP\n");
            printf("------------------------------------------------------------\n\n");
            printf("Pointers are powerful but require caution.\n\n");
            printf("Always ensure that a pointer points to a valid memory address.\n");
            printf("Dereferencing a NULL or uninitialized pointer can lead to crashes.\n\n");
            printf("Master pointers, Warrior, and you will wield great power!\n");
        }

        // ========================= NAVIGATION =========================
    printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections);  
        if(navigation == 'N')  
        {
            section++;
        }
        else if(navigation == 'P')  
        {
            section--;
        }
        else if(navigation == 'E')  
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }
    }
}

void Pointer_quiz()
{
    clear_screen();  
    printf("============================================================\n");
    printf("                  POINTER KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "What will be the output?\n\n"
        "int x = 10;\n"
        "int *ptr = &x;\n"
        "*ptr = 20;\n"
        "printf(\"%d\", x);";

    char Q1_option[4][60] =
    {
        "10",
        "20",
        "The address of x",
        "Garbage value"
    };

    char Q1_explanation[4][150] =
    {
        "*ptr changes x to 20.",
        "*ptr accesses x and changes it to 20.",
        "%d prints the value, not the address.",
        "x is initialized."
    };

    traning_answer(Q1, Q1_option, 2, Q1_explanation); 

    char Q2[] =
        "What is wrong with this code?\n\n"
        "int x = 10;\n"
        "int *ptr;\n"
        "*ptr = 20;";

    char Q2_option[4][60] =
    {
        "x should be float",
        "ptr is not pointing to a valid address",
        "20 cannot be stored in a pointer",
        "The * operator cannot be used here"
    };

    char Q2_explanation[4][150] =
    {
        "x can be an int.",
        "ptr has not been initialized with a valid address.",
        "20 can be assigned through a valid int pointer.",
        "* is used for dereferencing."
    };

    traning_answer(Q2, Q2_option, 2, Q2_explanation);  
    enter_to_continue();  
}

int String_quizUnlocked = 0;
void StringTraining()
{
    int choice;

    while (1)
    {
        clear_screen();  

        printf("\n============================================================\n");
        printf("                    SILENT CORRIDOR\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (String_quizUnlocked==1)  
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2);  

        if (choice == 0)  
            return;

        if (choice == 1)  
        {
            String_lesson();  
            String_quizUnlocked = 1;
        }

        else if (choice == 2)  
        {
            if (String_quizUnlocked==1)  
                String_quiz();  
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue();  
            }
        }
    }
}

void String_lesson()
{
    int section = 1;
    int total_sections = 5;
    char navigation;

    while(section >= 1 && section <= total_sections)
    {
        clear_screen();  
        if(section == 1)  
        {
            printf("============================================================\n");
            printf("                     SILENT CORRIDOR\n");
            printf("============================================================\n\n");
            printf("Welcome, Warrior! You have entered the Silent Corridor.\n");
            printf("Here, you will learn how to work with strings in C.\n\n");
            printf("A string is an array of characters terminated by a null character '\\0'.\n\n");
            printf("Example:\n");
            printf("    char name[20] = \"Warrior\";\n\n");
            printf("Strings are used to store text such as names, messages, and commands.\n");
        }
        else if(section == 2)  
        {
            printf("------------------------------------------------------------\n");
            printf("                  STRING DECLARATION\n");
            printf("------------------------------------------------------------\n\n");
            printf("You can declare a string as a character array:\n\n");
            printf("    char str[50];\n\n");
            printf("Or initialize it with a value:\n\n");
            printf("    char str[] = \"Hello\";\n\n");
            printf("The size of the array should be large enough to hold the string and the null terminator.\n");
        }

        else if(section == 3)  
        {
            printf("------------------------------------------------------------\n");
            printf("                  STRING INPUT & OUTPUT\n");
            printf("------------------------------------------------------------\n\n");
            printf("You can read a string from the user using scanf:\n\n");
            printf("    char name[20];\n");
            printf("    scanf(\"%%s\", name);\n\n");
            printf("To print a string, use printf:\n\n");
            printf("    printf(\"Hello, %%s!\\n\", name);\n\n");
            printf("IMPORTANT:\n");
            printf("scanf stops reading at whitespace. Use fgets for multi-word strings.\n");
        }

        else if(section == 4)  
        {
            printf("------------------------------------------------------------\n");
            printf("                  STRING FUNCTIONS\n");
            printf("------------------------------------------------------------\n\n");
            printf("C provides several functions to manipulate strings.\n\n");
            printf("Some common string functions include:\n");
            printf("    strlen(str)   -> returns the length of the string\n");
            printf("    strcpy(dest, src) -> copies src to dest\n");
            printf("    strcat(dest, src) -> appends src to dest\n");
            printf("    strcmp(str1, str2) -> compares two strings\n\n");
            printf("These functions are declared in the <string.h> header file.\n");
        }

        else if(section == 5)  
        {
            printf("------------------------------------------------------------\n");
            printf("                     WARRIOR TIP\n");
            printf("------------------------------------------------------------\n\n");
            printf("Strings are powerful for handling text data.\n\n");
            printf("Always ensure that your strings are properly null-terminated.\n");
            printf("Be cautious of buffer overflows when working with strings.\n\n");
            printf("Master strings, Warrior, and you will command the power of words!\n");
        }
           // ========================= NAVIGATION =========================
        printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections);  
        if(navigation == 'N')  
        {
            section++;
        }
        else if(navigation == 'P') 
        {
            section--;
        }
        else if(navigation == 'E') 
        {
            printf("\nLesson Complete!\n");
            enter_to_continue();  
            return;
        }
    }
}

void String_quiz()
{
    clear_screen();  
    printf("============================================================\n");
    printf("                   STRING KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    char Q1[] =
        "What will be the output?\n\n"
        "char name[] = \"Code\";\n"
        "printf(\"%c\", name[1]);";

    char Q1_option[4][60] =
    {
        "C",
        "o",
        "d",
        "e"
    };

    char Q1_explanation[4][150] =
    {
        "name[0] is C.",
        "name[1] is o.",
        "name[2] is d.",
        "name[3] is e."
    };

    traning_answer(Q1, Q1_option, 2, Q1_explanation);  
    char Q2[] =
        "What is wrong with this code?\n\n"
        "char name[5] = \"Warrior\";";

    char Q2_option[4][60] =
    {
        "char cannot store strings",
        "The array is too small",
        "The quotation marks are wrong",
        "Strings cannot be initialized during declaration"
    };

    char Q2_explanation[4][150] =
    {
        "char arrays can store strings.",
        "warrior needs 8 elements including '\\0'.",
        "the quotation marks are valid.",
        "strings can initialize char arrays."
    };

    traning_answer(Q2, Q2_option, 2, Q2_explanation);  
    enter_to_continue();  
}

//__________________UTILITY_____________

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void enter_to_continue() {
    printf("\nPress Enter to continue...");
    getchar();
}
char continue_or_back()
{
    char hold;
    printf("\n___________________________________________");
    printf("\n->Enter \"Back\" to Redirect to menu..\n");
    printf("->Enter to continue....     :");
    while(1){
    hold=getchar();
    if(hold=='B'|| hold=='b'||hold=='\n')
    {
        if(hold=='B'|| hold=='b')
        {
            flush_input();
            return 'R';
        }
        return 'n';         //hudai kono kam nai
    }
    else
    {
        flush_input();
        printf("invalid input, \n Enter corectly :");
    }
}
}
