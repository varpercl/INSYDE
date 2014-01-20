#include "acosolver.h"

ACOSolver::ACOSolver()
{
	TRACE ( printf("INITIALIZE TRIAL\n"); );

	start_timers();
	time_used = elapsed_time( VIRTUAL );
	time_passed = time_used;

//    if (comp_report) {
//        fprintf(comp_report,"seed %ld\n",seed);
//        fflush(comp_report);
//    }
	/* Initialize variables concerning statistics etc. */

	n_tours      = 1;
	iteration    = 1;
	restart_iteration = 1;
	lambda       = 0.05;
	best_so_far_ant->tour_length = INFTY;
	found_best   = 0;

	/* Initialize the Pheromone trails, only if ACS is used, pheromones
	   have to be initialized differently */
	if ( !(acs_flag || mmas_flag || bwas_flag) ) {
		trail_0 = 1. / ( (rho) * nn_tour() );
		/* in the original papers on Ant System, Elitist Ant System, and
		   Rank-based Ant System it is not exactly defined what the
		   initial value of the pheromones is. Here we set it to some
		   small constant, analogously as done in MAX-MIN Ant System.
		*/
		init_pheromone_trails( trail_0 );
	}
	if ( bwas_flag ) {
		trail_0 = 1. / ( (double) n * (double) nn_tour()) ;
		init_pheromone_trails( trail_0 );
	}
	if ( mmas_flag ) {
		trail_max = 1. / ( (rho) * nn_tour() );
		trail_min = trail_max / ( 2. * n );
		init_pheromone_trails( trail_max );
	}
	if ( acs_flag ) {
		trail_0 = 1. / ( (double) n * (double) nn_tour( ) ) ;
		init_pheromone_trails( trail_0 );
	}

	/* Calculate combined information pheromone times heuristic information */
	compute_total_information();

//    if (comp_report) fprintf(comp_report,"begin try %li \n",ntry);
//    if (stat_report) fprintf(stat_report,"begin try %li \n",ntry);
}

void ACOSolver::construct_solutions(void)
{
	/*
		  FUNCTION:       manage the solution construction phase
		  INPUT:          none
		  OUTPUT:         none
		  (SIDE)EFFECTS:  when finished, all ants of the colony have constructed a solution
	*/
	long int k;        /* counter variable */
	long int step;    /* counter of the number of construction steps */

	TRACE ( printf("construct solutions for all ants\n"); );

	/* Mark all cities as unvisited */
	for ( k = 0 ; k < n_ants ; k++) {
		ant_empty_memory( &ant[k] );
	}

	step = 0;
	/* Place the ants on same initial city */
	for ( k = 0 ; k < n_ants ; k++ )
		place_ant( &ant[k], step);

	while ( step < n-1 ) {
		step++;
		for ( k = 0 ; k < n_ants ; k++ ) {
			neighbour_choose_and_move_to_next( &ant[k], step);
			if ( acs_flag )
				local_acs_pheromone_update( &ant[k], step );
		}
	}

	step = n;
	for ( k = 0 ; k < n_ants ; k++ ) {
		ant[k].tour[n] = ant[k].tour[0];
		ant[k].tour_length = compute_tour_length( ant[k].tour );
		if ( acs_flag )
			local_acs_pheromone_update( &ant[k], step );
	}
	n_tours += n_ants;
}

void ACOSolver::ant_empty_memory(Ant *a)
{
	/*
		  FUNCTION:       empty the ants's memory regarding visited cities
		  INPUT:          ant identifier
		  OUTPUT:         none
		  (SIDE)EFFECTS:  vector of visited cities is reinitialized to FALSE
	*/
	long int   i;

	for( i = 0 ; i < n ; i++ ) {
		a->visited[i] = false;
	}
}

void ACOSolver::place_ant(Ant *a, long step)
{
	/*
		  FUNCTION:      place an ant on a randomly chosen initial city
		  INPUT:         pointer to ant and the number of construction steps
		  OUTPUT:        none
		  (SIDE)EFFECT:  ant is put on the chosen city
	*/
	long int     rnd;

	rnd = (long int) (ran01( &seed ) * (double) n); /* random number between 0 .. n-1 */
	a->tour[step] = rnd;
	a->visited[rnd] = true;
}

