#include <bits/stdc++.h>
using namespace std;
string fi = "FISH_PRICE";
string ch="CHICKEN_PRICE";
string bu="BURGER_PRICE";
string pi="PIZZA_PRICE";
string sa="SALAD_PRICE";
string pa="PASTA_PRICE";
string st="STEAK_PRICE";
string su="SUSHI_PRICE";
string ta="TACOS_PRICE";
string san="SANDWICH_PRICE";
string sh="SHRIMP_SCAMPI_PRICE";
string bur="BURRITO_PRICE";
string bb="BBQ_RIBS_PRICE";
string ca="CAESAR_SALAD_PRICE";
string la="LASAGNA_PRICE";
string lo="LOBSTER_PRICE";
string gy="GYRO_PRICE";
string qu="QUESADILLA_PRICE";
string chi="CHICKEN_ALFREDO_PRICE";
string cho="CHOCOLATE_CAKE_PRICE";
string ic="ICE_CREAM_PRICE";
string shr="SHRIMP_STIR_FRY_PRICE";
string na="NACHOS_PRICE";
string pan="PANCAKES_PRICE";
string fr="FRUIT_SALAD_PRICE";
const int MAX_CUSTOMERS = 10;
const int FISH_PRICE = 13;
const int CHICKEN_PRICE = 10;
const int BURGER_PRICE = 8;
const int PIZZA_PRICE = 11;
const int SALAD_PRICE = 7;
const int PASTA_PRICE = 12;
const int STEAK_PRICE = 16;
const int SUSHI_PRICE = 14;
const int TACOS_PRICE = 8;
const int SANDWICH_PRICE = 6;
const int SHRIMP_SCAMPI_PRICE = 15;
const int BURRITO_PRICE = 9;
const int BBQ_RIBS_PRICE = 17;
const int CAESAR_SALAD_PRICE = 10;
const int LASAGNA_PRICE = 13;
const int LOBSTER_PRICE = 20;
const int GYRO_PRICE = 8;
const int QUESADILLA_PRICE = 9;
const int CHICKEN_ALFREDO_PRICE = 12;
const int CHOCOLATE_CAKE_PRICE = 5;
const int ICE_CREAM_PRICE = 4;
const int SHRIMP_STIR_FRY_PRICE = 13;
const int NACHOS_PRICE = 8;
const int PANCAKES_PRICE = 7;
const int FRUIT_SALAD_PRICE = 5;
struct Order {
    string item;
    int price;
    Order* next;
};
struct node{
    string name;
    float check;
    node *next;
    node *prev;
    int table;
    Order* orderList;
};
node *head = NULL;
node *tail = NULL;
void addToOrderList(node*customer,string item,int price){
    Order *newOrder = new Order;
    newOrder->item = item;
    newOrder->price= price;
    newOrder->next = customer->orderList;
    customer->orderList = newOrder;
}
void deleteOrderList(Order*& orderList) {
    while (orderList != NULL) {
        Order* temp = orderList;
        orderList = orderList->next;
        delete temp;
    }
}
void deleteCustomerList(node*& head) {
    while (head != NULL) {
        node* tempCustomer = head;
        head = head->next;
        deleteOrderList(tempCustomer->orderList);
        delete tempCustomer;
    }
}
void displayOrderList(Order* orderList) {
    Order* current = orderList;
    while (current != NULL) {
        cout << "Item: " << current->item << ", $" << current->price << endl;
        current = current->next;
    }
}
void addCustomer(string name,int table){
    node* newName = new node;
    newName->name = name;
    newName->next = NULL;
    newName->prev = NULL;
    newName->table = table;
    if(head ==NULL){
        tail = head= newName;
    }
    else{
        tail->next = newName;
        newName->prev = tail;
        tail = newName;
    }
}
void addPrice(int totalPrice, node* currentCustomer) {
    currentCustomer->check = totalPrice;
}
void displayCustomerInfo(node* customer){
    cout<<"Customer Name: "<<customer->name<<endl;
    cout<<"Table Number: "<<customer->table<<endl;
    cout<<"Order list:"<<endl;
    displayOrderList(customer->orderList);
    cout<<"Total Check: "<<customer->check<<endl;
}
node* findCustomerByTable(int tableNumber) {
    node* current = head;
    while (current != NULL) {
        if (current->table == tableNumber) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void menu(){
    cout << "Food Menu:" << endl;
    cout << "1. Fish - $" << FISH_PRICE << endl;
    cout << "2. Chicken - $" << CHICKEN_PRICE << endl;
    cout << "3. Burger - $" << BURGER_PRICE << endl;
    cout << "4. Pizza - $" << PIZZA_PRICE << endl;
    cout << "5. Salad - $" << SALAD_PRICE << endl;
    cout << "6. Pasta - $" << PASTA_PRICE << endl;
    cout << "7. Steak - $" << STEAK_PRICE << endl;
    cout << "8. Sushi - $" << SUSHI_PRICE << endl;
    cout << "9. Tacos - $" << TACOS_PRICE << endl;
    cout << "10. Sandwich - $" << SANDWICH_PRICE << endl;
    cout << "11. Shrimp Scampi - $" << SHRIMP_SCAMPI_PRICE << endl;
    cout << "12. Burrito - $" << BURRITO_PRICE << endl;
    cout << "13. BBQ Ribs - $" << BBQ_RIBS_PRICE << endl;
    cout << "14. Caesar Salad - $" << CAESAR_SALAD_PRICE << endl;
    cout << "15. Lasagna - $" << LASAGNA_PRICE << endl;
    cout << "16. Lobster - $" << LOBSTER_PRICE << endl;
    cout << "17. Gyro - $" << GYRO_PRICE << endl;
    cout << "18. Quesadilla - $" << QUESADILLA_PRICE << endl;
    cout << "19. Chicken Alfredo - $" << CHICKEN_ALFREDO_PRICE << endl;
    cout << "20. Chocolate Cake - $" << CHOCOLATE_CAKE_PRICE << endl;
    cout << "21. Ice Cream - $" << ICE_CREAM_PRICE << endl;
    cout << "22. Shrimp Stir Fry - $" << SHRIMP_STIR_FRY_PRICE << endl;
    cout << "23. Nachos - $" << NACHOS_PRICE << endl;
    cout << "24. Pancakes - $" << PANCAKES_PRICE << endl;
    cout << "25. Fruit Salad - $" << FRUIT_SALAD_PRICE << endl;
    cout << "Enter your choice (1-25): " << endl;
}
int main() {
    int totalPrice = 0;
    int table[MAX_CUSTOMERS]={0};
    int t=1;
    string name;
    while (t!=0) {
    cout << "table number?"<<endl;
    cin >> t;
    table[t]++;
        cout << "Enter customer name: ";
        cin>>name;
        addCustomer(name, t);
        cout << "Welcome, how would you like me to help you "<<name<<"?" << endl;
        cout << "Menu please          " << "Check please" << endl;
        char c;
        cin >> c;
        if (c == 'm') {
            if (table[t]<=1) {
                menu();
                int choice = -1;
                while (choice != 0) {
                    cin >> choice;
                    node* new_CustomerOrder = findCustomerByTable(t);
                    switch (choice) {
                        case 1:
                            totalPrice += FISH_PRICE;
                            addToOrderList(new_CustomerOrder, fi, FISH_PRICE);
                            break;
                        case 2:
                            totalPrice += CHICKEN_PRICE;
                            addToOrderList(new_CustomerOrder, ch, CHICKEN_PRICE);
                            break;
                        case 3:
                            totalPrice += BURGER_PRICE;
                            addToOrderList(new_CustomerOrder, bu, BURGER_PRICE);
                            break;
                        case 4:
                            totalPrice += PIZZA_PRICE;
                            addToOrderList(new_CustomerOrder, pi, PIZZA_PRICE);
                            break;
                        case 5:
                            totalPrice += SALAD_PRICE;
                            addToOrderList(new_CustomerOrder, sa, SALAD_PRICE);
                            break;
                        case 6:
                            totalPrice += PASTA_PRICE;
                            addToOrderList(new_CustomerOrder, pa, PASTA_PRICE);
                            break;
                        case 7:
                            totalPrice += STEAK_PRICE;
                            addToOrderList(new_CustomerOrder, st, STEAK_PRICE);
                            break;
                        case 8:
                            totalPrice += SUSHI_PRICE;
                            addToOrderList(new_CustomerOrder, su, SUSHI_PRICE);
                            break;
                        case 9:
                            totalPrice += TACOS_PRICE;
                            addToOrderList(new_CustomerOrder, ta, TACOS_PRICE);
                            break;
                        case 10:
                            totalPrice += SANDWICH_PRICE;
                            addToOrderList(new_CustomerOrder, san, SANDWICH_PRICE);
                            break;
                        case 11:
                            totalPrice += SHRIMP_SCAMPI_PRICE;
                            addToOrderList(new_CustomerOrder, sh, SHRIMP_SCAMPI_PRICE);
                            break;
                        case 12:
                            totalPrice += BURRITO_PRICE;
                            addToOrderList(new_CustomerOrder, bur, BURRITO_PRICE);
                            break;
                        case 13:
                            totalPrice += BBQ_RIBS_PRICE;
                            addToOrderList(new_CustomerOrder, bb, BBQ_RIBS_PRICE);
                            break;
                        case 14:
                            totalPrice += CAESAR_SALAD_PRICE;
                            addToOrderList(new_CustomerOrder, ca, CAESAR_SALAD_PRICE);
                            break;
                        case 15:
                            totalPrice += LASAGNA_PRICE;
                            addToOrderList(new_CustomerOrder, la, LASAGNA_PRICE);
                            break;
                        case 16:
                            totalPrice += LOBSTER_PRICE;
                            addToOrderList(new_CustomerOrder, lo, LOBSTER_PRICE);
                            break;
                        case 17:
                            totalPrice += GYRO_PRICE;
                            addToOrderList(new_CustomerOrder, gy, GYRO_PRICE);
                            break;
                        case 18:
                            totalPrice += QUESADILLA_PRICE;
                            addToOrderList(new_CustomerOrder, qu, QUESADILLA_PRICE);
                            break;
                        case 19:
                            totalPrice += CHICKEN_ALFREDO_PRICE;
                            addToOrderList(new_CustomerOrder, chi, CHICKEN_ALFREDO_PRICE);
                            break;
                        case 20:
                            totalPrice += CHOCOLATE_CAKE_PRICE;
                            addToOrderList(new_CustomerOrder, cho, CHOCOLATE_CAKE_PRICE);
                            break;
                        case 21:
                            totalPrice += ICE_CREAM_PRICE;
                            addToOrderList(new_CustomerOrder, ic, ICE_CREAM_PRICE);
                            break;
                        case 22:
                            totalPrice += SHRIMP_STIR_FRY_PRICE;
                            addToOrderList(new_CustomerOrder, shr, SHRIMP_STIR_FRY_PRICE);
                            break;
                        case 23:
                            totalPrice += NACHOS_PRICE;
                            addToOrderList(new_CustomerOrder, na, NACHOS_PRICE);
                            break;
                        case 24:
                            totalPrice += PANCAKES_PRICE;
                            addToOrderList(new_CustomerOrder, pan, PANCAKES_PRICE);
                            break;
                        case 25:
                            totalPrice += FRUIT_SALAD_PRICE;
                            addToOrderList(new_CustomerOrder, fr, FRUIT_SALAD_PRICE);
                            break;
                        default:
                            break;
                    }
                    addPrice(totalPrice, new_CustomerOrder);
                }
            }
            else{
                cout<<"This Table is not empty:"<<endl;
                table[t]--;
            }
        } else if (c == 'c') {

            cout << "Okay, one second, please" << endl;
            node* customerToDisplay = findCustomerByTable(t);
            if (customerToDisplay != NULL) {
                cout << "Customer information for table " << t << ":" << endl;
                displayCustomerInfo(customerToDisplay);
                deleteCustomerList(customerToDisplay);
                table[t]=0;
            } else {
                cout << "Customer not found for table " << t << "." << endl;
            }
        }
        totalPrice = 0;
    }
    return 0;
}