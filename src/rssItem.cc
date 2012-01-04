#include "rssItem.h"

RssItem::RssItem(string title, string link, t_time pubDate, string description)
{
	 _title = title;
	 _link = link;
	 _pubDate = pubDate;
	 _description = description;
}

string RssItem::getTitle()
{
	 return _title;
}

void RssItem::setTitle(string title)
{
	 _title = title;
}

string RssItem::getLink()
{
	 return _link;
}

void RssItem::setLink(string link)
{
	 _link = link;
}

t_time RssItem::getPubDate()
{
	 return _pubDate;
}

void RssItem::setPubDate(t_time pubDate)
{
	 _pubDate = pubDate;
}

string RssItem::getDescription()
{
	 return _description;
}

void RssItem::setDescription(string description)
{
	 _description = description;
}
