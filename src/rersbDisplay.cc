/*****************************************************************************/
/* rersbDisplay.cc for rersb                                                 */
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
#include "rersbDisplay.h"

extern "C" {
#include <mrss.h>
#include <ncurses.h>
}

RersbDisplay::RersbDisplay(int y, int x, string url)
{
   _y = y;
   _x = x;
   _url = url;
   _win = newwin(y, x, 0, 0);
   box(_win, 0, 0);
   wrefresh(_win);
   _rssData = NULL;
   _itemCount = 0;
   _index = 0;
}

RersbDisplay::~RersbDisplay()
{
   delwin(_win);

   if(_rssData != NULL)
      mrss_free(&_rssData);
}

void RersbDisplay::writeItems(int startItem)
{
   if(_rssData == NULL)
      refreshRssData();

   int ypos = 1;
   mrss_item_t * item = _rssData->item;
   
   while(item != NULL && ypos < _y) {
      mvwprintw(_win, ypos, 1, "%.*s", _x - 2, item->title);
      ypos++;
      item = item->next;
   }

   _index = 0;
   highlightItem(_index);      

   wrefresh(_win);
}

void RersbDisplay::highlightItem(int index)
{
   if(index >= _itemCount || index < 0)
      return;

   /* erase the line */
   mvwchgat(_win, index + 1, 1, _x - 2, A_REVERSE, 0, NULL);
   wrefresh(_win);
}

void RersbDisplay::dehighlightItem(int index)
{
   if(index >= _itemCount || index < 0)
      return;

   /* erase the line */
   mvwchgat(_win, index + 1, 1, _x - 2, A_NORMAL, 0, NULL);
   wrefresh(_win);
}

void RersbDisplay::moveUp()
{
   if(_index == 0)
      return;

   dehighlightItem(_index--);
   highlightItem(_index);   
}

void RersbDisplay::moveDown()
{
   if(_index == _itemCount - 1)
      return;

   dehighlightItem(_index++);
   highlightItem(_index);
}

void RersbDisplay::refreshRssData()
{
   mrss_error_t rss_err;

   if(_rssData != NULL)
      mrss_free(&_rssData);

   rss_err = mrss_parse_url((char *)_url.c_str(), &_rssData);
   mrss_item_t * item = _rssData->item;

   while(item != NULL) {
      _itemCount++;
      item = item->next;
   }

   /* Todo: error handling */
}
