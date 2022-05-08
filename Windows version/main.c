#include <stdio.h>
#include <stdlib.h>
#include "turing.h"
#define BUF_MAX 100
#define NBR_PARAMS 5
int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        char *mot = malloc(100 * sizeof(char));
        if (!strcmp(argv[3], "--epsilon") || !strcmp(argv[3], "-e"))
            mot = "#";
        else
            mot = argv[3];

        MT mt = initMT();

        FILE *fichier = fopen(argv[1], "r");
        char chaine[BUF_MAX] = "";

        if (fichier)
        {
            while (fgets(&chaine, BUF_MAX, fichier))
            {
                char params[NBR_PARAMS] = {chaine[0], chaine[1], chaine[3], chaine[4], chaine[5]};
                addInstruction(&mt, createMTParams(params[0], params[1], params[2], params[3], params[4]));
            }

            if (!strcmp(argv[2], "--accepteur"))
            {
                Evaluation evaluation = MTEvaluation(mt, mot, ACCEPTEUR);
                if (!strcmp(mot, "#"))
                    mot = "epsilon";

                if (evaluation.found)
                    printf("The machine recognizes the word : %s \n", mot);
                else
                    printf("The machine doesn't recognize the word : %s\n", mot);
            }
            else if (!strcmp(argv[2], "--calculateur"))
            {
                Evaluation evaluation = MTEvaluation(mt, mot, CALCULATEUR);

                if (evaluation.found)
                {
                    if (!strcmp(mot, "#"))
                        mot = "epsilon";
                    printf("Given word : %s\n", mot);
                    printf("Result     : %s\n", evaluation.res);
                }
                else
                    printf("The machine detected a word that doesn't belong to language!\n");
            }
        }
        else
        {
            sprintf(stderr, "Adressing error !");
        }

        fclose(fichier);
    }
    else
    {
        printf("Verify that the number of parameters is 4 !\n");
    }
    return 0;
}