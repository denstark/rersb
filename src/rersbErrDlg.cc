/*****************************************************************************/ 
/* rersbErrDlg.cc for rersb                                                  */ 
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

#include "rersbErrDlg.h"

extern "C" {
#include <ncurses.h>
}

RersbErrDlg::RersbErrDlg(string errMsg)
{
  _errMsg = errMsg;
  _errWin = newwin(10,30,LINES / 2, COLS / 2);
  box(_errWin, 0, 0);
}

RersbErrDlg::~RersbErrDlg() 
{
  delwin(_errWin);
}

void RersbErrDlg::showErr() 
{
  wprintw(_errWin, _errMsg.c_str());
  wrefresh(_errWin);
}
