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
#include <mrss.h>
}

#include <getopt.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

static char short_opts[] = "hv";
static struct option long_options[] = 
{
   {"help", no_argument, 0, 'h'},
   {"version", no_argument, 0, 'v'},
   {0,0,0,0}
};

const string VERSION = "0.1";
const string AUTHORS = "Thomas Hartman, Tim Stella";

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
   
   if(url != "")
      cout << "Rersb called with url string " << url << endl;
   
   return 0;
}
