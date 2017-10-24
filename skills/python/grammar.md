## Some Basic Grammar
---
### 1.Built-In Types and Data Structures

### 2.Control Flow
+ ***if*** Statements
```python
if x < 0:
    print("x < 0")
elif x == 0:
    print("x==0")
else:
    print("x > 0")
```
+ ***for*** Statements
```python
>>> for w in words[:]:  # Loop over a slice copy of the entire list.
...     if len(w) > 6:
...         words.insert(0, w)
...
>>> words
['defenestrate', 'cat', 'window', 'defenestrate']
```
+ ***range()*** Function
```python
>>> for i in range(3):
...     print(i)
...
0
1
2
>>> list(range(5))
[0, 1, 2, 3, 4]
```

+ ***break*** and ***continue*** Statements, and ***else*** Clauses on Loops
 The ***else*** Clauses is executed when the loop terminates through exhaustion of the list (with ***for***) or when the condition becomes false (with ***while***), but not when the loop is terminated by a break statement.

```python
>>> for n in range(2, 5):
...     for x in range(2, n):
...         if n % x == 0:
...             print(n, 'equals', x, '*', n//x)
...             break
...     else:
...         # loop fell through without finding a factor
...         print(n, 'is a prime number')
...
2 is a prime number
3 is a prime number
4 equals 2 * 2
```
+ **Defining Functions**

```python
>>> def fib(n):    # write Fibonacci series up to n
...     """Print a Fibonacci series up to n."""
...     a, b = 0, 1
...     while a < n:
...         print(a, end=' ')
...         a, b = b, a+b
...     print()
...
>>> # Now call the function we just defined:
... fib(2000)
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597
#---------------------------------------------------------
# parameter passing
def foo(a, b):
    "parameter passing in function"
    print(">>>parameter passing")
    print("addr(a) = {:#X}, addr(b) = {:#X}".format(id(a), id(b)))
    a = 2
    b.append(1)
    print(">>>assignments")
    print("addr(a) = {:#X}, addr(b) = {:#X}".format(id(a), id(b)))

c = 1
d = [12]
print(">>>before")
print("addr(c) = {:#X}, addr(d) = {:#X}".format(id(c), id(d)))
foo(c, d)
print(">>>after")
print("c = {0}, d = {1}".format(c, d))

>>>before
addr(c) = 0X560BA944AE80, addr(d) = 0X7F9D78C13108
>>>parameter passing
addr(a) = 0X560BA944AE80, addr(b) = 0X7F9D78C13108
>>>assignments
addr(a) = 0X560BA944AEA0, addr(b) = 0X7F9D78C13108
>>>after
c = 1, d = [12, 1]
```
