#pragma once

#include "stdafx.h"

namespace Types {

	typedef std::basic_string<TCHAR> tstring;

	//Point구조체 정의
	struct Point {

		float x, y;

		Point(float nx, float ny) :x(nx), y(ny) {		}
		~Point() = default;

		bool operator ==(const Point& other) {
			if (this->x == other.x && this->y == other.y)
				return true;

			return false;
		}

		Point operator +(const Point& other) {
			return Point(this->x + other.x, this->y + other.y);
		}

		Point operator -(const Point& other) {
			return Point(this->x - other.x, this->y - other.y);
		}

		Point operator *(const Point& other) {
			return Point(this->x * other.x, this->y * other.y);
		}

		Point& operator =(const Point& other) {
			if (*this == other)
				return *this;

			this->x = other.x;
			this->y = other.y;

			return *this;
		}

	};

	//오브젝트 타입 정의
	enum ObjectType { OT_PLAYER, OT_ENEMY, OT_PROBS, OT_PICKUP, OT_MAP };

	//오브젝트 상태 정의
	enum ObjectState { OS_IDLE, OS_MOVE, OS_ATTACK, OS_DAMAGED, OS_FALL };

	//방향 열거체 정의
	enum Direction { DIR_DOWN = -1, DIR_IDLE, DIR_Up, DIR_LEFT, DIR_RIGHT };

	enum SceneType { ST_TITLE, ST_GAME, ST_SELECT };

}