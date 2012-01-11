/*****************************************************************************/
/* rersbDisplay.h for rersb                                                  */
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
#ifndef RERSBDISPLAY_HH_
#define RERSBDISPLAY_HH_

#include <string>
extern "C" {
#include <ncurses.h>
}

using std::string;
struct mrss_t;

class RersbDisplay
{  
  public:
   RersbDisplay(int y, int x, string url);
   ~RersbDisplay();

   void writeItems(int startItem = 0);
   void highlightItem(int index);
   void dehighlightItem(int index);
   void moveUp();
   void moveDown();
   void refreshRssData();

  private:
   WINDOW * _win;
   mrss_t * _rssData;
   string _url;
   int _y;
   int _x;
   int _itemCount;
   int _index;
};

#endif//RERSBDISPLAY_HH_
