#ifndef ERROR_H
#define ERROR_H

enum errors
{
    OK,
    NO_FILE,
    FILE_FORMAT_ERR,
    FILE_CONTENT_ERR,
    PTR_ALL_ERR,
    NO_DATA,
    NO_LINKS,
    UNKNOWN_COMMAND
};

void error_message(errors err);

#endif // ERROR_H
