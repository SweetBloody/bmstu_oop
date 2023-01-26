#ifndef MATRIX_BASE_EXCEPTION_H
#define MATRIX_BASE_EXCEPTION_H

#include <iostream>
#include <string>
#include <ctime>

/// Выделить отдельные ошибки для итераторов

// For ctime() func unsafe warnings (Visual Studio)
#pragma warning(disable : 4996)

class MatrixBaseException : public std::exception
{
public:
	MatrixBaseException(std::string file, std::string classname, int line, time_t time, std::string msg)
	{
		error_msg = "File name: " + file + " in line " + std::to_string(line)
			+ "\nTime: " + ctime(&time) + "Info: " + msg + "\n";
	}

	virtual const char* what(void) const noexcept override { return (this->error_msg).c_str(); } 

protected:
	std::string error_msg;
};

class IndexException : public MatrixBaseException
{
public:
	IndexException(std::string file, std::string classname, int line, time_t time, std::string msg)
		: MatrixBaseException(file, classname, line, time, msg) { } ;
	const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class IsNotEqualException : public MatrixBaseException
{
public:
	IsNotEqualException(std::string file, std::string classname, int line, time_t time, std::string msg)
		: MatrixBaseException(file, classname, line, time, msg) { }
	const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class IsEmptyException : public MatrixBaseException
{
public:
	IsEmptyException(std::string file, std::string classname, int line, time_t time, std::string msg)
		: MatrixBaseException(file, classname, line, time, msg) { }
	const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class MultMatrixException : public MatrixBaseException
{
public:
	MultMatrixException(std::string file, std::string classname, int line, time_t time, std::string msg)
		: MatrixBaseException(file, classname, line, time, msg) { }
	const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class NullPtrException : public MatrixBaseException
{
public:
    NullPtrException(std::string file, std::string classname, int line, time_t time, std::string msg)
            : MatrixBaseException(file, classname, line, time, msg) { }
    const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class BadAllocException : public MatrixBaseException
{
public:
    BadAllocException(std::string file, std::string classname, int line, time_t time, std::string msg)
            : MatrixBaseException(file, classname, line, time, msg) { }
    const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

class MatrixDetException : public MatrixBaseException
{
public:
    MatrixDetException(std::string file, std::string classname, int line, time_t time, std::string msg)
        : MatrixBaseException(file, classname, line, time, msg) { }
    const char* what(void) const noexcept { return this->error_msg.c_str(); }
};

#endif // !MATRIX_BASE_EXCEPTION_H

