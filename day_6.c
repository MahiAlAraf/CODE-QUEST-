// CODE QUEST: Escape from the Compiler Kingdom

#include <stdio.h>
#include <string.h>

//_________________________global_variables______________________
char Name[50];
int Coin = 0;
int HP = 100;
int Max_HP = 100;
int Level = 1;
int XP = 0;
int Iron_shield = 0;   // set to 1 when the player buys the Iron Shield (halves next wrong-answer penalty)

//_______________________function prototypes_____________________
void show_menu();
void new_game();
void enter_to_continue();
void current_status();
void flush_input();
void HP_Bar();
int answer_input_loop();
char Yes_No_loop();
void fallen_statement();
int correct_answer(char question[], char option[4][60], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]);
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


int main() {
    show_menu();
    return 0;
}

//__________________MAIN MENU_____________
void show_menu() {
    int choice;
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
    printf("1. New Game\n2. Exit\n");
    printf("Enter choice: ");

    while (1) {
        scanf("%d", &choice);
        flush_input();
        if (choice == 1 || choice == 2) {
            break;
        } else {
            printf("Invalid Input...\nEnter properly: ");
        }
    }

    if (choice == 1) {
        new_game();
    } else {
        printf("\n   Goodbye, Apprentice.\n");
        printf("==========game end===========\n");
    }
}

//___________________________________________________________NEW GAME____________________________________________________
void new_game() {
    printf("\n--------------------------------------------------------------\n");
    printf("              The Compiler Kingdom is broken.\n");
    printf("       A virus called the NULL POINTER shattered its code.\n");
    printf("             You are the last Code Apprentice.\n");
    printf("      Fix 4 lands. Face the Null Pointer. Save the kingdom.\n");
    printf("----------------------------------------------------------------\n\n");

    printf("Enter your name: ");
    scanf("%s", Name);
    flush_input();

    printf("\nWelcome %s, your journey begins!\n", Name);
    enter_to_continue();

    while (1) {
        // reset stats at the start of every attempt
        HP = 100;
        Max_HP = 100;
        XP = 0;
        Coin = 0;
        Level = 1;
        Iron_shield = 0;

        HP = variable_village();
        if (HP <= 0) {
            fallen_statement();
            enter_to_continue();
            continue;
        }

        HP = loop_forest();
        if (HP <= 0) {
            fallen_statement();
            enter_to_continue();
            continue;
        }

        current_status();
        enter_to_continue();
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
        current_status();
        enter_to_continue();

        HP = array_cave();
        if (HP <= 0) {
            fallen_statement();
            enter_to_continue();
            continue;
        }
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%s : OHH, at last back in one piece. I guess there should be Function Falls ahead.\n", Name);
        current_status();
        printf("Need to do something about it\n");
        printf("Want to search for any store? (y/n): ");
        char store_choice = Yes_No_loop();
        if (store_choice == 'y' || store_choice == 'Y') {
            After_cave_shop();
        } else {
            printf("OK, to the next phase then...\n");
        }
        enter_to_continue();
        HP = Function_falls();
        if (HP <= 0) {
            fallen_statement();
            enter_to_continue();
            continue;
        }
        current_status();
        HP=Pointer_peak();                   //  709
        if(HP<=0)
        {
            fallen_statement();
            enter_to_continue();
            continue;
        }
        enter_to_continue();
        current_status();
        enter_to_continue();
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
        printf("\n\n%s : I think I should take some precaution steps before facing the NULL POINTER\n", Name);
        printf("%s : Let's head back to the store and see what I can grab.\n\n", Name);
        printf("\n\n----------On the way to the store, %s found a man seeking his help!", Name);
        printf("\nWant to see? Or ignore him?\ny/n: ");

        char decision = Yes_No_loop();
        if (decision == 'y' || decision == 'Y')
        {
            Precaution_EQuest();
        }
        else
        {
            printf("Are you sure you want to avoid this? This might be a great chance to win some coins...\n");
            printf("y/n: ");
            char decision2 = Yes_No_loop();
            if (decision2 == 'y' || decision2 == 'Y')
            {
                printf("%s : Sorry sir, but I am in a hurry, I have not much time.\n\n", Name);
            }
            else
            {
                Precaution_EQuest();
            }
        }
        precaution();
        enter_to_continue();

        HP=final_stage();
        if(HP<=0)
        {
            fallen_statement();
            enter_to_continue();
            continue;
        }

        HP=NUL_POINTER();
        if(HP<=0)
        {
            fallen_statement();
            enter_to_continue();
            continue;
        }
        break;
    }
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
    if (XP > 85) {
        printf("    Level  :   Expert\n");
    } else if (XP > 75) {
        printf("    Level  :   Advanced\n");
    } else if (XP > 50) {
        printf("    Level   :    Intermediate\n");
    } else if (XP > 25) {
        printf("    Level    :   Noob\n");
    } else {
        printf("    Level     :    Boot\n");
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

    printf("\n%s\n", question);
    for (i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, option[i]);
    }
    printf("Enter Answer: ");
    answer = answer_input_loop();

    if (answer == correctAns) {
        printf("Correct!...\n+%d XP  +%d Coin\n", reward_XP, Reward_Coin);
        XP = XP + reward_XP;
        Coin = Coin + Reward_Coin;
        is_wrong = 0;
    } else {
        int actual_penalty = HP_Minus_if_wrong;
        printf("Wrong! The correct answer is: %s\n", option[correctAns - 1]);
        if (Iron_shield == 1) {
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

    printf("Want to see why?...\n");
    char yes;
    printf("\n Choose : y/n  :");
    yes = Yes_No_loop();
    if (yes == 'y' || yes=='Y') 
    {
        for (i = 0; i < 4; i++) {
            printf("%s\n", explanation[i]);
        }
    }
    enter_to_continue();
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
    enter_to_continue();
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
    printf("2.Iron Sheild             cancel panalty HP for 1 time                   -175coins\n");
    printf("3.XP Potion              Duubble XP for next chalange                    -150coins\n");
    printf("4.Skip                       continue journey, no cost                      --\n");
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
        } else if (Choose == 2||Choose==3) {
            printf(" Insufficient coin...\npeak something else..");
        }
        else if(Choose==4)
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
    printf("\nElder:\n");
    printf(" _________________________________________________________________________________________________________________________________ \n");
    printf("|Careful this time, traveler. Loops merely repeat mistakes. Functions, when broken, corrupt everything downstream.                |\n");
    printf("|One wrong scroll and the whole wheel jams. This region will cost you more if you fail - but it'll reward you more if you succeed.|\n");
    printf("|_________________________________________________________________________________________________________________________________|\n");
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
    printf("The road ends at a tall, grey mountain. Cold wind blows. Signs everywhere say \"Do not trust what you see.\"\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("An old guard stops you\n");
    printf("====================================================================\n");
    printf("This is Pointer Peak\n");
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
    enter_to_continue();
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
        scanf("%d", &answer);
        if (answer == 20)
        {
            Congratulations();
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

//__________________UTILITY_____________
// clears everything left in the input buffer up to and including the next newline
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// waits for the player to press Enter (buffer is always clean here, thanks to flush_input)
void enter_to_continue() {
    printf("\nPress Enter to continue...");
    getchar();
}
