#ifndef drawable_h
#define drawable_h

class drawable{
	public:
	bool operator<(const drawable& rhs);
	virtual void draw();

	protected:
	int level; //level yang lebih kecil digambar lebih atas
};

#endif
