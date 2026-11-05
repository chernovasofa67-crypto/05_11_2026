#include <iostream>


void displayMessage() {
    std::cout << "[Глобальна область] Привіт від глобальної функції!\n";
}

namespace A {
    namespace B {
        void displayMessage() {
            std::cout << "[Простір імен A::B] Привіт із вкладеного простору імен B!\n";
        }
    }
}

int main() {
    std::cout << "--- Етап 1: Виклик функцій через явну вказівку шляху ---\n";
    ::displayMessage();
    A::B::displayMessage();
    std::cout << "\n--- Етап 2: Спроба імпорту простору імен B ---\n";

    using namespace A::B;

    std::cout << "ПОМИЛКА: Прямий виклик displayMessage() призведе до помилки компіляції!\n";
    std::cout << "ЧОМУ: Компілятор не знає, яку саме функцію викликати — "
              << "глобальну ::displayMessage() чи імпортовану A::B::displayMessage(), "
              << "оскільки обидві тепер доступні в поточній області видимості без префіксів.\n";

    return 0;
}
