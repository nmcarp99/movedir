#pragma once
#include "movedir.h"

increments checkIncrements(float x, float y, float destinationX, float destinationY) {
	increments incrementVals = { 0, 0 };
	if (destinationX > x && destinationY > y) {
		incrementVals.x = (destinationX - x) / (destinationY - y);
		incrementVals.y = 1;
		while (incrementVals.x > 3) {
			incrementVals.x = incrementVals.x / 2;
			incrementVals.y = incrementVals.y / 2;
		}
	}
	else if (destinationX < x && destinationY > y) {
		incrementVals.x = (destinationX - x) / (destinationY - y);
		incrementVals.y = 1;
		while (incrementVals.x < -3) {
			incrementVals.x = incrementVals.x / 2;
			incrementVals.y = incrementVals.y / 2;
		}
	}
	else if (destinationX < x && destinationY < y) {
		incrementVals.x = -((destinationX - x) / (destinationY - y));
		incrementVals.y = -1;
		while (incrementVals.x < -3) {
			incrementVals.x = incrementVals.x / 2;
			incrementVals.y = incrementVals.y / 2;
		}
	}
	else if (destinationX > x && destinationY < y) {
		incrementVals.x = -((destinationX - x) / (destinationY - y));
		incrementVals.y = -1;
		while (incrementVals.x > 3) {
			incrementVals.x = incrementVals.x / 2;
			incrementVals.y = incrementVals.y / 2;
		}
	}
	return incrementVals;
}