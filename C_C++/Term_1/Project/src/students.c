#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include "uiDraw.h"
#define MaxSize 2000
enum Gender
{
    F,
    M
};
struct Date
{
    int year;
    int month;
    int day;
};
typedef struct GraduateInfo
{
    char student_id[20];
    char name[30];
    enum Gender gender;
    struct Date birth_date;
    int enrollment_year;
    int graduation_year;
    char education_level[20];
    char major[50];
    char career_direction[30];
    int isEmployed; // 0 = 未就业, 1 = 已就业
    char employer[100];
    char job_major[50];
} GraduateInfo;
// 统一的打印函数，保证输出列对齐
void PrintGraduateLine(const GraduateInfo *s)
{
    char gender = (s->gender == M ? 'M' : 'F');
    if (s->isEmployed)
    {
        printf("%-10s %-8s %-4c %04d-%02d-%02d   %-6d %-6d %-8s %-12s %-12s %-12s %-12s\n",
                s->student_id,
                s->name,
                gender,
                s->birth_date.year, s->birth_date.month, s->birth_date.day,
                s->enrollment_year,
                s->graduation_year,
                s->education_level,
                s->major,
                s->career_direction,
                s->employer,
                s->job_major);
    }
    else
    {
        printf("%-10s %-8s %-4c %04d-%02d-%02d   %-6d %-6d %-8s %-12s %-12s %-12s\n",
                s->student_id,
                s->name,
                gender,
                s->birth_date.year, s->birth_date.month, s->birth_date.day,
                s->enrollment_year,
                s->graduation_year,
                s->education_level,
                s->major,
                s->career_direction,
                "未就业");
    }
}
GraduateInfo *ImportEmploymentData()
{
    system("cls");
    FILE *fp = NULL;
    FILE *bp = NULL;// 为GraduateInfo结构体数组分配内存,避免函数结束后立马被销毁.
    GraduateInfo *graduate = (GraduateInfo *)malloc(MaxSize * sizeof(GraduateInfo));
    if (graduate == NULL)
    {
        printf("内存分配失败!\n");
        system("pause");
        return NULL;
    }
    int count = 0;
    fp = fopen("StudentsList.txt", "r");
    if (fp == NULL)
    {
        printf("文件未找到!\n");
        Sleep(2000);
        free(graduate);
        return NULL;
    }
    char rest[512];
    GraduateInfo temp;
    char genderChar;//读取txt文件当中的信息
    while (count < MaxSize)
    {
        //读取固定字段部分(不含空格)
        int m = fscanf(fp, "%19s %29s %c %d %d %d %d %d %19s %49s %29s",
                        temp.student_id, temp.name, &genderChar,
                        &temp.birth_date.year, &temp.birth_date.month, &temp.birth_date.day,
                        &temp.enrollment_year, &temp.graduation_year,
                        temp.education_level, temp.major, temp.career_direction);
        if (m == EOF)
            break;
        if (m < 11)
        {
            //当前行字段不完整，跳过到行尾并继续
            int c;
            while ((c = fgetc(fp)) != EOF && c != '\n')
                ;
            continue;
        }
        temp.gender = (genderChar == 'M' ? M : F);
        // 读取当前行剩余部分（到换行结束）并解析雇主/工作专业
        if (fgets(rest, sizeof(rest), fp) != NULL)
        {
            // rest 为当前行剩余内容(可能是 "\n" 或空白)
            char emp[100] = "";
            char jobm[50] = "";
            //从rest中解析雇主和工作专业,允许雇主或工作专业为空,若有则n>=1
            int n = sscanf(rest, " %99s %49s", emp, jobm);
            if (n >= 1)
            {
                temp.isEmployed = 1;
                strcpy(temp.employer, emp);
                temp.employer[sizeof(temp.employer) - 1] = '\0';
            }
            else
            {
                temp.isEmployed = 0;
                temp.employer[0] = '\0';
            }
            //将第二个字符串作为工作专业赋值给job_major
            if (n >= 2)
            {
                strcpy(temp.job_major, jobm);
                temp.job_major[sizeof(temp.job_major) - 1] = '\0';
            }
            else
            {
                temp.job_major[0] = '\0';
            }
        }
        else
        {
            temp.isEmployed = 0;
            temp.employer[0] = '\0';
            temp.job_major[0] = '\0';
        }
        //学号查重工作
        int isDuplicateID = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(graduate[i].student_id, temp.student_id) == 0)
            {
                isDuplicateID = 1;
                break;
            }
        }
        if (isDuplicateID)
        {
            printf("发现重复学号: %s , 将跳过此条记录...\n", temp.student_id);
            Sleep(400);
            continue;
        }
        //将数据存入数组
        graduate[count++] = temp;
    }
    fclose(fp);
    // 写入二进制文件
    bp = fopen("students.dat", "wb");
    if (bp == NULL)
    {
        printf("未能打开二进制文件并进行写入!\n");
        Sleep(2000);
        free(graduate);
        return NULL;
    }
    for (int i = 0; i < count; i++)
    {
        fwrite(&graduate[i], sizeof(GraduateInfo), 1, bp);
    }
    fclose(bp);
    printf("\n %d  条记录已写入students.dat.\n\n", count);
    system("pause");
    return graduate;
}
GraduateInfo *ViewEmploymentData()
{
    system("cls");
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("未找到students.dat!\n");
        system("pause");
        return NULL;
    }
    // 为GraduateInfo结构体数组分配内存,避免函数结束后立马被销毁.
    GraduateInfo *student = (GraduateInfo *)malloc(MaxSize * sizeof(GraduateInfo));
    int count = 0;
    while (fread(&student[count], sizeof(GraduateInfo), 1, fp))
    {
        count++;
    }
    fclose(fp);
    // 打印表头
    printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
            "学号", "姓名", "性别", "出生日期", "入学", "毕业", "学历", "专业", "就业方向", "雇主/单位", "工作专业");
    printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
            "----------", "--------", "---", "------------", "-----", "-----", "------", "-----------", "-----------", "-----------", "------------");
    for (int i = 0; i < count; i++)
    {
        PrintGraduateLine(&student[i]);
    }
    if (count == 0)
    {
        printf("当前系统无毕业生信息!\n");
        free(student);
        return NULL;
    }
    system("pause");
    return student;
}
void SearchEmploymentData(int option)
{
    system("cls");
    char message[40];
    int found, continue_research = 1;
    FILE *fp;
    GraduateInfo tempStudent; // 添加临时变量
    while (continue_research)
    {
        system("cls");
        fp = fopen("students.dat", "rb");
        if (fp == NULL)
        {
            printf("未找到students.dat!\n");
            system("pause");
            return;
        }
        switch (option)
        {
        case 1:
            printf("请输入要搜索的学生的学号: ");
            scanf("%s", message);
            break;
        case 2:
            printf("请输入要搜索的学生的姓名: ");
            scanf("%s", message);
            break;
        default:
            return;
        }
        found = 0;
        // 读取所有学生信息
        while (fread(&tempStudent, sizeof(GraduateInfo), 1, fp)) // 使用临时变量
        {
            switch (option)
            {
            case 1:
                if (strcmp(tempStudent.student_id, message) == 0)
                {
                    found = 1;
                    printf("\n找到的学生信息:\n");
                    printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                            "学号", "姓名", "性别", "出生日期", "入学", "毕业", "学历", "专业", "就业方向", "雇主/单位", "工作专业");
                    printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                            "----------", "--------", "---", "------------", "----", "----", "------", "-----------", "-----------", "------------", "------------");
                    PrintGraduateLine(&tempStudent);
                    break; // 找到匹配的记录后立即跳出循环
                }
                break;
            case 2:
                if (strcmp(tempStudent.name, message) == 0)
                {
                    found = 1;
                    printf("\n找到的学生信息:\n");
                    printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                            "学号", "姓名", "性别", "出生日期", "入学", "毕业", "学历", "专业", "就业方向", "雇主/单位", "工作专业");
                    printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                            "----------", "--------", "---", "------------", "----", "----", "------", "-----------", "-----------", "------------", "------------");
                    PrintGraduateLine(&tempStudent);
                    break; // 找到匹配的记录后立即跳出循环
                }
                break;
            default:
                printf("无效的搜索选项。\n");
                fclose(fp);
                system("pause");
                return;
            }
        }
        fclose(fp); // 在每次循环结束后关闭文件
        if (!found)
        {
            printf("\n未找到匹配的记录。\n");
        }
        printf("\n是否继续搜索?(y/n): ");
        char choice;
        scanf(" %c", &choice); // 空格用于跳过之前的换行符
        if (choice != 'y' && choice != 'Y')
        {
            continue_research = 0; // 用户选择不继续搜索
        }
    }
    printf("\n");
    system("pause");
    return;
}
void AddEmploymentData(GraduateInfo *graduate)
{
    system("cls");
    GraduateInfo newGraduate;
    printf("请输入新毕业生的信息:\n");
    printf("学号: ");
    scanf("%s", newGraduate.student_id);
    printf("姓名: ");
    scanf("%s", newGraduate.name);
    printf("性别: ");
    char sex;
    scanf(" %c", &sex); // 空格用于跳过之前的换行符
    newGraduate.gender = (sex == 'M' ? M : F);
    printf("出生日期(年 月 日): ");
    scanf("%d %d %d", &newGraduate.birth_date.year, &newGraduate.birth_date.month, &newGraduate.birth_date.day);
    printf("入学年份: ");
    scanf("%d", &newGraduate.enrollment_year);
    printf("毕业年份: ");
    scanf("%d", &newGraduate.graduation_year);
    printf("学历水平: ");
    scanf("%s", newGraduate.education_level);
    printf("专业: ");
    scanf("%s", newGraduate.major);
    printf("职业方向: ");
    scanf("%s", newGraduate.career_direction);
    printf("是否已就业? (y/n): ");
    char empChoice;
    scanf(" %c", &empChoice);
    if (empChoice == 'y' || empChoice == 'Y')
    {
        newGraduate.isEmployed = 1;
        printf("就业单位: ");
        scanf("%s", newGraduate.employer);
        printf("工作专业: ");
        scanf("%s", newGraduate.job_major);
    }
    else
    {
        newGraduate.isEmployed = 0;
        newGraduate.employer[0] = '\0';
        newGraduate.job_major[0] = '\0';
    }
    // 检查学号是否重复
    FILE *fp = fopen("students.dat", "rb");
    if (fp != NULL)
    {
        GraduateInfo tmp;
        while (fread(&tmp, sizeof(GraduateInfo), 1, fp))
        {
            if (strcmp(tmp.student_id, newGraduate.student_id) == 0)
            {
                printf("发现重复学号: %s , 将跳过此条记录...\n", newGraduate.student_id);
                fclose(fp);
                system("pause");
                return;
            }
        }
        fclose(fp);
    }
    // 以追加模式打开.dat文件
    FILE *bp = fopen("students.dat", "ab");
    if (bp == NULL)
    {
        printf("未能打开二进制文件并进行写入!\n");
        system("pause");
        return;
    }
    // 写入新的毕业生信息
    fwrite(&newGraduate, sizeof(GraduateInfo), 1, bp);
    fclose(bp);
    printf("\n新数据已成功添加!\n");
    system("pause");
    return;
}
void DeleteEmploymentData(GraduateInfo *students)
{
    system("cls");
    printf("请输入要删除的学生的学号或姓名: ");
    char message[30];
    scanf("%s", message);
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("未找到students.dat!\n");
        system("pause");
        return;
    }
    int found = 0;
    int deleteConfirmed = 0;
    GraduateInfo student;
    // 读取所有学生信息
    int index = 0;
    while (fread(&students[index], sizeof(GraduateInfo), 1, fp))
    {
        if (strcmp(students[index].student_id, message) == 0 || strcmp(students[index].name, message) == 0)
        {
            printf("\n找到的学生信息:\n");
            printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                    "学号", "姓名", "性别", "出生日期", "入学", "毕业", "学历", "专业", "就业方向", "雇主/单位", "工作专业");
            printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                    "----------", "--------", "---", "------------", "----", "----", "------", "-----------", "-----------", "------------", "------------");
            PrintGraduateLine(&students[index]);
            printf("\n确认删除此学生信息?(y/n): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                deleteConfirmed = 1;
            }
            else
            {
                printf("删除操作已取消。\n");
            }
            found = 1;
        }
        index++;
    }
    fclose(fp);
    if (!found)
    {
        printf("\n未找到匹配的记录。\n");
        system("pause");
        return;
    }
    if (deleteConfirmed)
    {
        // 重新创建students.dat文件
        FILE *bp = fopen("students.dat", "wb");
        if (bp == NULL)
        {
            printf("未能打开二进制文件并进行写入!\n");
            system("pause");
            return;
        }
        // 写入除要删除的学生以外的所有学生信息
        for (int i = 0; i < index; i++)
        {
            if (strcmp(students[i].student_id, message) != 0 && strcmp(students[i].name, message) != 0)
            {
                fwrite(&students[i], sizeof(GraduateInfo), 1, bp);
            }
        }
        fclose(bp);
        printf("\n该学生信息已成功删除!\n");
    }
    system("pause");
    return;
}

