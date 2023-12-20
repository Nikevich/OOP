#include "csvreader.h"

static std::vector<std::string> split_line(const std::string &str, char delim) {

    std::vector<std::string> tokens;

    if (!str.empty()) {
        size_t start = 0, end;
        do {
            tokens.push_back(str.substr(start, (str.find(delim, start) - start)));
            end = str.find(delim, start);
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}


CsvReader::CsvReader(const std::string& filename){
    fin.open(filename);
}
bool CsvReader::isOpen(){
    return fin.is_open();
}

    std::vector<Film> CsvReader::readAll(){
        std::vector<Film> emp;
        while(!fin.eof())
        {
            std::string line;
            std::getline(fin, line);
            auto tokens = split_line(line, ';');
            if (tokens.size() >= 4) {
                Film e;
                e.id = std::strtol(tokens[0].data(), nullptr, 10);
                e.name = tokens[1];
                e.genre = tokens[2];
                e.year = std::strtol(tokens[3].data(), nullptr, 10);

                if (tokens.size() >= 5) {
                    e.color = QColor(tokens[4].c_str());
                } else {
                    e.color = QColor(0, 0, 0);
                } // Для цвета - 4 лаба
                emp.push_back(e);
            }
        }
        return emp;
    }
int CsvReader::getMaxId(const std::vector<Film>& films) {
    int maxId = 0;

    for (const Film& film : films) {
            if (film.id > maxId) {
                maxId = film.id;
            }
        }
        return maxId;
    }
    std::ifstream fin;
