==============
Simple Filters
==============

---------------------
Edip built-in filters
---------------------

``Edip`` provide a lot of predefine, non-configurable built-in filters, applicable like this:

~~~~~~~~~~~~~
Pencil Sketch
~~~~~~~~~~~~~

  The Pencil Sketch filter produce a non-photorealistic line drawing image.

~~~~~~~~~~~
Stylisation
~~~~~~~~~~~

  The stylisation filter is an edge-aware filters which effect is not focused on photorealism but abstract regions of low contrast while preserving, or enhancing, high-contrast features.

~~~~~~~~~~~~~~
Detail Enhance
~~~~~~~~~~~~~~

  The Detail Enhance filter enhances the details of a particular image.

~~~~~~~~~~~~~~~~
Edges Preserving
~~~~~~~~~~~~~~~~

  The Edge Preserving filter is a smoothing filters used in many different applications.

~~~~~~~~~~~~
Stroke Edges
~~~~~~~~~~~~

  The Stroke Edges filter add black strokes on some edges of the image.

~~~~~~~~~~~~~~~~
Invert Intensity
~~~~~~~~~~~~~~~~

  The Invert Intensity filter invert the intensity.

  This mean that the maximal value become the minimal value and so soon in the pixel values range.

~~~~~~~~~~~~~~~
Light Intensity
~~~~~~~~~~~~~~~

  The Light Intensity filter invert the intensity from the pixels channels average value.

  So that it output an grayscale image with light effect.

