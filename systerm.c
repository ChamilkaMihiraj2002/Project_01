#include <stdlib.h>
#include <stdio.h>


//Database of Student :
struct student
{
    int Index;
    char name[255];
    int Accounting;
    int Econ;
    int ICT;
    int TM;
    double avg;
};

//Students in Class :
struct student s[40];

int grade(int g){
    char grade;
    if (g>=75)
    {
        grade = 'A';
    }else if (g >= 65)
    {
        grade ='B';
    }else if (g>=55)
    {
        grade = 'C';
    }else if (g >=45)
    {
        grade ='S';
    }else
    {
        grade ='W';
    }
    return grade;
}

int filehead(){
    FILE * fpointer=fopen("report.text","a");
    fprintf(fpointer,"------------------------------------------------------\n");
    fprintf(fpointer,"                  Student Reports                     \n");
    fprintf(fpointer,"------------------------------------------------------\n\n");
    fclose(fpointer);
}

int midfile(int total,double avg,int i){
    FILE * fpointer = fopen("report.text","a");
    fprintf(fpointer,"Name        : %s\n",s[i].name);
    fprintf(fpointer,"index       : %d\n",s[i].Index);
    fprintf(fpointer,"Subjects     Marks    Grade\n");
    fprintf(fpointer,"Econ        : %d\t\t%c\n",s[i].Econ,grade(s[i].Econ));
    fprintf(fpointer,"ICT         : %d\t\t%c\n",s[i].ICT,grade(s[i].ICT));
    fprintf(fpointer,"Accounting  : %d\t\t%c\n",s[i].Accounting,grade(s[i].Accounting));
    fprintf(fpointer,"-------------------------------------\n");
    fprintf(fpointer,"Total       : %d\n",total);
    fprintf(fpointer,"Average     : %0.2lf\n",avg);
    fprintf(fpointer,"_____________________________________\n\n");
    fclose(fpointer);
}



int main()
{
    printf(": To Exit <Press -1> :\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("                   Student Report Systerm                    |\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    filehead();
    int count = 0;
    int tot,i;
    double avg;
    while (1)
    {
        int id;
        char Rgrade;
        printf("Student Index Number ('-1 Entered Exit the program ') : ");
        scanf("%d",&id);
        
        if (id != -1)
        {
            s[count].Index = id;
            printf("Student name (10 letters included) : ");
            scanf("%10s",s[count].name);
            printf("Accounting   : ");
            scanf("%d",&s[count].Accounting);
            printf("Econ         : ");
            scanf("%d",&s[count].Econ); 
            printf("ICT          : ");
            scanf("%d",&s[count].ICT);
            printf("\n"); 
            count++;
        }
        else{
            break;
        }
    }
    char eq;
    printf("Show the Reports (Y/N) : ");
    scanf(" %c",&eq);

    switch (eq)
    {
        case 'Y':
        for (i = 0; i < count; i++)
        {
             tot = s[i].Accounting + s[i].Econ + s[i].ICT;
            avg = tot/3;
            midfile(tot,avg,i);
        }
            
        break;
        
        default:
            break;
    }
    return 0;
}
