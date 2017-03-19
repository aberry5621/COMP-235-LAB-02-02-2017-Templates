// COMP 235 LAB 02 02 2017 Templates
// Programmer alex DATE: 3/19/17.
// Minimal documentation for lab / demo purposes

#include <iostream>
using namespace std;

// List class template
// Accepts input of various type
// Holds maximum of 3 values in array
// Error condition if more than 3 values added
// Display contents of array
template<class T>
class List {
public:
    List();
    // construct list with one data item
    List(T p_value);
    /** getters **/
    int getSize();
    void displayList();
    /** setter **/
    // Insert a new value to the container
    void setValue(T p_newValue);
private:
    T m_arr[3];
    T m_capacity = 3;
    T m_size = 0;
};

// Driver Code
int main() {
    // insert code here...
    cout << "Template LAB 02 02 2017\n";
    List<int> listA;
    cout << "*** list A (instantiated with int base type), \n";
    cout << "built as an empty container ***\n";
    cout << "SIZE = " << listA.getSize() << endl;
    cout << "Content: ";
    listA.displayList();
    cout << "Inserting 111, 222, 333, 444...";
    listA.setValue(111);
    listA.setValue(222);
    listA.setValue(333);
    listA.setValue(444);
    cout << "Content: ";
    listA.displayList();
    cout << endl << endl;
    
    List<int> listB(9999);
    cout << "*** list B (instantiated with int base type), \n";
    cout << "built with an initial value 9999 ***\n";
    cout << "SIZE = " << listB.getSize() << endl;
    cout << "Content: ";
    listB.displayList();
    cout << "Inserting 111, 222, 333, 444...";
    listB.setValue(111);
    listB.setValue(222);
    listB.setValue(333);
    listB.setValue(444);
    cout << "Content: ";
    listB.displayList();
    
    cout << endl << endl;
    List<char> listC('Z');
    cout << "*** list C (instantiated with char base type), \n";
    cout << "built with an initial value of character Z ***\n";
    cout << "SIZE = " << listC.getSize() << endl;
    cout << "Content: ";
    listC.displayList();
    cout << "Inserting A, B, C, D...";
    listC.setValue('A');
    listC.setValue('B');
    listC.setValue('C');
    listC.setValue('D');
    cout << "Content: ";
    listC.displayList();
    
    return 0;
}

// List class template implementation
// default constructor
template<class T>
List<T>::List() {
    for (int i = 0; i < m_capacity; i++) {
        m_arr[i] = 0;
    }
}
// construct with one initial value
template<class T>
List<T>::List(T p_value) {
    for (int i = 0; i < m_capacity; i++) {
        if (!!p_value && (i == 0)) {
            m_arr[i] = p_value;
        } else {
            m_arr[i] = 0;
        }
    }
    List::setValue(p_value);
}
// getter - size
template<class T>
int List<T>::getSize() {
    return m_size;
}
// getter - show list
template<class T>
void List<T>::displayList() {
    for (int i = 0; i < m_capacity; i++) {
        cout << m_arr[i] << " ";
    }
    cout << endl;
}
// setter - add new value
template<class T>
void List<T>::setValue(T p_newValue) {
    if (m_size < m_capacity) {
        m_arr[m_size] = p_newValue;
        m_size++;
    } else {
        cout << "\nERROR: Overflow, " << p_newValue << " not added!\n";
    }
}
