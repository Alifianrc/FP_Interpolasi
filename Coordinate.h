#pragma once
struct Coordinate
{
	float x, y;

	Coordinate(float valX, float valY) {
		x = valX;
		y = valY;
	}

	Coordinate() = default;
};