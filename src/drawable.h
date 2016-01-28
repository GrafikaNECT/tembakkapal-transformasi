#ifndef drawable_h
#define drawable_h

class drawable{
	public:
	bool operator<(const drawable& rhs);
	virtual void draw() = 0;

	void setLevel(int _level);
	int getLevel();

	protected:
	int level; //level yang lebih kecil digambar lebih atas
};

#endif
