Export
======

Currently models can be exported into 2 file formats:

- STEP
- IGES

Exporting is done by ``write`` function:

.. card:: Export into a file

   .. code::

      write(<file_name>, <list of objects>, [file_format])

   The ``file_format`` parameter is optional and its default value is ``step``.
