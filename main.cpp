#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <deque>
using namespace std;

//Итераторы в C++ - это объекты, которые используются для обхода элементов внутри контейнеров или последовательностей. Они предоставляют абстракцию, позволяющую оперировать элементами в контейнерах без необходимости знать внутреннюю структуру данных.

ostream& operator<< (ostream& out, const vector<int> p) {
    vector<int>::const_iterator start = p.begin(); //const_iterator используется для итерации по контейнеру, когда не планируется изменять значения элементов в контейнере
     while (start != p.end()) {
        out << *start << " ";
        ++start;
     }
    return out;
}
ostream& operator<< (ostream& out, const list<int> p) {
    list<int>::const_iterator start = p.begin(); 
     while (start != p.end()) {
        out << *start << " ";
        ++start;
     }
    return out;
}
ostream& operator<< (ostream& out, const deque<int> p) {
    deque<int>::const_iterator start = p.begin();
     while (start != p.end()) {
        out << *start << " ";
        ++start;
     }
    return out;
}

int main() {

    cout << "№1 Контейнерные алгоритмы" << endl;

    cout << "Создайте список целых чисел" << endl;
    cout << "Количество элементов: " << endl;
    int n;
    cin >> n;
    vector<int> task1; 
    cout << "Элементы: " << endl; 
    for (int i=0; i<n; i++) {
        int z;
        cin >> z;
        task1.push_back(z);
    }

    vector<int>::iterator first = task1.begin();//итератор, указывающий на первый элемент
    vector<int>::iterator after_last = task1.end();//итератор, указывающий на следующую позицию после последнего элемента
    int summa = 0,m = 1000000, M = -1000000;
    cout << "Введенный список: ";
    while (first != after_last) {
        cout << *first << " ";
        if (*first > M) {
            M = *first;
        }
        if (*first < m) {
            m = *first;
        }
        summa += *first;
        ++first;
    }
    cout << endl << "Сумма всех элементов: " << summa << endl;
    cout << "Максимальный и минимальный элементы: " << M << " " << m << endl << '\v' << '\v' << '\v';

    cout << "№2 Итераторы-адаптеры" << endl;

    vector<int> task2_vector = {1, 4, -9, 33, 6, -27, 2};
    cout << "vector:" << endl;
    cout << task2_vector << endl;
    auto back = back_inserter(task2_vector);//Функция back_inserter в C++ возвращает специальный итератор, который позволяет добавлять элементы в конец контейнера с помощью функции push_back. Когда используем auto, компилятор самостоятельно выведет тип back таким образом, что это будет итератор для контейнера task2_vector, который поддерживает операцию push_back.
    *back = 56;
    *inserter(task2_vector, task2_vector.begin()) = 2;
    *inserter(task2_vector, task2_vector.begin()+3) = 678;//работает +3, потому что вектор в C++ представляет собой динамический массив, где элементы хранятся в непрерывном блоке памяти
    cout << task2_vector << endl;
    
    list<int> task2_list= {2, 6, 11, -5, -100, 43, 1};
    cout << "list:" << endl;
    cout << task2_list << endl;;
    *back_inserter(task2_list) = 56;
    *inserter(task2_list, task2_list.begin()) = 8;
    *inserter(task2_list, next(task2_list.begin(),3)) = 111;//не работает +3, нужен next, потому что list представляет собой двусвязный список, где каждый элемент хранит ссылку на следующий и предыдущий элемент
    *front_inserter(task2_list) = 33;//не работает с vector. Причина заключается в том, что vector не предоставляет операцию push_front, которая требуется для front_inserter.
    cout << task2_list << endl << '\v' << '\v' << '\v';

    cout << "№3 Файловый ввод-вывод с итераторами" << endl << '\v' << '\v' << '\v';

    ifstream file_read;
    file_read.open("read.txt");
    istream_iterator<string> begin(file_read);//итератор ввода из потока. При создании этого итератора он начнет считывать данные из потока (файла) по мере продвижения по последовательности данных (в данном случае, строк)
    istream_iterator<string> end;//Здесь мы создаем "конечный" итератор, который представляет конец файла (или потока). Этот итератор используется для сравнения со входным итератором, чтобы определить момент достижения конца файла или потока данных.
    vector<string> gritings(begin, end);//Конструктор вектора предполагает, что begin будет итерироваться по данным до тех пор, пока не достигнет end, и скопирует все считанные строки в вектор.
    file_read.close();

    ofstream file_write;
    file_write.open("write.txt");
    ostream_iterator<string> write(file_write, "\n");//итератор вывода в поток. Второй аргумент `"\n"` указывает разделитель, который будет добавлен между каждым элементом при записи в выходной файл
    copy(gritings.begin(), gritings.end(), write);//функция  для копирования элементов из указанного диапазона в выходной поток, указанный итератором write
    file_write.close();

    cout << "№4 Взаимодействие итераторов" << endl;

    vector<int> task4_vector = {9, 8, 7, 6, 5, 4, 3, 2};
    deque<int> task4_deque;
    copy(task4_vector.begin(), task4_vector.end(), back_inserter(task4_deque));
    cout << "vevtor:" << endl << task4_vector << endl << "deque:" << endl << task4_deque << endl << '\v' << '\v' << '\v';

    cout << "№5 Обратные итераторы" << endl;

    cout << "Создайте список целых чисел" << endl;
    cout << "Количество элементов: " << endl;
    int k;
    cin >> k;
    vector<int> task5; 
    cout << "Элементы: " << endl; 
    for (int i=0; i<k; i++) {
        int z;
        cin >> z;
        task5.push_back(z);
    }

    vector<int>::reverse_iterator last = task5.rbegin();//обратный итератор, указывающий на последний элемент
    vector<int>::reverse_iterator before_first = task5.rend();//обратный итератор, указывающйи на элемент перед первым, (a-1) это первый
    cout << "Введенный список:" << endl << task5 << endl;
    cout << "Список в обратном порядке:" << endl;
    while(last != before_first) {
        cout << *last << " ";
        ++last;
    }
    cout << endl;

    return 0;
}
