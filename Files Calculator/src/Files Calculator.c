/*
 ============================================================================
 Name        : Files.c
 Author      : Ilya Buzuev
 Version     : 3.0
 Copyright   : 
 Description : Для работы калькулятора необходимо записать значения в входной файл
               Например: (+ v 3 1 2 3 1 2 3)
               Для 's':
               '+' - "Сложение";
               '-' - "Вычитание";
               '*' - "Умножение";
               '/' - "Деление";
               '^' - "Возведение в степень";
               '!' - "Факториал".
               Для 'v':
               '+' - сложение векторов, '-' - вычитание векторов, '*' - скалярное произведение векторов
               Повторный запуск программы:
               1 - да;
               0 - нет;
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    // Указатель для работы с файлами
    FILE *inputValues, *outputValues;
    // Переменная для ввода пути с клавиатуры к входному файлу
    char path[256];
    // Переменная для ввода пути с клавиатуры к выходному файлу
    char pathToOutputValues[256];
    // Переменные для получения символов для работы с операциями
    char operation, symbol;
    // Переменные для получения и записи значений из файла
    float firstValue, secondValue, result;
    // Переменная для факториала и степени
    int n;
    // Переменные для работы с длинной и индексами массива
    int size, index;
    // Переменные для обозначения массивов
    int *str1, *str2, *str3, res = 0;
    // Переменная для рестарта
    int restart;

    do
    {
        // Пишем путь для того, чтобы открыть файл с входными значениями
        puts("Enter the path to open the file with input values. (Example: D:\\inputValues.txt): ");
        scanf("%s", path);
        // Переменная для того, чтобы открывать файл для чтения значений, который указали выше
        inputValues = fopen(path, "r");
        // Пишем путь для того, чтобы открыть файл с выходными значениями
        puts("Enter the path to open the file with output values. (Example: D:\\outputValues.txt): ");
        scanf("%s", pathToOutputValues);
        // Переменная для того, чтобы открывать файл для записи значений, который указали выше
        outputValues = fopen(pathToOutputValues, "w");

        // Проверка для того, чтобы узнать верно ли введен путь к файлам, если "Error!", то путь указан неверно
        if ((inputValues == NULL) || outputValues == NULL)
        {
            puts("Error: Invalid file path!");
        }

        // Получаем символ(+, -, *, /, ^, !) из файла ввходных значений
        fscanf(inputValues, "%c ", &symbol);
        // Получаем символ операции(s, v) из файла ввходных значений
        fscanf(inputValues, "%c ", &operation);

        if ((symbol == '+') && (operation == 's'))
        {
            puts("+, s\nCalculating ...\nCheck the output file");
            fscanf(inputValues, "%f", &firstValue);
            fprintf(outputValues, "%f ", firstValue);
            fscanf(inputValues, "%f", &secondValue);
            fprintf(outputValues, "+ %f", secondValue);
            fprintf(outputValues, " = %f", firstValue + secondValue);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '-') && (operation == 's'))
        {
            puts("-, s\nCalculating ...\nCheck the output file");
            fscanf(inputValues, "%f", &firstValue);
            fprintf(outputValues, "%f ", firstValue);
            fscanf(inputValues, "%f", &secondValue);
            fprintf(outputValues, "- %f", secondValue);
            fprintf(outputValues, " = %f", firstValue - secondValue);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '*') && (operation == 's'))
        {
            puts("*, s\nCalculating ...\nCheck the output file");
            fscanf(inputValues, "%f", &firstValue);
            fprintf(outputValues, "%f ", firstValue);
            fscanf(inputValues, "%f", &secondValue);
            fprintf(outputValues, "* %f", secondValue);
            fprintf(outputValues, " = %f", firstValue * secondValue);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '/') && (operation == 's'))
        {
            puts("/, s\nCalculating ...\nCheck the output file");
            fscanf(inputValues, "%f", &firstValue);
            fprintf(outputValues, "%f ", firstValue);
            fscanf(inputValues, "%f", &secondValue);
            fprintf(outputValues, "/ %f", secondValue);
            if (secondValue == 0)
            {
                fprintf(outputValues, " - Error!");
            }
            else
            {
                fprintf(outputValues, " = %f", firstValue / secondValue);
            }
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '^') && (operation == 's'))
        {
            puts("^, s\nCalculating ...\nCheck the output file");
            fscanf(inputValues, "%f", &firstValue);
            fprintf(outputValues, "%f ", firstValue);
            fscanf(inputValues, "%d", &n);
            fprintf(outputValues, "^ %d", n);
            result = 1;
            // Цикл, который будет длиться до того момента, пока 'n' больше '0' и с каждым разом 'result' будет увеличиваться
            for (; n > 0; n--)
            {
                result *= firstValue;
            }
            fprintf(outputValues, " = %f", result);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '!') && (operation == 's'))
        {
            puts("!, s\nCalculating ...\nCheck the output file");
            fscanf(inputValues, "%f", &firstValue);
            fprintf(outputValues, "%f", firstValue);
            fprintf(outputValues, "!");
            if (firstValue == 0)
            {
                fprintf(outputValues, " = %f", firstValue + 1);
            }
            else
            {
                result = 1;
                // Цикл, который каждый раз умножает 'result' на увеличенное значение 'n' до того момента, пока 'n' <= 'firstValue'
                for (n = 1; n <= firstValue; n++)
                {
                    result *= n;
                }
                fprintf(outputValues, " = %f", result);
            }
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '+') && (operation == 'v'))
        {
            puts("+, v\nCalculating ...\nCheck the output file");
            // Считывание длины векторов
            fscanf(inputValues, "%d ", &size);
            // Выделение памяти для первого вектора
            str1 = malloc(size*sizeof(int));
            fprintf(outputValues, "(");
            // Цикл, который сохраняет значения первого вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений первого вектора
                fscanf(inputValues, "%d", &str1[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues, "%d ", str1[index]);
                }
                else
                {
                    fprintf(outputValues, "%d)", str1[index]);
                }
            }
            fprintf(outputValues, " + ");
            // Выделение памяти для второго вектора
            str2 = malloc(size*sizeof(int));
            fprintf(outputValues, "(");
            // Цикл, который сохраняет значения второго вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений второго вектора
                fscanf(inputValues, "%d", &str2[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues, "%d ", str2[index]);
                }
                else
                {
                    fprintf(outputValues, "%d)", str2[index]);
                }
            }
            fprintf(outputValues, " = ");
            fprintf(outputValues, "(");
            // Цикл, который по очереди складывает значения, которые находятся в определенном индексе массива
            for (index = 0; index < size; index++)
            {
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues ,"%d ", str1[index] + str2[index]);
                }
                else
                {
                    fprintf(outputValues ,"%d)", str1[index] + str2[index]);
                }
            }
            // Освобождене памяти первого массива
            free(str1);
            // Освобождене памяти второго массива
            free(str2);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '-') && (operation == 'v'))
        {
            puts("-, v\nCalculating ...\nCheck the output file");
            // Считывание длины первого вектора
            fscanf(inputValues, "%d ", &size);
            // Выделение памяти для первого вектора
            str1 = malloc(size*sizeof(int));
            fprintf(outputValues, "(");
            // Цикл, который сохраняет значения первого вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений первого вектора
                fscanf(inputValues, "%d", &str1[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues, "%d ", str1[index]);
                }
                else
                {
                    fprintf(outputValues, "%d)", str1[index]);
                }
            }
            fprintf(outputValues, " - ");
            // Выделение памяти для второго вектора
            str2 = malloc(size*sizeof(int));
            fprintf(outputValues, "(");
            // Цикл, который сохраняет значения второго вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений второго вектора
                fscanf(inputValues, "%d", &str2[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues, "%d ", str2[index]);
                }
                else
                {
                    fprintf(outputValues, "%d)", str2[index]);
                }
            }
            fprintf(outputValues, " = ");
            fprintf(outputValues, "(");
            // Цикл, который по очереди складывает значения, которые находятся в определенном индексе массива
            for (index = 0; index < size; index++)
            {
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues ,"%d ", str1[index] - str2[index]);
                }
                else
                {
                    fprintf(outputValues ,"%d)", str1[index] - str2[index]);
                }
            }
            // Освобождене памяти первого массива
            free(str1);
            // Освобождене памяти второго массива
            free(str2);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        if ((symbol == '*') && (operation == 'v'))
        {
            puts("*, v\nCalculating ...\nCheck the output file");
            // Считывание длины первого вектора
            fscanf(inputValues, "%d ", &size);
            // Выделение памяти для первого вектора
            str1 = malloc(size*sizeof(int));
            fprintf(outputValues, "(");
            // Цикл, который сохраняет значения первого вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений первого вектора
                fscanf(inputValues, "%d", &str1[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues, "%d ", str1[index]);
                }
                else
                {
                    fprintf(outputValues, "%d)", str1[index]);
                }
            }
            fprintf(outputValues, " * ");
            // Выделение памяти для второго вектора
            str2 = malloc(size*sizeof(int));
            fprintf(outputValues, "(");
            // Цикл, который сохраняет значения второго вектора в выделенную память(в массив)
            for (index = 0; index < size; index++)
            {
                // Считывание значений второго вектора
                fscanf(inputValues, "%d", &str2[index]);
                //Проверка для того, чтобы не было пробела после последнего считанного значения
                if (index != size - 1)
                {
                    fprintf(outputValues, "%d ", str2[index]);
                }
                else
                {
                    fprintf(outputValues, "%d)", str2[index]);
                }
            }
            fprintf(outputValues, " = ");
            str3 = malloc(size*sizeof(int));
            // Цикл, который по очереди умножает значения, которые находятся в определенном индексе массива,
            // а затем в переменную 'res' записывается сумма самой перменной 'res' и значений индексов
            for (index = 0; index < size; index++)
            {
                str3[index] = str1[index] * str2[index];
                res += str3[index];
            }
            fprintf(outputValues, "%d", res);
            // Освобождене памяти первого массива
            free(str1);
            // Освобождене памяти второго массива
            free(str2);
            // Освобождене памяти третьего массива
            free(str3);
            // Закрытие входного файла
            fclose(outputValues);
            // Закрытие выходного файла
            fclose(inputValues);
        }
        puts("Restart? 1/0: 1 - Yes, 0 - No");
        scanf("%d", &restart);
    }
    while (restart != 0);
}
