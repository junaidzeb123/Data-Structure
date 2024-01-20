#include<iostream>
#include<cstring>
using namespace std;
template <class type>
type makeDouble (type  no){
    return no*no;
     
}

template <class type>       // will cause an error if we did't define new template for this hello();
type hello( type no){
    return no;
}

template <typename type>
int MakeFun(int s = 0){
    type t;
    return t;

}



// this is an error  b/c if  we need such funtion we have to defined both template in one template
// template <typename u>
// template <typename t>
// int fun(u n1, t n2){

// }

template<typename t1, typename t2>
int fun(t1 n1, t2 n2){

    return 0;
}

//user specified templates 
//sometiems the template functin did't works for all dataype, in this case we make user specified templates as below.
// 

template<class type>
bool isequal(type t1,type t2){
    cout<<"for template ";
    return t1 == t2;
} 
template<>
bool isequal(int n1,int n2){
    cout<<"for intergers\n";
    return n1 == n2;        
}
template<class type>
bool isequal(const char*t1,const char*t2){
        cout<<"for string ";
       return strcmp(t1,t2) == 0;

}

template<class type>
type sum(type t1 , type t2){
    cout<<"general function ";
    return t1 + t2;
}
template<>
const char* sum(const char* t1, const char* t2) {
    // Calculate the length needed for the concatenated C-style string
    size_t len1 = strlen(t1);
    size_t len2 = strlen(t2);
    char* result = new char[len1 + len2 + 1]; // +1 for the null terminator

    strcpy(result, t1); // Copy the first string
    strcat(result, t2); // Concatenate the second string
    cout<<"for string\n";
    return result; // Return the dynamically allocated C-style string
}
 

// FOR DOUBLE TEMPLATE PORTION
/* if we need two different templates*/
//  errer

// template<class t1>
// template<class t2>
// void print(t1 n1, t2 n2){
//     cout<<n1<<endl;
//     cout<<n2<<endl;
// }

template <class t1 ,typename t2>
void print(t1 n1, t2 n2){
    cout<<"first no\t "<<n1<<endl;
    cout<<"second no\t "<<n2<<endl;
}

//
template<class U, class V>
U fun2(V var){
    cout<<var<<endl;
    cout<<U(var)<<endl;
    return U(var);
}

template<class U, class V>
void fun3(V var){
    cout<<typeid(V).name();
    cout<<typeid(U).name();
    cout<<var<<endl;

}


// TEMPLATE FOR USER DEFINIED DATA TYPES
// class Point{
//     public:
//     int x, y;        //isSame will caue an error b/c == is not overloaded
//     Point(int x = 0 , int  y = 0 ){
//         this->x = x;
//         this->y = y;
//     }
// };

class Point{
    public:
    int x, y;        
    Point(int x = 0 , int  y = 0 ){
        this->x = x;
        this->y = y;
    }
    bool operator==(const Point&p){
        return this->x == p.x && this->y == p.y;
    }
};

template<class t1,class t2>
bool isSame(t1 p1, t2 p2){
    return p1 == p2;
}


int main(){
 
    // cout<<makeDouble(3)<<"\n";
    // cout<<makeDouble<int>(3)<<"\n"; // same as above
    // cout<<makeDouble('d');    // will run 
    // cout<<makeDouble("d");     // error

    // cout<<MakeFun<int>();
    // fun(2,2);

    // USER SPECIFIED TEMPLATE PORTION
//     cout<<isequal(2,2)<<endl; // for integers
//     cout<<isequal(2,2)<<endl;   // for integers
//     cout<<isequal('a','a')<<endl;   // for template
//     cout<<"abc abc\t";
//     cout<<isequal("abc","abc")<<endl;   // for stirng

//    cout<<sum(2,3)<<endl;
//    cout<<sum("abc","xyz")<<endl;    // specified function
//    string s = "abc";
//    string s2 = "xyz";
//    cout<<sum(s,s2); // general fucntion


    // FOR DIFFERENT 2 TEMPLATES

    // print(2,'c');
    // cout<<fun2('12'); // error becaue u is not specified
    // cout<<fun2<int,char>(65);// first type is always goes with return type
    // fun3<int,char>('3');



    // TEMPLATE FOR USER DEFINIED DATA TYPES
    //  we can also passed user defined class and struct to template function but ther operation will only be perfomed it is allowd on that type, or operation is overloaded for that datatype
    Point p1(2,3),p2(5,6);
   // cout<<isSame(p1,p2);    // error b/c in isSame we are performing the p1 == p2 and == is not overloader
   p1 = Point(1,2);
   p2 = Point(1,2);
    cout<<isSame(p1,p2);

}


