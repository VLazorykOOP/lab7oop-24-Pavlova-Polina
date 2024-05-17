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

// Спеціалізація функції-шаблону для типу char*
template <>
const char* max<const char*>(const char* x, const char* y) {
    return (strcmp(x, y) > 0) ? x : y;
}

template <>
const char* min<const char*>(const char* x, const char* y) {
    return (strcmp(x, y) < 0) ? x : y;
}
// шаблон для сортування методом бульбашки
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

// шаблон для бінарного пошуку
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

    return -1; // елемент не знайдено
}

// Спеціалізація шаблонів для типу const char*
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

    return -1; // рядок не знайдено
}

// Клас вузла списку
template <typename T>
class Node {
public:
    T data; // Дані, збережені у вузлі
    Node* next; // Вказівник на наступний вузол

    // Конструктор, який ініціалізує дані та вказівник на NULL
    Node(T value) : data(value), next(nullptr) {}
};

// Параметризований клас однозв'язного списку
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head; // Вказівник на перший вузол списку

public:
    // Конструктор, що створює порожній список
    SinglyLinkedList() : head(nullptr) {}

    // Деструктор для звільнення пам'яті, зв'язаної з списком
    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Додавання елемента в кінець списку
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

    // Виведення списку на екран
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};
// Клас вузла списку
template <typename T>
class Node {
public:
    T data; // Дані, збережені у вузлі
    Node* next; // Вказівник на наступний вузол

    // Конструктор, що ініціалізує дані та вказівник на NULL
    Node(T value) : data(value), next(nullptr) {}
};

// Клас ітератора для проходження по списку
template <typename T>
class ListIterator {
private:
    Node<T>* current; // Поточний вузол, на якому знаходиться ітератор

public:
    // Конструктор ітератора
    ListIterator(Node<T>* startNode) : current(startNode) {}

    // Перевірка, чи ітератор показує на дійсний вузол списку
    bool isValid() const {
        return current != nullptr;
    }

    // Переміщення ітератора до наступного вузла у списку
    void next() {
        if (current != nullptr) {
            current = current->next;
        }
    }

    // Отримання значення поточного вузла
    T& value() const {
        if (current == nullptr) {
            throw std::logic_error("Iterator is not valid");
        }
        return current->data;
    }
};

// Параметризований клас однозв'язного списку
template <typename T>
class List {
private:
    Node<T>* head; // Вказівник на перший вузол списку

public:
    // Конструктор, що створює порожній список
    List() : head(nullptr) {}

    // Деструктор для звільнення пам'яті, зв'язаної зі списком
    ~List() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Додавання елемента в кінець списку
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

    // Отримання ітератора, що показує на початок списку
    ListIterator<T> begin() {
        return ListIterator<T>(head);
    }

    // Отримання ітератора, що показує поза кінець списку (nullptr)
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

    // Масив цілих чисел
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

    // Масив рядів (const char*)
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
    // Створення однозв'язного списку цілих чисел
    SinglyLinkedList<int> intList;

    // Додавання елементів до списку
    intList.append(10);
    intList.append(20);
    intList.append(30);

    // Виведення списку на екран
    std::cout << "Integer List: ";
    intList.display();

    // Створення однозв'язного списку рядків
    SinglyLinkedList<std::string> strList;

    // Додавання елементів до списку
    strList.append("apple");
    strList.append("banana");
    strList.append("orange");

    // Виведення списку на екран
    std::cout << "String List: ";
    strList.display();
    return 0;
    // Створення однозв'язного списку цілих чисел
    List<int> intList;

    // Додавання елементів до списку
    intList.append(10);
    intList.append(20);
    intList.append(30);

    // Проходження по списку за допомогою ітератора і виведення елементів
    std::cout << "Integer List: ";
    for (ListIterator<int> it = intList.begin(); it.isValid(); it.next()) {
        std::cout << it.value() << " -> ";
    }
    std::cout << "nullptr" << std::endl;

    // Створення однозв'язного списку рядків
    List<std::string> strList;

    // Додавання елементів до списку
    strList.append("apple");
    strList.append("banana");
    strList.append("orange");

    // Проходження по списку за допомогою ітератора і виведення елементів
    std::cout << "String List: ";
    for (ListIterator<std::string> it = strList.begin(); it.isValid(); it.next()) {
        std::cout << it.value() << " -> ";
    }
    std::cout << "nullptr" << std::endl;

}
