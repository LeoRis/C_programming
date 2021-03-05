#include <stdio.h>

#define MAX 20

typedef struct president{
    char nameSurname[MAX];
    char politicalParty[MAX];
} pres;

typedef struct capital{
    char capitalName[MAX];
    int population;
} capi;

typedef struct country{
    char name[MAX];
    pres trump;
    capi town;
} count;


int main(){
    struct country c[MAX];
    int i = 0, n = 0;

    printf("How many countries you want to compare?\n");
    printf("Please enter: ");
    scanf("%d", &n);

    printf("Enter country names: \n");

    for(i = 0; i < n; i++){
        scanf("%s", &c[i].name);
    }

    printf("\n");

    printf("Enter country's president name, party, capital and capital's population: \n");

    for(i = 0; i < n; i++){
        scanf("%s%s%s%d", &c[i].trump.nameSurname, &c[i].trump.politicalParty, &c[i].town.capitalName, &c[i].town.population);
    }

    printf("\n");

    for(i = 0; i < n; i++){
        printf("%d. %10s %10s   %10s    %10s %d\n", i + 1, c[i].name, c[i].trump.nameSurname, c[i].trump.politicalParty, c[i].town.capitalName, c[i].town.population);
    }

    printf("\n");

    int maxIndex = 0;
    int max = c[maxIndex].town.population;

    for(i = 0; i < n; i++){
        if(c[i].town.population > max){
            max = c[i].town.population;
            maxIndex = i;
        }
    }

    printf("\nThe name of the president of the state with the largest capital is: %s\n", c[maxIndex].trump.nameSurname);

    return 0;
}
