#include <stdio.h>
#include <string.h>
int main()
{
    printf("===============================================================================================================\n");
    printf("                                                    STUDENT MARK ANALYZER");
    printf("\n===============================================================================================================\n");
    int n;
    printf("1.ENTER STUDENT RECORDS:\n");
    printf("2.VIEW STUDENT RECORD\n");
    printf("3.STATISTICS\n");
    printf("4.EXIT\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {
        int ID,ROLL,PHY,CHEM,MATH;
        char NAME[50];
        printf("enter ID:");
        scanf("%d",&ID);
        printf("enter NAME:");
        scanf("%s",&NAME);
        printf("enter PHYSICS MARK:");
        scanf("%d",&PHY);
        printf("enter CHEMISTRY MARK:");
        scanf("%d",&CHEM);
        printf("enter MATH MARK:");
        scanf("%d",&MATH);

        FILE * fo;
        fo=fopen("C:\\Users\\SOWMYA SHRIE S\\Desktop\\stu.txt","a");

        if (fo == NULL)
        {
            printf("Error opening the file!\n");
            return 1;
        }

        fprintf(fo,"ID:%d",ID);
        fprintf(fo,"\nNAME:%s",NAME);
        fprintf(fo,"\nPHYSICS:%d",PHY);
        fprintf(fo,"\nCHEMISTRY:%d",CHEM);
        fprintf(fo,"\nMATH:%d",MATH);
        fprintf(fo,"------------------------------");

        fclose(fo);
        break;
    }
    case 2:
    {
        FILE * fo;
        int a,l,id;
        char b[500];
        fo=fopen("C:\\Users\\SOWMYA SHRIE S\\Desktop\\stu.txt","r");
        printf("Enter ID of the student to view the record:");
        scanf("%d",&id);
        int i=0;
        while (i==0)
        {
            fgets(b,sizeof(b),fo);
            sscanf(b,"ID:%d",&a);
            if (a==id)
            {
                printf("%s",b);
                fgets(b,sizeof(b),fo);
                printf("%s",b);
                fgets(b,sizeof(b),fo);
                printf("%s",b);
                fgets(b,sizeof(b),fo);
                printf("%s",b);
                fgets(b,sizeof(b),fo);
                printf("%s",b);
                break;
            }
            else
            {
                for(l=0; l<5; l++)
                {
                    fgets(b,sizeof(b),fo);
                }
                continue;
            }


        }
        break;
    }
    case 3:
    {
        FILE * fo;
        int a,p,ch,m;
        char c[50],b[500];
        int phy=0;
        int chem=0;
        int math=0;
        fo=fopen("C:\\Users\\SOWMYA SHRIE S\\Desktop\\stu.txt","r");
        while (fgets(b,sizeof(b),fo)!=NULL)
        {
            sscanf(b,"ID:%d",&a);
            fgets(b,sizeof(b),fo);
            sscanf(b,"NAME:%s",c);
            fgets(b,sizeof(b),fo);
            sscanf(b,"PHYSICS:%d",&p);
            fgets(b,sizeof(b),fo);
            sscanf(b,"CHEMISTRY:%d",&ch);
            fgets(b,sizeof(b),fo);
            sscanf(b,"MATH:%d",&m);
            if (p>phy)
            {
                phy=p;
            }
            if (m>math)
            {
                math=m;
            }
            if (ch>chem)
            {
                chem=ch;
            }
        }
        fclose(fo);
        printf("\n=== STATISTICS ===\n");
        printf("Highest Physics Mark: %d\n", phy);
        printf("Highest Chemistry Mark: %d\n", chem);
        printf("Highest Math Mark: %d\n", math);
        break;
    }
    case 4:
    {
        printf("thank u");
    }
    break;
    }
}
