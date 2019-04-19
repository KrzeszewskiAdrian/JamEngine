#pragma once

#include "RenderManager.h"
#include "InitSettings.h"
#include "Settings.h"
#include "RenderSettings.h"


class ApplicationManager
{
public:
	ApplicationManager();
	bool init();
	bool runApplication();
	RenderSettings takeRenderSettings();
	InitSettings takeInitSettings();
};