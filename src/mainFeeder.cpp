/***********************************************************************
 *                            T R O K A M
 *                       Internet Search Engine
 *
 * Copyright (C) 2018, Nicolas Slusarenko
 *                     nicolas.slusarenko@trokam.com
 *
 * This file is part of Trokam.
 *
 * Trokam is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Trokam is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Trokam. If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

/// C++
#include <iostream>

/// Trokam
#include "common.h"
#include "feeder.h"
#include "reporting.h"
#include "options.h"

/**
 *
 **/
int main(int argc, const char* argv[])
{
    /**
     * Command options could be read from command line and a file.
     **/
    Trokam::Options opt(argc, argv);
    opt.readSettings(CONFIG_FILE);

    try
    {
        /**
         * Copy data from crunchers' database into web server's database.
         **/
        Trokam::Feeder feed(opt);
        feed.copyAll();
    }
    catch(const int &e)
    {
        Trokam::Reporting::showGeneralError(e);
    }

    /**
     * Cleaning up.
     **/
    opt.deleteWorkingDirectory();
}
