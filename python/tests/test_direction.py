import pytest
import formo
import math


def test_is_equal():
    dir = formo.Direction(1, 2, 3)
    assert(dir.is_equal(formo.Direction(1, 2, 3), 1e-14))
    assert(not dir.is_equal(formo.Direction(-1, -2, 3), 1e-14))


def test_is_normal():
    dir = formo.Direction(1, 0, 0);
    assert(dir.is_normal(formo.Direction(0, 1, 0), 1e-14))
    assert(not dir.is_normal(formo.Direction(-1, -2, -3), 1e-14))


def test_is_opposite():
    dir = formo.Direction(1, 2, 3);
    assert(dir.is_opposite(formo.Direction(-1, -2, -3), 1e-14))
    assert(not dir.is_normal(formo.Direction(0, 2, -3), 1e-14))


def test_is_parallel():
    dir = formo.Direction(1, 2, 3);
    assert(dir.is_parallel(formo.Direction(-1, -2, -3), 1e-14))
    assert(not dir.is_parallel(formo.Direction(0, 2, -3), 1e-14))


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


def test_dot_product():
    dot = formo.dot_product(formo.Direction(1, 2, 3), formo.Direction(-2, 3, 5))
    assert(math.isclose(dot, 0.82375447104791411, abs_tol=1e-15))


def test_cross_product():
    cp = formo.cross_product(formo.Direction(1, 0, 0), formo.Direction(0, 1, 0))
    assert(math.isclose(cp.x, 0., abs_tol=1e-15))
    assert(math.isclose(cp.y, 0., abs_tol=1e-15))
    assert(math.isclose(cp.z, 1., abs_tol=1e-15))


def test_scale_op():
    vec = 12.34 * formo.Direction(1, 0, 0)
    assert(math.isclose(vec.x, 12.34, abs_tol=1e-15))
    assert(math.isclose(vec.y, 0., abs_tol=1e-15))
    assert(math.isclose(vec.z, 0., abs_tol=1e-15))
