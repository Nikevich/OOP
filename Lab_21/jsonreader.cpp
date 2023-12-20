#include "JsonReader.h"
#include "json.hpp"


JsonReader::JsonReader(const std::string& filename){
    fin.open(filename);
}
bool JsonReader::isOpen(){
    return fin.is_open();
}

std::vector<Film> JsonReader::readAll() {
    std::vector<Film> result;

    nlohmann::json json;

    fin >> json;

    for(const auto & j: json) {
        Film e;

        e.id = j["id"].get<int>();
        e.name = j["name"].get<std::string>();
        e.genre = j["genre"].get<std::string>();
        e.year = j["year"].get<int>();
        e.color = QColor(j["color"].get<std::string>().c_str());

        result.push_back(e);
    }

    return result;
}
