#pragma once
#include <iostream>
#include <cctype>
#include <fstream>

#define N 70

int count_el = 0; // number of list items

using namespace std;

struct list {
    char uniq_number[N];
    char type[N];
    char animals_name[N];
    char animals_nickname[N];
    int DOB[3];//day of birthday
    char diet_number[N];
    char surname_warden[N];
    char surname_vet[N];
    char phone_number[N];

    struct list* next;
};

list* create(list* head);
void see_list(list* head);
void input_info(list* head, list* p);
list* add_el_head(list* head);
void add_el_mid(list* head, int code);
void add_el_end(list* head);
list* del_first_el(list* head);
void del_mid_el(list* head, int code);
void del_last_el(list* head);
int edit_el(list* head, int code);
void file_create(string name_file, list* head);
list* read_file(string name_file, list* head);

void menu();
void toupper_and_tolower(list* p);
void clear_cin();
bool check_uniq(list* head, list* p);
void delete_n(list* p);
void delete_list(list* head);

         //the main functions

//create a list
list* create(list* head)
{

    int count = 1;
    char c;
    list* p, * pred; // pred - previous, p - current

    cout << "\t\tThis is the first element." << endl;

    head = pred = p = new list;

    input_info(head, p);

    cout << "Enter 'y' to continue and any other button to stop: " << endl;
    cin >> c;
    while (c == 'y')
    {
        count++;
        cout << "\t\tThis is " << count << " element." << endl;

        p = new list;
        input_info(head, p);

        pred->next = p; 
        pred = p; 
        cout << "Enter 'y' to continue and any other button to stop: " << endl;
        cin >> c;
    }
    p->next = NULL;

    return head;
}

//view a list
void see_list(list* head)
{
    int count = 0;
    list* p;
    p = head;



    cout << " \n\n\t\t\t\t\t\t\t\tINFORMATION:" << endl;
    cout << "  ____________________________________________________________________________________________________________________________________" << endl
        << " | Uniq. num. |     Type     |  Anim. name  |Anim. nickname|  Birthday  | Diet num. | Surname wardens | Surname of vet. | Vet's phone |" << endl
        << " ======================================================================================================================================" << endl;
    while (p != NULL) //until the end of the list
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

        p = p->next; // moving through the list
    }
    cout << " ======================================================================================================================================" << endl;


}

