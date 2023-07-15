#include <stdbool.h>
#include <stdio.h>

#define fn int
#define arg (
#define dcl ) {
#define body return (
#define nf ); }

#define if(cond) (cond) && (
#define elif(cond) , true) || (cond) && (
#define else , true) || (
#define fi , true)

fn getnum arg
    void
dcl
    int n;
body
    scanf("%d", &n), n
nf

fn fizzbuzz arg
    int n
dcl body
    if (n % 15 == 0)
        puts("FizzBuzz")
    elif (n % 3 == 0)
        puts("Fizz")
    elif (n % 5 == 0)
        puts("Buzz")
    else
        printf("%d\n", n)
    fi, 0
nf

fn repeat arg
    int i,
    int n
dcl body
    if (i <= n)
        fizzbuzz(i),
        repeat(i + 1, n)
    fi, 0
nf

fn repwrap arg
    int n
dcl body
    repeat(1, n), 0
nf

fn main arg
    void
dcl body
    repwrap(getnum()), 0
nf
