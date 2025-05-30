#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include <stdlib.h>
#include <iomanip> 

using namespace std;


struct id
{
    string name;
    string no ;
    int gpa ;
};

struct node
{
   id data ;
   node * next ;
   node * back ;
};

class SDB
{
private :
    node * first , *last , *new_node ;
    long int type ;
    int counter ; int flag = 0 ;
public:

    SDB(){first = last = NULL ; int  counter = 1; }

    int create ( long int i ,string n ,string x , long double y )
    {
        if ( first == NULL)
        {
        type = i ;
        new_node = new node ;
        new_node -> data.name = n;
        new_node -> data.no = x ;
        new_node -> data.gpa = y ;
        new_node -> next = NULL;
        new_node -> back = NULL;
        first = new_node ;
        last = new_node ;
        counter++ ;
        return 1 ;
        }
        else
        {
            cout << "  You used create option previously \n " ;
            return 0 ;
        }
    }

    int insertelement ( string n , string x , long double y )
    {

        new_node = new node ;
        new_node -> data.name = n;
        new_node -> data.no = x ;
        new_node -> data.gpa = y ;

        if( first != NULL)
        {

        switch ( type )
        {
          case 1 :

            if ( first -> data.name[0] >= n[0])
            {
                first -> back = new_node ;
                new_node -> next = first ;
                new_node -> back = NULL ;
                first = new_node ;
                counter++ ;
                return 1 ;
            }

           else if ( last -> data.name[0] <= n[0] )
            {
                last -> next = new_node ;
                new_node -> next = NULL ;
                new_node -> back = last ;
                last = new_node ;
                counter++ ;
                return 1 ;
            }
            else
            {
                node * current = first ;
                node * cur_next = current-> next ;

                for ( ; cur_next -> next != NULL ; )
                {
                    current = current -> next ;
                    cur_next = cur_next ->next ;

                    if( cur_next -> data.name[0] >= n[0])
                        break ;
                }

                     cur_next -> back  = new_node ;
                     new_node -> next  = cur_next ;
                     new_node -> back = current ;
                     current -> next = new_node ;
                     counter++ ;
                     return 1 ;

            }
            break ;

          case 2 :

            if ( first -> data.no >= x)
            {
                first -> back = new_node ;
                new_node -> next = first ;
                new_node -> back = NULL ;
                first = new_node ;
                counter++ ;
                return 1 ;
            }

           else if ( last -> data.no <= x )
            {
                last -> next = new_node ;
                new_node -> next = NULL ;
                new_node -> back = last ;
                last = new_node ;
                counter++ ;
                return 1 ;
            }
            else
            {
                node * current = first ;
                node * cur_next = current-> next ;

                for ( ; cur_next -> next != NULL ; )
                {
                    current = current -> next ;
                    cur_next = cur_next ->next ;

                    if( cur_next -> data.no >= x)
                        break ;
                }

                     cur_next -> back  = new_node ;
                     new_node -> next  = cur_next ;
                     new_node -> back = current ;
                     current -> next = new_node ;
                     counter++ ;
                     return 1 ;
            }
            break ;

        }
        }
        else
            {
            cout << " Please use  create option first \n";
            return 0 ;
            }
    }


    int deleteelement (string  x )
    {
        if ( first != NULL)
        {
          node * del_first = first ;
          node * del_last = last;
          node * del_next = del_first -> next ;
          node * del_back = last -> back ;

          if ( first -> data.no == x )
          {
           first = del_next ;
           delete (del_first);
           counter-- ;
           return 1;
          }

          else if (  last -> data.no == x)
          {
              last = del_back;
              last -> next = NULL ;
              delete (del_last);
              counter-- ;
              return 1;
          }
          else
          {

          for ( ; del_first ->next != NULL ; )
          {
              del_first = del_first -> next ;
              del_back = del_first -> back ;
              del_next = del_first -> next ;


              if ( x == del_first -> data.no)
              {
                  del_next -> back = del_first ->back ;
                  del_back -> next = del_first ->next;
                  delete (del_first);
                  flag = 1 ;
                  counter-- ;
                  return 1;
              }
          }
          }

          if ( flag == 0 ) {
            cout << "Wrong ID \n" ;
            return 3;
          }
        }
        else
        {
            cout << "Empty database !!\n";
            return 0;
        }
    }

    void print ( void )
    {
         cout << "   Name\t\tID\tGPA\n\n";
         node* pri_ele = first ;

         for (  ; pri_ele != NULL ; )
         {
             cout << pri_ele-> data.name << "\t" << pri_ele ->data.no << "\t" << pri_ele->data.gpa << endl ;
             pri_ele = pri_ele-> next ;
         }
     }