void ChangeEmploymentData(GraduateInfo *students)
{
    system("cls");
    printf("请输入要修改的学生的学号或姓名: ");
    char message[30];
    scanf("%s", message);
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("未找到students.dat!\n");
        system("pause");
        return;
    }
    int found = 0;
    // 读取所有学生信息
    int index = 0;
    while (fread(&students[index], sizeof(GraduateInfo), 1, fp))
    {
        if (strcmp(students[index].student_id, message) == 0 || strcmp(students[index].name, message) == 0)
        {
            printf("\n找到的学生信息:\n");
            printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                    "学号", "姓名", "性别", "出生日期", "入学", "毕业", "学历", "专业", "就业方向", "雇主/单位", "工作专业");
            printf("%-10s %-8s %-3s %-12s %-6s %-6s %-8s %-12s %-12s %-12s %-12s\n",
                    "----------", "--------", "---", "------------", "----", "----", "------", "-----------", "-----------", "------------", "------------");
            PrintGraduateLine(&students[index]);
            char stringData[30];
            char sex;int intData, intYear, intMonth, intDay;
            int choice = ShowWhichInfo();
            switch (choice)
            {
            case 1:
                scanf("%s", stringData);
                strcpy(students[index].student_id, stringData);
                break;
            case 2:
                scanf("%s", stringData);
                strcpy(students[index].name, stringData);
                break;
            case 3:
                scanf(" %c", &sex);
                students[index].gender = (sex == 'M' ? M : F);
                break;
            case 4:
                scanf("%d %d %d", &intYear, &intMonth, &intDay);
                students[index].birth_date.year = intYear;
                students[index].birth_date.month = intMonth;
                students[index].birth_date.day = intDay;
                break;
            case 5:
                scanf("%d", &intData);
                students[index].enrollment_year = intData;
                break;
            case 6:
                scanf("%d", &intData);
                students[index].graduation_year = intData;
                break;
            case 7:
                scanf("%s", stringData);
                strcpy(students[index].major, stringData);
                break;
            case 8:
                scanf("%s", stringData);
                strcpy(students[index].career_direction, stringData);
                break;
            case 9:
                scanf("%s", stringData);
                strcpy(students[index].employer, stringData);
                break;
            case 10:
                scanf("%s", stringData);
                strcpy(students[index].job_major, stringData);
                break;
            case 11:
            {
                printf("是否已就业? (y/n): ");
                char ec;
                scanf(" %c", &ec);
                if (ec == 'y' || ec == 'Y')
                {
                    students[index].isEmployed = 1;
                    printf("请输入新的就业单位: ");
                    scanf("%s", students[index].employer);
                    printf("请输入新的工作专业: ");
                    scanf("%s", students[index].job_major);
                }
                else
                {
                    students[index].isEmployed = 0;
                    students[index].employer[0] = '\0';
                    students[index].job_major[0] = '\0';
                }
            }
            break;
            default:
                Sleep(1000);
                return;
            }
            found = 1;
        }
        index++;
    }
    fclose(fp);
    if (!found)
    {
        printf("\n未找到匹配的记录。\n");
        system("pause");
        return;
    }
    FILE *bp = fopen("students.dat", "wb");
    if (bp == NULL)
    {
        printf("未能打开二进制文件并进行写入!\n");
        system("pause");
        return;
    }
    // 修改新的毕业生信息
    for (int i = 0; i < index; i++)
    {
        fwrite(&students[i], sizeof(GraduateInfo), 1, bp);
    }
    fclose(bp);
    printf("数据修改成功!\n");
    Sleep(2000);
    return;
}
void StatisticsEmploymentData(int option)
{
    // 清屏
    system("cls");
    // 打开存储学生信息的文件
    FILE *fp = fopen("students.dat", "rb");
    // 如果文件未找到，打印错误信息并暂停程序
    if (fp == NULL)
    {
        printf("未找到students.dat!\n");
        system("pause");
        return;
    }
    // 计数器用于统计文件中学生信息的数量
    int count = 0;
    GraduateInfo student;
    // 读取文件中所有学生的信息以统计总数
    while (fread(&student, sizeof(GraduateInfo), 1, fp))
    {
        count++;
    }
    // 关闭文件
    fclose(fp);
    // 如果系统中没有毕业生信息，打印提示信息并暂停程序
    if (count == 0)
    {
        printf("当前系统无毕业生信息!\n");
        system("pause");
        return;
    }
    // 分配内存以存储所有学生信息
    GraduateInfo *arr = (GraduateInfo *)malloc(count * sizeof(GraduateInfo));
    // 如果内存分配失败，打印错误信息并暂停程序
    if (!arr)
    {
        printf("内存分配失败!\n");
        system("pause");
        return;
    }
    // 再次打开文件以重新读取学生信息
    fp = fopen("students.dat", "rb");
    int n = 0;
    // 将学生信息读取到数组中
    while (fread(&arr[n], sizeof(GraduateInfo), 1, fp))
    {
        n++;
    }
    // 关闭文件
    fclose(fp);
    // 提示用户输入要统计的年份
    int year;
    printf("请输入要统计的毕业年份: ");
    scanf("%d", &year);
    // 初始化统计变量
    int total = 0, employed = 0;
    char keys[MaxSize][64];
    int totalCnt[MaxSize] = {0};
    int empCnt[MaxSize] = {0};
    int uniq = 0;
    int cnt[MaxSize] = {0};
    // 根据用户选择的选项进行相应的统计
    switch (option)
    {
    case 1:
        // 统计特定年份的毕业生总数及其已就业人数
        for (int i = 0; i < n; i++)
        {
            if (arr[i].graduation_year == year)
            {
                total++;
                if (arr[i].isEmployed)
                    employed++;
            }
        }
        // 根据统计结果输出信息
        if (total == 0)
        {
            printf("%d 年没有毕业生记录。\n", year);
        }
        else
        {
            printf("%d 年共有毕业生 %d 人，其中已就业 %d 人，就业率: %.2f%%\n", year, total, employed, (double)employed * 100.0 / total);
        }
        break;
    case 2:
        // 按学历统计特定年份的毕业生人数及其已就业人数
        for (int i = 0; i < n; i++)
        {
            if (arr[i].graduation_year != year)
                continue;
            char *k = arr[i].education_level;
            int idx = -1;
            for (int j = 0; j < uniq; j++)
            {
                if (strcmp(keys[j], k) == 0)
                {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
            {
                strncpy(keys[uniq], k, 63);
                keys[uniq][63] = '\0';
                totalCnt[uniq] = 1;
                empCnt[uniq] = arr[i].isEmployed ? 1 : 0;
                uniq++;
            }
            else
            {
                totalCnt[idx]++;
                if (arr[i].isEmployed)
                {
                    empCnt[idx]++;
                }
            }
        }
        // 根据统计结果输出信息
        if (uniq == 0)
        {
            printf("%d 年没有毕业生记录。\n", year);
        }
        else
        {
            printf("学历\t\t总人数\t已就业\t就业率\n");
            for (int j = 0; j < uniq; j++)
            {
                printf("%-16s %-6d %-6d %.2f%%\n", keys[j], totalCnt[j], empCnt[j], totalCnt[j] ? (double)empCnt[j] * 100.0 / totalCnt[j] : 0.0);
            }
        }
        break;
    case 3:
        // 按专业统计特定年份的毕业生人数及其已就业人数
        for (int i = 0; i < n; i++)
        {
            if (arr[i].graduation_year != year)
                continue;
            char *k = arr[i].major;
            int idx = -1;
            for (int j = 0; j < uniq; j++)
            {
                if (strcmp(keys[j], k) == 0)
                {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
            {
                strcpy(keys[uniq], k);
                keys[uniq][63] = '\0';
                totalCnt[uniq] = 1;
                empCnt[uniq] = arr[i].isEmployed ? 1 : 0;
                uniq++;
            }
            else
            {
                totalCnt[idx]++;
                if (arr[i].isEmployed)
                    empCnt[idx]++;
            }
        }
        // 根据统计结果输出信息
        if (uniq == 0)
        {
            printf("%d 年没有毕业生记录。\n", year);
        }
        else
        {
            printf("专业\t\t总人数\t已就业\t就业率\n");
            for (int j = 0; j < uniq; j++)
            {
                printf("%-17s %-6d %-6d %.2f%%\n", keys[j], totalCnt[j], empCnt[j], totalCnt[j] ? (double)empCnt[j] * 100.0 / totalCnt[j] : 0.0);
            }
        }
        break;
    case 4:
        // 统计特定年份的毕业生就业方向及其人数
        for (int i = 0; i < n; i++)
        {
            if (arr[i].graduation_year != year)
                continue;
            total++;
            char *k = arr[i].career_direction;
            int idx = -1;
            for (int j = 0; j < uniq; j++)
            {
                if (strcmp(keys[j], k) == 0)
                {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
            {
                strcpy(keys[uniq], k);
                keys[uniq][63] = '\0';
                cnt[uniq] = 1;
                uniq++;
            }
            else
            {
                cnt[idx]++;
            }
        }
        // 根据统计结果输出信息
        if (total == 0)
        {
            printf("%d 年没有毕业生记录。\n", year);
        }
        else
        {
            printf("就业方向\t\t人数\t比例\n");
            for (int j = 0; j < uniq; j++)
            {
                printf("%-24s %-6d %.2f%%\n", keys[j], cnt[j], (double)cnt[j] * 100.0 / total);
            }
        }
        break;
    case 5:
        // 统计特定年份的毕业生工作专业及其人数
        int consideredTotal = 0; // 统计用于本统计项的毕业生总数
        for (int i = 0; i < n; i++)
        {
            if (arr[i].graduation_year != year)
                continue;
            // 回退规则：优先使用 job_major（有工作时），否则使用 career_direction
            char *k = NULL;
            if (arr[i].job_major[0] != '\0')
            {
                k = arr[i].job_major;
            }
            else if (arr[i].career_direction[0] != '\0')
            {
                k = arr[i].career_direction;
            }
            else
            {
                k = "未指定";
            }
            consideredTotal++;
            int idx = -1;
            for (int j = 0; j < uniq; j++)
            {
                if (strcmp(keys[j], k) == 0)
                {
                    idx = j;
                    break;
                }
            }
            if (idx == -1)
            {
                strcpy(keys[uniq], k);
                keys[uniq][63] = '\0';
                cnt[uniq] = 1;
                uniq++;
            }
            else
            {
                cnt[idx]++;
            }
        }
        // 根据统计结果输出信息
        if (consideredTotal == 0)
        {
            printf("%d 年没有毕业生记录。\n", year);
        }
        else
        {
            printf("工作专业\t\t人数\t比例(占毕业生)\n");
            for (int j = 0; j < uniq; j++)
            {
                printf("%-24s %-6d %.2f%%\n", keys[j], cnt[j], (double)cnt[j] * 100.0 / consideredTotal);
            }
        }
        break;
    default:
        // 当用户选择的选项无效时，打印错误信息并退出函数
        printf("无效的统计选项!\n");
        Sleep(1000);
        free(arr);
        return;
    }
    // 暂停程序以查看统计结果
    system("pause");
    // 释放之前分配的内存
    free(arr);
}