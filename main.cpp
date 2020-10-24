// lib.hpp contains all the CPP STL libraries that has been usd in the implementation
#include "lib.hpp"

// utility.hpp contains the genetic algorithm method to solve Knapsack
#include "utility.hpp"

// dp.hpp contains the dynamic programming method to solve knapsack
#include "dp.hpp"


// Test case solver
void Test_Case(int Test_num = 0, int iter = 0, int flag = 0)
{
	// number of items
	if (!flag) cout << "\nEnter the number of items : ";
	int n;
	cin >> n;

	if (flag)
	{
		cout << "\nTest Case : " << Test_num << "\n";
		cout << "number of items is : n = " << n << endl;
		cout << "number of iterations is : iter = " << iter << endl;
	}

	// capacity of the knapsack
	if (!flag) cout << "Enter the capacity of the KnapSack : ";
	int capacity;
	cin >> capacity;

	// storing the weight and the value of the items
	vector<int> weight(n);
	vector<int> value(n);

	if (!flag) cout << "For each item enter -> 'weight' space 'value' : \n";

	for (int i = 0; i < n; ++i)
	{
		cin >> weight[i] >> value[i];
	}

	// number of iterations
	if (!flag) cout << "Enter the number of iterations :";
	if (!flag) cin >> iter;
	cout << endl;

	// starting the high resolution clock
	auto start =  chrono::high_resolution_clock::now();

	// Using genetic algorithm to solve knapsack
	int ans = -1;
	for (int i = 0; i < iter; ++i)
	{
		int out = KnapSack(weight, value, capacity);
		cout << "Iteration : " << i + 1 << "\t-> Score is : " << out <<  endl;
		ans =  max(ans, out);
	}

	// final answer of the genetice algorithm after all the iterations
	cout << "\nFinal score after " << iter << " iterations is : " << ans <<  endl;

	// ending the high resolution clock
	auto end =  chrono::high_resolution_clock::now();

	// finding the total time taken for genetic algorithm
	double tt =   chrono::duration_cast< chrono::nanoseconds>(end - start).count();
	cout << "\nExecuted in : " <<  fixed << tt * 1e-9 <<  setprecision(9) << " sec\n";

	// optimal answer using dynamic programming
	cout << "\nThe optimal answer (calculated using dynamic programming) is : ";
	cout << KnapSack_dp(weight, value, capacity) <<  endl <<  endl;
}


int main()
{
	// pseudo ranfom number generator
	srand(time(0));

	cout << "\nHii there, Welcome aboard!!" << endl;
	cout << "I am a KnapSack 0/1 Problem solver and I am programmed by Pratik Goyal (B18BB024)\n";
	cout << "I use genetic algorithm to solve the KnapSack problem and then I compare my result with the most optimal result calculated using dynamic programming.\n\n";
	cout << "I have test cases for you. \nIf you still wish to check against your custom inputs please press 'y' otherwise press 'n' : ";

	char c;
	cin >> c;

	if (c != 'y' && c != 'Y')
	{
		cout << "\nI have 6 test cases for you\n";
		cout << "Test_Case : 1 \t n = 4\n";
		cout << "Test_Case : 2 \t n = 5\n";
		cout << "Test_Case : 3 \t n = 6\n";
		cout << "Test_Case : 4 \t n = 20\n";
		cout << "Test_Case : 5 \t n = 200\n";
		cout << "Test_Case : 6 \t n = 2000\n";

		int tc;
		cout << "\nEnter the Test Case number : ";
		cin >> tc;

		string s = "test_cases/inp";
		s += '0' + tc;
		s += ".txt";

		// number of iterations
		int iter;
		cout << "\nEnter the number of iterations : ";
		cin >> iter;

		// opening the automatic test case files
		freopen(s.c_str(), "r", stdin);

		Test_Case(tc, iter, 1);
	}

	else
	{
		Test_Case();
	}

	return 0;
}