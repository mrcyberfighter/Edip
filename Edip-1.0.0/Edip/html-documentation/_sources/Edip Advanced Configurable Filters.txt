=============================
Advanced Configurable Filters
=============================

--------------
Kernel filters
--------------

~~~~~~~~~~~~~~~~~~~~~
Sharpen kernel filter
~~~~~~~~~~~~~~~~~~~~~

You can apply a fully configurable :ref:`Sharpen kernel <sharpen-matrix>` filter to the image.

* **Configuration options**:

  + **Kernel type**:

    - :ref:`Square <square-kernel>`
 
    - :ref:`Diamond <diamond-kernel>`
 
    - :ref:`Cross <cross-kernel>`
 
    - :ref:`X <x-kernel>`
 
  + **Kernel size**:

    The size of the kernel: per example a size of **3** correspond to a **3x3 matrix**.
 
    You can only use **odd** values between **3** and **31** included.
 
  + **Values factor**:

    The factor to multtply each kernel component with.
 
  + **Center factor**:

    The factor to multiply the kernel center with.    

.. note::

  You can preview the kernel you have configurated by using the :guilabel:`&Preview kernel` button.


~~~~~~~~~~~~~~~~~~~~
Emboss kernel filter
~~~~~~~~~~~~~~~~~~~~

You can apply a fully configurable :ref:`Emboss kernel <emboss-matrix>` filter to the image.

* **Configuration options**:


  + **Kernel type**:

    - :ref:`Square <square-kernel>`
 
    - :ref:`Diamond <diamond-kernel>`
 
    - :ref:`Cross <cross-kernel>`
 
    - :ref:`X <x-kernel>`

  + **Kernel size**:

    The size of the kernel: per example a size of **3** correspond to a **3x3 matrix**.
 
    You can only use **odd** values between **3** and **31** included.


.. note::

  You can preview the kernel you have configurated by using the :guilabel:`&Preview kernel` button.


~~~~~~~~~~~~~~~~~~
Mean kernel filter
~~~~~~~~~~~~~~~~~~

You can apply a fully configurable :ref:`Mean kernel <mean-matrix>` filter to the image.

* **Configuration options**:

  + **Kernel type**:

    - :ref:`Square <square-kernel>`
 
    - :ref:`Diamond <diamond-kernel>`
 
    - :ref:`Cross <cross-kernel>`
 
    - :ref:`X <x-kernel>`

  + **Kernel size**:

    The size of the kernel: per example a size of **3** correspond to a **3x3 matrix**.
 
    You can only use **odd** values between **3** and **31** included.

.. note::

  You can preview the kernel you have configurated by using the :guilabel:`&Preview kernel` button.

~~~~~~~~~~~~~~~~~~~~~~
Gaussian kernel filter
~~~~~~~~~~~~~~~~~~~~~~

You can apply a fully configurable :ref:`Gaussian kernel <gaussian-matrix>` filter to the image.

* **Configuration options**:

  + **Kernel type**:

    - :ref:`Square <square-kernel>`
 
    - :ref:`Diamond <diamond-kernel>`
 
    - :ref:`Cross <cross-kernel>`
 
    - :ref:`X <x-kernel>`
 
  + **Kernel size**:

    The size of the kernel: per example a size of **3** correspond to a **3x3 matrix**.
 
    You can only use **odd** values between **3** and **31** included.
 
  + **Sigma value**:

    Seed value used to generate the :ref:`gaussian vector <gaussian-vector>` on which the kernel will be based.

.. note::

  You can preview the kernel you have configurated by using the :guilabel:`&Preview kernel` button.

~~~~~~~~~~~~~~~~~~~~
Kirsch kernel filter
~~~~~~~~~~~~~~~~~~~~

You can apply a fully configurable :ref:`Kirsch kernel <kirsch-matrix>` filter to the image.

* **Configuration options**:

  + Direction:

    - :ref:`East <kirsch-east>`
 
    - :ref:`West <kirsch-west>`
 
    - :ref:`North <kirsch-north>`
 
    - :ref:`South <kirsch-south>`
 
  + **Kernel size**:

    The size of the kernel: per example a size of **3** correspond to a **3x3 matrix**.
 
    You can only use **odd** values between **3** and **31** included.
 
  + **Values factor**:

    The factor to multtply each kernel component with.

.. note::

  You can preview the kernel you have configurated by using the :guilabel:`&Preview kernel` button.

-------------------
Photography filters
-------------------

~~~~~~~~~~~~~
Pencil Sketch
~~~~~~~~~~~~~

The Pencil Sketch filter produce a non-photorealistic line drawing image.

* **Configuration options**:

  + **Sigma S**:

    Value between **0.0** and **200.0**.
 
  + **Sigma R**:

    Value between **0.0** and **1.0**.
 
  + **Shade** factor:

    Value between **0.001** and **0.100**.

