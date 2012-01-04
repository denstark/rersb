#ifndef RSSITEM_H
#define RSSITEM_H

#include <string>
#include <ctime>

using std::string;

class RssItem 
{
	public:

	 RssItem(string title, string link, t_time pubDate, string description);
			
	 string getTitle();
	 void setTitle(string title);

	 string getLink();
	 void setLink(string link);

	 t_time getPubDate();
	 void setPubDate(t_time pubDate);

	 string getDescription();
	 void setDescription(string description);

	private:
	 string _title;
	 string _link;
	 t_time _pubDate;
	 string _description;
};

#endif//RSSITEM_H
