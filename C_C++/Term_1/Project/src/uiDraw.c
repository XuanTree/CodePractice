#include <stdio.h>
#include <windows.h>
void DrawManu(){
    printf(
        "   信息学院毕业生就业去向管理系统\n\n");
    printf("+---------------------------------+\n");
    printf("| 1. 批量导入就业数据             |\n");
    printf("|---------------------------------|\n");
    printf("| 2. 浏览就业数据                 |\n");
    printf("|---------------------------------|\n");
    printf("| 3. 查询就业数据                 |\n");
    printf("|---------------------------------|\n");
    printf("| 4. 增录就业数据                 |\n");
    printf("|---------------------------------|\n");
    printf("| 5. 删除就业数据                 |\n");
    printf("|---------------------------------|\n");
    printf("| 6. 修改就业数据                 |\n");
    printf("|---------------------------------|\n");
    printf("| 7. 统计就业数据                 |\n");
    printf("|---------------------------------|\n");
    printf("| 8. 退出管理系统                 |\n");
    printf("+---------------------------------+\n");
    printf("选择操作方式:");
}
int DrawSecondManu(){
    system("cls");
    printf("| 统计就业数据                                             |\n");
    printf("+----------------------------------------------------------+\n");
    printf("| 1. 统计某一年份就业率                                    |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| 2. 统计某一年份不同学历就业率                            |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| 3. 统计某一年份不同专业就业率                            |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| 4. 统计某一年份不同就业方向人数和比例                    |\n");
    printf("|----------------------------------------------------------|\n");
    printf("| 5. 统计某一年份从事不同专业方向人数和比例                |\n");
    printf("+----------------------------------------------------------+\n");
    printf("选择操作方式:");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        return 0;
    }
}
int ShowReminderIDName()
{
    system("cls");
    printf(" 查询就业数据                    \n");
    printf("=================================\n");
    printf("1. 学号\t2. 姓名\n");
    printf("=================================\n");
    printf("请选择查询方式:");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    default:
        return 0;
    }
}
int ShowWhichInfo()
{
    printf("\n 修改就业数据                 \n");
    printf("+-------------------------------+\n");
    printf("| 1. 学号\n| 2. 姓名\n| 3. 性别\n| 4. 出生时间\n| 5. 入学年份\n");
    printf("| 6. 毕业年份\n| 7. 专业\n| 8. 就业方向\n| 9. 就业单位\n| 10. 工作专业\n| 11. 就业状态(已就业/未就业)\n");
    printf("+-------------------------------+\n");
    printf("请选择要修改的信息:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("请输入新的学号:");
            return 1;
        case 2:
            printf("请输入新的姓名:");
            return 2;
        case 3:
            printf("请输入新的性别:");
            return 3;
        case 4:
            printf("请输入新的出生时间:");
            return 4;
        case 5:
            printf("请输入新的入学年份:");
            return 5;
        case 6:
            printf("请输入新的毕业年份:");
            return 6;
        case 7: 
            printf("请输入新的专业:");
            return 7;
        case 8:
            printf("请输入新的就业方向:");
            return 8;
        case 9:
            printf("请输入新的就业单位:");
            return 9;
        case 10:
            printf("请输入新的工作专业:");
            return 10;
        case 11:
            printf("请设置就业状态(输入 y 表示已就业, n 表示未就业):");
            return 11;
        default:
            printf("无效的选项!");
            return 0;
    }
}