#coding=utf-8

import random

f = open('vision.in', 'w')



for i in xrange(300):
    a = random.randint(1, 40)
    b = random.randint(1, 40)
    while (a == b):
        b = random.randint(1, 40)
    f.write('%d %d 1 1\n'%(a, b))
f.close()
