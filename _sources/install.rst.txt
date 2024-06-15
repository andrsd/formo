Installation
============

Requirements:

* C++17 compiler (tested with gcc and clang)
* OpenCASCADE (>=7.6.0)
* fmt (>=9.0)
* pybind (>=2.11)


.. tab-set::

   .. tab-item:: conda

      1. Add the following channels:

         .. code::

            $ conda config --add channels conda-forge
            $ conda config --add channels andrsd

      2. Install

         .. code::

            $ conda install -c andrsd formo

   .. tab-item:: from sources

      1. Clone the repo:

         .. code::

            $ cd /some/path
            $ git clone https://github.com/andrsd/formo.git

      2. Build the code

         .. code::

            $ cd formo
            $ mkdir build
            $ cmake -S . -B build
            $ cmake --build build
