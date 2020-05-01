#include <iostream> 

using namespace std;

// Any char[] output
void Word(char* word)
{
	int length;
	for (length = 0; word[length]; length++);
	cout << "\'";
	for (int i = 0; i < length; i++)
	{
		cout << word[i];
	}
	cout << "\'";
}


//Menu
void Menu()
{
	cout << "\n1. Write in the end of File" << endl;
	cout << "2. Write in the begining of File" << endl; 
	cout << "3. Output the text of File" << endl;
	cout << "4. Output the resersed text of File" << endl;
	cout << "5. Output 1 string - 1 word" << endl;
	cout << "6. Find word..." << endl;
	cout << "7. Output by id" << endl;
	cout << "8. Output words with unpair number of letters" << endl;
	cout << "9. Delete id" << endl;
	cout << "10. Exit.\n" << endl;
	cout << "Choose any item...(1-8) \t";
}


class List
{
public:
	// Methods
	List();
	~List();
	void push_back(char* data); // Запись в конец файла
	void push_front(char* data);
	void pop_front();
	void show_text();
	void show_all_words();
	void reverse_show();
	void find_word(char* word);
	void delete_id(int id);
	char& operator[](const int index);
	int get_list_size();
	void output_unpair_words();
	void output_id(int id);

private:
	char* UnpairNumberWord_array();
	
	bool is_empty();
	void clear();
	char get_tail_data();
	char get_head_data();
	void push_back_in_empty_list(char * data);
	void push_back_in_filled_list(char * data);

	// Node of symbols
	class Node {
	public:
		Node* get_next() { return next; }
		Node* get_prev() { return prev; }
		char get_data() { return data; }
		void set_next(Node* next) { this->next = next; }
		void set_prev(Node* prev) { this->prev = prev; }
		void set_data(char data) { this->data = data; }
		Node(char data = '\0', Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	private:
		Node *next;
		Node *prev;
		char data;
	};

