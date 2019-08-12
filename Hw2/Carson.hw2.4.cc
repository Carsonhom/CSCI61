#include <queue>
#include <stack>
#include <iostream>
#include <string>


std::string postfix_to_prefix(std::string postfix[], int len)
{
	std::stack<std::string> expr;
	for(std::size_t i = 0; i < len; ++i)
	{
		if(postfix[i].at(0) - '0' >= 0 && postfix[i].at(0) - '0' < 10)
		{
			expr.push(postfix[i]);
		}
		else
		{
			std::string str;
			str += postfix[i];
			std::string first;
			std::string scnd;
			first = expr.top();
			expr.pop();
			scnd = expr.top();
			expr.pop();
			str += scnd;
			str += first;
			expr.push(str);
		}
	} 
	return expr.top();
}

int main()
{
	std::string postfix[11] = {"7", "2", "4", "*", "-", "5", "9", "+", "+", "3", "-"};
	std::cout << postfix_to_prefix(postfix, 11) << std::endl;

	
	return 0;
}