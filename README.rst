---------------------------------------------------
E.D.I.P the Easy Digital Imaging Processing program
---------------------------------------------------

  :Program: Edip
 
  :Version: 1.0.0
 
  :Author: Eddie Brüggemann <mrcyberfighter@gmail.com>

  :Language: C++

  :Release: 24/11/2015
 
  :License: GPLv3
 
  .. image:: ./Edip_icon.png

====================
E.D.I.P presentation
====================

  ``Edip`` is an easy to use image effects processing programme with severals functionnalities.

  ``Edip`` permit to:

  + **Rotate** your image over 90° to the **left** or to the **right**.

  + **Mirror** your image, so that:
  
    - The left side from your image is copy, mirror likewise, on the right side.
  
    - The right side from your image is copy, mirror likewise, on the left side.
  
    - The upper part of your image is copy, mirror likewise, on the bottom part.
  
    - The bottom part of your image is copy, mirror likewise, on the upper part.
  
  + **Zoom** on a **selected center** or the default **image center**.
  
  + **Flipping** your image. 
  
    - From left to right.
  
    - From right to left.
  
    - From up to down.
  
    - From down to up.
 
  ``Edip`` permit to change the image color intensity and some phenomenal color spaces settings.
 
  + **Color intensity**
 
    - You can set the **red** intensity.
    
    - You can set the **green** intensity.
   
    - You can set the **blue** intensity.
   
    - You can set the **global** intensity.
  
  + **Phenomenal color spaces settings**
  
    - You can set the **Lightness** from your image.
 
    - You can set the **Hue** from your image.
 
    - You can set the **Saturation** from your image.
       
    - You can set the **Brightness** from your image.   
  
  ``Edip`` permit to apply severals built-in filters to your image by simply selecting the wanted filter in the list and pressing the apply button.

  The built-in filters are divide into **3** differents categories:

  + **normal filters**

    You can apply over **30** differents filters to your image.
  
  + **Grayscaling filters**

    You can grayscale your image according **6** differents algorithms.
  
  + **Colorscaling** filters

    You can colorscale your image in 6 differents colors (**red**, **green**, **blue**, **yellow**, **pink**, **turquoise**) according differents algorithms for every color.
  
  In addition ``Edip`` provide many fully configurable filters which you can apply to your image:

  + **Kernel** filters.

  + **Photography** filters.

  + **Morphological** filters.

  + **Canny** filter.

  + **Color contours** filter.

  + **Multiply colors**.

  + **Multiply global intensity**.

  + **Set image in color tone**.

  
  ``Edip`` provide some basic draw functionalities to draw onto your image in the wanted color with the wanted thickness or to fill your form.

  + **Polylines**.

  + **Rectangle**.

  + **Circle**.

  + **Ellipse**.

  + **Polygone**: *normal* or *strikethrough*.

  + **Star**: *normal*, *strikethrough*, *flower likewise*, *stroked*.

  + **Text**.

============
Installation
============
    
    :depends: gtkmm-3.0 opencv-3.0.0
    
    opencv-3.0.0 source furnished with Edip.
    
    Because Edip required this library in this version.
    
    OpenCV coming from your packages manager is often precompiled with

    GTK2 support and not GTK3 support, so uncompatible with Edip.

    If you get opencv-3.0.0 installed and you are not sure,
    
    try to launch the test program by typing:
     
    :: 
     
        $ make test

    If this fail you can install the opencv-3.0.0 version shipped with
    
    Edip by typing:
    
    ::
    
        $ make opencv3 # An internet connection is required.

        $ sudo make install-opencv3 # Install opencv-3.0.0

    What will add a library to your system and the only case it can disturb you is

    if you want to write an application using GTK2 and opencv.

    
    Installation process:    
    
    ::
    
        $ make opencv3 # An internet connection is required.
          
        $ sudo make install-opencv3 # Build and install opencv-3.0.0 from source.
        
        $ make # Build all binaries. 
        
        $ sudo make install # Install Edip on your system. 



=======
Credits
=======

  :Author: Eddie Bruggemann
 
  :Contact: <mrcyberfighter@gmail.com>
 
  :License: GPLv3.
  
  Thank's to my beloved mother, my family and to the doctors.
 
  Stay away from drugs: drugs destroy your brain and your life.
  
=========  
Copyright
=========                              

 This programm is under copyright from the GPL GNU GENERAL PUBLIC LICENSE        