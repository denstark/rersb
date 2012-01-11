/*****************************************************************************/
/* rersbException.h for rersb                                                */
/* Copyright (c) 2012 Thomas Hartman (rokstar83@gmail.com)                   */
/*                                                                           */
/* This program is free software; you can redistribute it and/or             */
/* modify it under the terms of the GNU General Public License               */
/* as published by the Free Software Foundation; either version 2            */
/* of the License, or the License, or (at your option) any later             */
/* version.                                                                  */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*****************************************************************************/
#ifndef RERSBEXCEPTION_HH_
#define RERSBEXCEPTION_HH_

#include <string>

using std::string;

class RersbException
{
  public:
   RersbException(string msg) {_msg = msg;}
   string getMsg() {return _msg;}

  private:
   string _msg;
};

#endif//RERSBEXCEPTION_HH_
