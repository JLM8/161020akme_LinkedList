#include<iostream>

using namespace std;

struct node{
	node(int m,int n){
		_m=m;
		_n=n;
	}//:_m(m),_n(n){};
	int _m;
	int _n;
	node * next;
};
	
class queue{
private:
	int _size;
	node * head;
public:
	queue(){
		head = new node(NULL,NULL);
		_size = 0;
	}
	void push(int m, int n){
		node * p = new node(m,n);
		node * cur=NULL;
		cur= head;
		
	//	cout<<cur->_m<<" "<<cur->_n<<endl;
		int i=0;
		while(cur&&i<_size){
			//cout<<i<<":"<<cur->_m<<" "<<cur->_n<<endl;
			cur= cur->next;
			i++;
		}

		cur->next=p;
		//cout<<head->next->_m<<" "<<head->next->_n<<endl;
		//delete cur;
		cout<<"push "<<cur->next->_m<<" "<<cur->next->_n<<endl;
		_size += 1;
	}
	void pop(){
		node * p=NULL;
		p= head->next;
		for(int i=1; i<_size; i++)
			p= p->next;
		cout<<"pop "<<p->_m<<" "<<p->_n<<endl;
		delete p;
		_size-=1;
	}
	int size(){
		return _size;
	}
	int m(){
		node * cur=NULL;
		cur= head;
		
	//	cout<<cur->_m<<" "<<cur->_n<<endl;
		int i=0;
		while(cur&&i<_size){
			//cout<<i<<":"<<cur->_m<<" "<<cur->_n<<endl;
			cur= cur->next;
			i++;
		}
		//cout<<"m:"<<cur->m<<endl;
		return cur->_m;
	}
	int n(){
		node * cur=NULL;
		cur= head;
		
	//	cout<<cur->_m<<" "<<cur->_n<<endl;
		int i=0;
		while(cur&&i<_size){
			//cout<<i<<":"<<cur->_m<<" "<<cur->_n<<endl;
			cur= cur->next;
			i++;
		}
		//cout<<"n:"<<cur->n<<endl;
		return cur->_n;
	}
};



int main(){
	queue  que;
	int m,n;
	cout<<"Input m n" <<endl;
	cin>>m>>n;
	cout<<endl;
	que.push(m,n);
	int _m=m,_n=n;
	do{
	//	cout<<"==="<<endl;
		if(que.n()==0){
			_m=que.m()-1;
			_n=1;
			que.pop();
			que.push(_m,_n);
			system("pause");
			//cout<<que.m()<<" "<<que.n()<<endl;
		}else if(que.m()==0){
			_n=que.n()+1;
			que.pop();
			_m=que.m()-1;
			que.pop();
			que.push(_m,_n);
			system("pause");
			//cout<<que.m()<<" "<<que.n()<<endl;
		}else{
			while(que.n()!=0){
				_n-=1;
			    que.push(_m,_n);
				system("pause");
			//cout<<que.m()<<" "<<que.n()<<endl;
			}
		}
	}while(que.size()!=1);
	
	do{
		if(que.n()==0){
			_n=1;
			_m=que.m()-1;
			que.pop();
			que.push(_m,_n);
			system("pause");
		}else if(que.m()==0){
			_n=que.n()+1;
			que.pop();
			_m=que.m()-1;
			que.pop();
			que.push(_m,_n);
			system("pause");
		}else{
			while(que.n()!=0){
				_m=que.m();
				_n=que.n()-1;
				que.push(_m,_n);
				system("pause");
			}
		}
	}while(que.size()!=1);
	int result = que.n()+1;
	que.pop();
	cout<<"The result is "<<result<<endl;
	
	system("pause");
	return 0;
}
	