///////////////////////////////////////////////////////////
// VectError.h
#ifndef _VECT_ERROR_
#define _VECT_ERROR_

#include <iostream>

#define DEBUG  // Режим отладки

// Базовый класс для ошибок вектора
class VectError {
public:
    VectError() {}

    virtual void ErrMsg() const {
        std::cerr << "Error with Vect object.\n";
    }

    void Continue() const {
#ifdef DEBUG
        std::cerr << "Debug: program is being continued.\n";
#else
        throw;  // Повторно выбрасываем исключение
#endif
    }
};

// Ошибка выхода за границы диапазона
class VectRangeErr : public VectError {
public:
    VectRangeErr(int _min, int _max, int _actual)
        : min(_min), max(_max), actual(_actual) {}

    void ErrMsg() const override {
        std::cerr << "Error of Index: ";
        std::cerr << "possible range: " << min << " - " << max << ", ";
        std::cerr << "actual Index: " << actual << std::endl;
        Continue();
    }

private:
    int min, max;
    int actual;
};

// Ошибка удаления из пустого вектора
class VectPopErr : public VectError {
public:
    void ErrMsg() const override {
        std::cerr << "Error of pop\n";
        Continue();
    }
};

#endif /* _VECT_ERROR_ */
///////////////////////////////////////////////////////////