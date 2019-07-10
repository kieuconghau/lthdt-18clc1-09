#pragma once

#include "Graphic.h"
#include <vector>
using namespace std;

class cSetting
{
public:
	class Game
	{
	public:
		static const int TOP_LIMIT;
		static const int BOT_LIMIT;
		static const int LEFT_LIMIT;
		static const int RIGHT_LIMIT;
		static const ecColor BORDER_COLOR;
	};

	class Object
	{
	public:
		class Car
		{
		public:
			static const char BRICK_SHAPE;
			static const ecColor BRICK_COLOR;
			static const int N;
			static const vector<char> SHAPES;
		};

		class Truck
		{
		public:
			static const char BRICK_SHAPE;
			static const ecColor BRICK_COLOR;
			static const int N;
			static const vector<char> SHAPES;
		};

		class Train
		{
		public:
			static const char BRICK_SHAPE;
			static const ecColor BRICK_COLOR;
			static const int N;
			static const vector<char> SHAPES;
		};

		class Bird
		{
		public:
			static const char BRICK_SHAPE;
			static const ecColor BRICK_COLOR;
			static const int N;
			static const vector<char> SHAPES;
		};

		class Dinosaur
		{
		public:
			static const char BRICK_SHAPE;
			static const ecColor BRICK_COLOR;
			static const int N;
			static const vector<char> SHAPES;
		};
	};

	cSetting();
	~cSetting();

private:
	class Console
	{
		static const bool SETTING_0;
		static const bool SETTING_1;
		static const bool SETTING_2;
	};
};

