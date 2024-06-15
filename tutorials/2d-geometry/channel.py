from formo import *

WIDTH = 5
HEIGHT = 1
RADIUS = 0.1
CENTER = Point(1, 0, 0)

pt1 = Point(0, -HEIGHT/2, 0)
pt2 = Point(WIDTH, -HEIGHT/2, 0)
pt3 = Point(WIDTH, HEIGHT/2, 0)
pt4 = Point(0, HEIGHT/2, 0)

wire_rect = Wire([
    Line(pt1, pt2),
    Line(pt2, pt3),
    Line(pt3, pt4),
    Line(pt4, pt1)
])
rect = Face(wire_rect)

wire_circ = Wire([
    Circle(CENTER, RADIUS)
])
circ = Face(wire_circ)

channel = rect.cut(circ)

write("channel.step", [channel])
