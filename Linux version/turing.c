#include "turing.h"
#include <string.h>

MT initMT()
{
    MT mt;
    mt.nbr = 0;
    return mt;
}

void addInstruction(MT *mt, MTParams mtParams)
{
    int position = mt->nbr;

    mt->tab[position] = mtParams;
    mt->nbr += 1;
}

void showMT(MT mt)
{
    int size = mt.nbr;
    int i;
    printf("┌───────────────────┐\n");
    printf("│ Machine de turing │\n");
    printf("├───────────────────┤\n");
    for (i = 0; i < size - 1; i++)
    {
        MTParams mtParams = mt.tab[i];
        printf("│    %cq%c → %c%cq%c     │\n", mtParams.toRead, mtParams.currentState, mtParams.transformTo, mtParams.position, mtParams.nextState);
        printf("├───────────────────┤\n");
    }
    MTParams mtParams = mt.tab[i];

    printf("│    %cq%c → %c%cq%c     │\n", mtParams.toRead, mtParams.currentState, mtParams.transformTo, mtParams.position, mtParams.nextState);
    printf("└───────────────────┘\n\n");
}

MTParams createMTParams(char toRead, char currentState, char transformTo, char position, char nextState)
{
    MTParams mtParams;
    mtParams.toRead = toRead;
    mtParams.currentState = currentState;
    mtParams.transformTo = transformTo;
    mtParams.position = position;
    mtParams.nextState = nextState;

    return mtParams;
}

char *creerRuban(char word[])
{
    int wordSize = strlen(word);
    int expendSize = wordSize * (1 + 2 * FACTOR);
    char *ruban = malloc(sizeof(char) * expendSize);

    for (int i = 0; i < FACTOR * wordSize; i++)
    {
        ruban[i] = '#';
    }

    for (int k = FACTOR * wordSize; k < (FACTOR + 1) * wordSize; k++)
    {
        ruban[k] = word[k - FACTOR * wordSize];
    }
    for (int j = (FACTOR + 1) * wordSize; j < expendSize; j++)
    {
        ruban[j] = '#';
    }
    ruban[expendSize] = '\0';

    return ruban;
}

Evaluation MTEvaluation(MT mt, const char givenWord[], char mode)
{
    int size = mt.nbr;
    MTParams current;
    char *word = creerRuban(givenWord);
    int wordPos = FACTOR * strlen(givenWord);
    char tmpState = INIT_STATE;
    Evaluation evaluation;
    evaluation.found = 0;
    evaluation.res[MAX] = "";

    do
    {
        // On teste si une des instruction de la MT satisfait le mot
        for (int i = 0; i < size; i++)
        {
            MTParams elem = mt.tab[i];

            if (elem.currentState == tmpState && elem.toRead == word[wordPos])
            {
                tmpState = elem.nextState;
                word[wordPos] = elem.transformTo;

                if (elem.position == DROITE)
                    wordPos += 1;
                else if (elem.position == GAUCHE)
                    wordPos -= 1;

                evaluation.found = 1;
                break;
            };
        }
        // Aucune des instructions n'est valide
        if (evaluation.found == 0)
            return evaluation;

        evaluation.found = 0;
    } while (tmpState != FINAL_STATE);

    if (tmpState == FINAL_STATE)
        evaluation.found = 1;

    if (mode == CALCULATEUR)
    {
        int i = 0;
        while (word[wordPos + i] != '#')
        {
            evaluation.res[i] = word[wordPos + i];
            i++;
        }

    }

    return evaluation;
}
