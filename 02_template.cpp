#include<iostream>
using namespace std;
// CLASS TEMPLATES
class point{};
template<class type>
class Vector{
   public:
      type* v;
      int size;
   Vector();
   template<class V>
   void outlinePrint(V n);
   //template function inside the class template 
   template<class v = double>
   void print2(v v1 = 'c'){
      // v v1 = 65;
      cout<<"i am print 2\tv1 = "<<v1<<endl;
   }

};
template<class type>
Vector<type>::Vector(){
      cout<<"constructor of vector\n";
}
// outline template function 
template<class type>
template<class V>
void Vector<type>::outlinePrint(V n){
   cout<<"i am outline print function\t value is ="<<n<<endl;;
}

int main(){
   Vector<int> v;
   Vector <point> v2;
   // v2.print<int,char>();
   // v2.print2('d');

   v2.outlinePrint<char>(65);
}