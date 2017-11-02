The structrue of this directory is:

file "README.md"
file "sortlink.h"
directory "examples"
    file "README.md"
    file "example.cpp"
    file "Makefile"

"sortlink.h" has constructed a sorted link list(from big to small) template class named "SortLink".
It has realised following functions:

* Use "SortLink<DataType> A;" to define a empty SortLink A;
* Use "SortLink<DataType> B(A);" or "SortLink<DataType> B = A;" to define a SortLink B adn initialize it by A;
* Use "A.insert(x);" to insert variable x in type "DataType" to corresponding place of SortLink A;
* Use "cout << A;" to print the structure of SortLink A;
* Use "A = B" to clone SortLink B to SortLink A;
* Use "A.empty();" to judge if SortLink A is empty;
* Use "A.length();" to get the number of elements of SortLink A;
* Use "A.clear();" to clear SortLink A's memory;
* Use "A.begin();" to get the first element's iterator;
* Use "A.end();" to get the tail element's next position's iterator;
* Use const_iterator to loop through the SortLink;
    `for(SortLink<DataType>::const_iterator it = A.begin(); it != A.end(); it++)
        cout << *it;`
* Use "A.erase(k)"(with k in type "int") to erase the k-position(count from 0) element in SortLink.
* Use "A.erase(it)"(with it intype "const_iterator") to erase an element in SortLink A at position that const_iterator point to;
* Use "A.find(x)" to find out if the passed-in element is in the SortLink. If yes, return it's location in type "const_iterator";
* Use "A.locate(k)"(with k in type "int") to get position k's iterator;
* Use "A.locate(it)"(with it in type "const_iterator") to get iterator's position index in type "int";
* Use "A.merge(B)" to merge SortLink B into A;

There are example program in "./examples/". You can compile the example by the guiding of "./example/README.md".

The object to build this SortLink class is to store polynomial's terms.
So it is used by class "Poly"(defined in "../../Poly").