#include <iostream>
#include <iomanip>
#include <string>

// Константы для комиссий и курсов валют
const double COMMISSION_RATE = 0.05;
const double RATE_USD = 0.012;
const double RATE_EUR = 0.011;
const double RATE_CNY = 0.086;
const double RATE_ZWL = 3.5;
const double RATE_JPY = 1.76;

void showMenu() {
    std::cout << "\nВыберите валюту для покупки:\n";
    std::cout << "1. Доллар (USD)\n";
    std::cout << "2. Евро (EUR)\n";
    std::cout << "3. Юань (CNY)\n";
    std::cout << "4. Доллар Зимбабве (ZWL)\n";
    std::cout << "5. Йена (JPY)\n";
    std::cout << "Введите номер валюты: ";
}

double convertCurrency(double rubles, double rate, double& commission) {
    commission = rubles * COMMISSION_RATE;
    double amountAfterCommission = rubles - commission;
    return amountAfterCommission * rate;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double rubles;
    int choice;
    char repeat;

    do {
        std::cout << "Введите количество рублей для обмена: ";
        std::cin >> rubles;

        if (rubles <= 0) {
            std::cout << "Ошибка: сумма должна быть больше 0. Попробуйте снова.\n";
            continue;
        }

        showMenu();
        std::cin >> choice;

        double commission = 0.0;
        double result = 0.0;
        std::string currency;

        switch (choice) {
        case 1:
            result = convertCurrency(rubles, RATE_USD, commission);
            currency = "USD";
            break;
        case 2:
            result = convertCurrency(rubles, RATE_EUR, commission);
            currency = "EUR";
            break;
        case 3:
            result = convertCurrency(rubles, RATE_CNY, commission);
            currency = "CNY";
            break;
        case 4:
            result = convertCurrency(rubles, RATE_ZWL, commission);
            currency = "ZWL";
            break;
        case 5:
            result = convertCurrency(rubles, RATE_JPY, commission);
            currency = "JPY";
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            continue;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nВы получили: " << result << " " << currency << "\n";
        std::cout << "Сумма комиссии: " << commission << " рублей\n";

        std::cout << "Хотите повторить обмен? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    std::cout << "Спасибо за использование нашего сервиса!\n";
    return 0;
}
