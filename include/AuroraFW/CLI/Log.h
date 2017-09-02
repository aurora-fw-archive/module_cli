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

#ifndef AURORAFW_CLI_LOG_H
#define AURORAFW_CLI_LOG_H

#include <AuroraFW/TLib/Target/Environment.h>
#include <AuroraFW/CLI/Output.h>
#include <AuroraFW/Core/Debug.h>

namespace AuroraFW {
    namespace CLI
	{
		enum MessageStatus
		{
			Error,
			Warning,
			Notice,
			Information,
			Debug
		};

        template <typename T>
		void __Log(T t)
		{
			Output << t;
		}

        template <typename T, typename... R>
		void __Log(T t, R... args)
		{
			Output << t;
			__Log(args...);
		}

        template <typename T, typename... R>
		void Log (T t, R... args)
		{
			// TODO: Windows ANSI integration
			//       Needs to be tested on Windows and Apple platforms
			if(t == Error)
			{
				#ifdef AFW_TARGET_ENVIRONMENT_UNIX
				Output << "\033[0m\033[1m[\033[1;31mERROR\033[0;1m] \033[0m";
				#else
				Output << "[ERROR] ";
				#endif
			}
			else if (t == Warning)
			{
				#ifdef AFW_TARGET_ENVIRONMENT_UNIX
				Output << "\033[0m\033[1m[\033[1;33mWARNING\033[0;1m] \033[0m";
				#else
				Output << "[WARNING] ";
				#endif
			}
			else if (t == Notice)
			{
				#ifdef AFW_TARGET_ENVIRONMENT_UNIX
				Output << "\033[0m\033[1m[\033[1;36mNOTICE\033[0;1m] \033[0m";
				#else
				Output << "[NOTICE] ";
				#endif
			}
			else if (t == Information)
			{
				#ifdef AFW_TARGET_ENVIRONMENT_UNIX
				Output << "\033[0m\033[1m[\033[1;32mINFORMATION\033[0;1m] \033[0m";
				#else
				Output << "[INFORMATION] ";
				#endif
			}
			else if (t == AuroraFW::CLI::Debug)
			{
				if(AuroraFW::Debug::Status)
				{
					#if AFW_DEBUG_LOG

					#else
						if(Debug::isVerbose == false)
						#ifdef AFW_TARGET_ENVIRONMENT_UNIX
							Output << "\033[0m\033[1m[\033[1;36mDEBUG\033[0;1m] \033[0m";
						#else
							Output << "[DEBUG] ";
						#endif
						__Log(args...);
						Output << EndLine;
					#endif
					return;
				}
				else return;
			}
            else {
                __Log(t, args...);
                Output << EndLine;
                return;
            }
			__Log(args...);
			Output << EndLine;
		}
	}
}

#endif // AURORAFW_CLI_LOG_H
