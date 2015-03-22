#include <boost/shared_ptr.hpp> 
#include <memory>
#include <iostream>
class RemoveOnDelete {
  public:
    RemoveOnDelete(){};
    void operator() (int *x) {
    	std::cout << "delete " << *x << std::endl;
    }
}; // 起到delete的作用

typedef boost::shared_ptr<int> vint;

vint create_inter(int x)
{
	return vint(new int(x), RemoveOnDelete());
}
int main()  
{      
	for (int t = 0; t<10; t++) {
		vint v = create_inter(t);
	}
}
