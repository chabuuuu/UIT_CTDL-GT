#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


void Nhap(DATHUC& B, double heso, int somu) {
DONTHUC* new_donthuc = new DONTHUC(heso, somu);
Node* new_node = new Node(new_donthuc);
if (B.head == nullptr) {
    B.head = new_node;
    B.tail = new_node;
} else {
    B.tail->next = new_node;
    B.tail = new_node;
}
}

void Xuat(DATHUC B) {
Node* cur = B.head;
bool firstTerm = true;
bool all_zero = true;
while (cur != nullptr) {
    double heso = cur->data->heso;
    int somu = cur->data->somu;

    if (heso != 0) {
        all_zero = false;
        if (!firstTerm && heso > 0) {
            cout << "+";
        }

        if (somu == 0) {
            cout << heso;
        } else {
            if (heso != 1 && heso != -1) {
                cout << heso;
            } else if (heso == -1) {
                cout << "-";
            }

            cout << "x";

            if (somu != 1) {
                cout << "^" << somu;
            }
        }

        firstTerm = false;
    }else{
        if (all_zero != false){
             all_zero = true;
        }
       
    }
  

    cur = cur->next;
}
  if (all_zero == true){
        cout<<"0";
    }
}

double TinhDaThuc(DATHUC B, double x) {
double result = 0;
Node* cur = B.head;
while (cur != nullptr) {
    double heso = cur->data->heso;
    int somu = cur->data->somu;
    double termValue = 1;

    for (int i = 0; i < somu; i++) {
        termValue *= x;
    }

    result += heso * termValue;
    cur = cur->next;
}

return result;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
