#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define NAME_LEN 30

struct Stock {
    char name[NAME_LEN];
    float price;
};

struct Portfolio {
    int quantity[MAX_STOCKS];
    float balance;
};

void displayStocks(struct Stock stocks[]) {
    printf("\nAvailable Stocks:\n");
    printf("ID\tName\t\tPrice\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("%d\t%s\t\t%.2f\n", i, stocks[i].name, stocks[i].price);
    }
}

void updatePrices(struct Stock stocks[]) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        float change = ((rand() % 200) - 100) / 100.0; 
        stocks[i].price += change;
        if (stocks[i].price < 1)
            stocks[i].price = 1;
    }
}

void buyStock(struct Stock stocks[], struct Portfolio *p) {
    int id, qty;
    displayStocks(stocks);
    printf("Enter Stock ID to buy: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    float cost = stocks[id].price * qty;
    if (cost <= p->balance) {
        p->quantity[id] += qty;
        p->balance -= cost;
        printf("Stock purchased successfully.\n");
    } else {
        printf("Insufficient balance.\n");
    }
}

void sellStock(struct Stock stocks[], struct Portfolio *p) {
    int id, qty;
    displayStocks(stocks);
    printf("Enter Stock ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    if (p->quantity[id] >= qty) {
        p->quantity[id] -= qty;
        p->balance += stocks[id].price * qty;
        printf("Stock sold successfully.\n");
    } else {
        printf("Not enough stocks to sell.\n");
    }
}

void viewPortfolio(struct Stock stocks[], struct Portfolio p) {
    printf("\nYour Portfolio:\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (p.quantity[i] > 0) {
            printf("%s : %d shares @ %.2f\n", stocks[i].name, p.quantity[i], stocks[i].price);
        }
    }
    printf("Available Balance: %.2f\n", p.balance);
}

int main() {
    struct Stock stocks[MAX_STOCKS] = {
        {"TCS", 3500},
        {"INFY", 1500},
        {"RELIANCE", 2500},
        {"HDFC", 1700},
        {"ICICI", 900},
        {"WIPRO", 450},
        {"HCLTECH", 1200},
        {"SBIN", 650},
        {"LT", 3200},
        {"AXISBANK", 1100}
    };

    struct Portfolio p;
    p.balance = 100000;
    for (int i = 0; i < MAX_STOCKS; i++)
        p.quantity[i] = 0;

    int choice;
    srand(time(0));

    do {
        printf("\n--- Stock Market Simulator ---\n");
        printf("1. View Stocks\n");
        printf("2. Buy Stock\n");
        printf("3. Sell Stock\n");
        printf("4. View Portfolio\n");
        printf("5. Update Stock Prices\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayStocks(stocks);
            break;
        case 2:
            buyStock(stocks, &p);
            break;
        case 3:
            sellStock(stocks, &p);
            break;
        case 4:
            viewPortfolio(stocks, p);
            break;
        case 5:
            updatePrices(stocks);
            printf("Stock prices updated.\n");
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
