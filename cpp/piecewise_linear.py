#!/bin/python3
import math

class Vec3():
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return Vec3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vec3(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, scalar):
        return Vec3(self.x * scalar, self.y * scalar, self.z * scalar)

    def dot(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def norm(self):
        return math.sqrt(self.dot(self))

    def __str__(self):
        return f'[{self.x}, {self.y}, {self.z}]'

def getLength(trajectory):
    length = 0
    for i, point in enumerate(trajectory):
        if (i != len(trajectory) - 1):
            length += (trajectory[i] - trajectory[i+1]).norm()
    return length

def interpolateTrajectory(points, t):
    length = getLength(points)
    remaining_length = t * length
    for i, point in enumerate(points[:-1]):
        segment_length = (points[i] - points[i+1]).norm()
        if remaining_length < segment_length:
            segment_t = remaining_length / segment_length
            return points[i] * (1-segment_t) + points[i+1] * segment_t
        else:
            remaining_length -= segment_length
    return points[len(points) - 1]


def main():

    points = [Vec3(0, 0, 0),Vec3(1, 0, 0),Vec3(1, 1, 0),Vec3(3, 1, 0)]
    print(f't = 0.0: {interpolateTrajectory(points, 0.0)}')
    print(f't = 0.2: {interpolateTrajectory(points, 0.2)}')
    print(f't = 0.4: {interpolateTrajectory(points, 0.4)}')
    print(f't = 0.6: {interpolateTrajectory(points, 0.6)}')
    print(f't = 0.8: {interpolateTrajectory(points, 0.8)}')
    print(f't = 1.0: {interpolateTrajectory(points, 1.0)}')

if __name__ == "__main__":
    main()