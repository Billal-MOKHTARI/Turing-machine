1. Les deux fichiers `calculateur.txt` et `accepteur.txt` contiennt chacun d'eux un exemple de machine de Turing, le premier : $f(x) = 2x$ avec $x \in \\{0, 1\\}^*$. Le deuxième reconnait le langage $L = \\{a^ib^jc^{2i}, \ avec \ i,j >= 0\\}$.
2. Les instruction sont sous cette forme :
    - [toRead][currentState] [transformTo][position][nextState]

3. L'exécution :
    ```shell 
    ./main [file] [--mode] [word]
    ```

4. Si `[word] = "--epsilon"` ou `p`, cela veut dire que notre mot est $\epsilon$.
5. Les états prennent leurs valeurs dans l'ensemble $\\{0, 1, \dots , 9, a, b, c, \dots , z, A, B, C, \dots , Z\\}$ pour la facilité de la mise en oeuvre (coté implémentation).

6. Le fichier `calculateur2.txt` contient la MT suivante :
    $$f(x = \\{a,\ b\\}^*) = \vert x\vert$$
