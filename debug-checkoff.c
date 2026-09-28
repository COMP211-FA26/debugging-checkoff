#include <stdio.h>

int find_seat(int seats[], int count, int requested) {
    int position = -1;

    for (int i = 0; i < count; i++) {
        if (seats[i] == requested) {
            position = i;
        }
    }

    return position;
}

int calculate_price(int base_price, int student, int matinee) {
    int price = base_price;

    if (student == 1) {
        price -= 4;
    } else if (matinee == 1) {
        price -= 3;
    }

    return price;
}

int reserve_seat(int seats[], int count, int requested, int student,
                 int matinee) {
    int position = find_seat(seats, count, requested);

    if (position == -1) {
        return -1;
    }

    int base_price = 15;
    int final_price = calculate_price(base_price, student, matinee);

    printf("Seat %d reserved.\n", requested);
    printf("Ticket price: $%d\n", final_price);

    return position;
}

int main(void) {
    int seats[] = {12, 18, 24, 31, 37, 42};
    int count = 6;
    int requested;
    int student = 1;
    int matinee = 1;

    printf("Enter seat number: ");
    scanf("%d", &requested);

    int position = reserve_seat(seats, count, requested, student, matinee);

    if (position == -1) {
        printf("Seat not found.\n");
    } else {
        printf("Reservation complete.\n");
    }

    return 0;
}