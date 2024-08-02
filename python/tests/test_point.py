import pytest
import formo
import math

def test_point():
    a = formo.Point(1, 2, 3)
    assert(math.isclose(a.x, 1, abs_tol=1e-10))
    assert(math.isclose(a.y, 2, abs_tol=1e-10))
    assert(math.isclose(a.z, 3, abs_tol=1e-10))


def test_is_equal():
    a = formo.Point(1, 2, 3)
    b = formo.Point(1, 2, 3)
    assert(a.is_equal(b, 1e-14))


def test_distance():
    a = formo.Point(1, 2, 3)
    b = formo.Point(4, 2, 7)
    assert(math.isclose(a.distance(b), 5., abs_tol=1e-14))


def test_rotate():
    pt = formo.Point(1, 0, 2)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    pt.rotate(ax1, math.pi / 2.)
    assert(math.isclose(pt.x, 0, abs_tol=1e-15))
    assert(math.isclose(pt.y, 1, abs_tol=1e-15))
    assert(math.isclose(pt.z, 2, abs_tol=1e-15))


def test_rotated():
    pt = formo.Point(1, 0, 2)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    npt = pt.rotated(ax1, math.pi / 2.)
    assert(math.isclose(npt.x, 0, abs_tol=1e-15))
    assert(math.isclose(npt.y, 1, abs_tol=1e-15))
    assert(math.isclose(npt.z, 2, abs_tol=1e-15))


def test_scale():
    pt = formo.Point(1, 0, 2)
    pt.scale(formo.Point(0, 0, 0), 2);
    assert(math.isclose(pt.x, 2, abs_tol=1e-15))
    assert(math.isclose(pt.y, 0, abs_tol=1e-15))
    assert(math.isclose(pt.z, 4, abs_tol=1e-15))


def test_scaled():
    pt = formo.Point(1, 0, 2)
    npt = pt.scaled(formo.Point(0, 0, 0), 2);
    assert(math.isclose(npt.x, 2, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, 4, abs_tol=1e-15))


def test_translate():
    pt = formo.Point(1, 0, 2)
    pt.translate(formo.Vector(1, -1, 2));
    assert(math.isclose(pt.x, 2, abs_tol=1e-15))
    assert(math.isclose(pt.y, -1, abs_tol=1e-15))
    assert(math.isclose(pt.z, 4, abs_tol=1e-15))


def test_translate_2pts():
    pt = formo.Point(1, 0, 2)
    pt.translate(formo.Point(0, 0, 0), formo.Point(1, -1, 2))
    assert(math.isclose(pt.x, 2, abs_tol=1e-15))
    assert(math.isclose(pt.y, -1, abs_tol=1e-15))
    assert(math.isclose(pt.z, 4, abs_tol=1e-15))


def test_translated():
    pt = formo.Point(1, 0, 2)
    npt = pt.translated(formo.Vector(1, -1, 2))
    assert(math.isclose(npt.x, 2, abs_tol=1e-15))
    assert(math.isclose(npt.y, -1, abs_tol=1e-15))
    assert(math.isclose(npt.z, 4, abs_tol=1e-15))


def test_translated_2pts():
    pt = formo.Point(1, 0, 2)
    npt = pt.translated(formo.Point(0, 0, 0), formo.Point(1, -1, 2))
    assert(math.isclose(npt.x, 2, abs_tol=1e-15))
    assert(math.isclose(npt.y, -1, abs_tol=1e-15))
    assert(math.isclose(npt.z, 4, abs_tol=1e-15))


def test_mirror_pt():
    pt = formo.Point(1, 0, -2)
    symm = formo.Point(0, 0, 0)
    pt.mirror(symm)
    assert(math.isclose(pt.x, -1, abs_tol=1e-15))
    assert(math.isclose(pt.y, 0, abs_tol=1e-15))
    assert(math.isclose(pt.z, 2, abs_tol=1e-15))


def test_mirror_ax1():
    pt = formo.Point(1, 0, -2)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 1, 0))
    pt.mirror(ax1)
    assert(math.isclose(pt.x, -1, abs_tol=1e-15))
    assert(math.isclose(pt.y, 0, abs_tol=1e-15))
    assert(math.isclose(pt.z, 2, abs_tol=1e-15))


def test_mirror_ax2():
    pt = formo.Point(1, 0, -2)
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(1, 0, 0))
    pt.mirror(ax2)
    assert(math.isclose(pt.x, -1, abs_tol=1e-15))
    assert(math.isclose(pt.y, 0, abs_tol=1e-15))
    assert(math.isclose(pt.z, -2, abs_tol=1e-15))


def test_mirrored_pt():
    pt = formo.Point(1, 0, -2)
    symm = formo.Point(0, 0, 0)
    npt = pt.mirrored(symm)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, 2, abs_tol=1e-15))


def test_mirrored_ax1():
    pt = formo.Point(1, 0, -2)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 1, 0))
    npt = pt.mirrored(ax1)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, 2, abs_tol=1e-15))


def test_mirrored_ax2():
    pt = formo.Point(1, 0, -2)
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(1, 0, 0))
    npt = pt.mirrored(ax2)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, -2, abs_tol=1e-15))


def test_add_point_point():
    a = formo.Point(1, 2, 3)
    b = formo.Point(-2, 1, 4)
    c = a + b
    assert(math.isclose(c.x, -1, abs_tol=1e-10))
    assert(math.isclose(c.y, 3, abs_tol=1e-10))
    assert(math.isclose(c.z, 7, abs_tol=1e-10))


def test_add_point_vec():
    a = formo.Point(1, 2, 3)
    b = formo.Vector(-2, 1, 4)
    c = a + b
    assert(math.isclose(c.x, -1, abs_tol=1e-10))
    assert(math.isclose(c.y, 3, abs_tol=1e-10))
    assert(math.isclose(c.z, 7, abs_tol=1e-10))
