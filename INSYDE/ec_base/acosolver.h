#ifndef ACOSOLVER_H
#define ACOSOLVER_H

#include "ECFramework_global.h"
#include <QtCore>
#include <time.h>
#include <assert.h>
#include "ant.h"

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876
#define INFTY                 LONG_MAX

#define HEURISTIC(m,n)     (1.0 / ((double) instance.distance[m][n] + 0.1))

#define DEBUG( x )

#define TRACE( x )

#define LINE_BUF_LEN 50

/*!
 * \brief The ec_base namespace stores a variety of classes to perform Emergent Computing algorithms
 * like Ant Colony Optimization, multiagent system, Particle Swarm Optimization and much more.
 *
 * \author Edixon V
 * \date 12/01/17
 */
namespace ec_base{

typedef enum type_timer {REAL, VIRTUAL} TIMER_TYPE;

class ECFRAMEWORKSHARED_EXPORT Problem{
	public:
		char name[LINE_BUF_LEN];      	 /* instance name */
		char edge_weight_type[LINE_BUF_LEN];  /* selfexplanatory */
		long int optimum;                /* optimal tour length if known, otherwise a bound */
		long int n;                      /* number of cities */
		long int n_near;                 /* number of nearest neighbors */
		QPointF *nodeptr;               /* array of structs containing coordinates of nodes */
		long int **distance;	        /* distance matrix: distance[i][j] gives distance
										   between city i und j */
		long int **nn_list;              /* nearest neighbor list; contains for each node i a
										   sorted list of n_near nearest neighbors */
};

class ACOSolver
{

		long int nn_ls;

		long int dlb_flag;

		long int ls_flag;

		double   trail_max;       /* maximum pheromone trail in MMAS */
		double   trail_min;       /* minimum pheromone trail in MMAS */
		double rho;           /* parameter for evaporation */
		long int mmas_flag;   /* = 1, run MAX-MIN ant system */
		long int bwas_flag;   /* = 1, run best-worst ant system */
		double   time_used;    /* time used until some given event */
		double   time_passed;  /* time passed until some moment*/


		clock_t start_time;
		double elapsed;


		long int found_best;         /* iteration in which best solution is found */
		Ant *best_so_far_ant;   /* struct that contains the best-so-far ant */
		double   lambda;       /* Parameter to determine branching factor */
		long int iteration;    /* iteration counter */
		long int restart_iteration;    /* iteration counter */
		double beta;          /* importance of heuristic evaluate */
		double alpha;         /* importance of trail */
		double   trail_0;         /* initial pheromone trail level in ACS  and BWAS */
		double   **pheromone; /* pheromone matrix, one entry for each arc */
		Problem instance;

		double   **total;     /* combination of pheromone times heuristic information */
		long int nn_ants;     /* length of nearest neighbor lists for the ants'
										solution construction */
		double   *prob_of_selection;
		double q_0;           /* probability of best choice in tour construction */
		long int seed;
		long int n_tours;      /* number of constructed tours */
		long int acs_flag;    /* = 1, run ant colony system */
		int n;              /* number of cities in the instance to be solved */
		long int n_ants;    /* number of ants */
		Ant *ant;           /* this (array of) struct will hold the colony */

	public:
		explicit ACOSolver();

		/**
		  Esta funcion da inicio a la fase de construccion de las soluciones

		  */
		void construct_solutions( void );

		/**
		  Inicializa una hormiga indicando que ningun nodo ha sido visitado
		  Esto quiere decir, a un estado inicial.

		  @param[in] a Puntero a la hormiga que se quiere inicializar

		  */
		void ant_empty_memory( Ant *a );

		/**
		  Coloca una hormiga en una ciudad aleatoriamente

		  @param[in] a Puntero a la hormiga que se desea posicionar
		  @param step Numero de pasos para construir el camino
		  */
		void place_ant( Ant *a , long int step );

		/**
		  Selecciona y mueve la hormiga al proximo nodo vecino basandose en
		  la probabilidad de visitar ese nodo.

		  @param[in] a Puntero a la hormiga que se movera
		  @param phase Paso actual en la fase de construccion
		  */
		void neighbour_choose_and_move_to_next( Ant *a , long phase );

		/**
		  Elimina parte de las feromonas en la arista por la cual acaba de pasar la hormiga

		  @param[in] a Puntero a la hormiga que hara la actualizacion
		  @param phase Fase en la que se encuentra la construccion
		  */
		void local_acs_pheromone_update( Ant *a, long int phase );

		/**
		  Calcula la longitud de un tour basandose en las distancias de los vertices @code{t}

		  @param[in] t Puntero al tour que se calculara
		  */
		long int compute_tour_length( long int *t );

		double ran01( long *idum );

		void neighbour_choose_best_next( Ant *a, long int phase );

		/*!
		 * \brief Select the best next vertice for the current ant.
		 *
		 * \param[in] a A pointer to the current ant.
		 * \param phase
		 */
		void choose_best_next( Ant *a, long int phase );

		void start_timers(void);

		double elapsed_time(TIMER_TYPE type);

		long int nn_tour( void );

		void init_pheromone_trails( double initial_trail );

		void compute_total_information( void );

		void choose_closest_next( Ant *a, long int phase );

		void two_opt_first( long int *tour );

		long int * generate_random_permutation( long int n );


};
}
#endif // ACOSOLVER_H