//entering information into a new element
void input_info(list* head, list* p)
{
    count_el++; // counter of the number of elements

    bool check;

    clear_cin();

    cout << "\tEnter a unique animal number (only numbers 0-9): XXXX" << endl;
    do
    {

        fgets(p->uniq_number, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->uniq_number) - 1); i++)
            if (!isdigit(p->uniq_number[i]))//check if its not number
                check = 1;

        if (check || strlen(p->uniq_number) != 5)
        {
            cout << " Wrong value, only 4 digits. Try again!" << endl;
            check = 1;
        }


    } while (check || check_uniq(head, p));

    clear_cin();

    cout << "\tEnter the type of animal: " << endl;
    do
    {
        fgets(p->type, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->type) - 1); i++)
            if (!isalpha(p->type[i]))//check if its not letter
                check = 1;

        if (check || p->type[0] == '\n')
            cout << " Wrong value, only letters. Try again!" << endl;

    } while (check || p->type[0] == '\n');

    cout << "\tEnter the name of the animal: " << endl;
    do
    {
        fgets(p->animals_name, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->animals_name) - 1); i++)
            if (!isalpha(p->animals_name[i]))//check if its not letter
                check = 1;

        if (check || p->animals_name[0] == '\n')
            cout << " Wrong value, only letters. Try again!" << endl;

    } while (check || p->animals_name[0] == '\n');


    cout << "\tEnter the nickname of the animal: " << endl;
    do
    {
        fgets(p->animals_nickname, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->animals_nickname) - 1); i++)
            if (!isalpha(p->animals_nickname[i]))//check if its not letter
                check = 1;

        if (check || p->animals_nickname[0] == '\n')
            cout << " Wrong value, only letters. Try again!" << endl;

    } while (check || p->animals_nickname[0] == '\n');

    cout << "\tEnter the date of birth of the animal" << endl;
    cout << " Day(1-31): ";

    do
    {
        cin >> p->DOB[0];

        check = 0;

        if (cin.fail() || p->DOB[0] < 1 || p->DOB[0] > 31) // (check for matching value) if previous extract was unsuccessful,
        {
            check = 1;
            cin.clear(); // return cin in 'usual' operating mode
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
            cout << " Wrong value! ONLY numbers(0-9). Days from 1 to 31, try again." << endl;
        }

    } while (check);

    cout << "\n Month(1-12): ";

    do
    {
        cin >> p->DOB[1];

        check = 0;

        if (cin.fail() || p->DOB[1] < 1 || p->DOB[1] > 12) // (check for matching value) if previous extract was unsuccessful,
        {
            check = 1;
            cin.clear(); // return cin in 'usual' operating mode
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
            cout << " Wrong value! ONLY numbers(0-9). Month from 1 to 12, try again." << endl;
        }

    } while (check);

    cout << "\n Year(1800-2020): ";

    do
    {
        cin >> p->DOB[2];

        check = 0;

        if (cin.fail() || p->DOB[2] < 1800 || p->DOB[2] > 2020) // (check for matching value) if previous extract was unsuccessful,
        {
            check = 1;
            cin.clear(); // return cin in 'usual' operating mode
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
            cout << " Wrong value! ONLY numbers(0-9). Year from 1800 to 2020, try again." << endl;
        }

    } while (check);

    clear_cin();

    cout << "\n\tEnter animal ration number (only numbers 0-9): XXXX " << endl;


    do
    {
        fgets(p->diet_number, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->diet_number) - 1); i++)
            if (!isdigit(p->diet_number[i]))//check if its not number
                check = 1;

        if (check || strlen(p->diet_number) != 5)
        {
            cout << " Wrong value, only 4 digits. Try again!" << endl;
            check = 1;
        }

    } while (check);

    cout << "\tEnter the surname of the warden: " << endl;
    do
    {
        fgets(p->surname_warden, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->surname_warden) - 1); i++)
            if (!isalpha(p->surname_warden[i]))//check if its not letter
                check = 1;

        if (check || p->surname_warden[0] == '\n')
            cout << " Wrong value, only letters. Try again!" << endl;

    } while (check || p->surname_warden[0] == '\n');

    cout << "\tEnter the surname of the veterinarian: " << endl;
    do
    {
        fgets(p->surname_vet, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->surname_vet) - 1); i++)
            if (!isalpha(p->surname_vet[i]))//check if its not letter
                check = 1;

        if (check || p->surname_vet[0] == '\n')
            cout << " Wrong value, only letters. Try again!" << endl;

    } while (check || p->surname_vet[0] == '\n');

    cout << "\tEnter the vet's phone number: " << endl;
    do
    {
        fgets(p->phone_number, N, stdin);

        check = 0;

        for (size_t i = 0; i < (strlen(p->phone_number) - 1); i++)
            if (!isdigit(p->phone_number[i]))//check if its not number
                check = 1;

        if (check || p->phone_number[0] == '\n')
            cout << " Wrong value, only digits. Try again!" << endl;

    } while (check || p->phone_number[0] == '\n');

    toupper_and_tolower(p);
    delete_n(p);


}

// head addition
list* add_el_head(list* head)
{
    list* p; // previous

    p = new list;
    p->next = head;

    head = p;

    input_info(head, p);

    return head;
}

// adding to the middle
void add_el_mid(list* head, int code)
{
    list* p, * new_el, * tmp, *pred;

    int count = 1;

    p = pred = head;

    while(count != code)
    {
        count++;

        pred = p;
        p = p->next;

    } 

    new_el = new list;
    input_info(head, new_el);

    tmp = pred->next;// saving pointer for next node
    pred->next = new_el;// previous node points on new node
    new_el->next = tmp;// new node points on next node
}

// append to the end
void add_el_end(list* head)
{
    list* p;
    list* new_el;

    p = head;


    if (p->next != NULL)
    {
        do
            p = p->next;
        while (p->next != NULL);
    }

    new_el = new list;

    input_info(head, new_el);

    p->next = new_el; //pointer next elements points in new element

    new_el->next = NULL;

}

//delete first element
list* del_first_el(list* head)
{

    list* tmp, * p;

    tmp = p = head;

    p = p->next; //2 element

    head = p; //address 2 elements is head now

    delete tmp;

    count_el--;

    return head;
}

// delete element in the middle
void del_mid_el(list* head, int code)
{
    list* p, * pred;
    int count = 2;

    pred = head;
    p = pred->next;

    while (count != code)
    {
        count++;
        pred = pred->next;
        p = p->next;
    }

    pred->next = p->next;

    delete p;

    count_el--;

}

