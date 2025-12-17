#include <iostream>
using namespace std;

class Maxheap
{
	int *arr;
	int size, total_size; // number of elements in the array and capacity of the array
public:
	Maxheap(int n)
	{
		arr = new int[n];
		size = 0;		// initially 0 elements in the array
		total_size = n; // capacity of the array
	}
	void insert(int num)
	{
		if (size == total_size)
		{
			cout << "Overflow" << endl;
			return;
		}

		arr[size] = num;
		int index = size; // always points to the last index
		size++;

		while (index > 0 && arr[(index - 1) / 2] < arr[index]) // checking parent node
		{
			swap(arr[(index - 1) / 2], arr[index]);
			index = (index - 1) / 2;
		}
	}

	void heapify(int index)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int largest = index;

		if (left < size && arr[left] > arr[largest])
		{
			largest = left;
		}

		if (right < size && arr[right] > arr[largest])
		{
			largest = right;
		}
		if (largest != index)
		{
			swap(arr[index], arr[largest]);
			heapify(largest);
		}
	}

	void deleteElement()
	{
		if (size == 0)
		{
			cout << "there is no elements left" << endl;
			return;
		}
		arr[0] = arr[size - 1]; // replace with last element
		size--;
		if (size == 0)
			return;
		heapify(0);
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~Maxheap()
	{
		delete[] arr;
	}
};

#include <iostream>
using namespace std;
int main()
{
	Maxheap Hp(10);
	Hp.insert(20);
	Hp.insert(40);
	Hp.insert(50);
	Hp.insert(10);
	Hp.insert(50);
	Hp.insert(70);
	Hp.insert(80);
	Hp.insert(100);

	Hp.print();
	Hp.deleteElement();
	Hp.print();
	Hp.deleteElement();
	Hp.print();
	Hp.deleteElement();
	Hp.print();
	return 0;
}