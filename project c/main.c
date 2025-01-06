#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "datatype.h"

int main(int argc, char *argv[]) {
    int choice; 
    int choice1;
    int choice2;
    int n = 0;
    Book book[100];
    Customer customer[100];
    
    loadBook(book, &n);  // T?i danh sách sách
    loadCustomer(customer, &n);  // T?i danh sách khách hàng
    do {
        showMainMenu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
        case 1: { 
            system("cls");
            // Ch?c nãng qu?n l? sách 
            do {
                showBookManage();
                scanf("%d", &choice1);
                getchar();

                switch (choice1) {
                case 1: {  
                    system("cls");                  
                    showBook(book, n);
                    break;
                }
                case 2: {  
                    system("cls");                 
                    addBook(book, &n);
                    saveBook(book, n);
                    break;
                }
                case 3: { 
                    system("cls");                   
                    fixBook(book, n);
                    saveBook(book, n);
                    break;
                }
                case 4: {  
                    system("cls");                   
                    deleteBook(book, &n);
                    saveBook(book, n);
                    break;
                }
                case 5: {  
                    system("cls");         
                    searchBook(book, n);
                    break;
                }
                case 6: {
                    system("cls");          
                    sortBook(book, n);
                    saveBook(book, n);
                    break;
                }
                case 0: {
                    system("cls");                           
                    printf("Thoat khoi menu quan ly sach thanh cong.\n");
                    break;
                }
                default: {
                    printf("Lua chon khong hop le. Vui long chon lai\n");
                    break;
                }
                }
            } while (choice1 != 0);
            break;
        }
        case 2: {
            system("cls");
            do {
                showCustomerManage();
                scanf("%d", &choice2);
                getchar();

                switch (choice2) {
                case 1: {  
                    system("cls");                
                    showCustomer(customer, n);
                    break;
                }
                case 2: {  
                    system("cls");                 
                    addCustomer(customer, &n);
                    saveCustomer(customer, n);
                    break;
                }
                case 3: { 
                    system("cls");                   
                    fixCustomer(customer, n);
                    saveCustomer(customer, n);
                    break;
                }
                case 4: {  
                    break;
                }
                case 5: {  
                    break;
                }
                case 6: {

                    break;
                }
                case 7: {
                    break;
                }
                case 0: {
                    system("cls");
                    printf("Thoat khoi menu quan ly khach hang thanh cong.\n");
                    break;
                }
                default: {
                    printf("Lua chon khong hop le. Vui long chon lai\n");
                    break;
                }
                }
            } while (choice2 != 0);
            break;
        }
        case 0: {
            system("cls");
            printf("Thoat chuong trinh thanh cong\n");
            break;
        }
        default: {
            printf("Lua chon khong hop le. Vui long chon lai\n");
            break;
        }
        }
    } while (choice != 0);

    return 0;
}