     int savefile(void) {
        node *save = first;
        int fs = 0;
        ofstream fout("save.txt");
    
        if (!fout.is_open()) {  // Failed to open file
            cout << "Could not open the file " << "save.txt" << endl;
            return 0;
        }
    
        // Set column widths for better alignment
        fout << left << setw(20) << "Name" << setw(15) << "ID" << setw(10) << "GPA" << "\n\n";
    
        while (save != NULL) {
            fout << left << setw(20) << save->data.name
                 << setw(15) << save->data.no
                 << setw(10) << fixed << setprecision(2) << save->data.gpa
                 << endl;
            save = save->next;
            fs = 1;
        }
    
        fout.close();
    
        if (fs == 0) {
            cout << "Empty database !! \n";
            return 0;
        } else {
            cout << "Done \n";
            return 1;
        }
    }

    int searchelement ( string x)
    {
       node* sch = first ;
       int f = 0;

       if ( first == NULL )
       {
           cout << "Empty Database \n";
           return 0 ;
       }
       else
       {
           while ( sch != NULL)
           {
               if( sch -> data.no == x  )
               {
                   cout <<sch -> data.name << "\t" << sch -> data.no << "\t" << sch -> data.gpa << endl ;
                   f = 1;
                   return 1;
                   break ;
               }
               sch = sch ->next;
           }
          if (f == 0)
          {
              cout << "Wrong ID \n" ;
            return 3;
          }
       }


   }

   void help() {
    system("CLS");
    cout << "Student Database Management System\n"
         << "==================================\n\n"
         << "This program helps manage a college student database with various functions.\n\n"

         << "1. Create Function:\n"
         << "   - Use this function to create a new database.\n"
         << "   - You must create a database before inserting any records.\n\n"

         << "2. Insert Function:\n"
         << "   - Allows you to add student records to the database.\n"
         << "   - Ensure the database is created before using this function.\n\n"

         << "3. Delete Function:\n"
         << "   - Enables you to remove specific student records from the database.\n"
         << "   - Enter the student details or ID to delete a record.\n\n"

         << "4. Search Function:\n"
         << "   - Helps you find a student record by name, ID, or other criteria.\n\n"

         << "5. Save Function:\n"
         << "   - Stores all inputted student records for future use.\n"
         << "   - Data will be saved in the 'save.txt' file.\n\n"

         << "6. Print Function:\n"
         << "   - Displays all stored student records in a structured format.\n"
         << "   - Useful for reviewing data without opening the file manually.\n\n"

         << "Thank you for using this program! We hope you find it useful.\n";
}


};


void show (void) ;
int check_num(int x = 0);
int menu ();


int main()
{
     show();
     SDB obj ;
     long int type , test  , num_cases  ;
     long  int num_insert , num_del ,num_search ,check_insert , check_del ,check_search ;
     long double gpa;
     string name , id ;

     test = 1;

     cout << "  Enter your choice: ";
     num_cases = check_num(3);


     while (test == 1) {
        switch (num_cases) {
            case 1:
                system("CLS");
                cout << "You chose 1 to create a database, Please enter the Name, ID, and GPA of the student\n";
    
                cout << "Enter name: ";
                getline(cin, name);
                while (name[0] < 65 || name[0] > 122) {
                    cout << "  Wrong input !\n";
                    getline(cin, name);
                }
    
                cout << "Enter ID: ";
                getline(cin, id);
    
                cout << "Enter GPA: ";
                while (!(cin >> gpa) || gpa > 10 || gpa < 0) {
                    cout << "  Wrong input! Please enter a valid GPA (0-10): ";
                    cin.clear();
                    while (cin.get() != '\n') continue;
                }
                cin.ignore();  // Clear the newline left in the buffer
    
                cout << "What type of database arrangement do you want?\n"
                     << "1-Name     2-ID \n";
                type = check_num(2);
    
                obj.create(type, name, id, gpa);
    
                num_cases = menu();
                break;
        
    
    

        case 2 :
system("CLS");
               cout << "  You chose 2 to insert data , Please enter number of students you want to save . \n" ;

               check_insert = 1 ;
               num_insert = check_num(0) ;

               for ( int j = 1 ; j <= num_insert ; j++)
               {
                   if ( check_insert == 1)
                   {
                   cout << " Please enter name of student , Please enter the Name, ID and GPA of the student\n";
                   getline(cin ,name);

                   while ( name[0] < 65 or name[0] > 122)
                   {
                   cout << "  Wrong Name ! \n";
                   getline(cin ,name);
                   }

                   getline(cin ,id);

                   while ( !(cin >> gpa) or gpa > 4)
                   {
                    cin.clear();
                    while ( cin.get() != '\n') continue;
                    cout << " Wrong input !\n";
                   }
                   while ( cin.get() != '\n') continue;

                  check_insert = obj.insertelement(name , id , gpa);
                  }
               }
                    num_cases = menu();

                 break;

        case 3 :
system("CLS");
              cout << "You chose 3 to delete data, Please enter number of students you want to delete  \n";

              check_del = 1 ;
              num_del = check_num(0);

               for ( int k = 1 ; k <= num_del ; k++)
               {
                   if ( check_del != 0)
                   {

                   cout << "Please enter ID of student \n";
                   getline(cin , id);
                   check_del = obj.deleteelement(id);
                   if ( check_del == 3) k-- ;
                   }
               }

                num_cases = menu();

                 break;

           case 4 :
system("CLS");
               cout << "You chose 4 to search on data,Please enter number of students you want to search on \n";
               check_search = 1 ;
               num_search = check_num();

               for ( int l = 1 ; l <= num_search ; l++)
               {
                   if ( check_search != 0 )
                   {
                   cout << " Please enter ID of student \n";
                   getline(cin , id);
                   check_search = obj.searchelement(id);
                   if ( check_search == 3) l--;
                   }
               }

            num_cases = menu();
                 break;


           case 5 :
           	system("CLS");
               obj.print() ;
               num_cases = menu();
                break ;

           case 6 :
system("CLS");
                int save_cheak ;
                save_cheak =obj.savefile();
                num_cases = menu();

                break ;

           case 7 :

                obj.help();
                num_cases = menu();
                break ;

           case 8 :

                exit(EXIT_SUCCESS);
                    break ;

           default :

            cout << "Wrong input ! \n";
            cout << "Enter your choice: \n";
            num_cases = check_num(3);
            break ;
         }
  }


    return 0;
}


