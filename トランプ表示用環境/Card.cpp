#include "Card.h"
#include <numeric>
#include <algorithm>
Card::Card()
{
	iota(hand.begin(), hand.end(), 1); // 1`13 ‚Ü‚Å‚Ì’l‚ğ¶¬
}
