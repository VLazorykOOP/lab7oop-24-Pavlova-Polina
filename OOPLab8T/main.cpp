#include <iostream>
#include <cstring>
#include<stdexcept>

using std::cout;
using std::endl;
using std::ostream;

template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}

template <typename T>
T min(T x, T y) {
    return (x < y) ? x : y;
}

// ������������ �������-������� ��� ���� char*
template <>
const char* max<const char*>(const char* x, const char* y) {
    return (strcmp(x, y) > 0) ? x : y;
}

template <>
const char* min<const char*>(const char* x, const char* y) {
    return (strcmp(x, y) < 0) ? x : y;
}
// ������ ��� ���������� ������� ���������
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ������ ��� �������� ������
template <typename T>
int binarySearch(T arr[], int size, T key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // ������� �� ��������
}

// ������������ ������� ��� ���� const char*
template <>
void bubbleSort<const char*>(const char* arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                const char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <>
int binarySearch<const char*>(const char* arr[], int size, const char* key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (strcmp(arr[mid], key) == 0)
            return mid;
        else if (strcmp(arr[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // ����� �� ��������
}

// ���� ����� ������
template <typename T>
class Node {
public:
    T data; // ���, �������� � ����
    Node* next; // �������� �� ��������� �����

    // �����������, ���� �������� ��� �� �������� �� NULL
    Node(T value) : data(value), next(nullptr) {}
};

// ���������������� ���� ������'������ ������
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head; // �������� �� ������ ����� ������

public:
    // �����������, �� ������� ������� ������
    SinglyLinkedList() : head(nullptr) {}

    // ���������� ��� ��������� ���'��, ��'����� � �������
    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // ��������� �������� � ����� ������
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // ��������� ������ �� �����
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};
// ���� ����� ������
template <typename T>
class Node {
public:
    T data; // ���, �������� � ����
    Node* next; // �������� �� ��������� �����

    // �����������, �� �������� ��� �� �������� �� NULL
    Node(T value) : data(value), next(nullptr) {}
};

// ���� ��������� ��� ����������� �� ������
template <typename T>
class ListIterator {
private:
    Node<T>* current; // �������� �����, �� ����� ����������� ��������

public:
    // ����������� ���������
    ListIterator(Node<T>* startNode) : current(startNode) {}

    // ��������, �� �������� ������ �� ������ ����� ������
    bool isValid() const {
        return current != nullptr;
    }

    // ���������� ��������� �� ���������� ����� � ������
    void next() {
        if (current != nullptr) {
            current = current->next;
        }
    }

    // ��������� �������� ��������� �����
    T& value() const {
        if (current == nullptr) {
            throw std::logic_error("Iterator is not valid");
        }
        return current->data;
    }
};

// ���������������� ���� ������'������ ������
template <typename T>
class List {
private:
    Node<T>* head; // �������� �� ������ ����� ������

public:
    // �����������, �� ������� ������� ������
    List() : head(nullptr) {}

    // ���������� ��� ��������� ���'��, ��'����� � �������
    ~List() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // ��������� �������� � ����� ������
    void append(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // ��������� ���������, �� ������ �� ������� ������
    ListIterator<T> begin() {
        return ListIterator<T>(head);
    }

    // ��������� ���������, �� ������ ���� ����� ������ (nullptr)
    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }
};


int main() {
    int a = 5, b = 4;
    double t = 3.5, q = 3.05;
    const char* s1 = "text";
    const char* s2 = "txt";

    int maxInt = max(a, b);
    int minInt = min(a, b);

    double maxDouble = max(t, q);
    double minDouble = min(t, q);

    const char* maxString = max(s1, s2);
    const char* minString = min(s1, s2);

    cout << "Max int: " << maxInt << endl;
    cout << "Min int: " << minInt << endl;
    cout << "Max double: " << maxDouble << endl;
    cout << "Min double: " << minDouble << endl;
    cout << "Max string: " << maxString << endl;
    cout << "Min string: " << minString << endl;

    // ����� ����� �����
    int intArr[] = { 5, 3, 8, 2, 1 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    bubbleSort(intArr, intSize);

    cout << "Sorted Int Array: ";
    for (int i = 0; i < intSize; ++i) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    int intKey = 3;
    int intIndex = binarySearch(intArr, intSize, intKey);
    if (intIndex != -1) {
        cout << "Integer " << intKey << " found at index: " << intIndex << endl;
    }
    else {
        cout << "Integer " << intKey << " not found." << endl;
    }

    // ����� ���� (const char*)
    const char* strArr[] = { "apple", "banana", "orange", "grape", "kiwi" };
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    bubbleSort(strArr, strSize);

    cout << "Sorted String Array: ";
    for (int i = 0; i < strSize; ++i) {
        cout << strArr[i] << " ";
    }
    cout << endl;

    const char* strKey = "orange";
    int strIndex = binarySearch(strArr, strSize, strKey);
    if (strIndex != -1) {
        cout << "String \"" << strKey << "\" found at index: " << strIndex << endl;
    }
    else {
        cout << "String \"" << strKey << "\" not found." << endl;
    }
    // ��������� ������'������ ������ ����� �����
    SinglyLinkedList<int> intList;

    // ��������� �������� �� ������
    intList.append(10);
    intList.append(20);
    intList.append(30);

    // ��������� ������ �� �����
    std::cout << "Integer List: ";
    intList.display();

    // ��������� ������'������ ������ �����
    SinglyLinkedList<std::string> strList;

    // ��������� �������� �� ������
    strList.append("apple");
    strList.append("banana");
    strList.append("orange");

    // ��������� ������ �� �����
    std::cout << "String List: ";
    strList.display();
    return 0;
    // ��������� ������'������ ������ ����� �����
    List<int> intList;

    // ��������� �������� �� ������
    intList.append(10);
    intList.append(20);
    intList.append(30);

    // ����������� �� ������ �� ��������� ��������� � ��������� ��������
    std::cout << "Integer List: ";
    for (ListIterator<int> it = intList.begin(); it.isValid(); it.next()) {
        std::cout << it.value() << " -> ";
    }
    std::cout << "nullptr" << std::endl;

    // ��������� ������'������ ������ �����
    List<std::string> strList;

    // ��������� �������� �� ������
    strList.append("apple");
    strList.append("banana");
    strList.append("orange");

    // ����������� �� ������ �� ��������� ��������� � ��������� ��������
    std::cout << "String List: ";
    for (ListIterator<std::string> it = strList.begin(); it.isValid(); it.next()) {
        std::cout << it.value() << " -> ";
    }
    std::cout << "nullptr" << std::endl;

}
