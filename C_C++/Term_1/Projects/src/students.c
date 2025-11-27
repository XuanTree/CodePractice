#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "uiDraw.h"
#define MaxSize 2000
struct Date
{
    int year;
    int month;
    int day;
};
struct GraduateInfo
{
    char student_id[20];     
    char name[30];           
    char gender;
    struct Date birth_date;
    int enrollment_year;
    int graduation_year;
    char education_level[20];
    char major[50];
    char career_direction[30];
    char employer[100];
    char job_major[50];
};//想着搞指针传参来着,但传来传去最后出Bug了...遂全用Void(-_-)
int ImportEmploymentData()
{
    system("cls");
    FILE *fp = NULL;
    FILE *bp = NULL;
    struct GraduateInfo graduate[MaxSize];
    int count = 0;
    fp = fopen("StudentsList.txt","r");
    if (fp == NULL)
    {
        printf("文件未找到!\n");
        Sleep(2000);
        return 1;
    }
    while(count < MaxSize && 
        fscanf(fp, "%s %s %c %d %d %d %d %d %s %s %s %s %s", 
                graduate[count].student_id, 
                graduate[count].name, 
                &graduate[count].gender, 
                &graduate[count].birth_date.year, 
                &graduate[count].birth_date.month, 
                &graduate[count].birth_date.day, 
                &graduate[count].enrollment_year, 
                &graduate[count].graduation_year, 
                graduate[count].education_level, 
                graduate[count].major, 
                graduate[count].career_direction, 
                graduate[count].employer, 
                graduate[count].job_major) == 13)
    {
        //对学号进行查重工作
        int isDuplicateID = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcmp(graduate[i].student_id,graduate[count].student_id) == 0)
            {
                isDuplicateID = 1;
                break;
            }
        }
        if (isDuplicateID)
        {
            printf("发现重复学号: %s , 将跳过此条记录...\n", graduate[count].student_id);
            Sleep(800);
            continue;
        }
        count++;
    }
    fclose(fp);
    printf("\n %d 条数据已成功添加!\n", count);
    //生成二进制文件
    bp = fopen("students.dat", "wb");
    if (bp == NULL)
    {
        printf("未能打开二进制文件并进行写入!\n");
        Sleep(2000);
        return 1;
    }
    //写入数据
    for (int i = 0; i < count; i++)
    {
        fwrite(&graduate[i], sizeof(struct GraduateInfo),1,bp);
    }
    fclose(bp);
    printf("\n %d  条记录已写入students.dat.\n\n", count);
    system("pause");
    return count;
}
void ViewEmploymentData(int count)
{
    system("cls");
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        if (count == 0) {
            printf("当前系统无毕业生信息!\n");
        } else {
            printf("未找到students.dat!\n");
        }
        system("pause");
        return;
    }
    struct GraduateInfo student;
    int records = 0;
    while (fread(&student, sizeof(struct GraduateInfo), 1, fp))
    {
        printf("%s\t%s\t%c\t%d-%02d-%02d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n",
                student.student_id,
                student.name,
                student.gender,
                student.birth_date.year,
                student.birth_date.month,
                student.birth_date.day,
                student.enrollment_year,
                student.graduation_year,
                student.education_level,
                student.major,
                student.career_direction,
                student.employer,
                student.job_major);
        records++;
    }
    fclose(fp);
    if (records == 0) {
        printf("当前系统无毕业生信息!\n");
    }
    printf("\n");system("pause");
    return;
}
void SearchEmploymentData(int option)
{
    system("cls");
    char message[MaxSize];
    struct GraduateInfo student;
    int found;
    int continue_research = 1;
    FILE *fp;
    while(continue_research)
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
                printf("\n请输入学号:");
                scanf("%s", message);
                break;
            case 2:
                printf("\n请输入姓名:");
                scanf("%s", message);
                break;
            default:
                printf("\n无效的搜索选项。\n");
                fclose(fp);
                system("pause");
                return;
        }
        found = 0;
        while (fread(&student, sizeof(struct GraduateInfo), 1, fp))
        {
            switch (option)
            {
                case 1:
                    if (strcmp(student.student_id, message) == 0)
                    {
                        found = 1;
                        printf("\n%s\t%s\t%c\t%d-%02d-%02d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n",
                                student.student_id,
                                student.name,
                                student.gender,
                                student.birth_date.year,
                                student.birth_date.month,
                                student.birth_date.day,
                                student.enrollment_year,
                                student.graduation_year,
                                student.education_level,
                                student.major,
                                student.career_direction,
                                student.employer,
                                student.job_major);
                        break; // 找到匹配的记录后立即跳出循环
                    }
                    break;
                case 2:
                    if (strcmp(student.name, message) == 0)
                    {
                        found = 1;
                        printf("\n%s\t%s\t%c\t%d-%02d-%02d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n",
                                student.student_id,
                                student.name,
                                student.gender,
                                student.birth_date.year,
                                student.birth_date.month,
                                student.birth_date.day,
                                student.enrollment_year,
                                student.graduation_year,
                                student.education_level,
                                student.major,
                                student.career_direction,
                                student.employer,
                                student.job_major);
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
        if (!found)
        {
            printf("\n未找到匹配的记录。\n");
        }
        fclose(fp);
        printf("\n是否继续搜索?(y/n): ");
        char choice;
        scanf(" %c", &choice); //空格用于跳过之前的换行符
        
        if (choice != 'y' && choice != 'Y')
        {
            continue_research = 0; // 用户选择不继续搜索
        }
    }
    printf("\n");
    system("pause");
    return;
}
void AddEmploymentData()
{
    system("cls");
    struct GraduateInfo newGraduate;
    printf("请输入新毕业生的信息:\n");
    printf("学号: ");
    scanf("%s", newGraduate.student_id);
    printf("姓名: ");
    scanf("%s", newGraduate.name);
    printf("性别: ");
    scanf(" %c", &newGraduate.gender); //空格用于跳过之前的换行符
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
    printf("就业单位: ");
    scanf("%s", newGraduate.employer);
    printf("工作专业: ");
    scanf("%s", newGraduate.job_major);
    // 检查学号是否重复
    FILE *fp = fopen("students.dat", "rb");
    if (fp != NULL) {
        int count = 0;
        struct GraduateInfo graduate;
        while (fread(&graduate, sizeof(struct GraduateInfo), 1, fp)) {
            if (strcmp(graduate.student_id, newGraduate.student_id) == 0) {
                printf("发现重复学号: %s , 将跳过此条记录...\n", newGraduate.student_id);
                fclose(fp);
                system("pause");
                return;
            }
            count++;
        }
        fclose(fp);
    }
    // 以追加模式打开.dat文件
    FILE *bp = fopen("students.dat", "ab");
    if (bp == NULL) {
        printf("未能打开二进制文件并进行写入!\n");
        system("pause");
        return;
    }
    // 写入新的毕业生信息
    fwrite(&newGraduate, sizeof(struct GraduateInfo), 1, bp);
    fclose(bp);
    printf("\n新数据已成功添加!\n");
    system("pause");
    return;
}
void DeleteEmploymentData(int count)
{
    system("cls");
    if(count == 0)
    {
        printf("当前系统无毕业生信息!\n");
        system("pause");
        return;
    }
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
    struct GraduateInfo student;
    struct GraduateInfo students[MaxSize];
    // 读取所有学生信息
    int index = 0;
    while (fread(&students[index], sizeof(struct GraduateInfo), 1, fp))
    {
        if (strcmp(students[index].student_id, message) == 0 || strcmp(students[index].name, message) == 0)
        {
            printf("\n找到的学生信息:\n");
            printf("%s\t%s\t%c\t%d-%02d-%02d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n",
                students[index].student_id,
                students[index].name,
                students[index].gender,
                students[index].birth_date.year,
                students[index].birth_date.month,
                students[index].birth_date.day,
                students[index].enrollment_year,
                students[index].graduation_year,
                students[index].education_level,
                students[index].major,
                students[index].career_direction,
                students[index].employer,
                students[index].job_major);
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
                fwrite(&students[i], sizeof(struct GraduateInfo), 1, bp);
            }
        }
        fclose(bp);
        printf("\n该学生信息已成功删除!\n");
    }
    system("pause");
    return;
}
void ChangeEmploymentData(int count)
{
    system("cls");
    if(count == 0)
    {
        printf("当前系统无毕业生信息!\n");
        system("pause");
        return;
    }
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
    struct GraduateInfo students[MaxSize];
    // 读取所有学生信息
    int index = 0;
    while (fread(&students[index], sizeof(struct GraduateInfo), 1, fp))
    {
        if (strcmp(students[index].student_id, message) == 0 || strcmp(students[index].name, message) == 0)
        {
            printf("\n找到的学生信息:\n");
            printf("%s\t%s\t%c\t%d-%02d-%02d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n",
                students[index].student_id,
                students[index].name,
                students[index].gender,
                students[index].birth_date.year,
                students[index].birth_date.month,
                students[index].birth_date.day,
                students[index].enrollment_year,
                students[index].graduation_year,
                students[index].education_level,
                students[index].major,
                students[index].career_direction,
                students[index].employer,
                students[index].job_major);
            char stringData[30];
            char sex;
            int intData,intYear,intMonth,intDay;
            int choice = ShowWhichInfo();
            switch(choice)
            {
                case 1:
                    scanf("%s",stringData);
                    strcpy(students[index].student_id, stringData);
                    break;
                case 2:
                    scanf("%s",stringData);
                    strcpy(students[index].name, stringData);
                    break;
                case 3:
                    scanf("%c",&sex);
                    students[index].gender = sex;
                    break;
                case 4:
                    scanf("%d %d %d",&intYear,&intMonth,&intDay);
                    students[index].birth_date.year = intYear;
                    students[index].birth_date.month = intMonth;
                    students[index].birth_date.day = intDay;
                    break;
                case 5:
                    scanf("%d",&intData);
                    students[index].enrollment_year = intData;
                    break;
                case 6:
                    scanf("%d",&intData);
                    students[index].graduation_year = intData;
                    break;
                case 7: 
                    scanf("%s",stringData);
                    strcpy(students[index].major, stringData);
                    break;
                case 8:
                    scanf("%s",stringData);
                    strcpy(students[index].career_direction, stringData);
                    break;
                case 9:
                    scanf("%s",stringData);
                    strcpy(students[index].employer, stringData);
                    break;
                case 10:
                    scanf("%s",stringData);
                    strcpy(students[index].job_major, stringData);
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
    if (bp == NULL) {
        printf("未能打开二进制文件并进行写入!\n");
        system("pause");
        return;
    }
    // 修改新的毕业生信息
    for (int i = 0; i < index; i++)
    {
        fwrite(&students[i], sizeof(struct GraduateInfo), 1, bp);
    }
    fclose(bp);
    printf("数据修改成功!\n");
    Sleep(2000);
    return;
}