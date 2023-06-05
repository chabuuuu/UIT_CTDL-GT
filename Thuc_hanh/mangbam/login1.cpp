#include <iostream>
#include<map>
using namespace std;


int N, Q;

string checkPass(map <string, string>& users, string& currentUser){
    map<string,string>::iterator thisUser;
    thisUser = users.find(currentUser);
     if (thisUser  != users.end()){
           string password = thisUser->second;
          return password; 
     }
        return "Chua Dang Ky!";
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
cin >> N>>Q;
     map <string, string> usersMap;
	string username, password;
	for (int i = 0; i < N; i++){
        cin>>username>>password;
        usersMap[username] = password;
    }
    string currentUser;
    for (int i  = 0; i < Q ; i ++ ){
        cin>>currentUser;
        cout<<checkPass(usersMap, currentUser)<<endl;
    }

	return 0;
}

