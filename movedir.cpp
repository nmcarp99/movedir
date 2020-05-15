#pragma once
#include "movedir.h"

increments checkIncrements(float x, float y, float destinationX, float destinationY) {
	increments incrementVals = { 0, 0 };
	if (destinationY > y+5) {
		incrementVals = { 0, 1 };
	}
	else if (destinationY < y-5) {
		incrementVals = { 0, -1 };
	}
	if (destinationX > x+5) {
		if (destinationY > y) {
			incrementVals.x = (destinationX - x) / (destinationY - y);
			incrementVals.y = 1;
			while (incrementVals.x > 3) {
				incrementVals.x = incrementVals.x / 2;
				incrementVals.y = incrementVals.y / 2;
			}
		}
		else if (destinationY < y) {
			incrementVals.x = -((destinationX - x) / (destinationY - y));
			incrementVals.y = -1;
			while (incrementVals.x > 3) {
				incrementVals.x = incrementVals.x / 2;
				incrementVals.y = incrementVals.y / 2;
			}
		}
	}
	else if (destinationX < x-5) {
		if (destinationY > y) {
			incrementVals.x = (destinationX - x) / (destinationY - y);
			incrementVals.y = 1;
			while (incrementVals.x < -3) {
				incrementVals.x = incrementVals.x / 2;
				incrementVals.y = incrementVals.y / 2;
			}
		}
		else if (destinationY < y) {
			incrementVals.x = -((destinationX - x) / (destinationY - y));
			incrementVals.y = -1;
			while (incrementVals.x < -3) {
				incrementVals.x = incrementVals.x / 2;
				incrementVals.y = incrementVals.y / 2;
			}
		}
	}
	return incrementVals;
}