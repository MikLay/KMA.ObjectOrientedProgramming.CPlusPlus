#include "Sequance.h"

int main()
{
	{
		cout << "=+=+=+=+=+=+ Create empty sequance =+=+=+=+=+=+\n";
		const auto sequence = new Sequence<double>(1);
		cout << "Before adding: \n" << *sequence;
		cout << "Add new 3 elements\n";
		(*sequence).add(123.5);
		(*sequence).add(123.5);
		cout << "After adding : \n" << *sequence;
		(*sequence).remove(0);
		cout << "After removing first element: \n" << *sequence;
		(*sequence).clear();;
		system("pause");
	}
	{
		const auto sequance = new Sequence<int>(5);
		cout << "Sequance before adding by iterating: " << *sequance;
		for (auto i = 0; i < 10; ++i)
		{
			(*sequance).add(i);
		}

		cout << "Sequance after adding by iterating: " << *sequance << endl;

		(*sequance).remove(0);
		(*sequance).remove(1);
		(*sequance).remove(2);

		cout << "Remove first 3 elements: " << *sequance << endl;

		(*sequance).insert(10, 0);

		cout << *sequance << endl;

		cout << "Check if element 5 is in sequance: \n";

		cout << ((*sequance).contains(5) ? "Element 5 in sequance\n" : "Element 5 not in sequance\n");

		cout << "Check if sequance is full: \n";

		cout << ((*sequance).full() ? "Sequence sequance is full\n" : "Sequence sequance is not full\n");

		cout << "Cut sequance: \n";
		(*sequance).cut();

		cout << *sequance << endl;

		(*sequance).clear();

		cout << "Clear sequance:\n";

		cout << *sequance << endl;

		system("pause");
	}
	return 0;
}
