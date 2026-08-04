// CODE QUEST: Escape from the Compiler Kingdom
// Region 1: Variables Village

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
void flush_input();
void HP_Bar();
int answer_input_loop();
int correct_answer(char question[], char option[4][30], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]);
void variable_village();

int main() {
    show_menu();
    return 0;
}

//__________________MAIN MENU_____________
void show_menu() {
    int choice;

    printf("=============================================\n");
    printf("   CODE QUEST: Escape from the Compiler Kingdom\n");
    printf("=============================================\n");
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
        printf("\nGoodbye, Apprentice.\n");
    }
}

//__________________NEW GAME_____________
void new_game() {
    printf("\n----------------------------------------\n");
    printf("The Compiler Kingdom is broken.\n");
    printf("A virus called the NULL POINTER shattered its code.\n");
    printf("You are the last Code Apprentice.\n");
    printf("Fix 4 lands. Face the Null Pointer. Save the kingdom.\n");
    printf("----------------------------------------\n\n");

    printf("Enter your name: ");
    scanf("%s", Name);
    flush_input();

    printf("\nWelcome %s, your journey begins!\n", Name);
    enter_to_continue();

    variable_village();
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

int correct_answer(char question[], char option[4][30], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]) {
    int i;
    int answer;
    int is_wrong;

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
        HP_Bar();
        is_wrong = 1;
    }

    printf("Press Enter to see why...\n");
    enter_to_continue();
    for (i = 0; i < 4; i++) {
        printf("%s\n", explanation[i]);
    }
    enter_to_continue();

    return is_wrong;
}

//__________________REGION 1: VARIABLES VILLAGE_____________
void variable_village() {
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
    char Q1_option[4][30] = {"int", "char", "float", "double"};
    char Q1_explanation[4][150] = {
        "int - stores whole numbers (no decimals), not meant for letters.",
        "char - designed specifically to hold a single character. Correct answer.",
        "float - stores decimal numbers like 3.14, not characters.",
        "double - stores larger, more precise decimal numbers, also not characters."
    };
    correct_answer(Q1, Q1_option, 2, 10, 2, 5, Q1_explanation);

    //________________question NO. 2_________________
    char Q2[] = "What is the correct way to declare an integer variable named age?";
    char Q2_option[4][30] = {"int age;", "integer age;", "age int;", "var age;"};
    char Q2_explanation[4][150] = {
        "int age; - correct C syntax: type first, then variable name. Correct answer.",
        "integer age; - integer isn't a real C keyword (some other languages use it, C doesn't).",
        "age int; - wrong order; the type must always come before the name in C.",
        "var age; - var isn't a C keyword either (that's from JavaScript)."
    };
    correct_answer(Q2, Q2_option, 1, 8, 2, 5, Q2_explanation);

    //________________question NO. 3_________________
    char Q3[] = "What will this print?\n  int x = 5;\n  x = x + 3;\n  printf(\"%d\", x);";
    char Q3_option[4][30] = {"5", "3", "8", "53"};
    char Q3_explanation[4][150] = {
        "5 - that was the value before the addition happened, not after.",
        "3 - that's just the number being added, not the final result.",
        "8 - correct: 5 + 3 = 8, and x is updated to that new value. Correct answer.",
        "53 - that would only happen if you joined text/strings together, not added numbers."
    };
    correct_answer(Q3, Q3_option, 3, 12, 3, 5, Q3_explanation);

    //________________question NO. 4 - Corrupted Villager (mini-boss)_________________
    printf("\nA Corrupted Villager blocks the village exit!\n");
    char Q4[] = "Which data type is used to store decimal numbers like 3.14?";
    char Q4_option[4][30] = {"int", "char", "float", "void"};
    char Q4_explanation[4][150] = {
        "int - only holds whole numbers, would chop off the .14.",
        "char - holds a single character, not numeric values.",
        "float - built specifically for decimal/floating-point numbers. Correct answer.",
        "void - means no value at all, used for functions that return nothing, not a storage type."
    };
    correct_answer(Q4, Q4_option, 3, 20, 5, 10, Q4_explanation);

    printf("\nThe Corrupted Villager fades away. The village calms down.\n");
    printf("A fragment of the Great Algorithm is restored!\n");
    printf("Elder Byte: \"Well done. The forest ahead awaits your help.\"\n");
    HP_Bar();
    printf("XP: %d | Coins: %d | Level: %d\n", XP, Coin, Level);

    enter_to_continue();
    printf("\n(Region 2: Loop Forest coming next)\n");
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