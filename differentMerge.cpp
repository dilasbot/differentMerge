#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void print_arr(vector<int>& arr, int first, int last)
{
	for (int i = first; i <= last; i++)
	{
		string if_eol = (i == last) ? "\n" : ", ";

		cout << arr[i] << if_eol;
	}
}
void func(vector<int>& L, int first, int last)
{
	int m = 0;
	int k = first;

	while (k < last)
	{
		if (L[k] > L[k + 1])
		{
			int temp = L[k];

			L[k] = L[k + 1];

			L[k + 1] = temp;
		}

		k++;
		k++;
	}

	k = first + 1;

	vector<int> A;
	const unsigned int size = last - first + 1;
	A.resize(size);

	while (k <= last)

	{
		A[m] = L[k];

		m = m + 1;

		k = k + 2;

	}

	int x = first;

	k = first;

	while (k <= last)

	{
		L[x] = L[k];

		x = x + 1;

		k = k + 2;

	}

	k = 0;

	while (k < m)

	{
		L[x] = A[k];

		x = x + 1;

		k++;

	}
}
void merge(vector<int>& L, int first, int mid, int afterMid, int last)
{
	int i = first;

	int j = afterMid;

	int k = 0;

	vector<int> temp;
	temp.resize(last - first + 1);

	while (i <= mid && j <= last)

	{
		if (L[i] < L[j])

		{
			temp[k++] = L[i++];

		}
		else

		{
			temp[k++] = L[j++];

		}
	}

	while (i <= mid)

	{
		temp[k++] = L[i++];

	}

	while (j <= last)

	{
		temp[k++] = L[j++];

	}

	i = first;

	j = 0;

	while (i <= last)

	{
		L[i] = temp[j];

		i = i + 1;

		j = j + 1;

	}
}


void minMax(vector<int>& arr, int first, int last)
{
	if (first < last)
	{
		int max = last;
		int min = first;
		int i, j;
		for (i = first; i <= last; i++)
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		for (j = first; j <= last; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		cout << "Min: " << arr[min] << "	Max:" << arr[max] << endl;
		int temp = min; 
		min = first;
		first = temp;
		temp = max;
		max = last;
		last = temp;		
		minMax(arr, first + 1, last - 1);
	}
}
void sort(vector<int>& arr, int first, int last)
{
	int n = last - first + 1;
	if (n <= 1)
	{
		return;
	}
	if (first < last)
	{
		print_arr(arr, first, last);
		func(arr, first, last);
		int mid = (first + last) / 2;
		cout << "Min max unsorted: ";
		print_arr(arr, first, mid);
		minMax(arr, first, mid);
		cout << "Min_max sorted: ";
		print_arr(arr, first, mid);
		//sort(arr, first, mid);
		sort(arr, mid + 1, last);
		merge(arr, first, mid, mid + 1, last);
	}
}

int main(int argc, char* argv[])
{

	vector<int> all_values;


	try {

		string filename = argv[1];

		ifstream myfile(filename);


		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				int number = stoi(line);
				all_values.push_back(number);
			}

			sort(all_values, 0, all_values.size() - 1);

			print_arr(all_values, 0, all_values.size() - 1);
		}
		else
		{
			cout << "File is not available." << endl;
			throw;
		}

	}
	catch (const ifstream::failure& e)
	{
		cerr << "Exception opening the file!" << endl;
		return -1;
	}
	catch (...)
	{
		cerr << "Something's wrong!" << endl;
		return -1;
	}
	return 0;
}