# Shannon-Fano algorithm
This is a simple implementation of Shannon-Fano algorithm. It includes an example file "data.in" for an image with 256 pixels resolution that looks like this: first line has an array of color codes and second line has the frequency of apparition for each color code.

This implementation is based on Shannon-Fano standard algorithm: ordering the list in decrease order and than splitting the current list in 2 so that the sum of each resulting list is almost equal.

For the "data.in" example the output will be displayed like this:

K 00
W 10
Y 010
B 110
O 0110
R 1110
P 0111
G 10