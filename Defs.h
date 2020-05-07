#pragma once

constexpr double MaxSize = 100.0;
constexpr double MinSize = 10.0;
constexpr auto MaxItems = 80;
constexpr auto AinmationFps = 60;
constexpr double DeltaPosMin = 1.0;
constexpr double DeltaPosMax = 2.0;
constexpr double RotationStep = 1.0;
constexpr double OpacityStep = 0.005;
constexpr auto DeleteAfterMs = 200;

namespace Shapes
{
	enum Shape { Rectangle, Ellipse, Triangle, Image };
}