void ACOSolver::neighbour_choose_and_move_to_next(Ant *a, long phase)
{
	/*
		  FUNCTION:      Choose for an ant probabilistically a next city among all
						 unvisited cities in the current city's candidate list.
						 If this is not possible, choose the closest next
		  INPUT:         pointer to ant the construction step "phase"
		  OUTPUT:        none
		  (SIDE)EFFECT:  ant moves to the chosen city
	*/
	long int i, help;
	long int current_city;
	double   rnd, partial_sum = 0., sum_prob = 0.0;
	/*  double   *prob_of_selection; */ /* stores the selection probabilities
		of the nearest neighbor cities */
	double   *prob_ptr;



	if ( (q_0 > 0.0) && (ran01( &seed ) < q_0)  ) {
		/* with a probability q_0 make the best possible choice
		   according to pheromone trails and heuristic information */
		/* we first check whether q_0 > 0.0, to avoid the very common case
		   of q_0 = 0.0 to have to compute a random number, which is
		   expensive computationally */
		neighbour_choose_best_next(a, phase);
		return;
	}

	prob_ptr = prob_of_selection;

	current_city = a->tour[phase-1]; /* current_city city of ant k */
	DEBUG( assert ( current_city >= 0 && current_city < n ); )
	for ( i = 0 ; i < nn_ants ; i++ ) {
		if ( a->visited[instance.nn_list[current_city][i]] )
			prob_ptr[i] = 0.0;   /* city already visited */
		else {
			DEBUG( assert ( instance.nn_list[current_city][i] >= 0 && instance.nn_list[current_city][i] < n ); )
			prob_ptr[i] = total[current_city][instance.nn_list[current_city][i]];
			sum_prob += prob_ptr[i];
		}
	}

	if (sum_prob <= 0.0) {
		/* All cities from the candidate set are tabu */
		choose_best_next( a, phase );
	}
	else {
		/* at least one neighbor is eligible, chose one according to the
		   selection probabilities */
		rnd = ran01( &seed );
		rnd *= sum_prob;
		i = 0;
		partial_sum = prob_ptr[i];
		/* This loop always stops because prob_ptr[nn_ants] == HUGE_VAL  */
		while (partial_sum <= rnd) {
			i++;
			partial_sum += prob_ptr[i];
		}
		/* This may very rarely happen because of rounding if rnd is
		   close to 1.  */
		if (i == nn_ants) {
			neighbour_choose_best_next(a, phase);
			return;
		}
		DEBUG( assert ( 0 <= i && i < nn_ants); );
		DEBUG( assert ( prob_ptr[i] >= 0.0); );
		help = instance.nn_list[current_city][i];
		DEBUG( assert ( help >= 0 && help < n ); )
		DEBUG( assert ( a->visited[help] == FALSE ); )
		a->tour[phase] = help; /* instance.nn_list[current_city][i]; */
		a->visited[help] = 't';
	}
}

void ACOSolver::local_acs_pheromone_update(Ant *a, long phase)
{
	/*
		  FUNCTION:      removes some pheromone on edge just passed by the ant
		  INPUT:         pointer to ant and number of constr. phase
		  OUTPUT:        none
		  (SIDE)EFFECTS: pheromones of arcs in ant k's tour are increased
		  COMMENTS:      I did not do experiments with with different values of the parameter
						 xi for the local pheromone update; therefore, here xi is fixed to 0.1
						 as suggested by Gambardella and Dorigo for the TSP. If you wish to run
						 experiments with that parameter it may be reasonable to use it as a
						 commandline parameter
	*/
	long int  h, j;

	DEBUG ( assert ( phase > 0 && phase <= n ); )
		j = a->tour[phase];

	h = a->tour[phase-1];
	DEBUG ( assert ( 0 <= j && j < n ); )
		DEBUG ( assert ( 0 <= h && h < n ); )
		/* still additional parameter has to be introduced */
		pheromone[h][j] = (1. - 0.1) * pheromone[h][j] + 0.1 * trail_0;
	pheromone[j][h] = pheromone[h][j];
	total[h][j] = pow(pheromone[h][j], alpha) * pow(HEURISTIC(h,j),beta);
	total[j][h] = total[h][j];
}

long ACOSolver::compute_tour_length(long *t)
{
	/*
		  FUNCTION: compute the tour length of tour t
		  INPUT:    pointer to tour t
		  OUTPUT:   tour length of tour t
	*/
	int      i;
	long int tour_length = 0;

	for ( i = 0 ; i < n ; i++ ) {
		tour_length += instance.distance[t[i]][t[i+1]];
	}
	return tour_length;
}

