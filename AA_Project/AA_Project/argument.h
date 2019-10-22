#ifndef ARGUMENT_H_
#define ARGUMENT_H_

class argument
{
private:
	int ID;
	bool is_pro;		// PRO = TRUE, CON = FALSE
	float Affect_score;
	float Reason_score;
	float involvement;  // THE GRADE OF INVOLVEMENT THAT REPRESENT THE ARGUMENT (THE VALIDITY??)
	float AR_ratio;		// THE GRADE OF AFFECTIVITY VS REASONS OF AN ARGUMENT GIVEN
	float AFFECT_MIN = 1.0;	float AFFECT_MAX = 7.0;
	float REASON_MIN = 1.0;	float REASON_MAX = 7.0;
	float AR_RATIO_MIN = AFFECT_MIN / REASON_MAX;	float AR_RATIO_MAX = AFFECT_MAX / REASON_MAX;
	float INVOLVEMENT_MIN = (AFFECT_MIN + REASON_MIN) / 2; float INVOLVEMENT_MAX = (AFFECT_MAX + REASON_MAX) / 2;

	void update_values() {
		involvement = (Reason_score + Affect_score) / 2;
		AR_ratio = Affect_score / Reason_score;
	}

public:
	argument() { ID = 1; is_pro = true; Affect_score = 3.0f; Reason_score = 3.0f; AR_ratio = Affect_score / Reason_score; 
				involvement = (Reason_score + Affect_score) / 2;	}
	argument(int Id, bool pro = true, float affect_score = 0.0, float reason_score = 0.0) {
		ID = Id; is_pro = pro; Affect_score = affect_score; Reason_score = reason_score; AR_ratio = affect_score / reason_score;
		involvement = (reason_score + affect_score) / 2;
	}
	~argument() {}

	//SET AND GET FUNCTIONS
	void Set_ID(int Id) { ID = Id; }					    int Get_ID() { return ID; }
	float Set_Affect(float score) { Affect_score = score; update_values(); } float Get_Affect() { return Affect_score; }
	float Set_Reason(float score) {	Reason_score = score; update_values(); } float Get_Reason() { return Affect_score; }
	float Get_involvement() { return involvement; }
	float Get_AR_ratio() { return AR_ratio; }
	void Set_pro(bool pro) { is_pro = pro; }				bool Get_pro() { return is_pro; }
	void set_argument(int Id, bool pro = true, float inv = 50.0f, float ar = 50.0f) {
		ID = Id; is_pro = pro; involvement = inv; AR_ratio = ar;}
	float Get_AR_RATIO_MIN() { return AR_RATIO_MIN; }	float Get_AR_RATIO_MAX() { return AR_RATIO_MAX; }
	float Get_INVOLVEMENT_MIN() { return INVOLVEMENT_MIN; } float Get_INVOLVEMENT_MAX() { return INVOLVEMENT_MAX; }
};

#endif