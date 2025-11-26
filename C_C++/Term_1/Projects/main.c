#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "uiDraw.h"
#include "students.h"
int main()
{
    ShowMainUi();
    int count = 0;
    int choice,option;
    while(scanf("%d",&choice) != EOF)
    {
        switch(choice)
        {
        case 1:
            count = ImportEmploymentData();
            break;
        case 2:
            ViewEmploymentData(count);
            break;
        case 3:
            option = ShowReminderIDName();
            SearchEmploymentData(option);
            break;
        case 4:
            AddEmploymentData();
            break;
        case 5:
            DeleteEmploymentData(count);
            break;
        case 6:
            ChangeEmploymentData(count);
            break;
        case 7:
            ShowSecondUi();
            //StatisticsEmploymentData();
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
        ShowMainUi();
    }
    end:
        system("pause");
    return 0;
}