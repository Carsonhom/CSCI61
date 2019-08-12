#include <iostream>

#include <cstdlib>

#include <cmath>

#include <ctime>

#include <utility>

#include <queue>

 

using namespace std;

 

typedef pair<double,double> customer;

 

// double average_waiting_time(double arrival_rate, double service_rate, std::size_t N)

// {

// }

 

double exp_rand(double rate)

{

   double u;

   do

   {

   u = rand()/static_cast<double>(RAND_MAX);

   } while (u == 0.0 || u == 1.0);

 

   return -log(u)/rate;

}

double average_waiting_time(double arrival_rate, double service_rate, std::size_t number_of_students)
{
	queue<double> waiting;
	double avg = 0;
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
	for(std::size_t j = 0; j < number_of_students; j++)
	{
		avg += waiting.front();
		waiting.pop();
	}
	return avg/number_of_students;

}

 

int main()

{

srand(time(0));

const std::size_t N(1000000);

 

cout << average_waiting_time(1.0, 5.0, N) << endl;

cout << average_waiting_time(1.0, 3.0, N) << endl;

cout << average_waiting_time(1.0, 2.0, N) << endl;

cout << average_waiting_time(1.0, 1.5, N) << endl;

cout << average_waiting_time(1.0, 1.1, N) << endl;

cout << average_waiting_time(1.0, 1.05, N) << endl;

cout << average_waiting_time(1.0, 1.025, N) << endl;

 

return 0;

 

}

