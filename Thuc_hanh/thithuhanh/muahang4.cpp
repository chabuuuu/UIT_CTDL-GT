#include<bits/stdc++.h>
using namespace std;
bool cmp(const pair<int,int> p1,const pair<int,int> p2) {
	return p1.first < p2.first;
}

bool comparePairs(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first < b.first;
}

void printImposs(){
    cout << "Impossible" << endl;
}





class GiftManage{
private:
    int N;
    int x;
    int Array[];
public:
    

};



int main(){
int N;
cin>>N;
if (N <= 300){
    int X = 0;
    int max=0;
    int x1,x2,x3,x4;
    cin>>X;


    int Array[N];



    for(int i=0;i<N;i++)
    
    {
        cin>>Array[i];
        
        }



         
for( int i=0; i< N; i++){

for(int j=i+1;j<N;j++)
{
for(int h=j+1;h<N;h++){

for(int k=h+1;k<N;k++){
    if(Array[i]+Array[j]+Array[h]+Array[k]<=X )
    {
        if(max<Array[i]+Array[j]+Array[h]+Array[k]){


            max = Array[i]+Array[j]+Array[h]+Array[k];
            x1=i;x2=j;x3=h;x4=k;
        }
    }
}
}
}
}



    if(N>500){
        for(int i=0;i<101;i++){
            for(int i=0;i<N;i++){

        for(int j=i+1;j<N;j++)
        {
            for(int h=j+1;h<N;h++){
                for(int k=h+1;k<N;k++){
                    if(Array[i]+Array[j]+Array[h]+Array[k]<=X )
                    {
                        if(max<Array[i]+Array[j]+Array[h]+Array[k]){

                            max = Array[i]+Array[j]+Array[h]+Array[k];
                            x1=i;x2=j;x3=h;x4=k;
                        }
                    }
                }
            }
        }
    }


        }
        for(int i=101;i<201;i++){
            for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++)
        {
            for(int h=j+1;h<N;h++){
                for(int k=h+1;k<N;k++){
                    if(Array[i]+Array[j]+Array[h]+Array[k]<=X )
                    {
                        if(max<Array[i]+Array[j]+Array[h]+Array[k]){
                            max = Array[i]+Array[j]+Array[h]+Array[k];
                            x1=i;x2=j;x3=h;x4=k;
                        }
                    }
                }
            }
        }
    }


}
for(int i=201;i<301;i++){
for(int i=0;i<N;i++){
for(int j=i+1;j<N;j++)
{
for(int h=j+1;h<N;h++){
for(int k=h+1;k<N;k++){
if(Array[i]+Array[j]+Array[h]+Array[k]<=X )
{
if(max<Array[i]+Array[j]+Array[h]+Array[k]){
    max = Array[i]+Array[j]+Array[h]+Array[k];
    
    x1=i;x2=j;x3=h;x4=k;

}
}
}
}
}
}



        }
        for(int i=301;i<401;i++){
            for(int i=0;i<N;i++){

        for(int j=i+1;j<N;j++)
        {
            for(int h=j+1;h<N;h++){
                for(int k=h+1;k<N;k++){

                    if(Array[i]+Array[j]+Array[h]+Array[k]<=X )
                    {
                        if(max<=Array[i]+Array[j]+Array[h]+Array[k]){

                            max = Array[i]+Array[j]+Array[h]+Array[k];
                            x1=i;x2=j;x3=h;x4=k;
                        }
                    }
                }
            }
        }
    }



        }
        for(int i=401;i<N;i++){
            for(int i=0;i<N;i++){

        for(int j=i+1;j<N;j++)
        {
            for(int h=j+1;h<N;h++){

                for(int k=h+1;k<N;k++){

                    if(Array[i]+Array[j]+Array[h]+Array[k]<=X )
                    {
                        if(max<Array[i]+Array[j]+Array[h]+Array[k]){
                            max = Array[i]+Array[j]+Array[h]+Array[k];
                            x1=i;x2=j;x3=h;x4=k;
                        }
                    }
                }
            }
        }
    }
        }
    }


    if (max == 0){
        cout<<"Impossible"<<endl;
    }else{
            cout<<max<<endl;
    cout<<x1+1<<" "<<x2+1<<" "<<x3+1<<" "<<x4+1;
    }
    return 0;
    }

    if (N > 300 && N < 700){
        
    int x;
    
    
    cin  >> x;
    vector< pair<int,int> > v(N);
    
    for(int index = 0; index < N; index++) {
        cin >> v[index].first;
        v[index].second = index+1;
    }
    sort(v.begin(),v.end(),cmp);
    if(v.size() < 4 || v[0].first+v[1].first+v[2].first+v[3].first > x) {
    	cout << "Impossible" << endl;
    	return 0;
	}
	vector<int> arr(4);
    int l = 0, r = N - 1;
    int max_sum = 0;
    while(l < r) {
        int sum = v[l].first + v[r].first;
        if(sum < x) {
        	int left = l+1, right = r-1;
        	
        	while(left < right) {
        		int next_sum = sum + v[left].first + v[right].first;
        		if(next_sum <= x) {
        			if(max_sum < next_sum) {
        				arr[0] = v[l].second;
			        	arr[1] = v[r].second;
			        	arr[2] = v[left].second;
			        	arr[3] = v[right].second;
			        	max_sum = next_sum;
					}
        			left++;
				}
				else {
					right--;
				}	
			}
            l++;
        }
		else {
			r--;
		}
    }
    cout << max_sum << endl;
    
    
    sort(arr.begin(),arr.end());
    for(int i = 0; i < 4; i++) {
    	cout << arr[i] << ' ';
	}
    return 0;
    }




    int x;

    cin >> x;
    int* arr = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<pair<int, pair<int, int>>> pairs;

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 1; j < N; ++j) {
            pairs.push_back(make_pair(arr[i] + arr[j], make_pair(i, j)));
        }
    }

    sort(pairs.begin(), pairs.end(), comparePairs);

    int left = 0;
    int right = pairs.size() - 1;
    int maxSum = 0;
    int a = -1, b = -1, c = -1, d = -1;

    while (left < right) {
        int sum = pairs[left].first + pairs[right].first;
        if (sum <= x) {
            int i = pairs[left].second.first;
            int j = pairs[left].second.second;
            int k = pairs[right].second.first;
            int l = pairs[right].second.second;

            if (i != j && i != k && i != l && j != k && j != l && k != l) {
                if (sum > maxSum) {
                    maxSum = sum;
                    a = i;
                    b = j;
                    c = k;
                    d = l;
                }
            }

            ++left;
        }
        else {
            --right;
        }
    }

    if (a != -1 && b != -1 && c != -1 && d != -1) {
        vector<int> values = { a, b, c, d };
        sort(values.begin(), values.end());

        cout << x << "\n";
        for (int i = 0; i < 4; ++i) {
            cout << values[i] + 1 << " ";
        }
        cout << "\n";
    }
    else {
        cout << "Impossible\n";
    }
}

   