double ACOSolver::ran01(long *idum)
{
	/*
			  FUNCTION:       generate a random number that is uniformly distributed in [0,1]
			  INPUT:          pointer to variable with the current seed
			  OUTPUT:         random number uniformly distributed in [0,1]
			  (SIDE)EFFECTS:  random number seed is modified (important, this has to be done!)
			  ORIGIN:         numerical recipes in C
	*/

	long k;
	double ans;

	k =(*idum)/IQ;
	*idum = IA * (*idum - k * IQ) - IR * k;
	if (*idum < 0 ) *idum += IM;
	ans = AM * (*idum);
	return ans;

}

void ACOSolver::neighbour_choose_best_next(Ant *a, long phase)
{
	/*
		  FUNCTION:      chooses for an ant as the next city the one with
						 maximal value of heuristic information times pheromone
		  INPUT:         pointer to ant and the construction step "phase"
		  OUTPUT:        none
		  (SIDE)EFFECT:  ant moves to the chosen city
	*/
	long int i, current_city, next_city, help_city;
	double   value_best, help;

	next_city = n;
	DEBUG( assert ( phase > 0 && phase < n ); );
	current_city = a->tour[phase-1];
	DEBUG ( assert ( 0 <= current_city && current_city < n ); )
	value_best = -1.;             /* values in total matix are always >= 0.0 */
	for ( i = 0 ; i < nn_ants ; i++ ) {
		help_city = instance.nn_list[current_city][i];
		if ( a->visited[help_city] )
			;   /* city already visited, do nothing */
		else {
			help = total[current_city][help_city];
			if ( help > value_best ) {
				value_best = help;
				next_city = help_city;
			}
		}
	}
	if ( next_city == n )
		/* all cities in nearest neighbor list were already visited */
		choose_best_next( a, phase );
	else {
		DEBUG( assert ( 0 <= next_city && next_city < n); )
		DEBUG( assert ( value_best > 0.0 ); )
		DEBUG( assert ( a->visited[next_city] == FALSE ); )
		a->tour[phase] = next_city;
		a->visited[next_city] = 't';
	}
}

void ACOSolver::choose_best_next(Ant *a, long phase)
{
	/*
		  FUNCTION:      chooses for an ant as the next city the one with
						 maximal value of heuristic information times pheromone
		  INPUT:         pointer to ant and the construction step
		  OUTPUT:        none
		  (SIDE)EFFECT:  ant moves to the chosen city
	*/
	long int city, current_city, next_city;
	double   value_best;

	next_city = n;
	DEBUG( assert ( phase > 0 && phase < n ); );
	current_city = a->tour[phase-1];
	value_best = -1.;             /* values in total matrix are always >= 0.0 */
	for ( city = 0 ; city < n ; city++ ) {
		if ( a->visited[city] )
			; /* city already visited, do nothing */
		else {
			if ( total[current_city][city] > value_best ) {
				next_city = city;
				value_best = total[current_city][city];
			}
		}
	}
	DEBUG( assert ( 0 <= next_city && next_city < n); );
	DEBUG( assert ( value_best > 0.0 ); )
	DEBUG( assert ( a->visited[next_city] == FALSE ); )
	a->tour[phase] = next_city;
	a->visited[next_city] = 't';
}

void ACOSolver::start_timers()
{
	/*
		  FUNCTION:       virtual and real time of day are computed and stored to
						  allow at later time the computation of the elapsed time
						  (virtual or real)
		  INPUT:          none
		  OUTPUT:         none
		  (SIDE)EFFECTS:  virtual and real time are computed
	*/
	start_time = clock();
}

double ACOSolver::elapsed_time(TIMER_TYPE type)
{
	Q_UNUSED(type);
	/*
		  FUNCTION:       return the time used in seconds (virtual or real, depending on type)
		  INPUT:          TIMER_TYPE (virtual or real time)
		  OUTPUT:         seconds since last call to start_timers (virtual or real)
		  (SIDE)EFFECTS:  none
	*/
	elapsed = clock()- start_time;
	return elapsed / CLOCKS_PER_SEC;
}

long ACOSolver::nn_tour()
{
	/*
		  FUNCTION:       generate some nearest neighbor tour and compute tour length
		  INPUT:          none
		  OUTPUT:         none
		  (SIDE)EFFECTS:  needs ant colony and one statistic ants
	*/
	long int phase, help;

	ant_empty_memory( &ant[0] );

	phase = 0; /* counter of the construction steps */
	place_ant( &ant[0], phase);

	while ( phase < n-1 ) {
		phase++;
		choose_closest_next( &ant[0],phase);
	}
	phase = n;
	ant[0].tour[n] = ant[0].tour[0];
	if ( ls_flag ) {
		two_opt_first( ant[0].tour );
	}
	n_tours += 1;
/*   copy_from_to( &ant[0], best_so_far_ant ); */
	ant[0].tour_length = compute_tour_length( ant[0].tour );

	help = ant[0].tour_length;
	ant_empty_memory( &ant[0] );
	return help;
}

