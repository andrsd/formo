Operations
==========

.. doxygenfunction:: formo::translate(const Shape &, const Vector &)

.. doxygenfunction:: formo::translate(const Shape &, const Point &, const Point &)

.. doxygenfunction:: formo::scale(const Shape &, double)

.. doxygenfunction:: formo::scale(const Vector &, double)

.. doxygenfunction:: formo::mirror(const Shape &, const Axis1 &)

.. doxygenfunction:: formo::mirror(const Vector &, const Axis1 &)

.. doxygenfunction:: formo::mirror(const Vector &, const Axis2 &)

.. doxygenfunction:: formo::mirror(const Point &, const Axis1 &)

.. doxygenfunction:: formo::mirror(const Point &, const Axis2 &)

.. doxygenfunction:: formo::fuse(const Shape &, const Shape &)

.. doxygenfunction:: formo::cut(const Shape &, const Shape &)

.. doxygenfunction:: formo::intersect(const Shape &, const Shape &)

.. doxygenfunction:: fillet(const Shape &, const std::vector<Edge> &, double)

.. doxygenfunction:: hollow(const Shape &, const std::vector<Face> &, double, double)

.. doxygenfunction:: extrude(const Shape &, const Vector &)

.. doxygenfunction:: revolve(const Shape &, const Axis1 &, double)

.. doxygenfunction:: rotate(const Point &, const Axis1 &, double)

.. doxygenfunction:: rotate(const Vector &, const Axis1 &, double)

.. doxygenfunction:: rotate(const Shape &, const Axis1 &, double)

.. doxygenfunction:: section(const Shape &, const Plane &)

.. doxygenfunction:: draft(const Shape &, const Plane &, const std::vector<Face> &, double)

.. doxygenfunction:: hole(const Shape &, const Axis1 &, double)

.. doxygenfunction:: hole(const Shape &, const Axis1 &, double, double)

.. doxygenfunction:: sweep(const Shape &, const Wire &)
