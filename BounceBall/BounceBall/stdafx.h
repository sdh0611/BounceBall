#pragma once


#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <memory>
#include "Types.h"


#define SAFE_DELETE(ptr) if(ptr != nullptr){ delete ptr; ptr = nullptr; }