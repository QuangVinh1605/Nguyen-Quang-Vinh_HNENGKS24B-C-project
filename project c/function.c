#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>

void showMainMenu() {
    printf("*** HE THONG QUAN LY THU VIEN ***\n");
    printf("\n");
    printf("\t CHON VAI TRO\n");
    printf("========================================\n");
    printf("[1] Quan Ly Sach\n");
    printf("[2] Quan Ly Khach Hang\n");
    printf("[0] Thoat chuong trinh\n");
    printf("========================================\n");
    printf("Nhap lua chon cua ban: ");
}

void showLogin() {
    printf("*** HE THONG QUAN LY THU VIEN ***\n");
    printf("\n");
    printf("\t\t DANG NHAP\n");
    printf("==========================\n");
    printf("Email: ");
    printf("Mat khau: ");
    printf("==========================\n");
}

void printSeparator(int width) {
	int i;
    for (i= 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}
int isDuplicateID(Book book[],int n,char id[]){
	int j;
		for( j=0;j<n;j++){
				if(strcmp(id ,book[j].bookID)==0){
					return 1;
				} 
			}
			return 0;
}
int isDuplicateName(Book book[],int n,char name[]){
		int j;
	for(j=0;j<n;j++){
				if(strcmp(name ,book[j].bookName)==0){
					return 1;
				} 
			}
			return 0;
}
void toLowerCase(char str[]) {
		int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


//CHUC NANG QUAN LI SACH; 
void showBookManage() {
    printf("*** HE THONG QUAN LY THU VIEN ***\n");
    printf("\n");
    printf("\t\t MENU SACH\n");
    printf("======================\n");
    printf("[1] Hien thi danh sach sach\n");
    printf("[2] Them sach\n");
    printf("[3] Sua thong tin sach (khong duoc sua ID)\n");
    printf("[4] Xoa sach\n");
    printf("[5] Tim kiem sach theo ten\n");
    printf("[6] Sap xep sach theo gia tien\n");
    printf("[0] Thoat\n");
    printf("======================\n");
    printf("Nhap lua chon cua ban: ");
}

void loadBook(Book book[], int *n) {
    FILE *file = fopen("booklibrary.bin", "rb");
    if (file == NULL) {
        *n = 0;
        return;
    }
    fread(n, sizeof(int), 1, file);
    fread(book, sizeof(Book), *n, file);
    fclose(file);
}

void saveBook(Book book[], int n) {
    FILE *file = fopen("booklibrary.bin", "wb");
    if (file == NULL) {
        printf("Khong the luu vao file.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, file);
    fwrite(book, sizeof(Book), n, file);
    fclose(file);
}

void showBook(Book book[], int n) {
    if (n == 0) {
        printf("Khong co sach trong danh sach.\n");
        return;
    }

    printf("DANH SACH SACH\n");
    printSeparator(112);
    printf("| %-10s | %-40s | %-20s | %-20s | %-5s |\n", "ID", "Ten sach", "Tac gia", "The loai", "Gia");
    printSeparator(112);
	int i;
    for (i = 0; i < n; i++) {
        printf("| %-10s | %-40s | %-20s | %-20s | %-5.2f |\n",book[i].bookID, book[i].bookName, book[i].author, book[i].category, book[i].price);
        printSeparator(112);
    }
}
void addBook(Book book[], int *n) {
    int count;
    printf("Nhap so sach ban muon them: ");
    scanf("%d", &count);
    getchar();

    if (*n + count > 100) {
        printf("Khong du bo nho de them sach. Vui long thu lai voi so luong nho hon.\n");
        return;
    }
	int i;
    for ( i = 0; i < count; i++) {
        printf("\nNhap thong tin sach thu %d:\n", *n + 1);

        do {
            printf("Ma sach (6 ky tu): ");
            fgets(book[*n].bookID, sizeof(book[*n].bookID), stdin);
            book[*n].bookID[strcspn(book[*n].bookID, "\n")] = '\0';

            if (strlen(book[*n].bookID) == 0) {
                printf("Ma sach khong duoc de trong. Vui long nhap lai.\n");
            } else if (strlen(book[*n].bookID) != 6) {
                printf("Ma sach phai co dung 6 ky tu. Vui long nhap lai.\n");
            } else if (isDuplicateID(book, *n, book[*n].bookID)) {
                printf("Ma sach da ton tai. Vui long nhap ma khac.\n");
            } else {
                break;
            }
        } while (1);
        do {
            printf("Ten sach: ");
            fgets(book[*n].bookName, sizeof(book[*n].bookName), stdin);
            book[*n].bookName[strcspn(book[*n].bookName, "\n")] = '\0';

            if (strlen(book[*n].bookName) == 0) {
                printf("Ten sach khong duoc de trong. Vui long nhap lai.\n");
            } else if(isDuplicateName(book,*n,book[*n].bookName)){
            	printf("ten sach da ton tai.Vui long nhap ten khac.\n");
			}else{
		
              break;
            }
        } while (1);

        do {
            printf("Tac gia: ");
            fgets(book[*n].author, sizeof(book[*n].author), stdin);
            book[*n].author[strcspn(book[*n].author, "\n")] = '\0';

            if (strlen(book[*n].author) == 0) {
                printf("Tac gia khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("The loai: ");
            fgets(book[*n].category, sizeof(book[*n].category), stdin);
            book[*n].category[strcspn(book[*n].category, "\n")] = '\0';

            if (strlen(book[*n].category) == 0) {
                printf("The loai khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        printf("Gia tien: ");
        while (scanf("%f", &book[*n].price) != 1 || book[*n].price < 0) {
            getchar();
            printf("Gia tien khong hop le. Vui long nhap lai: ");
        }
        getchar();

        (*n)++;
    }

    printf("\nDa them %d sach thanh cong.\n", count);
    saveBook(book, *n);
}

void fixBook(Book book[], int n) {
    char id[20];
    printf("Nhap vao ID sach ban muon sua thong tin: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int flag = -1;
    	int i;
    for ( i = 0; i < n; i++) {
        if (strcmp(id, book[i].bookID) == 0) {
            flag = i;
            break;
        }
    }

    if (flag == -1) {
        printf("ID khong ton tai trong danh sach.\n");
        return;
    }
     printf("thong tin sach hien tai:\n");
     printSeparator(112);
        printf("| %-10s | %-40s | %-20s | %-20s | %-5s |\n", "ID", "Ten sach", "Tac gia", "The loai", "Gia");
         printSeparator(112);
        printf("| %-10s | %-40s | %-20s | %-20s | %-5.2f |\n",book[flag].bookID, book[flag].bookName, book[flag].author, book[flag].category, book[flag].price);
        printSeparator(112);

        do {
            printf("Ten sach: ");
            fgets(book[flag].bookName, sizeof(book[flag].bookName), stdin);
            book[flag].bookName[strcspn(book[flag].bookName, "\n")] = '\0';

            if (strlen(book[flag].bookName) == 0) {
                printf("Ten sach khong duoc de trong. Vui long nhap lai.\n");
			}else{
		
              break;
            }
        } while (1);

        do {
            printf("Tac gia: ");
            fgets(book[flag].author, sizeof(book[flag].author), stdin);
            book[flag].author[strcspn(book[flag].author, "\n")] = '\0';

            if (strlen(book[flag].author) == 0) {
                printf("Tac gia khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("The loai: ");
            fgets(book[flag].category, sizeof(book[flag].category), stdin);
            book[flag].category[strcspn(book[flag].category, "\n")] = '\0';

            if (strlen(book[flag].category) == 0) {
                printf("The loai khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        printf("Gia tien: ");
        while (scanf("%f", &book[flag].price) != 1 || book[flag].price < 0) {
            getchar();
            printf("Gia tien khong hop le. Vui long nhap lai: ");
        }
        getchar();
    printf("Cap nhat thong tin thanh cong.\n");
}
void deleteBook(Book book[], int *n) {
    char id[20];
    int conform;
    printf("Nhap vao ID sach ma ban muon xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int flag = -1;
    	int i;
    for ( i = 0; i < *n; i++) {
        if (strcmp(book[i].bookID, id) == 0) {
            flag = i;
			printf("ban co chac chan muon xoa khong: \n");
			printf("[1].co\n");
			printf("[2].khong\n");
			printf("nhap lua chon: \n");
			scanf("%d",&conform);
			getchar();
			if(conform==1){
				int j;
            for ( j = i; j < *n - 1; j++) {
                book[j] = book[j + 1];
            }
            (*n)--;
            break;  
        }else if(conform==2){
        	printf("da thoat ra menu\n");
        	return;
		}
    }
    }

    if (flag == -1) {
        printf("ID khong ton tai trong danh sach.\n");
        return;
    }

    printf("Xoa sach thanh cong.\n");
}
void sortBook(Book book[], int n) {
    int choice;
    printf("Chon thu tu sap xep:\n");
    printf("[1] Sap xep tang dan theo gia tien\n");
    printf("[2] Sap xep giam dan theo gia tien\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    getchar();

    if (choice != 1 && choice != 2) {
        printf("Lua chon khong hop le. Vui long thu lai.\n");
        return;
    }
	int i;
		int j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n-i-1; j++) {
            if ((choice==1&&book[j].price>book[j+1].price)||(choice==2&&book[j].price<book[j+1].price)) {
                Book temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }

    printf("Danh sach sach sau khi sap xep:\n");
    showBook(book, n);
}
void searchBook(Book book[], int n) {
    char name[50], tempBookName[50], tempInput[50];
    printf("Moi ban nhap vao ten sach ma ban muon tim kiem: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int found = 0;
    strcpy(tempInput, name);
    toLowerCase(tempInput);

    printf("\nKet qua tim kiem:\n");
 	int i;
    for (i = 0; i < n; i++) {
        strcpy(tempBookName, book[i].bookName);
        toLowerCase(tempBookName);

    if (strstr(tempBookName, tempInput) != NULL) {
    if (!found) {
    printSeparator(112);
    printf("| %-10s | %-40s | %-20s | %-20s | %-5s |\n", "ID", "Ten sach", "Tac gia", "The loai", "Gia");
    printSeparator(112);
    found = 1;
    }
    printf("| %-10s | %-40s | %-20s | %-20s | %-5.2f |\n",
    book[i].bookID, book[i].bookName, book[i].author, book[i].category, book[i].price);
    }
    }

    if (found) {
        printSeparator(112);
    } else {
        printf("Khong tim thay sach nao phu hop voi ten '%s'.\n", name);
    }
}

	 

//CHUC NANG QUAN LI KHACH HANG 
void showCustomerManage() {
    printf("*** HE THONG QUAN LY THU VIEN ***\n");
    printf("\n");
    printf("\t\t MENU KHACH HANG\n");
    printf("=======================\n");
    printf("[1] Hien thi danh sach khach hang\n");
    printf("[2] Them khach hang\n");
    printf("[3] Sua thong tin khach hang\n");
    printf("[4] Khoa/Mo khoa khach hang\n");
    printf("[5] Tim kiem khach hang theo ten\n");
    printf("[6] Cho muon sach\n");
    printf("[7] Tra sach\n");
    printf("=======================\n");
    printf("Nhap lua chon cua ban: ");
}
void loadCustomer(Customer customer[], int *n) {
    FILE *file = fopen("customers.dat", "rb");
    if (file == NULL) {
        printf("Khong tim thay file du lieu. Ban co the them du lieu moi.\n");
        return;
    }

    fread(n, sizeof(int), 1, file); 
    fread(customer, sizeof(Customer), *n, file);

    fclose(file);
    printf("Du lieu da duoc tai ve tu file 'customers.dat'.\n");
}
void saveCustomer(Customer customer[], int n) {
    FILE *file = fopen("customers.dat", "wb");
    if (file == NULL) {
        printf("Loi khi mo file.\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, file);
    fwrite(customer, sizeof(Customer), n, file);

    fclose(file);
    printf("Du lieu da luu vào file 'customers.dat'.\n");
}
void showCustomer(Customer customer[], int n) {
    if (n == 0) {
        printf("Khong co khach hang trong danh sach.\n");
        return;
    }

    printf("DANH SACH KHACH HANG\n");
    printSeparator(90);
    printf("| %-10s | %-20s | %-30s | %-15s |\n", "ID", "Ho ten", "Dia chi", "PHONE");
    printSeparator(90);

    int i;
    for (i = 0; i < n; i++) {
        printf("| %-10s | %-20s | %-30s | %-15s |\n", customer[i].customerID, customer[i].name, customer[i].address, customer[i].phone);
        printSeparator(90);
    }
}

void addCustomer(Customer customer[], int *n) {
    int count;
    printf("Nhap so khach hang ban muon them: ");
    scanf("%d", &count);
    getchar();

    if (*n + count > 100) {
        printf("Khong du bo nho de them khach hang. Vui long thu lai voi so luong nho hon.\n");
        return;
    }
    
    int i;
    for (i = 0; i < count; i++) {
        printf("\nNhap thong tin khach hang thu %d:\n", *n + 1);

        do {
            printf("ID khach hang (6 ky tu): ");
            fgets(customer[*n].customerID, sizeof(customer[*n].customerID), stdin);
            customer[*n].customerID[strcspn(customer[*n].customerID, "\n")] = '\0';

            if (strlen(customer[*n].customerID) == 0) {
                printf("ID khach hang khong duoc de trong. Vui long nhap lai.\n");
            } else if (strlen(customer[*n].customerID) != 6) {
                printf("ID khach hang phai co dung 6 ky tu. Vui long nhap lai.\n");
            } else if (isDuplicateID(customer, *n, customer[*n].customerID)) {
                printf("ID khach hang da ton tai. Vui long nhap ID khac.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("Ho ten: ");
            fgets(customer[*n].name, sizeof(customer[*n].name), stdin);
            customer[*n].name[strcspn(customer[*n].name, "\n")] = '\0';

            if (strlen(customer[*n].name) == 0) {
                printf("Ho ten khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("Dia chi: ");
            fgets(customer[*n].address, sizeof(customer[*n].address), stdin);
            customer[*n].address[strcspn(customer[*n].address, "\n")] = '\0';

            if (strlen(customer[*n].address) == 0) {
                printf("Dia chi khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        do {
            printf("So dien thoai: ");
            fgets(customer[*n].phone, sizeof(customer[*n].phone), stdin);
            customer[*n].phone[strcspn(customer[*n].phone,"\n")] = '\0';

            if (strlen(customer[*n].phone) == 0) {
                printf("So dien thoai khong duoc de trong. Vui long nhap lai.\n");
            } else {
                break;
            }
        } while (1);

        (*n)++;
    }

    printf("\nDa them %d khach hang thanh cong.\n", count);
    saveCustomer(customer, *n);
}

void fixCustomer(Customer customer[], int n) {
    char id[20];
    printf("Nhap vao ID khach hang ban muon sua thong tin: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int flag = -1;
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(id, customer[i].customerID) == 0) {
            flag = i;
            break;
        }
    }

    if (flag == -1) {
        printf("ID khach hang khong ton tai.\n");
        return;
    }

    printf("Thong tin khach hang hien tai:\n");
    printSeparator(90);
    printf("| %-10s | %-20s | %-30s | %-15s |\n", "ID", "Ho ten", "Dia chi", "PHONE");
    printSeparator(90);
    printf("| %-10s | %-20s | %-30s | %-15s |\n", customer[flag].customerID, customer[flag].name, customer[flag].address, customer[flag].phone);
    printSeparator(90);

    do {
        printf("Ho ten: ");
        fgets(customer[flag].name, sizeof(customer[flag].name), stdin);
        customer[flag].name[strcspn(customer[flag].name, "\n")] = '\0';

        if (strlen(customer[flag].name) == 0) {
            printf("Ho ten khong duoc de trong. Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Dia chi: ");
        fgets(customer[flag].address, sizeof(customer[flag].address), stdin);
        customer[flag].address[strcspn(customer[flag].address, "\n")] = '\0';

        if (strlen(customer[flag].address) == 0) {
            printf("Dia chi khong duoc de trong. Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("So dien thoai: ");
        fgets(customer[flag].phone, sizeof(customer[flag].phone), stdin);
        customer[flag].phone[strcspn(customer[flag].phone, "\n")] = '\0';

        if (strlen(customer[flag].phone) == 0) {
            printf("So dien thoai khong duoc de trong. Vui long nhap lai.\n");
        } else {
            break;
        }
    } while (1);

    printf("Cap nhat thong tin thanh cong.\n");
}

