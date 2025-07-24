Formo Primer
=============

Formo is build on top of `Open Cascade technology <https://www.opencascade.com/>`_, which is a
modelling engine using `boundary representation <https://en.wikipedia.org/wiki/Boundary_representation>`_
with very rich API and coming with a lot of capabilities.
This can be quite overwhelming for a new-comer and this is one of the reasons formo was created.

Formo tries to offer intuitive API to allow users to create their paramerical models easily.
It provides simple modeling primitives like ``Point``, ``Line``, ``Circle``, ``Box``, ``Cylinder``, etc.
that can be used to build complex geometries.

The final models can be exported to industry standard file formats like `STEP <https://en.wikipedia.org/wiki/ISO_10303>`_.
These files can then be used for further processing.

Basic Concepts
--------------

The basic concept is based on object-oriented approach to models.
This allows users to use composition and inheritance to create more complicated models.

Core modeling entities (like lines, arcs, etc.) can be combined into higher-level entities (like
shapes).

Formo comes with a python wrapper, so all models can be scripted using the power of python language.


Object-Oriented Models
----------------------

Since the modeling entities in formo are objects, the user doesn't deal with ID-based models.
Compare the following two approaches:

.. grid:: 2

   .. grid-item-card::  formo

      .. code::

         pt1 = Point(0, 0, 0)
         pt2 = Point(1, 0, 0)
         line = Line(pt1, pt2)

   .. grid-item-card::  Cubit

      .. code::

         create vertex 0 0 0
         create vertex 0 0 1
         create curve vertex 1 2

In the Cubit example, there is no notion that the command ``create vertex 0 0 0`` created a vertex
with ID 1 that can be passed into the ``create curve command``.
In formo, since all entities are objects, they are referred to via their variable names.
This leads to a great robustness of the script that produces the final model.

Putting Entities Together
-------------------------

The model can be build from bottom up.
Starting from points that are connected into edges, that are used to create wires, which are then
used to build face which can then be used to build solid shapes.

.. card:: Simple 3D shape

   .. code::

      pt1 = Point(0, 0, 0)
      pt2 = Point(1, 0, 0)
      pt3 = Point(0, 1, 0)
      triangle = Face(Polygon([pt1, pt2, pt3]))
      vec = Vector(0, 0, 1)
      solid = extrude(triangle, vec)


Using Modeling Primitives
-------------------------

Modeling primitives like ``Cylinder``, ``Box``, ``Sphere``, etc. are available to create solid objects quickly.
Those can then be combined together to create more complicated models.

.. card:: Combining Primitives

   .. code::

      origin = Point(0, 0, 0)
      z_vec = Direction(0, 0, 1)
      axis = Axis2(origin, z_vec)
      cyl = Cylinder(axis, 0.5, 2)

      sph_ctr = Point(0, 0, 2)
      sph = Sphere(sph_ctr, 0.5)

      solid = fuse(cyl, sph)


Running formo
--------------

You can create a standalone python file that can be executed in the usual manner:

.. card:: Python file

   ``example.py``:

   .. code::

      from formo import *

      <formo objects>

      write("prim.step", [<objects to export>])

   .. code::

      $ python example.py