//delete last element
void del_last_el(list* head)
{
    list* new_last, * last;

    new_last = head;
    last = new_last->next;

    if (count_el != 2)
    {
        do
        {
            new_last = new_last->next;
            last = last->next;

        } while (last->next != NULL);
    }

    new_last->next = NULL;

    delete last;

    count_el--;

}

//edit element
int edit_el(list* head, int code)
{
    list* p;
    int count = 1;

    int number;
    bool check;

    p = head;

    while (count != code)
    {
        count++;
        p = p->next;
    }
    cout << "\n\n\t\t\t\t\t\t\t\tMenu->Edit item:" << endl;
    cout << "\n\t\t\t\t\t\t\t\tTHIS IS " << code << " ELEMENT" << endl;
    cout << "  ____________________________________________________________________________________________________________________________________" << endl
        << " | Uniq. num. |     Type     |  Anim. name  |Anim. nickname|  Birthday  | Diet num. | Surname wardens | Surname of vet. | Vet's phone |" << endl
        << " ======================================================================================================================================" << endl;


    cout << "  1) " << p->uniq_number;
    cout << "\r\t\t\b\b|2)" << p->type;
    cout << "\r\t\t\t\t\b\b\b|3)" << p->animals_name;
    cout << "\r\t\t\t\t\t\t\b\b\b\b|4)" << p->animals_nickname;
    cout << "\r\t\t\t\t\t\t\t\t\b\b\b\b\b|5)" << p->DOB[0] << "." << p->DOB[1] << "." << p->DOB[2];
    cout << "\r\t\t\t\t\t\t\t\t\t|6)" << p->diet_number;
    cout << "\r\t\t\t\t\t\t\t\t\t\t\t\b\b\b\b|7)" << p->surname_warden;
    cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t\b\b|8)" << p->surname_vet;
    cout << "\r\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t |9)" << p->phone_number << endl;
    cout << " ======================================================================================================================================" << endl;

    cout << " 0. Back" << endl;
    cout << " Your choise: ";
    cin >> number;

    switch (number)
    {
    case 1:
    {
        cout << " Old value: " << p->uniq_number << endl;
        cout << " New value (only numbers 0-9) [XXXX] : ";
        clear_cin();
        do
        {

            fgets(p->uniq_number, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->uniq_number) - 1); i++)
                if (!isdigit(p->uniq_number[i]))
                    check = 1;

            if (check || strlen(p->uniq_number) != 5)
            {
                cout << " Wrong value, only 4 digits. Try again!" << endl;
                check = 1;
            }


        } while (check || check_uniq(head, p));
        break;
    }

    case 2:
    {
        cout << " Old value: " << p->type << endl;
        cout << " New value: ";
        clear_cin();
        do
        {
            fgets(p->type, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->type) - 1); i++)
                if (!isalpha(p->type[i]))
                    check = 1;

            if (check || p->type[0] == '\n')
                cout << "Wrong value, only letters. Try again!" << endl;

        } while (check || p->type[0] == '\n');
        break;
    }

    case 3:
    {
        cout << "Old value: " << p->animals_name << endl;
        cout << "New value: ";
        clear_cin();
        do
        {
            fgets(p->animals_name, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->animals_name) - 1); i++)
                if (!isalpha(p->animals_name[i]))
                    check = 1;

            if (check || p->animals_name[0] == '\n')
                cout << "Wrong value, only letters. Try again!" << endl;

        } while (check || p->animals_name[0] == '\n');
        break;
    }

    case 4:
    {
        cout << "Old value: " << p->animals_nickname << endl;
        cout << "New value: ";
        clear_cin();
        do
        {
            fgets(p->animals_nickname, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->animals_nickname) - 1); i++)
                if (!isalpha(p->animals_nickname[i]))
                    check = 1;

            if (check || p->animals_nickname[0] == '\n')
                cout << "Wrong value, only letters. Try again!" << endl;

        } while (check || p->animals_nickname[0] == '\n');
        break;
    }

    case 5:
    {
        cout << " Old value: ";
        for (int i = 0; i < 3; i++)
        {
            cout << p->DOB[i];
            if (i != 2)
                cout << ".";
        }

        cout << "\n New value: " << endl;

        cout << " Day(1-31): ";
        clear_cin();
        do
        {
            cin >> p->DOB[0];

            check = 0;

            if (cin.fail() || p->DOB[0] < 1 || p->DOB[0] > 31) // (check if its a letter) if previous extract was unsuccessful,
            {
                check = 1;
                cin.clear(); // return cin in 'usual' operating mode
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
                cout << " Wrong value! ONLY numbers(0-9). Days from 1 to 31, try again." << endl;
            }

        } while (check);

        cout << "\nMonth(1-12): ";
        clear_cin();
        do
        {
            cin >> p->DOB[1];

            check = 0;

            if (cin.fail() || p->DOB[1] < 1 || p->DOB[1] > 12) // (check if its a letter) if previous extract was unsuccessful,
            {
                check = 1;
                cin.clear(); // return cin in 'usual' operating mode
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
                cout << "Wrong value! ONLY numbers(0-9). Month from 1 to 12, try again." << endl;
            }

        } while (check);

        cout << "\nYear(1800-2020): ";
        clear_cin();
        do
        {
            cin >> p->DOB[2];

            check = 0;

            if (cin.fail() || p->DOB[2] < 1800 || p->DOB[2] > 2020) // (check if its a letter) if previous extract was unsuccessful,
            {
                check = 1;
                cin.clear(); // return cin in 'usual' operating mode
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
                cout << "Wrong value! ONLY numbers(0-9). Year from 1800 to 2020, try again." << endl;
            }

        } while (check);

        break;
    }
    case 6:
    {
        cout << "Old value: " << p->diet_number << endl;
        cout << "New value (only numbers 0-9) [XXXX] : " << endl;
        clear_cin();
        do
        {
            fgets(p->diet_number, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->diet_number) - 1); i++)
                if (!isdigit(p->diet_number[i]))
                    check = 1;

            if (check || strlen(p->diet_number) != 5)
            {
                cout << "Wrong value, only 4 digits. Try again!" << endl;
                check = 1;
            }

        } while (check);

        break;
    }
    case 7:
    {
        cout << " Old value: " << p->surname_warden << endl;
        cout << " New value: ";
        clear_cin();
        do
        {
            fgets(p->surname_warden, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->surname_warden) - 1); i++)
                if (!isalpha(p->surname_warden[i]))
                    check = 1;

            if (check || p->surname_warden[0] == '\n')
                cout << "Wrong value, only letters. Try again!" << endl;

        } while (check || p->surname_warden[0] == '\n');

        break;
    }
    case 8:
    {
        cout << " Old value: " << p->surname_vet << endl;
        cout << " New value: ";
        clear_cin();
        do
        {
            fgets(p->surname_vet, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->surname_vet) - 1); i++)
                if (!isalpha(p->surname_vet[i]))
                    check = 1;

            if (check || p->surname_vet[0] == '\n')
                cout << "Wrong value, only letters. Try again!" << endl;

        } while (check || p->surname_vet[0] == '\n');

        break;
    }
    case 9:
    {
        cout << " Old value: " << p->phone_number << endl;
        cout << " New value: ";
        clear_cin();
        do
        {
            fgets(p->phone_number, N, stdin);

            check = 0;

            for (size_t i = 0; i < (strlen(p->phone_number) - 1); i++)
                if (!isdigit(p->phone_number[i]))
                    check = 1;

            if (check || p->phone_number[0] == '\n')
                cout << "Wrong value, only digits. Try again!" << endl;

        } while (check || p->phone_number[0] == '\n');

        break;
    }
    case 0:
        return number;
    default:
        cout << " Not found";
    }

    delete_n(p);
    toupper_and_tolower(p);

    return number;

}


