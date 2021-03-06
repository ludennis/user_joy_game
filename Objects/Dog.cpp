
#include "Dog.h"

Dog::Dog(){}
Dog::Dog(int y, int x,vector< vector<Object*> >* g,Panel* p): Object('D',4,y,x,g,p){}

void Dog::attack(){
	Object* nearest_wolf = find_nearest_target('W');

	if (nearest_wolf==NULL){return;}
	else {
		if (distance_from(nearest_wolf)==1){
			(*grid)[nearest_wolf->get_y()][nearest_wolf->get_x()] = NULL;
			delete nearest_wolf;
			this->set_done(true);
			this->panel->inc_wolf_eaten();
		}
	}
}

void Dog::move(){
	Object* nearest_wolf = find_nearest_target('W');

	if (nearest_wolf==NULL){Object::move();}
	else {
		this->seek(nearest_wolf);
	}
}

Dog::~Dog(){}