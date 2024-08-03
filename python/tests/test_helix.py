import pytest
import formo
import math

def test_helix():
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    helix = formo.Helix(ax2, 2., 6, 4)
