#include <iostream>
#include <math.h>

using namespace std;

void check_card_no(long long credit_card_no);

int main() {
    cout << "Please input your credit card no\n";
    long long credit_card_no;
    cin >> credit_card_no;
    check_card_no(credit_card_no);
}

void check_card_no(long long credit_card_no)
{
    uint digit_length = 0;
    long long digit_num = 0;
    uint even_digit_count = 0;
    uint odd_digit_count = 0;
    while (1) {
        digit_num = credit_card_no / pow(10, digit_length);
        if (digit_num == 0)
            break;
        digit_num = digit_num % 10;
        if (digit_length % 2 == 1) {
            if (digit_num * 2 >= 10)
                even_digit_count += digit_num * 2 / 10 + digit_num * 2 % 10;
            else
                even_digit_count += digit_num * 2;
        } else
            odd_digit_count += digit_num;

        digit_length++;
    }

    uint bank_no = 0;
    if ((even_digit_count + odd_digit_count) % 10 != 0){
        cout << "Illegal Card No\n";
        return;
    }

    bank_no = credit_card_no / pow(10, digit_length - 2);
    if ((bank_no / 10) % 10 == 4 && (digit_length == 13 ||digit_length == 16))
        cout << "Visa Card\n";
    else if ((34 <= bank_no && bank_no <= 37) && digit_length ==15)
        cout << "Amercian Express Card\n";
    else if ((51 <= bank_no && bank_no <= 55) && digit_length ==16)
        cout << "Master Card\n";
    else
        cout << "Illegal Card No\n";
}
