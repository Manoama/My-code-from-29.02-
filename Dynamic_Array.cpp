// Dynamic_Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<ctime>
using namespace std;

const int MAX_SIZE = 10;

int curr_size = 0;
void show_array(char* text);
void clear_array(char* &text);
void delete_id(char* &text, int id);
void fill_array(char* &text);
void add_elem(char*&text, int id, char value);
void print_unpaired_word(char* text);

void Menu()
{
	system("cls");
	cout << "1. Fill array" << endl;
	cout << "2. Add char (id)" << endl;
	cout << "3. Delete char (id)" << endl;
	cout << "4. Show array" << endl;
	cout << "5. Clear array" << endl;
	cout << "6. Print unpaired word" << endl;
	cout << "7. Exit..." << endl;
}





////////////////////////////////////


void delete_ch(char*&text, int id)
{
	char* new_text = new char[MAX_SIZE - 1];
	for (int i = 0; i < curr_size; i++)
	{
		if (i < id) new_text[i] = text[i]; 
		else new_text[i] = text[i + 1];
	}
	delete[] text;
	text = new_text;
	curr_size--;
}


void add(char*&text, int id, char value)
{
	char* new_text = new char[MAX_SIZE + 1];
	for (int i = 0; i <= curr_size; i++)
	{
		if (i < id){
			new_text[i] = text[i];
		}
		if (i > id) {
			new_text[i] = text[i -1];
		}
	}
	curr_size++;
	new_text[id] = value;
	new_text[curr_size] = '\0';
	delete[] text;
	text = new_text;
	
}

/////////////////////////////////////////////


int main()
{
	char* text = new char[MAX_SIZE];
	int id = 2;
	fill_array(text);
	add(text, id, 'G');
	show_array(text);
 
	delete_ch(text, 3);
	show_array(text);

	delete_ch(text, 2);
	show_array(text);

	delete_ch(text, 1);
	show_array(text);
	

	char value = '\0';
	int id1 = 0;
	int choice = 0;
	while (choice != 7) {
		Menu();
		cin >> choice;
		id1 = 0;
		value = '\0';
		switch (choice)
		{
		case 1:
			fill_array(text);
			break;
		case 2:
			cout << "Id:  ";
			cin >> id;
			cout << "Value:  ";
			cin >> value;
			add_elem(text, id, value);
			break;
		case 3:
			cout << "Id:  ";
			cin >> id;
			delete_id(text, id);
			break;
		case 4:
			show_array(text);
			system("pause");
			break;
		case 5:
			clear_array(text);
			break;
		case 6:
			print_unpaired_word(text);
			system("pause");
			break;
		case 7:
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	}
		
	
	delete[] text;
	system("pause");
	return 0;
}



void fill_array(char* &text)
{
	int i = 1;
	char ch;
back:
	cout << "Input text:  __";
	cin.get(ch);
	if (ch == '\n')
	{
		cout << "wrong input" << endl;
		goto back;
		
	}
	else {
		text[0] = ch;
		curr_size++;
	}
	while (cin.get(ch) && ch != '.')
	{
		if (ch != '\n') {
			text[i++] = ch;
			curr_size++;
		}
		else break;
	}
	text[curr_size] = '\0';
}




void add_elem(char *& text, int id,char value)
{
	char* tmp = new char[++curr_size];
	for (int i = 0; i <= curr_size; i++)
	{
		if (i < id) tmp[i] = text[i];
		else tmp[i+1] = text[i];
		
	}
	tmp[id] = value;
	for (int i = 0; i < curr_size; i++)
	{
		text[i] = tmp[i];
	}
	text[curr_size] = '\0';
	//delete[] tmp;
}

void print_unpaired_word(char * text)
{
	bool unpaired = true;
	int counter = 0;
	int curr_pos = 0;
	for (int i = 0; i < curr_size; i++)
	{
		counter = 0;
		while (text[i] != ' ' && text[i] != '\0')
		{
			counter++;
			i++;
		}
		if (counter % 2 == 1)
		{

			for (int j = curr_pos; j < i; j++, curr_pos++)
			{
				cout << text[j];
				
			}
		}
		else  curr_pos = i; 
	}
	cout << endl;
}



void delete_id(char* &text, int id)
{
	for (int i = 0; i <= curr_size; i++)
	{
		if (i < id);
		else text[i] = text[i + 1];
	}
	curr_size--;

}



void show_array(char* text)
{
	cout << "Text:\t";
	for (int i = 0; i <= curr_size; i++)
	{
		if (text[i] != '\n') {
			cout << text[i];
		}
	}
	cout << endl;
}

void delete_value(char val)
{
}

void clear_array(char*&text)
{
	for (int i = 0; i < curr_size; i++)
	{
		text[i] = '\0';
	}
	
}