void ACOSolver::init_pheromone_trails(double initial_trail)
{
	/*
		  FUNCTION:      initialize pheromone trails
		  INPUT:         initial value of pheromone trails "initial_trail"
		  OUTPUT:        none
		  (SIDE)EFFECTS: pheromone matrix is reinitialized
	*/
	long int i, j;

	TRACE ( printf(" init trails with %.15f\n",initial_trail); );

	/* Initialize pheromone trails */
	for ( i = 0 ; i < n ; i++ ) {
		for ( j =0 ; j <= i ; j++ ) {
			pheromone[i][j] = initial_trail;
			pheromone[j][i] = initial_trail;
			total[i][j] = initial_trail;
			total[j][i] = initial_trail;
		}
	}
}

void ACOSolver::compute_total_information()
{
	/*
		  FUNCTION: calculates heuristic info times pheromone for each arc
		  INPUT:    none
		  OUTPUT:   none
	*/
	long int     i, j;

	TRACE ( printf("compute total information\n"); );

	for ( i = 0 ; i < n ; i++ ) {
		for ( j = 0 ; j < i ; j++ ) {
			total[i][j] = pow(pheromone[i][j],alpha) * pow(HEURISTIC(i,j),beta);
			total[j][i] = total[i][j];
		}
	}
}

void ACOSolver::choose_closest_next(Ant *a, long phase)
{
	/*
		  FUNCTION:      Chooses for an ant the closest city as the next one
		  INPUT:         pointer to ant and the construction step "phase"
		  OUTPUT:        none
		  (SIDE)EFFECT:  ant moves to the chosen city
	*/
	long int city, current_city, next_city, min_distance;

	next_city = n;
	DEBUG( assert ( phase > 0 && phase < n ); );
	current_city = a->tour[phase-1];
	min_distance = INFTY;             /* Search shortest edge */
	for ( city = 0 ; city < n ; city++ ) {
		if ( a->visited[city] )
			; /* city already visited */
		else {
			if ( instance.distance[current_city][city] < min_distance) {
				next_city = city;
				min_distance = instance.distance[current_city][city];
			}
		}
	}
	DEBUG( assert ( 0 <= next_city && next_city < n); );
	a->tour[phase] = next_city;
	a->visited[next_city] = 't';
}

