#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseStack(std::stack<double>& numbers) {
    queue<double> tempqueue;

    while (!numbers.empty()) {
        double value = numbers.top();
        numbers.pop();
        tempqueue.push(value);
    }

    while (!tempqueue.empty()) {
        double value = tempqueue.front();
        tempqueue.pop();
        numbers.push(value);
    }
}

int main() {
    std::stack<double> numbers;
    numbers.push(-10);
    numbers.push(-20);
    numbers.push(-30);
    numbers.push(-1);
    numbers.push(-50);
    numbers.push(-12);
    numbers.push(-60);
    numbers.push(70);

    std::stack<double> tempStack;
    reverseStack(numbers);
    bool foundt = false;
    // Переносим числа во временный стек до тех пор, пока не встретим положительное значение
    while (!numbers.empty()) {
        if (numbers.top() > 0) {
            foundt = true;
            break;
        }
        tempStack.push(numbers.top());
        numbers.pop();
    }

    if (foundt == true) {
        tempStack.push(numbers.top());


        // Возвращаем числа из временного стека обратно в основной стек
        while (!tempStack.empty()) {
            numbers.push(tempStack.top());
            tempStack.pop();
        }
        // Выводим обновленный список
        while (!numbers.empty()) {
            std::cout << numbers.top() << " ";
            numbers.pop();
        }

        return 0;
    }
}