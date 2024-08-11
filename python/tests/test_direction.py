import pytest
import formo
import math


def test_mirror_pt():
    dir = formo.Direction(1, 0, -2)
    symm = formo.Direction(0, 0, 1)
    dir.mirror(symm)
    sqrt5 = math.sqrt(5)
    assert(math.isclose(dir.x, -1. / sqrt5, abs_tol=1e-15))
    assert(math.isclose(dir.y, 0, abs_tol=1e-15))
    assert(math.isclose(dir.z, -2. / sqrt5, abs_tol=1e-15))


def test_mirror_ax1():
    dir = formo.Direction(1, 0, 0)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 1, 0))
    dir.mirror(ax1)
    assert(math.isclose(dir.x, -1, abs_tol=1e-15))
    assert(math.isclose(dir.y, 0, abs_tol=1e-15))
    assert(math.isclose(dir.z, 0, abs_tol=1e-15))


def test_mirror_ax2():
    dir = formo.Direction(1, 0, -2)
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(1, 0, 0))
    dir.mirror(ax2)
    sqrt5 = math.sqrt(5)
    assert(math.isclose(dir.x, -1. / sqrt5, abs_tol=1e-15))
    assert(math.isclose(dir.y, 0, abs_tol=1e-15))
    assert(math.isclose(dir.z, -2. / sqrt5, abs_tol=1e-15))


def test_mirrored_pt():
    dir = formo.Direction(1, 0, -2)
    symm = formo.Direction(0, 0, 1)
    npt = dir.mirrored(symm)
    sqrt5 = math.sqrt(5)
    assert(math.isclose(npt.x, -1. / sqrt5, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, -2. / sqrt5, abs_tol=1e-15))


def test_mirrored_ax1():
    dir = formo.Direction(1, 0, 0)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 1, 0))
    npt = dir.mirrored(ax1)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, 0, abs_tol=1e-15))


def test_mirrored_ax2():
    dir = formo.Direction(1, 0, -2)
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(1, 0, 0))
    npt = dir.mirrored(ax2)
    sqrt5 = math.sqrt(5)
    assert(math.isclose(npt.x, -1. / sqrt5, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, -2. / sqrt5, abs_tol=1e-15))


def test_rotate():
    dir = formo.Direction(1, 0, 0)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    dir.rotate(ax1, 0.5 * math.pi);
    assert(math.isclose(dir.x, 0, abs_tol=1e-15))
    assert(math.isclose(dir.y, 1, abs_tol=1e-15))
    assert(math.isclose(dir.z, 0, abs_tol=1e-15))


def test_rotated():
    dir = formo.Direction(1, 0, 0)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    r = dir.rotated(ax1, 0.5 * math.pi);
    assert(math.isclose(r.x, 0, abs_tol=1e-15))
    assert(math.isclose(r.y, 1, abs_tol=1e-15))
    assert(math.isclose(r.z, 0, abs_tol=1e-15))


def test_reverse():
    dir = formo.Direction(1, 0, 0)
    dir.reverse();
    assert(math.isclose(dir.x, -1, abs_tol=1e-15))
    assert(math.isclose(dir.y, 0, abs_tol=1e-15))
    assert(math.isclose(dir.z, 0, abs_tol=1e-15))


def test_reversed():
    dir = formo.Direction(1, 0, 0)
    rev = dir.reversed();
    assert(math.isclose(rev.x, -1, abs_tol=1e-15))
    assert(math.isclose(rev.y, 0, abs_tol=1e-15))
    assert(math.isclose(rev.z, 0, abs_tol=1e-15))


def test_invert():
    dir = formo.Direction(1, 0, 0)
    opos = -dir;
    assert(math.isclose(opos.x, -1, abs_tol=1e-15))
    assert(math.isclose(opos.y, 0, abs_tol=1e-15))
    assert(math.isclose(opos.z, 0, abs_tol=1e-15))
