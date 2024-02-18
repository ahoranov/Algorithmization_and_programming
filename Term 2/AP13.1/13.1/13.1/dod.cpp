#include "dod.h"
#include "var.h" 

using namespace nsVar;

void nsDod::dod() {
	double R = x * x * (2 * n - 1) / (2 * n + 1);
	a *= R;
}