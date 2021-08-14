#define _CRT_NONSTDC_NO_DEPRECATE
#include "list_organization_functions.h"
#include "search_functions.h"
#include <iostream>
#include <cstdlib>//for system("pause")
#include <string>

using namespace std;

int check_code();

int main()
{
    struct list* head = 0; // an address a head of list
    int code;
    int back;
    char c;
    bool check;
    string users_name_file;
    string programm_name_file = "Data.bin"; //standard file for write of data
    cout << "\n\n\t ===================================================================" << endl;
    cout << "\t ||                         List for zoo                          ||" << endl;
    cout << "\t ||      The program for work in the field of a zoo is developed. ||" << endl;
    cout << "\t ||---------------------------------------------------------------||" << endl;
    cout << "\t ||              Dynamic structure type - linked list             ||" << endl;
    cout << "\t ||                      Subject area - zoo                       ||" << endl;
    cout << "\t ||---------------------------------------------------------------||" << endl;
    cout << "\t ||      Structure: unique number of the animal, type,            ||" << endl;
    cout << "\t || nickname of the animal, name, year of birth, diet number,     ||" << endl;
    cout << "\t || surname of the warden, surname of the veterinarian, vet phone.||" << endl;
    cout << "\t ||===============================================================||" << endl;
    cout << "\t ||      Data input, output, data correction and deletion have    ||" << endl;
    cout << "\t || been developed. The possibility of forming a list of animals  ||" << endl;
    cout << "\t || assigned to one warden, deriving a list of animals born in a  ||" << endl;
    cout << "\t || given year, deriving complete  information about all animals  ||" << endl;
    cout << "\t || by the entered name is proposed. The search of all animals    ||" << endl;
    cout << "\t || assigned by the given veterinarian, his phone number, counting||" << endl;
    cout << "\t || the number of pets by type, sorting the list by date of birth ||" << endl;
    cout << "\t || has been developed. Work with files (read and write) is also  ||" << endl;
    cout << "\t || offered.                               Dev: Klitsman Kyrylo   ||" << endl;
    cout << "\t ===================================================================" << endl;
    cout << "\n\t\t\t\t   Hello, User! :D\n\n" << endl;
    system("pause");
    while (1)
    {
        system("cls");
        menu();
        
        code = check_code();

        switch (code)
        {
        case 1://add item 
        {
                     while (1)
                     {
                         system("cls");
                         cout << "\n\t Main menu -> 1. Add item:\n" << endl;
                         cout << " 1. - Create a list" << endl
                             << " 2. - Add element to head of list" << endl
                             << " 3. - Add to the middle of the list" << endl
                             << " 4. - Add element to the end of the list" << endl
                             << " 5. - Write to file" << endl
                             << " 6. - Read file" << endl
                             << " 0. - Back" << endl
                             << "\tYour choice: ";
                         code = check_code();
                         switch (code)
                         {
                             case 1:
                             {
                                    head = create(head);
                                    see_list(head);
                                    break;
                             }
                             case 2:
                             {
                                  if (head != 0)
                                  {
                                     head = add_el_head(head);
                                     see_list(head);
                                  }
                                  else
                                     cout << " First you need to create a list" << endl;

                                     break;
                             }
                             case 3:
                             {
                                  if (head != 0 && count_el != 1)
                                  {
                                     see_list(head);
                                     cout << " So what's the number will be your new element?" << endl;
                                     do
                                     {
                                         code = check_code();

                                          if (code <= 1 || code > count_el)
                                              cout << " Wrong value, 1 < number <= " << count_el << ". Try again:" << endl;

                                     } while ((code <= 1 || code > count_el));
                                     
                                     add_el_mid(head, code);
                                     see_list(head);
                                  }
                                  else
                                      cout << " First you need to create a list and have > 1 element" << endl;

                                   break;
                             }
                             case 4:
                             {
                                     if (head != 0)
                                     {
                                          add_el_end(head);
                                          see_list(head);
                                          break;
                                     }
                                     else
                                     {
                                          cout << " First you need to create a list" << endl;
                                          break;
                                     }

                             }
                             case 5:
                             {      
                                 system("cls");
                                 cout << "\n\t\tMain menu -> 1. Add item -> 5. Write to file:\n" << endl;
                                 cout << "\tSelect name file: " << endl;
                                 cout << "  _________________________________________________________" << endl;
                                 cout << " | 1. Standart file name - 'Data.bin' | 2. Your name file  |" << endl;
                                 cout << " -----------------------------------------------------------" << endl;
                                 cout << " |                         0. Back                         |" << endl;
                                 cout << " ===========================================================" << endl;

                                 cout << "\tYour choice: " << endl;

                                 do
                                 {
                                     code = check_code();

                                     if (code < 0 || code > 2)
                                         cout << " Enter ONLY 0 or 1, or 2 !" << endl;

                                 } while (code < 0 || code > 2);
                                 
                                 switch (code)
                                 {
                                 case 0:
                                     break;
                                 case 1:
                                 {
                                     file_create(programm_name_file, head);
                                     break;
                                 }
                                 case 2:
                                 {
                                     clear_cin();
                                     cout << " Enter the new file name ('Name.bin')" << endl;
                                     getline(cin, users_name_file);
                                     file_create(users_name_file, head);                     
                                     break;
                                 }
                                 }
                                  
                                   break;
                             }
                             case 6:
                             {
                                 system("cls");
                                 cout << "\n\t\tMain menu -> 1. Add item -> 6. Read file:\n" << endl;
                                 cout << "\tSelect name file: " << endl;
                                 cout << "  _________________________________________________________" << endl;
                                 cout << " | 1. Standart file name - 'Data.bin' | 2. Your name file  |" << endl;
                                 cout << " -----------------------------------------------------------" << endl;
                                 cout << " |                         0. Back                         |" << endl;
                                 cout << " ===========================================================" << endl;

                                 cout << "\tYour choice: " << endl;

                                 do
                                 {
                                     code = check_code();

                                     if (code < 0 || code > 2)
                                         cout << " Enter ONLY 0 or 1, or 2 !" << endl;

                                 } while (code < 0 || code > 2);

                                 switch (code)
                                 {
                                 case 0:
                                     break;
                                 case 1:
                                 {
                                     head = read_file(programm_name_file, head);
                                     break;
                                 }
                                 case 2:
                                 {
                                     clear_cin();
                                     cout << " Enter the file name ('Name.bin')" << endl;
                                     getline(cin, users_name_file);
                                     head = read_file(users_name_file, head);
                                     break;
                                 }
                                 default:
                                     cout << " Not found." << endl;
                                 }
                                
                                   break;
                             }
                             case 0:
                                   break;
                             default:
                             {
                                   cout << " Not found." << endl;
                                   break;
                             }
                         }
                         if (code == 0)
                             break;
                         system("pause");
                     }     
         
                     break;
        }   
        case 2://delete item 
        {
            while(1)
            {
                if (head != 0)
                {
                    system("cls");
                    cout << "\n\n\t\t\t\t\t\t\t\tMenu->Delete item:";
                    see_list(head);
                    cout << " Which element do you want to delete? Press '0' for back." << endl;
                    do
                    {
                        code = check_code();

                        if (code < 0 || code > count_el)
                            cout << "Wrong value, 1 <= number <= " << count_el << ". Try again:" << endl;

                    } while (code < 0 || code > count_el);

                    switch (code)
                    {
                         case 0:
                             break;
                         case 1:
                         {
                             cout << " Are you sure that you want to delete the first element? ('y' to true, any button to false)" << endl;
                              cin >> c;

                              if (c == 'y')
                              {
                                  head = del_first_el(head);
                                  if (head == 0)
                                      cout << " Not found a list." << endl;
                                  else
                                      see_list(head);
                              }

                              break;
                         }

                         default:
                         {
                              if (code == count_el) 
                              {
                                   cout << " Are you sure that you want to delete " << code << " element? ('y' to true, any button to false)" << endl;
                                   cin >> c;

                                   if (c == 'y')
                                   {
                                       del_last_el(head);
                                       see_list(head);
                                   }

                                   break;
                              }
                              else
                              {
                                   cout << " Are you sure that you want to delete " << code << " element? ('y' to true, any button to false)" << endl;
                                   cin >> c;

                                   if (c == 'y')
                                   {
                                        del_mid_el(head, code);
                                        see_list(head);
                                   }

                                   break;
                              }

                         }

                    }
                   
                }
                else
                {
                    cout << "Not found a list, create him." << endl;
                    break;
                }
                
                if (code == 0 || head == 0)
                    break;

                system("pause");
            }
            break;
        }
        case 3://edit item 
        {
            
            if (head != 0)
            {
                while (1)
                {
                    system("cls");
                    cout << "\n\n\t\t\t\t\t\t\t\tMenu->Edit item:";
                    see_list(head);

                    cout << "\tWhich item do you want to edit (press '0' for back): ";
                    do
                    {
                        code = check_code();

                        if (code < 0 || code > count_el)
                            cout << " Not found this item, try again." << endl;

                    } while (code < 0 || code > count_el);

                    if (code == 0)
                        break;

                    while (1)
                    {
                        system("cls");
                        back = edit_el(head, code);
                        if (back == 0)
                            break;         
                    }
                }
                break;
            }
            else
            {
                cout << "Not found a list, create him" << endl;
                break;
            }       
        }
        case 4://see list 
        {
            if (count_el == 0)
                cout << "List not exist." << endl;
            else
                 see_list(head);
            break;
        }
        case 5://search animals by a given warden
        {   
            if (count_el == 0)
                cout << "List not exist." << endl;
            else
            {   
                char search_warden[N];
                while (1)
                {
                    clear_cin();
                    system("cls");

                    cout << "\n\t\t\t\tMain menu -> 5 - Creating a list of animals assigned to one warden:" << endl;

                    see_list(head);

                    cout << "\tSelect number: " << endl;
                    cout << "  ________________________________________________" << endl;
                    cout << " | 1. Enter the surname of the warden for search |" << endl;
                    cout << " -------------------------------------------------" << endl;
                    cout << " | 0.                   Back                     |" << endl;
                    cout << " =================================================" << endl;

                    cout << "\tYour choice: " << endl;

                    do
                    {
                        code = check_code();

                        if (code < 0 || code > 1)
                            cout << " Wrong, enter ONLY 0 or 1!" << endl;

                    } while (code < 0 || code > 1);

                    if (code)
                    {
                        clear_cin();
                        cout << "\tEnter the surname of the warden for search: " << endl;

                        do
                        {
                            fgets(search_warden, N, stdin);

                            check = 0;

                            for (size_t i = 0; i < (strlen(search_warden) - 1); i++)
                                if (!isalpha(search_warden[i]))//проверка на наличие не букв
                                    check = 1;

                            if (check || search_warden[0] == '\n')
                                cout << " Wrong value, only letters. Try again!" << endl;

                        } while (check || search_warden[0] == '\n');

                        if (search_warden[strlen(search_warden) - 1] == '\n')
                            search_warden[strlen(search_warden) - 1] = '\0';

                        list_anim_warden(head, search_warden);
                        system("pause");
                    }
                    else break;  
                }
            }
            
            break;
        }
        case 6://search animals by a given year
        {
            if (count_el == 0)
                cout << "List not exist." << endl;
            else
            {
                int year_search;
                while (1)
                {

                    clear_cin();
                    system("cls");

                    cout << "\n\t\t\t\tMain menu -> 6 - Listing animals born in a given year:" << endl;

                    see_list(head);

                    cout << "\tSelect number: " << endl;
                    cout << "  __________________________" << endl;
                    cout << " | 1. Enter year for search |" << endl;
                    cout << " ----------------------------" << endl;
                    cout << " | 0.        Back           |" << endl;
                    cout << " ===========================" << endl;

                    cout << "\tYour choice: " << endl;

                    do
                    {
                        code = check_code();

                        if (code < 0 || code > 1)
                            cout << " Wrong, enter ONLY 0 or 1!" << endl;

                    } while (code < 0 || code > 1);

                    if (code)
                    {
                        cout << "\tEnter year for search: " << endl;
                        do
                        {
                            cin >> year_search;

                            check = 0;

                            if (cin.fail()) // (check if letter is written) if the previous extraction was unsuccessful,
                            {
                                check = 1;
                                cin.clear(); // return cin in 'usual' operating mode
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
                                cout << " Wrong value! ONLY numbers(0-9). Try again!" << endl;
                            }

                        } while (check);

                        same_year(head, year_search);
                        system("pause");
                    }
                    else break;
                }
                
            }
            break;
        }
        case 7://search animals by a given name 
        {
            
            if (count_el == 0)
                cout << "List not exist." << endl;
            else
            {
                char search_by_name[N];
                while (1)
                {
                    clear_cin();
                    system("cls");

                    cout << "\n\t\t\t\tMain menu -> 7 - Output complete information about all animals by the entered name:\n" << endl;
                    see_list(head);

                    cout << "\tSelect number: " << endl;
                    cout << "  __________________________" << endl;
                    cout << " | 1. Enter name for search |" << endl;
                    cout << " ----------------------------" << endl;
                    cout << " | 0.        Back           |" << endl;
                    cout << " ============================" << endl;

                    cout << "\tYour choice: " << endl;

                    do
                    {
                        code = check_code();

                        if (code < 0 || code > 1)
                            cout << " Wrong, enter ONLY 0 or 1!" << endl;

                    } while (code < 0 || code > 1);

                    if (code)
                    {
                        clear_cin();
                        cout << "\tEnter name for search: " << endl;

                        do
                        {
                            fgets(search_by_name, N, stdin);

                            check = 0;

                            for (size_t i = 0; i < (strlen(search_by_name) - 1); i++)
                                if (!isalpha(search_by_name[i]))//check if its not a letter
                                    check = 1;

                            if (check || search_by_name[0] == '\n')
                                cout << " Wrong value, only letters. Try again!" << endl;

                        } while (check || search_by_name[0] == '\n');

                        if (search_by_name[strlen(search_by_name) - 1] == '\n')
                            search_by_name[strlen(search_by_name) - 1] = '\0';

                        all_info_by_name(head, search_by_name);

                        system("pause");
                    }
                    else break;
                }
            }
            break;
        }
        case 8://search animals and number of phome by a given surname of veterinarian
        {
            if (count_el == 0)
                cout << "List not exist." << endl;
            else
            {
                char search_vet[N];
                while (1)
                {
                    clear_cin();
                    system("cls");

                    cout << "\n\t\t\t\tMain menu -> 8 - Search for all animals assigned to a particular veterinarian, his phone number:\n" << endl;
                    see_list(head);
                    cout << "\tSelect number: " << endl;
                    cout << "  _____________________________________________________" << endl;
                    cout << " | 1. Enter the surname of the veterinarian for search |" << endl;
                    cout << " -------------------------------------------------------" << endl;
                    cout << " | 0.                       Back                       |" << endl;
                    cout << " =======================================================" << endl;

                    cout << "\tYour choice: " << endl;

                    do
                    {
                        code = check_code();

                        if (code < 0 || code > 1)
                            cout << " Wrong, enter ONLY 0 or 1!" << endl;

                    } while (code < 0 || code > 1);

                    if (code)
                    {
                        clear_cin();
                        cout << "\tEnter the surname of the veterinarian for search: " << endl;

                        do
                        {
                            fgets(search_vet, N, stdin);

                            check = 0;

                            for (size_t i = 0; i < (strlen(search_vet) - 1); i++)
                                if (!isalpha(search_vet[i]))//check if its not a letter
                                    check = 1;

                            if (check || search_vet[0] == '\n')
                                cout << " Wrong value, only letters. Try again!" << endl;

                        } while (check || search_vet[0] == '\n');

                        if (search_vet[strlen(search_vet) - 1] == '\n')
                            search_vet[strlen(search_vet) - 1] = '\0';

                        anim_phone_vet(head, search_vet);
                        system("pause");
                    }
                    else break;
                }
            }
            break;
        }
        case 9://counting animals by type
        {
            if (count_el == 0)
                cout << "List not exist." << endl;
            else
            {

                char search_type[N];
                int amount_an;
                while (1)
                {


                    clear_cin();
                    system("cls");

                    cout << "\n\t\t\t\tMain menu -> 9 - Counting the number of animals by type\n" << endl;
                    see_list(head);

                    cout << "\tSelect number: " << endl;
                    cout << "  ________________________________" << endl;
                    cout << " | 1. Enter the type for counting |" << endl;
                    cout << " ----------------------------------" << endl;
                    cout << " | 0.            Back             |" << endl;
                    cout << " ==================================" << endl;

                    cout << "\tYour choice: " << endl;

                    do
                    {
                        code = check_code();

                        if (code < 0 || code > 1)
                            cout << " Wrong, enter ONLY 0 or 1!" << endl;

                    } while (code < 0 || code > 1);

                    if (code)
                    {
                        cout << "\tEnter the type for counting: " << endl;

                        clear_cin();

                        do
                        {
                            fgets(search_type, N, stdin);

                            check = 0;

                            for (size_t i = 0; i < (strlen(search_type) - 1); i++)
                                if (!isalpha(search_type[i]))//check if its not a letter
                                    check = 1;

                            if (check || search_type[0] == '\n')
                                cout << " Wrong value, only letters. Try again!" << endl;

                        } while (check || search_type[0] == '\n');

                        if (search_type[strlen(search_type) - 1] == '\n')
                            search_type[strlen(search_type) - 1] = '\0';

                        amount_an = amount_anim_by_type(head, search_type);

                        cout << "  ____________________" << endl;
                        cout << " |    Result: " << amount_an; cout << "\r\t\t\t\b\b|" << endl;
                        cout << " ======================" << endl;

                        system("pause");
                    }
                    else break;
                    
                }
            }
            break;
        }
        case 10://sorting by date of birthday
        {
            if(count_el == 0)
                cout << "List not exist." << endl;
            else
            {
                int* ptr_numbers_sort;
                int count_sort = 0;
                int count = 0;
                while (1)
                {
                    clear_cin();
                    system("cls");
                    count = 0;
                    cout << "\n\t\t\t\tMain menu -> 10 - Sort by date of birth:" << endl;

                    see_list(head);

                    cout << "\tSelect sorting type: " << endl;
                    cout << " _________________________________" << endl;
                    cout << " | 1. Ascending  | 2. Descending |" << endl;
                    cout << " =================================" << endl;
                    cout << " | 0.           Back             |" << endl;
                    cout << " =================================" << endl;

                    cout << "\tYour choice: " << endl;
                    do
                    {
                        code = check_code();

                        if (code < 0 || code > 2)
                            cout << " Enter ONLY 0 or 1, or 2 !" << endl;

                    } while (code < 0 || code > 2);


                    ptr_numbers_sort = sort_list(head);

                    list* p;

                    switch (code)
                    {
                    case 1:
                    {
                        cout << " \n\n\t\t\t\t\t\t\t\tINFORMATION (Ascending):" << endl;
                        cout << "  ____________________________________________________________________________________________________________________________________" << endl
                            << " | Uniq. num. |     Type     |  Anim. name  |Anim. nickname|  Birthday  | Diet num. | Surname wardens | Surname of vet. | Vet's phone |" << endl
                            << " ======================================================================================================================================" << endl;
                        for (int i = (count_el - 1); i >= 0; i--)
                        {
                            p = head;
                            while (p != NULL)
                            {
                                count_sort++;
                                if (count_sort == ptr_numbers_sort[i])
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
                                }

                                p = p->next; // move within a list

                            
                            }
                            count_sort = 0;

                        }
                        cout << " ======================================================================================================================================" << endl;
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        cout << " \n\n\t\t\t\t\t\t\t\tINFORMATION (Descending):" << endl;
                        cout << "  ____________________________________________________________________________________________________________________________________" << endl
                            << " | Uniq. num. |     Type     |  Anim. name  |Anim. nickname|  Birthday  | Diet num. | Surname wardens | Surname of vet. | Vet's phone |" << endl
                            << " ======================================================================================================================================" << endl;
                        for (int i = 0; i < count_el; i++)
                        {
                            p = head;
                            while (p != NULL)
                            {
                                count_sort++;
                                if (count_sort == ptr_numbers_sort[i])
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
                                }

                                p = p->next; // move within a list
                  
                            }
                            count_sort = 0;

                        }
                        cout << " ======================================================================================================================================" << endl;
                        system("pause");
                        break;
                    }
                    case 0:
                        break;
                    }
                    if (code == 0)
                        break;
                }
                delete[] ptr_numbers_sort;
            }

            break; 
        }
        case 0:
        {
            if(count_el!= 0)
                 delete_list(head);
            return 0;
            
        }
        default:
        {
            cout << "Not found." << endl;
            break;
        }

        }
        system("pause");
    }
}

int check_code()
{
    bool check;
    int code;

    do
    {
        cin >> code;

        check = 0;

        if (cin.fail()) // (check if its a letter) if previous extract was unsuccessful,
        {
            check = cin.fail();
            cin.clear(); // return cin in 'usual' operating mode
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // and delete previous values from the input buffer
            cout << "Wrong value! ONLY numbers, try again." << endl;
        }

    } while (check);

    return code;
}
