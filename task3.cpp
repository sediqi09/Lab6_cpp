#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class UniqueList {
private:
    unordered_set<int> elements;  // The unordered list stores unique elements

public:
    // Method to add an element to the list
    void add(int element) {
        elements.insert(element);  // Insert automatically handles duplicates
    }

    // Method to remove an element from the list
    void remove(int element) {
        elements.erase(element);  // Removes the element if it exists
    }

    // Method to perform the union of two collections
    UniqueList Union(const UniqueList& other) {
        UniqueList result;
        result.elements = elements;
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }

    // Method to remove elements of the second collection from the first
    UniqueList Except(const UniqueList& other) {
        UniqueList result;
        for (int e : elements) {
            if (other.elements.find(e) == other.elements.end()) {
                result.add(e);
            }
        }
        return result;
    }

    // Method to get the intersection of two collections
    UniqueList Intersect(const UniqueList& other) {
        UniqueList result;
        for (int e : elements) {
            if (other.elements.find(e) != other.elements.end()) {
                result.add(e);
            }
        }
        return result;
    }

    // Method to check if an element is present in the collection
    bool Contains(int element) const {
        return elements.find(element) != elements.end();
    }

    // Method to print the collection for debugging
    void print() const {
        for (int e : elements) {
            cout << e << " ";
        }
        cout << endl;
    }
};

int main() {
    // Example usage for the problem

    // List of discos
    UniqueList allDiscos;
    allDiscos.add(1);
    allDiscos.add(2);
    allDiscos.add(3);
    allDiscos.add(4);
    allDiscos.add(5);

    // Discos visited by each student (represented as sets of disco IDs)
    UniqueList student1;
    student1.add(1);
    student1.add(3);
    student1.add(5);

    UniqueList student2;
    student2.add(2);
    student2.add(3);
    student2.add(5);

    UniqueList student3;
    student3.add(1);
    student3.add(2);
    student3.add(3);

    // Determine which discos all students went to
    UniqueList allVisited = student1.Intersect(student2).Intersect(student3);
    cout << "Discos visited by all students: ";
    allVisited.print();

    // Determine which discos some students went to
    UniqueList someVisited = student1.Union(student2).Union(student3);
    cout << "Discos visited by some students: ";
    someVisited.print();

    // Determine which discos none of the students went to
    UniqueList noneVisited = allDiscos.Except(someVisited);
    cout << "Discos visited by no students: ";
    noneVisited.print();

    return 0;
}
