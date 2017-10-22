## Some Basic Grammar
---
### 1.Built-In Types

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
