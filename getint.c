#include <stdio.h>
#include <ctype.h>

#define SIZE 1000

int getch(void) ;
void ungetch(int) ;

int main(void)
{
    int i, n, array[SIZE], getint(int *);

    array[0] = -5948328;
    
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    array[n] = -5948328;

    for (i = 0; i < SIZE && array[i] != -5948328; i++)
        printf("%d\n", array[i]);


    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // it's not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getch();
    }
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
