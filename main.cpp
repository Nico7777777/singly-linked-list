#include<iostream>
using namespace std;
template <class T>
///now I make the element class

class SLL_element
{
public:
    SLL_element(T arg):data(arg), next(NULL){}
    ~SLL_element(){}

    //----------------------------------------------------------------------------------------------
    SLL_element *get_next(){ return next; }
    const T get_value(){
        return data;
    }
    void add_element_back(SLL_element *arg){
        next = arg;
    }
    void set_value(const T &arg){
        data = arg;
    }
    //----------------------------------------------------------------------------------------------
private:
    T data;
    SLL_element<T> *next;
};




///now I make the container class
template <class T>
class SLL{
public:
    SLL():commence(NULL), fin(NULL) {}
    ~SLL() {}
    void pop_at_front(){
        if( !commence and !fin ){ return; }
        SLL_element<T> *p = commence->get_next();
        delete commence;
        commence = p;
    }
    void pop_at_back(){
        SLL_element<T> *p = commence;
        if( fin == commence ){
            delete fin;
            fin = commence = NULL;
            return ;
        }
        while( p->get_next()->get_next()  ){  p = p->get_next(); }
        //p = p->get_next();
        fin = p;
        p->add_element_back(NULL);
    }
    void push_at_front(T arg){
        if(!commence){
            SLL_element<T>* q = new SLL_element<T>(arg);
            commence = q;
            fin = q;
        }
        else{
            SLL_element<T>* q = new SLL_element<T>(arg);
            q->next(commence);
            commence = q;
        }
    }
    void push_at_back(T arg)
    {
        SLL_element<T> q(arg);
        if( !commence ){
            SLL_element<T>* q = new SLL_element<T>(arg);
            commence = q;
            fin = q;
        }
        else{
            SLL_element<T>* q = new SLL_element<T>(arg);
            fin->add_element_back(q);
            fin = q;
        }
        //cout << commence<<"->v="<<commence->get_value()<<"->f="<<commence->get_next()<<"; "<<fin<<"->"<<fin->get_value() << '\n';
    }
    void iterate_through_list_in_memory(string separator){
        SLL_element<T> *itr;
        itr = commence;
        // cout<<"iteration begins:\n";
        while (itr != NULL)
        {
            cout << itr << separator;
            itr = itr->get_next();
        }
        // cout<<"iterattion ends\n";
        delete itr;
    }
    void iterate_through_list(string separator){
        SLL_element<T>* itr;
        itr = commence;
        //cout<<"iteration begins:\n";
        while( itr != NULL ){
            cout<< itr->get_value()<<separator;
            itr = itr->get_next();
        }
        //cout<<"iterattion ends\n";
        delete itr;
    }
    SLL_element<T>* get_commence(){
        return commence;
    }
    SLL_element<T>* get_fin(){
        return fin;
    }
    void set_commence(SLL_element<T> &arg){    commence = arg;}
    void set_fin(SLL_element<T> &arg){     fin = arg;}
    bool verifier_apartenance(T x){
        SLL_element<T> itr = &commence;
        while(itr){
            if( itr->get_value() ) 
            {
                delete itr;
                return true;
            }
            itr = (*itr).get_next();
        }
        return false;
    }

private:
    SLL_element<T> *commence, *fin;

};

int main()
{

    SLL<char>* my_list = new SLL<char>();
    char k = 'w';
    my_list->pop_at_front();
    my_list->push_at_back(k-1);
    my_list->push_at_back(k);
    my_list->push_at_back(++k);
    my_list->push_at_back((++k)++);
    my_list->push_at_back(k);

    my_list->iterate_through_list("  ");
    cout<<'\n';



}