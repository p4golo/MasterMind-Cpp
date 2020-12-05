#ifndef MODULO1_H_INCLUDED
#define MODULO1_H_INCLUDED

void print_if(void);
int level(void);
bool repeats(void);
void random_code(unsigned int code[],bool repeat,int lenght,int values);
int lenghtCode(int level);
int values(int level);
int opportunities(int level);
void printCode(unsigned int code[],int length);
void game(unsigned int code[],unsigned int digitTries[],int length,int opportunities);

#endif // MODULO1_H_INCLUDED
