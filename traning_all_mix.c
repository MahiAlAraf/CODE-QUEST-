#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------
   FORWARD DECLARATIONS (originally in utils.h)
   ------------------------------------------------------------ */
void clear_screen();
void flush_input();
int answer_input_loop();
char lesson_navigation(int section, int total_sections);          //need
int menu_input(int min, int max);                                 //need
void enter_to_continue(void);
void traning_answer(char question[], char option[4][60], int correctAns, char explanation[4][150]);       //need

/* ------------------------------------------------------------
   FORWARD DECLARATIONS (originally in training.h)
   ------------------------------------------------------------ */
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

/* ============================================================
   UTILS.C  --  shared helper functions
   ============================================================ */

void clear_screen(void)
{
    system("cls");  
}

void flush_input()
{
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF);  
}

int answer_input_loop()
{
    int answer;

    while(1)
    {
        if(scanf("%d", &answer) == 1)  
        {
            flush_input(); 

            if(answer >= 1 && answer <= 4)  
            {
                return answer;  
            }
        }
        else
        {
            flush_input();  
        }

        printf("Invalid input. Please enter a number from 1 to 4: ");
    }
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

void enter_to_continue()
{
    int ch;

    printf("\nPress Enter to continue...");
    while((ch = getchar()) != '\n' && ch != EOF);  
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
        choice = menu_input(0, 8);  

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
int main()
{
    training();  // launches the training menu (all 8 topic chambers)
    return 0;
}