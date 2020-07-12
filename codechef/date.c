
/*
	Version 1.12  Gary Katch 1999/1/6.
	fix argc=0 default behaviour.
	*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>

struct sdate {
  long y;
  long m;
  long d;
  };

struct sdate date1;
struct sdate date2;
struct sdate dtest;
struct timeval now, *pnow;
struct tm today, *ptoday;
long offset, g1, g2;
long calstart;   /* Earliest date on Gregorian calendar */
long args[6];
long *i, j;
char *progname;
const char warn1[] = "WARNING: Dates before Oct. 1582 are inaccurate.";

long gday(struct sdate d) {       /* convert date to day number */
  long  y, m;

  m = (d.m + 9)%12;                /* mar=0, feb=11 */
  y = d.y - m/10;                     /* if Jan/Feb, year-- */
  return y*365 + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (d.d - 1);
  }

struct sdate dtf(long d) { /* convert day number to y,m,d format */
  struct sdate pd;
  long y, ddd, mm, dd, mi;

  y = (10000*d + 14780)/3652425;
  ddd = d - (y*365 + y/4 - y/100 + y/400);
  if (ddd < 0) {
    y--;
    ddd = d - (y*365 + y/4 - y/100 + y/400);
    }
  mi = (52 + 100*ddd)/3060;
  pd.y = y + (mi + 2)/12;
  pd.m = (mi + 2)%12 + 1;
  pd.d = ddd - (mi*306 + 5)/10 + 1;
  return pd;
  }

long legald(struct sdate d) {   /* return gday, or exit if bad date */
  struct sdate t;
  long g;

  g = gday(d);
  if (g < calstart) fprintf(stderr,"%s: %s\n", progname, warn1);
  t = dtf(g);
  if (d.y == t.y && d.m == t.m && d.d == t.d) {
    return g;
    }
  else {
    fprintf(stderr,"%s: Illegal date %d %d %d.\n",
            progname, d.y, d.m, d.d);
    exit(2);
    }
  }
  
/* Main */
main(int argc, char *argv[])
{
  progname = argv[0];
  if (argc - 1 > 6) {
    fprintf(stderr,"%s: Too many arguments.\n", progname);
    exit(1);
    }
  i = args;
  j = argc;
  while (--j > 0) { /* Convert args to long integer */
    *i++ = atol(*++argv);
    if (errno != 0) {
      fprintf(stderr,"%s: Argument conversion error.\n",
              progname);
      exit(1);
      }
    }
  i = args;
  date1.y = 1582; date1.m = 10; date1.d =1;
  calstart = gday(date1);
  if (argc - 1 > 3) { /* Command line has base date */
    date1.y = *i++;
    date1.m = *i++;
    date1.d = *i;
    g1 = legald(date1);
    i = args + 3;
    }
  else { /* Use today as base date */
    ptoday = &today;
    gettimeofday(&now;, (struct timezone *)NULL);
    ptoday = localtime(&now.tv;_sec);
    date1.y = ptoday->tm_year + 1900;
    date1.m = ptoday->tm_mon + 1;
    date1.d = ptoday->tm_mday;
    if (argc -1 == 0) {
      printf("%d %d %d\n", date1.y, date1.m, date1.d);
      exit(0);
      }
    g1 = gday(date1);
    }

  if ((argc - 1)%3 == 1) { /* Compute new date from offset */
    date2 = dtf(g1 + *i);
    printf("%d %d %d\n", date2.y, date2.m, date2.d);
    if (g1 + *i > calstart) {
      exit(0);
      }
    else {
      fprintf(stderr, "%s: %s\n", progname, warn1);
      exit(2);
      }
    }
  else if ((argc - 1)%3 == 0) { /* Compute offset between dates */
    date2.y = *i++;
    date2.m = *i++;
    date2.d = *i;
    g2 = legald(date2);
    printf("%d\n", g2 - g1);
    exit(0);
    }
  else { /* Wrong number of arguments */
    fprintf(stderr,"Usage: %s [y m d] [ n | y m d ]\n", progname);
    exit(1);
    }

}