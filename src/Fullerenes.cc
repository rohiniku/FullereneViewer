/*
 * Project: FullereneViewer
 * Version: 1.0
 * Copyright: (C) 2011-14 Dr.Sc.KAWAMOTO,Takuji (Ext)
 * Create: 2012/01/18 00:37:23 JST
 */

#include "Fullerenes.h"
#include "Generator.h"
#include "CarbonAllotrope.h"
#include "Representations.h"
#include "Debug.h"
#include "DebugMemory.h"

Fullerenes::Fullerenes(const char* generator_label, int maximum_number_of_carbons,
                       bool symmetric, int maximum_vertices_of_polygons)
{
  Fullerene::s_need_representations = true;
  Generator gen = (generator_label ?
                   Generator(generator_label, maximum_vertices_of_polygons) :
                   Generator(symmetric, maximum_vertices_of_polygons));
  char buffer[1024];
  CarbonAllotrope* ca = new CarbonAllotrope();
  ca->make_symmetric_scrap(gen.scrap_no());
#ifdef DEBUG_ERRORS
  printf("* START ****************************************\n");
#endif
#ifdef DEBUG_CARBON_ALLOTROPE_CONSTRUCTION
  ca->print_detail();
#endif
  while (1)
    {
      int No = gen.glow();
      int num;
      ErrorCode result;
      if (symmetric)
        result =
          ca->fill_n_polygons_around_carbons_closed_to_center_and_pentagons(No, num);
      else
        result = ca->fill_n_polygon_around_oldest_carbon(No);
#ifdef DEBUG_CARBON_ALLOTROPE_CONSTRUCTION
      ca->print_detail();
#endif
      int number_of_carbons = ca->number_of_carbons();
      List<Carbon> boundary;
      ca->list_boundary_carbons(boundary);
      int number_of_carbons_in_boundary = boundary.length();
      if ((result != ERROR_CODE_OK) ||
          (number_of_carbons_in_boundary == 0) ||
          (number_of_carbons > maximum_number_of_carbons))
        {
#ifdef DEBUG_ERRORS
          printf("************************************************\n");
#endif
          gen.get_generator_label(buffer, 1024);
          if ((result == ERROR_CODE_OK) &&
              (number_of_carbons_in_boundary == 0))
            {
#ifdef DEBUG_ERRORS
              printf("* OK generated pattern = C%d %s\n",
                     ca->number_of_carbons(), buffer);
              printf("************************************************\n");
#endif
              Fullerene* fullerene = new Fullerene();
              fullerene->set_carbon_allotrope(ca);
              fullerene->set_generator_label(buffer);
              add_fullerene(fullerene);
            }
          else if (result != ERROR_CODE_OK)
            {
#ifdef DEBUG_ERRORS
              printf("* ERROR %s ", buffer);
              error_handler(result);
              printf("************************************************\n");
#endif
              delete ca;
            }
          else if (number_of_carbons > maximum_number_of_carbons)
            {
#ifdef DEBUG_ERRORS
              printf("* ERROR %s Too many carbons %d\n", buffer, number_of_carbons);
              printf("************************************************\n");
#endif
              delete ca;
            }
          else
            {
#ifdef DEBUG_ERRORS
              printf("* ERROR %s Unknown error\n", buffer);
              printf("************************************************\n");
#endif
              delete ca;
            }
          if (!gen.next_pattern())
            return;
          ca = new CarbonAllotrope();
          ca->make_symmetric_scrap(gen.scrap_no());
#ifdef DEBUG_ERRORS
          printf("* START ****************************************\n");
#endif
#ifdef DEBUG_CARBON_ALLOTROPE_CONSTRUCTION
          ca->print_detail();
#endif
        }
    }
}

Fullerenes::~Fullerenes()
{
}

void Fullerenes::add_fullerene(Fullerene* pat)
{
  int len = p_patterns.length();
  for (int i = 0; i < len; ++i)
    {
      Fullerene* pati = p_patterns[i];
      if ((*pat) == (*pati))
        {
#ifdef DEBUG_ERRORS
          printf("************************************************\n");
          printf("* NG same pattern = C%d(number of automorphisms=%d) %s\n",
                 pat->get_carbon_allotrope()->number_of_carbons(),
                 pat->get_representations()->number_of_automorphisms(),
                 pat->get_generator_label());
          printf("*    with pattern = C%d(number of automorphisms=%d) %s\n",
                 pati->get_carbon_allotrope()->number_of_carbons(),
                 pati->get_representations()->number_of_automorphisms(),
                 pati->get_generator_label());
          printf("************************************************\n");
#endif
          delete pat;
          return;
        }
    }
#ifdef DEBUG_ERRORS
  printf("************************************************\n");
  printf("* OK different pattern = C%d (number of automorphisms=%d) %s\n",
         pat->get_carbon_allotrope()->number_of_carbons(),
         pat->get_representations()->number_of_automorphisms(),
         pat->get_generator_label());
  printf("************************************************\n");
#else
  printf("C%d (NoA=%d) %s\n",
         pat->get_carbon_allotrope()->number_of_carbons(),
         pat->get_representations()->number_of_automorphisms(),
         pat->get_generator_label());
#endif
  p_patterns.add(pat);
}

/* Local Variables:	*/
/* mode: c++		*/
/* End:			*/
