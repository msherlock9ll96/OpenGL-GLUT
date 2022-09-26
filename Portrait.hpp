#ifndef Portrait_hpp
#define Portrait_hpp

#include <stdio.h>

class Portrait {

	private: 

		float xy[2] = {0,0};
		float scale = 1;
		float hairColor[3] = {(144.f/255.f), (79.f/255.f), (49.f/255.f)};
		float skinColor[3] = {(242.f/255.f), (209.f/255.f), (205.f/255.f)};
		float glassesColor[3] = {(0.f/255.f), (0.f/255.f), (0.f/255.f)};
		float eyeColor[3] = {(255.f/255.f), (255.f/255.f), (255.f/255.f)};

	public:

		// Constructor
		Portrait(float theXy[2]);

		// Default constructor and deconstructor
		Portrait(void) = delete;
		~Portrait(void) = default;

		// Unused Copy and Move constructors
		Portrait(const Portrait&);
		Portrait operator = (const Portrait& obj) = delete;
		Portrait(Portrait&&);
		Portrait operator = (Portrait&& obj) = delete;


		// Methods

		void draw(void) const;
		void drawHead(void) const;
		void drawHair(void) const;
		void drawFace(void) const;
		void drawAccessories(void) const;
		void drawEllipse(float x, float y) const;

};

#endif