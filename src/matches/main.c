#include "libmatches/logic.h"
#include "libmatches/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Rus");
 srand(time(NULL));
 display();
 char compNum;
 char buf[32];
 int inputNum;
 int key = 2;
 char choice;
 while (1) {
 int count = 100;
 while (count > 0) {
 printf("Осталось спичек: %d\n", count);
 printf("Сколько спичек хотите взять? ");
 fgets(buf, 32, stdin);
 if (sscanf(buf, "%d", &inputNum) != 1) {
 printf("Неправильный ввод\n");
 continue;
 }
 if (check_inputNum(inputNum) == 0) {
 printf("Введите число от одного до десяти\n");
 continue;
 }
 if (check_inputNum2(inputNum, &count) == 0) {
 printf("Введите допустимое значение\n");
 continue;
 }
 printf("Осталось спичек: %d\n", count);
 key = 2;
 if (count > 0) {
 compNum = rand() % 10 + 1;
 if ((count <= 22) && (count >= 13)) {
 compNum = count - 12;
 }
 if ((count <= 11) && (count >= 6)) {
 compNum = count - 1;
 }
 if (check_compNum(compNum, &count) == 0) {
 compNum = rand() % count;
 if (compNum == 0) {
 compNum += 1;
 }
 count -= compNum;
 }
 printf("Компьютер взял: %d\n", compNum);
 key = 1;
 }
 }
 if (key == 1) {
 printf("Вы выиграли !!!!\n");
 } 
 else {
 printf("Вы проиграли :(\n");
 }
 printf("Уходите?(n) Продолжаем?(y)\n");
 scanf("%c%*c", &choice);
 if (choice == 'n' || choice == 'N')
 exit(0);
 if (choice == 'y' || choice == 'Y')
 display();
 }
 return 0;
}