int check_num(int x )
{
  int num ;

    switch ( x )
      {

       case 1 :
       case 2 :

               while ( !(cin >> num) or  num > 2)
               {
               cin.clear();
               while ( cin.get() != '\n') continue;
               cout << " Wrong input !\n";
               }
               while ( cin.get() != '\n') continue;
               break ;
       case 3 :
              while (  !(cin >> num) or  num > 8)
               {
               cin.clear();
               while ( cin.get() != '\n') continue;
               cout << " Wrong input !\n";
               }
               while ( cin.get() != '\n') continue;
               break ;

       default :

              while (  !(cin >> num)  )
               {
               cin.clear();
               while ( cin.get() != '\n') continue;
               cout << " Wrong input !\n";
               }
               while ( cin.get() != '\n') continue;
               break ;

      }

    return num ;
}
int login();
void show (void)
{
	login();

    cout << "\n\t------DATABASE MANAGEMENT SYSTEM------\n";
    cout << "=========================================\n";
    cout << "===  1) Create Database               ===\n";
    cout << "===  2) Insert Data                   ===\n";
    cout << "===  3) Delete Data                   ===\n";
    cout << "===  4) Search Data                   ===\n";
    cout << "===  5) Print Data                    ===\n";
    cout << "===  6) Save                          ===\n";
    cout << "===  7) Help                          ===\n";
    cout << "===  8) Exit                          ===\n";
    cout << "=========================================\n";
  }

  int login()
{
    string username, password = "";
    char ch;
    
    cout << "\n\t======= Database Management System =======";
    
    // Taking Username Input
    cout << "\n\tEnter Username: ";
    cin >> username;
    
    cout << "\n\tEnter Password: ";
    
    while (true) {
        ch = _getch();
        
        if (ch == 13) { // Enter key
            break;
        } else if (ch == 8) { // Backspace key
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // Erase character from console
            }
        } else {
            password.push_back(ch);
            cout << '*'; // Masking the password
        }
    }
    
    if (username == "user" && password == "pass") {
        cout << "\n\tAccess Granted\n";
    } else {
        cout << "\n\tAccess Aborted...Press Any Key To Try Again\n";
        _getch();
        system("CLS");
        login();
    }
    
    system("PAUSE");
    system("CLS");
    return 0;
}


int menu()
{
    int num_cases;
    cout << "  Do you want to do another operation?\n "
         << " 1- Yes   2-No \n";

    int t = check_num(1);

    if (t == 1)
    {
        system("cls");

        // Display menu options again without calling show() to prevent re-login
        cout << "\n\t------DATABASE MANAGEMENT SYSTEM------\n";
        cout << "=========================================\n";
        cout << "===  1) Create Database               ===\n";
        cout << "===  2) Insert Data                   ===\n";
        cout << "===  3) Delete Data                   ===\n";
        cout << "===  4) Search Data                   ===\n";
        cout << "===  5) Print Data                    ===\n";
        cout << "===  6) Save                          ===\n";
        cout << "===  7) Help                          ===\n";
        cout << "===  8) Exit                          ===\n";
        cout << "=========================================\n";
        
        cout << "Enter your choice: \n";
        num_cases = check_num(3);
        return num_cases;
    }
    else
    {
        return 8; // Exit the program
    }
}


