#pragma once

#define uint unsigned int


//example, you pick what you wish

#define METER 10.0f
#define KILOMETER 10000.0f
#define DECIMETER 1.0f
#define CENTIMETER 0.1f
#define MILLIMETER 0.01f
//Error tolerance for floating point calcualtions
#define EPSILON 0.000001f

//Difference threshold within seperating "species"
#define DELTA 1000

//Time Metrics
#define HOUR 0.0416f
#define DAY 1.0f
#define WEEK 7.0f
#define MONTH 31.0f

#define NEWTON 10.0f
// mass metrics

#define GRAM 0.001f
#define KILOGRAM 1.0f

#define PI 3.14159f
//(found out const float is bad concerning scope issues)
