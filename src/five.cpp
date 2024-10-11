#include "five.h"

Five::Five() {
    _size = 1;
    _array = new unsigned char[1];
    _array[0] = 0;
}

Five::Five(char t) {
    _size = 1;
    if (t < '0' || t > '4') throw std::invalid_argument("invalid symbol");
    _array = new unsigned char[_size];
    _array[0] = t - '0';
}

Five::Five(const int t) {
    int num = t;
    int i = 0;
    if (t == 0) {
        _size = 1;
        _array = new unsigned char[_size];
        _array[0] = 0;
        return;
    }
    for (i; num; ++i) {
        num /= 5;
    }
    num = t;
    _size = i;
    _array = new unsigned char[_size];
    for (i = 0; i < _size && num; ++i) {
        _array[i] = static_cast<unsigned char>(num % 5);
        num /= 5;
    }
}

Five::Five(const std::initializer_list<unsigned char> &t)  
{   
    if (t.size() == 0) throw std::invalid_argument("cannot create a number from an empty list");
    auto t_array = t.begin();
    size_t number_of_nulls = 0;
    if (t_array[0] == 0) {
        for (auto &c : t) { 
            if (c != 0) break;
            number_of_nulls++;
        }
    }
    _size = t.size() - number_of_nulls;
    if (number_of_nulls == t.size()) {
        _size = 1;
        number_of_nulls--;
    }
    _array = new unsigned char[_size];
    for (size_t i = number_of_nulls; i < t.size(); ++i) {
        if (t_array[i] > 4 || t_array[i] < 0) throw std::invalid_argument("invalid value");
        _array[_size - 1 - i + number_of_nulls] = t_array[i];
    }
}

Five::Five(const std::string &t) {
    if (t.empty()) throw std::invalid_argument("cannot create a number from an empty string");
    size_t number_of_nulls = 0;
    if (t[0] == '0') {
        for (size_t i = 0; i < t.size(); ++i) {
            if (t[i] != '0') break;
            number_of_nulls++;
        }
    }
    _size = t.size() - number_of_nulls;
    if (number_of_nulls == t.size()) {
        _size = 1;
        number_of_nulls--;
    }
    _array = new unsigned char[_size];
    for (size_t i = number_of_nulls; i < t.size(); ++i) {
        if (t[i] < '0' || t[i] > '4') throw std::invalid_argument("invalid symbol");
        _array[_size - 1 - i + number_of_nulls] = t[i] - '0';
    }
}

Five::Five(const size_t size) {
    _size = size;
    _array = new unsigned char[_size];
}

