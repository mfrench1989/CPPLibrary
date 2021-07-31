#include "class_data.hpp"

#define DATA_ERROR -1

ClassData::ClassData() {
}

/*================================================================*/
/*Public Methods*/
/*================================================================*/
void ClassData::dataClear() {
  Vector_Data.clear();
}

void ClassData::dataPush(const std::string& label_in, const std::vector<char>& bytes_in) {
  Vector_Data.push_back({label_in, bytes_in});
}

int ClassData::dataIndex(const std::string& label_in) {
  for (int i = 0; i < static_cast<int>(Vector_Data.size()); ++i) {
      if (Vector_Data.at(i).Label == label_in) {
          return i;
        }
    }
  return DATA_ERROR;
}

std::string ClassData::dataLabel(const int index_in) {
  if (index_in < 0 || index_in >= static_cast<int>(Vector_Data.size())) {
      return std::string();
    }
  return Vector_Data.at(index_in).Label;
}

std::vector<char> ClassData::dataBytes(const int index_in) {
  if (index_in < 0 || index_in >= static_cast<int>(Vector_Data.size())) {
      return std::vector<char>();
    }
  return Vector_Data.at(index_in).Bytes;
}

std::vector<char> ClassData::dataBytes(const std::string& label_in) {
  for (int i = 0; i < static_cast<int>(Vector_Data.size()); ++i) {
      if (Vector_Data.at(i).Label == label_in) {
          return Vector_Data.at(i).Bytes;
        }
    }
  return std::vector<char>();
}

std::vector<std::string> ClassData::dataList() {
  std::vector<std::string> vector_out;
  for (const Data& data : Vector_Data) {
      vector_out.push_back(data.Label);
    }
  return vector_out;
}

