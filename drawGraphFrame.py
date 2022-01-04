import sys
import time
import numpy as np
from matplotlib import animation as animation, pyplot as plt, cm
"""
The goal of this file is to draw a plot plot representing the order of a vector of ints contents.
This is a python wrapper for this process, and should be called any time a swap operation occurs.
"""


plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

fig = plt.figure()
totalSeries = []
for line in sys.stdin:
    series = line.strip().split()
    series = [int(num) for num in series]
    totalSeries.append(series)

bars = plt.bar(range(len(totalSeries[0])), totalSeries[0], facecolor='green', alpha=0.75)

def animate(frame):
    for rect, h in zip(bars, totalSeries[frame]):
        rect.set_height(h)
        

ani = animation.FuncAnimation(fig, animate, frames=len(totalSeries),
        interval=1, repeat=False)

plt.show()







