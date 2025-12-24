#include <stdio.h>
#include <windows.h>
#include "uiDraw.h"
#include "students.h"
int main()
{
    DrawManu();
    struct GraduateInfo *student_p = NULL;//初始化指针
    int choice,option;
    while(scanf("%d",&choice) != EOF)
    {
        switch(choice)
        {
        case 1:
            student_p = ImportEmploymentData();
            break;
        case 2:
            student_p = ViewEmploymentData();
            break;
        case 3:
            option = ShowReminderIDName();
            SearchEmploymentData(option);
            break;
        case 4:
            AddEmploymentData(student_p);
            break;
        case 5:
            DeleteEmploymentData(student_p);
            break;
        case 6:
            ChangeEmploymentData(student_p);
            break;
        case 7:
            option = DrawSecondManu();
            StatisticsEmploymentData(option,student_p);
            break;
        case 8:
            printf("\n系统退出中.....\n");
            Sleep(2000);
            system("cls");
            goto end;
            break;
        default:
            printf("无效的选项!\n");
            Sleep(1000);
            break;
        }
        system("cls");
        DrawManu();
    }
    end:
        return 0;
    return 0;
}