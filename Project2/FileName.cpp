#include <iostream>
#include <string>
#include <Windows.h>


struct Drink {
    std::string name;
    int price;
};

Drink fruitList[4] = { {"Яблочный", 90}, {"Апельсиновый", 110},
                       {"Абрикосовый", 105}, {"Грушевый", 95} };
Drink vegList[3] = { {"Томатный", 80}, {"Луковый", 95}, {"Огуречный", 100} };
Drink teaList[2] = { {"Чесночный", 100}, {"Петрушевый", 105} };


int billSum = 0;
int billCount = 0;


void clearScreen() { system("cls"); }

void printTitle() {
    std::cout << "\n\n\n\t|===| МАГАЗИН НАПИТКОВ |===|";
}

void addToCart(int price, int amount) {
    billSum += price * amount;
    billCount += amount;
}


void buyFromCategory(int category) {
    int itemNum, amount, again;
    int price = 0, maxItems = 0;

    while (true) {
        clearScreen();

        if (category == 1) {
            std::cout << "\n\n\t= Фруктовые соки =";
            for (int i = 0; i < 4; i++)
                std::cout << "\n\t" << i + 1 << ") -- " << fruitList[i].name
                << " - " << fruitList[i].price << " руб.";
            maxItems = 4;
        }
        else if (category == 2) {
            std::cout << "\n\n\t= Овощные соки =";
            for (int i = 0; i < 3; i++)
                std::cout << "\n\t" << i + 1 << ") -- " << vegList[i].name
                << " - " << vegList[i].price << " руб.";
            maxItems = 3;
        }
        else {
            std::cout << "\n\n\t= Травяные чаи =";
            for (int i = 0; i < 2; i++)
                std::cout << "\n\t" << i + 1 << ") -- " << teaList[i].name
                << " - " << teaList[i].price << " руб.";
            maxItems = 2;
        }

        std::cout << "\n\n\tНомер товара -- ";
        std::cin >> itemNum;
        if (itemNum < 1 || itemNum > maxItems) continue;

        if (category == 1) price = fruitList[itemNum - 1].price;
        else if (category == 2) price = vegList[itemNum - 1].price;
        else price = teaList[itemNum - 1].price;

        std::cout << "\n\tКоличество (л) -- ";
        std::cin >> amount;

        if (amount > 0) {
            addToCart(price, amount);
            std::cout << "\n\n\tПозиция добавлена в корзину.";
        }
        else {
            std::cout << "\n\n\tКоличество должно быть положительным.";
        }

        std::cout << "\n\n\tПродолжить выбор в этой категории?";
        std::cout << "\n\t1) -- Да";
        std::cout << "\n\t2) -- Нет";
        std::cout << "\n\tВаш ответ -- ";
        std::cin >> again;

        if (again != 1) return;
    }
}


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int mainChoice;
    bool quit = false;

    while (!quit) {
        clearScreen();
        std::cout << "\n\t= Здравствуйте! Добро пожаловать в магазин напитков! =";
        printTitle();
        std::cout << "\n\n\tЧто будем делать?";
        std::cout << "\n\t1) -- Открыть каталог товаров.";
        std::cout << "\n\t2) -- Оформить заказ и закрыть программу.";
        std::cout << "\n\t0) -- Просто выйти.";
        std::cout << "\n\n\tВаш выбор -- ";
        std::cin >> mainChoice;

        switch (mainChoice) {
        case 0:
            clearScreen();
            std::cout << "\n\t= До новых встреч! =";
            std::cout << "\n\n\n\n\n\n\n\n";
            quit = true;
            break;

        case 2:
            clearScreen();
            std::cout << "\n\t= Ваш заказ =";
            std::cout << "\n\tВсего товаров : " << billCount << " шт.";
            std::cout << "\n\tИтоговая сумма: " << billSum << " руб.";
            std::cout << "\n\n\tСпасибо за покупку!";
            std::cout << "\n\tДля выхода нажмите любую клавишу...";
            std::cout << "\n\n\n\n\n\n\n\n";
            system("pause");
            quit = true;
            break;

        case 1: {
            int catChoice;
            do {
                clearScreen();
                printTitle();
                std::cout << "\n\n\t= Каталог (цены за 1 литр) =";
                std::cout << "\n\t1) -- Фруктовые соки.";
                std::cout << "\n\t2) -- Овощные соки.";
                std::cout << "\n\t3) -- Травяные чаи.";
                std::cout << "\n\t0) -- Назад в главное меню.";
                std::cout << "\n\n\tВаш выбор -- ";
                std::cin >> catChoice;

                if (catChoice >= 1 && catChoice <= 3)
                    buyFromCategory(catChoice);
            } while (catChoice != 0);
            break;
        }
        }
    }

    return 0;
}
