#ifndef GIFT           //if GIFT has not appeared ->here GIFT is just a calling name
#define GIFT           // then difine GIFT(all functions)  

void clear_screen();
void enter_to_continue();
void current_status();
void level_status();
void flush_input();
void HP_Bar();
int answer_input_loop();
char Yes_No_loop();
int correct_answer(char question[], char option[4][60], int correctAns,int HP_Minus_if_wrong, int Reward_Coin, int reward_XP, char explanation[4][150]);
char lesson_navigation(int section, int total_sections);          //need
int menu_input(int min, int max);                                 //need
void traning_answer(char question[], char option[4][60], int correctAns, char explanation[4][150]);       //need
int profile_open();
void profile_save();
void profile_reset();
void file_reset();
int file_open();
void file_save();
void Market_open();
void Market_save();
void Market_reset();

#endif //End of if