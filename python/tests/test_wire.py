import pytest
import formo
import math


def test_length():
    pt1 = formo.Point(0, 0, 0)
    pt2 = formo.Point(1, 0, 0)
    pt3 = formo.Point(1, 1, 0)
    ln1 = formo.Line(pt1, pt2)
    ln2 = formo.Line(pt2, pt3)
    wire = formo.Wire([ ln1, ln2 ])
    assert(math.isclose(wire.length(), 2., rel_tol=1e-14))
