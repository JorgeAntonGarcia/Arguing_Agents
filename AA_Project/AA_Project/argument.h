#ifndef ARGUMENT_H_
#define ARGUMENT_H_

class argument
{
private:
	int ID;
	bool is_pro;		// PRO = TRUE, CON = FALSE
	float involvement;  // THE GRADE OF INVOLVEMENT THAT REPRESENT THE ARGUMENT (THE VALIDITY??)
	float AR_ratio;		// THE GRADE OF AFFECTIVITY VS REASONS OF AN ARGUMENT GIVEN

public:
	argument() { ID = 1; is_pro = true; involvement = 50.0f; AR_ratio = 50.0f; }
	argument(int Id, bool pro = true, float inv = 0.0, float ar = 0.0) {
		ID = Id; is_pro = pro; involvement = inv; AR_ratio = ar; }
	~argument() {}

	//SET AND GET FUNCTIONS
	void Set_ID(int Id) { ID = Id; }					    int Get_ID() { return ID; }
	void Set_involvement(float inv) { involvement = inv; }	float Get_involvement() { return involvement; }
	void Set_AR_ratio(float ar) { AR_ratio = ar; }			float Get_AR_ratio() { return AR_ratio; }
	void Set_pro(bool pro) { is_pro = pro; }				bool Get_pro() { return is_pro; }
	void set_argument(int Id, bool pro = true, float inv = 50.0f, float ar = 50.0f) {
		ID = Id; is_pro = pro; involvement = inv; AR_ratio = ar;}
};

#endif