#pragma once

using namespace std;

void same_year();
void list_anim_warden(list* head, char search_warden[]);
void anim_phone_vet(list* head, char search_vet[]);
void all_info_by_name(list* head, char search_name[]);
int amount_anim_by_type(list* head, char search_type[]);
int* sort_list(list* head);

//− search animals by a given warden
void list_anim_warden(list* head, char search_warden[])
{
	int count = 0;
	
	list* p;

	p = head;
	cout << "  ______________" << endl;
	cout << " |    Result:   |" << endl;
	cout << " ================" << endl;
	while (p != NULL)
	{
		

		if (!stricmp(search_warden, p->surname_warden))
		{
			count++;
			cout << "  " << count << ". " << p->animals_nickname << endl;
			cout << " ----------------" << endl;
			
		}

		p = p->next;
	}
	if (!count)
	{
		cout << " |  Not found.  |" << endl;
		cout << " ================" << endl;
	}
	
	
}

//− search animals by a given year
void same_year(list* head, int year_search)
{
	int count = 0;

	list* p;

	p = head;
	cout << "  ______________" << endl;
	cout << " |    Result:   |" << endl;
	cout << " ================" << endl;
	while (p != NULL)
	{


		if (year_search == p->DOB[2])
		{
			count++;
			cout << "  " << count << ". " << p->animals_nickname << endl;
			cout << " ----------------" << endl;

		}

		p = p->next;
	}
	if (!count)
	{
		cout << " |  Not found.  |" << endl;
		cout << " ================" << endl;
	}
}

//− search animals by a given name 
void all_info_by_name(list* head, char search_by_name[])
{
	list* p;
	int count = 0;

	p = head;
	cout << " \n\n\t\t\t\t\t\t\t\tINFORMATION:" << endl;
	cout << "  ____________________________________________________________________________________________________________________________________" << endl
		<< " | Uniq. num. |     Type     |  Anim. name  |Anim. nickname|  Birthday  | Diet num. | Surname wardens | Surname of vet. | Vet's phone |" << endl
		<< " ======================================================================================================================================" << endl;
	while (p != NULL)
	{
		if (!stricmp(search_by_name, p->animals_name))
		{
			count++;
			cout << "  " << count << ". " << p->uniq_number;
			cout << "\r\t\t\b\b| " << p->type;
			cout << "\r\t\t\t\t\b\b\b| " << p->animals_name;
			cout << "\r\t\t\t\t\t\t\b\b\b\b| " << p->animals_nickname;
			cout << "\r\t\t\t\t\t\t\t\t\b\b\b\b\b| " << p->DOB[0] << "." << p->DOB[1] << "." << p->DOB[2];
			cout << "\r\t\t\t\t\t\t\t\t\t| " << p->diet_number;
			cout << "\r\t\t\t\t\t\t\t\t\t\t\t\b\b\b\b| " << p->surname_warden;
			cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t\b\b| " << p->surname_vet;
			cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| " << p->phone_number << endl;

			if (p->next != NULL)
				cout << " --------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}

		p = p->next; // move through a list

	}
	if (!count)
	{
		cout << " |                                                                 Not found.                                                         |" << endl;
		cout << " ======================================================================================================================================" << endl;
	}
}

//− search animals and number of phome by a given surname of veterinarian
void anim_phone_vet(list* head, char search_vet[])
{
	int count = 0;
	int i = 0;
	bool check = 1;
	list* p;

	string* ptr_phone_numbers = new string[count_el];//array for phone numbers if they are several

	for (size_t i = 0; i < strlen(search_vet); i++) //changes the case of letters to the form "Ххххх"
	{
		if (i == 0)
			search_vet[i] = toupper(search_vet[i]);
		else
			search_vet[i] = tolower(search_vet[i]);
	}

	p = head;
	cout << "  ______________" << endl;
	cout << " |    Result:   |" << endl;
	cout << " ================" << endl;
	while (p != NULL)
	{


		if (!stricmp(search_vet, p->surname_vet))
		{
			count++;
			cout << "  " << count << ". " << p->animals_nickname << endl;
			cout << " ----------------" << endl;
			if (i == 0) //first correct phone number is saved once
			{
				ptr_phone_numbers[i] = p->phone_number;
				i++;
			}
			else
			{
				for (int j = 0; j < i; j++) //check for available the same phone numbers
					if (!stricmp(ptr_phone_numbers[j].c_str(), p->phone_number))
						check = 0;
			
				if (check)//if the same number is not found, save it in array
				{
					ptr_phone_numbers[i] = p->phone_number;
					i++;
				}

				check = 1;
			}
		}

		p = p->next;
	}
	if (!count)
	{
		cout << " |  Not found.  |" << endl;
		cout << " ================" << endl;
	}
	
	count = 0;

	cout << " Surname veterinarian: " << search_vet << endl;
	cout << "  ____________________" << endl;
	cout << " |His phone number(s):|" << endl;
	cout << " ======================" << endl;
	for (int j = 0; j < i; j++)
	{
		count++;
		cout << "  " << count << ". " << ptr_phone_numbers[j] << endl;
		cout << " ----------------------" << endl;
	}
	if (!i)
	{
		cout << " |     Not found.     |" << endl;
		cout << " ======================" << endl;
	}

	delete[] ptr_phone_numbers;
}

//− counting animals by type
int amount_anim_by_type(list* head, char search_type[])
{
	int amount_an = 0;

	list* p;

	p = head;

	while (p != NULL)
	{

		if (!stricmp(search_type, p->type))
			amount_an++;

		p = p->next;
	}
	
	return amount_an;
}

//− sorting by date of birthday
int* sort_list(list* head)
{
	struct arr_for_sort
	{
		int year_month_day;
		int number;
	};

	arr_for_sort* ptr_arr = new arr_for_sort[count_el];
	int* ptr_numbers_sort = new int[count_el];

	list* p;
	int i = 0;
	arr_for_sort tmp;

	p = head;
	while (p != NULL)
	{
		ptr_arr[i].year_month_day = (p->DOB[2] * 10000 + p->DOB[1] * 100 + p->DOB[0]);//save this sum of factors in array of structures
		ptr_arr[i].number = (i + 1);// number of element
		i++;
		p = p->next;
	}

	for(int j = 0; j < count_el; j++) 
		for(int k = 0; k < (count_el - j - 1); k++)
			if (ptr_arr[k].year_month_day < ptr_arr[k + 1].year_month_day)// bubble sort
			{
				tmp = ptr_arr[k];
				ptr_arr[k] = ptr_arr[k + 1];
				ptr_arr[k + 1] = tmp;
			}

	for (int j = 0; j < count_el; j++)
		ptr_numbers_sort[j] = ptr_arr[j].number;// I save only sorted numbers of elements in order

	delete[] ptr_arr;

	return ptr_numbers_sort;
}