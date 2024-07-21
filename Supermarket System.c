#include <stdio.h>

int main()
{
    double a = 0, b = 0, c = 0, d = 0, e = 0;
    char letter;
    double option;
    const double dis1 = 0.01;
    const double dis2 = 0.05;
    const double VAT = 0.16;

    while (1)
    {
        printf("\nPlease enter the item code (a, b, c, d, e) or X to finish: ");
        scanf(" %c", &letter);

        if (letter == 'x' || letter == 'X')
        {
            break;
        }

        if (letter == 'a' || letter == 'A')
        {
            printf("Please enter the number of item units: ");
            scanf("%lf", &a);
            printf("Item cost is %f shekels\n", a * 2);
        }
        else if (letter == 'b' || letter == 'B')
        {
            printf("Please enter the number of item units: ");
            scanf("%lf", &b);
            printf("Item cost is %f shekels\n", b * 4);
        }
        else if (letter == 'c' || letter == 'C')
        {
            printf("Please enter the number of item units: ");
            scanf("%lf", &c);
            printf("Item cost is %f shekels\n", c * 6);
        }
        else if (letter == 'd' || letter == 'D')
        {
            printf("Please enter the number of item units: ");
            scanf("%lf", &d);
            printf("Item cost is %f shekels\n", d * 8);
        }
        else if (letter == 'e' || letter == 'E')
        {
            printf("Please enter the number of item units: ");
            scanf("%lf", &e);
            printf("Item cost is %f shekels\n", e * 10);
        }
    }

    double total_in_shekels = (a * 2 + b * 4 + c * 6 + d * 8 + e * 10) + ((a * 2 + b * 4 + c * 6 + d * 8 + e * 10) * VAT);
    double discount = 0;
    if (total_in_shekels >= 100 && total_in_shekels < 1000)
    {
        discount = dis1;
    }
    else if (total_in_shekels >= 1000)
    {
        discount = dis2;
    }
    double total_after_discount = total_in_shekels * (1 - discount);

    while (1)
    {
        printf("\n\n1-Receipt in shekel\n");
        printf("2-Receipt in dollar\n");
        printf("3-Total discount in shekel\n");
        printf("4-Pay\n");
        printf("5-Find max and min\n");
        printf("6-Cancel current\n");
        printf("7-Next customer\n");
        printf("8-Exit\n");
        scanf("%lf", &option);

        switch ((int)option)
        {
        case 1:
            printf("Total cost in shekels is %f shekels\n", total_after_discount);
            break;
        case 2:
            printf("Total cost in Dollars is %f Dollars\n", total_after_discount / 3.5);
            break;
        case 3:
            printf("Total discount in shekels is %f shekels\n", total_in_shekels * discount);
            break;
        case 4:
        {
            double payment;
            printf("Please enter amount paid in shekels: ");
            scanf("%lf", &payment);
            printf("Remainder = %f shekels\n", total_after_discount - payment);
            break;
        }
        case 5:
        {
            double prices[5] = {a * 2, b * 4, c * 6, d * 8, e * 10};
            double max_price = 0;
            double min_price = max_price * 2;
            for (int i = 0; i < 5; i++)
            {
                if (prices[i] > max_price)
                {
                    max_price = prices[i];
                }
                if (prices[i] < min_price && prices[i] > 0)
                {
                    min_price = prices[i];
                }
            }
            if (min_price == max_price * 2)
            {
                min_price = 0;
            }
            printf("Maximum price: %f shekels\n", max_price);
            printf("Minimum price: %f shekels\n", min_price);
            break;
        }
        case 6:
            a = b = c = d = e = 0;
            total_in_shekels = 0;
            total_after_discount = 0;
            break;
        case 7:
            printf("\nThank you! Next customer\n");
            a = b = c = d = e = 0;
            total_in_shekels = 0;
            total_after_discount = 0;
            break;
        case 8:
            printf("Exiting, thank you!!\n");
            return 0;
        default:
            printf("Invalid option! Please try again.\n");
            break;
        }
    }

    return 0;
}