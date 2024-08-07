import pytest
import formo
import math

def test_is_equal():
    a = formo.Vector(1, 2, 3)
    assert(a.is_equal(formo.Vector(1, 2, 3), 1e-14, 1e-14))
    assert(not a.is_equal(formo.Vector(-1, -2, 3), 1e-14, 1e-14))


def test_is_normal():
    vec = formo.Vector(1, 0, 0);
    assert(vec.is_normal(formo.Vector(0, 1, 0), 1e-14))
    assert(not vec.is_normal(formo.Vector(-1, -2, -3), 1e-14))


def test_is_opposite():
    vec = formo.Vector(1, 2, 3);
    assert(vec.is_opposite(formo.Vector(-1, -2, -3), 1e-14))
    assert(not vec.is_normal(formo.Vector(0, 2, -3), 1e-14))


def test_is_parallel():
    vec = formo.Vector(1, 2, 3);
    assert(vec.is_parallel(formo.Vector(-1, -2, -3), 1e-14))
    assert(not vec.is_parallel(formo.Vector(0, 2, -3), 1e-14))


def test_magnitude():
    a = formo.Vector(3, 0, 4);
    assert(math.isclose(a.magnitude(), 5., abs_tol=1e-14))


def test_mirror_pt():
    vec = formo.Vector(1, 0, -2)
    symm = formo.Vector(0, 0, 1)
    vec.mirror(symm)
    assert(math.isclose(vec.x, -1, abs_tol=1e-15))
    assert(math.isclose(vec.y, 0, abs_tol=1e-15))
    assert(math.isclose(vec.z, -2, abs_tol=1e-15))


def test_mirror_ax1():
    vec = formo.Vector(1, 0, -2)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 1, 0))
    vec.mirror(ax1)
    assert(math.isclose(vec.x, -1, abs_tol=1e-15))
    assert(math.isclose(vec.y, 0, abs_tol=1e-15))
    assert(math.isclose(vec.z, 2, abs_tol=1e-15))


def test_mirror_ax2():
    vec = formo.Vector(1, 0, -2)
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(1, 0, 0))
    vec.mirror(ax2)
    assert(math.isclose(vec.x, -1, abs_tol=1e-15))
    assert(math.isclose(vec.y, 0, abs_tol=1e-15))
    assert(math.isclose(vec.z, -2, abs_tol=1e-15))


def test_mirrored_pt():
    vec = formo.Vector(1, 0, -2)
    symm = formo.Vector(0, 0, 1)
    npt = vec.mirrored(symm)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, -2, abs_tol=1e-15))


def test_mirrored_ax1():
    vec = formo.Vector(1, 0, -2)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 1, 0))
    npt = vec.mirrored(ax1)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, 2, abs_tol=1e-15))


def test_mirrored_ax2():
    pt = formo.Vector(1, 0, -2)
    ax2 = formo.Axis2(formo.Point(0, 0, 0), formo.Direction(1, 0, 0))
    npt = pt.mirrored(ax2)
    assert(math.isclose(npt.x, -1, abs_tol=1e-15))
    assert(math.isclose(npt.y, 0, abs_tol=1e-15))
    assert(math.isclose(npt.z, -2, abs_tol=1e-15))


def test_rotate():
    vec = formo.Vector(1, 0, 0)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    vec.rotate(ax1, 0.5 * math.pi);
    assert(math.isclose(vec.x, 0, abs_tol=1e-15))
    assert(math.isclose(vec.y, 1, abs_tol=1e-15))
    assert(math.isclose(vec.z, 0, abs_tol=1e-15))


def test_rotated():
    vec = formo.Vector(1, 0, 0)
    ax1 = formo.Axis1(formo.Point(0, 0, 0), formo.Direction(0, 0, 1))
    r = vec.rotated(ax1, 0.5 * math.pi);
    assert(math.isclose(r.x, 0, abs_tol=1e-15))
    assert(math.isclose(r.y, 1, abs_tol=1e-15))
    assert(math.isclose(r.z, 0, abs_tol=1e-15))


def test_scale():
    vec = formo.Vector(1, 2, 3)
    vec.scale(2.5)
    assert(math.isclose(vec.x, 2.5, abs_tol=1e-15))
    assert(math.isclose(vec.y, 5.0, abs_tol=1e-15))
    assert(math.isclose(vec.z, 7.5, abs_tol=1e-15))


def test_scaled():
    vec = formo.Vector(1, 2, 3)
    nvec = vec.scaled(2.5)
    assert(math.isclose(nvec.x, 2.5, abs_tol=1e-15))
    assert(math.isclose(nvec.y, 5.0, abs_tol=1e-15))
    assert(math.isclose(nvec.z, 7.5, abs_tol=1e-15))


def test_op_add():
    vec = formo.Vector(1, 2, 3) + formo.Vector(2, -3, 1)
    assert(math.isclose(vec.x, 3., abs_tol=1e-15))
    assert(math.isclose(vec.y, -1., abs_tol=1e-15))
    assert(math.isclose(vec.z, 4., abs_tol=1e-15))


def test_op_sub():
    vec = formo.Vector(1, 2, 3) - formo.Vector(2, -3, 1)
    assert(math.isclose(vec.x, -1., abs_tol=1e-15))
    assert(math.isclose(vec.y, 5., abs_tol=1e-15))
    assert(math.isclose(vec.z, 2., abs_tol=1e-15))


def test_op_mult_scalar():
    vec = 1.5 * formo.Vector(1, 2, 3)
    assert(math.isclose(vec.x, 1.5, abs_tol=1e-15))
    assert(math.isclose(vec.y, 3., abs_tol=1e-15))
    assert(math.isclose(vec.z, 4.5, abs_tol=1e-15))


def test_op_mult_scalar_post():
    vec = formo.Vector(1, 2, 3) * 1.5
    assert(math.isclose(vec.x, 1.5, abs_tol=1e-15))
    assert(math.isclose(vec.y, 3., abs_tol=1e-15))
    assert(math.isclose(vec.z, 4.5, abs_tol=1e-15))


def test_dot_product():
    dot = formo.dot_product(formo.Vector(1, 2, 3), formo.Vector(-2, 3, 5))
    assert(math.isclose(dot, 19, abs_tol=1e-15))


def test_cross_product():
    cp = formo.cross_product(formo.Vector(1, 0, 0), formo.Vector(0, 1, 0))
    assert(math.isclose(cp.x, 0., abs_tol=1e-15))
    assert(math.isclose(cp.y, 0., abs_tol=1e-15))
    assert(math.isclose(cp.z, 1., abs_tol=1e-15))


def test_normalize():
    vec = formo.Vector(1, 2, 3)
    vec.normalize();
    assert(math.isclose(vec.magnitude(), 1., abs_tol=1e-15))
    assert(math.isclose(vec.x, 1. / math.sqrt(14), abs_tol=1e-15))
    assert(math.isclose(vec.y, 2. / math.sqrt(14), abs_tol=1e-15))
    assert(math.isclose(vec.z, 3. / math.sqrt(14), abs_tol=1e-15))


def test_normalized():
    vec = formo.Vector(1, 2, 3)
    n = vec.normalized();
    assert(math.isclose(n.magnitude(), 1., abs_tol=1e-15))
    assert(math.isclose(n.x, 1. / math.sqrt(14), abs_tol=1e-15))
    assert(math.isclose(n.y, 2. / math.sqrt(14), abs_tol=1e-15))
    assert(math.isclose(n.z, 3. / math.sqrt(14), abs_tol=1e-15))