Five::Five(const Five& other) {
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

Five::Five(Five&& other) noexcept {
    _size = other._size;
    _array = other._array;
    other._array = nullptr;
    other._size = 0;
}

int Five::size() const {
    return _size;
}

std::string Five::toStr() const {
    std::string result;
    for (int i = _size - 1; i >= 0; --i) {
        result.append(1, static_cast<char>(_array[i] + '0'));
    }
    return result;
}

bool Five::equals(const Five& other) const {
    if (_size != other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

bool Five::more(const Five& other) const {
    if (_size > other._size) {
        return true;
    } else if (_size < other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        size_t pos = _size - i - 1;
        if (_array[pos] != other._array[pos]) {
            return _array[pos] > other._array[pos];
        }
    }
    return false;
}

bool Five::less(const Five& other) const {
    if (_size < other._size) {
        return true;
    } else if (_size > other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        size_t pos = _size - i - 1;
        if (_array[pos] != other._array[pos]) {
            return _array[pos] < other._array[pos];
        }
    }
    return false;
}

Five Five::sum(const Five& other) const {
    size_t sum_size = std::max<size_t>(_size, other._size);
    Five result(sum_size);
    unsigned char sum = 0;
    for (size_t i = 0; i < std::min<size_t>(_size, other._size); ++i) {
        sum += (_array[i] + other._array[i]);
        result._array[i] = sum % 5;
        sum /= 5;
    }
    const Five& max_number = (_size >= other._size) ? *this : other;
    for (size_t i = std::min<size_t>(_size, other._size); i < std::max<size_t>(_size, other._size); ++i) {
        sum += (max_number._array[i]);
        result._array[i] = sum % 5;
        sum /= 5;
    }
    if (sum) {
        result._size += 1;
        unsigned char * new_result_array = new unsigned char[result._size];
        for (size_t i = 0; i < sum_size; ++i) {
            new_result_array[i] = result._array[i];
        }
        new_result_array[sum_size] = sum;
        delete[] result._array;
        result._array = new_result_array;
    }
    return result;
}

void Five::add(const Five& other) {
    size_t sum_size = std::max<size_t>(_size, other._size);
    unsigned char * result_array = new unsigned char[sum_size];
    unsigned char sum = 0;
    for (size_t i = 0; i < std::min<size_t>(_size, other._size); ++i) {
        sum += (_array[i] + other._array[i]);
        result_array[i] = sum % 5;
        sum /= 5;
    }
    const Five& max_number = (_size >= other._size) ? *this : other;
    for (size_t i = std::min<size_t>(_size, other._size); i < std::max<size_t>(_size, other._size); ++i) {
        sum += (max_number._array[i]);
        result_array[i] = sum % 5;
        sum /= 5;
    }
    if (sum) {
        unsigned char * new_result_array = new unsigned char[sum_size + 1];
        for (size_t i = 0; i < sum_size; ++i) {
            new_result_array[i] = result_array[i];
        }
        new_result_array[sum_size] = sum;
        delete[] _array;
        _array = new_result_array;
        _size = sum_size + 1;
        return;
    }
    delete[] _array;
    _array = result_array;
    _size = sum_size;
}

Five Five::subtract(const Five& other) const {
    if (this->less(other)) throw std::underflow_error("Five object can't be negative");
    Five result(_size);
    unsigned char tmp = 0;
    for (size_t i = 0; i < other._size; ++i) {
        tmp = (5 + _array[i] - other._array[i] + tmp);
        result._array[i] = tmp % 5;
        tmp = tmp / 5 - 1;
    }
    for (size_t i = other._size; i < _size; ++i) {
        tmp = (5 + _array[i] + tmp);
        result._array[i] = tmp % 5;
        tmp = tmp / 5 - 1;
    }
    if (result._array[_size - 1] == 0) {
        size_t number_of_nulls = 1;
        for (size_t i = _size - 1; i >= 1; --i) {
            if (result._array[i - 1] != 0) break;
            number_of_nulls++;
        }
        if (number_of_nulls == _size) {
            unsigned char * new_result_array = new unsigned char[1];
            result._size = 1;
            new_result_array[0] = 0;
            return result;
        }
        unsigned char * new_result_array = new unsigned char[result._size - number_of_nulls];
        for (size_t i = 0; i < result._size - number_of_nulls; ++i) {
            new_result_array[i] = result._array[i];
        }
        delete[] result._array;
        result._array = new_result_array;
        result._size = result._size - number_of_nulls;
    }
    return result;
}

void Five::remove(const Five& other){
    if(this->less(other)) throw std::underflow_error("Five object can't be negative");
    unsigned char * result_array = new unsigned char[_size];
    unsigned char tmp = 0;
    for (size_t i = 0; i < other._size; ++i){
        tmp = (5 + _array[i] - other._array[i] + tmp);
        result_array[i] = tmp % 5;
        tmp = tmp / 5 - 1;
    }
    for (size_t i = other._size; i < _size; ++i){
        tmp = (5 + _array[i] + tmp);
        result_array[i] = tmp % 5;
        tmp = tmp / 5 - 1;
    }
    if (result_array[_size - 1] == 0){
        size_t number_of_nulls = 1;
        for (size_t i = _size - 1; i >= 1; --i){
            if (result_array[i - 1] != 0) break;
            number_of_nulls++;
        }
        if (number_of_nulls == _size) {
            unsigned char * new_result_array = new unsigned char[1];
            new_result_array[0] = 0;
            _size = 1;
            delete[] _array;
            _array = new_result_array;
            return;
        }
        unsigned char * new_result_array = new unsigned char[_size - number_of_nulls];
        for (size_t i = 0; i < _size - number_of_nulls; ++i) {
            new_result_array[i] = result_array[i];
        }
        delete[] _array;
        _array = new_result_array;
        _size = _size - number_of_nulls;
        return;
    }
    delete[] _array;
    _array = result_array;
}

std::ostream &Five::print(std::ostream &os){   
    for (size_t i = 0; i < _size; ++i) {
        os << (static_cast<int>(_array[_size - i - 1]));
    }
    return os;
}

Five::~Five() noexcept {
    if (_array != nullptr){
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}