//create file
void file_create(string name_file, list* head)
{
    if (count_el != 0) //if there is some data that was written, delete it
        delete_list(head);

    
    
    ofstream fout;

    fout.open(name_file, ios::binary);

    if (!fout.is_open())
        cout << "ERROR OPEN FILE." << endl;
    else
    {
        cout << " File " << name_file << " is succesful open :D ! Please, enter information." << endl;
        head = create(head);
        list* p = head;

        fout.write((char*)&count_el, sizeof(int));

        while (p != NULL)
        {
             fout.write((char*)p, sizeof(list));
             p = p->next;
        }
        see_list(head);
        
    }

    fout.close();
    delete_list(head);
}

//read file
list* read_file(string name_file, list* head)
{
    ifstream fin;

    fin.open(name_file, ios::binary);

    if (!fin.is_open())
        cout << " ERROR READ FILE." << endl;
    else
    {
            int count = 0;

            fin.read((char*)&count_el, sizeof(int));//counting elements

            list* p, *pred;
            head = p = pred = new list;

            while (count != count_el)
            {
                count++;
                fin.read((char*)p, sizeof(list));
                pred = p;
                p = p->next;
                if (count == count_el)
                    p = NULL;
                else
                {
                     p = new list;
                     pred->next = p;
                }

               
            }
            cout << " Result: File \"" << name_file << "\" is succecful read!" << endl;
            see_list(head);
      
    }

    fin.close();

    return head;
}

