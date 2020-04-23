//// Tile based movement Using the mouse x and y position you'll use Multiplication rounding and division to get the tile. 
//// say the grid size was 200 you would need to divide the mouse positions x and y by 200. then round that value to the nearest decimal. 
//// Next you will want to multiply the result by 200.
////  * **Pseudo code * **
////
////  float GridSize = 100.0f;
////  // Get mouse position
////  vector2 position = mousePosition();
////
////  // Calculate Grid Position
////  vector2 tempPosition = vector2(Position / GridSize);
////  vector2 pointInGrid = vector2(round(tempPosition.X), bound(tempPosition.Y)) * GridSize;
////  //New location in cell -> pointInGrid; 
////
////  The last step would be to figure out which index the pointInGrid is located in - using division. (Note: Don't forget to include the offset!)
////
//#pragma once
//#include "Tile.h"
//
//class MouseControl : public GameEntity
//{
//	float BoardSize = 10.0f;
//
//	Vector2 mousePosition;
//
//	//Vector2 tempPosition;
//	//Vector2 pointInGrid;
//
//	int mouseX;
//	int mouseY;
//
//	static void Instance();
//	MouseControl();
//	~MouseControl();
//	void Update() override;
//	void Render() override;
//
//	
//};
//
