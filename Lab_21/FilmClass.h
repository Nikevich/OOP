#ifndef FILMCLASS_H
#define FILMCLASS_H
#include "fstream"
#include "vector"
#include "QColor"

struct Film {
    int id = 0;
    std::string name = "";
    int year = 0;
    std::string genre = "";
    QColor color = QColor(0, 0, 0);

    // Перегрузка оператора <
    bool operator<(const Film& film) const {
        return year < film.year;
    }

    // Перегрузка оператора ==
        bool operator==(const Film& film) const {
            return year == film.year;
        }

    // Перегрузка оператора вывода
        friend std::ostream& operator<<(std::ostream& os, const Film& film) {
            os << "ID: " << film.id << ", Name: " << film.name << ", Year: " << film.year;
            return os;
        }

    //Film() = default;
};

class AbstractClass{
public:
    virtual bool  isOpen() = 0;
    virtual std::vector<Film> readAll() = 0;
};





#endif // FILMCLASS_H