//freeing heap for a list
void delete_list(list* head)
{
    list* p = head;
    list* pred;

    while (p != NULL)
    {
        pred = p;
        p = p->next;
        delete pred;
    }

    count_el = 0;
}

        //additional functions

void menu()
{
    cout << "\n\tMenu:\n" << endl
        << " 1 - Add item" << endl
        << " 2 - Delete item" << endl
        << " 3 - Edit item" << endl
        << " 4 - Output all data" << endl
        << " 5 - Creating a list of animals assigned to one warden" << endl
        << " 6 - Listing animals born in a given year" << endl
        << " 7 - Output complete information about all animals by the entered name" << endl
        << " 8 - Search for all animals assigned to a particular veterinarian, his phone number" << endl
        << " 9 - Counting the number of animals by type" << endl
        << " 10 - Sort by date of birth" << endl
        << " 0 - Exit" << endl
        << "\n\tYour choice: ";

}

//changes the case of all string arrays to the form "Õõõõõ"
void toupper_and_tolower(list* p)
{
    for (size_t i = 0; i < strlen(p->type); i++)
    {
        if (i == 0)
            p->type[i] = toupper(p->type[i]);
        else
            p->type[i] = tolower(p->type[i]);
    }
    for (size_t i = 0; i < strlen(p->animals_name); i++)
    {
        if (i == 0)
            p->animals_name[i] = toupper(p->animals_name[i]);
        else
            p->animals_name[i] = tolower(p->animals_name[i]);
    }
    for (size_t i = 0; i < strlen(p->animals_nickname); i++)
    {
        if (i == 0)
            p->animals_nickname[i] = toupper(p->animals_nickname[i]);
        else
            p->animals_nickname[i] = tolower(p->animals_nickname[i]);
    }
    for (size_t i = 0; i < strlen(p->surname_warden); i++)
    {
        if (i == 0)
            p->surname_warden[i] = toupper(p->surname_warden[i]);
        else
            p->surname_warden[i] = tolower(p->surname_warden[i]);
    }
    for (size_t i = 0; i < strlen(p->surname_vet); i++)
    {
        if (i == 0)
            p->surname_vet[i] = toupper(p->surname_vet[i]);
        else
            p->surname_vet[i] = tolower(p->surname_vet[i]);
    }
}

//to clean up the input stream more succinctly
void clear_cin()
{
    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
}

//check for uniqueness of a unique number
bool check_uniq(list* head, list* p)
{
    if (head == p)
        return false;
    else
    {
        list* ptr;
        int count = 0;
        ptr = head;

        if (p->uniq_number[strlen(p->uniq_number) - 1] == '\n')
            p->uniq_number[strlen(p->uniq_number) - 1] = '\0';

        while (ptr != NULL)
        {

            count++;
            if (count != count_el)
            {
                if (stricmp(p->uniq_number, ptr->uniq_number) == 0)
                {
                    cout << " Unique number must be unique! Try again." << endl;
                    return true;
                }

                ptr = ptr->next;
            }
            else return false;

        }

        return false;
    }
    
}

//removes a line break at the end of char arrays for the convenience of displaying information
void delete_n(list* p)
{
    if (p->uniq_number[strlen(p->uniq_number) - 1] == '\n')
        p->uniq_number[strlen(p->uniq_number) - 1] = '\0';

    if (p->type[strlen(p->type) - 1] == '\n')
        p->type[strlen(p->type) - 1] = '\0';

    if (p->animals_name[strlen(p->animals_name) - 1] == '\n')
        p->animals_name[strlen(p->animals_name) - 1] = '\0';

    if (p->animals_nickname[strlen(p->animals_nickname) - 1] == '\n')
        p->animals_nickname[strlen(p->animals_nickname) - 1] = '\0';

    if (p->diet_number[strlen(p->diet_number) - 1] == '\n')
        p->diet_number[strlen(p->diet_number) - 1] = '\0';

    if (p->surname_warden[strlen(p->surname_warden) - 1] == '\n')
        p->surname_warden[strlen(p->surname_warden) - 1] = '\0';

    if (p->surname_vet[strlen(p->surname_vet) - 1] == '\n')
        p->surname_vet[strlen(p->surname_vet) - 1] = '\0';

    if (p->phone_number[strlen(p->phone_number) - 1] == '\n')
        p->phone_number[strlen(p->phone_number) - 1] = '\0';
}
