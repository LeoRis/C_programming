#include <stdio.h>

typedef struct{

    char *name;
    int scienceGrade, mathGrade, historyGrade, englishGrade;

} reportCard;

void printReportingCard(reportCard *rc){

    int average = (rc->scienceGrade + rc->englishGrade + rc->mathGrade + rc->historyGrade) / 4;
    printf("Student's Name: %s\nOverall Grade: %d\n", rc->name, average);
}

int main(){

    reportCard rc;

    printf("Enter the student's last name: \n");
    char str[20];
    scanf("%s", str);
    rc.name = str;

    printf("Science Grade: \n");
    scanf("%d", &rc.scienceGrade);

    printf("English Grade: \n");
    scanf("%d", &rc.englishGrade);

    printf("Math Grade: \n");
    scanf("%d", &rc.mathGrade);

    printf("History Grade: \n");
    scanf("%d", &rc.historyGrade);

    printReportingCard(&rc);

    return 0;
}
