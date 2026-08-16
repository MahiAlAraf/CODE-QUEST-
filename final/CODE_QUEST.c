#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//_________________________global_variables______________________
char Name[50];
int Coin = 0;
int HP = 100;
int Max_HP = 100;
int XP = 0;
int Iron_shield = 0;
int Pause;
int Vibranium_sheld = 0;
int dubble_XP = 0;
//_______________________function prototypes_____________________
void clear_screen();                                                    // line 212
void enter_to_continue();                                               // line 5979
char continue_or_back();                                                // line 5984
void current_status();                                                  // line 684
void level_status();                                                    // line 691
void flush_input();                                                     // line 5972
void HP_Bar();                                                          // line 664
int answer_input_loop();                                                // line 716
char Yes_No_loop();                                                     // line 734
int correct_answer(char question[], char option[4][60], int correctAns, // line 753
                   int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                   char explanation[4][150]);
void show_menu();           // line 97
int profile_open();         // line 237
void profile_save();        // line 226
void profile_reset();       // line 220
void MarketPlace();         // line 301
void MarketPlace_items();   // line 397
void file_reset();          // line 249
int file_open();            // line 256
void file_save();           // line 268
void Market_open();         // line 282
void Market_save();         // line 294
void Market_reset();        // line 275
void introduction();        // line 409
char new_game();            // line 423
void fallen_statement();    // line 657
int variable_village();     // line 829
int loop_forest();          // line 1075
void After_forest_EQuest(); // line 1383
int array_cave();           // line 1484
void After_cave_shop();     // line 1745
int Function_falls();       // line 1812
int Pointer_peak();         // line 2176
void Precaution_EQuest();   // line 2510
void precaution();          // line 2624
int final_stage();          // line 2667
int NUL_POINTER();          // line 2890
void Congratulations();     // line 3029

char lesson_navigation(int section, int total_sections);                                             // line 3085
int menu_input(int min, int max);                                                                    // line 3121
void training_answer(char question[], char option[4][60], int correctAns, char explanation[4][150]); // line 3145

void training();                 // line 3183
void VariableDatatypeTraining(); // line 3244
void V_D_lesson();               // line 3290
void V_D_quiz();                 // line 3387

void ConditionTraining(); // line 3601
void Condition_lesson();  // line 3648
void Condition_quiz();    // line 3794

void LoopTraining(); // line 4025
void Loop_lesson();  // line 4072
void Loop_quiz();    // line 4235

void ArrayTraining(); // line 4465
void Array_lesson();  // line 4512
void Array_quiz();    // line 4613

void FunctionTraining(); // line 4831
void Function_lesson();  // line 4877
void Function_quiz();    // line 5020

void PointerTraining(); // line 5252
void Pointer_lesson();  // line 5298
void Pointer_quiz();    // line 5398

void StringTraining(); // line 5615
void String_lesson();  // line 5662
void String_quiz();    // line 5754

int main()
{
    show_menu(); // line 97
    return 0;
}

