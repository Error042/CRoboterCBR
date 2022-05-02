#include <stdio.h>
#include <stdlib.h>

/* function responcible for measuring the distance walked until hit a wall */
/* condition is used to decide if */
/* checkingValue is used for checking if the length */
/*int measuring(int condition, int checkingValue)*/
void measuring(int *coordinates){
    char decide[2];
    int counter=0, wall=0;

    while (wall==0) {
        printf("Ist eine Wand da? (y/n)\n");
        scanf("%s", decide);

        switch(decide[0]){
            case 'y':
            case 'Y':
                if (coordinates[4] > 1) {
                    printf("Drehe 90 Grad nach rechts!\n");
                    wall=1;
                } else {
                    if ((coordinates[4] == 2 && counter < coordinates[0]) || (coordinates[4] == 3 && counter < coordinates[1])) {
                        printf("Du befindest dich nicht in einem rechteckigen Raum!\n");
                        exit(0);
                    } else {
                        printf("Drehe 90 Grad nach rechts!\n");
                        wall=1;
                    }
                }
                break;
            case 'n':
            case 'N':
                printf("Schritt!\n");
                counter++;
                break;
            default:
                printf("Ungueltige Eingabe!\n");
                break;
        }
    }
    coordinates[coordinates[4]] = counter;
    coordinates[4]++;
}
