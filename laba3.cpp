// laba3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void show(char arr[], int length) // вывод массива
{
	cout << "Вывод текса: ";
	int count = 0;
	if (length < 1) { cout << "Пустой массив" << endl; return; }
	while (arr[count] == ' ') count++;
	for (int i = count; i < length; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
int arrread(char arr[])  // заполнение массива
{
	cout << "Заполнение массива" << endl;
	char c='a';
	int count=0;
	c = cin.get();
	while ((c == ' ') || c == '\n') c = cin.get();
		while (c != '.')
		{
			if (count > 9999) { cout << "слишком большой текст" << endl; return 9999; }
			if (c == '\n') c = ' ';
			if ((c==' ') && (arr[count-1]==' ')) c = cin.get();
			if (((c>96) && (c<123)) || (c==32)) {
				arr[count] = c;
				count++;
				c = cin.get();
				if (c == '.') break;
				}
			if ((c != 32) && ((c < 97) || (c > 122))) {
				if (c == '.') { break; }
				c = cin.get();
			}
		}
	return count;
}
void task(char arr[], int length) // задание
{
	cout << "Выполенние задачи" << endl;
	char c;
	int count = 0, key = 0;
	while (arr[count] == ' ') { count++; }
	c = arr[count];
	while (count<=length) //цикл вывода элементов
	{
		key =0; // ключ для проверки отсутсвия слов с только букв "о" и "а"
		if (arr[count] != c) 
		{
			
			while (arr[count] != ' ')
			{
				if (count >= length) break;
				if ((arr[count] != 'a') && (arr[count] != 'o')) // невывод букв о или а
				{
					cout << arr[count];
					key++;
				}
				count++;
			}
			count++;
			if (key > 0) cout << " "; // пробел между словами
		}
		else
		{
			
			while (arr[count] != ' ')
			{	
				if (count >= length) break;
				count++;
			}
			count++;
		}
		
	}
	cout << endl;
}

struct List // двосвязный список
{
	char c;
	List *prev;
	List *next;
};
List *Begin = NULL; // первый елемент списка
List *End = NULL; // последний елемент списка
int legth = 0; // количество элементов в списке


List* fill(List* t) // считывание + создание списка
{
	cout << "Заполнение списка" << endl;
	Begin = t;
	char ch=' ';
	int count = 0;
	List* p=t;

	while (ch != '.')
	{
		ch = cin.get();
		if (((ch > 96) && (ch < 123)) || (ch == 32) || (ch == '\n')) // фильтр на только маленькие буквы алфавита и пробелы
		{
			if (ch == '\n')  {ch = ' ';}  
			{p = t;
			t->next = new List; // создание нового элемента
			t->c = ch; //запись значение
			t = t->next; // переход на новый элемент
			t->prev = p;
			t->next = NULL;
			legth++;
			}
		}
	}
	p->next = NULL;
	End = p;
	List * n = Begin;
	while (n->c == ' ') // удаление пробелов в начале списка" "
	{
		if (n == End) break;
		n = n->next;
		legth--;
	}
	p = n;
	p->prev = NULL;
	Begin = p;
	while (n->prev != NULL)
	{
		p = n;
		delete n;
		n = p->prev;
		legth--;
	}
	//List* l=Begin;
	p = Begin;
	n = Begin;
	List*l;
	while (p != End) // удаление повторяющихся пробелов" "
	{
		p = p->next;
		if ((p->c == ' ') && (n->c==' '))
		{
			n->next = p->next;
			l = p;
			p = p->next;
			p->prev = n;
			delete l;
			n=p;
		}
		n = p;
	}
	return Begin;
}



void show(List *t) // вывод списка
{
	cout << "Вывод списка: ";
	while (t->next!=NULL)
	{
		cout << t->c;
		t = t->next;
	}
	cout << t->c << endl;
}

void destroy() // удаление списка
{
	cout << "Удаление списка" << endl;
	List* p = End;
	while (End!=Begin)
	{
		//cout << End->c;
		End = End->prev;
		delete p;
		p = End;
	}
	End = NULL;
	Begin = NULL;
}

List* deletElem(List *t, int l) // удаление элемента
{
	int flag = 1;
	if ((l == 1) && (Begin->next == NULL)) //удаление единственного элемента
	{
		Begin->c = '\0';
		legth--;
		return Begin;
	}
	if (l == 1) //удалеие первого
	{
		Begin = t->next;
		Begin->prev = NULL;
		//delete t;
		return Begin;
	}
	if (l == legth) // удаление последнего
	{
		t = End;
		End = t->prev;
		End->next = NULL;
		//delete t;
		legth--;
		return Begin;
	}
	
	while (l != flag) // удаление
	{
		t = t->next;
		flag++;
	}
	if ((t->prev->c == ' ') && (t->next->c == ' ')) // удаление нескольки пробелов которые могли появится из-за удаления символа
	{
		Begin=deletElem(Begin, l + 1);
	}
	List* n = t;
	List *p = t->prev;
	t = t->next;
	t->prev=p;
	p->next = t;
	delete n;
	legth--;
	return Begin;
}
List* AddElem(List *t, char c, int l) // добавление элемента
{
	int flag = 0;
	List* n = t;
	List *p = t;
	if (l == 0) // добавление на 0 место
	{
		Begin = new List;
		Begin->prev = NULL;
		Begin->next = n;
		Begin->c = c;
		n->prev = Begin;
		legth++;
		return Begin;
	}
	if (l == legth)// добавление на последние место
	{
		n = new List;
		n->next = NULL;
		n->c = c;
		n->prev = End;
		End->next = n;
		End = End->next;
		legth++;
		return Begin;
	}

	while (l != flag) // добавление на слечайное место
	{
		t = t->next;
		flag++;
	}
	n = new List;
	p = t->prev;
	n->c = c;
	n->next = t;
	n->prev = p;
	p->next = n;
	t->prev = n;
	legth++;
	return Begin;
}

List* DeleteOA(List* t)
{
	int i = 1;
	List* n = t;
	List* p = t;
	while ((Begin->c == 'a') || (Begin->c == 'o') || Begin->c == ' ')
	{
		if (Begin->next == NULL)
		{
			legth--;
			Begin->c ='\0';
			return Begin;
		}
		p = Begin;
		Begin = Begin->next;
		legth--;
		Begin->prev = NULL;
		delete p;
	}
	//show(Begin);
	t = Begin;
	t = t->next;
	i++;
//	cout << t->c << " " << i << " " << legth << endl;
	while (i<=legth)
	{
	//	cout << t->c << " " << i << " " << legth << endl;
		if ((t->c == 'a') || (t->c == 'o'))
		{
			
			if (t->next == NULL)
			{
				End = End->prev;
				t = t->next;
				delete t;
				legth--;
				legth--;
				End->next = NULL;
				return Begin;
			}
			else
			{
				n = t->next;
				p = t->prev;
				delete t;
				legth--;
				n->prev = p;
				p->next = n;
				t = n;
			}

		}
		else
		{
			t = t->next;
			i++;
		}
	}
	return Begin;
}

List* DeleteProbel(List* t)
{
	List*n = t;
	List*p = t;
	while (t->next != NULL)
	{
		t = t->next;
		if ((t->next == NULL) && (t->c == ' '))
		{
			while (t->c == ' ')
			{
				End = t->prev;
				End->next = NULL;
				legth--;
				delete t;
				t = End;
			}
			return Begin;
		}
		if ((t->c == ' ') && (p->c == ' '))
		{
			n = t->next;
			n->prev = p;
			p->next = n;
			legth--;
			delete t;
			t = p;
		}
		p = t;
	}
	return Begin;
}
int findprobel(List*t)
{
	int l=0;
	while (t != NULL)
	{
		if (t->c == ' ')
		{
			return l;
		}
		l++;
		t = t->next;
	}
	return l;
}
void showwords(List* t)
{
	char firstch;
	int i = 1;
	firstch = t->c;
	List* n = t;
	while ((t->c != ' ') && (i<legth) && (t->next!=NULL))
	{
		i++;
		t = t->next;
	}
	//cout << t->c << endl;
	if (t->next == NULL) 
	{
		cout << endl;
		return;
	}
	t = t->next;
	i++;
	while (i<=legth)
	{
		//cout << t->c << endl;
		if (t->c != firstch)
		{
			
			while ((t->c != ' ') && (i<=legth))
			{
				i++;
				cout << t->c;
				if (t->next == NULL)
				{
					cout << endl; 
					return;
				}
				t = t->next;
				
			}
			cout << " ";
		}
		else
		{
			while ((t->c != ' ') && (i <= legth))
			{
				i++;
				if (t->next == NULL)
				{
					cout << endl;
					return;
				}
				t = t->next;
			}
		}
		if (t->next == NULL)
		{
			cout << endl;
			return;
		}
		t = t->next;
		i++;
	}
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	char arr[10000];
	int length=0;
	int flag = 1;
	int chose1=0, chose2=0, chose3=0;
	char ch3;
	int number=0;
	while (flag == 1)
	{
		cout << "Выберите действие:" << endl;
		cout << "1.Ввести новые данные" << endl;
		cout << "2.Закончить работу" << endl;
		cin >> chose1;
		if (chose1 == 2) { flag = 0; break; }
		if (chose1 == 1)
		{
			cout << "Выберите способ записи" << endl;
			cout << "1.Массив" << endl;
			cout << "2.Список" << endl;
			cout << "3.Выход" << endl;
			cin >> chose2;
			if (chose2 == 1) 
			{
				length = arrread(arr);
				show(arr, length);
				cout << "Слова без букв о, а и которые начинаются на первую букву первого слова" << endl;
				task(arr, length);
			}
			if (chose2 == 2)
			{
				
				List* work = new List;
				work->c = ' ';
				work = fill(work);
				show(work);
				while (chose3 != 4)
				{
					cout << "Выберите действие со списком" << endl;
					cout << "1.Вставить элемент на место под нормером (пробелы учитываются)" << endl;
					cout << "2.Удалить элемент пол номером (пробелы учитываются)" << endl;
					cout << "3.Вывести все слова которые начинаются на букву отличной от первой буквы первого слова текста, удалив при этом все вхождение о и а" << endl;
					cout << "4.Закончить работу" << endl;
					cout << "5.Доп" << endl;
					cin >> chose3;


					if (chose3 == 1)
					{
						cout << "Введите символ который нужно вставить" << endl;
						cin >> ch3;
						while ((ch3 < 97) || (ch3 > 122))
						{
							cout << "Введите коректный символ" << endl;
							cin >> ch3;
			
						}
						cout << "Введите номер в диапазоне от 0 (перед первым элементом) до " << legth << " (после последнего элемента)" << endl;
						cin >> number;
						while ((number < 0) || (number > legth))
						{
							cout << "Введите коректное место" << endl;
							cin >> number;
						}
						work=AddElem(work, ch3, number);
						show(work);
						
					}
					if (chose3 == 2)
					{
						if (legth == 0) cout << "Список УЖЕ пуст" << endl;
						else {
							cout << "Введите номер в диапазоне от 1 (начало) до " << legth << " (конец)" << endl;
							cin >> number;
							while ((number < 1) || (number > legth))
							{
								cout << "Введите коректное место" << endl;
								cin >> number;
							}
							work = deletElem(work, number);
							show(work);
						}	
					}
					if (chose3 == 3)
					{
						work = DeleteOA(work);
						//show(work);
						work = DeleteProbel(work);
						showwords(work);
						//show(work);
					}
					if (chose3 == 5)
					{
						int k = 0;
						k = findprobel(work);
						k++;
						ch3 = cin.get();
						while (ch3=='\n')
						{
							ch3 = cin.get();
						}
						while (ch3 != '.')
						{
							work = AddElem(work, ch3, k);
							k++;
							ch3 = cin.get();
							while (ch3 == '\n')
							{
								ch3 = cin.get();
							}
						}
						work = AddElem(work, ' ', k);
						show(work);
					}
				}
				destroy();
				delete work;
				chose3 = 0;
				legth = 0;
			}
			if (chose2 == 3) { flag = 0; }
		}
		if ((chose1 != 2) && (chose1!=1)) { cout << "Неправильный ввод" << endl; }
	}
	return 0;
}

