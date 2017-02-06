#include "stdafx.h"
#include "MyRectangle.h"


MyRectangle::MyRectangle()
{
}


MyRectangle::MyRectangle(int h, int w)
{
	height = h;
	width = w;
}

int MyRectangle::getHeight()
{
	return height;
}

int MyRectangle::getWidth()
{
	return width;
}

int MyRectangle::getArea()
{
	return height * width;
}