~~~~~~~~~~~~~~~~~~~~~
Recolor RC (Red-Cyan)
~~~~~~~~~~~~~~~~~~~~~

  Simulate conversion from RGB (Red, Green, Blue) to RC (red, cyan).

  Blues and greens are replaced with cyans.

  The effect is similar to Technicolor Process 2 (used in early color movies) and CGA Palette 3 (used in early color PCs).

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Recolor RGV (Red-Green-Value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Simulate conversion from RGB (Red, Green, Blue) to RGV (red, green, value).

  Blues are desaturated.

  The effect is similar to Technicolor Process 1 (used in early color movies).

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Recolor CMV (Cyan-Magenta-Value)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Simulate conversion from RGB (Red, Green, Blue) to CMV (cyan, magenta, value).

  Yellows are desaturated.

  The effect is similar to CGA Palette 1 (used in early color PCs).

~~~~~~~~~~~~~~~
Extrema Maximal
~~~~~~~~~~~~~~~

  The Extrema Maximal filter compute the maximal values from 2 differents channels and set the result on a channel.

~~~~~~~~~~~~~~~
Extrema Minimal
~~~~~~~~~~~~~~~

  The Extrema Minimal filter compute the minimal values from 2 differents channels and set the result on a channel.  

~~~~~~~
Sharpen
~~~~~~~

  The Sharpen filter sharpen the image by adding some white pixels at some edges and points of the image.

  This filter is based on a :ref:`Sharpen <sharpen-matrix>` :ref:`convolution matrix <convolution-matrix>`.

~~~~~~~~~~~~
Sharpen More
~~~~~~~~~~~~

  The Sharpen More filter sharpen the image by adding some white pixels at some edges and points of the image.

  It has more impact on the image as the Sharpen filter but does the same stronger.

  This filter is based on a :ref:`Sharpen <sharpen-matrix>` :ref:`convolution matrix <convolution-matrix>`.

~~~~~~~~~~
Find Edges
~~~~~~~~~~

  The Find Edges filter will result in black background image with the contours and some pixels, of the source image, displayed in color.

  This filter is based on a :ref:`Find Edges <find-edges-matrix>` :ref:`convolution matrix <convolution-matrix>`.

~~~~~~~~~
Mean Blur
~~~~~~~~~

  The Mean Blur filter swindle the image. The result image is blurred.

  This filter is based on a :ref:`Mean <mean-matrix>` :ref:`convolution matrix <convolution-matrix>`.

~~~~~~~~~~~~~~
Mean Blur More
~~~~~~~~~~~~~~

  The Mean Blur More filter swindle the image. The result image is blurred.

  It has more impact on the image as the Mean Blur filter but does the same stronger.

  This filter is based on a :ref:`Mean <mean-matrix>` :ref:`convolution matrix <convolution-matrix>`.

~~~~
Blur
~~~~

  The Blur filter swindle the image.

  What can remove some noise of the image or smooth an pixelize image.

~~~~~~~~~~~
Blur Median
~~~~~~~~~~~

  The Blur Median filter swindle the image.

  What can remove some noise of the image or smooth an pixelize image.

  This filter is well know for salt and pepper noise removing.

~~~~~~~~~~~~~
Blur Gaussian
~~~~~~~~~~~~~

  The Blur Gaussian filter swindle the image.

  What can remove some noise of the image or smooth an pixelize image.

  It use :ref:`gaussian values <gaussian-values>` for creating the blurring effect applying onto the image.

~~~~~~~~~
Denoising
~~~~~~~~~

  The denoising filter perform image denoising using Non-local Means Denoising with several computational optimizations.

  Noise expected to be a gaussian white noise.

  Denoising is done by converting image to CIELAB colorspace\nand then separately denoise L and AB components with different parameters.

~~~~~
Erode
~~~~~

  The Erode filter eroding the image content contours.

  This filter erodes the image by minimizing the pixels neighborhood.

~~~~~~
Dilate
~~~~~~

  The Dilate filter dilate the image content contours.

  This filter dilates the image by maximizing the pixels neighborhood.

~~~~~~~~~~~~~~~~~
Wave Horizontally
~~~~~~~~~~~~~~~~~

  The Wave Horizontally filter output an horizontally waved image.

~~~~~~~~~~~~~~~
Wave Vertically
~~~~~~~~~~~~~~~

  The Wave Vertically filter output an horizontally waved image.

~~~~~~~~~~
Wave Twice
~~~~~~~~~~

  The Wave Twice filter output an horizontally and vertically waved image.

~~~~~~~~~~~~~~~~~~~~
Contours Sobel White
~~~~~~~~~~~~~~~~~~~~

  The Contours :ref:`Sobel <sobel-matrix>` White filter result in an image with a white background and colored drawning wise foreground.

  All the contours strokes of the image will be displayed on a white background.

~~~~~~~~~~~~~~~~~~~~
Contours Sobel Black
~~~~~~~~~~~~~~~~~~~~

  The Contours :ref:`Sobel <sobel-matrix>` Black filter result in an image with a black background and colored drawning wise foreground.

  All the contours strokes of the image will be displayed on a black background.

~~~~~~~~~~~~~~~~~~~~~
Contours Sobel Emboss
~~~~~~~~~~~~~~~~~~~~~

  The Contours :ref:`Sobel <sobel-matrix>` Emboss filter result in an image with an :ref:`emboss gray <emboss-gray>` background and colored drawning wise foreground.

  All the contours strokes of the image will be displayed on a :ref:`emboss gray <emboss-gray>` background.

~~~~~~~~~~~~
Emboss Sobel
~~~~~~~~~~~~

  The Emboss :ref:`Sobel <sobel-matrix>` filter is an emboss filter which result looking like a kopper engraving.

  Based on the Sobel operator which detect edges horizontally and or vertically.

~~~~~~~~~~~~~~~~
Emboss Laplacian
~~~~~~~~~~~~~~~~

  The Emboss :ref:`Laplacian <laplacian-matrix>` filter is an emboss filter which result looking like a kopper engraving.

  Based on the Laplacian operator which detect edges horizontally and vertically.

.. _binary-white-OTSU:

~~~~~~~~~~~~~~~~~
Binary White OTSU
~~~~~~~~~~~~~~~~~

  The Binary White OTSU filter create an black and white image, from the source image, with white background and black foreground.

  Based on the OTSU image specific threshold computing algorithm.

  Simply try every algorithm to find the appositely one for your image, to get the best binary image from it.

.. _binary-white-TRIANGLE:

~~~~~~~~~~~~~~~~~~~~~
Binary White TRIANGLE
~~~~~~~~~~~~~~~~~~~~~

  The Binary White TRIANGLE filter create an black and white image, from the source image, with white background and black foreground.

  Based on the TRIANGLE image specific threshold computing algorithm.

  Simply try every algorithm to find the appositely one for your image, to get the best binary image from it.

.. _binary-white-AVERAGE:

~~~~~~~~~~~~~~~~~~~~
Binary White AVERAGE
~~~~~~~~~~~~~~~~~~~~

  The Binary White AVERAGE filter create an black and white image, from the source image, with white background and black foreground.

  Based on the OTSU and TRIANGLE image specific threshold computing algorithm, average.

  Simply try every algorithm to find the appositely one for your image, to get the best binary image from it.            
  
.. _binary-black-OTSU:  
  
~~~~~~~~~~~~~~~~~  
Binary Black OTSU
~~~~~~~~~~~~~~~~~

  The Binary Black OTSU filter create an black and white image, from the source image, with black background and white foreground.

  Based on the OTSU image specific threshold computing algorithm.

  Simply try every algorithm to find the appositely one for your image, to get the best binary image from it.

.. _binary-black-TRIANGLE:

~~~~~~~~~~~~~~~~~~~~~
Binary Black TRIANGLE
~~~~~~~~~~~~~~~~~~~~~

  The Binary Black TRIANGLE filter create an black and white image, from the source image, with black background and white foreground.

  Based on the TRIANGLE image specific threshold computing algorithm.

  Simply try every algorithm to find the appositely one for your image, to get the best binary image from it.

.. _binary-black-AVERAGE:

~~~~~~~~~~~~~~~~~~~~
Binary Black AVERAGE
~~~~~~~~~~~~~~~~~~~~

  The Binary Black AVERAGE filter create an black and white image, from the source image, with black background and white foreground.

  Based on the OTSU and TRIANGLE image specific threshold computing algorithm, average.

  Simply try every algorithm to find the appositely one for your image,\nto get the best binary image from it.

~~~~~~~~~~~~~~~~~~~~~
Binary Contours White
~~~~~~~~~~~~~~~~~~~~~

  The Binary Contours White filter create an black and white image, from the source image, with white background and black foreground.

  With as foreground all the contours strokes of the image.

  Like an black and white drawning.

~~~~~~~~~~~~~~~~~~~~~
Binary Contours Black
~~~~~~~~~~~~~~~~~~~~~

  The Binary Contours Black filter create an black and white image, from the source image, with black background and white foreground.

  With as foreground all the contours strokes of the image.

  Like an black and white drawning.

.. _simple-grayscaling:

------------------
Simple Grayscaling
------------------

``Edip`` can grayscaling your image, to set it enterely in gray tone, according differents bases:

+ Gray Scaling **Average**.

+ Gray Scaling **Maximal**.

+ Gray Scaling **Minimal**

+ Gray Scaling **Red**.

+ Gray Scaling **Green**.

+ Gray Scaling **Blue**.

``Edip`` will process all the pixels of your images to compute the wanted gray values.

To know that either a *gray pixel* can be encoded on a single value between **0** and **255** or

setting all channels on the same value will result in a :ref:`gray <gray-color>` pixel too.

For example let say the current pixel ``Edip`` is procesing has the following channels values:

    +-------+-----+-----+-----+
    |Channel| Red |Green|Blue |
    +=======+=====+=====+=====+
    | Value | 32  | 128 | 192 |
    +-------+-----+-----+-----+

+ Gray Scaling **Average**:

    ``Edip`` will compute the *average from all channels* and set the result as **gray value**.

    So ``Edip`` compute the average value:

    ::

        (32 + 128 + 192) / 3 = 117.

    So the resulting pixel will be transform to have following values:

        +-------+-----+-----+-----+
        |Channel| Red |Green|Blue |
        +=======+=====+=====+=====+
        | Value | 117 | 117 | 117 |
        +-------+-----+-----+-----+

    Or be encoded on a single value equal to **117**.


+ Gray Scaling **Maximal**:

    ``Edip`` will take the *highest value* from all the channels and set the it as **gray value**.

    So ``Edip`` compute the **maximal value** from the channels:

    ::

        32 < 128 < 192 = 192.

    So the resulting pixel will be transform to have following values:

        +-------+-----+-----+-----+
        |Channel| Red |Green|Blue |
        +=======+=====+=====+=====+
        | Value | 192 | 192 | 192 |
        +-------+-----+-----+-----+

    Or be encoded on a single value equal to **192**.

+ Gray Scaling **Minimal**:

    ``Edip`` will take the *lowest value* from all the channels and set the it as **gray value**.

    So ``Edip`` compute the **minimal value** from the all channels:

    ::

        192 > 128 > 32 = 32.

    So the resulting pixel will be transform to have following values:

        +-------+-----+-----+-----+
        |Channel| Red |Green|Blue |
        +=======+=====+=====+=====+
        | Value |  32 |  32 |  32 |
        +-------+-----+-----+-----+

    Or be encoded on a single value equal to **32**.

+ Gray Scaling **Red**:

    ``Edip`` will take the value from the *red channel* and set the it as **gray value**.

    So ``Edip`` recover the **red** channel value which is equal to **32**:

    ::

        Red = 32.

    So the resulting pixel will be transform to have following values:

        +-------+-----+-----+-----+
        |Channel| Red |Green|Blue |
        +=======+=====+=====+=====+
        | Value |  32 |  32 |  32 |
        +-------+-----+-----+-----+

    Or be encoded on a single value equal to **32**.


+ Gray Scaling **Green**:

    ``Edip`` will take the value from the *green channel* and set the it as **gray value**.

    So ``Edip`` recover the **green** channel value which is equal to **32**:

    ::

        Green = 128.

    So the resulting pixel will be transform to have following values:

        +-------+-----+-----+-----+
        |Channel| Red |Green|Blue |
        +=======+=====+=====+=====+
        | Value | 128 | 128 | 128 |
        +-------+-----+-----+-----+

    Or be encoded on a single value equal to **128**. 

+ Gray Scaling **Blue**:

    ``Edip`` will take the value from the *green channel* and set the it as **gray value**.

    So ``Edip`` recover the **blue** channel value which is equal to **192**:

    ::

        Blue = 192.

    So the resulting pixel will be transform to have following values:

        +-------+-----+-----+-----+
        |Channel| Red |Green|Blue |
        +=======+=====+=====+=====+
        | Value | 192 | 192 | 192 |
        +-------+-----+-----+-----+

    Or be encoded on a single value equal to **192**.


.. note::

  ``Edip`` will compute every pixel from your image like explain above according the choosen grayscaling base.

-------------------
Simple Colorscaling
-------------------

``Edip`` can colorscaling your image, to set it enterely in a main color tone, according differents bases:

+ In :ref:`red <red-color>` tone:

  - Red Scaling **Average**.

  - Red Scaling **Maximal**.

  - Red Scaling **Minimal**.

  - Red Scaling **Green**.

  - Red Scaling **Blue**.

+ In :ref:`green <green-color>` tone:

  - Green Scaling **Average**.

  - Green Scaling **Maximal**.

  - Green Scaling **Minimal**.

  - Green Scaling **Red**.

  - Green Scaling **Blue**.

+ In :ref:`blue <blue-color>` tone:

  - Blue Scaling **Average**.

  - Blue Scaling **Maximal**.

  - Blue Scaling **Minimal**.

  - Blue Scaling **Green**.

  - Blue Scaling **Blue**.

+ In :ref:`yellow <yellow-color>` tone:

  - Yellow Scaling **Average**.

  - Yellow Scaling **Maximal**.

  - Yellow Scaling **Minimal**.

  - Yellow Scaling **Red**.

  - Yellow Scaling **Green**.

  - Yellow Scaling **Blue**.

+ In :ref:`pink <pink-color>` tone:

  - Pink Scaling **Average**.

  - Pink Scaling **Maximal**.

  - Pink Scaling **Minimal**.

  - Pink Scaling **Red**.

  - Pink Scaling **Green**.

  - Pink Scaling **Blue**.

+ In :ref:`turquoise <turquoise-color>` tone:

  - Turquoise Scaling **Average**.

  - Turquoise Scaling **Maximal**.

  - Turquoise Scaling **Minimal**.

  - Turquoise Scaling **Red**.

  - Turquoise Scaling **Green**.

  - Turquoise Scaling **Blue**.

.. note::

  The pixels values computing according the differents bases are the same at by :ref:`grayscaling <simple-grayscaling>`.










        