~~~~~~~~~~~
Stylisation
~~~~~~~~~~~

The stylisation filter is an edge-aware filters which effect is not focused on photorealism but

abstract regions of low contrast while preserving, or enhancing, high-contrast features.

* **Configuration options**:

  + **Sigma S**:

    Value between **0.0** and **200.0**.
 
  + **Sigma R**:

    Value between **0.0** and **1.0**.


~~~~~~~~~~~~~~
Detail Enhance
~~~~~~~~~~~~~~

The Detail Enhance filter enhances the details of a particular image.

* **Configuration options**:

  + **Sigma S**:

    Value between **0.0** and **200.0**.
 
  + **Sigma R**:

    Value between **0.0** and **1.0**.


~~~~~~~~~~~~~~~
Edge Preserving
~~~~~~~~~~~~~~~

The Edge Preserving filter is a smoothing filters used in many different applications.

* **Configuration options**:

  + **Sigma S**:

    Value between **0.0** and **200.0**.
 
  + **Sigma R**:

    Value between **0.0** and **1.0**.

  + **Filter**:

    - **Recurse** filter.
 
    - **NormConv** Filter.



~~~~~~~~~
Denoising
~~~~~~~~~

The denoising filter perform image denoising using Non-local Means Denoising with several computational optimizations.

Noise expected to be a gaussian white noise.

Denoising is done by converting image to CIELAB colorspace and then separately denoise L and AB components with different parameters.

* **Configuration options**:

  + **Luminance factor**:

    Parameter regulating filter strength. Big values perfectly removes noise but also removes image details, smaller values preserves details but also preserves some noise.
 
  + **Color denoising factor**:

    The same as **Luminance factor** but for color components.




 
---------------------
Morphological filters
---------------------

Morphological operations process images according to shapes.

They apply a defined **structuring element** (named :ref:`kernel <convolution-matrix>`) to the image obtaining a new image where the current pixel is computed by comparing it to his neighborhood pixels.

.. note::

  Depending on the **structuring element** selected (which is fully configurable in ``Edip``)

  a morphological operation is more sensitive to one specific shape or the other.

~~~~~~~~~~~~~~~~~~~~~~~~
Morphological operations
~~~~~~~~~~~~~~~~~~~~~~~~

.. _morphological-dilatation:

++++++++++
Dilatation
++++++++++

Dilatation add pixels from the background to the boundaries of the object in an image.

In dilatation, the value of the output pixel is the maximum of all pixels in the neighborhood.

.. _morphological-erosion:

+++++++
Erosion
+++++++

Erosion remove pixels from the foreground.

Using erosion the value of the output pixel is the minimum of all pixels in the neighborhood.

.. _morphological-open:

+++++++
Opening
+++++++

Opening is an :ref:`erosion <morphological-erosion>` followed by a :ref:`dilatation <morphological-dilatation>`.

Opening remove small objects from an image while preserving the larger one.

.. _morphological-close:

+++++++
Closing
+++++++

Closing is a :ref:`dilatation <morphological-dilatation>` followed by an :ref:`erosion <morphological-erosion>`.

Closing is used to remove samll holes while preserving the larger one.

++++++
Tophat
++++++

Tophat ouput is the difference between the source image and it's :ref:`opening <morphological-open>`.

++++++++
Blackhat
++++++++

Blackhat ouput is the difference between the source image and it's :ref:`closing <morphological-close>`.

------------
Canny filter
------------

The **Canny** contours detection operator use 2 different :ref:`threshold <thresholding>` values:

  **Low threshold**:
    The low threshold should be chosen in a way that it included all edges pixels that are considered as to belong to a significant image contour.

    This should detect more edges that what is ideally needed in the case of the **Canny** algorithm.

  **High threshold**:
    His role is to define the edges that belong to all important contours.

    It should exclude all edges considered as outlier.

The **Canny** algorithm combines these two edges maps in order to produce an optimal map of contours.

It operate by keeping only edge points of the low threshold edge map for which a continuous path of edges exist, linking
all edges points of the high threshold map are kept, while isolated chains of edges points in the low threshold map are removed.


.. note::

  This strategy, based on the use of **two threshold** to obtain a binary map, is called **histereris thresholding**.

In addition, the **Canny** algorithm uses an extra strategy to improve the quality of the edge map: all edges points for which the gradient magnitude is not a maximum in the gradient direction are removed.

The gradient orientation is always perpendicular to the edge. Therefor, the local maximum of the gradient is this direction correspond to the points of maximum strength of the contours.

This explains why thin edges are obtained in tha **Canny** contours map.  

---------------------
Color contours filter
---------------------

This produce the same result as the **Canny** filter except that you can set:

  + The foreground color: the color of the detected edges.

  + The background color.
     


   