#include "pch.h"
#include "Calculator.h"
#include <cstring>


#define ERR_TOKEN_NOT_NUMBER    ( -1 )
#define ERR_NEGATIVE_OP         ( -2 )
#define ERR_OP_MISS             ( -3 )
#define ERR_DELIM_WITHOUT_END   ( -4 )


Calculator::Calculator() : exceptionMsg(NULL) {}
Calculator::~Calculator() {
    if (exceptionMsg) {
        free(exceptionMsg);
    }
}


/* String is number? */
static int CheckStr(char *str) {
    int i, length = strlen(str);

    i = (str[0] == '-') ? (1) : (0);
    for ( ; i < length; ++i) {
        if (isdigit(str[i]) == 0) {
            /* Not Number */
            return 0;
        } 
    }

    /* Good */
    return (1);
}


static int GetDelim(char **s, char **delim) {
    int status = 0;

    const char *DEFAULT_DELIM    = ",\n";
    const char *CHANGE_DELIM_TOK = "//";
    
    char *cur   = NULL;

    cur = strstr(*s, CHANGE_DELIM_TOK);
    if ( cur && (cur == *s) ) {
        *delim = cur + strlen(CHANGE_DELIM_TOK);

        /* Find terminate delim string */
        cur = strchr(*delim, '\n');
        if (cur) {
            *cur = '\0';
            *s = cur + 1;
        } else {
            status = ERR_DELIM_WITHOUT_END;
        }
    } else {
        /* Set default delim */
        *delim = (char *)DEFAULT_DELIM;
    }

    return (status);
}



static int Parse(char *tok, char *delim, char *nextSubStr) {
    int result = 0;

    if (CheckStr(tok)) {
        result = atoi(tok);
        if (result >= 0) {
            /* Check first char in the next substring */
            if (nextSubStr && (*nextSubStr != '\0')) {
                if (strchr(delim, *nextSubStr)) {
                    /* This is char is delimeter */
                    result = ERR_OP_MISS;
                }
            }
        } else {
            result = ERR_NEGATIVE_OP;
        }
    } else {
        result = ERR_TOKEN_NOT_NUMBER;
    }

    return (result);
}



int Calculator::Add(std::string expression) {
    return 0;
}



int Calculator::Add(char* expression) {
    char *delim;
    char *strCopy = strdup(expression);
    char *ptrFree = strCopy;
    char *tok, *rest;

    int result = 0, opCnt = 0;
    int sum    = 0, op = 0;

    /* Check Empty */
    if ((expression == NULL) || (strlen(expression) == 0)) {
        goto exit;
    }

    /* check on "//" */
    result = GetDelim(&strCopy, &delim);
    if (result != 0) {
        goto exit;
    }


    tok = strtok_s(strCopy, delim, &rest);

    while (true) {
        if (tok == NULL) {
            /* Parse complete */
            break;
        }

        op = Parse(tok, delim, rest);
        if (op < 0) {
            /* Fail complete, take code erroro from op value */
            result = op;
            break;
        } else {
            sum += op;
            tok  = strtok_s(rest, delim, &rest);
        }
    }

    if (result == 0) {
        result = sum;
    }

exit:
    /* Free memory */
    if (ptrFree) {
        free(ptrFree);
    }

    return (result);
}