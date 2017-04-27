//
// Created by gold1 on 26-Apr-17.
//

#include "main_window.h"
#include "preview_panel.h"

#include <easylogging++.h>

main_window::main_window() : _main_window(nullptr, wxID_ANY, "Minecraft Shaderpack Texture Viewer", wxPoint(50, 50), wxSize(450, 340)) {
	wxGLAttributes attrs;
	attrs.PlatformDefaults().Defaults().EndList();
	bool accepted = wxGLCanvas::IsDisplaySupported(attrs);

	if(!accepted) {
		LOG(WARNING) << "Could not create OpenGL context with default attributes, trying again";

		attrs.Reset();
		attrs.PlatformDefaults().RGBA().DoubleBuffer().Depth(16).EndList();
		accepted = wxGLCanvas::IsDisplaySupported(attrs);

		if(!accepted) {
			LOG(ERROR) << "Could not create OpenGL context with needed attributes";
		}
	}

	auto opengl_panel = new preview_panel(this, attrs);
}
