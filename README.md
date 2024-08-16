# About the Repository
Homework for OOP Program Designing. 
The program simulates a 3D-Model. Only support .obj files.

# IO-Format
## Point3D
(x, y, z), where x, y, z are the three coordinates.
For example, the following code
```cpp
// In main()
Point3D point(3, 2, 1);
std::cout << point << std::endl;
```
has the output
```
(3, 2, 1)
```
Input of Point3D is the same, but the whitespace between '(' and ')' will be ignored.
## MultiPoint
`[Point1, Point2, ..., PointN]`
For example:
```cpp
// In main()
Face3D face(Point3D(1, 1, 1), Point3D(2, 2, 2), Point3D(3, 3, 3));
std::cout << face << std::endl;
```
has the output
```
[(1, 1, 1), (2, 2, 2), (3, 3, 3)]
```
MultiPoint doesn't support input, because operator>> is not overloaded for MultiPoint.

# Path of the File
Absolute Path is supported. The support of relative path is untested.
