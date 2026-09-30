#include <stdio.h>

#define MAX_SIZE 50

int main(void) 
{ int steps[MAX_SIZE] = {4500, 8200, 6000, 3200, 10000}; 
int n = 5; 
int choice; 
int value; 
int pos;

do {
    printf(" CHUONG TRINH QUAN LY BUOC CHAN\n");
    printf("1. Them so buoc chan\n");
    printf("2. Sua so buoc chan\n");
    printf("3. Xoa so buoc chan\n");
    printf("4. Tim kiem so buoc chan\n");
    printf("0. Thoat chuong trinh\n");

    printf("Vui long nhap lua chon (0 - 4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Them so buoc chan\n");

            if (n == MAX_SIZE) {
                printf("Mang da day, khong the them!\n");
                break;
            }

            printf("Nhap so buoc chan can them: ");
            scanf("%d", &value);

            if (value < 0) {
                printf("So buoc chan khong hop le!\n");
                break;
            }

            printf("Nhap vi tri muon chen (1 - %d): ", n + 1);
            scanf("%d", &pos);

            if (pos < 1 || pos > n + 1) {
                printf("Vi tri chen khong hop le!\n");
                break;
            }

            for (int i = n; i >= pos; i--) {
                steps[i] = steps[i - 1];
            }

            steps[pos - 1] = value;
            n++;

            printf("Chen thanh cong!\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", steps[i]);
            }
            printf("\n");
            break;

        case 2:
            printf("Sua so buoc chan\n");

            printf("Nhap vi tri can sua: ");
            scanf("%d", &pos);

            if (pos < 1 || pos > n) {
                printf("Vi tri sua khong hop le!\n");
                break;
            }

            printf("Nhap so buoc chan moi: ");
            scanf("%d", &value);

            if (value < 0) {
                printf("So buoc chan khong hop le!\n");
                break;
            }

            steps[pos - 1] = value;

            printf("Sua thanh cong!\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", steps[i]);
            }
            printf("\n");
            break;

        case 3:
            printf("Xoa so buoc chan\n");

            if (n == 0) {
                printf("Mang rong, khong the xoa!\n");
                break;
            }

            printf("Nhap vi tri can xoa: ");
            scanf("%d", &pos);

            if (pos < 1 || pos > n) {
                printf("Vi tri xoa khong hop le!\n");
                break;
            }

            for (int i = pos - 1; i < n - 1; i++) {
                steps[i] = steps[i + 1];
            }

            n--;

            printf("Xoa thanh cong!\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", steps[i]);
            }
            printf("\n");
            break;

        case 4:
            printf("Tim kiem so buoc chan\n");

            printf("Nhap so buoc chan can tim: ");
            scanf("%d", &value);

            {
                int count = 0;

                printf("Tim thay tai vi tri: ");

                for (int i = 0; i < n; i++) {
                    if (steps[i] == value) {
                        printf("%d ", i + 1);
                        count++;
                    }
                }

                if (count == 0) {
                    printf("\nKhong tim thay gia tri trong mang!\n");
                } else {
                    printf("\nTong so lan xuat hien: %d\n", count);
                }
            }
            break;

        case 0:
            printf("Thoat chuong trinh!\n");
            break;

        default:
            printf("Lua chon khong hop le, vui long nhap lai!\n");
    }

} while (choice != 0);

return 0;
}
