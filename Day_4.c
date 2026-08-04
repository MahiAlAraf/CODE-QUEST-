// CODE QUEST: Escape from the Compiler Kingdom
// Region 1: Variables Village + Region 2: Loop Forest + Array Cave + Function Falls

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
char Yes_No_loop();
int correct_answer(char question[], char option[4][60], int correctAns,
                    int HP_Minus_if_wrong, int Reward_Coin, int reward_XP,
                    char explanation[4][150]);
int variable_village();
int loop_forest();
void After_forest_EQuest();
int array_cave();
void After_cave_shop();
int Function_falls();

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

        HP = variable_village();
        if (HP <= 0) {
            printf("\nYou have fallen, %s...\n", Name);
            printf("The kingdom's corruption was too strong this time.\n");
            printf("Restarting your journey from the beginning.\n");
            enter_to_continue();
            continue;
        }

        HP = loop_forest();
        if (HP <= 0) {
            printf("\nYou have fallen, %s...\n", Name);
            printf("The kingdom's corruption was too strong this time.\n");
            printf("Restarting your journey from the beginning.\n");
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
            printf("\nYou have fallen, %s...\n", Name);
            printf("The kingdom's corruption was too strong this time.\n");
            printf("Restarting your journey from the beginning.\n");
            enter_to_continue();
            continue;
        }
        printf("-----------------------------------------------------------------------------------------");
        printf("\n%s : OHH , At last Back in ONE pice. I guess there should be function falls ahead.\n,",Name);
        current_status();
        printf("Need to do something about it\n");
        printf("Want to search for any store?\ny/n?=");
        char Choose;
        while(1)
        {
         scanf("%s",&Choose);
          if(Choose=='y')
            {
                After_cave_shop();
                break;
            }
          else if (Choose=='n')
           {
                printf("OK to the next phase then ...");
                break;
            }  
            else{printf("Enter correctly ...=");}                                         
        }
        enter_to_continue();
        HP = Function_falls();
        if (HP <= 0) {
            printf("\nYou have fallen, %s...\n", Name);
            printf("The kingdom's corruption was too strong this time.\n");
            printf("Restarting your journey from the beginning.\n");
            enter_to_continue();
            continue;
        }
        current_status();

        break;
    }
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
        scanf("%c",&answer);
        if(answer=='y'||answer=='Y'||answer=='n'||answer=='N')
        {
            return answer;
            break;
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
    correct_answer(Q2, Q2_option, 1, 8, 3, 4, Q2_explanation);
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
    correct_answer(Q3, Q3_option, 3, 12, 4, 4, Q3_explanation);
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
    correct_answer(Q4, Q4_option, 3, 20, 6, 4, Q4_explanation);
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
    correct_answer(Q1, Q1_option, 1, 10, 12, 3, Q1_explanation);
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
    correct_answer(Q2, Q2_option, 1, 10, 12, 5, Q2_explanation);
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
    correct_answer(Q3, Q3_option, 3, 10, 14, 5, Q3_explanation);
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
    correct_answer(Q4, Q4_option, 2, 10, 18, 7, Q4_explanation);
    if (HP <= 0) return HP;

    printf("\nCongratulations %s, you have found a way out of the Loop Forest!\n", Name);

    return HP;
}

//_____________________________________________Loop forest Quest_______________________________________________
void After_forest_EQuest() {
    printf("\n\nOhh wait... another traveler is waving for help.\n");
    printf("Want to help her out?\n");
    printf("1. Yes\n2. No\n");
    printf("Enter choice: ");
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
        int wrong=correct_answer(side_Q1, side_q1_options, 1, 0, 15, 3, side_Q1_explanation);
        if(wrong==0){

        printf("\nThe Traveler: \"Thank you sir, it was a great help for me.\n");
        printf("I have nothing much to give you but I can surely give you some coins.\"\n");
        printf("----------------------------------------------------------------------\n");
        printf("    Congratulations %s! You have won bonus 15 coins and 3 XP.\n", Name);
        Coin=Coin+15;
        XP=XP+3;}
        else{
            printf("Traveler: \" Anyway, thank you sir for you kindness....\"\n");
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
    correct_answer(Q1, Q1_option, 3, 10, 8, 5, Q1_explanation);
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
    correct_answer(Q2, Q2_option, 2, 12, 10, 5, Q2_explanation);
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
    correct_answer(Q3, Q3_option, 3, 15, 12, 9, Q3_explanation);
    if (HP <= 0) return HP;

    printf("\nWell done %s! Cave stabilizes. Fragment restored.\n", Name);
    return HP;
}
//___________________________________________________Shop After array cave ________________________________________
void After_cave_shop()
{
    printf("\n=================================================================================================\n");
    printf("                          There is a small wooden shop ahead \n");
    printf("                                Travelar %s goes inside\n",Name);
    printf("                         ----------------------------------------\n");
    printf("    Shopkeper:  Hello Travelar ,can I help you with something ? I don't sell much ,\n");
    printf("Just a few things I found around the kingdom. Some are useful. Some are... expensive. Take a look\n");
    printf("=================================================================================================\n");
    int Choose;
    printf("  Items                            Effects                                Price\n\n");
    printf("1.Alexer                       resotere+50HP                             -60coins\n");
    printf("2.Iron Sheild             cancel panalty HP for 1 time                   -175coins\n");
    printf("3.XP Potion              Duubble XP for next chalange                    -150coins\n");
    printf("Enter Choose: ");
    while(1)
    {
        Choose=answer_input_loop();
        if(Choose==1 && Coin>=60)
        {
            printf("Alexer obtained \n HP restored by 50\n");
            HP=HP+50;
            if(HP>=Max_HP)
            {
                HP=Max_HP;
            }
        Coin=Coin-60;
        current_status();
        break;
        }
        else
        {
            printf(".... Insufficient Coins \nyour have %d coins.\n peek something else...",Coin);
        }
    }
    printf("%s : Lets head back to the Journey\n",Name);
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
    correct_answer(Q1, Q1_option, 2, 15, 40, 3, Q1_explanation);
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
    correct_answer(Q2, Q2_option, 3, 18, 50, 5, Q2_explanation);
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
    correct_answer(Q3, Q3_option, 4, 20, 60, 5, Q3_explanation);
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
    correct_answer(Q4, Q4_option, 2, 22, 70, 7, Q4_explanation);
    if (HP <= 0) return HP;

    printf("\nWell done %s! The Waterwheel turns once more.\n", Name);
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