//
//  Triangle.hpp
//  Week 01 - New
//
//  Created by Jean-Yves Hervé on 9/13/22.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>


class Triangle {

	private:
	
		float xy[3][2];

	public:
	
		Triangle(float theXy[][2]);
		~Triangle(void) = default;
	
		// copy and move constructors

		// copy and move operators

		// basic suit of constructors and operators
		Triangle(void);		// default constructor
		// You could also set this default constructor as
		// Triangle(void) = delete;
		// to prevent a non-overloaded object creation
		// 


		Triangle(const Triangle&); // copy
		Triangle(Triangle&&); // move constructor

		// Ocerloaded copy operator
		Triangle operator = (const Triangle& obj) = delete; // copy operator
		Triangle operator = (Triangle&& obj) = delete; // copy operator

		void draw(void) const;

};
#endif /* Triangle_hpp */

// Showing how references work (especially for &&)

// Triangle t1(...);
// Triangle t2(t1);  // t2 would be a triangle that is a copy of t1

// takes two triangles and returns where they intersect, this is where Triangle&& is used
// Triangle intersection(const Triangle& t1, const Triangle& t2);

// Triangle t3(intersection(t1, t2));

// Do a bit more research for Triangle&& meaning on your own...

