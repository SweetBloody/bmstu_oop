#ifndef LAB_02_ITERATOR_EXCEPTION_H
#define LAB_02_ITERATOR_EXCEPTION_H

#include <exception>
#include <string>

#include "matrix_base_exception.h"

class NullPointerIteratorException : public MatrixBaseException
{
public:
    NullPointerIteratorException(std::string file, std::string classname, int line, time_t time, std::string msg)
        : MatrixBaseException(file, classname, line, time, msg) { };
    const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class IndexIteratorException : public MatrixBaseException
{
public:
    IndexIteratorException(std::string file, std::string classname, int line, time_t time, std::string msg)
            : MatrixBaseException(file, classname, line, time, msg) { } ;
    const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

#endif //LAB_02_ITERATOR_EXCEPTION_H
