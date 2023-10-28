#ifndef CSVREADER_H
#define CSVREADER_H
#include "fstream"
#include "vector"
#include "QColor"

struct Film{
    int id;
    std::string name;
    int year;
    std::string genre;
    QColor color;
};

class CsvReader{
        public:
        CsvReader(const std::string& filename);
        bool isOpen();

        std::vector<Film> readAll();
        int getMaxId(const std::vector<Film>& film);

private:
        std::ifstream fin;
};

#endif // CSVREADER_H
