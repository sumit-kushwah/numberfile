import matplotlib.pyplot as plt
import numpy as np

xvalues = list(range(1, 20000))
yvalues = list()
for value in xvalues:
    temp = "{0:b}".format(value)
    temp = temp[::-1]
    temp = int(temp, 2)
    yvalues.append(value - temp)

xpoints = np.array(xvalues)
ypoints = np.array(yvalues)

plt.scatter(xpoints, ypoints)
plt.show()