#pragma once
#include "Config.h"
#include "SimulationConfig.h"
#include "common/String.h"
#include <cstring>

inline ByteString VersionInfo()
{
	ByteStringBuilder sb;
	sb << DISPLAY_VERSION[0] << "." << DISPLAY_VERSION[1];
	if constexpr (!SNAPSHOT)
	{
		sb << "." << APP_VERSION.build;
	}
	sb << " " << IDENT;
	if constexpr (MOD)
	{
		sb << " MOD " << MOD_ID << " UPSTREAM " << UPSTREAM_VERSION.build;
	}
	if constexpr (SNAPSHOT)
	{
		sb << " SNAPSHOT " << APP_VERSION.build;
	}
	if constexpr (LUACONSOLE)
	{
		sb << " LUACONSOLE";
	}
	if constexpr (NOHTTP)
	{
		sb << " NOHTTP";
	}
	else if constexpr (ENFORCE_HTTPS)
	{
		sb << " HTTPS";
	}
	if constexpr (DEBUG)
	{
		sb << " DEBUG";
	}
	return sb.Build();
}

inline ByteString IntroText()
{
          ByteStringBuilder sb;
          sb << "\bl\buSandboxEngine - Build 1.2\bu\n"
	      "\n"
	      "\n"
	      "\bgPress \bo'F1'\bg to show or hide this text.\n"
	      "\n"
	      "\bgTo choose a material, hover over one of the icons on the right, it will show a selection of elements in that group.\n"
	      "Pick your material from the menu using \bomouse left/right\bg buttons.\n"
	      "Draw freeform lines by dragging your mouse left/right button across the drawing area.\n"
	      "\n";
	if constexpr (BETA)
	{
		sb << "\brThis is SandboxEngine build 1.2\n";
	}

	if constexpr (std::string_view(IDENT_PLATFORM) == "EMSCRIPTEN")
	{
		sb << "\brLocal saves and other data are managed by your browser and may be deleted unexpectedly. \bgIf in doubt, save online.\n";
	}
	sb << "\n\bt" << VersionInfo();
	return sb.Build();
}
