# Student_management_system
学生管理系统
本次上传了两个版本 一难一易 实现了不同的功能
并且在第一版本内将其分文件编程 并使用makefile 

第一版本：
注意：
1）输出数组元素时，要将学号单独处理，输出为整数（即保留0位小数）。同理，在计算成绩时也要将第1列的学号撇开，只计算第2列之后的。成绩保留1位小数。
2）学生人数n贯穿始终，通过n的值判断当前命令的子函数是否能够调用执行。例如：当n=0时，说明还没有录入成绩。而一旦输入命令T，也即调用Type子函数录入了成绩，则n的值就不再是0。当n！=0时，就可以进行其他的成绩操作，但不能再执行录用成绩的操作。所以当用户输入的命令无法执行时，应当给出提示。

2023.8
重新用链表修改了程序
