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

class AbstractClass{
public:
    virtual bool  isOpen() = 0;
    virtual std::vector<Film> readAll() = 0;
};

class CsvReader : public AbstractClass{
public:
        CsvReader(const std::string& filename);

        bool isOpen() override ;
        std::vector<Film> readAll() override ;
        int getMaxId(const std::vector<Film>& film);

private:
        std::ifstream fin;
};

#endif // CSVREADER_H
