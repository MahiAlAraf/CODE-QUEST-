// CODE QUEST: Escape from the Compiler Kingdom
// Region 1: Variables Village + Region 2: Loop Forest

#include <stdio.h>
#include <string.h>

//_________________________global_variables______________________
char Name[50];
int Coin = 0;
int HP = 100;
int Max_HP = 100;
int Level = 1;
int XP = 0;

//_______________________function prototypes_____________________
void show_menu();
void new_game();
void enter_to_continue();
void current_status();
void flush_input();
void HP_Bar();
int answer_input_loop();
int correct_answer(char question[], char option[4][60], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]);
int variable_village();
int loop_forest();

int main() {
    show_menu();
    return 0;
}

//__________________MAIN MENU_____________
void show_menu() {
    int choice;

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

        HP = variable_village();                        //VILLAGE
        if (HP <= 0) {
            printf("\nYou have fallen, %s...\n", Name);
            printf("The kingdom's corruption was too strong this time.\n");
            printf("Restarting your journey from the beginning.\n");
            enter_to_continue();
            continue;   // go back to the top of the while loop and try again
        }

        HP = loop_forest();                              //FOREST
        if (HP <= 0) {
            printf("\nYou have fallen, %s...\n", Name);
            printf("The kingdom's corruption was too strong this time.\n");
            printf("Restarting your journey from the beginning.\n");
            enter_to_continue();
            continue;
        }

        
        break;
    }

    current_status();
    enter_to_continue();

    printf("\nWizard of Iteration: \"You have restored the second fragment.\n");
    printf("But something's wrong deeper in the kingdom.\n\n");
    printf("The caves beyond the forest are collapsing. Tunnels vanishing,\n");
    printf("paths caving in without warning. That's not natural.\n");
    printf("Something is reading memory it was never meant to touch.\"\n\n");
    printf("Wizard of Iteration: \"Go to Array Cave, apprentice %s.\n", Name);
    printf("Whatever broke the loops here... it's reaching further than we thought.\"\n");
    enter_to_continue();

    printf("\n\nOhh wait... another traveler is waving for help.\n");
    printf("Want to help her out?\n");
    printf("1. Yes\n2. No\n");
    printf("Enter choice: ");
    int choice = answer_input_loop();

    if (choice == 1) {
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
        correct_answer(side_Q1, side_q1_options, 1, 0, 17, 5, side_Q1_explanation);

        printf("\nThe Traveler: \"Thank you sir, it was a great help for me.\n");
        printf("I have nothing much to give you but I can surely give you some coins.\"\n");
        printf("----------------------------------------------------------------------\n");
        printf("    Congratulations %s! You have won bonus coins and XP.\n", Name);
    } else {
        printf("\n---------------------------------------------------------------------\n");
        printf("%s: \"I think I have been through a lot for one day.\"\n", Name);
    }

    current_status();
}

//__________________HP BAR_____________
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

void current_status() {
    printf("<------------------your current status---------------->\n");
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

//____________________________________QUESTION / BATTLE SYSTEM________________________________

int correct_answer(char question[], char option[4][60], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]) {
    int i,answer,is_wrong;
    

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
        printf("Wrong! The correct answer is: %s\n", option[correctAns - 1]);
        printf("-%d HP\n", HP_Minus_if_wrong);
        HP = HP - HP_Minus_if_wrong;
        if (HP < 0) {
            HP = 0;
        }
        HP_Bar();
        is_wrong = 1;
    }

    printf("Want to see why?...\n");
    int yes;
    printf("\n1.Yes\n2.No\n");
    printf("Choose : ");
    yes=answer_input_loop();
    if(yes==1)
    {
        enter_to_continue();
        for (i = 0; i < 4; i++) 
        {
          printf("%s\n", explanation[i]);
        }
    }
    else
    {
         enter_to_continue();
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
    correct_answer(Q1, Q1_option, 2, 10, 2, 3, Q1_explanation);
    if (HP <= 0) {
        return HP;
    }

    //________________question NO. 2_________________
    char Q2[] = "What is the correct way to declare an integer variable named age?";
    char Q2_option[4][60] = {"int age;", "integer age;", "age int;", "var age;"};
    char Q2_explanation[4][150] = {
        "int age; - correct C syntax: type first, then variable name. Correct answer.",
        "integer age; - integer isn't a real C keyword (some other languages use it, C doesn't).",
        "age int; - wrong order; the type must always come before the name in C.",
        "var age; - var isn't a C keyword either (that's from JavaScript)."
    };
    correct_answer(Q2, Q2_option, 1, 8, 2, 3, Q2_explanation);
    if (HP <= 0) {
        return HP;
    }

    //________________question NO. 3_________________
    char Q3[] = "What will this print?\n  int x = 5;\n  x = x + 3;\n  printf(\"%d\", x);";
    char Q3_option[4][60] = {"5", "3", "8", "53"};
    char Q3_explanation[4][150] = {
        "5 - that was the value before the addition happened, not after.",
        "3 - that's just the number being added, not the final result.",
        "8 - correct: 5 + 3 = 8, and x is updated to that new value. Correct answer.",
        "53 - that would only happen if you joined text/strings together, not added numbers."
    };
    correct_answer(Q3, Q3_option, 3, 12, 3, 4, Q3_explanation);
    if (HP <= 0) {
        return HP;
    }

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
    correct_answer(Q4, Q4_option, 3, 20, 5, 6, Q4_explanation);
    if (HP <= 0) {
        return HP;
    }

    printf("\nThe Corrupted Villager fades away. The village calms down.\n");
    printf("A fragment of the Great Algorithm is restored!\n");
    printf("Elder Byte: \"Well done. The forest ahead awaits your help.\"\n");
    current_status();
    enter_to_continue();

    return HP;
}

//_________________________________________REGION 2: LOOP FOREST_________________________________________
int loop_forest() {
    printf("\n                        =================\n");
    printf("                         ||  Loop Forest  ||\n");
    printf("                          =================\n");
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
    correct_answer(Q1, Q1_option, 1, 10, 26, 5, Q1_explanation);
    if (HP <= 0) {
        return HP;
    }

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
    correct_answer(Q2, Q2_option, 1, 10, 26, 6, Q2_explanation);
    if (HP <= 0) {
        return HP;
    }

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
    correct_answer(Q3, Q3_option, 3, 10, 25, 7, Q3_explanation);
    if (HP <= 0) {
        return HP;
    }

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
    correct_answer(Q4, Q4_option, 2, 10, 30, 9, Q4_explanation);
    if (HP <= 0) {
        return HP;
    }

    printf("\nCongratulations %s, you have found a way out of the Loop Forest!\n", Name);

    return HP;
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