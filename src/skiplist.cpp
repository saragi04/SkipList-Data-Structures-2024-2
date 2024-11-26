#include <iostream>
#include "skiplist.hh"

int main() {
    SkipList<int> sl;
    sl.insert(3);
    sl.insert(6);
    sl.insert(7);
    sl.insert(9);
    sl.insert(12);
    sl.insert(19);
    sl.insert(17);
    sl.insert(26);
    sl.insert(21);
    sl.insert(25);

    cout << "Skip List after insertions:" << endl;
    sl.print();

    cout << "Searching for 19: " << (sl.search(19) ? "Found" : "Not Found") << endl;
    sl.remove(19);
    cout << "After removing 19:" << endl;
    sl.print();
    cout << "Searching for 19: " << (sl.search(19) ? "Found" : "Not Found") << endl;

    return 0;
}
