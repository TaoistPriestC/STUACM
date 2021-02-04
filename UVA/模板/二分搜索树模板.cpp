
#include "bits/stdc++.h"
using namespace std;

//JAVA风格CPP代码,不包含重复元素BST
template<typename Elem>
class BST{
	//声明内部类结点
	private:class Node{
		public:
		Elem e;
		Node *left;
		Node *right;

		Node(Elem e){
			this->e = e;
			this->left = NULL;
			this->right = NULL;
		}
	};

	private:
		Node* _root;
		size_t  _size;
		vector<Elem> tovec;

	public:
		//选择遍历方式
		static const short INORDER = 0;
		static const short PREORDER = 1;
		static const short POSTORDER = 2;

		//选择删除方式
		static const short  PERCURSOR = 4;
		static const short  SUCCESSOR = 8;

	// //友元
	//  public:
	// 	friend istream &operator>>(istream &in, BST<Elem> &bst);
	// 	friend ostream &operator<<(ostream &out, BST<Elem> &bst);

	//构造函数
	public:
		BST(){
			_size = 0;
			_root = NULL;
		}
		BST(vector<int> vec){
			for (int i = 0; i < vec.size(); i++){
				insert(vec[i]);
			}
		}
		BST(Elem arr,size_t arrSize){
			for (int i = 0; i < arrSize; i++){
				insert(arr[i]);
			}
		}

	//常用的基础函数
	public: size_t size() { 
		return _size; 
	}
		
	public: bool empty() { 
		return _size == 0; 
	}


		
	private: Node* insert(Node *node,Elem e){
			//类比链表递归插入元素
		if(node==NULL){
			_size++;
			return new Node(e);
		}else if(e < node->e){
			node->left =  insert(node->left, e);
		}else if(e > node->e){
			node->right = insert(node->right, e);
		}
		return node;
	}

	public: void insert(Elem e){
		_root = insert(_root, e);
	}

	private: bool count(Node *node,Elem e){
		if(node==NULL){
			return false;
		}else if(e < node->e){
			return count(node->left, e);
		}else if(e > node->e){
			return count(node->right, e);
		}else{//相等
			return true;
		}
	}

	public: bool count(Elem e){
		return count(_root, e);
	}


	/*
	 * 前序遍历
	 * 中序遍历
	 * 后序遍历 
	*/


	private: void preOrder(Node *node,vector<Elem> &vec){
		if(node==NULL)
			return;
		vec.push_back(node->e);
		preOrder(node->left,vec);
		preOrder(node->right,vec);
	}

	public: vector<Elem> preOrder(){
		tovec.clear();
		preOrder(_root,tovec);
		return tovec;
	}
	
	private: void inOrder(Node *node,vector<Elem> &vec){
		if(node==NULL)
			return;
		inOrder(node->left,vec);
		vec.push_back(node->e);
		inOrder(node->right,vec);
	}

	public: vector<Elem> inOrder(){
		tovec.clear();
		inOrder(_root,tovec);
		return tovec;
	}

	private: void postOrder(Node *node,vector<Elem> &vec){
		if(node==NULL)
			return;
		postOrder(node->left,vec);
		postOrder(node->right,vec);
		vec.push_back(node->e);
	}

	public: vector<Elem> postOrder(){
		tovec.clear();
		postOrder(_root,tovec);
		return tovec;
	}
	

	private: string toString(int depth){
		string t;
		for (int i = 0; i < depth; i++){
			t += "--";
		}
		return t;
	}

	//前序toString
	private: void preOrder_toString(Node *node, int depth, string &ans){
		if(node==NULL){
			ans += ((toString(depth)) + "NULL\n");
			return;
		}
		ans += ((toString(depth)) + to_string(node->e) + "\n");
		preOrder_toString(node->left, depth + 1, ans);
		preOrder_toString(node->right, depth + 1, ans);
	}

	//中序toString
	private: void inOrder_toString(Node *node, int depth, string &ans){
		if(node==NULL){
			ans += ((toString(depth)) + "NULL\n");
			return;
		}
		inOrder_toString(node->left, depth + 1, ans);
		ans += ((toString(depth)) + to_string(node->e) + "\n");
		inOrder_toString(node->right, depth + 1, ans);
	}

	//后序toString
	private: void postOrder_toString(Node *node, int depth, string &ans){
		if(node==NULL){
			ans += ((toString(depth)) + "NULL\n");
			return;
		}
		postOrder_toString(node->left, depth + 1, ans);
		postOrder_toString(node->right, depth + 1, ans);
		ans += ((toString(depth)) + to_string(node->e) + "\n");
	}

