import pytest
import formo
import math


def test_draft():
    box = formo.Box(formo.Point(0, 0, 0), formo.Point(1, 2, 3))
    faces = []
    for f in box.faces():
        pln = f.plane()
        n = pln.axis().direction();
        if math.fabs(n.z) < 1e-14:
            faces.append(f)

    neutral_plane = formo.Plane(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    shape = formo.draft(box, neutral_plane, faces, math.radians(3))


def test_hole():
    box = formo.Box(formo.Point(0, 0, 0), formo.Point(1, 1, 1))
    ax1 = formo.Axis1(formo.Point(1.5, 0.5, 0.25), formo.Direction(-1, 0, 0))
    shape = formo.hole(box, ax1, 0.2)


def test_hole_blind():
    box = formo.Box(formo.Point(0, 0, 0), formo.Point(1, 1, 1))
    ax1 = formo.Axis1(formo.Point(0, 0.5, 0.25), formo.Direction(1, 0, 0))
    shape = formo.hole(box, ax1, 0.2, 0.5)


def test_sweep():
    l1 = formo.Line(formo.Point(0, 0, 0), formo.Point(0, 1, 0));
    arc = formo.ArcOfCircle(formo.Point(0, 1, 0), formo.Vector(0, 1, 0), formo.Point(1, 2, 0));
    l2 = formo.Line(formo.Point(1, 2, 0), formo.Point(2, 2, 0));
    path = formo.Wire([ l1, arc, l2 ]);

    circ = formo.Circle(formo.Axis2(formo.Point(0, 0, 0), formo.Direction(0, 1, 0)), 0.1);
    profile = formo.Face(formo.Wire([ circ ]));

    shape = formo.sweep(profile, path);


def test_rotate_shape():
    box = formo.Box(formo.Point(0, 0, 0), formo.Point(1, 1, 1))
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    box = formo.rotate(box, ax1, 45)
