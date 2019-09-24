#ifndef ARGUMENT_H_
#define ARGUMENT_H_

enum NATURE_SET { ECONOMIC = 1, ECOLOGIC, SOCIAL };

class argument
{
private:
	int nature; 
	bool is_pro; // PRO = TRUE, CON = FALSE
	float strength; // THE STRENGHT OF THE ARGUMENT IN THE FIELD
	float validity;// HOW MUCH AN ARGUMENT IS CONSISTENT

public:
	//argument() { nature = ECONOMIC; is_pro = true; strength = 0.0; validity = 0.0; }
	argument(int NAT = ECONOMIC, bool PRO = true, float STR = 0.0, float VAL = 0.0) { nature = NAT;  is_pro = PRO; 
	strength = STR; validity = VAL; }
	~argument() {}

	//SET AND GET FUNCTIONS
	void Set_nature(int NAT) { nature = NAT; }		  int Get_nature() { return nature; }
	void Set_strength(float STR) { strength = STR; } float Get_strength() { return strength; }
	void Set_validity(float VAL) { validity = VAL; } float Get_validity() { return validity; }
};

#endif // !1