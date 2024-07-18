#include <iostream> #include <stack>
hnathan

void printStackElements(std::stack<int> stack){
	while(!stack.empty())
	{
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
}

int main()
{
	std::stack<int> numbersStack;
	numbersStack.push(5);
	numbersStack.push(10);
	numbersStack.push(20);
	numbersStack.push(25);
	numbersStack.push(30);


	if(numbersStack.empty())
		std::cout << "Stack is empty" << std::endl;
	else{
		std::cout << "Stack is not empty" << std::endl;
		std::cout << "Stack size is: " << numbersStack.size() << std::endl;
	}

	numbersStack.pop();
	std::cout << "New Stack size is: " << numbersStack.size() << std::endl;

	printStackElements(numbersStack);

	return 0;
}
