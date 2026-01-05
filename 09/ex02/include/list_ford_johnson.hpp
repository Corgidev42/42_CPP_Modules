#ifndef LIST_FORD_JOHNSON_HPP
#define LIST_FORD_JOHNSON_HPP

#include <list>
#include <algorithm>

/*
** Type aliases
*/
typedef std::list<unsigned int> lui;
typedef std::pair<unsigned int, unsigned int> p;
typedef std::list<p> lpui;

/*
** Extract winners (max of each pair)
*/
static lui extractWinners(const lui& lst)
{
	lui winners;
	lui::const_iterator it = lst.begin();

	while (it != lst.end()) {
		unsigned int first = *it;
		++it;

		if (it == lst.end()) {          // Odd total count → last alone
			winners.push_back(first);
			break;
		}

		unsigned int second = *it;
		++it;

		winners.push_back(first > second ? first : second);
	}
	return winners;
}

/*
** Extract losers (min of each pair)
** Stored as (loser, winner)
*/
static lpui extractLosers(const lui& lst)
{
	lpui losers;
	lui::const_iterator it = lst.begin();

	while (it != lst.end()) {
		unsigned int first = *it;
		++it;

		if (it == lst.end())
			break;

		unsigned int second = *it;
		++it;

		unsigned int minv = first < second ? first : second;
		unsigned int maxv = first > second ? first : second;

		losers.push_back(std::make_pair(minv, maxv));
	}
	return losers;
}

/*
** Jacobsthal number: J(n) = J(n-1) + 2*J(n-2)
*/
static unsigned int ljacobsthal(unsigned int prev, unsigned int prev2)
{
	return prev + 2 * prev2;
}

/*
** Insert value into a std::list to the LEFT of iterator 'pos'
** Searching left while value < *pos
*/
static void insertBackLeft(lui& lst, lui::iterator pos, unsigned int value)
{
	if (pos == lst.begin()) {
		lst.insert(pos, value);
		return;
	}

	lui::iterator it = pos;

	// Move left as long as value should go before the current element
	do {
		if (value >= *it)
			break;
		if (it == lst.begin())
			break;
		--it;
	} while (true);

	if (value > *it)  // Insert *after* it
		++it;

	lst.insert(it, value);
}

/*
** Insert losers back into the sorted winners list
** using the Jacobsthal indexing (Ford–Johnson logic)
*/
static void insertLosers(lui& winners, const lpui& losers)
{
	unsigned int Jprev = 0;
	unsigned int Jcur  = 1;
	unsigned int Jnext = 0;

	while (Jnext < losers.size()) {
		Jcur = ljacobsthal(Jcur, Jprev);

		// Bound Jcur to losers.size()
		if (Jcur > losers.size())
			Jcur = losers.size();

		// Insert losers from index Jcur-1 down to Jnext
		lpui::const_iterator start = losers.begin();
		std::advance(start, Jcur);

		lpui::const_iterator it = start;
		for (unsigned int j = Jcur; j > Jnext; --j) {
			--it;

			lpui::const_iterator loserIt = it;
			p element = *loserIt;

			// Locate winner in sorted list
			lui::iterator wpos = std::find(winners.begin(), winners.end(), element.second);

			if (wpos == winners.end())
				continue;

			insertBackLeft(winners, wpos, element.first);
		}

		Jprev = Jnext;
		Jnext = Jcur;
	}
}

/*
** Ford–Johnson recursive merge-insertion sort for std::list
*/
static lui fordJohnson(const lui& lst)
{
	if (lst.size() <= 1)
		return lst;

	// Split into winners and losers
	lui winners = extractWinners(lst);
	lpui losers = extractLosers(lst);

	// Recursively sort winners
	if (winners.size() > 1)
		winners = fordJohnson(winners);

	// Merge losers back in optimal order
	insertLosers(winners, losers);

	return winners;
}

#endif // LIST_FORD_JOHNSON_HPP