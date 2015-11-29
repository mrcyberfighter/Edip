=====
Files
=====

----------------------------
Supported image file formats
----------------------------

  ``Edip`` support :ref:`normally <always-supported-filetypes>` following images files formats to load into the program for processing:

    + **bmp**, **dib** (*bitmap image file.*)

    + **jpg**, **jpeg**, **jpe** (*Join photographic Expert Group.*)

    + **png** (*Protable Network Graphics.*)

    + **tiff**, **tif** (*Tag(ged) Image File (Format).*)

    + **ras**, **sr** (*Sun Raster*).

    + **pbm**, **pgm**, **ppm** (*Portable Image Format.*)

    + **webp**.

  The image file is loaded into the program and converted into **RGB**, (internally **BGR**) format or **RGBA** (internally **BGRA**) if an alpha channel is available in the image.

  .. _always-supported-filetypes:

  .. note::

    For supporting an image filetype the required library need to be installed except for:

      + **bmp**, **dib** (*bitmap image file.*)
  
      + **pbm**, **pgm**, **ppm** (*Portable Image Format.*)
  
      + **ras**, **sr** (*Sun Raster*).
  
    Which are always supported.

-----------------
Load images files
-----------------  

  You can load an image file to process it into ``Edip`` by clicking on the :guilabel:`Open` button in the buttonbar,

  through the menu item :menuselection:`Files --> Open file` or by hitting the shortcut :kbd:`Ctrl + O`.

  You can start the program with am image file path as argument:

  .. code-block:: bash

    $ edip image_filepath

  You can open an recent image file by using the menu item :menuselection:`Files --> Recent files`.


.. note:

  By loading an image file ``Edip`` will work on a copy of the image datas, so don't alter the image file directly.

  And display the image resized, if needed, to the user.

------------------
Saving image files
------------------

  You can save an image file by pressing the button :guilabel:`Save` in the button bar,

  trough the menu item :menuselection:`Files --> Save file` or by hitting the shortcut :kbd:`Ctrl + S`.

  Then you can set the output size of the image which default to the originally image size.

  And setting some options in relatinship to the format if available.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Image file format saving options
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+++++++++++++++++++++++++++++
png image file saving options
+++++++++++++++++++++++++++++

  + **Compression**: from level from 0 to 9. A higher value means a smaller size and longer compression time. Default value is 3.

  + **Strategy**:

    - Default.

    - Filtered.

    - Huffman only.

    - RLE.

    - Fixed.

  + **Bilevel**:

    You can only store an image as bilevel if the image is a :ref:`binary <binary-images>` (black and white) image.

    Otherwise the result will be undefined.

++++++++++++++++++++++++++++++
jpeg image file saving options
++++++++++++++++++++++++++++++

  + **Quality**: it can be a quality from 0 to 100 (the higher is the better). Default value is 95.

  + **Features**:

    - **Progressiv** (disabled per default).

    - **Optimize** (disabled per default).

  + **RST Restart**: JPEG restart interval, 0 - 65535, default is 0 - no restart.

  + **LUMA quality**: Separate luma quality level, 0 - 100, default is 0 - don't use.

  + **CHROMA quality**: Separate chroma quality level, 0 - 100, default is 0 - don't use.

+++++++++++++++++++++++++++++
xpm image file saving options
+++++++++++++++++++++++++++++

  + **Binary**: For PPM, PGM, or PBM, it can be a binary format flag, 0 or 1. Default value is 1.

++++++++++++++++++++++++++++++
webp image file saving options
++++++++++++++++++++++++++++++

  + **Quality**: For WEBP, it can be a quality from 1 to 100 (the higher is the better). By default and for quality above 100 the lossless compression is used.


                      