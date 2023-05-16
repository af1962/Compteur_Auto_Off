#include "Arduino.h"
class Heures
{
private:
	uint8_t minutes;
	uint8_t secondes;
	char minSec[5];
public:
	String Affiche(int temps);
};
