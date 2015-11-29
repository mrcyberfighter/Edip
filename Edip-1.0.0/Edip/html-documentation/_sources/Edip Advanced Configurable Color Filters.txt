===================================
Advanced Configurable Color Filters
===================================

---------------
Mulitply Colors
---------------

  You can set following factors to multiply each different color channel by it corresponding factor value.
 
  + Multiply **red** channel:
 
    Factor to multiply the **red** channel.
   
  + Multiply **green** channel:
 
    Factor to multiply the **green** channel.
   
  + Multiply **blue** channel:
 
    Factor to multiply the **blue** channel.
   
  + Multiply **alpha** channel:
 
    Factor to multiply the **alpha** channel.
 
------------------------ 
Multiply global intesity
------------------------

  Mulitply each color channel (**red**, **green** and **blue**) by the given factor.
 
-----------------------
Set image in color tone
-----------------------

  You can select a color to set the entire image in this color tone.
 
  The color tone is applied to the image by following steps:
 
  1. Computing the image mean value for every channel.
 
  2. Dividing each given color by the corresponding mean value from each channel.
 
  3. Multiply each channel by the result from step 2.
 
   
 
      
      