====================
Images Files Merging
====================

  ``Edip`` provide severals files merging algorithms which permit to combine 2 input files to an single output file through an image mixing algorithm.

  You can choose 2 differents input image files, in any supported format, with giving eventual settings, to merge it into a single ouput image file.

  The differents images must have the same size to be interpolated, so ``Edip`` resize the output image to the same size, to the littler image file size from the twos per default.

  But you can set the output size you want for your output image.

  Then you can save the result of the image files merging to any supported format, by clicking on the :guilabel:`&Save file` button.   


-----------------------------
Files merging Blend algorithm
-----------------------------

  Interpolate 2 images file with the constant alpha to generate an output image:

  ::
  
    Result = Image1 * alpha - (1-alpha) * Image2

  + You must set the value of **alpha** which default to **0.5** between **0.01** and **1.0**.

  The images are converted to the same size (to the littler image) was is required for blend operation. 

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window.
  
------------------------------
Files merging Screen algorithm
------------------------------

  Superimpose two inverted images on the top of each other:

  ::

    Result = MAX - ((MAX-Image1)  * (MAX-Images2) / MAX)
  
  The images are converted to the same size (to the littler image) was is required for screen operation.

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window.  
  
------------------------------
Files merging Darker algorithm
------------------------------  

  Interpolate 2 images file and produce an output image with the darkest pixels values:

  ::

    Result = min( Image1, Image2 )

  The images are converted to the same size (to the littler image) was is required for darker operation.

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window. 
  
-------------------------------
Files merging Lighter algorithm
-------------------------------

  Interpolate 2 images file and produce an output image with the lightest pixels values:

  ::

    Result = max( Image1, Image2 )
  
  The images are converted to the same size (to the littler image) was is required for lighter operation.

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window. 
  
---------------------------
Files merging Add algorithm
---------------------------

  Add 2 images, dividing the result by scale and adding offset to generate an output image:

  ::

    Result = (Image1 + Image2) / scale + offset

  + You must set the value of **scale** which default to **1.0** between **0.01** and **8.0**.

  + You must set the value of **offset** which default to **0** between **0** and **255**.

  The images are converted to the same size (to the littler image) was is required for add operation.

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window.    
        
----------------------------------
Files merging Add modulo algorithm
----------------------------------

  Add 2 images and make the euclidian division of the result per the maximal:

  ::

    Result = ( Image1 + Image2 ) % MAX

  The images are converted to the same size (to the littler image) was is required for add modulo operation.

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window.
  
--------------------------------
Files merging Subtract algorithm
--------------------------------

  Subtract 2 images, dividing the result by scale and adding offset to generate an output image:

  ::

    Result = (Image1 - Image2) / scale + offset

  + You must set the value of **scale** which default to **1.0** between **0.01** and **8.0**.

  + You must set the value of **offset** which default to **0** between **0** and **255**.

  The images are converted to the same size (to the littler image) was is required for sub operation.      
  
  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window.
  
---------------------------------------
Files merging Subtract modulo algorithm
---------------------------------------

  Subtract 2 images and make the euclidian division of the result per the maximal:

  ::

    Result = ( Image1 - Image2 ) % MAX
  
  The images are converted to the same size (to the littler image) was is required for sub modulo operation.

  .. note::

    You can use the button :guilabel:`Preview result` to preview your output image.
  
    If the output size is greater than 800x600 pixels the preview image is resize to be included in the image preview window.  
       
      