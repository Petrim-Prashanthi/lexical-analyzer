#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

/* Check whether a word is a keyword */
int isKeyword(char *word)
{
    char *keywords[] = {
        "int", "float", "char", "double", "if", "else",
        "for", "while", "do", "return", "void", "switch",
        "case", "break", "continue", "long", "short"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

/* Check whether character is a separator */
int isSeparator(char ch)
{
    return ch == '(' || ch == ')' ||
           ch == '{' || ch == '}' ||
           ch == '[' || ch == ']' ||
           ch == ';' || ch == ',';
}

/* Check whether character is an operator */
int isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '%' || ch == '=' ||
           ch == '>' || ch == '<' ||
           ch == '!' || ch == '&' ||
           ch == '|';
}

int main()
{
    FILE *fp;
    char filename[100];

    char ch;
    char token[MAX];
    int i;

    int keywords = 0;
    int identifiers = 0;
    int operators = 0;
    int constants = 0;
    int stringLiterals = 0;
    int separators = 0;
    int comments = 0;

    printf("Enter source file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    printf("\nTOKEN TYPE\n");
    printf("------------------------------------------------\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Ignore white spaces */
        if (isspace(ch))
            continue;

        /* Identifier or Keyword */
        if (isalpha(ch) || ch == '_')
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            if (isKeyword(token))
            {
                printf("%-20s Keyword\n", token);
                keywords++;
            }
            else
            {
                printf("%-20s Identifier\n", token);
                identifiers++;
            }

            if (ch != EOF)
                ungetc(ch, fp);
        }

        /* Number constant */
        else if (isdigit(ch))
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isdigit(ch) || ch == '.'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            printf("%-20s Constant\n", token);
            constants++;

            if (ch != EOF)
                ungetc(ch, fp);
        }

        /* String literal */
        else if (ch == '"')
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && ch != '"')
            {
                token[i++] = ch;
            }

            if (ch == '"')
                token[i++] = ch;

            token[i] = '\0';

            printf("%-20s String Literal\n", token);
            stringLiterals++;
        }

        /* Comments or division operator */
        else if (ch == '/')
        {
            char next = fgetc(fp);

            /* Single-line comment */
            if (next == '/')
            {
                while ((ch = fgetc(fp)) != EOF && ch != '\n')
                    ;

                printf("%-20s Comment\n", "//");
                comments++;
            }

            /* Multi-line comment */
            else if (next == '*')
            {
                char prev = 0;

                while ((ch = fgetc(fp)) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }

                printf("%-20s Comment\n", "/* */");
                comments++;
            }

            /* Division operator */
            else
            {
                printf("%-20s Operator\n", "/");
                operators++;

                if (next != EOF)
                    ungetc(next, fp);
            }
        }

        /* Two-character operators */
        else if (ch == '=' || ch == '>' ||
                 ch == '<' || ch == '!' ||
                 ch == '+' || ch == '-' ||
                 ch == '&' || ch == '|')
        {
            char next = fgetc(fp);

            if ((ch == '=' && next == '=') ||
                (ch == '>' && next == '=') ||
                (ch == '<' && next == '=') ||
                (ch == '!' && next == '=') ||
                (ch == '+' && next == '+') ||
                (ch == '-' && next == '-') ||
                (ch == '&' && next == '&') ||
                (ch == '|' && next == '|'))
            {
                printf("%c%c                   Operator\n", ch, next);
                operators++;
            }
            else
            {
                printf("%-20c Operator\n", ch);
                operators++;

                if (next != EOF)
                    ungetc(next, fp);
            }
        }

        /* Single-character operators */
        else if (ch == '*' || ch == '%' ||
                 ch == '+')
        {
            printf("%-20c Operator\n", ch);
            operators++;
        }

        /* Separators */
        else if (isSeparator(ch))
        {
            printf("%-20c Separator\n", ch);
            separators++;
        }

        /* Special symbols */
        else
        {
            printf("%-20c Special Symbol\n", ch);
        }
    }

    printf("------------------------------------------------\n");

    printf("\nToken Count\n");
    printf("Keywords       : %d\n", keywords);
    printf("Identifiers    : %d\n", identifiers);
    printf("Operators      : %d\n", operators);
    printf("Constants      : %d\n", constants);
    printf("String Literals: %d\n", stringLiterals);
    printf("Separators     : %d\n", separators);
    printf("Comments       : %d\n", comments);

    fclose(fp);

    return 0;
}
