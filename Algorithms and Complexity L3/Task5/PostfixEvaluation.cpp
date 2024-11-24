#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <stdexcept>
#include <cctype>

class Stack {
private:
    static const int MAX_SIZE = 100; 
    std::array<int, MAX_SIZE> data; 
    int top; // (-1 when empty)

public:
    Stack() : top(-1) {}

    // Push an element onto the stack   
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            throw std::overflow_error("Stack overflow");
        }
        data[++top] = value;
    }

    // Pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return data[top--];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Get the top element without popping
    int peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[top];
    }
};

// Function to evaluate a postfix expression
int evaluatePostfix(const std::string& expression) {
    Stack stack;
    std::istringstream tokens(expression);
    std::string token;

    while (tokens >> token) {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            // If the token is a number, push it onto the stack
            stack.push(std::stoi(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            // If the token is an operator, pop two elements from the stack
            if (stack.isEmpty()) throw std::invalid_argument("Invalid expression: too few operands");
            int b = stack.pop();
            if (stack.isEmpty()) throw std::invalid_argument("Invalid expression: too few operands");
            int a = stack.pop();

            // Perform the operation and push the result back onto the stack
            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                if (b == 0) throw std::invalid_argument("Division by zero");
                stack.push(a / b);
            }
        } else {
            throw std::invalid_argument("Invalid token: " + token);
        }
    }

    // After processing all tokens, the stack should have exactly one element
    if (stack.isEmpty()) {
        throw std::invalid_argument("Invalid expression: no result found");
    }
    int result = stack.pop();

    // Ensure the stack is now empty (valid postfix expression)
    if (!stack.isEmpty()) {
        throw std::invalid_argument("Invalid expression: too many operands");
    }

    return result;
}

int main() {
    std::string expression;
    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, expression);

    try {
        int result = evaluatePostfix(expression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
