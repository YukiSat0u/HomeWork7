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
    //Test #1: ������������� ������
    {
        cout << "���� �1: ������������� ������" << endl;
        try
        {
            IntegerArray arr(-2);
            arr[4];
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������:" << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what();
        }
    }

    //���� #2: ��� ���������
    {
        cout << "���� �2: ��� ���������" << endl;
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
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //���� #3: �������
    {
        cout << "���� �3: ������� ����" << endl;
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
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "Index: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Test #4: = InsertBeforeFirst, InsertAfterLast, Search
    {
        cout << "���� �4: = InsertBeforeFirst, InsertAfterLast, Search." << endl;
        try
        {
            IntegerArray arr(3);

            arr[0] = 3;
            arr[1] = 4;
            arr[2] = -8;

            cout << "arr1 = ";
            print(arr);

            cout << "������� �����������" << endl;
            IntegerArray arr2;
            arr2 = arr;
            cout << "arr2 = ";
            print(arr2);

            cout << "������� �������� ����� ������ (arr1)" << endl;
            arr.insertBeforeFirst(10);
            cout << "arr1 = ";
            print(arr);

            cout << "������� �������� ����� ���������� (arr2)" << endl;
            arr2.insertAfterLast(100);
            cout << "arr2 = ";
            print(arr2);

            cout << "������� �������� ������ ����� \"-8\" � arr1" << endl;
            int index = arr.search(-8);
            cout << "������ ����� \"-8\": "
                << ((index == -1) ? "����� �� �������" : to_string(index)) << endl;

            cout << "������� �������� ������ ����� \"43\" � arr2" << endl;
            index = arr2.search(43);
            cout << "������ ����� \"43\": "
                << ((index == -1) ? "����� �� �������" : to_string(index)) << endl << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //���� #5: InsertBeforeFirst � ������ �������
    {
        cout << "���� �5: InsertBeforeFirst \"3\" � ������ �������" << endl;
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
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //���� #6: InsertAfterLast � ������ �������
    {
        cout << "���� �6: InsertAfterLast \"6\" � ������ �������" << endl;
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
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //���� #7: �����������(IntegerArray)
    {
        cout << "���� �7: �����������" << endl;
        {
            try
            {
                IntegerArray arr(3);

                arr[0] = 3;
                arr[1] = 4;
                arr[2] = -8;

                cout << "arr1 = ";
                print(arr);

                cout << "������� �����������" << endl;
                IntegerArray arr2;
                arr2.copy(arr);
                cout << "arr2 = ";
                print(arr2);
                cout << "" << endl;
            }
            catch (bad_range& br)
            {
                cout << br.what() << endl
                    << "��������: [0.." << br.getLength() - 1 << "]" << endl
                    << "������: " << br.getIndex() << endl;
            }
            catch (bad_length& bl)
            {
                cout << bl.what() << endl
                    << "��������: " << bl.getLength() << endl << endl;
            }
            catch (exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }

    //Test #8: ����� (-1)
    {
        cout << "���� �8: = ����� ������� �������� \"-1\"" << endl;
        try
        {
            IntegerArray arr(3);

            arr[0] = 3;
            arr[1] = 4;
            arr[2] = -8;

            cout << "arr1 = ";
            print(arr);

            cout << "������� �������� ������ ����� \"-1\" � arr1" << endl;
            int index = arr.search(-1);
            cout << "������ ����� \"-1\": "
                << ((index == -1) ? "����� \"-1\" �� �������" : to_string(index)) << endl << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl << endl;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    //Test #9: resize, insertBeforeFirst, insertAfterLast, Search
    {
        cout << "���� �9: = resize, insertBeforeFirst, insertAfterLast, Search" << endl;
        try
        {
            IntegerArray arr(3);

            arr[0] = 3;
            arr[1] = 4;
            arr[2] = -8;

            cout << "arr1 = ";
            print(arr);

            arr.resize(1);
            cout << "����� ��������� ������� (1) arr1 = ";
            print(arr);

            cout << "������� �������� ����� ������" << endl;
            arr.insertBeforeFirst(10);
            cout << "arr1 = ";
            print(arr);

            cout << "������� �������� ����� ����������" << endl;
            arr.insertAfterLast(100);
            cout << "arr2 = ";
            print(arr);

            cout << "������� �������� ������ ����� \"-8\" � arr1" << endl;
            int index = arr.search(-8);
            cout << "������ ����� \"-8\": "
                << ((index == -1) ? "����� �� �������" : to_string(index)) << endl;

            cout << "������� �������� ������ ����� \"-1\" � arr" << endl;
            index = arr.search(-1);
            cout << "������ ����� \"-1\": "
                << ((index == -1) ? "����� �� �������" : to_string(index)) << endl;
        }
        catch (bad_range& br)
        {
            cout << br.what() << endl
                << "��������: [0.." << br.getLength() - 1 << "]" << endl
                << "������: " << br.getIndex() << endl;
        }
        catch (bad_length& bl)
        {
            cout << bl.what() << endl
                << "��������: " << bl.getLength() << endl << endl;
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