#pragma once

#include "stdafx.h"

namespace Types {

	typedef std::basic_string<TCHAR> tstring;

	//Point����ü ����
	struct Point {

		float x, y;

		Point(float nx = 0.f, float ny = 0.f) :x(nx), y(ny) {		}
		~Point() { };

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
	   
	//������Ʈ Ÿ�� ����
	enum ObjectType { OT_PLAYER, OT_ENEMY, OT_PROBS, OT_PICKUP, OT_MAP };

	//������Ʈ ���� ����
	enum ObjectState { OS_IDLE, OS_MOVE, OS_ATTACK, OS_DAMAGED, OS_FALL };

	//���� ����ü ����
	enum Direction { DIR_DOWN = -1, DIR_IDLE, DIR_UP, DIR_LEFT, DIR_RIGHT };

	enum SceneType { ST_TITLE, ST_GAME, ST_SELECT };

}