// SPDX-FileCopyrightText: 2024 David Andrs <andrsd@gmail.com>
// SPDX-License-Identifier: MIT

#include "formo/helix.h"
#include "formo/vector.h"
#include "formo/axis1.h"
#include "formo/axis2.h"
#include "formo/exception.h"
#include "TColgp_HArray1OfPnt.hxx"
#include "GeomAPI_PointsToBSpline.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include <gp_Pnt.hxx>

namespace formo {

// NOTE: 4 was not enough to get circular shape
const int N_SEGS_PER_TURN = 8;

Helix::Helix(const Axis2 & ax2, double radius, double height, double turns, double start_angle) :
    Edge()
{
    auto ax1 = ax2.axis();
    auto n_pts = turns * N_SEGS_PER_TURN;
    auto dh = height / turns / N_SEGS_PER_TURN;
    auto dangle = 2 * M_PI / N_SEGS_PER_TURN;
    auto axial_dir = ax2.direction();

    // partial translate transformation
    gp_Trsf translate;
    translate.SetTranslation(dh * axial_dir);
    // partial rotate transformation
    gp_Trsf rotate;
    rotate.SetRotation(ax1, dangle);

    gp_Pnt pt = ax1.location();
    pt.Translate(radius * ax2.x_direction());
    TColgp_HArray1OfPnt pnts(0, n_pts);
    for (int idx = 0; idx < n_pts; idx++) {
        pnts.SetValue(idx, pt);
        pt.Transform(translate);
        pt.Transform(rotate);
    }
    pnts.SetValue(n_pts, pt);

    GeomAPI_PointsToBSpline mk(pnts, 3, 3, GeomAbs_C2);
    if (!mk.IsDone())
        throw Exception("Spline was not created");
    BRepBuilderAPI_MakeEdge make_edge(mk.Curve());
    make_edge.Build();
    if (!make_edge.IsDone())
        throw Exception("Edge was not created");
    set_shape(make_edge.Shape());
    set_edge(make_edge.Edge());
    this->spline_ = mk.Curve();
}

} // namespace formo
