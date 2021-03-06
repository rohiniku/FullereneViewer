/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2012/02/05 20:29:25 JST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <new>
#include "Version.h"
#include "List.h"
#include "Fullerene.h"
#include "DebugMemory.h"

void usage(char* argv0)
{
  fprintf(stderr, "usage: %s < infile > outfile\n", argv0);
  exit(1);
}

int main(int argc, char* argv[])
{
  if ((argc == 2) &&
      ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)))
    {
      print_version("ca-uniq Ver 1.0");
      exit(0);
    }
  if (argc != 1)
    usage(argv[0]);
  setvbuf(stdout, 0, _IONBF, 0);
  {
    List<Fullerene> patterns;
    try
      {
        while (1)
          {
            char buffer[1024];
            if (fgets(buffer, 1024, stdin) != buffer)
              break;
            buffer[strlen(buffer) - 1] = '\0';
            const char* name = buffer + 1;
            while (*name != ' ')
              ++name;
            ++name;
            while (*name != ' ')
              ++name;
            ++name;
            Fullerene* fullerene = new Fullerene(name);
            int len = patterns.length();
            int i = 0;
            while (1)
              {
                if (i == len)
                  {
                    printf("%s\n", buffer);
                    patterns.add(fullerene);
                    break;
                  }
                Fullerene* pati = patterns[i];
                if ((*fullerene) == (*pati))
                  {
                    delete fullerene;
                    break;
                  }
                ++i;
              }
          }
      }
    catch (const std::bad_alloc& err)
      {
        printf("std::bad_alloc exception\n");
        exit(10);
      }
    catch (...)
      {
        printf("unknown exception\n");
        exit(11);
      }
  }
  return 0;
}

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