	//生成node结点，深度depth二叉树
	public: string toString(short choice){
		string ans;
		switch (choice){
			case this->PREORDER:
				preOrder_toString(_root, 0, ans);
				break;
			case this->INORDER:
				inOrder_toString(_root, 0, ans);
				break;
			case this->POSTORDER:
				postOrder_toString(_root, 0, ans);
			default:
				break;
		}	
		return ans;
	}

	//层序遍历
	public: vector<vector<Elem>> layerOrder(){
		int s;
		vector<vector<Elem>> ans;
		queue<Node *> q;
		q.push(_root);
		while(!q.empty()){
			s = q.size();
			vector<Elem> tmp;
			while(s--){
				Node *curr = q.front();q.pop();
				tmp.push_back(curr->e);
				if(curr->left) q.push(curr->left);
				if(curr->right) q.push(curr->right);
			}
			ans.push_back(tmp);
		}
		return ans;
	}


	//获取最小值结点,不断向左走
	private: Node* minimum(Node *node){
		if(node->left==NULL){
			return node;
		}
		return minimum(node->left);
	}
	public: Elem minimum(){
		if(_size==0){
			cerr << "BST is NULL!" << endl;
			exit(0);
		}else{
			return minimum(_root)->e;
		}
	}
	//删除最小元素
	private: Node* removeMin(Node *node){
		if(node->left==NULL){
			Node *rightsubTree = node->right;
			node->right = NULL;
			_size--;
			return rightsubTree;
		}
		node->left = removeMin(node->left);
		return node;
	}
	public: Elem removeMin(){
		Elem ret = minimum();
		_root = removeMin(_root);
		return ret;
	}
	

	//获取最大值结点,不断向右走
	private: Node* maximum(Node *node){
		if(node->right==NULL){
			return node;
		}
		return maximum(node->right);
	}
	public: Elem maximum(){
		if(_size==0){
			cerr << "BST is NULL!" << endl;
			exit(0);
		}else{
			return maximum(_root)->e;
		}
	}
	//删除最大元素
	private: Node* removeMax(Node *node){
		if(node->right==NULL){
			Node *leftsubTree = node->left;
			_size--;
			return leftsubTree;
		}
		node->right = removeMax(node->right);
		return node;
	}
	public: Elem removeMax(){
		Elem ret = maximum();
		_root = removeMax(_root);
		return ret;
	}


	//删除任意元素
	//挑选一个结点作为代替原先结点的位置
	//选择前驱(左子树最右)或者后继(右子树最左)皆可
	
	//前驱版
	private: Node* deleteNode_p(Node *node,Elem e){
		if(node==NULL){
			return NULL;
		}
		if(e == node->e){
			if(node->right && node->left){			
				Node *  precursor = maximum(node->left);
				precursor->left = removeMax(node->left);
				precursor->right = node->right;
				node->left = node->right = NULL;
				return precursor;
			}else if(node->left==NULL){
				Node *rightsubTree = node->right;
				_size--;
				return rightsubTree;
			}else if(node->right==NULL){
				Node *leftsubTree = node->left;
				_size--;
				return leftsubTree;
			}
		}else if(e < node->e){
			node->left = deleteNode_p(node->left, e);
		}else if(e > node->e){
			node->right = deleteNode_p(node->right, e);
		}
		return node;
	}

	//后继版
	private: Node* deleteNode_s(Node *node,Elem e){
		if(node==NULL){
			return NULL;
		}
		if(e == node->e){
			if(node->right && node->left){			
				Node *  successor = minimum(node->right);
				successor->right = removeMin(node->right);
				successor->left = node->left;
				node->left = node->right = NULL;
				return successor;
			}else if(node->left==NULL){
				Node *rightsubTree = node->right;
				_size--;
				return rightsubTree;
			}else if(node->right==NULL){
				Node *leftsubTree = node->left;
				_size--;
				return leftsubTree;
			}
		}else if(e < node->e){
			node->left = deleteNode_s(node->left, e);
		}else if(e > node->e){
			node->right = deleteNode_s(node->right, e);
		}
		return node;
	}

	
	public: void deleteNode(Elem e,short choice){
		switch(choice){
			case PREORDER:
				deleteNode_p(_root,e);
				break;
			case SUCCESSOR:
				deleteNode_s(_root,e);
				break;
			default:
				cerr << "Input error!" << endl;
				break;
		}
	}

	private: Node* floor(Node*node, Elem e){
		if(e > node->e){
			return node;
		}else{ //e < node->e
			return floor(node->left, e);
		}
	}
	public: Elem floor(Elem e){
		return floor(_root, e)->e;
	}

	private: Node* ceil(Node *node,Elem e){
		if(e < node->e){
			return node;
		}else{
			return ceil(node->right, e);
		}
	}
	public: Elem ceil(Elem e){
		return ceil(_root, e)->e;
	}


};
