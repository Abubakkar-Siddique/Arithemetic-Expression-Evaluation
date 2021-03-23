#include<iostream>
#include<string>

using namespace std;

const int x = 30;

class ExpEvaluation {
private:
	string exp;
	char postfix[x];
	int counter;
public:

	ExpEvaluation()
	{
		counter = 0;
	}

	void ExpEnter()
	{
		counter = 0;
		cout << " Enter Expression : ";
		getline(cin, exp);
		getline(cin, exp);
		cout << endl;
		cout <<" Expression successfully entered! "<<endl;
		cout << endl;
	}

	void view()
	{
		cout << " Entered Expression is : ";
		for (int i = 0; i < exp.length(); i++)
		{
			cout << exp[i];
		}
		cout <<" "<< endl;
	}

	bool validity()
	{
		char stk[x];
		int top = 0;
		for (int i = 0; i < exp.length(); i++)
		{
			if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(') 
			{
				stk[top] = exp[i];
				top++;
			}
		
			if (exp[i] == ')' && stk[top - 1] != '(') 
			{
				return false;
			}

			else if (exp[i] == '}' && stk[top - 1] != '{') 
			{
				return false;
			}
			else if (exp[i] == ']' && stk[top - 1] != '[')
			{
				return false;
			}

			else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
			{
				top--;
			}
		}
		if (top == 0)
		{
			return true;
		}
		return false;
	}

	void Postfix()
	{
		char stk[x];
		int top = 0;
		counter = 0;

		for (int i = 0; i < exp.length(); i++)
		{
			if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
			{

				stk[top] = exp[i];
				top++;
			}
			else if (exp[i] == '0' || exp[i] == '1' || exp[i] == '2' || exp[i] == '3' || exp[i] == '4'
				|| exp[i] == '5' || exp[i] == '6' || exp[i] == '7' || exp[i] == '8' || exp[i] == '9')
			{
				postfix[counter] = exp[i];
				counter++;
			}
			else if (exp[i] == '^' || exp[i] == '/' || exp[i] == '*' || exp[i] == '+' || exp[i] == '-')
			{
				postfix[counter] = ',';
				counter++;

				if (precedence(stk[top - 1]) > precedence(exp[i]))
				{
					postfix[counter] = stk[top - 1];
					counter++;
					top--;
					if (precedence(stk[top - 1]) > precedence(exp[i]))
					{
						postfix[counter] = stk[top - 1];
						counter++;
						top--;
					}
					if (precedence(stk[top - 1]) > precedence(exp[i]))
					{
						postfix[counter] = stk[top - 1];
						counter++;
						top--;
					}
					if (precedence(stk[top - 1]) > precedence(exp[i]))
					{
						postfix[counter] = stk[top - 1];
						counter++;
						top--;
					}
					if (precedence(stk[top - 1]) > precedence(exp[i]))
					{
						postfix[counter] = stk[top - 1];
						counter++;
						top--;
					}
				}
				if (precedence(stk[top - 1]) == precedence(exp[i]))
				{
					postfix[counter] = stk[top - 1];
					counter++;
				}
				else if (precedence(stk[top - 1]) < precedence(exp[i]))
				{
					stk[top] = exp[i];
					top++;
				}
			}

			else if (exp[i] == ')')
			{
				postfix[counter] = ',';
				counter++;
				while (stk[top - 1] != '(')
				{
					postfix[counter] = stk[top - 1];
					counter++;
					top--;
				}
				top--;
			}
			else if (exp[i] == '}')
			{
				postfix[counter] = ',';
				counter++;
				while (stk[top - 1] != '{')
				{
					postfix[counter] = stk[top - 1];
					counter++;
					top--;
				}
				top--;
			}
			else if (exp[i] == ']')
			{
				postfix[counter] = ',';
				counter++;
				while (stk[top - 1] != '[')
				{
					postfix[counter] = stk[top - 1];
					counter++;
					top--;
				}
				top--;
			}
		}
			if (top > 0)
			{
				for (int i = top - 1; i > -1; i--)
				{
					postfix[counter] = stk[i];
					counter++;
				}
			}
		cout << " Postfix Expression : ";
		for (int j = 0; j < counter; j++)
		{
			cout << postfix[j];
		}
		cout << " " << endl;
	}

    int postfixEval()
	{
	int top1 = 0;
	int stk[x];
	char temp[x];
	int t = 0;
	int x, y, a;

	for (int i = 0; i < counter; i++) 
	{
		if (postfix[i] == '0' || postfix[i] == '1' || postfix[i] == '2' || postfix[i] == '3' || postfix[i] == '4'
			|| postfix[i] == '5' || postfix[i] == '6' || postfix[i] == '7' || postfix[i] == '8' || postfix[i] == '9')
		{
			temp[t] = postfix[i];
			t++;
		}
		else if (postfix[i] == ',' && t > 0)
		{
			stk[top1] = atoi(temp);
			top1++;
			for (int i = t - 1; i > -1; i--)
			{
				temp[t] = ' ';
				t--;
			}
			t = 0;
		}
		else if (postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-') 
		{
			switch (postfix[i]) 
			{

			case '/': 
			{
				y = stk[top1 - 1];
				top1--;
				x = stk[top1 - 1];
				top1--;
				a = x / y;
				stk[top1] = a;
				top1++;
			}
		    break;

			case '*':
			{
				y = stk[top1 - 1];
				top1--;
				x = stk[top1 - 1];
				top1--;
				a = x * y;
				stk[top1] = a;
				top1++;
			}
			break;

			case '+': 
			{
				y = stk[top1 - 1];
				top1--;
				x = stk[top1 - 1];
				top1--;
				a = x + y;
				stk[top1] = a;
				top1++;
			}
		    break;

			case '-': 
			{
				y = stk[top1 - 1];
				top1--;
				x = stk[top1 - 1];
				top1--;
				a = x - y;
				stk[top1] = a;
				top1++;
			}
			break;
			}
		  }
	   }
	    return stk[0];
      }

	int precedence(char z)
	{
		if (z == '^') {
			return 5;
		}
		else if (z == '/') {
			return 4;
		}
		else if (z == '*') {
			return 3;
		}
		else if (z == '+') {
			return 2;
		}
		else if (z == '-') {
			return 1;
		}
		else {
			return 0;
		}
	}

	int Typecasting(char ch)
	{
		if (ch == '0') {
			return 0;
		}
		else if (ch == '1') {
			return 1;
		}
		else if (ch == '2') {
			return 2;
		}
		else if (ch == '3') {
			return 3;
		}
		else if (ch == '4') {
			return 4;
		}
		else if (ch == '5') {
			return 5;
		}
		else if (ch == '6') {
			return 6;
		}
		else if (ch == '7') {
			return 7;
		}
		else if (ch == '8') {
			return 8;
		}
		else if (ch == '9') {
			return 9;
		}
	}

};
	
int main() 
{
	ExpEvaluation oa;
	int count = 0,count1 = 0,count2=0,count4=0;
	int a;
	cout << endl;
	cout << " Welcome to Expression Evaluation System! " << endl;
	cout << " " << endl;
	cout << " Enter 1 to Enter Expression " << endl;
	cout << " Enter 2 to Check Validity " << endl;
	cout << " Enter 3 to Convert into PostFix " << endl;
	cout << " Enter 4 to Evaluate Expression " << endl;
	cout << " Enter 5 to View Expression " << endl;
	cout << " Enter 0 to exit from System " << endl;
	cout << " " << endl;
	cout << " Please Enter Value from above Menu : ";
	cin >> a;
	cout << " " << endl;

	while (a != 0)
	{
		switch (a)
		{

		case 1:
		{
			count2 = 0,count1=0,count=0,count4=0;
			cout << " " << endl;
			oa.ExpEnter();
			count2++;
			cout << " " << endl;
		}
		break;

		case 2:
		{
			cout << " " << endl;
			if (count2 > 0)
			{
				count1++;
				if (oa.validity() == true)
				{
					cout << " Expression Valid! ";
					count++;
				}
				else
				{
					cout << " Expression not Valid! ";
				}
			}
			else
			{
				cout << " Expression not Entered! ";
			}
			cout << "\n\n " << endl;
		}
		break;

		case 3:
		{
			cout << " " << endl;
			if (count2 > 0)
			{
				if (count1 > 0)
				{
					if (count > 0)
					{
						oa.Postfix();
						count4++;
					}
					else
					{
						cout << " Expression not Valid! ";
					}
				}
				else
				{
					cout << " First check expression validity! ";
				}
			}
			else
			{
				cout << " Expression not Entered! ";
			}
			cout << "\n\n " << endl;
		}
		break;

		case 4:
		{
			cout << " " << endl;
			if (count2 > 0)
			{
				if (count1 > 0)
				{
					if (count > 0)
					{
						if (count4 > 0)
						{
							cout << " Answer is : ";
							cout << oa.postfixEval();
						}
						else
						{
							cout << " First Convert it into postfix! ";
						}
					}
					else
					{
						cout << " Expression not Valid! ";
					}
				}
				else
				{
					cout << " First check expression validity! ";
				}
			}
			else
			{
				cout << " Expression not Entered! ";
			}
			cout << "\n\n " << endl;
		}
		break;

		case 5:
		{
			cout << " " << endl;
			if (count2 > 0)
			{
				oa.view();
			}
			else
			{
				cout << " Expression not Entered! ";
			}
			cout << "\n\n " << endl;
		}
		break;

		default:
		{
			cout << " " << endl;
			cout << " Please enter appropriate value from menu! ";
			cout << "\n\n " << endl;
		}
		}
		cout << " Enter 1 to Enter Expression " << endl;
		cout << " Enter 2 to Check Validity " << endl;
		cout << " Enter 3 to Convert into PostFix " << endl;
		cout << " Enter 4 to Evaluate Expression " << endl;
		cout << " Enter 5 to View Expression" << endl;
		cout << " Enter 0 to exit from System" << endl;
		cout << " " << endl;
		cout << " Please Enter Value from above Menu : ";
		cin >> a;
		cout << " " << endl;
	}

	system("pause");
	return 0;	
}