	//Variables
	Node* HEAD;
	Node* TAIL;
	int LIST_SIZE;
};
List ls_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()																																					//
{
	char* text=NULL; 
	char ch;
	int size = 0; // go to 95 code string 
	int counter_n;
	int id = 0;//for choice = 7
	List ls;

	
	int choice = 1;
	while (choice != 10 && choice < 10 && choice > 0)
	{
		counter_n = 0;
		char buffer[4096] = { '\0' };
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			size = 0;
			cout << "Input:\n\t";
			cin.clear();
		//	if (ch == '\n') counter_n++;
			cin.get(ch);
			do
			{
				buffer[size] = ch;
				size++;
				if (ch == '\n') counter_n++;
				if (counter_n == 2) break;
			} while (cin.get(ch) && ch != '.' && ch != '!' && ch != '?');

			text = new char[size]; 
			for (int j = 0; j < size; j++)
			{
				text[j] = buffer[j];
			}
			text[size] = '\0';
			ls.push_back(text);
			
			system("pause");
			system("cls");
			break;
		case 2:
			size = 0;
			cout << "Input:\n\t";
			cin.clear();

			cin.get(ch);
			do
			{
				buffer[size] = ch;
				size++;
				if (ch == '\n') counter_n++;
				if (counter_n == 2) break;
			} while (cin.get(ch) && ch != '.' && ch != '!' && ch != '?');
		
			text = new char[size];
			for (int j = 0; j < size; j++)
			{
				text[j] = buffer[j];
			}
			text[size] = '\0';
			ls.push_front(text);

			system("pause");
			system("cls");
			break;
		case 3:
			ls.show_text();
			system("pause");
			system("cls");
			break;
		case 4:
			ls.reverse_show();
			system("pause");
			system("cls");
			break;
		case 5:
			ls.show_all_words();
			system("pause");
			system("cls");
			break;
		case 6:
			
			size = 0;
			cout << "Input:\n\t";
			cin.clear();
			cin.get(ch);
			do{
				if (ch != '\n')
				{
					buffer[size] = ch;
					size++;
				}
				else counter_n++;
				if (counter_n == 2) break;
			} while (cin.get(ch) && ch != '.' && ch != '!' && ch != '?'&&ch != ' ');

				
			ls.find_word(buffer);			
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Enter id:  ";
			cin >> id;
			ls.output_id(id);
			// id foo
			system("pause");
			system("cls");
			break;
		case 8:
			ls.output_unpair_words();
			system("pause");
			system("cls");
			break;
		case 9:
			cout << "Enter id:  ";
			cin >> id;
			ls.delete_id(id);
			system("pause");
			system("cls");
			break;
		case 10:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Default constructor
List::List()
{
	LIST_SIZE = 0;
	HEAD = NULL;
	TAIL = NULL;
}


void List::push_back(char * data)
{
	if (this->is_empty())
	{
		this->push_back_in_empty_list(data);
	}
	else
	{
		this->push_back_in_filled_list(data);
	}
	TAIL->set_data('\0');
	
}

void List::push_front(char * data)
{
	Node* new_head = new Node(*data);
	LIST_SIZE++;
	Node* new_tail = new_head;
	while (data != NULL && *(data) != '\0')
	{
		
		if (HEAD == NULL)
		{
			delete new_head;
			this->push_back(data);
			return;
		}
		else
		{
			static int i = 1;
			Node* current = new_tail;
			Node* tmp = new Node(*(++data), NULL, new_tail);
			current->set_next(tmp);
			new_tail = current->get_next();
			LIST_SIZE++;
			i++;
		}
		
	}
	new_tail->set_next(HEAD);
	HEAD->set_prev(new_tail);
	HEAD = new_head;

}
//DELETING 
void List::pop_front()
{
	if (is_empty()) {
		cout << "The list is empty. You can't delete any elements! " << endl;
		return;
	}
		
	Node* tmp = HEAD;
	HEAD = HEAD->get_next();
	delete tmp;
	LIST_SIZE--;
}
void List::show_text()
{
	Node* curr = HEAD;
	if (curr == NULL)
	{
		cout << "Empty" << endl;
		return;
	}
		do
		{
			if (curr->get_data() != '\n') {
				cout << curr->get_data();
			}
			curr = curr->get_next();
		} while (curr->get_next() != NULL);
		
}

void List::show_all_words()
{

	Node* default_head = HEAD;
	if (is_empty())
	{
		cout << "The list is empty" << endl;
		return;
	}
	int k = 0;// counter for number of words
	int curr_word_len = 0;// Lenght of current word
	while (HEAD != NULL)
	{
		Node* tmp = HEAD;// pointer for current word
		char word[20];// temporary array for current word
		int j = 0;// itertaror for temporary array for current word
		while (tmp->get_data() != '\0' && tmp->get_data() != 32)
		{
			word[j] = tmp->get_data();
			tmp = tmp->get_next();
			j++;
		}
		HEAD = tmp->get_next();
		k++;
		
		cout << "\nWord #" << k << ":\t";
		for (int i = 0; i < j; i++)
		{
			if (word[i] != '\n') cout << word[i];
		}		
	}
	HEAD = default_head;
}

void List::reverse_show()
{
	
	Node* curr = TAIL->get_prev();
	if (curr == NULL)
	{
		cout << "Empty" << endl;
		return;
	}
	do
	{
		cout << curr->get_data();
		curr = curr->get_prev();
	} while (curr != NULL);
	cout << endl << "Size = " << LIST_SIZE - 1 << endl;

}

void List::find_word(char * word)
{
	char* tmp_word = word;
	int counter_of_coinsidences = 0; // количество совпадений в тексте
	bool is_equal = true;
	Node* curr = HEAD;
	while (curr != NULL)
	{
		is_equal = true;
		while (curr->get_data() != '\0'&&curr->get_data() != ' ')
		{
			if (*(word) == curr->get_data())
			{
				word++;
				curr = curr->get_next();
			}
			else
			{
				is_equal = false;
				break;
			}
		}

		if (is_equal)
		{
			cout << "\nThis word ";
			Word(tmp_word);
			cout<<" is present" << endl;
			break;
			//			counter_of_coinsidences++
		}
		else
		{
			while (curr->get_data() != '\0' && curr->get_data() != ' ' && curr->get_data() != '\n')
			{
				curr = curr->get_next();
			}
			curr = curr->get_next();
			word = tmp_word;
			continue;
		}
     	
	}
	if (!is_equal)
	{
		cout << "\nThere is no word ";
		Word(tmp_word);
	}
	
}


//void List::output_id(int id)
//{
//	List ls_t = *this;
//	char tmp = '\0';
//	if (id > this->get_list_size() - 1) cout << " Out of array" << endl;
//	else
//	{
//		tmp = ls_t[id];
//		cout << id + 1 << "-s elem.:  " << tmp << endl;
//	}
//}

void List::delete_id(int id)
{
	Node* curr = HEAD;
	Node* pNext;
	Node* pPrev;
	int counter = 0;
	if (id > this->get_list_size() - 1) cout << " Out of array" << endl;
	else
	{
		while (counter != id)
		{
			curr = curr->get_next();
			counter++;
		}
		pNext = curr->get_next();
		pPrev = curr->get_prev();
		pPrev->set_next(pNext);
		pNext->set_prev(pPrev);
		delete curr;
		
	}
}



char& List::operator[](const int index)
{
	if(get_list_size()>=index)
	{
		int counter = 0;// считаем в каком єл-те мы сейчас
		Node* current = HEAD;
		while (current != NULL)
		{
			if (counter == index)
			{
				char link = current->get_data();
				return link;
			}
			current = current->get_next();
			counter++;
		}
	}
	else {
		cout << "Error. Beyond Array" << endl;
	}
}

int List::get_list_size()
{
	return LIST_SIZE - 1;
}

void List::output_unpair_words()
{
	char* tmp = this->UnpairNumberWord_array();
	while (*(tmp)!='\0')
	{
		cout << *(tmp);
		tmp++;
	}
}

void List::output_id(int id)
{
	ls_t = *this;
	char tmp='\0';
	if (id > this->get_list_size() - 1) cout << " Out of array" << endl;
	else
	{
		tmp = ls_t[id];
		cout << id+1 << "-s elem.:  " << tmp << endl;
	}
}


char* List::UnpairNumberWord_array()
{
	bool is_unpair = false;
	int i = 1; // whether 'i' pair or unpair 
	int j = 0;// iterator of writing into buffer
	char buffer[4096] = { '\0' };
	Node* curr = HEAD;
	Node* iterator = HEAD;
	while (curr != NULL && iterator != NULL)
	{
		i = 1;
		while (iterator->get_next()->get_data() != '\0' && iterator->get_next()->get_data() != 32 && iterator->get_next()->get_data() != '\n')
		{
			iterator = iterator->get_next();
			i++;

		}
		if ((i % 2) == 1)
		{
			is_unpair = true;
			while (curr != iterator->get_next())
			{
				if (curr->get_data() != '\n') {
					buffer[j] = curr->get_data();
					curr = curr->get_next();
					j++;
				}
				else
				{
					curr = curr->get_next();
				}
			}

		}
		else
		{
			curr = iterator->get_next()->get_next();
			//is_unpair = false;
		}
		curr = iterator->get_next()->get_next();
		iterator = iterator->get_next()->get_next();
		buffer[j++] = '\n';
		
	}
	//buffer[j + 1] = '\0';
	return buffer;
}

bool List::is_empty()
{
	if (HEAD == NULL) return 1;
	else return 0;
}

void List::clear()
{
	while (HEAD != NULL)
	{
		pop_front();
	}
	cout << "The List is empty" << endl;
}

char List::get_tail_data()
{
	return TAIL->get_prev()->get_data();
}

char List::get_head_data()
{
	return HEAD->get_data();
	
}

void List::push_back_in_empty_list(char * data)
{
	while (data != NULL && *(data) != '\0')
	{
		if (HEAD == NULL)
		{
			if (*data != '\n')
			{
				this->HEAD = new Node(*data);
				LIST_SIZE++;
				this->TAIL = this->HEAD;
			}
			else
			{
				data++;
			}

		}
		else
		{
			if (*data != '\n') 
			{
				static int i = 1;
				Node* current = TAIL;
				Node* tmp = new Node(*(++data), NULL, TAIL);
				current->set_next(tmp);
				TAIL = current->get_next();
				LIST_SIZE++;
				i++;
			}
			else
			{
				data++;
			}
		}
	}
	
}



void List::push_back_in_filled_list(char * data)
{
	int k = 0;
	while (*(data-1) != '\0')
	{
		if (*data != '\n') {
			static int i = 1;
			Node* current = TAIL;
			if (k)
			{
				data++;
				k++;
			}
			Node* tmp = new Node(*(data++), NULL, TAIL);
			current->set_next(tmp);
			TAIL = current->get_next();
			LIST_SIZE++;
			i++;
		}
		else
		{
			data++;
		}
	}
	
}

//Destructor
List::~List()
{
	this->clear();
}




