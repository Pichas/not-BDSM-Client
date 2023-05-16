#pragma once 

#include <vector>
#include <memory>

#include "window.h"
#include "../include/leftpanel.h"

namespace BDSM
{


struct Application final
{
	Application() = delete;
	Application(const Application&) = delete;
	Application(Application&&) = delete;
	Application& operator=(const Application&) = delete;
	Application& operator=(Application&&) = delete;

	Application(std::string_view title, ImVec2 windowSize = { 1280, 720 });
	virtual ~Application(){};
	
	void Run();

private:
	void StartFrame();
	void EndFrame();
	bool ProcessEvents();


	std::vector<std::shared_ptr<Panel>> m_panels;
	std::shared_ptr<Window>m_window;
};

}