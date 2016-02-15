#ifndef banterbakar_h
#define banterbakar_h

class banterbakar: public drawable, public movingObject{
	public:

	//bila di-attach, akan diset oleh pesawat
	void setX(int x);
	void setY(int y);

	void draw();
	void oneFrameMove();

	private:
	//untuk gambar, lihat empat variabel ini:
	int x; //ini x pusat
	int y; //ini y pusat

	//tambahan untuk gambar
	static const int width = 40;
	static const int height = 40;

	//untuk update
	float rotateSpeed;

	bool attached;

	float bounceelasticity=0.8;

	//hanya relevan bila sudah lepas
	int xSpeed;
	int ySpeed;
	static const int fallaccel = 1;

	//randomisasi
	static std::default_random_engine rd;
	static std::normal_distribution<double> speedRandomGenerator;
	
};

#endif
