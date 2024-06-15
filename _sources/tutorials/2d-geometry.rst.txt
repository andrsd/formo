2D geometry
===========

Even though formo is inherently 3-dimensional, 2D geometries are also possible.
Usually you can just set all z-coordinates to ``0``.

In this tutorial, we create a simple 2D rectangular channel with a circular obstacle.

.. image:: pics/2d-channel.png

1. Define some parameters, first:

   .. code::

      WIDTH = 5
      HEIGHT = 1
      RADIUS = 0.1
      CENTER = Point(1, 0, 0)

2. Create the rectangular channel

   .. code::

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

3. Create the circular obstacle

   .. code::

      wire_circ = Wire([
          Circle(CENTER, RADIUS)
      ])
      circ = Face(wire_circ)

4. Cut a "hole" into channel:

   .. code::

      channel = cut(rect, circ)

5. Export the final result

   .. code::

      write("channel.step", [channel])
