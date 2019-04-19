#pragma once

#include "ViewportCode.h"
//A mouse Click performed within borders of Panel
class PanelClick
{
public:
	PanelClick(vpc mPanel, double x, double y);
	double x;
	double y;
	vpc mPanel;
};