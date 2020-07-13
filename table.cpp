#include "test_runner.h"

using namespace std;

template <typename T> class Table {
private:
  vector<vector<T>> data;

public:
  Table(size_t row, size_t column) { Resize(row, column); }
  const vector<T> &operator[](size_t ind) const { return data[ind]; }
  vector<T> &operator[](size_t ind) { return data[ind]; }
  void Resize(size_t row, size_t column) {
    data.resize(row);
    for (auto &i : data) {
      i.resize(column);
    }
  }
  pair<size_t, size_t> Size() const {
    return {data.size(), (data.empty() ? 0 : data.at(0).size())};
  }
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
