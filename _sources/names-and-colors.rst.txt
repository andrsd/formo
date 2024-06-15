Names and Colors
================

With more complicated geometries, it is desired to be able to name individual parts of the model.
This can be achieved via ``set_name`` method.

.. card:: Naming a shape

   .. code::

      pt1 = Point(0, 0, 0)
      pt2 = Point(1, 0, 0)
      pt3 = Point(0, 1, 0)
      triangle = Face(Polygon([pt1, pt2, pt3]).wire())
      vec = Vector(0, 0, 1)
      solid = extrude(triangle, vec)
      solid.set_name('triangle')

To help users to understand the model, color can be assigned to individual parts of the model.

.. card:: Assign a color

   .. code::

      solid.set_color(colors.light_blue)

The following colors are available in formo:

.. card::

   .. raw:: html

      <svg width="1000" height="310">
         <style>
            .small {
               font: 13px sans-serif;
               alignment-baseline: middle;
            }
         </style>
         <rect x="00" y="00" width="20" height="20" style="fill:rgb(0, 0, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="25" y="10" class="small">black</text>
         <rect x="00" y="20" width="20" height="20" style="fill:rgb(19, 0, 255);stroke-width:2;stroke:#fff"></rect>
         <text x="25" y="30" class="small">blue</text>
         <rect x="00" y="40" width="20" height="20" style="fill:rgb(254, 0, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="25" y="50" class="small">red</text>

         <rect x="100" y="00" width="20" height="20" style="fill:rgb(156, 207, 237);stroke-width:2;stroke:#fff"></rect>
         <text x="125" y="10" class="small">medium_blue</text>
         <rect x="100" y="20" width="20" height="20" style="fill:rgb(165, 165, 165);stroke-width:2;stroke:#fff"></rect>
         <text x="125" y="30" class="small">medium_grey</text>

         <rect x="230" y="00" width="20" height="20" style="fill:rgb(60, 97, 180);stroke-width:2;stroke:#fff"></rect>
         <text x="255" y="10" class="small">dark_blue</text>
         <rect x="230" y="20" width="20" height="20" style="fill:rgb(234, 234, 234);stroke-width:2;stroke:#fff"></rect>
         <text x="255" y="30" class="small">light_grey</text>

         <rect x="360" y="00" width="20" height="20" style="fill:rgb(197, 226, 243);stroke-width:2;stroke:#fff"></rect>
         <text x="385" y="10" class="small">light_blue</text>
         <rect x="360" y="20" width="20" height="20" style="fill:rgb(247, 135, 3);stroke-width:2;stroke:#fff"></rect>
         <text x="385" y="30" class="small">orange</text>

         <rect x="490" y="00" width="20" height="20" style="fill:rgb(127, 127, 127);stroke-width:2;stroke:#fff"></rect>
         <text x="515" y="10" class="small">dark_grey</text>
         <rect x="490" y="20" width="20" height="20" style="fill:rgb(250, 182, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="515" y="30" class="small">yellow</text>


         <rect x="0" y="80" width="20" height="20" style="fill:rgb(229, 229, 229);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="80" width="20" height="20" style="fill:rgb(204, 204, 204);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="80" width="20" height="20" style="fill:rgb(178, 178, 178);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="80" width="20" height="20" style="fill:rgb(153, 153, 153);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="80" width="20" height="20" style="fill:rgb(127, 127, 127);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="80" width="20" height="20" style="fill:rgb(102, 102, 102);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="80" width="20" height="20" style="fill:rgb(76, 76, 76);stroke-width:2;stroke:#fff"></rect>
         <text x="25" y="90" class="small">grey1</text>
         <text x="105" y="90" class="small">grey2</text>
         <text x="185" y="90" class="small">grey3</text>
         <text x="265" y="90" class="small">grey4</text>
         <text x="345" y="90" class="small">grey5</text>
         <text x="425" y="90" class="small">grey6</text>
         <text x="505" y="90" class="small">grey7</text>

         <rect x="0" y="100" width="20" height="20" style="fill:rgb(229, 223, 207);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="100" width="20" height="20" style="fill:rgb(204, 199, 184);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="100" width="20" height="20" style="fill:rgb(178, 173, 161);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="100" width="20" height="20" style="fill:rgb(153, 149, 138);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="100" width="20" height="20" style="fill:rgb(127, 124, 115);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="100" width="20" height="20" style="fill:rgb(102, 99, 92);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="100" width="20" height="20" style="fill:rgb(76, 74, 69);stroke-width:2;stroke:#fff"></rect>
         <text x="25" y="110" class="small">gold1</text>
         <text x="105" y="110" class="small">gold2</text>
         <text x="185" y="110" class="small">gold3</text>
         <text x="265" y="110" class="small">gold4</text>
         <text x="345" y="110" class="small">gold5</text>
         <text x="425" y="110" class="small">gold6</text>
         <text x="505" y="110" class="small">gold7</text>

         <rect x="0" y="120" width="20" height="20" style="fill:rgb(207, 219, 229);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="120" width="20" height="20" style="fill:rgb(184, 195, 204);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="120" width="20" height="20" style="fill:rgb(161, 170, 178);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="120" width="20" height="20" style="fill:rgb(138, 146, 153);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="120" width="20" height="20" style="fill:rgb(115, 121, 127);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="120" width="20" height="20" style="fill:rgb(92, 98, 102);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="120" width="20" height="20" style="fill:rgb(69, 73, 76);stroke-width:2;stroke:#fff"></rect>
         <text x="25" y="130" class="small">silver1</text>
         <text x="105" y="130" class="small">silver2</text>
         <text x="185" y="130" class="small">silver3</text>
         <text x="265" y="130" class="small">silver4</text>
         <text x="345" y="130" class="small">silver5</text>
         <text x="425" y="130" class="small">silver6</text>
         <text x="505" y="130" class="small">silver7</text>

         <rect x="0" y="150" width="20" height="20" style="fill:rgb(229, 190, 179);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="150" width="20" height="20" style="fill:rgb(224, 153, 132);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="150" width="20" height="20" style="fill:rgb(224, 115, 82);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="150" width="20" height="20" style="fill:rgb(220, 78, 34);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="150" width="20" height="20" style="fill:rgb(178, 61, 26);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="150" width="20" height="20" style="fill:rgb(140, 42, 12);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="150" width="20" height="20" style="fill:rgb(102, 24, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="160" class="small">red1</text>
         <text x="105" y="160" class="small">red2</text>
         <text x="185" y="160" class="small">red3</text>
         <text x="265" y="160" class="small">red4</text>
         <text x="345" y="160" class="small">red5</text>
         <text x="425" y="160" class="small">red6</text>
         <text x="505" y="160" class="small">red7</text>

         <rect x="0" y="170" width="20" height="20" style="fill:rgb(229, 206, 179);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="170" width="20" height="20" style="fill:rgb(224, 181, 132);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="170" width="20" height="20" style="fill:rgb(224, 158, 82);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="170" width="20" height="20" style="fill:rgb(220, 133, 34);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="170" width="20" height="20" style="fill:rgb(178, 107, 26);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="170" width="20" height="20" style="fill:rgb(140, 80, 12);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="170" width="20" height="20" style="fill:rgb(102, 54, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="180" class="small">orange1</text>
         <text x="105" y="180" class="small">orange2</text>
         <text x="185" y="180" class="small">orange3</text>
         <text x="265" y="180" class="small">orange4</text>
         <text x="345" y="180" class="small">orange5</text>
         <text x="425" y="180" class="small">orange6</text>
         <text x="505" y="180" class="small">orange7</text>

         <rect x="0" y="190" width="20" height="20" style="fill:rgb(229, 216, 179);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="190" width="20" height="20" style="fill:rgb(224, 200, 132);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="190" width="20" height="20" style="fill:rgb(224, 186, 82);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="190" width="20" height="20" style="fill:rgb(220, 170, 34);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="190" width="20" height="20" style="fill:rgb(178, 138, 26);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="190" width="20" height="20" style="fill:rgb(140, 106, 12);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="190" width="20" height="20" style="fill:rgb(102, 75, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="200" class="small">yellow1</text>
         <text x="105" y="200" class="small">yellow2</text>
         <text x="185" y="200" class="small">yellow3</text>
         <text x="265" y="200" class="small">yellow4</text>
         <text x="345" y="200" class="small">yellow5</text>
         <text x="425" y="200" class="small">yellow6</text>
         <text x="505" y="200" class="small">yellow7</text>

         <rect x="0" y="210" width="20" height="20" style="fill:rgb(196, 229, 179);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="210" width="20" height="20" style="fill:rgb(163, 224, 132);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="210" width="20" height="20" style="fill:rgb(129, 224, 82);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="210" width="20" height="20" style="fill:rgb(96, 220, 34);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="210" width="20" height="20" style="fill:rgb(77, 178, 26);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="210" width="20" height="20" style="fill:rgb(55, 140, 12);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="210" width="20" height="20" style="fill:rgb(34, 102, 0);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="220" class="small">green1</text>
         <text x="105" y="220" class="small">green2</text>
         <text x="185" y="220" class="small">green3</text>
         <text x="265" y="220" class="small">green4</text>
         <text x="345" y="220" class="small">green5</text>
         <text x="425" y="220" class="small">green6</text>
         <text x="505" y="220" class="small">green7</text>

         <rect x="0" y="230" width="20" height="20" style="fill:rgb(179, 229, 225);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="230" width="20" height="20" style="fill:rgb(132, 224, 216);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="230" width="20" height="20" style="fill:rgb(82, 224, 212);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="230" width="20" height="20" style="fill:rgb(34, 220, 204);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="230" width="20" height="20" style="fill:rgb(26, 178, 166);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="230" width="20" height="20" style="fill:rgb(12, 140, 129);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="230" width="20" height="20" style="fill:rgb(0, 102, 93);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="240" class="small">teal1</text>
         <text x="105" y="240" class="small">teal2</text>
         <text x="185" y="240" class="small">teal3</text>
         <text x="265" y="240" class="small">teal4</text>
         <text x="345" y="240" class="small">teal5</text>
         <text x="425" y="240" class="small">teal6</text>
         <text x="505" y="240" class="small">teal7</text>

         <rect x="0" y="250" width="20" height="20" style="fill:rgb(179, 201, 229);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="250" width="20" height="20" style="fill:rgb(132, 172, 224);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="250" width="20" height="20" style="fill:rgb(82, 144, 224);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="250" width="20" height="20" style="fill:rgb(34, 115, 220);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="250" width="20" height="20" style="fill:rgb(26, 92, 178);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="250" width="20" height="20" style="fill:rgb(12, 67, 140);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="250" width="20" height="20" style="fill:rgb(0, 44, 102);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="260" class="small">blue1</text>
         <text x="105" y="260" class="small">blue2</text>
         <text x="185" y="260" class="small">blue3</text>
         <text x="265" y="260" class="small">blue4</text>
         <text x="345" y="260" class="small">blue5</text>
         <text x="425" y="260" class="small">blue6</text>
         <text x="505" y="260" class="small">blue7</text>

         <rect x="0" y="270" width="20" height="20" style="fill:rgb(196, 179, 229);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="270" width="20" height="20" style="fill:rgb(164, 132, 224);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="270" width="20" height="20" style="fill:rgb(132, 82, 224);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="270" width="20" height="20" style="fill:rgb(99, 34, 220);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="270" width="20" height="20" style="fill:rgb(79, 26, 178);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="270" width="20" height="20" style="fill:rgb(57, 12, 140);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="270" width="20" height="20" style="fill:rgb(36, 0, 102);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="280" class="small">violet1</text>
         <text x="105" y="280" class="small">violet2</text>
         <text x="185" y="280" class="small">violet3</text>
         <text x="265" y="280" class="small">violet4</text>
         <text x="345" y="280" class="small">violet5</text>
         <text x="425" y="280" class="small">violet6</text>
         <text x="505" y="280" class="small">violet7</text>

         <rect x="0" y="290" width="20" height="20" style="fill:rgb(222, 179, 229);stroke-width:2;stroke:#fff"></rect>
         <rect x="80" y="290" width="20" height="20" style="fill:rgb(210, 132, 224);stroke-width:2;stroke:#fff"></rect>
         <rect x="160" y="290" width="20" height="20" style="fill:rgb(203, 82, 224);stroke-width:2;stroke:#fff"></rect>
         <rect x="240" y="290" width="20" height="20" style="fill:rgb(192, 34, 220);stroke-width:2;stroke:#fff"></rect>
         <rect x="320" y="290" width="20" height="20" style="fill:rgb(155, 26, 178);stroke-width:2;stroke:#fff"></rect>
         <rect x="400" y="290" width="20" height="20" style="fill:rgb(121, 12, 140);stroke-width:2;stroke:#fff"></rect>
         <rect x="480" y="290" width="20" height="20" style="fill:rgb(87, 0, 102);stroke-width:2;stroke:#fff"></rect>
         <text x="025" y="300" class="small">purple1</text>
         <text x="105" y="300" class="small">purple2</text>
         <text x="185" y="300" class="small">purple3</text>
         <text x="265" y="300" class="small">purple4</text>
         <text x="345" y="300" class="small">purple5</text>
         <text x="425" y="300" class="small">purple6</text>
         <text x="505" y="300" class="small">purple7</text>
      </svg>
