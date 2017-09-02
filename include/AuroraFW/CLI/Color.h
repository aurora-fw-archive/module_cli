/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#ifndef AURORAFW_CLI_COLOR_H
#define AURORAFW_CLI_COLOR_H

#include <AuroraFW/Global.h>

namespace AuroraFW
{
	namespace CLI
	{
		enum class ColorType
		{
			Background,
			Foreground
		};

		enum class Color : unsigned int {
			Black,
			Blue,
			Green,
			Cyan,
			Red,
			Magenta,
			Yellow,
			LightGrey,
			DarkGrey,
			LightBlue,
			LightGreen,
			LightCyan,
			LightRed,
			LightMagenta,
			LightYellow,
			White
		};
		extern ArVoid_t setColor(Color color, ColorType type = ColorType::Foreground);
		extern ArVoid_t resetColor();
	}
}

#endif // AURORAFW_CLI_COLOR_H
