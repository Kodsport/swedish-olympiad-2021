from random import randint
print(10,11)
for i in range(10):
    for j in range(11):
        k = randint(0,3);
        if(k == 0): print('#', end='')
        else: print('.', end='')
    print()