void ACOSolver::two_opt_first(long *tour)
{
	/*
		  FUNCTION:       2-opt a tour
		  INPUT:          pointer to the tour that undergoes local optimization
		  OUTPUT:         none
		  (SIDE)EFFECTS:  tour is 2-opt
		  COMMENTS:       the neighbourhood is scanned in random order (this need
						  not be the best possible choice). Concerning the speed-ups used
						  here consult, for example, Chapter 8 of
						  Holger H. Hoos and Thomas Stuetzle,
						  Stochastic Local Search---Foundations and Applications,
						  Morgan Kaufmann Publishers, 2004.
						  or some of the papers online available from David S. Johnson.
	*/
	long int c1, c2;             /* cities considered for an exchange */
	long int s_c1, s_c2;         /* successor cities of c1 and c2     */
	long int p_c1, p_c2;         /* predecessor cities of c1 and c2   */
	long int pos_c1, pos_c2;     /* positions of cities c1, c2        */
	long int i, j, h, l;
	long int improvement_flag, improve_node, help, n_improves = 0, n_exchanges=0;
	long int h1=0, h2=0, h3=0, h4=0;
	long int radius;             /* radius of nn-search */
	long int gain = 0;
	long int *random_vector;
	long int *pos;               /* positions of cities in tour */
	long int *dlb;               /* vector containing don't look bits */

	pos = (long int*) malloc(n * sizeof(long int));
	dlb = (long int*) malloc(n * sizeof(long int));
	for ( i = 0 ; i < n ; i++ ) {
		pos[tour[i]] = i;
		dlb[i] = 'f';
	}

	improvement_flag = 't';
	random_vector = generate_random_permutation( n );

	while ( improvement_flag ) {

		improvement_flag = 'f';

		for (l = 0 ; l < n; l++) {

			c1 = random_vector[l];
			DEBUG ( assert ( c1 < n && c1 >= 0); )
				if ( dlb_flag && dlb[c1] )
					continue;
			improve_node = 'f';
			pos_c1 = pos[c1];
			s_c1 = tour[pos_c1+1];
			radius = instance.distance[c1][s_c1];

			/* First search for c1's nearest neighbours, use successor of c1 */
			for ( h = 0 ; h < nn_ls ; h++ ) {
				c2 = instance.nn_list[c1][h]; /* exchange partner, determine its position */
				if ( radius > instance.distance[c1][c2] ) {
					s_c2 = tour[pos[c2]+1];
					gain =  - radius + instance.distance[c1][c2] +
						instance.distance[s_c1][s_c2] - instance.distance[c2][s_c2];
					if ( gain < 0 ) {
						h1 = c1; h2 = s_c1; h3 = c2; h4 = s_c2;
						improve_node = 't';
						goto exchange2opt;
					}
				}
				else
					break;
			}
			/* Search one for next c1's h-nearest neighbours, use predecessor c1 */
			if (pos_c1 > 0)
				p_c1 = tour[pos_c1-1];
			else
				p_c1 = tour[n-1];
			radius = instance.distance[p_c1][c1];
			for ( h = 0 ; h < nn_ls ; h++ ) {
				c2 = instance.nn_list[c1][h];  /* exchange partner, determine its position */
				if ( radius > instance.distance[c1][c2] ) {
					pos_c2 = pos[c2];
					if (pos_c2 > 0)
						p_c2 = tour[pos_c2-1];
					else
						p_c2 = tour[n-1];
					if ( p_c2 == c1 )
						continue;
					if ( p_c1 == c2 )
						continue;
					gain =  - radius + instance.distance[c1][c2] +
						instance.distance[p_c1][p_c2] - instance.distance[p_c2][c2];
					if ( gain < 0 ) {
						h1 = p_c1; h2 = c1; h3 = p_c2; h4 = c2;
						improve_node = 't';
						goto exchange2opt;
					}
				}
				else
					break;
			}
			if (improve_node) {
			exchange2opt:
				n_exchanges++;
				improvement_flag = 't';
				dlb[h1] = 'f'; dlb[h2] = 'f';
				dlb[h3] = 'f'; dlb[h4] = 'f';
				/* Now perform move */
				if ( pos[h3] < pos[h1] ) {
					help = h1; h1 = h3; h3 = help;
					help = h2; h2 = h4; h4 = help;
				}
				if ( pos[h3] - pos[h2] < n / 2 + 1) {
					/* reverse inner part from pos[h2] to pos[h3] */
					i = pos[h2]; j = pos[h3];
					while (i < j) {
						c1 = tour[i];
						c2 = tour[j];
						tour[i] = c2;
						tour[j] = c1;
						pos[c1] = j;
						pos[c2] = i;
						i++; j--;
					}
				}
				else {
					/* reverse outer part from pos[h4] to pos[h1] */
					i = pos[h1]; j = pos[h4];
					if ( j > i )
						help = n - (j - i) + 1;
					else
						help = (i - j) + 1;
					help = help / 2;
					for ( h = 0 ; h < help ; h++ ) {
						c1 = tour[i];
						c2 = tour[j];
						tour[i] = c2;
						tour[j] = c1;
						pos[c1] = j;
						pos[c2] = i;
						i--; j++;
						if ( i < 0 )
							i = n-1;
						if ( j >= n )
							j = 0;
					}
					tour[n] = tour[0];
				}
			} else {
				dlb[c1] = 't';
			}

		}
		if ( improvement_flag ) {
			n_improves++;
		}
	}
	free( random_vector );
	free( dlb );
	free( pos );
}

long *ACOSolver::generate_random_permutation(long n)
{
	/*
		  FUNCTION:       generate a random permutation of the integers 0 .. n-1
		  INPUT:          length of the array
		  OUTPUT:         pointer to the random permutation
		  (SIDE)EFFECTS:  the array holding the random permutation is allocated in this
						  function. Don't forget to free again the memory!
		  COMMENTS:       only needed by the local search procedures
	*/
	long int  i, help, node, tot_assigned = 0;
	double    rnd;
	long int  *r;

	r = (long int*) malloc(n * sizeof(long int));

	for ( i = 0 ; i < n; i++)
		r[i] = i;

	for ( i = 0 ; i < n ; i++ ) {
		/* find (randomly) an index for a free unit */
		rnd  = ran01 ( &seed );
		node = (long int) (rnd  * (n - tot_assigned));
		assert( i + node < n );
		help = r[i];
		r[i] = r[i+node];
		r[i+node] = help;
		tot_assigned++;
	}
	return r;
}
