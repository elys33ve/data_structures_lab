#include <iostream>

using namespace std;

/*
not part of lab stuff -- just random related tests
ill delete this later
*/


class One{
	private:
		int num;

	public:
		One(){};
		One(int x){
			num = x;
		};
		int get_num(){
			return num;
		};
};

class Two{
	private:
		
		int n_arr;
	public:
		One arr[10];
		Two(){ n_arr = 0; };
		void add_arr(One obj){
			if (n_arr < 10){
				arr[n_arr] = obj;
				n_arr += 1;
			}
		}
		
};




int main(){
	One o1(1);
	One o2(2);
	One o3(3);

	Two two;
	two.add_arr(o1);

	One t = two.arr[0];
	cout << t.get_num() << endl;


	return 0;
}



/*

void Shelf::remove_movie(Movie obj){
	std::string title = obj.get_title();
	std::string credits = obj.get_credits();

	for (int i=0; i<num_movies; i++){
		if ((title == movies[i].get_title()) && (credits == movies[i].get_credits())){
			for (int j=i; j<num_movies-1; i++){
				movies[i] = movies[i+1];
			}
		}
	}
	num_movies -= 1;
}


*/