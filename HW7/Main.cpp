#include "IntegerArray.h"
#include <iostream>
#include <string>

using namespace std;

void test();
void print(IntegerArray& ia);

int main()
{
    setlocale(LC_ALL, "");

    test();

    return 0;
}

void test()
{
    //Test #1: Отрицательный массив
    {
        cout << "Тест №1: Отрицательный массив" << endl;
        try
        {
            IntegerArray arr(-2);
            arr[4];
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение:" << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what();
        }
    }

    //Тест #2: Вне диапазона
    {
        cout << "Тест №2: Вне диапазона" << endl;
        try
        {
            IntegerArray arr(2);
            arr[4];
            arr[0] = 3;
            arr[1] = -8;
            cout << "Arr {" << arr[0] << " , " << arr[1] << "}";
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Тест #3: Простой
    {
        cout << "Тест №3: Простой тест" << endl;
        try
        {
            IntegerArray arr(2);
            arr[0] = 3;
            arr[1] = -8;
            cout << "IntegerArray {" << arr[0] << ", " << arr[1] << "}" << endl << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Index: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Test #4: = InsertBeforeFirst, InsertAfterLast, Search
    {
        cout << "Тест №4: = InsertBeforeFirst, InsertAfterLast, Search." << endl;
        try
        {
            IntegerArray arr(3);

            arr[0] = 3;
            arr[1] = 4;
            arr[2] = -8;

            cout << "arr1 = ";
            print(arr);

            cout << "Попытка копирования" << endl;
            IntegerArray arr2;
            arr2 = arr;
            cout << "arr2 = ";
            print(arr2);

            cout << "Попытка вставить перед первым (arr1)" << endl;
            arr.insertBeforeFirst(10);
            cout << "arr1 = ";
            print(arr);

            cout << "Попытка вставить после последнего (arr2)" << endl;
            arr2.insertAfterLast(100);
            cout << "arr2 = ";
            print(arr2);

            cout << "Попытка получить индекс числа \"-8\" в arr1" << endl;
            int index = arr.search(-8);
            cout << "Индекс числа \"-8\": "
                << ((index == -1) ? "Число не найдено" : to_string(index)) << endl;

            cout << "Попытка получить индекс числа \"43\" в arr2" << endl;
            index = arr2.search(43);
            cout << "Индекс числа \"43\": "
                << ((index == -1) ? "Число не найдено" : to_string(index)) << endl << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Тест #5: InsertBeforeFirst в пустом массиве
    {
        cout << "Тест №5: InsertBeforeFirst \"3\" в пустом массиве" << endl;
        try
        {
            IntegerArray arr;

            arr.insertBeforeFirst(3);
            print(arr);
            cout << "" << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Тест #6: InsertAfterLast в пустом массиве
    {
        cout << "Тест №6: InsertAfterLast \"6\" в пустом массиве" << endl;
        try
        {
            IntegerArray arr;

            arr.insertAfterLast(6);
            print(arr);
            cout << "" << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Тест #7: Копирование(IntegerArray)
    {
        cout << "Тест №7: Копирование" << endl;
        {
            try
            {
                IntegerArray arr(3);

                arr[0] = 3;
                arr[1] = 4;
                arr[2] = -8;

                cout << "arr1 = ";
                print(arr);

                cout << "Попытка копирования" << endl;
                IntegerArray arr2;
                arr2.copy(arr);
                cout << "arr2 = ";
                print(arr2);
                cout << "" << endl;
            }
            catch (bad_range& br)
            {
                cout << br.what() << endl
                    << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                    << "Индекс: " << br.getIndex() << endl;
            }
            catch (bad_length& bl)
            {
                cout << bl.what() << endl
                    << "Значение: " << bl.getLength() << endl << endl;
            }
            catch (exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }

    //Test #8: Поиск (-1)
    {
        cout << "Тест №8: = Поиск индекса элемента \"-1\"" << endl;
        try
        {
            IntegerArray arr(3);

            arr[0] = 3;
            arr[1] = 4;
            arr[2] = -8;

            cout << "arr1 = ";
            print(arr);

            cout << "Попытка получить индекс числа \"-1\" в arr1" << endl;
            int index = arr.search(-1);
            cout << "Индекс числа \"-1\": "
                << ((index == -1) ? "Число \"-1\" не найдено" : to_string(index)) << endl << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Test #9: resize, insertBeforeFirst, insertAfterLast, Search
    {
        cout << "Тест №9: = resize, insertBeforeFirst, insertAfterLast, Search" << endl;
        try
        {
            IntegerArray arr(3);

            arr[0] = 3;
            arr[1] = 4;
            arr[2] = -8;

            cout << "arr1 = ";
            print(arr);

            arr.resize(1);
            cout << "После изменения размера (1) arr1 = ";
            print(arr);

            cout << "Попытка вставить перед первым" << endl;
            arr.insertBeforeFirst(10);
            cout << "arr1 = ";
            print(arr);

            cout << "Попытка вставить после последнего" << endl;
            arr.insertAfterLast(100);
            cout << "arr2 = ";
            print(arr);

            cout << "Попытка получить индекс числа \"-8\" в arr1" << endl;
            int index = arr.search(-8);
            cout << "Индекс числа \"-8\": "
                << ((index == -1) ? "Число не найдено" : to_string(index)) << endl;

            cout << "Попытка получить индекс числа \"-1\" в arr" << endl;
            index = arr.search(-1);
            cout << "Индекс числа \"-1\": "
                << ((index == -1) ? "Число не найдено" : to_string(index)) << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "Диапозон: [0.." << br.getLength() - 1 << "]" << endl
                << "Индекс: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "Значение: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }
}

void print(IntegerArray& ia)
{
    cout << "{ ";
    for (int i = 0; i < ia.getLength() - 1; ++i)
    {
        cout << ia[i] << ", ";
    }
    cout << ia[ia.getLength() - 1] << " }" << endl;
}