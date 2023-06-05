#include <iostream>
#include<map>
#include<set>
using namespace std;
void checkPass(const map <string, set<string>>& users, const string& currentUser){
    auto thisUser = users.find(currentUser);
     if (thisUser  != users.end()){
           for (const string& password : thisUser->second){
            cout<<password<<" ";
           }
          
     }else{
         cout<< "Chua Dang Ky!";
     }
     cout<<"\n";
       
        
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int N, Q;
cin >> N>>Q;
     map <string, set<string> > usersMap;
	string username, password;
	for (int i = 0; i < N; i++){
        cin>>username>>password;
        usersMap[username].insert(password);
    }
    string currentUser;
    for (int i  = 0; i < Q ; i ++ ){
        cin>>currentUser;
        checkPass(usersMap, currentUser);
    }
	return 0;
}

