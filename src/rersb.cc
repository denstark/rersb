/*****************************************************************************/
/* rersb.cc for rersb                                                        */
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
extern "C" {
#include <ncurses.h>
}

#include <getopt.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include "rersbDisplay.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

static char short_opts[] = "hv";
static struct option long_options[] = 
{
   {"help", no_argument, 0, 'h'},
   {"version", no_argument, 0, 'v'},
   {0,0,0,0}
};

const string VERSION = "0.1";
const string AUTHORS = "Thomas Hartman, Tim Stella";
const int DLG_XPAD = 2;
const int DLG_YPAD = 1;

void printHelp()
{
   cout << "rersb: reddit ncurses rss browser" << endl;
   cout << "Usage: rersb -[v,h] --[version,help] [url]" << endl;
   cout << "\t-h, --help" << endl;
   cout << "\t\tPrint this help message." << endl;
   cout << "\t-v, --version" << endl;
   cout << "\t\tPrint version information." << endl;
}

void printVersion()
{
   cout << "rersb v. " << VERSION << endl;
   cout << "Copyright (c) 2012 " << AUTHORS << endl;
}

string getString(string msg)
{
   int x, y;
   getmaxyx(stdscr, y, x);

   int dlgWidth = x / 3;
   int dlgHeight = ceil((double(msg.size()) / (double(dlgWidth - DLG_XPAD*2))) + 
			DLG_YPAD*4);
   WINDOW * dlg = newwin(dlgHeight, dlgWidth, (y / 2) - (dlgHeight / 2), 
			 (x / 2) - (dlgWidth / 2));
   wbkgd(dlg, COLOR_PAIR(2));
   box(dlg, 0, 0);
   wrefresh(dlg);

   int i = 0;
   int len = 0;
   int maxStrLen = dlgWidth - DLG_XPAD*2;
   vector<string> parts;

   while(i < (msg.size() - 1)) {
      len = (i + maxStrLen < (msg.size() - 1) ? maxStrLen : msg.size() - 1 - i);
      parts.push_back(msg.substr(i, len));
      i += len;
   }

   for(i = 0; i < parts.size(); ++i)
      mvwprintw(dlg, DLG_YPAD + i, DLG_XPAD, parts[i].c_str());
   wrefresh(dlg);
   
   wmove(dlg, dlgHeight - DLG_YPAD*2, DLG_XPAD);

   int c;
   string retval;
   bool loop = true;
   while(loop) {
      c = wgetch(dlg);
      
      if(c == KEY_ENTER)
	 loop = false;
      else if(c == 27) {
	 retval = "";
	 loop = false;
      }else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '/' || 
	       c == ':' || c == '.') {
	 retval += char(c);
      }
   }

   delwin(dlg);
   return retval;
}

int eventLoop(string url)
{
   initscr();
   // Sets the cursor to invisible
   curs_set(0);
   start_color();
   init_pair(1, COLOR_BLACK, COLOR_WHITE);
   init_pair(2, COLOR_BLACK, COLOR_YELLOW);

   cbreak();
   keypad(stdscr, TRUE);
   
   refresh();

   {
      int x, y;
      getmaxyx(stdscr, y, x);

      RersbDisplay rersbDisplay(y, x, url);
      rersbDisplay.printItems();
   
      int ch;
      while((ch = getch()) != 'q') {
	 switch(ch) {
	    case KEY_UP:
	       rersbDisplay.moveUp();
	       break;
	    case KEY_DOWN:
	       rersbDisplay.moveDown();
	       break;
	    case 'g':
	       url = getString("Please enter rss url:");
	       refresh();
	       //rersbDisplay.setUrl(url);
	       break;
	    default:
	       break;
	 }
      }
   }

   endwin();

   return 0;
}

int main(int argc, char ** argv)
{
   int opt = 0, option_index = 0;
   string url;
   
   /* Parse cli arguments */
   while((opt = getopt_long(argc, argv, short_opts, long_options, 
			    &option_index)) != -1) {
      switch(opt) {
	 case 'h':
	    printHelp();
	    return 0;
	    
	 case 'v':
	    printVersion();
	    return 0;
	    
	 default:
	    cout << "Unknown option '" << char(opt) << "'." << endl;
	    cout << endl;
	    printHelp();
	    return -1;
      }			
   }
   
   if(optind == (argc - 1))
      url = argv[optind];
   else if(optind > (argc - 1)) {
      cout << "Too many arguments." << endl << endl;
      printHelp();
      return -1;
   }	 	 
   
   return eventLoop(url);  
}
