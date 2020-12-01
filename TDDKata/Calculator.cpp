#include "pch.h"
#include "Calculator.h"
#include <string.h>

/* String is number? */
static int CheckStr(char *str) {
    int i, length = strlen(str);
    for (i = 0; i < length; ++i) {
        if (isdigit(str[i]) == 0) {
            /* Not Number */
            return 0;
        } 
    }

    /* Good */
    return (1);
}



int Calculator::Add(std::string expression)
{
    return 0;
}

#define MAX_OP                  (255)
#define ERR_MANY_ARG            (-10)
#define ERR_TOKEN_NOT_NUMBER    (-1 )
#define ERR_BAD_SPLIT_CHAR      (-2 )
#define ERR_OP_MISS             (-3 )

int Calculator::Add(char* expression) {
    const char* delim = ",\n";

    char *strCopy = strdup(expression);
    char *ptrFree = strCopy;

    int result, op[MAX_OP] = { 0, 0 };
    int opCnt = 0;
    char *tok;

        /* Check Empty */
    if ((expression == NULL) || (strlen(expression) == 0)) {
        return (0);
    }

    if (strstr(expression, delim)) {
        result = ERR_OP_MISS;
        return (result);
    }

    opCnt  = 0;
    tok    = strtok(strCopy, delim);

    if (strcmp(strCopy, expression) == 0) {
        if (!CheckStr(tok)) {
            result = ERR_BAD_SPLIT_CHAR;
            return (result);
        }
    }

    result = 0;

    while (true) {
        if (tok == NULL) {
            break;
        }

        if (opCnt >= MAX_OP) {
            result = ERR_MANY_ARG;
            break;
        }

        if (CheckStr(tok)) {
            op[opCnt] = atoi(tok);
            tok       = strtok(NULL, delim);
            opCnt++;
        } else {
            result = ERR_TOKEN_NOT_NUMBER;
            break;
        }
    }

    if (result >= 0) {
        for (int i = 0; i < opCnt; ++i)
        result += op[i];
    }

    /* Clean memory */
    if (ptrFree) {
        free(ptrFree);
    }

    return (result);
}
