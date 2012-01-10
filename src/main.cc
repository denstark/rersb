extern "C" {
#include <mrss.h>
}

int main(int argc, char ** argv)
{
	 mrss_t * rss_feed = 0;
	 mrss_error_t rss_err;

	 /* basic cli arg parsing */
	 if(argc != 2)
			return -1;

	 rss_err = mrss_parse_url(argv[1], &rss_feed);

	 mrss_free(&rss_feed);

	 return 0;
}
