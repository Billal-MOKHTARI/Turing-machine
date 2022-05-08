#ifndef __TURING__H__
#define __TURING__H__

#define MAX 10000
#define INIT_STATE '0'
#define FINAL_STATE 'f'
#define DROITE 'D'
#define GAUCHE 'G'
#define STATIONNAIRE 'S'
#define FACTOR 3
#define ACCEPTEUR 'a'
#define CALCULATEUR 'c'

typedef struct MTParams
{
    char toRead;
    char currentState;
    char transformTo;
    char position;
    char nextState;
} MTParams;

typedef struct MT
{
    MTParams tab[MAX];
    int nbr;
} MT;

typedef struct Evaluation
{
    int found;
    char res[MAX];
} Evaluation;

char *creerRuban(char *word);

MT initMT();
void addInstruction(MT *mt, MTParams mtParams);
void showMT(MT mt);
MTParams createMTParams(char toRead, char currentState, char transformTo, char position, char nextState);
Evaluation MTEvaluation(MT mt, const char word[], char mode);

#endif