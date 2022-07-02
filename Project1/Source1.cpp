#include <iostream>
using namespace std;
int price;
int counter = 0;
//array of struct for the members(buyers or sellers)
struct member {
    int id;
    string email = { "user@gmail.com" };
    string name = { "user" };
    string password = { "1234" };
    string delivery_address{ "helwan" };
    long long phone_number = { 0100123 };
    int points = { 2 };
    string statue = { "buyer" };
    string items[100];
} add[100];


//array of struct for items
struct date {
    int day;
    int month;
    int year;
};
struct items
{
    int number;
    string category;
    double start_price;
    date dateofBuying;
    string status;
}
s[100];
void show_last_month_sales(int index)
{

    if (s[index].status == "sold")
    {

    }


}

//this function allows user to log in or register email
void sign_up()
{

    for (int i = counter; i < 2; i++)
    {
        cout << "enter your id : ";
        cin >> add[i].id;
        cout << "enter your name : ";
        cin >> add[i].name;
        cout << "enter your email : ";
        cin >> add[i].email;
        cout << "enter your password : ";
        cin >> add[i].password;
        cout << "enter your delivery address : ";
        cin >> add[i].delivery_address;
        cout << "enter your phone number : ";
        cin >> add[i].phone_number;
        cout << "enter your points : ";
        cin >> add[i].points;
        cout << "you are buyer or seller:";
        cin >> add[i].statue;

    }
}
//this function allow user to search by category name or category name and price 
void search_items(int index)
{
    string category;
    int price;
    if (index == 1)
    {
        cout << "enter your category:";
        cin >> category;
        for (int i = 0; i < 100; i++)
        {
            if (category == s[i].category)
            {

                cout << "details about this item" << endl;
                cout << "category = " << s[i].category << endl;
                cout << " the date is:" << s[i].dateofBuying.day << "/" << s[i].dateofBuying.month << "/" << s[i].dateofBuying.year << endl;
                cout << "start price of this item is:" << s[i].start_price << endl;
                cout << "status is :" << s[i].status << endl;
                cout << "number:" << s[i].number << endl;
                cout << "1.do you agree this price" << endl << "2.enter your price do you want" << endl;
                int agreeing;
                cin >> agreeing;
                if (agreeing == 1)
                {
                    cout << "Make sucussful" << endl;
                    s[i].status = "sold";
                    show_last_month_sales(i);
                }
                else if (agreeing == 2)
                {
                    double price;
                    cout << "enter your price" << endl;
                    cin >> price;
                    cout << "your request was sent" << endl;
                }
                break;
            }
            else
            {
                cout << "this items doesn't exist" << endl;
                break;
            }
        }
    }
    else if (index == 2)
    {
        cout << "enter your category:";
        cin >> category;
        cout << "enteryour price:";
        cin >> price;
        for (int i = 0; i < 100; i++)
        {
            if (category == s[i].category && price == s[i].start_price)
            {
                cout << "details about this items \n";
                cout << "category = " << s[i].category << endl;
                cout << "the date is:" << s[i].dateofBuying.day << "/" << s[i].dateofBuying.month << "/" << s[i].dateofBuying.year << endl;
                cout << "start price is :" << s[i].start_price << endl;
                cout << "status is:" << s[i].status << endl;
                cout << "the number:" << s[i].number << endl;
            }
            else
            {
                cout << "sorry, this item doesn't exist" << endl;
                break;
            }
        }
    }
}
//This function allows to the user to sent buying requset
// THis function to sign in user's account by email and password only.

void sign_in()
{
    string email, category, password; char choice; int a;
    cout << "Enter your email please\n";
    cin >> email;
    cout << "Enter you password please\n";
    cin >> password;
    for (int i = 0; i < 100; i++)
    {
        if (email == add[i].email && password == add[i].password)
        {
            if (add[i].statue == "seller")
            {
                cout << "to add items press (a)" << endl;
                cin >> choice;
                if (choice == 'a' || choice == 'A')
                    cout << "how many items : ";
                cin >> a;
                for (int j = 0; j < a; j++)
                {
                    cout << "write the type :: ";
                    cin >> add[i].items[j];
                }
                cout << "the operation had completed\n";
            }
            else
            {

                cout << "to search about items press (s)\n";
                cin >> choice;
                if (choice == 's' || choice == 'S')
                {
                    int search;
                    cout << "you need" << endl << "1-search by category only" << endl << "2-both category and price";
                    cin >> search;
                    search_items(search);
                    break;

                }
            }
        }
    }

}
void send_request()
{
    int requset;
    cout << "1-I want to send buying request \n";
    cout << "2-I don't want this operation \n";
    cin >> requset;
    if (requset == 1)
    {
        cout << "Enter the price do you want \n";
        cin >> price;
        cout << "your request was sent \n";
    }
    else
    {
        cout << "No porblem \n";

    }

}
//This function allows to the seller to allow or refuse the requset of buying from user
void received_requset()
{
    cout << " the seller only can enter the value of this operation \n";
    int received;
    cout << "1.the seller is agree for this requset \n";
    cout << "2.the seller is not agree for this request \n";
    cin >> received;
    if (received == 1)
    {
        cout << "Good, this operation of buying was made successfully \n ";
    }
    else
    {
        cout << "Sorry, the seller was not agree for this price \n";
    }
}
void handle()
{
    string handle;
    cout << "Enter your handle \n";
    cin >> handle;
    cout << "Well done \n";

}
void feedback()
{
    int rate;
    string feed;
    cout << "please Enter your feedback\n";
    cin >> feed;
    cout << "please enter the rate for seller \n";
    cin >> rate;
    if (rate >= 3)
    {
        add[rate].points += 1;
        cout << "you have a new point \n";
    }
    else
        cout << " it's Bad\n";
}
void menu()
{
    int enter;
    do {


        cout << " ######### Welcome to  Online auction system ##########" << endl;
        cout << "1)sign up \n";
        cout << "2)sign in \n";
        cout << "3)send buying request\n";
        cout << "4)Request received\n";
        cout << "5)handle rquests\n";
        cout << "6)give feedback\n";
        cout << "7)show last month sales\n";
        cout << "8)Exit\n";
        cout << "please select your choice from above #_#";
        cin >> enter;
        switch (enter)
        {
        case 1:
            sign_up();
            break;
        case 2:
            sign_in();
            break;
        case 3:
            send_request();
            break;
        case 4:
            received_requset();
            break;
        case 5:
            handle();
            break;
        case 6:
            feedback();
            break;
        case 7:
            break;
        default:
            exit(-1);
            break;
        }

    } while (enter != 8);

}
int main()
{
    s[0].number = 1;
    s[0].dateofBuying.day = 1;
    s[0].dateofBuying.month = 7;
    s[0].dateofBuying.year = 2020;
    s[0].category = "car";
    s[0].start_price = 200000;
    s[0].status = "available";

    s[1].number = 2;
    s[1].dateofBuying.day = 2;
    s[1].dateofBuying.month = 7;
    s[1].dateofBuying.year = 2020;
    s[1].category = "mobile";
    s[1].start_price = 5000;
    s[1].status = "available";

    s[2].number = 3;
    s[2].dateofBuying.day = 3;
    s[2].dateofBuying.month = 7;
    s[2].dateofBuying.year = 2020;
    s[2].category = "cover";
    s[2].start_price = 50;
    s[2].status = "available";

    menu();


    system("pause");
    return 0;
}
