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
    shape = formo.draft(box, neutral_plane, faces, math.radians(3));
