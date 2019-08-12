#include <queue>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

struct student
{
	pair<double, double> student;
};
   

double exp_rand(double rate)
{
	double u;
	do
	{
		u = rand()/static_cast<double>(RAND_MAX);
	} 
	while (u == 0.0 || u == 1.0);
    return -log(u)/rate;
}

double average_waiting_time(double arrival_rate, double service_rate, std::size_t number_of_students)
{
	queue<double> waiting;
	// double avg = 0;
	for(std::size_t i = 0; i < number_of_students; ++i)
	{
		if(i != 0)
		{
			waiting.push(exp_rand(service_rate));
		}
		else
		{
			waiting.push(exp_rand(arrival_rate) + exp_rand(service_rate));
		}
	}
	double avg = 0;
	for(int j = 0; j < number_of_students; j++)
	{
		avg += waiting.front();
		waiting.pop();
	}
	return avg/number_of_students;

}

int main()
{
	// cout << exp_rand(1) << endl;
	// cout << exp_rand(3) << endl;
	
	return 0;
}