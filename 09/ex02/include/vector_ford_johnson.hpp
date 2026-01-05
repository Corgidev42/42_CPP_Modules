#ifndef VECTOR_FORD_JOHNSON_HPP
#define VECTOR_FORD_JOHNSON_HPP

#include <vector>
#include <algorithm>

/*
** Type aliases
*/
typedef std::vector<unsigned int> vui;
typedef std::pair<unsigned int, unsigned int> p;
typedef std::vector<p> vpui;

/*
** Extract the winners (max of each pair)
*/
static vui extractWinners(const vui& list)
{
	vui winners;

	for (size_t i = 0; i < list.size(); i += 2) {
		unsigned int first = list[i];

		if (i + 1 == list.size()) {   // Odd number of elements → last one is alone
			winners.push_back(first);
			break;
		}

		unsigned int second = list[i + 1];
		winners.push_back(first > second ? first : second);
	}
	return winners;
}

/*
** Extract the losers (the smallest element of each pair)
** Stored as pairs (loser, winner)
*/
static vpui extractLosers(const vui& list)
{
	vpui losers;

	for (size_t i = 0; i + 1 < list.size(); i += 2) {
		unsigned int first = list[i];
		unsigned int second = list[i + 1];

		unsigned int minv = first < second ? first : second;
		unsigned int maxv = first > second ? first : second;

		losers.push_back(std::make_pair(minv, maxv));
	}
	return losers;
}

/*
** Jacobsthal recurrence: J(n) = J(n-1) + 2*J(n-2)
*/
static unsigned int jacobsthal(unsigned int prev, unsigned int secondPrev)
{
	return prev + 2 * secondPrev;
}

/*
** Insert 'value' to the left of iterator 'it' in 'list'
** (binary-search-like insertion but moving left)
*/
static void insertBackLeft(vui& list, vui::iterator it, unsigned int value)
{
	if (it == list.begin()) {
		list.insert(it, value);
		return;
	}

	// Move left until correct insertion position
	while (it != list.begin() && value < *it)
		--it;

	if (value > *it)
		++it;

	list.insert(it, value);
}

/*
** Insert all losers into the sorted winners list
** following the Ford–Johnson Jacobsthal-based order.
*/
static void insertLosers(vui& winners, const vpui& losers)
{
	unsigned int Jprev = 0;
	unsigned int Jcur  = 1;
	unsigned int Jnext = 0;

	while (Jnext < losers.size()) {
		Jcur = jacobsthal(Jcur, Jprev);

		// Insert losers from index Jcur-1 down to Jnext
		for (unsigned int j = Jcur; j > Jnext; --j) {
			if (j > losers.size())
				j = losers.size();

			p pair = losers[j - 1];

			// Locate the winner to determine insertion range
			vui::iterator it = std::find(winners.begin(), winners.end(), pair.second);

			insertBackLeft(winners, it, pair.first);
		}
		Jprev = Jnext;
		Jnext = Jcur;
	}
}

/*
** Recursive Ford–Johnson (Merge-Insertion) sorting algorithm
*/
static vui fordJohnson(const vui& list)
{
	vui winners = extractWinners(list);
	vpui losers = extractLosers(list);

	// Recursive sorting of winners
	if (winners.size() > 1)
		winners = fordJohnson(winners);

	// Insert losers back into sorted winners
	insertLosers(winners, losers);

	return winners;
}

#endif