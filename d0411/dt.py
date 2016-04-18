f = open('data.txt', 'w')
import random
f.write('300\n')
for i in xrange(300):
    f.write('%d\n'%random.randint(1, 100000))
f.close();