//__________________MAIN MENU_____________
void show_menu()
{
    int choice;
    file_open(); // line 256
    printf(
        "   ______   ____  \n"
        "  / ____/  / __ \\ \n"
        " | |      | |  | |\n"
        " | |      | |  | |\n"
        " | |____  | |__| |\n"
        "  \\_____|  \\___\\_\\\n");
    printf("================================================\n");
    printf("  CODE QUEST: Escape from the Compiler Kingdom\n");
    printf("================================================\n");
    printf("1. New Game\n2. Continue\n3. MarketPlace\n4. Profile\n5. Traning\n6. Exit\n");
    printf("Enter choice: ");

    while (1)
    {
        scanf("%d", &choice);
        flush_input(); // line 5972
        if (choice >= 1 && choice <= 6)
        {
            break;
        }
        else
            printf("Invalid Input....\nEnter again: ");
    }

    if (choice == 1)
    {
        file_reset();          // line 249
        profile_reset();       // line 220
        Market_reset();        // line 275
        clear_screen();        // line 212
        introduction();        // line 409
        enter_to_continue();   // line 5979
        clear_screen();        // line 212
        if (new_game() == 'B') // line 423
        {
            clear_screen(); // line 212
            show_menu();    // line 97
        }
    }
    else if (choice == 2)
    {
        clear_screen(); // line 212
        if (file_open() == 0)
        { // line 256
            printf("\nNo saved game found. Starting a new game...\n");
            file_reset();        // line 249
            introduction();      // line 409
            enter_to_continue(); // line 5979
        }
        else
        {
            profile_open(); // line 237
        }
        clear_screen();        // line 212
        if (new_game() == 'B') // line 423
        {
            clear_screen(); // line 212
            show_menu();    // line 97
        }
    }
    else if (choice == 3)
    {
        if (Pause == 1 || XP <= 25)
        {
            printf("Marketplace is locked. You need to reach at least level \"Noob\" to access it.\n");
            enter_to_continue(); // line 5979
            clear_screen();      // line 212
            show_menu();         // line 97
        }
        else
        {
            MarketPlace();       // line 301
            enter_to_continue(); // line 5979
            clear_screen();      // line 212
            show_menu();         // line 97
        }
    }
    else if (choice == 4)
    {
        if (profile_open() == 0) // line 237
        {
            printf("\nNo profile found.\n\n\n");
        }
        else
        {
            printf("\nProfile loaded successfully.\n");
            profile_open(); // line 237
            file_open();    // line 256
            printf("\nProfile Name: %s\n", Name);
            printf("Current HP    :     %d\n", HP);
            printf("Current XP    :     %d\n", XP);
            level_status(); // line 691
            printf("Current Coins :     %d\n\n\n", Coin);
        }
        enter_to_continue(); // line 5979
        clear_screen();      // line 212
        show_menu();         // line 97
    }
    else if (choice == 5)
    {
        training();     // line 3183
        clear_screen(); // line 212
        show_menu();    // line 97
    }
    else
    {
        printf("\n   Goodbye, Apprentice.\n");
        printf("==========game end===========\n");
    }
}
void clear_screen()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear"); // for Linux and Macos
#endif
}
void profile_reset()
{
    FILE *reset;
    reset = fopen("profile.txt", "w");
    fclose(reset);
}
void profile_save()
{
    printf("Enter your name: ");
    scanf("%s", Name);
    flush_input(); // line 5972
    printf("\nWelcome %s, your journey begins!\n", Name);
    FILE *save;
    save = fopen("profile.txt", "w");
    fprintf(save, "%49s", Name);
    fclose(save);
}
int profile_open()
{
    FILE *save;
    save = fopen("profile.txt", "r");
    if (save == NULL)
    {
        return 0;
    }
    fscanf(save, "%s\n", Name);
    fclose(save);
    return 1;
}
void file_reset()
{
    FILE *reset;
    reset = fopen("save.txt", "w");
    fprintf(reset, "%d %d %d %d %d", 1, 100, 0, 0, 0);
    fclose(reset);
}
int file_open()
{
    FILE *save;
    save = fopen("save.txt", "r");
    if (save == NULL)
    {
        return 0;
    }
    fscanf(save, "%d %d %d %d %d", &Pause, &HP, &Coin, &XP, &Iron_shield);
    fclose(save);
    return 1;
}
void file_save()
{
    FILE *save;
    save = fopen("save.txt", "w");
    fprintf(save, "%d %d %d %d %d", Pause, HP, Coin, XP, Iron_shield);
    fclose(save);
}
void Market_reset()
{
    FILE *reset;
    reset = fopen("market.txt", "w");
    fprintf(reset, "%d %d", 0, 0);
    fclose(reset);
}
void Market_open()
{
    FILE *open;
    open = fopen("market.txt", "r");
    if (open == NULL)
    {
        Market_reset(); // line 275
        open = fopen("market.txt", "r");
    }
    fscanf(open, "%d %d", &Vibranium_sheld, &dubble_XP);
    fclose(open);
}
void Market_save()
{
    FILE *save;
    save = fopen("market.txt", "w");
    fprintf(save, "%d %d", Vibranium_sheld, dubble_XP);
    fclose(save);
}
void MarketPlace()
{
    Market_open(); // line 282
    printf("\n====================MARKETPLACE====================\n");
    printf("Welcome to the Marketplace, %s!\n", Name);
    printf("Here you can buy special items to aid your journey.\n");
    printf("Your current coins: %d\n", Coin);
    while (1)
    {
        MarketPlace_items(); // line 397
        file_open();         // line 256
        int choice;
        choice = answer_input_loop(); // line 716

        if (choice == 1)
        {
            if (Coin >= 200)
            {
                Vibranium_sheld = 1;
                Coin = Coin - 200;
                printf("You have purchased the Vibranium Shield!\n");
                break;
            }
            else
            {
                printf("Insufficient coins for Vibranium Shield.\n");
                continue;
            }
        }
        else if (choice == 2)
        {
            if (Coin >= 150)
            {
                dubble_XP = 1;
                Coin = Coin - 150;
                printf("You have purchased the Double XP Potion!\n");
                break;
            }
            else
            {
                printf("Insufficient coins for Double XP Potion.\n");
                continue;
            }
        }
        else if (choice == 3)
        {
            if (HP == Max_HP)
            {
                printf("You are already at maximum HP. No need to buy HP drops.\n");
                continue;
            }
            else
            {
                printf("How many HP drops would you like to buy? (1-25): ");
                int drops;
                while (1)
                {
                    scanf("%d", &drops);
                    flush_input(); // line 5972
                    if (drops >= 1 && drops <= 25)
                    {
                        break;
                    }
                    else
                    {
                        printf("Invalid input. Please enter a number between 1 and 25: ");
                    }
                }
                if (Coin >= (drops * 4))
                {
                    HP = HP + drops;
                    if (HP > Max_HP)
                    {
                        HP = Max_HP;
                    }
                    Coin = Coin - (drops * 4);
                    printf("You have purchased %d HP drops! Your current HP: %d\n", drops, HP);
                    break;
                }
                else
                {
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
    Market_save(); // line 294
    file_save();   // line 268
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

    profile_save(); // line 226
    profile_open(); // line 237
}

//___________________________________________________________NEW GAME____________________________________________________
char new_game()
{

    while (1)
    {
        file_open(); // line 256
        if (Pause == 1)
        {
            HP = variable_village(); // line 829
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            Pause = 2;
            file_save(); // line 268
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }
        if (Pause == 2)
        {
            HP = loop_forest(); // line 1075
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            Pause = 3;
            file_save();      // line 268
            current_status(); // line 684
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }
        if (Pause == 3)
        {
            printf(" =========================================================================\n");
            printf("       Wizard of Iteration: \"You have restored the second fragment.      \n");
            printf("             But something's wrong deeper in the kingdom.              \n");
            printf("      The caves beyond the forest are collapsing. Tunnels vanishing,      \n");
            printf("        paths caving in without warning. That's not natural.          \n");
            printf("          Something is reading memory it was never meant to touch.\"        \n");
            printf("        Wizard of Iteration: \"Go to Array Cave, apprentice %s.       \n", Name);
            printf("Whatever broke the loops here..it's reaching further than we thought.\"\n");
            printf("=========================================================================\n");
            enter_to_continue();   // line 5979
            After_forest_EQuest(); // line 1383
            file_save();           // line 268
            current_status();      // line 684
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
            Pause = 4;
        }
        if (Pause == 4)
        {
            HP = array_cave(); // line 1484
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            Pause = 5;
            file_save(); // line 268
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }
        if (Pause == 5)
        {
            printf("-----------------------------------------------------------------------------------------\n");
            printf("%s : OHH, at last back in one piece. I guess there should be Function Falls ahead.\n", Name);
            current_status(); // line 684
            printf("Need to do something about it\n");
            printf("Want to search for any store? (y/n): ");
            char store_choice = Yes_No_loop(); // line 734
            if (store_choice == 'y' || store_choice == 'Y')
            {
                After_cave_shop(); // line 1745
                file_save();       // line 268
            }
            else
            {
                printf("OK, to the next phase then...\n");
            }
            Pause = 6;
            file_save(); // line 268
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }
        if (Pause == 6)
        {
            HP = Function_falls(); // line 1812
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            Pause = 7;
            file_save();      // line 268
            current_status(); // line 684
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }
        if (Pause == 7)
        {
            HP = Pointer_peak(); // line 2176
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            Pause = 8;
            file_save();         // line 268
            current_status();    // line 684
            enter_to_continue(); // line 5979
            clear_screen();      // line 212
        }
        if (Pause == 8)
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
            enter_to_continue(); // line 5979
            clear_screen();      // line 212
            current_status();    // line 684
            printf("\n\n%s : I think I should take some precaution steps before facing the NULL POINTER\n", Name);
            printf("%s : Let's head back to the store and see what I can grab.\n\n", Name);
            printf("\n\n----------On the way to the store, %s found a man seeking his help!", Name);
            printf("\nWant to see? Or ignore him?\ny/n: ");

            char decision = Yes_No_loop(); // line 734
            if (decision == 'y' || decision == 'Y')
            {
                clear_screen();      // line 212
                Precaution_EQuest(); // line 2510
                file_save();         // line 268
            }
            else
            {
                clear_screen(); // line 212
                printf("Are you sure you want to avoid this? This might be a great chance to win some coins...\n");
                printf("y/n: ");
                char decision2 = Yes_No_loop(); // line 734
                if (decision2 == 'y' || decision2 == 'Y')
                {
                    printf("%s : Sorry sir, but I am in a hurry, I have not much time.\n\n", Name);
                }
                else
                {
                    clear_screen();      // line 212
                    Precaution_EQuest(); // line 2510
                    file_save();         // line 268
                }
            }
            enter_to_continue(); // line 5979
            clear_screen();      // line 212
            precaution();        // line 2624
            Pause = 9;
            file_save(); // line 268
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }

        if (Pause == 9)
        {
            HP = final_stage(); // line 2667
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            Pause = 10;
            file_save(); // line 268
            if (continue_or_back() == 'R')
                return 'B'; // line 5984
            clear_screen(); // line 212
        }
        if (Pause == 10)
        {
            HP = NUL_POINTER(); // line 2890
            if (HP <= 0)
            {
                fallen_statement();  // line 657
                enter_to_continue(); // line 5979
                clear_screen();      // line 212
                file_reset();        // line 249
                continue;
            }
            remove("save.txt");
            profile_reset(); // line 220
            Market_reset();  // line 275
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
void HP_Bar()
{
    int filled = (HP * 10) / Max_HP;
    int i;

    printf("HP[");
    for (i = 0; i < 10; i++)
    {
        if (i < filled)
        {
            printf("#");
        }
        else
        {
            printf(".");
        }
    }
    printf("]%d/%d\n", HP, Max_HP);
}
//__________________________________curent status___________________________________
void current_status()
{
    printf("\n\n<------------------your current status---------------->\n");
    printf("       %d HP  ;   %d   XP    ;    %d   Coins\n", HP, XP, Coin);
    HP_Bar();       // line 664
    level_status(); // line 691
}
void level_status()
{
    if (XP > 85)
    {
        printf("    Level  :   Expert\n");
    }
    else if (XP > 75)
    {
        printf("    Level  :   Advanced\n");
    }
    else if (XP > 50)
    {
        printf("    Level   :    Intermediate\n");
    }
    else if (XP > 25)
    {
        printf("    Level    :   Noob\n");
    }
    else
    {
        printf("    Level     :  Beginner\n");
    }
}

//__________________VALIDATED ANSWER INPUT_____________
int answer_input_loop()
{
    int answer;
    while (1)
    {
        scanf("%d", &answer);
        flush_input(); // line 5972
        if (answer == 1 || answer == 2 || answer == 3 || answer == 4)
        {
            return answer;
        }
        else
        {
            printf("Invalid Input....\nEnter again: ");
        }
    }
}
//_____________________________________Yes NO loop______________________________________
char Yes_No_loop()
{
    char answer;
    while (1)
    {
        scanf(" %c", &answer);
        flush_input(); // line 5972
        if (answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
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
                   char explanation[4][150])
{
    int i, answer, is_wrong;
    Market_open(); // line 282

    printf("\n%s\n", question);
    for (i = 0; i < 4; i++)
    {
        printf("%d. %s\n", i + 1, option[i]);
    }
    printf("Enter Answer: ");
    answer = answer_input_loop(); // line 716

    if (answer == correctAns)
    {
        if (dubble_XP == 1)
        {
            reward_XP = reward_XP * 2;
            dubble_XP = 0;
            printf("Your Double XP Potion doubles your XP reward!\n");
        }
        printf("Correct!...\n+%d XP  +%d Coin\n", reward_XP, Reward_Coin);
        XP = XP + reward_XP;
        Coin = Coin + Reward_Coin;
        is_wrong = 0;
    }
    else
    {
        int actual_penalty = HP_Minus_if_wrong;
        printf("Wrong! The correct answer is: %s\n", option[correctAns - 1]);
        if (Vibranium_sheld == 1)
        {
            actual_penalty = 0;
            Vibranium_sheld = 0;
            printf("Your Vibranium Shield absorbs all the damage!\n");
        }
        else if (Iron_shield == 1)
        {
            actual_penalty = actual_penalty / 2;
            Iron_shield = 0;
            printf("Your Iron Shield absorbs half the damage!\n");
        }
        printf("-%d HP\n", actual_penalty);
        HP = HP - actual_penalty;
        if (HP < 0)
        {
            HP = 0;
        }
        HP_Bar(); // line 664
        is_wrong = 1;
    }
    Market_save(); // line 294

    printf("Want to see why?...\n");
    char yes;
    printf("\n Choose : y/n  :");
    yes = Yes_No_loop(); // line 734
    if (yes == 'y' || yes == 'Y')
    {
        for (i = 0; i < 4; i++)
        {
            printf("%s\n", explanation[i]);
        }
        enter_to_continue(); // line 5979
        clear_screen();      // line 212
    }
    else
    {
        clear_screen(); // line 212
    }
    return is_wrong;
}

//_________________________________________REGION 1: VARIABLES VILLAGE_________________________________________
int variable_village()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));
    printf("\n========================================\n");
    printf("REGION 1: Variables Village\n");
    printf("========================================\n");
    printf("Village houses keep changing values. Nobody trusts anything anymore.\n");
    printf("Elder Byte: \"Fix our variables, apprentice. Show them what's real.\"\n\n");
    printf("Be careful, wrong answers cost HP. Your current HP:\n");
    HP_Bar();            // line 664
    enter_to_continue(); // line 5979
    clear_screen();      // line 212

    //________________question NO. 1_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit; // uper limit =4; lower limit =1;
    if (Time == 1)
    {
        char Q1[] = "Which data type stores a single character like 'A'?";
        char Q1_option[4][60] = {"int", "char", "float", "double"};
        char Q1_explanation[4][150] = {
            "int - stores whole numbers (no decimals), not meant for letters.",
            "char - designed specifically to hold a single character. Correct answer.",
            "float - stores decimal numbers like 3.14, not characters.",
            "double - stores larger, more precise decimal numbers, also not characters."};
        correct_answer(Q1, Q1_option, 2, 10, 3, 2, Q1_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q1[] = "Which data type is used to store high-precision decimal numbers in C?";
        char Q1_option[4][60] = {"int", "double", "char", "bool"};
        char Q1_explanation[4][150] = {
            "int - used for whole numbers without decimal places.",
            "double - stores high-precision 64-bit floating-point numbers. Correct answer.",
            "char - used for storing single characters or small integers.",
            "bool - used for true/false boolean values."};
        correct_answer(Q1, Q1_option, 2, 10, 3, 2, Q1_explanation);
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q1[] = "Which data type modifier allows an integer variable to hold only non-negative values?";
        char Q1_option[4][60] = {"signed", "unsigned", "long", "short"};
        char Q1_explanation[4][150] = {
            "signed - allows both positive and negative values.",
            "unsigned - restricts values to positive numbers and zero. Correct answer.",
            "long - increases the storage size/range of an integer.",
            "short - decreases the storage size of an integer."};
        correct_answer(Q1, Q1_option, 2, 10, 3, 2, Q1_explanation);
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q1[] = "Which data type keyword represents the absence of a value or type?";
        char Q1_option[4][60] = {"null", "void", "empty", "zero"};
        char Q1_explanation[4][150] = {
            "null - represents a null pointer constant, not a C data type.",
            "void - represents an empty type or no return value. Correct answer.",
            "empty - not a valid keyword in standard C.",
            "zero - a numeric literal, not a data type."};
        correct_answer(Q1, Q1_option, 2, 10, 3, 2, Q1_explanation);
        if (HP <= 0)
            return HP;
    }

    //________________question NO. 2_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        char Q2[] = "What is the correct way to declare an integer variable named age?";
        char Q2_option[4][60] = {"int age;", "integer age;", "age int;", "var age;"};
        char Q2_explanation[4][150] = {
            "int age; - correct C syntax: type first, then variable name. Correct answer.",
            "integer age; - integer isn't a real C keyword (some other languages use it, C doesn't).",
            "age int; - wrong order; the type must always come before the name in C.",
            "var age; - var isn't a C keyword either (that's from JavaScript)."};
        correct_answer(Q2, Q2_option, 1, 8, 3, 2, Q2_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q2[] = "What is the correct way to declare and initialize a float variable named temp to 36.5?";
        char Q2_option[4][60] = {"float temp = 36.5;", "temp float = 36.5;", "float = 36.5 temp;", "val temp = 36.5;"};
        char Q2_explanation[4][150] = {
            "float temp = 36.5; - correct syntax: type, name, assignment operator, and value. Correct answer.",
            "temp float = 36.5; - wrong order; type must come before the variable name.",
            "float = 36.5 temp; - invalid syntax; variable name must precede assignment.",
            "val temp = 36.5; - 'val' is not a valid keyword in C."};
        correct_answer(Q2, Q2_option, 1, 8, 3, 2, Q2_explanation);
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q2[] = "Which of the following is a VALID variable name in C?";
        char Q2_option[4][60] = {"2score", "_score", "score-total", "int"};
        char Q2_explanation[4][150] = {
            "2score - variable names in C cannot start with a digit.",
            "_score - valid name; variable names can start with letters or underscores. Correct answer.",
            "score-total - hyphens are treated as subtraction operators, not identifier characters.",
            "int - reserved keyword; cannot be used as a variable name."};
        correct_answer(Q2, Q2_option, 2, 8, 3, 2, Q2_explanation);
        if (HP <= 0)
            return HP;
    }
    else if (Time == 4)
    {
        char Q2[] = "How do you declare two integer variables, x and y, on a single line in C?";
        char Q2_option[4][60] = {"int x and y;", "int x, y;", "int x & y;", "int x; y;"};
        char Q2_explanation[4][150] = {
            "int x and y; - 'and' is not a valid separator in C declarations.",
            "int x, y; - commas separate multiple variables of the same type in one statement. Correct answer.",
            "int x & y; - '&' is an address-of or bitwise operator, not a separator.",
            "int x; y; - 'y' is missing its data type specifier."};
        correct_answer(Q2, Q2_option, 2, 8, 3, 2, Q2_explanation);
        if (HP <= 0)
            return HP;
    }

    //________________question NO. 3_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        char Q3[] = "What will this print?\n  int x = 5;\n  x = x + 3;\n  printf(\"%d\", x);";
        char Q3_option[4][60] = {"5", "3", "8", "53"};
        char Q3_explanation[4][150] = {
            "5 - that was the value before the addition happened, not after.",
            "3 - that's just the number being added, not the final result.",
            "8 - correct: 5 + 3 = 8, and x is updated to that new value. Correct answer.",
            "53 - that would only happen if you joined text/strings together, not added numbers."};
        correct_answer(Q3, Q3_option, 3, 12, 4, 3, Q3_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q3[] = "What will this print?\n  int x = 10;\n  int y = 3;\n  printf(\"%d\", x % y);";
        char Q3_option[4][60] = {"3", "1", "3.33", "0"};
        char Q3_explanation[4][150] = {
            "3 - that is the quotient (10 / 3), not the remainder.",
            "1 - correct: 10 % 3 calculates the remainder of division (10 = 3*3 + 1). Correct answer.",
            "3.33 - modulus works with integers and yields integer remainders, not floats.",
            "0 - 10 is not evenly divisible by 3, so the remainder is non-zero."};
        correct_answer(Q3, Q3_option, 2, 12, 4, 3, Q3_explanation);
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q3[] = "What will this print?\n  int x = 2;\n  x = x * 3 + 1;\n  printf(\"%d\", x);";
        char Q3_option[4][60] = {"8", "7", "6", "9"};
        char Q3_explanation[4][150] = {
            "8 - multiplication happens before addition, so it's not 2 * (3 + 1).",
            "7 - correct: multiplication evaluates first (2 * 3 = 6), then addition (6 + 1 = 7). Correct answer.",
            "6 - that is just 2 * 3, leaving out the + 1 addition step.",
            "9 - incorrect order of evaluation."};
        correct_answer(Q3, Q3_option, 2, 12, 4, 3, Q3_explanation);
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q3[] = "What will this print?\n  int x = 6;\n  x += 4;\n  printf(\"%d\", x);";
        char Q3_option[4][60] = {"6", "4", "10", "64"};
        char Q3_explanation[4][150] = {
            "6 - that was the initial value of x before += 4 was executed.",
            "4 - that is the value being added, not the final result stored in x.",
            "10 - correct: x += 4 is shorthand for x = x + 4, giving 6 + 4 = 10. Correct answer.",
            "64 - C performs numeric addition, not string concatenation."};
        correct_answer(Q3, Q3_option, 3, 12, 4, 3, Q3_explanation);
        if (HP <= 0)
            return HP;
    }

    //________________question NO. 4 - Corrupted Villager (mini-boss)_________________
    printf("\nA Corrupted Villager blocks the village exit!\n");
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    if (Time == 1)
    {
        char Q4[] = "Which data type is used to store decimal numbers like 3.14?";
        char Q4_option[4][60] = {"int", "char", "float", "void"};
        char Q4_explanation[4][150] = {
            "int - only holds whole numbers, would chop off the .14.",
            "char - holds a single character, not numeric values.",
            "float - built specifically for decimal/floating-point numbers. Correct answer.",
            "void - means no value at all, used for functions that return nothing, not a storage type."};
        correct_answer(Q4, Q4_option, 3, 20, 5, 4, Q4_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q4[] = "What happens if you store 9.99 into an 'int' variable in C?";
        char Q4_option[4][60] = {"Rounds to 10", "Truncates to 9", "Causes error", "Stores 9.99"};
        char Q4_explanation[4][150] = {
            "Rounds to 10 - C does not round float values automatically when assigning to int.",
            "Truncates to 9 - C drops the fractional part entirely (.99 is lost). Correct answer.",
            "Causes error - implicit conversion works, but loses precision without a syntax error.",
            "Stores 9.99 - int variables cannot store decimal places at all."};
        correct_answer(Q4, Q4_option, 2, 20, 5, 4, Q4_explanation);
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q4[] = "How many bytes of memory does a standard 'float' typically occupy in standard C?";
        char Q4_option[4][60] = {"1 byte", "2 bytes", "4 bytes", "8 bytes"};
        char Q4_explanation[4][150] = {
            "1 byte - 1 byte is the standard size for a char.",
            "2 bytes - short int typically occupies 2 bytes.",
            "4 bytes - float standardly occupies 4 bytes (32 bits) in C. Correct answer.",
            "8 bytes - 8 bytes is typical for double precision numbers."};
        correct_answer(Q4, Q4_option, 3, 20, 5, 4, Q4_explanation);
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q4[] = "Which data type provides double precision (64-bit) for decimal numbers?";
        char Q4_option[4][60] = {"float", "int", "double", "short"};
        char Q4_explanation[4][150] = {
            "float - single precision (32-bit), less precise than double.",
            "int - used for whole integers, cannot store fractional decimal parts.",
            "double - double-precision floating-point type for higher accuracy. Correct answer.",
            "short - small integer type, does not store decimals."};
        correct_answer(Q4, Q4_option, 3, 20, 5, 4, Q4_explanation);
        if (HP <= 0)
            return HP;
    }

    printf("\nThe Corrupted Villager fades away. The village calms down.\n");
    printf("A fragment of the Great Algorithm is restored!\n");
    printf("Elder Byte: \"Well done. The forest ahead awaits your help.\"\n");
    current_status(); // line 684
    printf("\n");

    return HP;
}

//_________________________________________REGION 2: LOOP FOREST_________________________________________
int loop_forest()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

    printf("                         ==================\n");
    printf("                         ||  Loop Forest ||\n");
    printf("                         ==================\n");
    printf("===========================================================================\n");
    printf("     Trees shaped like `for` and `while`, paths that repeat forever.\n");
    printf("   Travelers wander here, stuck - trapped by loops with no exit condition.\n");
    printf("  A Wizard of Iteration: \"Something forgot how to stop looping. Free them.\"\n");
    printf("============================================================================\n");

    //________________question NO. 1 - loop syntax_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        char Q1[] = "Which of these correctly writes a for loop that runs 5 times (from 0 to 4)?";
        char Q1_option[4][60] = {
            "for (i = 0; i < 5; i++)",
            "for (i = 0, i < 5, i++)",
            "while (i = 0; i < 5; i++)",
            "for i = 0; i < 5; i++"};
        char Q1_explanation[4][150] = {
            "Option 1: correct - semicolons separate the three parts of a for loop.",
            "Option 2: wrong - commas instead of semicolons; won't compile.",
            "Option 3: wrong - mixes while with for syntax.",
            "Option 4: wrong - missing the parentheses ( ) around the loop header."};
        correct_answer(Q1, Q1_option, 1, 10, 5, 3, Q1_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q1[] = "Which of these correctly writes a while loop that runs while i is less than 3?";
        char Q1_option[4][60] = {
            "while (i < 3)",
            "while i < 3",
            "while (i < 3);",
            "until (i < 3)"};
        char Q1_explanation[4][150] = {
            "Option 1: correct - a while loop's condition must sit inside parentheses.",
            "Option 2: wrong - the condition must be wrapped in parentheses in C.",
            "Option 3: wrong - a trailing semicolon here would turn the loop body into an empty statement.",
            "Option 4: wrong - 'until' is not a C keyword."};
        correct_answer(Q1, Q1_option, 1, 10, 5, 3, Q1_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q1[] = "Which of these correctly writes a do-while loop that runs its body once, then checks i < 3?";
        char Q1_option[4][60] = {
            "do { } while (i < 3);",
            "while (i < 3) { } do;",
            "do while (i < 3) { }",
            "do { } until (i < 3);"};
        char Q1_explanation[4][150] = {
            "Option 1: correct - the body runs first, then the condition is checked at the end.",
            "Option 2: wrong - that runs the while loop first, backwards from do-while.",
            "Option 3: wrong - missing the closing 'while(...)' after the body block.",
            "Option 4: wrong - 'until' is not a C keyword."};
        correct_answer(Q1, Q1_option, 1, 10, 5, 3, Q1_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q1[] = "Which of these correctly writes a for loop that counts down from 10 to 1?";
        char Q1_option[4][60] = {
            "for (i = 10; i >= 1; i--)",
            "for (i = 10; i <= 1; i++)",
            "for (i = 10, i >= 1, i--)",
            "for i = 10; i >= 1; i--"};
        char Q1_explanation[4][150] = {
            "Option 1: correct - starts at 10, decrements, stops once i drops below 1.",
            "Option 2: wrong - i++ would move away from 1, not toward it; this never runs.",
            "Option 3: wrong - commas instead of semicolons; won't compile.",
            "Option 4: wrong - missing the parentheses ( ) around the loop header."};
        correct_answer(Q1, Q1_option, 1, 10, 5, 3, Q1_explanation); // line 753
        if (HP <= 0)
            return HP;
    }

    //________________question NO. 2 - trace the output_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        char Q2[] = "What does this print?\nfor (int i = 1; i <= 5; i++) {\n    printf(\"%d \", i);\n}";
        char Q2_option[4][60] = {
            "1 2 3 4 5",
            "0 1 2 3 4",
            "1 2 3 4 5 6",
            "5 4 3 2 1"};
        char Q2_explanation[4][150] = {
            "Option 1: correct - starts at 1, stops once i exceeds 5, so it prints 1 through 5.",
            "Option 2: wrong - that would be the output if the loop started at i = 0.",
            "Option 3: wrong - that would need the condition i <= 6.",
            "Option 4: wrong - that's a countdown, this loop counts up."};
        correct_answer(Q2, Q2_option, 1, 10, 5, 3, Q2_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q2[] = "What does this print?\nint i = 0;\nwhile (i < 5) {\n    printf(\"%d \", i);\n    i++;\n}";
        char Q2_option[4][60] = {
            "0 1 2 3 4",
            "1 2 3 4 5",
            "0 1 2 3 4 5",
            "5 4 3 2 1"};
        char Q2_explanation[4][150] = {
            "Option 1: correct - starts at 0, stops once i reaches 5, so it prints 0 through 4.",
            "Option 2: wrong - that would be the output if i started at 1.",
            "Option 3: wrong - the loop stops as soon as i is no longer less than 5.",
            "Option 4: wrong - that's a countdown, this loop counts up."};
        correct_answer(Q2, Q2_option, 1, 10, 5, 3, Q2_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q2[] = "What does this print?\nint i = 1;\ndo {\n    printf(\"%d \", i);\n    i++;\n} while (i <= 3);";
        char Q2_option[4][60] = {
            "1 2 3",
            "1 2 3 4",
            "0 1 2",
            "3 2 1"};
        char Q2_explanation[4][150] = {
            "Option 1: correct - the body runs for i = 1, 2, 3, then stops once i becomes 4.",
            "Option 2: wrong - the loop stops once i exceeds 3, so 4 is never printed.",
            "Option 3: wrong - i starts at 1, not 0.",
            "Option 4: wrong - this loop counts up, not down."};
        correct_answer(Q2, Q2_option, 1, 10, 5, 3, Q2_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q2[] = "What does this print?\nfor (int i = 5; i >= 1; i--) {\n    printf(\"%d \", i);\n}";
        char Q2_option[4][60] = {
            "5 4 3 2 1",
            "1 2 3 4 5",
            "5 4 3 2 1 0",
            "4 3 2 1"};
        char Q2_explanation[4][150] = {
            "Option 1: correct - starts at 5, decrements, stops once i drops below 1.",
            "Option 2: wrong - that's counting up, this loop counts down.",
            "Option 3: wrong - the loop stops once i is no longer >= 1, so 0 never prints.",
            "Option 4: wrong - i starts at 5, not 4."};
        correct_answer(Q2, Q2_option, 1, 10, 5, 3, Q2_explanation); // line 753
        if (HP <= 0)
            return HP;
    }

    //________________question NO. 3 - spot the infinite loop_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
            "Snippet 4: ends normally - counts down from 10 to 1, correctly decrementing each pass."};
        correct_answer(Q3, Q3_option, 3, 10, 6, 4, Q3_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q3[] = "Three of these loops end normally. One never stops. Which is trapped?\n"
                    "Snippet 1: for (int i = 0; i < 5; i++) { }\n"
                    "Snippet 2: int i = 5; while (i > 0) { i--; }\n"
                    "Snippet 3: int i = 5; while (i > 0) { i = i; }\n"
                    "Snippet 4: for (int i = 5; i > 0; i--) { }";
        char Q3_option[4][60] = {"Snippet 1", "Snippet 2", "Snippet 3", "Snippet 4"};
        char Q3_explanation[4][150] = {
            "Snippet 1: ends normally - i increments every pass, eventually hits 5.",
            "Snippet 2: ends normally - i-- inside the loop body correctly moves it toward 0.",
            "Snippet 3: infinite - i = i does nothing; i never actually changes, so i > 0 stays true forever.",
            "Snippet 4: ends normally - counts down from 5, correctly decrementing each pass."};
        correct_answer(Q3, Q3_option, 3, 10, 6, 4, Q3_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q3[] = "Three of these loops end normally. One never stops. Which is trapped?\n"
                    "Snippet 1: int i = 0; do { i++; } while (i < 5);\n"
                    "Snippet 2: int i = 10; while (i != 0) { i -= 3; }\n"
                    "Snippet 3: for (int i = 0; i < 10; i += 2) { }\n"
                    "Snippet 4: int i = 0; while (i < 3) { i++; }";
        char Q3_option[4][60] = {"Snippet 1", "Snippet 2", "Snippet 3", "Snippet 4"};
        char Q3_explanation[4][150] = {
            "Snippet 1: ends normally - i increments each pass until it reaches 5.",
            "Snippet 2: infinite - i steps by 3 (10,7,4,1,-2,...) and skips over exactly 0, so i != 0 never becomes false.",
            "Snippet 3: ends normally - i steps by 2 and lands exactly on 10, ending the loop.",
            "Snippet 4: ends normally - i increments each pass until it reaches 3."};
        correct_answer(Q3, Q3_option, 2, 10, 6, 4, Q3_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q3[] = "Three of these loops end normally. One never stops. Which is trapped?\n"
                    "Snippet 1: for (int i = 10; i >= 0; i--) { }\n"
                    "Snippet 2: int i = 0; while (i < 5) { printf(\"%d\", i); i++; }\n"
                    "Snippet 3: int i = 1; for (;;) { if (i > 5) break; i++; }\n"
                    "Snippet 4: int i = 1; while (i <= 5) { printf(\"%d\", i); }";
        char Q3_option[4][60] = {"Snippet 1", "Snippet 2", "Snippet 3", "Snippet 4"};
        char Q3_explanation[4][150] = {
            "Snippet 1: ends normally - i decrements every pass until it drops below 0.",
            "Snippet 2: ends normally - i++ inside the loop moves it toward the exit condition.",
            "Snippet 3: ends normally - the break statement exits once i exceeds 5.",
            "Snippet 4: infinite - i is never incremented anywhere inside the loop, so i <= 5 stays true forever."};
        correct_answer(Q3, Q3_option, 4, 10, 6, 4, Q3_explanation); // line 753
        if (HP <= 0)
            return HP;
    }

    //________________question NO. 4 - mini-boss: Infinite Loop Beast (off-by-one bug)_________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        char Q4[] = "int total = 0;\nfor (int i = 0; i <= 5; i++) {\n    total = total + i;\n}\n\n"
                    "This is meant to sum the numbers 0 through 4 (0+1+2+3+4 = 10), but it gives the wrong result. What's the bug?";
        char Q4_option[4][60] = {
            "total should start at 1, not 0",
            "The condition should be i < 5, not i <= 5",
            "i should start at 1, not 0",
            "total = total + i should be total = i"};
        char Q4_explanation[4][150] = {
            "Option 1: wrong - starting total at 0 is correct; that's the right 'empty sum' starting point.",
            "Option 2: correct - i <= 5 lets the loop run one extra time (includes 5), the classic off-by-one bug.",
            "Option 3: wrong - starting i at 0 is intentional, since the goal is to include 0 in the sum.",
            "Option 4: wrong - that would overwrite total every time instead of accumulating it."};
        correct_answer(Q4, Q4_option, 2, 10, 9, 5, Q4_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 2)
    {
        char Q4[] = "int total = 0;\nfor (int i = 1; i < 5; i++) {\n    total = total + i;\n}\n\n"
                    "This is meant to sum the numbers 1 through 5 (1+2+3+4+5 = 15), but it gives the wrong result. What's the bug?";
        char Q4_option[4][60] = {
            "total should start at 1, not 0",
            "The condition should be i <= 5, not i < 5",
            "i should start at 0, not 1",
            "total = total + i should be total = i"};
        char Q4_explanation[4][150] = {
            "Option 1: wrong - starting total at 0 is correct; that's the right 'empty sum' starting point.",
            "Option 2: correct - i < 5 stops one pass too early, skipping the number 5, the classic off-by-one bug.",
            "Option 3: wrong - starting i at 1 is intentional, since 0 shouldn't be included in this sum.",
            "Option 4: wrong - that would overwrite total every time instead of accumulating it."};
        correct_answer(Q4, Q4_option, 2, 10, 9, 5, Q4_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else if (Time == 3)
    {
        char Q4[] = "int product = 1;\nfor (int i = 1; i < 4; i++) {\n    product = product * i;\n}\n\n"
                    "This is meant to calculate 4! (1*2*3*4 = 24), but it gives the wrong result. What's the bug?";
        char Q4_option[4][60] = {
            "product should start at 0, not 1",
            "The condition should be i <= 4, not i < 4",
            "i should start at 0, not 1",
            "product = product * i should be product = i"};
        char Q4_explanation[4][150] = {
            "Option 1: wrong - starting product at 0 would make the whole result 0; 1 is the correct starting point.",
            "Option 2: correct - i < 4 stops one pass too early, skipping the multiply-by-4 step.",
            "Option 3: wrong - starting i at 1 is intentional; multiplying by 0 would zero out the whole product.",
            "Option 4: wrong - that would overwrite product every time instead of multiplying into it."};
        correct_answer(Q4, Q4_option, 2, 10, 9, 5, Q4_explanation); // line 753
        if (HP <= 0)
            return HP;
    }
    else
    {
        char Q4[] = "int sum = 0;\nfor (int i = 1; i <= 6; i++) {\n    sum = sum + i;\n}\n\n"
                    "This is meant to sum the numbers 1 through 5 (1+2+3+4+5 = 15), but it gives the wrong result. What's the bug?";
        char Q4_option[4][60] = {
            "sum should start at 1, not 0",
            "The condition should be i < 6, not i <= 6",
            "i should start at 0, not 1",
            "sum = sum + i should be sum = i"};
        char Q4_explanation[4][150] = {
            "Option 1: wrong - starting sum at 0 is correct; that's the right 'empty sum' starting point.",
            "Option 2: correct - i <= 6 lets the loop run one extra time (includes 6), the classic off-by-one bug.",
            "Option 3: wrong - starting i at 1 is intentional, since 0 shouldn't be part of this sum.",
            "Option 4: wrong - that would overwrite sum every time instead of accumulating it."};
        correct_answer(Q4, Q4_option, 2, 10, 9, 5, Q4_explanation); // line 753
        if (HP <= 0)
            return HP;
    }

    printf("\nCongratulations %s, you have found a way out of the Loop Forest!\n", Name);

    return HP;
}

//_____________________________________________Loop forest Quest_______________________________________________
void After_forest_EQuest()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

    printf("\n\nOhh wait... another traveler is waving for help.\n");
    printf("Want to help her out? (y/n): ");
    char choice = Yes_No_loop(); // line 734

    if (choice == 'y' || choice == 'Y')
    {
        clear_screen(); // line 212
        printf("\n=============================SIDE QUEST===================================\n");
        printf("             Note: Side quests may give rewards but never cost HP.\n\n");
        printf("A traveler waves at you from a loop: \"Help me - I don't know if I'll ever get out!\"\n");

        int wrong;
        Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
        if (Time == 1)
        {
            char side_Q1[] = "int count = 5;\nwhile (count > 0)\n{\n    printf(\"Counting down: %d\\n\", count);\n    count--;\n}";
            char side_q1_options[4][60] = {
                "Yes, it will escape",
                "No, count > 0 stays true forever",
                "Yes, but only if count starts even",
                "No, while loops never stop"};
            char side_Q1_explanation[4][150] = {
                "Option 1: correct - count-- moves count toward 0 every pass, so the loop ends once count is no longer greater than 0.",
                "Option 2: wrong - that would only be true if count were never modified inside the loop.",
                "Option 3: wrong - the starting value being even or odd doesn't matter here; it counts down to 0 either way.",
                "Option 4: wrong - while loops absolutely can and do stop, as long as the condition eventually becomes false."};
            wrong = correct_answer(side_Q1, side_q1_options, 1, 0, 8, 3, side_Q1_explanation); // line 753
        }
        else if (Time == 2)
        {
            char side_Q1[] = "int i = 0;\nwhile (i < 4)\n{\n    printf(\"Step %d\\n\", i);\n    i++;\n}";
            char side_q1_options[4][60] = {
                "Yes, i eventually reaches 4 and the loop stops",
                "No, i < 4 stays true forever",
                "Yes, but only if i starts negative",
                "No, while loops never stop"};
            char side_Q1_explanation[4][150] = {
                "Option 1: correct - i++ moves i toward 4 every pass, so the loop ends once i is no longer less than 4.",
                "Option 2: wrong - that would only be true if i were never modified inside the loop.",
                "Option 3: wrong - the starting value doesn't need to be negative; it steps up to 4 regardless.",
                "Option 4: wrong - while loops absolutely can and do stop, as long as the condition eventually becomes false."};
            wrong = correct_answer(side_Q1, side_q1_options, 1, 0, 8, 3, side_Q1_explanation); // line 753
        }
        else if (Time == 3)
        {
            char side_Q1[] = "int n = 8;\ndo\n{\n    printf(\"n = %d\\n\", n);\n    n = n / 2;\n} while (n > 0);";
            char side_q1_options[4][60] = {
                "Yes, n shrinks toward 0 and the loop stops",
                "No, n > 0 stays true forever",
                "Yes, but only if n starts even",
                "No, do-while loops never stop"};
            char side_Q1_explanation[4][150] = {
                "Option 1: correct - integer division keeps shrinking n toward 0, so the loop eventually ends.",
                "Option 2: wrong - that would only be true if n were never modified inside the loop.",
                "Option 3: wrong - integer division still reaches 0 whether n starts even or odd.",
                "Option 4: wrong - do-while loops absolutely can and do stop, once the condition becomes false."};
            wrong = correct_answer(side_Q1, side_q1_options, 1, 0, 8, 3, side_Q1_explanation); // line 753
        }
        else
        {
            char side_Q1[] = "int x = 3;\nfor (; x > 0; x--)\n{\n    printf(\"x = %d\\n\", x);\n}";
            char side_q1_options[4][60] = {
                "Yes, x decrements toward 0 and the loop stops",
                "No, x > 0 stays true forever",
                "Yes, but only if x starts even",
                "No, for loops never stop without an initializer"};
            char side_Q1_explanation[4][150] = {
                "Option 1: correct - x-- moves x toward 0 every pass, so the loop ends once x is no longer greater than 0.",
                "Option 2: wrong - that would only be true if x were never modified inside the loop.",
                "Option 3: wrong - the starting value being even or odd doesn't matter here; it counts down to 0 either way.",
                "Option 4: wrong - a missing initializer doesn't stop a for loop from working; x is already initialized above."};
            wrong = correct_answer(side_Q1, side_q1_options, 1, 0, 8, 3, side_Q1_explanation); // line 753
        }

        if (wrong == 0)
        {
            printf("\nThe Traveler: \"Thank you sir, it was a great help for me.\n");
            printf("I have nothing much to give you but I can surely give you some coins.\"\n");
            printf("----------------------------------------------------------------------\n");
            printf("    Congratulations %s! You have won a bonus of 6 coins and 2 XP.\n", Name);
            Coin = Coin + 6;
            XP = XP + 2;
        }
        else
        {
            printf("Traveler: \"Anyway, thank you sir for your kindness....\"\n");
        }
    }
    else
    {
        printf("\n---------------------------------------------------------------------\n");
        printf("%s: \"I think I have been through a lot for one day.\"\n", Name);
    }
}

//_________________________________________REGION 3: ARRAY CAVE_________________________________________
int array_cave()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

    printf("\n =================================================================================\n");
    printf(" ||                   The apprentice enters Array Cave                            ||\n");
    printf(" ||                    The walls aren't stone anymore                             ||\n");
    printf(" ||they're rows of glowing boxes, stacked side by side, each one holding a number.||\n");
    printf(" ||       This is how the old builders stored things in order: an array.          ||\n");
    printf(" ===================================================================================\n\n");
    printf("The Wizard: \"Careful, apprentice. Step wrong here, and you don't just fail - you corrupt what's next to you.\"\n");
    enter_to_continue(); // line 5979

    //_____________________________________question 1____________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("\nint arr[5] = {10, 20, 30, 40, 50};\n");
        printf("printf(\"%%d\", arr[5]);\n");
        char Q1[] = "What happens?";
        char Q1_option[4][60] = {
            "Prints 50",
            "Prints 0",
            "Undefined behavior - reading out of bounds",
            "Compiler error, won't build"};
        char Q1_explanation[4][150] = {
            "Wrong - arr[5] is past the valid range, there's no guaranteed value there.",
            "Wrong - memory isn't automatically zeroed just because it's out of bounds.",
            "Correct! Valid indices are 0 to 4. arr[5] reaches past the array into memory it doesn't own.",
            "Wrong - this compiles fine; the danger is at runtime, not compile time."};
        correct_answer(Q1, Q1_option, 3, 10, 6, 4, Q1_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\nint arr[3] = {1, 2, 3};\n");
        printf("printf(\"%%d\", arr[-1]);\n");
        char Q1[] = "What happens?";
        char Q1_option[4][60] = {
            "Prints 3",
            "Prints 0",
            "Undefined behavior - reading before the array",
            "Compiler error, won't build"};
        char Q1_explanation[4][150] = {
            "Wrong - there's no wraparound to the last element in C arrays.",
            "Wrong - memory isn't automatically zeroed just because it's out of bounds.",
            "Correct! arr[-1] steps backward before the array's first element, into memory it doesn't own.",
            "Wrong - this compiles fine; the danger is at runtime, not compile time."};
        correct_answer(Q1, Q1_option, 3, 10, 6, 4, Q1_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\nint arr[4] = {2, 4, 6, 8};\n");
        printf("for (int i = 0; i <= 4; i++) {\n");
        printf("    printf(\"%%d \", arr[i]);\n");
        printf("}\n");
        char Q1[] = "What happens?";
        char Q1_option[4][60] = {
            "Prints 2 4 6 8 then stops safely",
            "Prints 2 4 6 8 0",
            "Undefined behavior - arr[4] reads out of bounds",
            "Compiler error, won't build"};
        char Q1_explanation[4][150] = {
            "Wrong - the loop doesn't magically stop safely; i <= 4 still triggers one extra access.",
            "Wrong - there's no guarantee the extra read is 0; it's whatever memory happens to hold.",
            "Correct! i <= 4 lets the loop reach arr[4], one step past the last valid index (3).",
            "Wrong - this compiles fine; the danger is at runtime, not compile time."};
        correct_answer(Q1, Q1_option, 3, 10, 6, 4, Q1_explanation); // line 753
    }
    else
    {
        printf("\nint arr[5] = {1, 2, 3, 4, 5};\n");
        printf("int *p = arr;\n");
        printf("printf(\"%%d\", *(p + 10));\n");
        char Q1[] = "What happens?";
        char Q1_option[4][60] = {
            "Prints 10",
            "Prints 0",
            "Undefined behavior - pointer reads far out of bounds",
            "Compiler error, won't build"};
        char Q1_explanation[4][150] = {
            "Wrong - the number 10 in the code is an offset, not a guaranteed value in memory.",
            "Wrong - memory isn't automatically zeroed just because it's out of bounds.",
            "Correct! p + 10 reaches 10 elements past arr, well outside memory the array owns.",
            "Wrong - this compiles fine; the danger is at runtime, not compile time."};
        correct_answer(Q1, Q1_option, 3, 10, 6, 4, Q1_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //__________________________________Question 2___________________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
            "Arrays can't be used in loops"};
        char Q2_explanation[4][150] = {
            "Wrong - this does NOT print 10; it skips arr[0] and reads out of bounds.",
            "Correct! Starting at i=1 skips arr[0], and i<=4 reads one step past the array on the last pass.",
            "Wrong - sum = 0; is a proper initialization.",
            "Wrong - arrays are meant to be used inside loops; that's the whole point of indexing."};
        correct_answer(Q2, Q2_option, 2, 12, 8, 5, Q2_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\nint arr[5] = {10, 20, 30, 40, 50};\n");
        printf("int max = arr[0];\n");
        printf("for (int i = 0; i <= 5; i++) {\n");
        printf("    if (arr[i] > max) max = arr[i];\n");
        printf("}\n");
        printf("printf(\"%%d\", max);\n");
        char Q2[] = "What's wrong here?";
        char Q2_option[4][60] = {
            "Nothing, prints 50",
            "Off-by-one - loop condition should be i < 5, not i <= 5",
            "max was never initialized",
            "Arrays can't store 5 elements"};
        char Q2_explanation[4][150] = {
            "Wrong - this does NOT safely print 50; it also reads arr[5], one step out of bounds.",
            "Correct! i <= 5 lets the loop reach arr[5], one step past the last valid index (4).",
            "Wrong - max = arr[0]; is a proper initialization.",
            "Wrong - int arr[5] correctly declares room for 5 elements."};
        correct_answer(Q2, Q2_option, 2, 12, 8, 5, Q2_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\nint arr[6] = {1, 2, 3, 4, 5, 6};\n");
        printf("int count = 0;\n");
        printf("for (int i = 1; i < 6; i++) {\n");
        printf("    count++;\n");
        printf("}\n");
        printf("printf(\"%%d\", count);\n");
        char Q2[] = "This is meant to count all 6 elements. What's wrong here?";
        char Q2_option[4][60] = {
            "Nothing, prints 6",
            "Off-by-one - loop should start at i = 0, not i = 1",
            "count was never initialized",
            "Arrays can't be counted in a loop"};
        char Q2_explanation[4][150] = {
            "Wrong - this does NOT print 6; starting at i=1 skips one pass, so it undercounts.",
            "Correct! Starting at i=1 skips the element at index 0, so count ends up one short.",
            "Wrong - count = 0; is a proper initialization.",
            "Wrong - looping over an array's indices to count elements is exactly how it's normally done."};
        correct_answer(Q2, Q2_option, 2, 12, 8, 5, Q2_explanation); // line 753
    }
    else
    {
        printf("\nint arr[4] = {5, 10, 15, 20};\n");
        printf("int total = 0;\n");
        printf("for (int i = 0; i < 4; i++) {\n");
        printf("    total += arr[i + 1];\n");
        printf("}\n");
        printf("printf(\"%%d\", total);\n");
        char Q2[] = "What's wrong here?";
        char Q2_option[4][60] = {
            "Nothing, prints the correct total",
            "Off-by-one - arr[i+1] reads past the array on the last pass",
            "total was never initialized",
            "Arrays can't use i+1 as an index"};
        char Q2_explanation[4][150] = {
            "Wrong - this does NOT print the correct total; the last pass reads out of bounds.",
            "Correct! When i = 3, arr[i+1] becomes arr[4], one step past the last valid index (3).",
            "Wrong - total = 0; is a proper initialization.",
            "Wrong - i+1 is a perfectly valid index expression; the problem is only that it goes out of range here."};
        correct_answer(Q2, Q2_option, 2, 12, 8, 5, Q2_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //__________________________________________question 3________________________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("\nint arr[3] = {5, 10, 15};\n");
        printf("int *p = arr;\n");
        printf("printf(\"%%d\", *(p + 2));\n");
        char Q3[] = "What prints?";
        char Q3_option[4][60] = {
            "5",
            "10",
            "15",
            "Garbage - invalid syntax"};
        char Q3_explanation[4][150] = {
            "Wrong - that's arr[0], not what *(p+2) points to.",
            "Wrong - that's arr[1], one step short.",
            "Correct! p points to arr[0]; *(p+2) is arr[2] = 15. Arrays and pointer arithmetic are the same thing under the hood.",
            "Wrong - this is completely valid C syntax."};
        correct_answer(Q3, Q3_option, 3, 15, 10, 5, Q3_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\nint arr[4] = {2, 4, 6, 8};\n");
        printf("int *p = arr + 1;\n");
        printf("printf(\"%%d\", *(p + 2));\n");
        char Q3[] = "What prints?";
        char Q3_option[4][60] = {
            "4",
            "6",
            "8",
            "Garbage - invalid syntax"};
        char Q3_explanation[4][150] = {
            "Wrong - that's arr[1], where p starts, not where *(p+2) lands.",
            "Wrong - that's arr[2], one step short of where *(p+2) lands.",
            "Correct! p starts at arr[1]; *(p+2) is two steps further, landing on arr[3] = 8.",
            "Wrong - this is completely valid C syntax."};
        correct_answer(Q3, Q3_option, 3, 15, 10, 5, Q3_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\nint arr[5] = {1, 3, 5, 7, 9};\n");
        printf("int *p = &arr[2];\n");
        printf("printf(\"%%d\", *(p - 1));\n");
        char Q3[] = "What prints?";
        char Q3_option[4][60] = {
            "5",
            "1",
            "3",
            "Garbage - invalid syntax"};
        char Q3_explanation[4][150] = {
            "Wrong - that's arr[2], where p starts, not where *(p-1) lands.",
            "Wrong - that's arr[0], one step further back than *(p-1) actually goes.",
            "Correct! p starts at arr[2]; *(p-1) steps one element back, landing on arr[1] = 3.",
            "Wrong - this is completely valid C syntax."};
        correct_answer(Q3, Q3_option, 3, 15, 10, 5, Q3_explanation); // line 753
    }
    else
    {
        printf("\nint arr[3] = {100, 200, 300};\n");
        printf("int *p = arr;\n");
        printf("p++;\n");
        printf("printf(\"%%d\", *p);\n");
        char Q3[] = "What prints?";
        char Q3_option[4][60] = {
            "100",
            "200",
            "300",
            "Garbage - invalid syntax"};
        char Q3_explanation[4][150] = {
            "Wrong - that's arr[0], where p started before p++.",
            "Correct! p starts at arr[0]; p++ moves it one element forward, to arr[1] = 200.",
            "Wrong - reaching arr[2] would need p to be incremented twice, not once.",
            "Wrong - this is completely valid C syntax."};
        correct_answer(Q3, Q3_option, 2, 15, 10, 5, Q3_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    printf("\nWell done %s! Cave stabilizes. Fragment restored.\n", Name);
    return HP;
}
//___________________________________________________Shop After array cave ________________________________________
void After_cave_shop()
{
    clear_screen(); // line 212
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
    while (1)
    {
        Choose = answer_input_loop(); // line 716
        if (Choose == 1)
        {
            if (Coin >= 30)
            {
                printf("Elixir obtained\nHP restored by 50\n");
                HP = HP + 50;
                if (HP >= Max_HP)
                {
                    HP = Max_HP;
                }
                Coin = Coin - 30;
                current_status(); // line 684
                break;
            }
            else
            {
                printf(".... Insufficient Coins \nYou have %d coins.\nPick something else...\n", Coin);
            }
        }
        else if (Choose == 2)
        {
            if (Coin >= 175)
            {
                printf("Iron Shield obtained\nHP penalty canceled by 50%% for the next wrong answer.\n");
                Coin = Coin - 175;
                Iron_shield = 1;
                current_status(); // line 684
                break;
            }
            else
            {
                printf(".... Insufficient Coins \nYou have %d coins.\nPick something else...\n", Coin);
            }
        }
        else if (Choose == 3)
        {
            printf("OK, no purchase made.\n");
            break;
        }
        else
        {
            printf("That item isn't on the shelf. Pick 1 or 2 or 3: ");
        }
    }
    printf("%s : Let's head back to the journey\n", Name);
}

//_________________________________________REGION 4: FUNCTION FALLS_________________________________________
int Function_falls()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

    printf("\n-----------------------------------------------------------------------------------------------------\n");
    printf("|         Water used to pour into the Great Waterwheel and come out exactly as it should            |\n");
    printf("|                     that's what the old engineers called functions.                               |\n");
    printf("|  Now the wheel is jammed. Something's torn its scrolls apart and scattered them across the falls. |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    enter_to_continue(); // line 5979
    clear_screen();      // line 212
    printf("\nElder:\n");
    printf(" ______________________________________________________________________________________ \n");
    printf("|                           Careful this time, traveler.                               |\n");
    printf("|                   One wrong scroll and the whole wheel jams                          |\n");
    printf("|This region will cost you more if you fail - but it'll reward you more if you succeed |\n");
    printf("|______________________________________________________________________________________|\n");
    enter_to_continue(); // line 5979

    //________________________________________________________________Question NO 1_______________________________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
            "Compilation error"};
        char Q1_explanation[4][150] = {
            "Wrong - that would only happen if C passed by reference, which it doesn't by default.",
            "Correct! C passes arguments by value. changeIt only modifies a copy of num, not the original.",
            "Wrong - num is a properly initialized local variable, not garbage.",
            "Wrong - this compiles and runs fine."};
        correct_answer(Q1, Q1_option, 2, 15, 11, 4, Q1_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\nvoid doubleIt(int x) {\n");
        printf("    x = x * 2;\n");
        printf("}\n\n");
        printf("int main() {\n");
        printf("    int num = 7;\n");
        printf("    doubleIt(num);\n");
        printf("    printf(\"%%d\", num);\n");
        printf("    return 0;\n");
        printf("}\n");
        char Q1[] = "What gets printed?";
        char Q1_option[4][60] = {
            "14",
            "7",
            "Garbage value",
            "Compilation error"};
        char Q1_explanation[4][150] = {
            "Wrong - that would only happen if C passed by reference, which it doesn't by default.",
            "Correct! C passes arguments by value. doubleIt only modifies a copy of num, not the original.",
            "Wrong - num is a properly initialized local variable, not garbage.",
            "Wrong - this compiles and runs fine."};
        correct_answer(Q1, Q1_option, 2, 15, 11, 4, Q1_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\nvoid reset(int x) {\n");
        printf("    x = 0;\n");
        printf("}\n\n");
        printf("int main() {\n");
        printf("    int score = 42;\n");
        printf("    reset(score);\n");
        printf("    printf(\"%%d\", score);\n");
        printf("    return 0;\n");
        printf("}\n");
        char Q1[] = "What gets printed?";
        char Q1_option[4][60] = {
            "0",
            "42",
            "Garbage value",
            "Compilation error"};
        char Q1_explanation[4][150] = {
            "Wrong - that would only happen if C passed by reference, which it doesn't by default.",
            "Correct! C passes arguments by value. reset only modifies a copy of score, not the original.",
            "Wrong - score is a properly initialized local variable, not garbage.",
            "Wrong - this compiles and runs fine."};
        correct_answer(Q1, Q1_option, 2, 15, 11, 4, Q1_explanation); // line 753
    }
    else
    {
        printf("\nvoid addFive(int x) {\n");
        printf("    x = x + 5;\n");
        printf("}\n\n");
        printf("int main() {\n");
        printf("    int val = 10;\n");
        printf("    addFive(val);\n");
        printf("    printf(\"%%d\", val);\n");
        printf("    return 0;\n");
        printf("}\n");
        char Q1[] = "What gets printed?";
        char Q1_option[4][60] = {
            "15",
            "10",
            "Garbage value",
            "Compilation error"};
        char Q1_explanation[4][150] = {
            "Wrong - that would only happen if C passed by reference, which it doesn't by default.",
            "Correct! C passes arguments by value. addFive only modifies a copy of val, not the original.",
            "Wrong - val is a properly initialized local variable, not garbage.",
            "Wrong - this compiles and runs fine."};
        correct_answer(Q1, Q1_option, 2, 15, 11, 4, Q1_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //_____________________________________________Question 2 - recursion___________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
            "Infinite loop"};
        char Q2_explanation[4][150] = {
            "Wrong - that's just the starting value n, not the accumulated sum.",
            "Wrong - that's not how this sum works out.",
            "Correct! It's a sum: 4+3+2+1+0 = 10. Recursion with a proper base case (n==0) always terminates.",
            "Wrong - n == 0 is a valid base case, so this recursion does terminate."};
        correct_answer(Q2, Q2_option, 3, 18, 12, 5, Q2_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\nint mystery(int n) {\n");
        printf("    if (n == 0)\n");
        printf("        return 0;\n");
        printf("    return n + mystery(n - 1);\n");
        printf("}\n");
        char Q2[] = "What does mystery(5) return?";
        char Q2_option[4][60] = {
            "5",
            "20",
            "15",
            "Infinite loop"};
        char Q2_explanation[4][150] = {
            "Wrong - that's just the starting value n, not the accumulated sum.",
            "Wrong - that's not how this sum works out.",
            "Correct! It's a sum: 5+4+3+2+1+0 = 15. Recursion with a proper base case (n==0) always terminates.",
            "Wrong - n == 0 is a valid base case, so this recursion does terminate."};
        correct_answer(Q2, Q2_option, 3, 18, 12, 5, Q2_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\nint fact(int n) {\n");
        printf("    if (n == 1)\n");
        printf("        return 1;\n");
        printf("    return n * fact(n - 1);\n");
        printf("}\n");
        char Q2[] = "What does fact(4) return?";
        char Q2_option[4][60] = {
            "4",
            "10",
            "24",
            "Infinite loop"};
        char Q2_explanation[4][150] = {
            "Wrong - that's just the starting value n, not the accumulated product.",
            "Wrong - that's not how this product works out.",
            "Correct! It's a product: 4*3*2*1 = 24. Recursion with a proper base case (n==1) always terminates.",
            "Wrong - n == 1 is a valid base case, so this recursion does terminate."};
        correct_answer(Q2, Q2_option, 3, 18, 12, 5, Q2_explanation); // line 753
    }
    else
    {
        printf("\nint mystery(int n) {\n");
        printf("    if (n == 0)\n");
        printf("        return 0;\n");
        printf("    return n + mystery(n - 1);\n");
        printf("}\n");
        char Q2[] = "What does mystery(3) return?";
        char Q2_option[4][60] = {
            "3",
            "9",
            "6",
            "Infinite loop"};
        char Q2_explanation[4][150] = {
            "Wrong - that's just the starting value n, not the accumulated sum.",
            "Wrong - that's not how this sum works out.",
            "Correct! It's a sum: 3+2+1+0 = 6. Recursion with a proper base case (n==0) always terminates.",
            "Wrong - n == 0 is a valid base case, so this recursion does terminate."};
        correct_answer(Q2, Q2_option, 3, 18, 12, 5, Q2_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //________________________________________Question 3 - variable shadowing_______________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
        char Q3_option[4][60] = {"00", "1010", "100", "010"};
        char Q3_explanation[4][150] = {
            "Wrong - reset()'s local count and the global count are different variables.",
            "Wrong - that would happen only if both prints referred to the same variable.",
            "Wrong - close, but check the order of digits printed.",
            "Correct! Local count inside reset() shadows the global one. Prints 0, then the global 10 -> \"010\"."};
        correct_answer(Q3, Q3_option, 4, 20, 14, 6, Q3_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\nint val = 5;\n\n");
        printf("void show() {\n");
        printf("    int val = 20;\n");
        printf("    printf(\"%%d\", val);\n");
        printf("}\n\n");
        printf("int main() {\n");
        printf("    show();\n");
        printf("    printf(\"%%d\", val);\n");
        printf("    return 0;\n");
        printf("}\n");
        char Q3[] = "What will be the outcome of the program?";
        char Q3_option[4][60] = {"55", "2020", "520", "205"};
        char Q3_explanation[4][150] = {
            "Wrong - show()'s local val and the global val are different variables.",
            "Wrong - that would happen only if both prints referred to the same variable.",
            "Wrong - close, but check the order of digits printed.",
            "Correct! Local val inside show() shadows the global one. Prints 20, then the global 5 -> \"205\"."};
        correct_answer(Q3, Q3_option, 4, 20, 14, 6, Q3_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\nint score = 3;\n\n");
        printf("void update() {\n");
        printf("    int score = 9;\n");
        printf("    printf(\"%%d\", score);\n");
        printf("}\n\n");
        printf("int main() {\n");
        printf("    update();\n");
        printf("    printf(\"%%d\", score);\n");
        printf("    return 0;\n");
        printf("}\n");
        char Q3[] = "What will be the outcome of the program?";
        char Q3_option[4][60] = {"33", "99", "39", "93"};
        char Q3_explanation[4][150] = {
            "Wrong - update()'s local score and the global score are different variables.",
            "Wrong - that would happen only if both prints referred to the same variable.",
            "Wrong - close, but check the order of digits printed.",
            "Correct! Local score inside update() shadows the global one. Prints 9, then the global 3 -> \"93\"."};
        correct_answer(Q3, Q3_option, 4, 20, 14, 6, Q3_explanation); // line 753
    }
    else
    {
        printf("\nint level = 7;\n\n");
        printf("void change() {\n");
        printf("    int level = 1;\n");
        printf("    printf(\"%%d\", level);\n");
        printf("}\n\n");
        printf("int main() {\n");
        printf("    change();\n");
        printf("    printf(\"%%d\", level);\n");
        printf("    return 0;\n");
        printf("}\n");
        char Q3[] = "What will be the outcome of the program?";
        char Q3_option[4][60] = {"77", "11", "71", "17"};
        char Q3_explanation[4][150] = {
            "Wrong - change()'s local level and the global level are different variables.",
            "Wrong - that would happen only if both prints referred to the same variable.",
            "Wrong - close, but check the order of digits printed.",
            "Correct! Local level inside change() shadows the global one. Prints 1, then the global 7 -> \"17\"."};
        correct_answer(Q3, Q3_option, 4, 20, 14, 6, Q3_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //________________________________________Question 4 - prototypes______________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        char Q4[] = "Which of these will cause a compiler warning/error if placed before main() calls it, with no prototype declared above main?";
        char Q4_option[4][60] = {
            "int add(int a, int b); declared above main",
            "The function defined after main() with no prototype above it",
            "A function defined before main()",
            "None of the above cause issues"};
        char Q4_explanation[4][150] = {
            "Wrong - a prototype above main is exactly what prevents the warning.",
            "Correct! With no prototype above main, the compiler doesn't know the function exists yet - implicit declaration warning/error in modern C.",
            "Wrong - a function fully defined before main() acts as its own prototype; no issue.",
            "Wrong - option 2 does cause an issue."};
        correct_answer(Q4, Q4_option, 2, 22, 16, 7, Q4_explanation); // line 753
    }
    else if (Time == 2)
    {
        char Q4[] = "What happens if a function is called before it is defined, and no prototype has been declared above main()?";
        char Q4_option[4][60] = {
            "The program runs fine every time",
            "Compiler doesn't know it yet - implicit declaration warning",
            "It automatically becomes a prototype",
            "Nothing, C ignores function order entirely"};
        char Q4_explanation[4][150] = {
            "Wrong - relying on this is unsafe; without a prototype the compiler is guessing.",
            "Correct! The compiler hasn't seen the function's signature yet, so it flags an implicit-declaration warning/error.",
            "Wrong - a call site is not a declaration; it doesn't create a prototype.",
            "Wrong - C does care about the order functions are declared or defined relative to their use."};
        correct_answer(Q4, Q4_option, 2, 22, 16, 7, Q4_explanation); // line 753
    }
    else if (Time == 3)
    {
        char Q4[] = "Why do C programmers often place function prototypes near the top of the file, above main()?";
        char Q4_option[4][60] = {
            "To make the file longer",
            "So the compiler knows the function before it's called",
            "Prototypes are required by law in C",
            "To skip writing the function body"};
        char Q4_explanation[4][150] = {
            "Wrong - that's not the purpose; length is just a side effect.",
            "Correct! A prototype tells the compiler the function's signature ahead of time, so calls before the definition are safe.",
            "Wrong - C has no such legal requirement; it's a compiler-warning issue, not a law.",
            "Wrong - a prototype declares a function's signature; the body still has to be written somewhere."};
        correct_answer(Q4, Q4_option, 2, 22, 16, 7, Q4_explanation); // line 753
    }
    else
    {
        char Q4[] = "What is the risk of calling a function in main() when that function is defined below main() with no prototype above it?";
        char Q4_option[4][60] = {
            "No risk, C always resolves this automatically",
            "Compiler may not know it yet - implicit-declaration warning",
            "The program will always crash at compile-time",
            "The function becomes private automatically"};
        char Q4_explanation[4][150] = {
            "Wrong - C does not automatically resolve calls to functions it hasn't seen yet.",
            "Correct! Without a prototype above main, the compiler doesn't yet know the function's signature.",
            "Wrong - it's typically a warning, not a guaranteed compile failure, though behavior can still be risky.",
            "Wrong - C has no such 'private' concept tied to prototypes."};
        correct_answer(Q4, Q4_option, 2, 22, 16, 7, Q4_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    printf("\nWell done %s! The Waterwheel turns once more.\n", Name);
    return HP;
}

int Pointer_peak()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

    printf("The road ends at a tall, grey mountain. Cold wind blows.\nSigns everywhere say \"Do not trust what you see.\"\n");
    printf("An old guard stops you\n\n");
    printf("====================================================================\n");
    printf("                        This is Pointer Peak\n");
    printf("Here, nothing is what it looks like. A box may hold another box\n");
    printf("                    A name may point to a name.\n");
    printf("         One wrong step, and you fall into empty memory\n");
    printf("====================================================================\n");
    printf("He hands you a torch. \"Light your way. Trust the address, not the shadow.\"\n\n");
    enter_to_continue(); // line 5979

    printf("Note: Pointer Peak does not forgive mistakes. -15HP for each wrong answer\n");

    //________________________________Question 1 - dereference assignment__________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("int x = 7;\n");
        printf("int *p = &x;\n");
        printf("*p = *p + 3;\n");
        char Q1[] = "What is x after this code?";
        char Q1_option[4][60] = {"7", "10", "Address of x", "Error"};
        char Q1_explanation[4][150] = {
            "Wrong - *p reads x (7), adds 3, then writes it back into x.",
            "Correct - *p = *p + 3 means \"take what p points to, add 3, store it back.\" Since p points to x, x becomes 10.",
            "Wrong - *p is a value, not an address.",
            "Wrong - this is valid, common pointer code."};
        correct_answer(Q1, Q1_option, 2, 10, 9, 4, Q1_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("int x = 5;\n");
        printf("int *p = &x;\n");
        printf("*p = *p * 4;\n");
        char Q1[] = "What is x after this code?";
        char Q1_option[4][60] = {"5", "20", "Address of x", "Error"};
        char Q1_explanation[4][150] = {
            "Wrong - *p reads x (5), multiplies by 4, then writes it back into x.",
            "Correct - *p = *p * 4 means \"take what p points to, multiply by 4, store it back.\" Since p points to x, x becomes 20.",
            "Wrong - *p is a value, not an address.",
            "Wrong - this is valid, common pointer code."};
        correct_answer(Q1, Q1_option, 2, 10, 9, 4, Q1_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("int x = 12;\n");
        printf("int *p = &x;\n");
        printf("*p = *p - 5;\n");
        char Q1[] = "What is x after this code?";
        char Q1_option[4][60] = {"12", "7", "Address of x", "Error"};
        char Q1_explanation[4][150] = {
            "Wrong - *p reads x (12), subtracts 5, then writes it back into x.",
            "Correct - *p = *p - 5 means \"take what p points to, subtract 5, store it back.\" Since p points to x, x becomes 7.",
            "Wrong - *p is a value, not an address.",
            "Wrong - this is valid, common pointer code."};
        correct_answer(Q1, Q1_option, 2, 10, 9, 4, Q1_explanation); // line 753
    }
    else
    {
        printf("int x = 3;\n");
        printf("int *p = &x;\n");
        printf("*p = *p + *p;\n");
        char Q1[] = "What is x after this code?";
        char Q1_option[4][60] = {"3", "6", "Address of x", "Error"};
        char Q1_explanation[4][150] = {
            "Wrong - *p reads x (3) twice, adds them, then writes the result back into x.",
            "Correct - *p = *p + *p means \"add what p points to, to itself, store it back.\" Since p points to x, x becomes 6.",
            "Wrong - *p is a value, not an address.",
            "Wrong - this is valid, common pointer code."};
        correct_answer(Q1, Q1_option, 2, 10, 9, 4, Q1_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //__________________________________________Question 2 - conditional pointer____________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("int a = 4, b = 9;\n");
        printf("int *p;\n");
        printf("if (a > b)\n");
        printf("    p = &a;\n");
        printf("else\n");
        printf("    p = &b;\n");
        printf("*p = *p * 2;\n");
        char Q2[] = "What is b after this code?";
        char Q2_option[4][60] = {"9", "18", "4", "8"};
        char Q2_explanation[4][150] = {
            "Wrong - b gets doubled by the last line, it does not stay the same.",
            "Correct - a > b is false (4 is not greater than 9), so the else runs: p = &b. Then *p = *p * 2 doubles b: 9 -> 18.",
            "Wrong - 4 is the value of a, not b, and a is untouched here.",
            "Wrong - 8 would be 4 doubled, but the pointer never points to a in this run."};
        correct_answer(Q2, Q2_option, 2, 15, 11, 5, Q2_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("int a = 15, b = 6;\n");
        printf("int *p;\n");
        printf("if (a > b)\n");
        printf("    p = &a;\n");
        printf("else\n");
        printf("    p = &b;\n");
        printf("*p = *p + 5;\n");
        char Q2[] = "What is a after this code?";
        char Q2_option[4][60] = {"15", "20", "6", "11"};
        char Q2_explanation[4][150] = {
            "Wrong - a gets increased by the last line, it does not stay the same.",
            "Correct - a > b is true (15 is greater than 6), so the if runs: p = &a. Then *p = *p + 5 adds 5 to a: 15 -> 20.",
            "Wrong - 6 is the value of b, not a, and b is untouched here.",
            "Wrong - 11 would be 6 plus 5, but the pointer never points to b in this run."};
        correct_answer(Q2, Q2_option, 2, 15, 11, 5, Q2_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("int a = 2, b = 2;\n");
        printf("int *p;\n");
        printf("if (a >= b)\n");
        printf("    p = &a;\n");
        printf("else\n");
        printf("    p = &b;\n");
        printf("*p = *p * 3;\n");
        char Q2[] = "What is a after this code?";
        char Q2_option[4][60] = {"2", "6", "0", "4"};
        char Q2_explanation[4][150] = {
            "Wrong - a gets tripled by the last line, it does not stay the same.",
            "Correct - a >= b is true (2 is equal to 2), so the if runs: p = &a. Then *p = *p * 3 triples a: 2 -> 6.",
            "Wrong - nothing in this code sets a variable to 0.",
            "Wrong - 4 is not the result of tripling 2."};
        correct_answer(Q2, Q2_option, 2, 15, 11, 5, Q2_explanation); // line 753
    }
    else
    {
        printf("int a = 8, b = 1;\n");
        printf("int *p;\n");
        printf("if (a < b)\n");
        printf("    p = &a;\n");
        printf("else\n");
        printf("    p = &b;\n");
        printf("*p = *p - 1;\n");
        char Q2[] = "What is b after this code?";
        char Q2_option[4][60] = {"1", "0", "8", "7"};
        char Q2_explanation[4][150] = {
            "Wrong - b gets decreased by the last line, it does not stay the same.",
            "Correct - a < b is false (8 is not less than 1), so the else runs: p = &b. Then *p = *p - 1 subtracts 1 from b: 1 -> 0.",
            "Wrong - 8 is the value of a, not b, and a is untouched here.",
            "Wrong - 7 would be 8 minus 1, but the pointer never points to a in this run."};
        correct_answer(Q2, Q2_option, 2, 15, 11, 5, Q2_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //____________________________________________Question 3 - pointer traversal sum________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("int arr[4] = {1, 2, 3, 4};\n");
        printf("int *p = arr;\n");
        printf("int sum = 0;\n");
        printf("for (int i = 0; i < 4; i++)\n");
        printf("{\n");
        printf("    sum += *p;\n");
        printf("    p++;\n");
        printf("}\n");
        char Q3[] = "What is sum after this loop?";
        char Q3_option[4][60] = {"4", "0", "15", "10"};
        char Q3_explanation[4][150] = {
            "Wrong - 4 is only the last element, not the total.",
            "Wrong - sum starts at 0 but changes inside the loop; it does not stay 0.",
            "Wrong - 15 is not the sum of these four numbers.",
            "Correct - p starts at arr[0] and moves forward each loop (p++). It adds 1+2+3+4 = 10."};
        correct_answer(Q3, Q3_option, 4, 15, 12, 6, Q3_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("int arr[3] = {5, 10, 15};\n");
        printf("int *p = arr;\n");
        printf("int sum = 0;\n");
        printf("for (int i = 0; i < 3; i++)\n");
        printf("{\n");
        printf("    sum += *p;\n");
        printf("    p++;\n");
        printf("}\n");
        char Q3[] = "What is sum after this loop?";
        char Q3_option[4][60] = {"5", "15", "0", "30"};
        char Q3_explanation[4][150] = {
            "Wrong - 5 is only the first element, not the total.",
            "Wrong - 15 is only the last element, not the total.",
            "Wrong - sum starts at 0 but changes inside the loop; it does not stay 0.",
            "Correct - p starts at arr[0] and moves forward each loop (p++). It adds 5+10+15 = 30."};
        correct_answer(Q3, Q3_option, 4, 15, 12, 6, Q3_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("int arr[5] = {1, 1, 1, 1, 1};\n");
        printf("int *p = arr;\n");
        printf("int sum = 0;\n");
        printf("for (int i = 0; i < 5; i++)\n");
        printf("{\n");
        printf("    sum += *p;\n");
        printf("    p++;\n");
        printf("}\n");
        char Q3[] = "What is sum after this loop?";
        char Q3_option[4][60] = {"1", "0", "10", "5"};
        char Q3_explanation[4][150] = {
            "Wrong - 1 is only a single element, not the total.",
            "Wrong - sum starts at 0 but changes inside the loop; it does not stay 0.",
            "Wrong - 10 is not the sum of these five 1's.",
            "Correct - p starts at arr[0] and moves forward each loop (p++). It adds 1+1+1+1+1 = 5."};
        correct_answer(Q3, Q3_option, 4, 15, 12, 6, Q3_explanation); // line 753
    }
    else
    {
        printf("int arr[4] = {2, 2, 2, 2};\n");
        printf("int *p = arr;\n");
        printf("int sum = 0;\n");
        printf("for (int i = 0; i < 4; i++)\n");
        printf("{\n");
        printf("    sum += *p;\n");
        printf("    p++;\n");
        printf("}\n");
        char Q3[] = "What is sum after this loop?";
        char Q3_option[4][60] = {"2", "0", "4", "8"};
        char Q3_explanation[4][150] = {
            "Wrong - 2 is only a single element, not the total.",
            "Wrong - sum starts at 0 but changes inside the loop; it does not stay 0.",
            "Wrong - 4 is only two of the elements, not all of them.",
            "Correct - p starts at arr[0] and moves forward each loop (p++). It adds 2+2+2+2 = 8."};
        correct_answer(Q3, Q3_option, 4, 15, 12, 6, Q3_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    //__________________________________Question 4 - conditional counting via pointer___________________________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
        char Q4_option[4][60] = {"5", "3", "2", "0"};
        char Q4_explanation[4][150] = {
            "Wrong - not every number in the array divides evenly by 4.",
            "Wrong - 6 and 10 do not divide evenly by 4, so they don't count.",
            "Correct - the loop walks through the array using the pointer. Only 4 and 8 divide evenly by 4 (remainder 0), so count becomes 2.",
            "Wrong - some numbers do divide by 4 (4 and 8), so count is not 0."};
        correct_answer(Q4, Q4_option, 3, 15, 14, 7, Q4_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("int arr[5] = {3, 6, 9, 12, 15};\n");
        printf("int *p = arr;\n");
        printf("int count = 0;\n");
        printf("for (int i = 0; i < 5; i++)\n");
        printf("{\n");
        printf("    if (*p %% 3 == 0)\n");
        printf("    {\n");
        printf("        count++;\n");
        printf("    }\n");
        printf("    p++;\n");
        printf("}\n");
        char Q4[] = "What is \"count\" after this code?";
        char Q4_option[4][60] = {"0", "2", "5", "3"};
        char Q4_explanation[4][150] = {
            "Wrong - every number here does divide evenly by 3, so count is not 0.",
            "Wrong - more than 2 of these numbers divide evenly by 3.",
            "Correct - the loop walks through the array using the pointer. Every number (3,6,9,12,15) divides evenly by 3, so count becomes 5.",
            "Wrong - 3 is too low; all five elements qualify here."};
        correct_answer(Q4, Q4_option, 3, 15, 14, 7, Q4_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("int arr[5] = {1, 2, 3, 4, 5};\n");
        printf("int *p = arr;\n");
        printf("int count = 0;\n");
        printf("for (int i = 0; i < 5; i++)\n");
        printf("{\n");
        printf("    if (*p %% 2 == 0)\n");
        printf("    {\n");
        printf("        count++;\n");
        printf("    }\n");
        printf("    p++;\n");
        printf("}\n");
        char Q4[] = "What is \"count\" after this code?";
        char Q4_option[4][60] = {"0", "3", "2", "5"};
        char Q4_explanation[4][150] = {
            "Wrong - some numbers do divide evenly by 2, so count is not 0.",
            "Wrong - only 2 of these numbers divide evenly by 2, not 3.",
            "Correct - the loop walks through the array using the pointer. Only 2 and 4 divide evenly by 2 (remainder 0), so count becomes 2.",
            "Wrong - not every number here is even, so count isn't 5."};
        correct_answer(Q4, Q4_option, 3, 15, 14, 7, Q4_explanation); // line 753
    }
    else
    {
        printf("int arr[6] = {10, 15, 20, 25, 30, 35};\n");
        printf("int *p = arr;\n");
        printf("int count = 0;\n");
        printf("for (int i = 0; i < 6; i++)\n");
        printf("{\n");
        printf("    if (*p %% 10 == 0)\n");
        printf("    {\n");
        printf("        count++;\n");
        printf("    }\n");
        printf("    p++;\n");
        printf("}\n");
        char Q4[] = "What is \"count\" after this code?";
        char Q4_option[4][60] = {"6", "0", "3", "5"};
        char Q4_explanation[4][150] = {
            "Wrong - not every number in the array divides evenly by 10.",
            "Wrong - some numbers do divide by 10, so count is not 0.",
            "Correct - the loop walks through the array using the pointer. Only 10, 20 and 30 divide evenly by 10 (remainder 0), so count becomes 3.",
            "Wrong - only 3 of these numbers qualify, not 5."};
        correct_answer(Q4, Q4_option, 3, 15, 14, 7, Q4_explanation); // line 753
    }
    if (HP <= 0)
        return HP;

    return HP;
}

//_______________________________________precoursion EQuest______________________________
void Precaution_EQuest()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

    printf("-----------------------------------------------------------------\n");
    printf("    Traveler : Hello sir, I am locked outside of my house.\n");
    printf("and the password for my door is the output of this particular code\n");
    printf("    but I am unable to find the output. Can you help me?\n");
    printf("-------------------------------------------------------------------\n");

    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
        char QE_option[4][60] = {"150", "Undefined behavior", "100", "Compilation error"};
        char QE_explanation[4][150] = {
            "Wrong - 150 would be the sum only if ptr never moved on its own.",
            "Correct! ptr advances with ptr++ AND i is added on top of it each pass, so *(ptr+i) drifts past the array and reads out-of-bounds memory.",
            "Wrong - 100 isn't the sum of these five numbers even under normal conditions.",
            "Wrong - this compiles fine; the problem only shows up at runtime."};
        correct_answer(QE, QE_option, 2, 0, 18, 1, QE_explanation); // line 753
        printf("\n%s : Sir, your code is corrupted. It reads out of bounds - \"ptr++\" is causing the problem.\n", Name);
        printf("Remove it and the code should output 150.\n");
    }
    else if (Time == 2)
    {
        printf("#include <stdio.h>\n");
        printf("int main() {\n");
        printf("int arr[] = {1, 2, 3, 4};\n");
        printf("int *ptr = arr;\n");
        printf(" int sum = 0;\n");
        printf(" for (int i = 0; i < 6; i++) {\n");
        printf(" sum += *(ptr + i);\n");
        printf(" }\n");
        printf("  printf(\"%%d\", sum);\n");
        printf(" return 0;\n");
        printf("}\n");

        char QE[] = "Find the output?";
        char QE_option[4][60] = {"10", "Undefined behavior", "6", "Compilation error"};
        char QE_explanation[4][150] = {
            "Wrong - 10 would only be the sum if the loop stopped after 4 elements.",
            "Correct! The loop runs 6 times but the array only has 4 elements, so *(ptr+i) reads past the array into out-of-bounds memory.",
            "Wrong - 6 is just the loop count, not a guaranteed sum.",
            "Wrong - this compiles fine; the problem only shows up at runtime."};
        correct_answer(QE, QE_option, 2, 0, 18, 1, QE_explanation); // line 753
        printf("\n%s : Sir, your code is corrupted. The loop runs 6 times but the array only has 4 elements.\n", Name);
        printf("Fix the loop to stop at 4 and the code should output 10.\n");
    }
    else if (Time == 3)
    {
        printf("#include <stdio.h>\n");
        printf("int main() {\n");
        printf("int arr[] = {5, 10, 15};\n");
        printf("int *ptr = arr + 5;\n");
        printf("  printf(\"%%d\", *ptr);\n");
        printf(" return 0;\n");
        printf("}\n");

        char QE[] = "Find the output?";
        char QE_option[4][60] = {"15", "Undefined behavior", "0", "Compilation error"};
        char QE_explanation[4][150] = {
            "Wrong - 15 is only the last valid element; ptr never actually points there.",
            "Correct! ptr = arr + 5 already points 5 steps past a 3-element array, and dereferencing it reads out-of-bounds memory.",
            "Wrong - memory isn't automatically zeroed just because it's out of bounds.",
            "Wrong - this compiles fine; the problem only shows up at runtime."};
        correct_answer(QE, QE_option, 2, 0, 18, 1, QE_explanation); // line 753
        printf("\n%s : Sir, your code is corrupted. \"arr + 5\" already points far past your 3-element array.\n", Name);
        printf("Fix the offset and the pointer will land back inside the array.\n");
    }
    else
    {
        printf("#include <stdio.h>\n");
        printf("int main() {\n");
        printf("int arr[] = {2, 4, 6, 8};\n");
        printf("int *ptr = arr;\n");
        printf(" for (int i = 0; i <= 4; i++) {\n");
        printf(" ptr++;}\n");
        printf("  printf(\"%%d\", *ptr);\n");
        printf(" return 0;\n");
        printf("}\n");

        char QE[] = "Find the output?";
        char QE_option[4][60] = {"8", "Undefined behavior", "0", "Compilation error"};
        char QE_explanation[4][150] = {
            "Wrong - 8 is only the last valid element; ptr walks one step further than that.",
            "Correct! i <= 4 runs the loop one extra time, walking ptr one step past the end of the array before it's dereferenced.",
            "Wrong - memory isn't automatically zeroed just because it's out of bounds.",
            "Wrong - this compiles fine; the problem only shows up at runtime."};
        correct_answer(QE, QE_option, 2, 0, 18, 1, QE_explanation); // line 753
        printf("\n%s : Sir, your code is corrupted. The loop condition \"i <= 4\" walks ptr one step too far.\n", Name);
        printf("Fix the condition and the pointer will land back inside the array.\n");
    }

    printf("---------------------------------------------------------\n");
    printf("Traveler : Thank you, here's a little something for your trouble.\n");
    printf("---------------------------------------------------------\n");
    current_status(); // line 684
    file_save();      // line 268
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
    while (1)
    {
        choice = answer_input_loop(); // line 716
        if (choice == 1)
        {
            if (Coin >= 80)
            {
                printf("You have bought the Iron Shield.\n");
                printf("Your next wrong answer's HP penalty will be halved.\n");
                Coin = Coin - 80;
                Iron_shield = 1;
                break;
            }
            else
            {
                printf("Insufficient coins.\nYou have %d coins. Choose again: ", Coin);
            }
        }
        else if (choice == 2)
        {
            printf("OK, no purchase made.\n");
            break;
        }
        else
        {
            printf("That item isn't on the shelf. Pick 1 or 2: ");
        }
    }
}
//__________________________________________________final stage_________________________________________
int final_stage()
{
    int Time, upper_limit = 4, lower_limit = 1;
    srand(time(NULL));

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

    //____________________________________question 1 - strcat buffer_______________________________________
    enter_to_continue(); // line 5979
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("char city[10] = \"Code\";\n");
        printf("strcat(city, \"Quest\");\n");
        printf("printf(\"%%s\", city);\n");
        char Q1[] = "What does this code print?";
        char Q1_option[4][60] = {"CodeQuest", "Code Quest", "A crash from buffer overflow", "Quest"};
        char Q1_explanation[4][150] = {
            "Correct - strcat appends \"Quest\" right after \"Code\", and city[10] has exactly enough room: 4+5 = 9 characters + \\0 = 10.",
            "Wrong - strcat doesn't add a space, it joins the strings directly, back to back.",
            "Wrong - tempting, but count the space: city[10] holds 9 characters + \\0, and \"CodeQuest\" is exactly 9, it fits perfectly.",
            "Wrong - strcat doesn't overwrite, it appends onto the end of the existing string."};
        correct_answer(Q1, Q1_option, 1, 20, 8, 3, Q1_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("char word[8] = \"Go\";\n");
        printf("strcat(word, \"Fast\");\n");
        printf("printf(\"%%s\", word);\n");
        char Q1[] = "What does this code print?";
        char Q1_option[4][60] = {"GoFast", "Go Fast", "A crash from buffer overflow", "Fast"};
        char Q1_explanation[4][150] = {
            "Correct - strcat appends \"Fast\" right after \"Go\", and word[8] has exactly enough room: 2+4 = 6 characters + \\0 = 7, which fits in 8.",
            "Wrong - strcat doesn't add a space, it joins the strings directly, back to back.",
            "Wrong - there's enough room here: word[8] holds up to 7 characters + \\0, and \"GoFast\" is only 6.",
            "Wrong - strcat doesn't overwrite, it appends onto the end of the existing string."};
        correct_answer(Q1, Q1_option, 1, 20, 8, 3, Q1_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("char text[6] = \"Hi\";\n");
        printf("strcat(text, \"Bug\");\n");
        printf("printf(\"%%s\", text);\n");
        char Q1[] = "What does this code print?";
        char Q1_option[4][60] = {"HiBug", "Hi Bug", "A crash from buffer overflow", "Bug"};
        char Q1_explanation[4][150] = {
            "Correct - strcat appends \"Bug\" right after \"Hi\", and text[6] has exactly enough room: 2+3 = 5 characters + \\0 = 6.",
            "Wrong - strcat doesn't add a space, it joins the strings directly, back to back.",
            "Wrong - tempting, but count the space: text[6] holds 5 characters + \\0, and \"HiBug\" is exactly 5, it fits perfectly.",
            "Wrong - strcat doesn't overwrite, it appends onto the end of the existing string."};
        correct_answer(Q1, Q1_option, 1, 20, 8, 3, Q1_explanation); // line 753
    }
    else
    {
        printf("char msg[7] = \"C\";\n");
        printf("strcat(msg, \"Lang\");\n");
        printf("printf(\"%%s\", msg);\n");
        char Q1[] = "What does this code print?";
        char Q1_option[4][60] = {"CLang", "C Lang", "A crash from buffer overflow", "Lang"};
        char Q1_explanation[4][150] = {
            "Correct - strcat appends \"Lang\" right after \"C\", and msg[7] has exactly enough room: 1+4 = 5 characters + \\0 = 6, which fits in 7.",
            "Wrong - strcat doesn't add a space, it joins the strings directly, back to back.",
            "Wrong - there's enough room here: msg[7] holds up to 6 characters + \\0, and \"CLang\" is only 5.",
            "Wrong - strcat doesn't overwrite, it appends onto the end of the existing string."};
        correct_answer(Q1, Q1_option, 1, 20, 8, 3, Q1_explanation); // line 753
    }
    if (HP <= 0)
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

    //________________question2 - what does the counter count________________________
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
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
        char Q2[] = "What will be the output?";
        char Q2_option[4][60] = {"Total number of words", "Total number of characters", "Total number of empty spaces", "Garbage value"};
        char Q2_explanation[4][150] = {
            "Wrong - the function never groups letters into words, it only reacts to space characters.",
            "Wrong - count only increases on spaces, not on every character in the string.",
            "Correct - count only increments when s1[i] hits a space character, so it totals the number of spaces.",
            "Wrong - s1 is properly read and count starts at 0, so there's no garbage here."};
        correct_answer(Q2, Q2_option, 3, 20, 5, 3, Q2_explanation); // line 753
    }
    else if (Time == 2)
    {
        printf("\n\n#include<stdio.h>\n");
        printf("#include<string.h>\n\n");
        printf("int Count(char s1[]){\n");
        printf("    int count=0,i;\n");
        printf("    for (i = 0; s1[i] != '\\0'; i++){\n");
        printf("        if (s1[i] >= '0' && s1[i] <= '9')\n");
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
        char Q2[] = "What will be the output?";
        char Q2_option[4][60] = {"Total number of words", "Total number of alphabetic characters", "Total number of digit characters", "Garbage value"};
        char Q2_explanation[4][150] = {
            "Wrong - the function never groups letters into words, it only reacts to digit characters.",
            "Wrong - the check tests for digits '0'-'9', not letters.",
            "Correct - count only increments when s1[i] falls between '0' and '9', so it totals the digit characters.",
            "Wrong - s1 is properly read and count starts at 0, so there's no garbage here."};
        correct_answer(Q2, Q2_option, 3, 20, 5, 3, Q2_explanation); // line 753
    }
    else if (Time == 3)
    {
        printf("\n\n#include<stdio.h>\n");
        printf("#include<string.h>\n\n");
        printf("int Count(char s1[]){\n");
        printf("    int count=0,i;\n");
        printf("    for (i = 0; s1[i] != '\\0'; i++){\n");
        printf("        if (s1[i] >= 'A' && s1[i] <= 'Z')\n");
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
        char Q2[] = "What will be the output?";
        char Q2_option[4][60] = {"Total number of words", "Total number of lowercase letters", "Total number of uppercase letters", "Garbage value"};
        char Q2_explanation[4][150] = {
            "Wrong - the function never groups letters into words, it only reacts to uppercase characters.",
            "Wrong - the check tests for 'A'-'Z', which is uppercase, not lowercase.",
            "Correct - count only increments when s1[i] falls between 'A' and 'Z', so it totals the uppercase letters.",
            "Wrong - s1 is properly read and count starts at 0, so there's no garbage here."};
        correct_answer(Q2, Q2_option, 3, 20, 5, 3, Q2_explanation); // line 753
    }
    else
    {
        printf("\n\n#include<stdio.h>\n");
        printf("#include<string.h>\n\n");
        printf("int Count(char s1[]){\n");
        printf("    int count=0,i;\n");
        printf("    for (i = 0; s1[i] != '\\0'; i++){\n");
        printf("        if (s1[i] == ',')\n");
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
        char Q2[] = "What will be the output?";
        char Q2_option[4][60] = {"Total number of words", "Total number of periods", "Total number of commas", "Garbage value"};
        char Q2_explanation[4][150] = {
            "Wrong - the function never groups letters into words, it only reacts to comma characters.",
            "Wrong - the check tests for ',', not '.'.",
            "Correct - count only increments when s1[i] hits a comma character, so it totals the commas.",
            "Wrong - s1 is properly read and count starts at 0, so there's no garbage here."};
        correct_answer(Q2, Q2_option, 3, 20, 5, 3, Q2_explanation); // line 753
    }
    if (HP <= 0)
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
    int Time, upper_limit = 4, lower_limit = 1;
    int correct_result;
    srand(time(NULL));

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
    enter_to_continue(); // line 5979

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

    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        printf("    char *words[] = {\"Code\", \"Quest\", \"NULL\", \"Bug\", \"Pointer\", \"NULL\"};\n");
        printf("    int result = mystery(words, 6);\n");
        printf("    printf(\"%%d\\n\", result);\n");
        printf("    return 0;\n");
        printf("}\n\n");
        correct_result = 20;
    }
    else if (Time == 2)
    {
        printf("    char *words[] = {\"Stack\", \"Heap\", \"NULL\", \"Bug\", \"Kernel\", \"Cache\"};\n");
        printf("    int result = mystery(words, 6);\n");
        printf("    printf(\"%%d\\n\", result);\n");
        printf("    return 0;\n");
        printf("}\n\n");
        correct_result = 10;
    }
    else if (Time == 3)
    {
        printf("    char *words[] = {\"NULL\", \"Byte\", \"NULL\", \"Wire\", \"NULL\", \"Port\"};\n");
        printf("    int result = mystery(words, 6);\n");
        printf("    printf(\"%%d\\n\", result);\n");
        printf("    return 0;\n");
        printf("}\n\n");
        correct_result = 30;
    }
    else
    {
        printf("    char *words[] = {\"Ptr\", \"Segment\", \"NULL\", \"Free\", \"Alloc\", \"NULL\"};\n");
        printf("    int result = mystery(words, 6);\n");
        printf("    printf(\"%%d\\n\", result);\n");
        printf("    return 0;\n");
        printf("}\n\n");
        correct_result = 20;
    }

    printf("===========================================================================\n");
    printf("                  What integer does this program print?\n");
    printf("                             you have 3 chance\n");
    printf("===========================================================================\n");

    int chance = 1, answer;
    int solved = 0;

    while (chance <= 3)
    {
        printf("Answer :");
        if (scanf("%d", &answer) != 1)
        {
            printf("Invalid input. Please enter an integer.\n");
            flush_input(); // line 5972
            continue;
        }
        flush_input(); // line 5972
        if (answer == correct_result)
        {
            clear_screen();    // line 212
            Congratulations(); // line 3029
            file_reset();      // line 249
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
            current_status(); // line 684
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

    if (section > 1)
    {
        printf("[1] Previous Section\n");
    }

    printf("Press ENTER to continue...\n");

    input = getchar();

    if (input == '\n')
    {
        if (section < total_sections)
        {
            return 'N';
        }
        else
        {
            return 'E';
        }
    }
    if (input == '1' && section > 1)
    {
        flush_input(); // line 5972
        return 'P';
    }

    flush_input(); // line 5972
    printf("Invalid input.\n");
    return 'I';
}

int menu_input(int min, int max)
{
    int choice;

    while (1)
    {
        if (scanf("%d", &choice) == 1)
        {
            flush_input(); // line 5972

            if (choice >= min && choice <= max)
            {
                return choice; // valid choice entered, exit the input loop
            }
        }
        else
        {
            flush_input(); // line 5972
        }

        printf("Invalid input.\n");
        printf("Enter your choice again: ");
    }
}
void training_answer(char question[], char option[4][60], int correctAns, char explanation[4][150])
{
    int i;
    int answer;

    printf("\n%s\n", question);

    for (i = 0; i < 4; i++)
    {
        printf("%d. %s\n", i + 1, option[i]);
    }

    printf("Enter Answer: ");
    answer = answer_input_loop(); // line 716

    if (answer == correctAns)
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

        return;
    }
}
void training()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212
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
        choice = menu_input(0, 7); // line 3121

        switch (choice)
        {
        case 1:
            VariableDatatypeTraining(); // line 3244
            break;

        case 2:
            ConditionTraining(); // line 3601
            break;

        case 3:
            LoopTraining(); // line 4025
            break;

        case 4:
            ArrayTraining(); // line 4465
            break;

        case 5:
            FunctionTraining(); // line 4831
            break;

        case 6:
            PointerTraining(); // line 5252
            break;

        case 7:
            StringTraining(); // line 5615
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
        clear_screen(); // line 212

        printf("\n============================================================\n");
        printf("             VARIABLE & DATATYPE CHAMBER\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (V_D_QuizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            V_D_lesson(); // line 3290
            V_D_QuizUnlocked = 1;
        }
        else if (choice == 2)
        {
            if (V_D_QuizUnlocked == 1)
                V_D_quiz(); // line 3387
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void V_D_lesson()
{
    int section = 1;
    int total_sections = 4;
    char navigation;

    while (section >= 1 && section <= total_sections)
    {
        clear_screen(); // line 212

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
        navigation = lesson_navigation(section, total_sections); // line 3085

        if (navigation == 'N')
            section++;

        else if (navigation == 'P')
            section--;

        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void V_D_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212
    printf("============================================================\n");
    printf("          VARIABLE & DATATYPE KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");
    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
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
                "Garbage value"};

        char Q1_explanation[4][150] =
            {
                "age is changed to 25 before printf.",
                "age is changed from 20 to 25.",
                "age has a valid assigned value.",
                "age was initialized before printing."};

        training_answer(Q1, Q1_option, 2, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "Which datatype is normally used to store a single character?";

        char Q2_option[4][60] =
            {
                "int",
                "float",
                "char",
                "double"};

        char Q2_explanation[4][150] =
            {
                "int stores whole numbers.",
                "float stores decimal numbers.",
                "char stores a single character.",
                "double stores decimal values."};

        training_answer(Q2, Q2_option, 3, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "Which of the following is a valid variable name?";

        char Q3_option[4][60] =
            {
                "2ndVariable",
                "my variable",
                "_myVariable",
                "int"};

        char Q3_explanation[4][150] =
            {
                "Variable names cannot start with a digit.",
                "Variable names cannot contain spaces.",
                "Correct - variable names can start with an underscore.",
                "int is a reserved keyword in C."};

        training_answer(Q3, Q3_option, 3, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "What is the correct format specifier for printing a float value?";

        char Q4_option[4][60] =
            {
                "%d",
                "%f",
                "%c",
                "%s"};

        char Q4_explanation[4][150] =
            {
                "%d is for int values.",
                "Correct - %f is used to print float values.",
                "%c is for single characters.",
                "%s is for strings."};

        training_answer(Q4, Q4_option, 2, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "What will be the output?\n\n"
            "float pi = 3.14;\n"
            "printf(\"%f\", pi);";

        char Q5_option[4][60] =
            {
                "3.140000",
                "3.14",
                "0",
                "Garbage value"};

        char Q5_explanation[4][150] =
            {
                "Correct - pi is a float and will print as 3.140000.",
                "Incorrect - %f prints the full float value.",
                "Incorrect - pi has a valid assigned value.",
                "Incorrect - pi was initialized before printing."};

        training_answer(Q5, Q5_option, 1, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "Which datatype is used to store decimal numbers with double precision?";

        char Q6_option[4][60] =
            {
                "int",
                "float",
                "char",
                "double"};

        char Q6_explanation[4][150] =
            {
                "int stores whole numbers.",
                "float stores decimal numbers but with single precision.",
                "char stores a single character.",
                "Correct - double stores decimal values with double precision."};

        training_answer(Q6, Q6_option, 4, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "Which of the following is NOT a valid variable name?";

        char Q7_option[4][60] =
            {
                "myVariable",
                "_myVariable",
                "2ndVariable",
                "variable_name"};

        char Q7_explanation[4][150] =
            {
                "Correct - this is a valid variable name.",
                "Correct - this is a valid variable name.",
                "Incorrect - variable names cannot start with a digit.",
                "Correct - this is a valid variable name."};

        training_answer(Q7, Q7_option, 3, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "What is the correct format specifier for printing a character value?";

        char Q8_option[4][60] =
            {
                "%d",
                "%f",
                "%c",
                "%s"};

        char Q8_explanation[4][150] =
            {
                "%d is for int values.",
                "%f is for float values.",
                "Correct - %c is used to print single character values.",
                "%s is for strings."};

        training_answer(Q8, Q8_option, 3, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

int Condition_quizUnlocked = 0;

void ConditionTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212

        printf("\n============================================================\n");
        printf("                    CONDITION CITADEL\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Condition_quizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            Condition_lesson(); // line 3648
            Condition_quizUnlocked = 1;
        }

        else if (choice == 2)
        {
            if (Condition_quizUnlocked == 1)
                Condition_quiz(); // line 3794
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void Condition_lesson()
{
    int section = 1;
    int total_sections = 8;
    char navigation;
    while (section >= 1 && section <= total_sections)
    {
        clear_screen(); // line 212

        if (section == 1)
        {
            printf("============================================================\n");
            printf("                 CONDITION CITADEL\n");
            printf("============================================================\n\n");
            printf("Welcome, Warrior! You have entered the Condition Citadel.\n");
            printf("Here, your decisions will determine the path of your program.\n\n");
        }
        else if (section == 2)
        {
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
        else if (section == 3)
        {
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
        else if (section == 4)
        {
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
        else if (section == 5)
        {
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
        else if (section == 6)
        {
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

        else if (section == 7)
        {
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
        else if (section == 8)
        {
            printf("------------------------------------------------------------\n");
            printf("                    WARRIOR TIP\n");
            printf("------------------------------------------------------------\n");
            printf("Conditions are the decision-making system of C.\n");
            printf("Master them, and your programs can choose what to do!\n\n");
        }

        // ========================= NAVIGATION =========================
        printf("\n------------------------------------------------------------\n");

        navigation = lesson_navigation(section, total_sections); // line 3085
        if (navigation == 'N')
        {
            section++;
        }
        else if (navigation == 'P')
        {
            section--;
        }
        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void Condition_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212
    printf("============================================================\n");
    printf("          CONDITIONAL STATEMENTS QUIZ\n");
    printf("============================================================\n\n");
    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q1[] =
            "What will be the output?\n\n"
            "int x = 10;\n"
            "if(x > 5)\n"
            "    printf(\"Yes\");\n"
            "else\n"
            "    printf(\"No\");";

        char Q1_option[4][60] =
            {
                "Yes",
                "No",
                "10",
                "Error"};

        char Q1_explanation[4][150] =
            {
                "Correct - 10 is greater than 5, so the if block executes.",
                "The else block executes only when the condition is false.",
                "10 is the value of x, not the output.",
                "The code is valid C code."};
        training_answer(Q1, Q1_option, 1, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "What will be the output?\n\n"
            "int age = 15;\n"
            "if(age >= 18)\n"
            "    printf(\"Adult\");\n"
            "else\n"
            "    printf(\"Minor\");";

        char Q2_option[4][60] =
            {
                "Adult",
                "Minor",
                "15",
                "Error"};

        char Q2_explanation[4][150] =
            {
                "The condition age >= 18 is false because age is 15.",
                "Correct - 15 is less than 18, so the else block executes.",
                "15 is the value of age, not the output.",
                "The code is valid C code."};

        training_answer(Q2, Q2_option, 2, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "What will be the output?\n\n"
            "int n = 20;\n"
            "if(n == 20)\n"
            "    printf(\"Match\");\n"
            "else\n"
            "    printf(\"No Match\");";

        char Q3_option[4][60] =
            {
                "20",
                "No Match",
                "Match",
                "Error"};

        char Q3_explanation[4][150] =
            {
                "20 is the value of n, not the printed output.",
                "The condition is true, so the else block does not execute.",
                "Correct - n is equal to 20, so Match is printed.",
                "The code is valid C code."};

        training_answer(Q3, Q3_option, 3, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "What will be the output?\n\n"
            "int marks = 40;\n"
            "if(marks >= 50)\n"
            "    printf(\"Pass\");\n"
            "else\n"
            "    printf(\"Fail\");";

        char Q4_option[4][60] =
            {
                "Pass",
                "40",
                "Fail",
                "Error"};

        char Q4_explanation[4][150] =
            {
                "The condition marks >= 50 is false.",
                "40 is the value of marks, not the output.",
                "Correct - 40 is less than 50, so Fail is printed.",
                "The code is valid C code."};

        training_answer(Q4, Q4_option, 3, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "Which operator is used to check whether two values are equal in C?";

        char Q5_option[4][60] =
            {
                "=",
                "==",
                "!=",
                ">="};

        char Q5_explanation[4][150] =
            {
                "= is the assignment operator.",
                "Correct - == is the equality comparison operator.",
                "!= checks whether two values are not equal.",
                ">= checks whether one value is greater than or equal to another."};

        training_answer(Q5, Q5_option, 2, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "Which condition correctly checks whether x is between 10 and 20, including both limits?";

        char Q6_option[4][60] =
            {
                "x > 10 && x < 20",
                "x >= 10 && x <= 20",
                "x >= 10 || x <= 20",
                "x == 10 && x == 20"};

        char Q6_explanation[4][150] =
            {
                "This excludes 10 and 20.",
                "Correct - both boundaries are included using >= and <=.",
                "Using || would allow values outside the range.",
                "A value cannot normally be both 10 and 20 at the same time."};

        training_answer(Q6, Q6_option, 2, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "What does the expression !(x > 10) mean?";

        char Q7_option[4][60] =
            {
                "x is greater than 10",
                "x is less than or equal to 10",
                "x is exactly 10",
                "x is not equal to 10"};

        char Q7_explanation[4][150] =
            {
                "That is the original condition, before applying !.",
                "Correct - ! reverses x > 10, giving x <= 10.",
                "The expression also allows values below 10.",
                "Not equal to 10 also includes values greater than 10."};
        training_answer(Q7, Q7_option, 2, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "What will be the output?\n\n"
            "int n = 12;\n"
            "if(n % 2 == 0 || n > 20)\n"
            "    printf(\"True\");\n"
            "else\n"
            "    printf(\"False\");";

        char Q8_option[4][60] =
            {
                "True",
                "False",
                "12",
                "Error"};

        char Q8_explanation[4][150] =
            {
                "Correct - 12 % 2 is 0, so the first condition is true.",
                "The second condition does not need to be true because || requires only one true condition.",
                "12 is the value of n, not the output.",
                "The expression is valid C syntax."};

        training_answer(Q8, Q8_option, 1, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

int Loop_quizUnlocked = 0;
void LoopTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212

        printf("\n============================================================\n");
        printf("                    LOOP LABYRINTH\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Loop_quizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            Loop_lesson(); // line 4072
            Loop_quizUnlocked = 1;
        }

        else if (choice == 2)
        {
            if (Loop_quizUnlocked == 1)
                Loop_quiz(); // line 4235
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void Loop_lesson()
{
    int section = 1;
    int total_sections = 7;
    char navigation;

    while (section >= 1 && section <= total_sections)
    {
        clear_screen(); // line 212
        if (section == 1)
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
        else if (section == 2)
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

        else if (section == 3)
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
        else if (section == 4)
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
        else if (section == 5)
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
        else if (section == 6)
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
        else if (section == 7)
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

        navigation = lesson_navigation(section, total_sections); // line 3085
        if (navigation == 'N')
        {
            section++;
        }
        else if (navigation == 'P')
        {
            section--;
        }
        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void Loop_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212

    printf("============================================================\n");
    printf("                    LOOP KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");
    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q1[] =
            "What will be the output?\n\n"
            "for(int i = 1; i <= 4; i++)\n"
            "    printf(\"%d \", i);";

        char Q1_option[4][60] =
            {
                "0 1 2 3",
                "1 2 3 4",
                "1 2 3",
                "4 3 2 1"};

        char Q1_explanation[4][150] =
            {
                "The loop starts from 1, so 0 is not printed.",
                "Correct - i takes the values 1, 2, 3, and 4.",
                "The condition i <= 4 allows 4 to be printed.",
                "i is increased after each iteration, so the order is ascending."};

        training_answer(Q1, Q1_option, 2, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "How many times will this loop execute?\n\n"
            "for(int i = 0; i < 5; i++)\n"
            "    printf(\"Hello\");";

        char Q2_option[4][60] =
            {
                "4",
                "5",
                "6",
                "0"};

        char Q2_explanation[4][150] =
            {
                "The loop includes i values from 0 through 4.",
                "Correct - the loop executes 5 times.",
                "The loop stops when i becomes 5.",
                "The initial condition i < 5 is true, so the loop executes."};

        training_answer(Q2, Q2_option, 2, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "Which part of a for loop changes the loop variable after each iteration?";

        char Q3_option[4][60] =
            {
                "Initialization",
                "Condition",
                "Update expression",
                "Loop body"};

        char Q3_explanation[4][150] =
            {
                "Initialization gives the loop variable its starting value.",
                "The condition determines whether another iteration will occur.",
                "Correct - the update expression changes the loop variable.",
                "The loop body contains the statements that are repeatedly executed."};

        training_answer(Q3, Q3_option, 3, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "What will happen if the condition of a while loop is false before the first iteration?";

        char Q4_option[4][60] =
            {
                "The loop executes once",
                "The loop executes twice",
                "The loop body does not execute",
                "The program produces an error"};

        char Q4_explanation[4][150] =
            {
                "A while loop checks its condition before executing its body.",
                "There is no rule that makes a while loop execute twice.",
                "Correct - if the initial condition is false, the loop body is skipped.",
                "A false condition does not automatically cause a program error."};

        training_answer(Q4, Q4_option, 3, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "What will be the output?\n\n"
            "int i = 5;\n"
            "while(i > 2)\n"
            "{\n"
            "    printf(\"%d \", i);\n"
            "    i--;\n"
            "}";

        char Q5_option[4][60] =
            {
                "5 4 3",
                "5 4 3 2",
                "3 4 5",
                "2 3 4"};

        char Q5_explanation[4][150] =
            {
                "Correct - i is printed as 5, 4, and 3 before becoming 2.",
                "2 is not printed because the condition is i > 2.",
                "The loop decreases i, so the values are printed in descending order.",
                "The loop starts at 5, not 2."};

        training_answer(Q5, Q5_option, 1, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "What does the break statement do when used inside a loop?";

        char Q6_option[4][60] =
            {
                "Skips the current iteration",
                "Restarts the loop",
                "Immediately terminates the loop",
                "Pauses the program"};

        char Q6_explanation[4][150] =
            {
                "continue skips the current iteration.",
                "break does not restart the loop.",
                "Correct - break immediately exits the loop.",
                "break does not pause the program."};

        training_answer(Q6, Q6_option, 3, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "What will be the output?\n\n"
            "for(int i = 1; i <= 5; i++)\n"
            "{\n"
            "    if(i == 3)\n"
            "        continue;\n"
            "    printf(\"%d \", i);\n"
            "}";

        char Q7_option[4][60] =
            {
                "1 2 3 4 5",
                "1 2 4 5",
                "3",
                "1 2"};

        char Q7_explanation[4][150] =
            {
                "continue prevents 3 from being printed.",
                "Correct - when i is 3, continue skips that iteration, so 1, 2, 4, and 5 are printed.",
                "continue does not print only the value 3.",
                "The loop continues after 3 and prints 4 and 5."};

        training_answer(Q7, Q7_option, 2, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "How many times will the inner printf execute?\n\n"
            "for(int i = 1; i <= 3; i++)\n"
            "{\n"
            "    for(int j = 1; j <= 2; j++)\n"
            "        printf(\"*\");\n"
            "}";

        char Q8_option[4][60] =
            {
                "3",
                "5",
                "6",
                "9"};

        char Q8_explanation[4][150] =
            {
                "The inner loop executes twice for each outer iteration.",
                "The total number is greater than 5.",
                "Correct - the outer loop runs 3 times and the inner loop runs 2 times each, giving 3 x 2 = 6.",
                "3 x 2 gives 6, not 9."};

        training_answer(Q8, Q8_option, 3, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

int Array_quizUnlocked = 0;
void ArrayTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212

        printf("\n============================================================\n");
        printf("                      ARRAY ARENA\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Array_quizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            Array_lesson(); // line 4512
            Array_quizUnlocked = 1;
        }

        else if (choice == 2)
        {
            if (Array_quizUnlocked == 1)
                Array_quiz(); // line 4613
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void Array_lesson()
{
    int section = 1;
    int total_sections = 4;
    char navigation;

    while (section >= 1 && section <= total_sections)
    {
        clear_screen();   // line 212
        if (section == 1) // SECTION 1: Array Cave
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
        else if (section == 2)
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
        else if (section == 3)
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
        else if (section == 4)
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

        navigation = lesson_navigation(section, total_sections); // line 3085
        if (navigation == 'N')
        {
            section++;
        }
        else if (navigation == 'P')
        {
            section--;
        }
        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void Array_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212
    printf("============================================================\n");
    printf("                ARRAYS KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q1[] =
            "Which is the correct way to declare an integer array with 5 elements?";

        char Q1_option[4][60] =
            {
                "int arr;",
                "int arr[5];",
                "array int arr[5];",
                "int[5] arr;"};

        char Q1_explanation[4][150] =
            {
                "This declares only one integer variable.",
                "Correct - int arr[5] declares an integer array with 5 elements.",
                "array is not a keyword used to declare arrays in C.",
                "In C, the array size is written after the array name."};

        training_answer(Q1, Q1_option, 2, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "If int numbers[6] is declared, what is the index of the last element?";

        char Q2_option[4][60] =
            {
                "6",
                "5",
                "4",
                "0"};

        char Q2_explanation[4][150] =
            {
                "Index 6 is outside the valid range of the array.",
                "Correct - an array with 6 elements has indices from 0 through 5.",
                "Index 4 refers to the fifth element.",
                "Index 0 refers to the first element."};

        training_answer(Q2, Q2_option, 2, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "If int marks[5] = {10, 20, 30, 40, 50}; which index contains 40?";

        char Q3_option[4][60] =
            {
                "2",
                "3",
                "4",
                "5"};

        char Q3_explanation[4][150] =
            {
                "marks[2] contains 30.",
                "Correct - 40 is stored at index 3.",
                "marks[4] contains 50.",
                "Index 5 is outside the valid range."};

        training_answer(Q3, Q3_option, 2, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "Which statement correctly changes the third element of arr to 100?\n\n"
            "int arr[5] = {10, 20, 30, 40, 50};";

        char Q4_option[4][60] =
            {
                "arr[3] = 100;",
                "arr[2] = 100;",
                "arr[1] = 100;",
                "arr[5] = 100;"};

        char Q4_explanation[4][150] =
            {
                "Index 3 refers to the fourth element.",
                "Correct - the third element has index 2 because indexing starts at 0.",
                "Index 1 refers to the second element.",
                "Index 5 is outside the valid range of this array."};

        training_answer(Q4, Q4_option, 2, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "What will be the output?\n\n"
            "int a[4] = {5, 10, 15, 20};\n"
            "printf(\"%d\", a[2]);";

        char Q5_option[4][60] =
            {
                "5",
                "10",
                "15",
                "20"};

        char Q5_explanation[4][150] =
            {
                "a[0] contains 5.",
                "a[1] contains 10.",
                "Correct - a[2] contains 15.",
                "a[3] contains 20."};

        training_answer(Q5, Q5_option, 3, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "Which loop correctly visits every element of an array with 8 elements?";

        char Q6_option[4][60] =
            {
                "for(int i = 0; i <= 8; i++)",
                "for(int i = 1; i < 8; i++)",
                "for(int i = 0; i < 8; i++)",
                "for(int i = 0; i <= 6; i++)"};

        char Q6_explanation[4][150] =
            {
                "i <= 8 attempts to access index 8, which is outside the array.",
                "Starting from 1 skips the first element at index 0.",
                "Correct - this visits every index from 0 through 7.",
                "i <= 6 stops at index 6, so the last element at index 7 is skipped."};

        training_answer(Q6, Q6_option, 3, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "What will be the value of sum?\n\n"
            "int arr[4] = {2, 4, 6, 8};\n"
            "int sum = 0;\n"
            "for(int i = 0; i < 4; i++)\n"
            "    sum += arr[i];";

        char Q7_option[4][60] =
            {
                "10",
                "16",
                "20",
                "24"};

        char Q7_explanation[4][150] =
            {
                "10 is only the sum of the first two elements.",
                "16 is not the total sum of the array.",
                "Correct - 2 + 4 + 6 + 8 equals 20.",
                "24 is not the sum of all four elements."};

        training_answer(Q7, Q7_option, 3, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "Which statement correctly checks whether the first element of arr is even?\n\n"
            "int arr[5] = {8, 11, 15, 20, 25};";

        char Q8_option[4][60] =
            {
                "if(arr[1] % 2 == 0)",
                "if(arr[0] % 2 == 0)",
                "if(arr[0] / 2 == 0)",
                "if(arr[5] % 2 == 0)"};

        char Q8_explanation[4][150] =
            {
                "arr[1] refers to the second element, not the first.",
                "Correct - arr[0] is the first element and % 2 checks whether it is even.",
                "Division by 2 does not correctly determine whether a number is even.",
                "arr[5] is outside the valid range of the array."};

        training_answer(Q8, Q8_option, 2, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

int Function_quizUnlocked = 0;
void FunctionTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212
        printf("\n============================================================\n");
        printf("                   FUNCTION FORTRESS\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Function_quizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            Function_lesson(); // line 4877
            Function_quizUnlocked = 1;
        }

        else if (choice == 2)
        {
            if (Function_quizUnlocked == 1)
                Function_quiz(); // line 5020
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void Function_lesson()
{
    int section = 1;
    int total_sections = 5;
    char navigation;

    while (section >= 1 && section <= total_sections)
    {
        clear_screen(); // line 212
        if (section == 1)
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

        else if (section == 2)
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

        else if (section == 3)
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

        else if (section == 4)
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

        else if (section == 5)
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

        navigation = lesson_navigation(section, total_sections); // line 3085
        if (navigation == 'N')
        {
            section++;
        }
        else if (navigation == 'P')
        {
            section--;
        }
        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void Function_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212
    printf("============================================================\n");
    printf("                FUNCTION KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
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
                "53"};

        char Q1_explanation[4][150] =
            {
                "5 is the first argument passed to the function.",
                "3 is the second argument passed to the function.",
                "Correct - the function returns 5 + 3, which is 8.",
                "The two integer arguments are added numerically, not joined as text."};

        training_answer(Q1, Q1_option, 3, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "What is the main purpose of the return statement in a function?";

        char Q2_option[4][60] =
            {
                "To repeat the function",
                "To send a value back to the caller",
                "To declare a variable",
                "To stop the entire program"};

        char Q2_explanation[4][150] =
            {
                "A return statement does not repeat a function.",
                "Correct - return sends a value back to the code that called the function.",
                "Variables are declared separately from the return statement.",
                "return exits the current function, not necessarily the entire program."};

        training_answer(Q2, Q2_option, 2, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "Which function declaration correctly accepts two integers and returns an integer?";

        char Q3_option[4][60] =
            {
                "int add(int a, int b);",
                "void add(int a, int b);",
                "int add(a, b);",
                "add(int a, int b);"};

        char Q3_explanation[4][150] =
            {
                "Correct - int specifies the return type and the two int parameters are declared.",
                "void means the function does not return a value.",
                "The parameter types should be specified in a standard function declaration.",
                "A return type is required in a normal function declaration."};

        training_answer(Q3, Q3_option, 1, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "What will be the output?\n\n"
            "void show()\n"
            "{\n"
            "    printf(\"Hello\");\n"
            "}\n\n"
            "show();";

        char Q4_option[4][60] =
            {
                "show",
                "Hello",
                "void",
                "Error"};

        char Q4_explanation[4][150] =
            {
                "show is the function name, not the text printed.",
                "Correct - calling show() executes printf(\"Hello\").",
                "void specifies that the function does not return a value.",
                "The function definition and call are valid C code."};

        training_answer(Q4, Q4_option, 2, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "What will be the output?\n\n"
            "int square(int x)\n"
            "{\n"
            "    return x * x;\n"
            "}\n\n"
            "printf(\"%d\", square(4));";

        char Q5_option[4][60] =
            {
                "4",
                "8",
                "16",
                "20"};

        char Q5_explanation[4][150] =
            {
                "The function multiplies 4 by itself rather than returning 4.",
                "4 multiplied by 4 is not 8.",
                "Correct - square(4) returns 4 * 4, which is 16.",
                "20 is not the result of 4 * 4."};

        training_answer(Q5, Q5_option, 3, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "Which statement correctly calls a function named calculate that takes two integers?";

        char Q6_option[4][60] =
            {
                "calculate;",
                "calculate(5, 10);",
                "call calculate(5, 10);",
                "calculate[int, int];"};

        char Q6_explanation[4][150] =
            {
                "A function that takes parameters must receive them when called.",
                "Correct - the function is called using its name followed by the arguments in parentheses.",
                "call is not a C keyword used to call functions.",
                "Square brackets are not used to pass function arguments."};

        training_answer(Q6, Q6_option, 2, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "What will be the output?\n\n"
            "int change(int x)\n"
            "{\n"
            "    x = 20;\n"
            "    return x;\n"
            "}\n\n"
            "int n = 5;\n"
            "printf(\"%d\", change(n));";

        char Q7_option[4][60] =
            {
                "5",
                "20",
                "25",
                "Error"};

        char Q7_explanation[4][150] =
            {
                "The function changes its local parameter x to 20 before returning it.",
                "Correct - x is assigned 20 inside the function, so change(n) returns 20.",
                "The function does not add 5 and 20.",
                "The function definition and call are valid C code."};

        training_answer(Q7, Q7_option, 2, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "Which statement about function parameters is correct?";

        char Q8_option[4][60] =
            {
                "A function can never have parameters",
                "Parameters receive values when the function is called",
                "Parameters must always be global variables",
                "Parameters can only be of type int"};

        char Q8_explanation[4][150] =
            {
                "Functions can have one or more parameters.",
                "Correct - arguments passed during a function call are received by the corresponding parameters.",
                "Function parameters are local to the function.",
                "Parameters can have different data types depending on the function."};

        training_answer(Q8, Q8_option, 2, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

int Pointer_quizUnlocked = 0;
void PointerTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212
        printf("\n============================================================\n");
        printf("                     POINTER PEAK\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (Pointer_quizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            Pointer_lesson(); // line 5298
            Pointer_quizUnlocked = 1;
        }

        else if (choice == 2)
        {
            if (Pointer_quizUnlocked == 1)
                Pointer_quiz(); // line 5398
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void Pointer_lesson()
{
    int section = 1;
    int total_sections = 5;
    char navigation;

    while (section >= 1 && section <= total_sections)
    {
        clear_screen(); // line 212
        if (section == 1)
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

        else if (section == 2)
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

        else if (section == 3)
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

        else if (section == 4)
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

        else if (section == 5)
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

        navigation = lesson_navigation(section, total_sections); // line 3085
        if (navigation == 'N')
        {
            section++;
        }
        else if (navigation == 'P')
        {
            section--;
        }
        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void Pointer_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212
    printf("============================================================\n");
    printf("                POINTERS KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q1[] =
            "What is a pointer in C?";

        char Q1_option[4][60] =
            {
                "A variable that stores only integers",
                "A variable that stores the address of another variable",
                "A function that returns an address",
                "A variable that can never change"};

        char Q1_explanation[4][150] =
            {
                "A pointer can store addresses of different types of variables.",
                "Correct - a pointer stores the memory address of another variable.",
                "A pointer is a variable, not a function.",
                "A pointer can be changed to store a different address."};

        training_answer(Q1, Q1_option, 2, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "Which symbol is used to declare a pointer variable in C?";

        char Q2_option[4][60] =
            {
                "&",
                "*",
                "%",
                "#"};

        char Q2_explanation[4][150] =
            {
                "& is commonly used to get the address of a variable.",
                "Correct - * is used when declaring a pointer variable.",
                "% is used with format specifiers and the modulus operator.",
                "# is used for preprocessor directives."};

        training_answer(Q2, Q2_option, 2, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "What does the & operator do when used with a variable?";

        char Q3_option[4][60] =
            {
                "Gets the value of the variable",
                "Gets the address of the variable",
                "Deletes the variable",
                "Changes the variable's data type"};

        char Q3_explanation[4][150] =
            {
                "The variable name itself is used to access its value.",
                "Correct - & gives the memory address of the variable.",
                "The & operator does not delete variables.",
                "The & operator does not change data types."};

        training_answer(Q3, Q3_option, 2, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "What does the * operator do when used with a pointer?";

        char Q4_option[4][60] =
            {
                "Gets the address stored in the pointer",
                "Declares an integer variable",
                "Accesses the value stored at the pointer's address",
                "Deletes the pointer"};

        char Q4_explanation[4][150] =
            {
                "The & operator is used to obtain an address.",
                "The * symbol can declare a pointer, but that is not what it does when used with an existing pointer.",
                "Correct - * dereferences the pointer and accesses the value stored at its address.",
                "The * operator does not delete pointers."};

        training_answer(Q4, Q4_option, 3, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "What will be the output?\n\n"
            "int x = 10;\n"
            "int *p = &x;\n"
            "printf(\"%d\", *p);";

        char Q5_option[4][60] =
            {
                "10",
                "Address of x",
                "0",
                "Error"};

        char Q5_explanation[4][150] =
            {
                "Correct - *p accesses the value stored at the address held by p, which is 10.",
                "p contains the address, but *p accesses the value at that address.",
                "x was initialized to 10, so dereferencing p does not produce 0.",
                "The pointer declaration and dereference are valid C code."};

        training_answer(Q5, Q5_option, 1, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "What will be the output?\n\n"
            "int x = 7;\n"
            "int *p = &x;\n"
            "*p = 15;\n"
            "printf(\"%d\", x);";

        char Q6_option[4][60] =
            {
                "7",
                "15",
                "Address of x",
                "Error"};

        char Q6_explanation[4][150] =
            {
                "The value of x is changed through the pointer.",
                "Correct - *p refers to x, so assigning 15 to *p changes x to 15.",
                "The program prints x's value, not its address.",
                "The pointer assignment is valid C code."};

        training_answer(Q6, Q6_option, 2, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "Which statement correctly declares a pointer to an integer variable?";

        char Q7_option[4][60] =
            {
                "int p;",
                "int &p;",
                "int *p;",
                "pointer int p;"};

        char Q7_explanation[4][150] =
            {
                "int p declares a normal integer variable.",
                "& is not used this way to declare a pointer in C.",
                "Correct - int *p declares p as a pointer to an integer.",
                "pointer is not a C keyword for declaring pointers."};

        training_answer(Q7, Q7_option, 3, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "If int x = 20; and int *p = &x;, which expression gives the value 20?";

        char Q8_option[4][60] =
            {
                "&p",
                "p",
                "*p",
                "&x"};

        char Q8_explanation[4][150] =
            {
                "&p gives the address of the pointer variable itself.",
                "p contains the address of x, not the value 20.",
                "Correct - *p dereferences the pointer and gives the value stored in x, which is 20.",
                "&x gives the address of x, not its value."};

        training_answer(Q8, Q8_option, 3, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

int String_quizUnlocked = 0;
void StringTraining()
{
    int choice;

    while (1)
    {
        clear_screen(); // line 212

        printf("\n============================================================\n");
        printf("                    SILENT CORRIDOR\n");
        printf("============================================================\n\n");

        printf("[1] Knowledge Quest\n");

        if (String_quizUnlocked == 1)
            printf("[2] Knowledge Battle\n");
        else
            printf("[2] Knowledge Battle - LOCKED\n");

        printf("[0] Return to Topic List\n\n");

        printf("Your choice: ");
        choice = menu_input(0, 2); // line 3121

        if (choice == 0)
            return;

        if (choice == 1)
        {
            String_lesson(); // line 5662
            String_quizUnlocked = 1;
        }

        else if (choice == 2)
        {
            if (String_quizUnlocked == 1)
                String_quiz(); // line 5754
            else
            {
                printf("\nKnowledge Battle is locked.\n");
                printf("Complete the Knowledge Quest first.\n");
                enter_to_continue(); // line 5979
            }
        }
    }
}

void String_lesson()
{
    int section = 1;
    int total_sections = 5;
    char navigation;

    while (section >= 1 && section <= total_sections)
    {
        clear_screen(); // line 212
        if (section == 1)
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
        else if (section == 2)
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

        else if (section == 3)
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

        else if (section == 4)
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

        else if (section == 5)
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

        navigation = lesson_navigation(section, total_sections); // line 3085
        if (navigation == 'N')
        {
            section++;
        }
        else if (navigation == 'P')
        {
            section--;
        }
        else if (navigation == 'E')
        {
            printf("\nLesson Complete!\n");
            enter_to_continue(); // line 5979
            return;
        }
    }
}

void String_quiz()
{
    int upper_limit = 4, lower_limit = 1;
    int Time;
    clear_screen(); // line 212
    printf("============================================================\n");
    printf("                STRING KNOWLEDGE BATTLE\n");
    printf("============================================================\n\n");

    //------------------------------question 1--------------------------------
    srand(time(NULL));
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;
    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q1[] =
            "Which is the correct way to declare a string in C?";

        char Q1_option[4][60] =
            {
                "char name;",
                "char name[20];",
                "string name;",
                "text name[20];"};

        char Q1_explanation[4][150] =
            {
                "char name can store only one character.",
                "Correct - a string can be stored in a character array such as char name[20].",
                "string is not a basic built-in data type in C.",
                "text is not a C data type."};

        training_answer(Q1, Q1_option, 2, Q1_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q2[] =
            "Which format specifier is used to print a string using printf()?";

        char Q2_option[4][60] =
            {
                "%c",
                "%d",
                "%s",
                "%f"};

        char Q2_explanation[4][150] =
            {
                "%c is used to print a single character.",
                "%d is used to print an integer.",
                "Correct - %s is used to print a string.",
                "%f is used to print a floating-point value."};

        training_answer(Q2, Q2_option, 3, Q2_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q3[] =
            "What is the correct way to initialize a string with \"Hello\"?";

        char Q3_option[4][60] =
            {
                "char str = \"Hello\";",
                "char str[] = \"Hello\";",
                "string str = \"Hello\";",
                "char str[5] = \"Hello\";"};

        char Q3_explanation[4][150] =
            {
                "A single char variable cannot store an entire string.",
                "Correct - char str[] creates a character array and stores the string Hello.",
                "string is not a basic C data type.",
                "Hello needs 6 characters in the array when the null character is included."};

        training_answer(Q3, Q3_option, 2, Q3_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q4[] =
            "What is the index of the first character in a C string?";

        char Q4_option[4][60] =
            {
                "0",
                "1",
                "-1",
                "2"};

        char Q4_explanation[4][150] =
            {
                "Correct - C arrays start from index 0.",
                "Index 1 refers to the second character.",
                "Negative indexing is not used for the first character.",
                "Index 2 refers to the third character."};

        training_answer(Q4, Q4_option, 1, Q4_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    //------------------------------question 2--------------------------------
    
    Time = rand() % (upper_limit - lower_limit + 1) + lower_limit;

    if (Time == 1)
    {
        clear_screen(); // line 212
        char Q5[] =
            "What will be the output?\n\n"
            "char name[] = \"Sam\";\n"
            "printf(\"%c\", name[1]);";

        char Q5_option[4][60] =
            {
                "S",
                "a",
                "m",
                "Sam"};

        char Q5_explanation[4][150] =
            {
                "name[0] contains S.",
                "Correct - name[1] contains a.",
                "name[2] contains m.",
                "%c prints one character, not the whole string."};

        training_answer(Q5, Q5_option, 2, Q5_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 2)
    {
        clear_screen(); // line 212
        char Q6[] =
            "What will be the output?\n\n"
            "char word[] = \"Code\";\n"
            "printf(\"%s\", word);";

        char Q6_option[4][60] =
            {
                "C",
                "Code",
                "word",
                "Error"};

        char Q6_explanation[4][150] =
            {
                "%s prints the complete string, not only the first character.",
                "Correct - %s prints the characters stored in the string.",
                "word is the variable name, not its output.",
                "The declaration and printf statement are valid C code."};

        training_answer(Q6, Q6_option, 2, Q6_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 3)
    {
        clear_screen(); // line 212
        char Q7[] =
            "What will be the output?\n\n"
            "char text[] = \"Cat\";\n"
            "text[0] = 'B';\n"
            "printf(\"%s\", text);";

        char Q7_option[4][60] =
            {
                "Cat",
                "Bat",
                "B",
                "Error"};

        char Q7_explanation[4][150] =
            {
                "The first character is changed from C to B.",
                "Correct - text[0] changes C to B, making the string Bat.",
                "Changing one character does not remove the remaining characters.",
                "The character array can be modified."};

        training_answer(Q7, Q7_option, 2, Q7_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }

    else if (Time == 4)
    {
        clear_screen(); // line 212
        char Q8[] =
            "Which statement correctly stores the word \"Apple\" in a character array?";

        char Q8_option[4][60] =
            {
                "char fruit[5] = \"Apple\";",
                "char fruit[6] = \"Apple\";",
                "char fruit = \"Apple\";",
                "string fruit[6] = \"Apple\";"};

        char Q8_explanation[4][150] =
            {
                "The array also needs space for the null character.",
                "Correct - Apple has 5 characters plus the null character, so 6 spaces are needed.",
                "A char variable can store only one character.",
                "string is not a basic C data type."};

        training_answer(Q8, Q8_option, 2, Q8_explanation); // line 3145
        enter_to_continue();                               // line 5979
    }
}

//__________________UTILITY_____________

void flush_input()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void enter_to_continue()
{
    printf("\nPress Enter to continue...");
    getchar();
}
char continue_or_back()
{
    char hold;
    printf("\n___________________________________________");
    printf("\n->Enter \"Back\" to Redirect to menu..\n");
    printf("->Enter to continue....     :");
    while (1)
    {
        hold = getchar();
        if (hold == 'B' || hold == 'b' || hold == '\n')
        {
            if (hold == 'B' || hold == 'b')
            {
                flush_input(); // line 5972
                return 'R';
            }
            return 'n'; // hudai kono kam nai
        }
        else
        {
            flush_input(); // line 5972
            printf("invalid input, \n Enter corectly :");
        }
    }
}
