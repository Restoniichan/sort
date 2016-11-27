#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Подключаем свои заголовочные файлы
#include "srt_tools.h"
#include "srt_bubble.h"
#include "srt_insert.h"
#include "srt_quick.h"

int main(int argc, char **argv) {
    //Проверка на корректность ввода аргументов
    if(argc > 3) {
        printf("Incorrect input! There must be 2 arguments.\n");
        return 0;
    }

    int n, i, *str_len, strs_amnt, srt_mth;
    char cur;
    FILE *fl_inp;
    char **strs;

    n = atoi(argv[1]);
    fl_inp = fopen(argv[2], "r");
    //Проверка на существование файла со строками
    if(fl_inp == NULL) {
        printf("No such file in directory!\n");
        return 0;
    }

    //Здесь узнаём реальное кол-во строк для сортировки
    strs_amnt=0;
    do {
        cur = fgetc(fl_inp);
        if(cur == '\n')
            ++strs_amnt;
    } while(cur != EOF && strs_amnt<n);

    //Заводим массивы длин строк и самих строк
    str_len = (int*)malloc(sizeof(int)*strs_amnt);
    strs = (char**)malloc(sizeof(char*)*strs_amnt);
    rewind(fl_inp);

    //Узнаём длины строк
    i=0;
    str_len[0] = 0;
    do {
        cur = fgetc(fl_inp);
        if(cur != '\n')
            ++str_len[i];
        else {
            strs[i] = (char*)malloc(sizeof(char)*(str_len[i]+1));
            ++i;
            if(i != strs_amnt)
                str_len[i] = 0;
        }
    } while(cur != EOF && i < strs_amnt);
    rewind(fl_inp);

    //Записываем строки в массив
    for(i = 0; i < strs_amnt; ++i) {
        fgets(strs[i], str_len[i]+1, fl_inp);
        cur = getc(fl_inp);
    }
    fclose(fl_inp);

    //Выбираем метод сортировки
    printf("Please, choose sort method (1. Bubble, 2. Insert, 3. Quick): ");
    scanf("%d", &srt_mth);
    switch(srt_mth) {
    case 1:
        printf("Bubble choosed.\n");
        srt_bubble(strs, strs_amnt);
        break;
    case 2:
        printf("Insert choosed.\n");
        srt_insert(strs, strs_amnt);
        break;

    case 3:
        printf("Quick choosed.\n");
        srt_quick(strs, 0, strs_amnt-1);
        break;
    default:
        printf("Incorrect input. Default choosed (Quick).\n");
        srt_quick(strs, 0, strs_amnt-1);

    }

    //Вывод отсортированного массива
    printf("Here's your sorted array:\n");
    for(i = 0; i < strs_amnt; ++i) {
        //printf("%d) %s\n", i+1, strs[i]);
        free(strs[i]);
    }
    free(strs);
    free(str_len);

    return 0;
}
