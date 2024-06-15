from formo import *

HEIGHT = 50
WIDTH = 70
THICKNESS = 30

pt1 = Point(-WIDTH / 2., 0, 0)
pt2 = Point(-WIDTH / 2., -THICKNESS / 4., 0)
pt3 = Point(0, -THICKNESS / 2., 0)
pt4 = Point(WIDTH / 2., -THICKNESS / 4., 0)
pt5 = Point(WIDTH / 2., 0, 0)

arc = ArcOfCircle(pt2, pt3, pt4)
segment1 = Line(pt1, pt2)
segment2 = Line(pt4, pt5)

wire = Wire([segment1, arc, segment2])

x_axis = Geometry.OX()
mirrored_wire = mirror(wire, x_axis)

wire_profile = Wire([wire, mirrored_wire])

face_profile = Face(wire_profile)

prism_vec = Vector(0, 0, HEIGHT)
body = extrude(face_profile, prism_vec)

edges = body.edges()
body = fillet(body, edges, THICKNESS / 12.0)

neck_location = Point(0, 0, HEIGHT)
neck_axis = Geometry.DZ()
neck_ax2 = Axis2(neck_location, neck_axis)

neck_radius = THICKNESS / 4.
neck_height = HEIGHT / 10
neck = Cylinder(neck_ax2, neck_radius, neck_height)

body = fuse(body, neck)

z_max = -1.
top_face = None
for face in body.faces():
    if face.is_plane():
        plane = face.plane()
        if plane.location.z > z_max:
            z_max = plane.location.z
            top_face = face
body = hollow(body, [top_face], -THICKNESS / 50, 1e-3)

write("bottle.step", [body])
