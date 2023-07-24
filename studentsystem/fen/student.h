#ifndef STUDENT_H
#define STUDENT_H

#define N 10

typedef struct stu
{
    int num;
    float score[3];
    float ave;
} STU;
STU st[N];
extern int n;

void help();
void type();
void list();
void average();
void sort();
void search();
void add();
void del();
void modify();

#endif // STUDENT_H
