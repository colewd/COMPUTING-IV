/**********************************************************************

 

*  sierpinski-readme template                                                   


*  Recursive Graphics Assignment                       


**********************************************************************/

Your name:
Cole DiStasio


Operating system you're using (Linux, OS X, or Windows):
Windows 


If Windows, which solution?:
virtualbox


Text editor or IDE you're using:
emacs


Hours to complete assignment:
roughly 2-3 hours


/**********************************************************************

 

*  Discussion (important)

 

*  About what you did—at least 100 words (what you actually implemented)

**********************************************************************/
In this assignment I created a class sierpinski and overloaded the draw function so I was able to call sierpinski recursively to draw multiple triangles within one another. When constructed the sierpinski class would create a large triangle and then draw, using sprites to the window, smaller level triangles until the depth of recursion has been met. It would create these triangles using the same coordiantes of the previous triangle but of half the length. One on the left, one on the right and the one on top.







/**********************************************************************

 

*  List whatever help (if any) you received from TAs, the instructor,

 

*  classmates, or anyone else.

 

**********************************************************************/
Did not recieve any help on this assignment.






/**********************************************************************

 

* Describe what was interesting, hard, fun, or easy about your project.

                 

 

**********************************************************************/
I thought this assignment was fairly easy with all the information provided in class. I thought it was fun seeing how the sierpinski triangles design looks cooler the larger the depth of recursion. 






/**********************************************************************

 

* List any other comments here.                                     

 

**********************************************************************/
To run the executable:
make
./sierpinski (depth of recursion) (window height)
For example:
./sierpinski 3 500
