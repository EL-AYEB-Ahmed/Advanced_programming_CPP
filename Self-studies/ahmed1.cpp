#include <iostream>
#include "num.hpp"

struct grid_point{
    num x;
    num y;
    

    grid_point(const num& a, const num& b): x(a), y(b) {}
    grid_point(const grid_point& other_point): x(other_point.x), y(other_point.y){}
    grid_point(): x("0.x",0), y("0.y",0) {}
    
    
    grid_point add(const grid_point& other_point)const {
        fun_scope;
        return {this->x + other_point.x, this->y + other_point.y};
    }
    grid_point sub(const grid_point& other_point)const{
        fun_scope;
        return {this->x - other_point.x, this->y - other_point.y};
    }
    num dot_product(const grid_point& other_point)const{
        fun_scope;
        return {this->x *  other_point.x + this->y * other_point.y};
    }
    static grid_point from_ints (int i , int j){
        return {num("i",i),num("j",j)};
    }
    void raz(){
        this->x=0;
        this->y=0;
    }
    static grid_point zero(){
        return {num("0.x",0),("0.y",0)};
    }
    num distance2(const grid_point& other_point)const{
        fun_scope;
        grid_point temp {this->sub(other_point)};
        return temp.dot_product(temp);
    }
    bool is_equal(const grid_point& other_point)const{
        return {this->x == other_point.x && this->y==other_point.y};
    }
};
std::ostream& operator<<(std::ostream& os, const grid_point& the_one_to_print) {
  os << '(' << the_one_to_print.x << ", " << the_one_to_print.y << ')';
  return os;
}
int main (int argc, char* argv[]){
    fun_scope;
    grid_point a {num("a.x",10),num("a.y",5)};
    grid_point b {-a.y,a.x};   
    ___;
    rem("testing distance");
    num d2 {a.distance2(b)};
    std::cout << scope_indent << "d2(" << a << ", " << b << ") = " << d2 << std::endl;
    ___;
    rem("Testing orthogonality");
    bool ortho (a.dot_product(b) == 0) ;
    std::cout << scope_indent << "Are " << a << " and " << b << " orthogonal ? "
	    << std::boolalpha << ortho
	    << std::endl;
    ___;
    rem("Testing from_ints");
    bool equal = a.is_equal(grid_point::from_ints(10,5));
    std::cout << scope_indent << "This is supposed to be true, is it ? " << std::boolalpha
	    << equal
	    << std::endl;
    ___;
    rem("Testing raz");
    a.raz();
    equal = a.is_equal(grid_point::zero());
    std::cout << scope_indent << "This is supposed to be true, is it ? " << std::boolalpha
	    << equal
	    << std::endl;

}   
